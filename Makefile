NAME=myGame

# == Colors ==
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
RESET=\033[0m

# == Files ==
INCLUDE_DIR=includes
SRCS=$(shell find src -name "*.cpp")
OBJS=$(SRCS:.cpp=.o)
FOLDERS= src/game \
		 src/game/assets \
		 src/game/actors \
		 src/game/utils \
		 src/game/rooms \
		 src/game/sprites \
		 includes/game \
		 includes/game/sprites \
		 includes/game/actors \
		 includes/game/utils \

# == Compiler ==
CC=g++
CFLAGS=-std=c++17 -Wall -Wextra -I$(INCLUDE_DIR)
LDFLAGS=-lSDL2 -lSDL2_ttf -Wl,-rpath,'$$ORIGIN/lib'

# == Dist ==
DEB_DIR=$(NAME)_deb
DEB_BIN=$(DEB_DIR)/usr/local/bin
DEB_SHARE=$(DEB_DIR)/usr/local/share/$(NAME)
DEBIAN_DIR=$(DEB_DIR)/DEBIAN
CC_WIN=x86_64-w64-mingw32-g++
DIST_WIN=$(NAME)_win

# == Rules ==
all: $(NAME)

clean:
	@echo "$(YELLOW)Cleaning...$(RESET)"
	@rm -f $(OBJS)

fclean: clean
	@echo "$(YELLOW)Removing executable...$(RESET)"
	@rm -f $(NAME)

re: fclean all

folders:
	@echo "$(BLUE)Creating folders...$(RESET)"
	@mkdir -p $(FOLDERS)

$(NAME): $(OBJS)
	@echo "$(GREEN)Linking...$(RESET)"
	@$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

dist-linux: $(NAME)
	@echo "$(GREEN)Creating distribuition...$(RESET)"
	@rm -rf $(DEB_DIR)
	
# === Create folders structure ===
	@mkdir -p $(DEB_BIN)
	@mkdir -p $(DEB_SHARE)
	@mkdir -p $(DEBIAN_DIR)

# === Binaries ===
	@cp $(NAME) $(DEB_BIN)

# === Assets ===
	@cp -r src/game/assets/* $(DEB_SHARE) 2 >/dev/null || true

# === Control file ===
	@printf "Package: $(NAME)\nVersion: 1.0\nSection: games\nPriority: optional\nArchitecture: amd64\nDepends: libsdl2-2.0-0, libsdl2-ttf-2.0-0\nMaintainer: you\nDescription: My SDL2 Game\n" > $(DEBIAN_DIR)/control

# === Build ===
	@dpkg-deb --build $(DEB_DIR)
	
	@echo "$(GREEN)Distribuition created: $(NAME).deb$(RESET)"

dist-win:
	@echo "$(GREEN)Building Windows executable...$(RESET)"

# clean folder first
	@rm -rf $(DIST_WIN)
	@mkdir -p $(DIST_WIN)

# build exe (IMPORTANT: no linux flags)
	@$(CC_WIN) $(CFLAGS) -o $(NAME).exe $(SRCS) \
		-lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf

# move exe
	@mv $(NAME).exe $(DIST_WIN)/

# dlls
	@cp /usr/x86_64-w64-mingw32/bin/SDL2.dll $(DIST_WIN) 2>/dev/null || true
	@cp /usr/x86_64-w64-mingw32/bin/SDL2_ttf.dll $(DIST_WIN) 2>/dev/null || true

# assets
	@cp -r src/game/assets $(DIST_WIN) 2>/dev/null || true

# zip
	@zip -r $(DIST_WIN).zip $(DIST_WIN)

	@echo "$(GREEN)Distribution created: $(DIST_WIN).zip$(RESET)"


.PHONY: all clean fclean re folders dist-linux dist-win