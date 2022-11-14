#pragma once

#include <string>

namespace solver {

class ISolver {
public:
    virtual ~ISolver() = default;
    virtual std::string Solve(const std::string&) = 0;
};

}  // namespace solver
