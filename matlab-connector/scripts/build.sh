#!/bin/bash

# Build script for Raspberry Pi 5
# Cross-compiles da_connector.c from WSL to ARM64 target

echo "Building da_connector for Raspberry Pi 5 (ARM64)..."

# Check if ARM64 cross-compiler is installed
ARM_CC="aarch64-linux-gnu-gcc"

if ! command -v $ARM_CC &> /dev/null; then
    echo "ARM64 cross-compiler not found!"
    echo "Installing cross-compilation toolchain..."
    sudo apt-get update
    sudo apt-get install -y gcc-aarch64-linux-gnu g++-aarch64-linux-gnu
    
    if ! command -v $ARM_CC &> /dev/null; then
        echo "ERROR: Failed to install ARM64 cross-compiler."
        echo "Please install manually: sudo apt-get install gcc-aarch64-linux-gnu"
        exit 1
    fi
fi

# Compiler settings for ARM64 target
CC=$ARM_CC
CFLAGS="-O2 -fPIC -march=armv8-a -w"
LDFLAGS="-shared"

# Source files
SOURCES="da_connector.c"
MAIN_SOURCE="main.c"
HEADERS="da_connector.h"

# Build directory
BUILD_DIR="build"

# Outputs
LIB_OUTPUT="$BUILD_DIR/libda_connector.so"
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

if [ ! -f "da_connector.h" ]; then
    echo "ERROR: da_connector.h not found!"
    exit 1
fi

if [ ! -f "main.c" ]; then
    echo "ERROR: main.c not found!"
    exit 1
fi

# Compile the shared library
echo "Compiling shared library $SOURCES..."
$CC $CFLAGS $LDFLAGS -o $LIB_OUTPUT $SOURCES

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Shared library build successful! Output: $LIB_OUTPUT"
    ls -lh $LIB_OUTPUT
else
    echo "ERROR: Shared library build failed!"
    exit 1
fi

# Compile the executable
echo "Compiling executable $MAIN_SOURCE..."
$CC $CFLAGS -o $EXE_OUTPUT $MAIN_SOURCE $SOURCES

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Executable build successful! Output: $EXE_OUTPUT"
    ls -lh $EXE_OUTPUT
else
    echo "ERROR: Executable build failed!"
    exit 1
fi

echo "Build complete!"
