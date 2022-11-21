#include <vector>

#include "isolver.hpp"

namespace solver {

using Array = std::vector<uint64_t>;

class BasePowerSolver : public ISolver {
public:
    ResultData Solve(const InputData&) override;

public:
    virtual long double Pow(long double base, uint64_t exp) = 0;
};

/// O(N)
class IterPowerSolver : public BasePowerSolver {
public:
    long double Pow(long double base, uint64_t exp);
};

/// O(N/2+LogN) = O(N)
class MultiPowerSolver : public BasePowerSolver {
public:
    long double Pow(long double base, uint64_t exp);
};

/// O(LogN)
class BinaryPowerSolver : public BasePowerSolver {
public:
    long double Pow(long double base, uint64_t exp);
};



}  // namespace solver