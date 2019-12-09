#include <iostream>
#include "Logger.hpp"

Logger::Logger() {

}

void Logger::log(const std::string str) {
  std::cout << str << std::endl;
}

Logger::~Logger() {

}