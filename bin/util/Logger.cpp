#include "Logger.h"

Logger* Logger::instance = NULL;

Logger::Logger() {

}

Logger* Logger::getLogger() {
	if (instance == NULL) {
		instance = new Logger();
	}

	return instance;
}

void Logger::log(LogLevel level, const char* text) {
	printf("[%s][%s] %s\n", getTimestamp().c_str(), getLevelText(level), text);
}