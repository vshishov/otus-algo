#pragma once

#include "isolver.hpp"

#include <string>
#include <memory>

namespace tester {

class Tester {
public:
  void Run(const std::shared_ptr<solver::ISolver>& solver, const std::string& test_path);

private:
  // void RunTest()
};

}