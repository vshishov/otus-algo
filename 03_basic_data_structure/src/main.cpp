#include <iostream>

#include "arrays.hpp"
#include "profiler.hpp"
#include "tester.hpp"

using namespace otus;

template <typename T>
void test_add_array(IArray<T>* array, size_t size) {
    Profiler pro(std::to_string(size));
    for (size_t i = 0; i < size; ++i) {
        array->add(i);
    }
}

template <typename T>
void print_array(IArray<T>* array) {
    for (size_t i = 0; i < array->size(); ++i) {
        std::cout << array->get(i) << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char** argv) {
    //    TestArray(new MatrixArray<int>(), 100'000);

    //    return 0;

    //    FactorArray<int> arr;
    auto arr = new MatrixArray<int>(5);

    for (int i = 0; i < 15; ++i) {
        arr->add(i);
    }

    std::cout << "sz " << arr->size() << std::endl;
    arr->add(123456789, 5);
    std::cout << "sz " << arr->size() << std::endl;

    std::cout << "rm " << arr->remove(5) << std::endl;
    std::cout << "rm " << arr->remove(15) << std::endl;
    std::cout << "rm " << arr->remove(13) << std::endl;

    print_array(arr);

    std::cout << std::endl;
    arr->remove(1);

    arr->add(100500);
    arr->add(777);

    print_array(arr);
    std::cout << std::endl;

    std::cout << std::endl << "SingleArray" << std::endl;
    test_add_array(new SingleArray<int>(), 1'000);
    test_add_array(new SingleArray<int>(), 10'000);
    test_add_array(new SingleArray<int>(), 100'000);
//    test_add_array(new SingleArray<int>(), 1'000'000);
//    test_add_array(new SingleArray<int>(), 10'000'000);
//    test_add_array(new SingleArray<int>(), 100'000'000);

    std::cout << std::endl << "VectorArray" << std::endl;
    test_add_array(new VectorArray<int>(), 1'000);
    test_add_array(new VectorArray<int>(), 10'000);
    test_add_array(new VectorArray<int>(), 100'000);
    test_add_array(new VectorArray<int>(), 1'000'000);
//    test_add_array(new VectorArray<int>(), 10'000'000);
//    test_add_array(new VectorArray<int>(), 100'000'000);

    std::cout << std::endl << "FactorArray" << std::endl;
    test_add_array(new FactorArray<int>(), 1'000);
    test_add_array(new FactorArray<int>(), 10'000);
    test_add_array(new FactorArray<int>(), 100'000);
    test_add_array(new FactorArray<int>(), 1'000'000);
    test_add_array(new FactorArray<int>(), 10'000'000);
    test_add_array(new FactorArray<int>(), 100'000'000);


    //    print_array(new MatrixArray<int>());

    return 0;
}
