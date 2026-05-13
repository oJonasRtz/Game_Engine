#ifndef COLORS_HPP
#define COLORS_HPP

#include <SDL2/SDL.h>

// === Colors ===
namespace Colors {
	//constexpr makes the color objects available at compile time, improving performance and reducing memory usage
	
	constexpr SDL_Color RED = {255, 0, 0, 255};
	constexpr SDL_Color GREEN = {0, 255, 0, 255};
	constexpr SDL_Color BLUE = {0, 0, 255, 255};
	constexpr SDL_Color YELLOW = {255, 255, 0, 255};
	constexpr SDL_Color CYAN = {0, 255, 255, 255};
	constexpr SDL_Color MAGENTA = {255, 0, 255, 255};
	constexpr SDL_Color WHITE = {255, 255, 255, 255};
	constexpr SDL_Color BLACK = {0, 0, 0, 255};
	constexpr SDL_Color GRAY = {128, 128, 128, 255};
	constexpr SDL_Color ORANGE = {255, 165, 0, 255};
	constexpr SDL_Color PURPLE = {128, 0, 128, 255};
	constexpr SDL_Color PINK = {255, 192, 203, 255};
	constexpr SDL_Color BROWN = {165, 42, 42, 255};
};

#endif // COLORS_HPP