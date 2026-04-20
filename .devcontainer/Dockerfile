FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

# Essentials
RUN apt-get update && apt-get install -y \
	build-essential \
	cmake \
	gdb \
	git \
	curl \
	wget \
	unzip \
	zip \
	pkg-config \
	software-properties-common

# SDL2 linux
RUN apt-get install -y \
	libsdl2-dev \
	libsdl2-image-dev \
	libsdl2-ttf-dev \
	libsdl2-mixer-dev

# Vulkan
RUN apt-get install -y \
	vulkan-tools \
	libvulkan-dev \
	vulkan-validationlayers-dev \
	spirv-tools

# Utils
RUN apt-get install -y \
	clang \
	clangd \
	lldb

# === WINDOWS CROSS-COMPILATION ===
RUN apt-get install -y mingw-w64 gcc-mingw-w64-x86-64 g++-mingw-w64-x86-64

# SDL2 windows
RUN wget https://www.libsdl.org/release/SDL2-devel-2.28.5-mingw.tar.gz -O /tmp/sdl2.tar.gz && \
	tar -xzf /tmp/sdl2.tar.gz -C /tmp && \
	cp -r /tmp/SDL2-2.28.5/x86_64-w64-mingw32/* /usr/x86_64-w64-mingw32/ && \
	rm -rf /tmp/sdl2*

# SDL2_ttf windows
RUN wget https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-devel-2.22.0-mingw.tar.gz -O /tmp/sdl2_ttf.tar.gz && \
	tar -xzf /tmp/sdl2_ttf.tar.gz -C /tmp && \
	cp -r /tmp/SDL2_ttf-2.22.0/x86_64-w64-mingw32/* /usr/x86_64-w64-mingw32/ && \
	rm -rf /tmp/sdl2_ttf*


# Clean
RUN apt-get clean && rm -rf /var/lib/apt/lists/*

WORKDIR /workspace