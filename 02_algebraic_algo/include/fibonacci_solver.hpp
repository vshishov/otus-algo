#pragma once

#include <ostream>
#include <string>

#include "isolver.hpp"

namespace solver {

class BigInt {
public:
    BigInt(uint64_t n = 0);
    BigInt(BigInt& a);
    BigInt& operator=(const BigInt&);

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

    virtual BigInt Fibo(int) = 0;
};

///  O(2^N)
class RecursFibonacciSolver : public BaseFibonacciSolver {
public:
    BigInt Fibo(int) override;
};

/// O(N)
class IterFibonacciSolver : public BaseFibonacciSolver {
public:
    BigInt Fibo(int N) override;
};

/// O(1)
class BinetFibonacciSolver : public BaseFibonacciSolver {
public:
    BigInt Fibo(int N) override;
};


}  // namespace solver