#include <vector>

#include "isolver.hpp"

namespace solver {

using Array = std::vector<uint64_t>;

class BasePowerSolver : public ISolver {
public:
    ResultData Solve(const InputData&) override;

public:
    virtual double Pow(double base, uint64_t exp) = 0;
};

class IterPowerSolver : public BasePowerSolver {
public:
    double Pow(double base, uint64_t exp);
};

class BinaryPowerSolver : public BasePowerSolver {
public:
    double Pow(double base, uint64_t exp);
};



}  // namespace solver