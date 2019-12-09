#pragma once
#include <string>

class Logger {
private:
public:
    Logger();
    void log(const std::string fmt);
    ~Logger();
protected:

};