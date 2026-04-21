#include "../../includes/engine/Render/Window.class.hpp"

Window::Window(const std::string& title, int width, int height, int fps):
	title(title.empty() ? DEFAULT_TITLE : title),
	width(width > 0 ? width : DEFAULT_WIDTH),
	height(height > 0 ? height : DEFAULT_HEIGHT),
	fps(fps > 0 ? fps : DEFAULT_FPS)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0 || TTF_Init() < 0) {
		std::cerr << COLOR_RED << "Error: Could not initialize SDL: " << SDL_GetError() << COLOR_RESET << std::endl;
		return;
	}

	this->window = SDL_CreateWindow(this->title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->width, this->height, SDL_WINDOW_SHOWN);
	if (!this->window) {
		std::cerr << COLOR_RED << "Error: Could not create window: " << SDL_GetError() << COLOR_RESET << std::endl;
		return;
	}
	this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
	if (!this->renderer) {
		std::cerr << COLOR_RED << "Error: Could not create renderer: " << SDL_GetError() << COLOR_RESET << std::endl;
		return;
	}
}

Window::~Window() {
	SDL_DestroyRenderer(this->renderer);
	SDL_DestroyWindow(this->window);
	TTF_Quit();
	SDL_Quit();
}