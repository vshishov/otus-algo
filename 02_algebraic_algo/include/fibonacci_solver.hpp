#pragma once

#include "isolver.hpp"

namespace solver {

class BaseFibonacciSolver : public ISolver {
public:
    ResultData Solve(const InputData&) override;

protected:
    virtual uint64_t Fibo(int) = 0;
};

class RecursFibonacciSolver : public BaseFibonacciSolver {
protected:
    uint64_t Fibo(int N) override;
};

class IterFibonacciSolver : public BaseFibonacciSolver {
protected:
    uint64_t Fibo(int N) override;
};


}