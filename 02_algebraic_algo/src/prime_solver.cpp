#include "prime_solver.hpp"

#include <iostream>
#include <math.h>
#include <string.h>

namespace solver {

//-------------------------
// class BasePrimeSolver
//-------------------------
ResultData BasePrimeSolver::Solve(const InputData& input) {
    return std::to_string(Prime(std::stoi(input[0])));
}

//-------------------------
// class IterPrimeSolver
//-------------------------
uint64_t IterPrimeSolver::Prime(int N) {
    uint64_t count = 0;

    for (int i = 1; i <= N; ++i) {
        if (IsPrime(i)) {
            ++count;
        }
    }
    return count;
}

bool IterPrimeSolver::IsPrime(int N) {
    if (N == 1) return false;
    if (N == 2) return true;
    if (N % 2 == 0) return false;

    for (int num = 3; num <= std::sqrt(N); num += 2) {
        if (N % num == 0) {
            return false;
        }
    }

    return true;
}

//-------------------------
// class DivPrimeSolver
//-------------------------
DivPrimeSolver::~DivPrimeSolver() {
    if (primes) {
        delete primes;
    }
}

uint64_t DivPrimeSolver::Prime(int N) {
    if (N == 1) return 0;
    if (N == 2) return 1;

    delete primes;
    primes = new int[N / 2];
    int i = 0;
    primes[i++] = 2;
    for (int num = 3; num <= N; ++num) {
        if (IsPrime(num)) {
            primes[i++] = num;
        }
    }
    return i;
}

bool DivPrimeSolver::IsPrime(int N) {
    auto sqrt =  std::sqrt(N);
    for (auto i = 0; primes[i] <= sqrt; ++i) {
        if (N % primes[i] == 0) {
            return false;
        }
    }

    return true;
}

//-------------------------
// class EratosPrimeSolver
//-------------------------
uint64_t EratosPrimeSolver::Prime(int N) {
    if (N == 1) return 0;
    if (N == 2) return 1;

    auto array = new bool[N + 1];

    for (int i = 0; i <= N; ++i) {
        array[i] = true;
    }

    for (int i = 2; i * i <= N; ++i) {
        if (array[i]) {
            for (int j = i * i; j <= N; j += i) {
                array[j] = false;
            }
        }
    }

    int count = 0;
    for (int i = 2; i <= N; ++i) {
        if (array[i]) {
            ++count;
        }
    }

    return count;
}


//-------------------------
// class EratosEvenPrimeSolver
//-------------------------
uint64_t EratosEvenPrimeSolver::Prime(int N) {
    if (N == 1) return 0;
    if (N == 2) return 1;

    auto array_size = (N + 1) / 2;
    auto array = new bool[array_size + 1];

    for (int i = 0; i <= array_size; ++i) {
        array[i] = true;
    }

    for (int i = 3; i * i <= N; i += 2) {
        if (array[i / 2]) {
            for (int j = i * i; j <= N; j += i) {
                if (j % 2 != 0) {
                    array[j / 2] = false;
                }
            }
        }
    }

    int count = 0;
    for (int i = 1; i <= array_size; ++i) {
        if (array[i]) {
            ++count;
        }
    }

    return count;
}


///------------------------------
/// class EratosOptimPrimeSolver
///------------------------------
uint64_t EratosEvenBitsPrimeSolver::Prime(int N) {
    if (N == 1) return 0;
    if (N == 2) return 1;

    auto Narr = (N + 1) / 2;
    BitArray array(Narr);

    for (int i = 0; i <= Narr ; ++i) {
        array.set(i, true);
    }


    for (int i = 3; i * i <= N; i+=2) {
        if (array.get(i / 2)) {
            for (int j = i * i; j <= N; j += i) {
                if ( j % 2 != 0) {
                    array.set(j / 2, false);
                }
            }
        }
    }

    int count = 0;
    for (int i = 1; i <= Narr; ++i) {
        if (array.get(i)) {
            ++count;
        }
    }

    return count;
}

///-------------------------
///     class BitArray
///-------------------------
BitArray::BitArray(std::size_t N) {
    auto size = N / BasketSize + 1;
    data = new int[size];
}

BitArray::~BitArray() {
    delete data;
}

bool BitArray::get(std::size_t idx) {
    auto busket_idx = GetBasketIdx(idx);
    auto bit_idx = GetBitIdx(idx);
    return data[busket_idx] & (1 << bit_idx);
}
void BitArray::set(std::size_t idx, bool value) {
    auto busket_idx = GetBasketIdx(idx);
    auto bit_idx = GetBitIdx(idx);
    if (value) {
        data[busket_idx] |= (1 << bit_idx);
    }
    else {
        data[busket_idx] &= ~(1 << bit_idx);
    }
}

std::size_t BitArray::GetBasketIdx(std::size_t idx) {
    return idx / BasketSize;
}

std::size_t BitArray::GetBitIdx(std::size_t idx) {
    return idx % BasketSize;
}

}  // namespace solver