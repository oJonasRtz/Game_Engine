#include "../../includes/engine/Render/Renderer.class.hpp"
#include "../../includes/engine/Render/Window.class.hpp"
#include "../../includes/engine/Engine.class.hpp"

Window* Render::window = nullptr;
SDL_Renderer* Render::renderer = nullptr;

void Render::init(Window* w) {
	if (!w){
		std::cerr << COLOR_RED << "Error: Window is null!" << COLOR_RESET << std::endl;
		Engine::exit();
		return;
	}

	Render::window = w;
	Render::renderer = w->getRenderer();

	SDL_SetRenderDrawColor(Render::renderer, 0, 0, 0, 255); // Set default draw color to black
}

void Render::clear() {
	if (!renderer)
		return;

	SDL_RenderClear(renderer);
}
void Render::present() {
	if (!renderer)
		return;

	SDL_RenderPresent(renderer);
}

// == Drawing methods ===
void Render::draw_text(const std::string& text, const std::string& font_path, int font_size, int x, int y) {}
void Render::draw_rectangle(int x, int y, int width, int height, const std::string& color) {}
void Render::draw_circle(int x, int y, int radius, const std::string& color) {}
void Render::draw_line(int x1, int y1, int x2, int y2, const std::string& color) {}
