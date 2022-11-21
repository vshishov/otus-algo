#include "fibonacci_solver.hpp"

#include <iostream>

#include <boost/multiprecision/cpp_int.hpp>

namespace solver {

///--------------------------------
///   class BigInt
///--------------------------------
BigInt::BigInt(uint64_t n) {
    do {
        data.push_back(n % 10);
        n /= 10;
    } while (n);
}

BigInt::BigInt(BigInt& a) { data = a.data; }

BigInt& BigInt::operator=(const BigInt& a) {
    data = a.data;
    return *this;
}

std::size_t BigInt::Length() const { return data.size(); }

std::string BigInt::ToStr() const {
    std::stringstream ss;
    ss << *this;
    return ss.str();
}

BigInt& operator+=(BigInt& a, const BigInt& b) {
    int t = 0, s, i;
    auto n = a.Length();
    auto m = b.Length();
    if (m > n)
        a.data.append(m - n, 0);
    n = a.Length();
    for (i = 0; i < n; i++) {
        if (i < m)
            s = (a.data[i] + b.data[i]) + t;
        else
            s = a.data[i] + t;
        t = s / 10;
        a.data[i] = (s % 10);
    }
    if (t)
        a.data.push_back(t);
    return a;
}

BigInt operator+(const BigInt& a, const BigInt& b) {
    BigInt temp;
    temp = a;
    temp += b;
    return temp;
}

std::ostream& operator<<(std::ostream& out, const BigInt& a) {
    for (int i = a.data.size() - 1; i >= 0; --i)
        out << (short)a.data[i];
    return out;
}

///--------------------------------
///   class RecursFibonacciSolver
///--------------------------------
ResultData BaseFibonacciSolver::Solve(const InputData& input) {
    return Fibo(std::stoi(input[0])).ToStr();
}

///--------------------------------
///   class RecursFibonacciSolver
///--------------------------------
// Only 7 of tests
BigInt RecursFibonacciSolver::Fibo(int N) {
    uint64_t count = 0;
    if (N == 0)
        return 0;
    if (N == 1 or N == 2)
        return 1;

    std::cout << N << std::endl;
    return Fibo(N - 1) + Fibo(N - 2);
}

BigInt IterFibonacciSolver::Fibo(int N) {
    BigInt count = 0;
    if (N == 0)
        return 0;
    if (N == 1 or N == 2)
        return 1;

    BigInt a = 1;
    BigInt b = 1;
    BigInt c;
    for (int i = 3; i <= N; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

///--------------------------------
///   class BinetFibonacciSolver
///--------------------------------
BigInt BinetFibonacciSolver::Fibo(int N) {
    double sqrt_5 = std::sqrt(5);
    double phi = (1 + sqrt_5) / 2;
    double result = (std::pow(phi, N) - std::pow(-phi, -N)) / sqrt_5;

    return (uint64_t)result;
}

}  // namespace solver