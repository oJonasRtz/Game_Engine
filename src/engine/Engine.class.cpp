#include "../../includes/engine/Engine.class.hpp"
#include "../../includes/engine/Render/Window.class.hpp"
#include "../../includes/engine/Render/Renderer.class.hpp"

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
	Render::init(Engine::window);

	auto ONE_SECOND = std::chrono::seconds(1);
	auto lastTime = std::chrono::high_resolution_clock::now();

	int cnt = 0;
	int fps_show = 0;

	while (Engine::isRunning) {
		auto now = std::chrono::high_resolution_clock::now();
		cnt++;
		// === Events ===
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				Engine::exit();
		}
		
		// Placeholder for game loop logic
		if (!Engine::isPaused) {
			Render::clear();
			std::cout << "\r"
					<< Engine::engineName
					<< " is Running: "
					<< COLOR_BLUE
					<< Engine::gameName
					<< COLOR_RESET
					<< " | FPS: " << COLOR_YELLOW << fps_show << COLOR_RESET
					<< std::flush;
			Render::present();
		}

		// === Implementar limitador de FPS, vamos deixar um template por enquanto ===
		std::this_thread::sleep_for(std::chrono::milliseconds(1000 / 60)); // Simulate ~60 FPS

		if (now - lastTime >= ONE_SECOND) {
			fps_show = cnt;
			cnt = 0;
			lastTime = now;
		}
	}
}
