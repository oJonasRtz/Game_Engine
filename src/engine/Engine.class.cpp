#include "../../includes/engine/Engine.class.hpp"
#include "../../includes/engine/Window.class.hpp"

#include <SDL2/SDL_scancode.h>
#include <thread>
#include <chrono>

// === Static member initialization ===
std::string defaultGameName = "My Awesome Game";
bool Engine::isPaused = false;
bool Engine::isRunning = false;
Window* Engine::window = nullptr;

// === Game and engine information ===
/*
	Versioning scheme:
	- Game version: Major.Minor.Patch (e.g., 1.0.0)
		- Ex: 1.0.0: Initial release
		- Ex: 1.1.0: Added new features
		- Ex: 1.1.1: Bug fixes and performance improvements
*/
std::string Engine::gameName = defaultGameName;
std::string Engine::gameVersion = "1.0.0";
std::string Engine::engineName = "Stray Engine";
std::string Engine::engineVersion = "0.0.1";


// == Public methods ===
void Engine::start() {
	if (Engine::isRunning) {
		std::cerr << COLOR_YELLOW << "Warning: Engine is already running!" << COLOR_RESET << std::endl;
		return;
	}

	std::cout << COLOR_GREEN << "Starting engine..." << COLOR_RESET << std::endl;

	Engine::isRunning = true;
	Engine::window = new Window(Engine::gameName);

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
		if (!Engine::isPaused)
			std::cout << "\r" << COLOR_BLUE << Engine::engineName << " is Running: " << Engine::gameName << COLOR_RESET << std::flush;

		// === Events ===
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT || event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
				Engine::exit();

			if (event.key.keysym.scancode == SDL_SCANCODE_P)
				Engine::stop();
			else if (event.key.keysym.scancode == SDL_SCANCODE_R)
				Engine::resume();
		}
	}
}
