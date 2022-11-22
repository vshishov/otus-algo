#pragma once

#include <string>
#include <vector>

namespace solver {

using InputData = std::vector<std::string>;
using ResultData = std::string;

class ISolver {
public:
    virtual ~ISolver() = default;
    virtual ResultData Solve(const InputData&) = 0;
};

}  // namespace solver
