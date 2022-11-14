#include "power_solver.hpp"

#include <algorithm>
#include <charconv>
#include <iomanip>
#include <iostream>
#include <sstream>

#include <math.h>

#include <boost/lexical_cast.hpp>

namespace solver {

ResultData BasePowerSolver::Solve(const InputData& input) {
    //    double val;
    //    std::to_chars( val);
    std::string str_base = input[0];
    //    double l = 0.0;

    //    const auto res = std::from_chars(str_base.data(), str_base.data() + str_base.size(), l);

    auto l = boost::lexical_cast<double>(str_base);
    auto l2 = ::atof(str_base.c_str());

    std::cout << ">>> " << input[0] << " " << l << std::endl;
    auto reslut = Pow(std::stof(input[0]), std::stoll(input[1]));
    reslut += 0.0;
    std::ostringstream strs;
    strs << std::setprecision(11) << reslut;
    printf("+ %.1f\n", reslut);
    auto str = boost::lexical_cast<std::string>(reslut);
    return strs.str();
}

double IterPowerSolver::Pow(double base, uint64_t exp) {
    std::cout << base << " " << exp << std::endl;
    double result = 1.0;
    for (uint64_t i = 0; i < exp; ++i) {
        result *= base;
    }
    return result;
}

// O(logN)
double BinaryPowerSolver::Pow(double base, uint64_t exp) {
    std::cout << "pow " << base << " " << exp << std::endl;
    double result = 1.0;
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
