NAME=myGame

# == Colors ==
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
RESET=\033[0m

# == Files ==
INCLUDE_DIR=includes
SRCS=$(shell find . -name "*.cpp")
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
LDFLAGS=-lSDL2 -LSDL2_ttf

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

.PHONY: all clean fclean re folders