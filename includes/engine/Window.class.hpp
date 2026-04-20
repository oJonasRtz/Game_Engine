#ifndef WINDOW_CLASS_CPP
#define WINDOW_CLASS_CPP

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "utils.hpp"

// == Default values ==
#define DEFAULT_FPS 60
#define DEFAULT_TITLE "My Game"
#define DEFAULT_WIDTH 800
#define DEFAULT_HEIGHT 600

class Window {
	private:
		SDL_Window *window;
		SDL_Renderer *renderer;

		std::string title;
		int width, height, fps;
	public:
		/**
		 * Creates a new window with the specified title, width, height and frames per second (fps). The window will be created using SDL2 and will be used for rendering the game. If the window cannot be created, an error message will be printed to the console.
		 * @param title The title of the window.
		 * @param width The width of the window in pixels.
		 * @param height The height of the window in pixels.
		 * @param fps The frames per second (fps) of the window. This will be used to control the game loop and ensure that the game runs at a consistent speed. If fps is 0, a default value will be used.
		*/
		Window(const std::string& title = DEFAULT_TITLE, int width = DEFAULT_WIDTH, int height = DEFAULT_HEIGHT, int fps = DEFAULT_FPS);
		~Window();
};

#endif // WINDOW_CLASS_CPP
