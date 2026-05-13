#include "../../includes/engine/Render/Renderer.class.hpp"
#include "../../includes/engine/Render/Window.class.hpp"
#include "../../includes/engine/Engine.class.hpp"
#include <unordered_map>

// === Font cache for draw_text method ===
static std::unordered_map<std::string, TTF_Font*> font_cache;
static TTF_Font* current_font = nullptr;

static TTF_Font* getFont(const std::string& font_path, int font_size) {
	std::string key = font_path + "_" + std::to_string(font_size);

	if (font_cache.find(key) != font_cache.end())
		return font_cache[key];

	TTF_Font* font = TTF_OpenFont(font_path.c_str(), font_size);
	if (!font)
		return nullptr;

	font_cache[key] = font;
	return font;
}

// === Static member initialization ===
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

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Clear with black color
	SDL_RenderClear(renderer);
}
void Render::present() {
	if (!renderer)
		return;

	SDL_RenderPresent(renderer);
}

// == Drawing methods ===
void Render::draw_set_font(const std::string& font_path, int font_size) {
	current_font = getFont(font_path, font_size);

	if (!current_font) {
		std::cerr << COLOR_RED << "Error: Could not load font '" << font_path << "' with size " << font_size << "!" << COLOR_RESET << std::endl;
	}
}

void Render::draw_text(const std::string& text, int x, int y, const SDL_Color& color) {
	if (!renderer || !current_font)
		return;

	SDL_Surface* surface = TTF_RenderUTF8_Blended(current_font, text.c_str(), color);
	if (!surface)
		return;

	int w = surface->w;
	int h = surface->h;

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	if (!texture)
		return;

	SDL_Rect dstRect = {x, y, w, h};
	SDL_RenderCopy(renderer, texture, nullptr, &dstRect);
	SDL_DestroyTexture(texture);
}
void Render::draw_rectangle(int x, int y, int width, int height, const SDL_Color& color) {
	if (!renderer)
		return;

	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

	SDL_Rect rect = {x, y, width, height};
	SDL_RenderFillRect(renderer, &rect);
}
void Render::draw_circle(int x, int y, int radius, const SDL_Color& color) {
	if (!renderer)
		return;
}
void Render::draw_line(int x1, int y1, int x2, int y2, const SDL_Color& color) {
	if (!renderer)
		return;
}
