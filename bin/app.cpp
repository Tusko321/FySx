#include "Window.h"
#include "Logger.h"

int main(int argc, char* args[]) {
	Logger::getLogger()->log(INFO, "Before window");

	Window* window = new Window(1200, 800, "Wind'er");

	Logger::getLogger()->log(INFO, "After window");

	delete window;

	return 0;
}