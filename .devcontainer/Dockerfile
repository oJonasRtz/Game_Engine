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
	pkg-config \
	software-properties-common

# SDL2
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

RUN apt-get install -y \
	clang \
	clangd \
	lldb

# Clean
RUN apt-get clean && rm -rf /var/lib/apt/lists/*

WORKDIR /workspace