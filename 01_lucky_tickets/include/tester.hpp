#pragma once

#include <memory>
#include <string>

#include "isolver.hpp"

namespace tester {

class Tester {
public:
    void Run(const std::shared_ptr<solver::ISolver>& solver, const std::string& test_path);

private:
    // void RunTest()
};

}  // namespace tester