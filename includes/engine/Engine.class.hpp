#ifndef ENGINE_CLASS_CPP
#define ENGINE_CLASS_CPP

#include <iostream>
#include "utils.hpp"

class Window;

class Engine {
	private:
		Engine() = delete;
		~Engine() = delete;

		// === Engine state ===
		static bool isRunning;
		static bool isPaused;
		static Window* window;

		// === Game information ===
		static std::string gameName;
		static std::string gameVersion;

		// == Engine information ===
		static std::string engineName;
		static std::string engineVersion;
		
		// === Private methods ===
		static void gameLoop();
	public:
		/**
		 * Starts the game engine. If the engine is already running, it will print a warning message.
		 */
		static void start();
		/**
		 * Resumes the game if it is paused with Engine::stop(). If the engine is not paused, it will print a warning message.
		 * Note: This method does not start the game loop, it only resumes the game logic
		*/
		static void resume();
		/**
		 * Pauses Actors events and rendering. If the engine is not running or already paused, it will print a warning message.
		 * Note: This method does not stop the game loop, it only pauses the game logic and rendering.
		*/
		static void stop();
		/**
		 * Stops the game engine and exits the game loop. If the engine is not running, it will print a warning message.
		 * Note: This method will stop the game loop and exit the game, it does not just pause the game logic and rendering like Engine::stop().
		 * 
		*/
		static void exit();

		// === Getters ===
		static const std::string& getGameName() { return Engine::gameName; }
		static const std::string& getGameVersion() { return Engine::gameVersion; }
		static const std::string& getEngineName() { return Engine::engineName; }
		static const std::string& getEngineVersion() { return Engine::engineVersion; }

		// == Setters ===
		static void setGameName(const std::string& name) { Engine::gameName = name; }
		static void setGameVersion(const std::string& version) { Engine::gameVersion = version; }
};

#endif // ENGINE_CLASS_CPP
