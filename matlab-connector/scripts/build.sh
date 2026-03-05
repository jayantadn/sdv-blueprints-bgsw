#!/bin/bash

# Build script for local machine
# Compiles da_connector.c natively

echo "Building da_connector for local machine..."

# Compiler settings for native compilation
CC="gcc"
CXX="g++"
CFLAGS="-O2 -fPIC -w"
CXXFLAGS="-O2 -fPIC -w -std=c++17 -Ilocal/protogen"
LDFLAGS="-shared"

# gRPC and protobuf libraries
GRPC_LIBS="-lgrpc++ -lgrpc -lprotobuf -lpthread -ldl"

# Source files
C_SOURCES="da_connector.c"
CPP_SOURCES="client.cpp"
PROTOBUF_SOURCES="local/protogen/kuksa/val/v1/val.pb.cc local/protogen/kuksa/val/v1/val.grpc.pb.cc"
MAIN_SOURCE="local/main.c"
HEADERS="da_connector.h kuksa_bridge.h"

# Build directory
BUILD_DIR="build"

# Outputs
EXE_OUTPUT="$BUILD_DIR/da_connector_app"

# Create build directory if it doesn't exist
if [ ! -d "$BUILD_DIR" ]; then
    echo "Creating build directory..."
    mkdir -p "$BUILD_DIR"
fi

# Check if source files exist
if [ ! -f "da_connector.c" ]; then
    echo "ERROR: da_connector.c not found!"
    exit 1
fi

if [ ! -f "client.cpp" ]; then
    echo "ERROR: client.cpp not found!"
    exit 1
fi

if [ ! -f "da_connector.h" ]; then
    echo "ERROR: da_connector.h not found!"
    exit 1
fi

if [ ! -f "kuksa_bridge.h" ]; then
    echo "ERROR: kuksa_bridge.h not found!"
    exit 1
fi

if [ ! -f "local/main.c" ]; then
    echo "ERROR: local/main.c not found!"
    exit 1
fi

# Compile C source to object file
echo "Compiling C source: $C_SOURCES..."
$CC $CFLAGS -c -o $BUILD_DIR/da_connector.o $C_SOURCES

if [ $? -ne 0 ]; then
    echo "ERROR: C compilation failed!"
    exit 1
fi

# Compile protobuf generated files
echo "Compiling protobuf sources..."
$CXX $CXXFLAGS -c -o $BUILD_DIR/val.pb.o local/protogen/kuksa/val/v1/val.pb.cc

if [ $? -ne 0 ]; then
    echo "ERROR: Protobuf compilation failed!"
    exit 1
fi

$CXX $CXXFLAGS -c -o $BUILD_DIR/val.grpc.pb.o local/protogen/kuksa/val/v1/val.grpc.pb.cc

if [ $? -ne 0 ]; then
    echo "ERROR: Protobuf gRPC compilation failed!"
    exit 1
fi

# Compile C++ source to object file
echo "Compiling C++ source: $CPP_SOURCES..."
$CXX $CXXFLAGS -c -o $BUILD_DIR/client.o $CPP_SOURCES

if [ $? -ne 0 ]; then
    echo "ERROR: C++ compilation failed!"
    exit 1
fi

# Compile the executable using C++ linker (since it links with C++ code)
echo "Compiling executable $MAIN_SOURCE..."
$CC $CFLAGS -c -o $BUILD_DIR/main.o $MAIN_SOURCE

if [ $? -ne 0 ]; then
    echo "ERROR: Main compilation failed!"
    exit 1
fi

echo "Linking executable..."
$CXX -o $EXE_OUTPUT $BUILD_DIR/main.o $BUILD_DIR/da_connector.o $BUILD_DIR/client.o $BUILD_DIR/val.pb.o $BUILD_DIR/val.grpc.pb.o $GRPC_LIBS

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Executable build successful! Output: $EXE_OUTPUT"
    ls -lh $EXE_OUTPUT
else
    echo "ERROR: Executable build failed!"
    exit 1
fi

echo "Build complete!"
