#include <iostream>
#include "../includes/engine/Engine.class.hpp"
#include <unordered_map>
#include <functional>
#include <algorithm>
#include "../includes/engine/utils.hpp"

// === Command line arguments map ===
/**
 * Handle commands line arguments like --help, --version, etc.
*/
static int handleCommands(const std::string& command, const std::string& program) {
	std::string cmd = command;
	std::transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);
	std::transform(cmd.begin(), cmd.end(), cmd.begin(), [](unsigned char c) { return std::isspace(c) ? ' ' : c; });

	if (cmd.empty()){
		std::cerr << COLOR_YELLOW << "Warning: No command provided!" << COLOR_RESET << std::endl;
		return 1;
	}

	std::unordered_map<std::string, std::function<void()>> command_map;
	command_map["--help"] = [program](){
		std::cout << "Usage: " << COLOR_YELLOW << program << " [command]" << COLOR_RESET << std::endl;
		std::cout << "Commands:" << std::endl;
		std::cout << "  " << COLOR_BLUE << "--help" << COLOR_RESET << "     Show this help message" << std::endl;
		std::cout << "  " << COLOR_BLUE << "--version" << COLOR_RESET << "  Show engine version" << std::endl;
		std::cout << "  " << COLOR_BLUE << "--info" << COLOR_RESET << "     Show engine and game information" << std::endl;
	};
	command_map["--version"] = [](){
	std::cout << COLOR_GREEN << Engine::getEngineName() << " version: " << Engine::getEngineVersion() << COLOR_RESET << std::endl;
	};
	command_map["--info"] = [](){
		std::cout << Engine::getEngineName() << COLOR_BLUE << " version: " << COLOR_RESET << Engine::getEngineVersion() << std::endl;
		std::cout << "Game: " << Engine::getGameName() << COLOR_BLUE << " version: " << COLOR_RESET << Engine::getGameVersion() << std::endl;
	};

	if (command_map.find(cmd) == command_map.end()) {
		std::cerr << COLOR_YELLOW << "Warning: Unknown command '" << cmd << "'!" << COLOR_RESET << std::endl;
		return 1;
	}

	command_map[cmd]();
	return 0;
}

int main(int argc, char* argv[]) {
	
	// Setting my game information
	Engine::setGameName("Stray Engine Demo");
	Engine::setGameVersion("0.0.3");

	if (argc > 1)
		return handleCommands(argv[1], argv[0]);

	Engine::start();

	return 0;
}
