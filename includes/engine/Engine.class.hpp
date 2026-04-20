#ifndef ENGINE_CLASS_CPP
#define ENGINE_CLASS_CPP

#include <iostream>
#include "utils.hpp"

class Window;

class Engine {
	private:
		Engine() = delete;
		~Engine() = delete;

		static bool isRunning;
		static bool isPaused;
		static std::string name;
		static Window* window;

		static void gameLoop();


	public:
		/**
		 * Starts the game engine with the specified game name. If the engine is already running, it will print a warning message.
		 * @param gameName The name of the game to start. If empty, a default name will be used.
		*/
		static void start(const std::string& gameName);
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
};

#endif // ENGINE_CLASS_CPP
