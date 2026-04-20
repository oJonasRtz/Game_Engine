#ifndef ENGINE_CLASS_CPP
#define ENGINE_CLASS_CPP

#include <iostream>
#include "utils.hpp"

class Engine {
	private:
		Engine() = delete;
		~Engine() = delete;

		static bool isRunning;
		static std::string name;

		static void gameLoop();

	public:
		static void start(const std::string& gameName);
		static void stop();
};

#endif // ENGINE_CLASS_CPP
