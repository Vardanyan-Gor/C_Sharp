#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <thread>
class Logger {
    static std::chrono::system_clock::time_point startTime;

public:
    static void Init() {
        startTime = std::chrono::system_clock::now();
        std::time_t t = std::chrono::system_clock::to_time_t(startTime);
        std::cout << "[Logger started at " << std::ctime(&t) << "]\n";
    }

    static void Log(const std::string& msg) {
        auto now = std::chrono::system_clock::now();
        std::time_t t = std::chrono::system_clock::to_time_t(now);
        std::string timeStr = std::ctime(&t);
        if (!timeStr.empty() && timeStr.back() == '\n') timeStr.pop_back();

        std::cout << "[" << timeStr << "] " << msg << "\n";
    }
};

std::chrono::system_clock::time_point Logger::startTime;

int main() {
    Logger::Init();

    Logger::Log("Программа запущена.");
    Logger::Log("Создаю объект...");
    std::this_thread::sleep_for(std::chrono::seconds(2));
    Logger::Log("Работа завершена.");

    return 0;
}


