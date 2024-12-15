#!/bin/bash

OPENGL_PACKAGE="libopengl-dev"
DIST_DIR="dist"

check_opengl() {
    dpkg -l | grep -i "libopengl" > /dev/null 2>&1
}

install_opengl() {
    sudo apt update
    sudo apt install -y $OPENGL_PACKAGE
}

if ! check_opengl; then
    install_opengl
else
    echo "OpenGL is already installed."
fi

if [ ! -d "$DIST_DIR" ]; then
    mkdir -p "$DIST_DIR"
fi

cmake -S . -B "$DIST_DIR"
cmake --build "$DIST_DIR"

echo "Build complete!"
