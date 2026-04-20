#include "../../includes/engine/Engine.class.hpp"
#include "../../includes/engine/Window.class.hpp"

#include <SDL2/SDL_scancode.h>
#include <thread>
#include <chrono>

// === Static member initialization ===
std::string defaultGameName = "My Game";
bool Engine::isPaused = false;
bool Engine::isRunning = false;
std::string Engine::name = defaultGameName;
Window* Engine::window = nullptr;


// == Public methods ===
void Engine::start(const std::string& gameName) {
	if (Engine::isRunning) {
		std::cerr << COLOR_YELLOW << "Warning: Engine is already running!" << COLOR_RESET << std::endl;
		return;
	}

	std::cout << COLOR_GREEN << "Starting engine..." << COLOR_RESET << std::endl;

	Engine::name = gameName.empty() ? defaultGameName : gameName;
	Engine::isRunning = true;
	Engine::window = new Window(Engine::name);

	Engine::gameLoop();
}

void Engine::stop() {
	if (!Engine::isPaused && !Engine::isRunning) {
		std::cerr << COLOR_YELLOW << "Warning: Engine is not running!" << COLOR_RESET << std::endl;
		return;
	}

	std::cout << COLOR_YELLOW << "Stopping engine..." << COLOR_RESET << std::endl;
	Engine::isPaused = true;
}

void Engine::resume() {
	if (!Engine::isPaused) {
		std::cerr << COLOR_YELLOW << "Warning: Engine is not paused!" << COLOR_RESET << std::endl;
		return;
	}

	std::cout << COLOR_GREEN << "Resuming engine..." << COLOR_RESET << std::endl;
	Engine::isPaused = false;
}
void Engine::exit() {
	std::cout << COLOR_RED << "Exiting game..." << COLOR_RESET << std::endl;
	Engine::isRunning = false;
	delete Engine::window;
	Engine::window = nullptr;
}

// == Private methods ===
void Engine::gameLoop() {
	SDL_Event event;

	while (Engine::isRunning) {
		// Placeholder for game loop logic
		std::cout << "\r" << COLOR_BLUE << Engine::name << " is Running: " << Engine::name << COLOR_RESET << std::endl;

		// === Events ===
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				Engine::exit();

			if (event.type == SDL_SCANCODE_ESCAPE)
				Engine::stop();
			
			if (event.type == SDL_SCANCODE_SPACE)
				Engine::resume();
		}
	}
}