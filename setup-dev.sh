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

# Detect distro
if [ -f /etc/os-release ]; then
    . /etc/os-release
    DISTRO=$ID
else
    echo "Unsupported system: /etc/os-release not found"
    exit 1
fi

echo "Detected distro: $DISTRO"

# Common dependencies
COMMON_PKGS=(
    git
    ninja
    cmake
    gcc
    g++
    clang
    make
    unzip
)

install_arch() {
    echo "[+] Installing dev tools on Arch..."
    sudo pacman -Sy --needed "${COMMON_PKGS[@]}"
}

install_fedora() {
    echo "[+] Installing dev tools on Fedora..."
    sudo dnf install -y "${COMMON_PKGS[@]}"
}

# Install system packages
case "$DISTRO" in
    arch|manjaro)
        install_arch
        ;;
    fedora)
        install_fedora
        ;;
    *)
        echo "Unsupported distro: $DISTRO"
        exit 1
        ;;
esac

# Optionally build bleeding edge CMake from source
read -p "Do you want to build the latest CMake from source? [y/N] " -n 1 -r
echo
if [[ $REPLY =~ ^[Yy]$ ]]; then
    echo "[+] Building CMake from source..."
    mkdir -p ~/dev-tools/cmake && cd ~/dev-tools/cmake
    curl -LO https://github.com/Kitware/CMake/releases/latest/download/cmake-*-tar.gz
    tar -xf cmake-*-tar.gz --strip-components=1
    ./bootstrap --prefix=$HOME/.local
    make -j$(nproc)
    make install
    echo "export PATH=\$HOME/.local/bin:\$PATH" >> ~/.bashrc
    echo "[+] CMake installed to ~/.local/bin"
else
    echo "[-] Skipping CMake build"
fi

# Summary
echo
echo "[✓] Dev environment setup complete!"
echo "C++ version: $(g++ --version | head -n1)"
echo "CMake version: $(cmake --version | head -n1)"
