#!/bin/bash

# Build a static library that wraps the Simulink custom code (da_connector + gRPC client)
# so that the Simulink build can link against it.
#
# Usage:
#   ./scripts/build_simulink_lib.sh
#
# After running this script, point Simulink at:
#   - The resulting static library: build/libkuksa.a
#   - The required system gRPC/protobuf libraries (see the printed list)

set -euo pipefail

# Output folder
BUILD_DIR="build"
mkdir -p "$BUILD_DIR"

# Compiler selection
CC="gcc"
CXX="g++"

# Use pkg-config to query gRPC/protobuf flags when available
GRPC_CFLAGS=""
GRPC_LIBS=""
if command -v pkg-config >/dev/null 2>&1; then
  GRPC_CFLAGS=$(pkg-config --cflags grpc++ 2>/dev/null || true)
  GRPC_LIBS=$(pkg-config --libs grpc++ 2>/dev/null || true)
fi

# Fall back to common flags if pkg-config did not return anything
if [ -z "${GRPC_LIBS}" ]; then
  GRPC_LIBS="-lgrpc++ -lgrpc -lgpr -lprotobuf -lpthread -ldl"
fi

# Source files
C_SOURCE="da_connector.c"
CPP_SOURCE="client.cpp"
PROTO_DIR="local/protogen/kuksa/val/v1"

echo "Building static library for Simulink..."

echo "Compiling $C_SOURCE..."
$CC -O2 -fPIC -w -I. $GRPC_CFLAGS -c "$C_SOURCE" -o "$BUILD_DIR/da_connector.o"

echo "Compiling $CPP_SOURCE..."
$CXX -O2 -fPIC -w -std=c++17 -I. -Ilocal/protogen -Ilocal/protogen/kuksa/val/v1 $GRPC_CFLAGS -c "$CPP_SOURCE" -o "$BUILD_DIR/client.o"

# Compile generated protobuf sources (if any)
echo "Compiling protobuf-generated sources in $PROTO_DIR..."
for src in "$PROTO_DIR"/*.pb.cpp; do
  [ -e "$src" ] || continue
  obj="$BUILD_DIR/$(basename "$src" .cpp).o"
  echo "  $src -> $obj"
  $CXX -O2 -fPIC -w -std=c++17 -I. -Ilocal/protogen -Ilocal/protogen/kuksa/val/v1 $GRPC_CFLAGS -c "$src" -o "$obj"
done

# Build library
LIB_OUT="$BUILD_DIR/libkuksa.a"
ar -rcs "$LIB_OUT" "$BUILD_DIR"/*.o

cat <<EOF

Built static library: $LIB_OUT

Next steps:
 1) In Simulink Custom Code > Source files, include any .h files you need (e.g. da_connector.h).
 2) In Simulink Custom Code > Libraries, point to this library:
      $LIB_OUT
 3) If Simulink supports it, add the following system library names (no -l prefix):
      grpc++
      grpc
      gpr
      protobuf

To help you find those system libraries, the command below prints the actual paths:
  scripts/build_simulink_lib.sh --print-system-libs

EOF

# Print helpful list of gRPC/protobuf libraries if requested
if [ "${1:-}" = "--print-system-libs" ]; then
  echo "System library paths (from ldconfig) to use in Simulink (copy the ones you have):"
  ldconfig -p | grep -E "libgrpc\+\+|libgrpc\b|libgpr\b|libprotobuf\b" || true
fi
