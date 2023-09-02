#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H
#include <chrono>

class TimeManager {
private:
    std::chrono::time_point<std::chrono::system_clock> tp1;
    std::chrono::time_point<std::chrono::system_clock> tp2;

public:
    TimeManager();

    void Reset();

    float GetElapsedTime();
};
#endif