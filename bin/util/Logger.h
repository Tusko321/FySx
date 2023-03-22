#pragma once

#include <stdio.h>
#include <ctime>
#include <format>
#include <string>
#define LOGGER Logger::GetLogger()

enum LogLevel {
	DEBUG,
	INFO,
	WARN,
	ERROR,
	FATAL
};

class Logger {
private:
	Logger();
	Logger(const Logger&) {};
	Logger& operator=(const Logger&) { return *this; };
	static Logger* instance;

	inline const char* getLevelText(LogLevel level) {
		const char* text{};
		switch (level) {
		case DEBUG: text = "DEBUG"; break;
		case INFO: text = "INFO"; break;
		case WARN: text = "WARN"; break;
		case ERROR: text = "ERROR"; break;
		case FATAL: text = "FATAL"; break;
		default: text = "DEBUG"; break;
		}
		return text;
	}

	std::string getTimestamp() {
		time_t now = time(0);

		std::string date_time;
		char buf[64];
		ctime_s(buf, sizeof(buf), &now);

		date_time = buf;
		date_time.erase(std::remove(date_time.begin(), date_time.end(), '\n'), date_time.cend());

		return date_time;
	}
public:
	void log(LogLevel level, const char* text);

	static Logger* getLogger();
};