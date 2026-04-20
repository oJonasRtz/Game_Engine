#include "../../includes/engine/Engine.class.hpp"

#include <thread>
#include <chrono>

// === Static member initialization ===
std::string defaultGameName = "My Game";
bool Engine::isRunning = false;
std::string Engine::name = defaultGameName;

// == Public methods ===
void Engine::start(const std::string& gameName) {
	if (Engine::isRunning) {
		std::cerr << COLOR_YELLOW << "Warning: Engine is already running!" << COLOR_RESET << std::endl;
		return;
	}

	std::cout << COLOR_GREEN << "Starting engine..." << COLOR_RESET << std::endl;

	Engine::name = gameName.empty() ? defaultGameName : gameName;
	Engine::isRunning = true;


	Engine::gameLoop();
}

void Engine::stop() {
	if (!Engine::isRunning) {
		std::cerr << COLOR_YELLOW << "Warning: Engine is not running!" << COLOR_RESET << std::endl;
		return;
	}

	std::cout << COLOR_RED << "Stopping engine..." << COLOR_RESET << std::endl;
	Engine::isRunning = false;
	Engine::name = defaultGameName;
}

// == Private methods ===
void Engine::gameLoop() {
	while (Engine::isRunning) {
		// Placeholder for game loop logic
		std::cout << "\r" << COLOR_BLUE << Engine::name << " is Running: " << Engine::name << COLOR_RESET << std::endl;

		// Simulate a simple game loop with a sleep
		std::this_thread::sleep_for(std::chrono::seconds(1));
		Engine::stop(); // For demonstration, stop after one iteration
	}
}