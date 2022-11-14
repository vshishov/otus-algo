#include "fibonacci_solver.hpp"

#include <iostream>

namespace solver {

ResultData BaseFibonacciSolver::Solve(const InputData& input) {
    return std::to_string(Fibo(std::stoi(input[0])));
}

// Only 7 of tests
uint64_t RecursFibonacciSolver::Fibo(int N) {
    uint64_t count = 0;
    if (N == 0) return 0;
    if (N == 1 or N == 2) return 1;

    std::cout << N << std::endl;
    return Fibo(N - 1) + Fibo(N - 2);
}

uint64_t IterFibonacciSolver::Fibo(int N) {
    uint64_t count = 0;
    if (N == 0) return 0;
    if (N == 1 or N == 2) return 1;

    uint64_t a=1;
    uint64_t b=1;
    uint64_t c;
    for (int i = 3; i <= N; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

}  // namespace solver