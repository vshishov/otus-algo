#include <iostream>

#include "fibonacci_solver.hpp"
#include "power_solver.hpp"
#include "tester.hpp"

int main(int argc, char** argv) {
    //    float a;
    //    std::cin >> a;

    tester::Tester tester;
    //    tester.Run(std::make_shared<solver::IterPowerSolver>(),
    //    "../../02_algebraic_algo/tests/3.Power/"); solver::BinaryPowerSolver bin; auto val =
    //    bin.Pow(1.001, 1000); std::cout << bin.Pow(1.001, 1000); // 2.71692393224
    //    tester.Run(std::make_shared<solver::BinaryPowerSolver>(),
    //    "../../02_algebraic_algo/tests/3.Power/");

//    tester.Run(std::make_shared<solver::RecursFibonacciSolver>(),
//               "../../02_algebraic_algo/tests/4.Fibo/");

    tester.Run(std::make_shared<solver::IterFibonacciSolver>(),
               "../../02_algebraic_algo/tests/4.Fibo/");

    return 0;
}
