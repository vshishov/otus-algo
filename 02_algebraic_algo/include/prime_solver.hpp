#pragma once

#include "isolver.hpp"

namespace solver {

class BasePrimeSolver : public ISolver {
public:
    ResultData Solve(const InputData&) override;

protected:
    virtual uint64_t Prime(int) = 0;
};

/// O(n^2)
class IterPrimeSolver : public BasePrimeSolver {
protected:
    uint64_t Prime(int N) override;

private:
    bool IsPrime(int N);
};

/// O(n * Sqrt(n) / Ln (n)).
class DivPrimeSolver : public BasePrimeSolver {
public:
    ~DivPrimeSolver();

protected:
    uint64_t Prime(int N) override;

private:
    bool IsPrime(int N);

private:
    int* primes;
};


/// O(n log(log n))
class EratosPrimeSolver : public BasePrimeSolver {
protected:
    uint64_t Prime(int N) override;
};

/// O(n/2 log( log( n/2 ) ) )
class EratosEvenPrimeSolver : public BasePrimeSolver {
protected:
    uint64_t Prime(int N) override;
};

class BitArray {
public:
    BitArray(std::size_t N);
    ~BitArray();

    bool operator[](std::size_t ind);

    bool get(std::size_t idx);
    void set(std::size_t idx, bool value);

private:
    inline std::size_t GetBasketIdx(std::size_t idx);
    inline std::size_t GetBitIdx(std::size_t idx);

private:
    const std::size_t BasketSize = sizeof(int) * 8;
    int* data;
};


/// O(n/2 log( log( n/2 ) ) )
class EratosEvenBitsPrimeSolver : public BasePrimeSolver {
protected:
    uint64_t Prime(int N) override;
};




}