#include "power_solver.hpp"

#include <iostream>

#include <math.h>

#include <boost/lexical_cast.hpp>

namespace solver {

///-------------------------
///  class BasePowerSolver
///-------------------------
ResultData BasePowerSolver::Solve(const InputData& input) {
    auto reslut = Pow(boost::lexical_cast<long double>(input[0]), std::stoll(input[1]));
    constexpr size_t precision = 11;
    std::stringstream sout;
    sout.precision(precision);
    sout << std::fixed << reslut;
    return sout.str();
}

///-------------------------
///  class IterPowerSolver
///-------------------------
long double IterPowerSolver::Pow(long double base, uint64_t exp) {
    long double result = 1.0;
    for (uint64_t i = 0; i < exp; ++i) {
        result *= base;
    }
    return result;
}

///-------------------------
///  class IterPowerSolver
///-------------------------
long double MultiPowerSolver::Pow(long double base, uint64_t exp) {
    if (exp == 0)
        return 1;
    if (exp == 1)
        return base;

    size_t p = 2;
    long double result = base * base;
    while (2 * p <= exp) {
        p *= 2;
        result *= result;
    }
    for (size_t i = p; i < exp; ++i)
        result *= base;

    return result;
}

///-------------------------
/// class BinaryPowerSolver
///-------------------------
long double BinaryPowerSolver::Pow(long double base, uint64_t exp) {
    long double result = 1.0;
    while (exp >= 1) {
        exp /= 2;
        base *= base;
        if (exp % 2 == 1) {
            result *= base;
        }
    }
    return result;
}

}  // namespace solver
