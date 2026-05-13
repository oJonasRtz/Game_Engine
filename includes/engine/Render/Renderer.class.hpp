#ifndef RENDERER_CLASS_CPP
#define RENDERER_CLASS_CPP

#include <iostream>
#include <SDL2/SDL.h>
#include "../utils.hpp"
#include "colors.hpp"

class Window;

class Render {
	private:
		Render() = delete;
		~Render() = delete;

		static Window* window;
		static SDL_Renderer* renderer;
	
	public:
		static void init(Window* window);

		// === Rendering methods ===
		// static void draw_texture(const std::string& texture_path, int x, int y);
		static void draw_set_font(const std::string& font_path, int font_size);
		static void draw_text(const std::string& text, int x, int y, const SDL_Color& color = Colors::WHITE);
		static void draw_rectangle(int x, int y, int width, int height, const SDL_Color& color);
		static void draw_circle(int x, int y, int radius, const SDL_Color& color);
		static void draw_line(int x1, int y1, int x2, int y2, const SDL_Color& color);

		static void clear(); // beginFrame
		static void present(); // endFrame
};

#endif // RENDERER_CLASS_CPP
