#!/bin/bash
set -e

cat << "EOF"
 ____            _       _                         _        _           
/ ___|  ___ _ __(_)_ __ | |_   _ __ ___   __ _  __| | ___  | |__  _   _ 
\___ \ / __| '__| | '_ \| __| | '_ ` _ \ / _` |/ _` |/ _ \ | '_ \| | | |
 ___) | (__| |  | | |_) | |_  | | | | | | (_| | (_| |  __/ | |_) | |_| |
|____/ \___|_|  |_| .__/ \__| |_| |_| |_|\__,_|\__,_|\___| |_.__/ \__, |
                  |_|                                             |___/ 
  ____ _           _    ____ ____ _____ 
 / ___| |__   __ _| |_ / ___|  _ \_   _|
| |   | '_ \ / _` | __| |  _| |_) || |  
| |___| | | | (_| | |_| |_| |  __/ | |  
 \____|_| |_|\__,_|\__|\____|_|    |_|    
EOF

echo "[+] Building Lyndsay..."

# Where you want your build to happen
PROJECT_DIR=`pwd`
BUILD_DIR="build"

# Create or clean the build directory
mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR"

# Run CMake
cmake .. -G Ninja

# Actually build it
if ninja; then
    echo `pwd`
    mkdir -p shaders
    cp $PROJECT_DIR/shaders/*.glsl shaders
    echo
    echo "✨✨ Lyndsay has compiled. She lives again. ✨✨"
    echo "Press F12 to debug like a god."
else
    echo
    echo "💥💥 Build failed. Lyndsay is displeased. 💥💥"
    echo "Check your logs, mortal."
    exit 1
fi
