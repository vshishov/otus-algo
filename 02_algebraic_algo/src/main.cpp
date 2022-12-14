#include <iostream>

#include "fibonacci_solver.hpp"
#include "power_solver.hpp"
#include "prime_solver.hpp"
#include "tester.hpp"

int main(int argc, char** argv) {
    tester::Tester tester;

    /// -------------
    ///     Power
    /// -------------
        tester.Run(std::make_shared<solver::IterPowerSolver>(),
        "../../02_algebraic_algo/tests/3.Power/");

    tester.Run(std::make_shared<solver::MultiPowerSolver>(),
               "../../02_algebraic_algo/tests/3.Power/");

    //    tester.Run(std::make_shared<solver::BinaryPowerSolver>(),
    //    "../../02_algebraic_algo/tests/3.Power/");

    /// -------------
    ///   Fibonacci
    /// -------------
    //    tester.Run(std::make_shared<solver::RecursFibonacciSolver>(),
    //               "../../02_algebraic_algo/tests/4.Fibo/");

    //    tester.Run(std::make_shared<solver::IterFibonacciSolver>(),
    //               "../../02_algebraic_algo/tests/4.Fibo/");

    //    tester.Run(std::make_shared<solver::BinetFibonacciSolver>(),
    //               "../../02_algebraic_algo/tests/4.Fibo/");

    /// ------------
    ///    Primes
    /// ------------
    //    tester.Run(std::make_shared<solver::IterPrimeSolver>(),
    //               "../../02_algebraic_algo/tests/5.Primes/");

    //    tester.Run(std::make_shared<solver::DivPrimeSolver>(),
    //               "../../02_algebraic_algo/tests/5.Primes/");

    //    tester.Run(std::make_shared<solver::EratosPrimeSolver>(),
    //               "../../02_algebraic_algo/tests/5.Primes/");

    //        tester.Run(std::make_shared<solver::EratosEvenPrimeSolver>(),
    //                   "../../02_algebraic_algo/tests/5.Primes/");

    //    tester.Run(std::make_shared<solver::EratosEvenBitsPrimeSolver>(),
    //               "../../02_algebraic_algo/tests/5.Primes/");

    return 0;
}
