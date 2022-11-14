#include "tester.hpp"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include "thread"

#include "profiler.hpp"

namespace tester {
void Tester::Run(const std::shared_ptr<solver::ISolver>& solver, const std::string& test_path) {
    int i = 0;
    Profiler all_tests("All tests");
    while (true) {
        auto file_name = test_path + "test." + std::to_string(i);
        std::ifstream test_file(file_name + ".in");
        std::ifstream result_file(file_name + ".out");
        ;
        if (!test_file.is_open() or !test_file.is_open()) {
            return;
        }

        std::vector<std::string> test_input;
        std::string test_result;

        std::copy(std::istream_iterator<std::string>(test_file),
                  std::istream_iterator<std::string>(), std::back_inserter(test_input));

        result_file >> test_result;

        auto start = std::chrono::steady_clock::now();
        auto solver_result = solver->Solve(test_input);
//        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        auto dur = std::chrono::steady_clock::now() - start;
        auto dur_ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
        if (solver_result == test_result) {
            std::cout << "[Test " << i << "]: \033[1;32mOK\033[0m (" << dur_ms << "ms)" <<std::endl;
        } else {
            std::cout << "[Test " << i << "]: \033[1;31mFAILED\033[0m" << std::endl;
            std::cout << std::setw(10) << "Expected: " << test_result << std::endl;
            std::cout << std::setw(10) << "Actual: " << solver_result << std::endl << std::endl;
        }
        ++i;

        if (i > 7 )
            return ;
    }
}

}  // namespace tester
