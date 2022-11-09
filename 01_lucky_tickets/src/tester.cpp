#include "tester.hpp"

#include <fstream>
#include <iostream>
#include <iomanip>

#include "profiler.hpp"

namespace tester
{
void Tester::Run(const std::shared_ptr<solver::ISolver>& solver, const std::string& test_path) {
  int i = 0;
  Profiler all_tests("All tests");
  while (true) {
    auto file_name = test_path + "test." + std::to_string(i);
    std::ifstream test_file(file_name + ".in");
    std::ifstream result_file(file_name + ".out");;
    if (!test_file.is_open() or !test_file.is_open() ) {
      return;
    }

    std::string test_input;
    std::string test_result;
    test_file >> test_input;
    result_file >> test_result;

    auto solver_result = solver->Solve(test_input);
    if (solver_result == test_result) {
      std::cout << "[Test " << i << "]: \033[1;32mOK\033[0m" << std::endl;
    }
    else {
      std::cout << "[Test " << i << "]: \033[1;31mFAILED\033[0m" << std::endl;
      std::cout << std::setw(10) << "Expected: " << test_result << std::endl;
      std::cout << std::setw(10) << "Actual: " << solver_result << std::endl << std::endl;
    }
    ++i;
  }
}

} // namespace tester
