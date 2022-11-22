#pragma once

#include <chrono>
#include <functional>
#include <iostream>
#include <sstream>
#include <string>

// Profilers used for time measurement.
// Measured time is the time of life of the profiler

class ProfilerBase {
public:
    explicit ProfilerBase(const std::string& msg)
        : message(msg + ": "), start(std::chrono::steady_clock::now()) {}

protected:
    std::string message;
    std::chrono::steady_clock::time_point start;
};

// message is displayes in console via std
class Profiler : public ProfilerBase {
public:
    explicit Profiler(const std::string& msg = "", std::ostream& sout = std::cout)
        : ProfilerBase(msg), stream_out(sout) {}

    ~Profiler() {
        auto dur = std::chrono::steady_clock::now() - start;
        std::stringstream ss;
        stream_out << message << std::chrono::duration_cast<std::chrono::milliseconds>(dur).count()
                   << " ms" << std::endl;
    }

private:
    std::ostream& stream_out{std::cout};
};

