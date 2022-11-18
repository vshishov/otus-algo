#pragma once

#include <ostream>
#include <string>

#include "isolver.hpp"

namespace solver {

class BigInt {
public:
    BigInt(int n = 0);
    BigInt(const BigInt& a);

    std::size_t Length() const;
    std::string ToStr() const;

    friend BigInt& operator+=(BigInt&, const BigInt&);
    friend BigInt operator+(const BigInt&, const BigInt&);
    friend std::ostream& operator<<(std::ostream&, const BigInt&);

private:
    std::string data;
};

class BaseFibonacciSolver : public ISolver {
public:
    ResultData Solve(const InputData&) override;

protected:
    virtual BigInt Fibo(int) = 0;
};

class RecursFibonacciSolver : public BaseFibonacciSolver {
protected:
    BigInt Fibo(int N) override;
};

class IterFibonacciSolver : public BaseFibonacciSolver {
protected:
    BigInt Fibo(int N) override;
};

}  // namespace solver