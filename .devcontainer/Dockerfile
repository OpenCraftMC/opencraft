FROM mcr.microsoft.com/devcontainers/cpp:ubuntu-24.04

RUN sudo apt-get update \
 && sudo apt-get install -y \
    xorg-dev \
    build-essential \
    cmake \
    git \
    libgl1-mesa-dev \
    libglu1-mesa-dev \
    libgles2-mesa-dev \
    libegl1-mesa-dev

# Install BGFX dependencies
RUN sudo apt-get install -y \
    libxrandr-dev \
    libxinerama-dev \
    libxcursor-dev \
    libxi-dev

# Clone BGFX repository
RUN git clone --recursive https://github.com/bkaradzic/bgfx.git /usr/local/bgfx

# Set up the user
RUN useradd -ms /bin/bash developer
USER developer
WORKDIR /home/developer

# Copy the application files
COPY . /home/developer
