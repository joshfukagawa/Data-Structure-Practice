#include <iostream>
#include "Array.h"
#include <vector>
#include <cstdlib>

int main(int argc, const char * argv[]) {
    std::cout << std::boolalpha;

    Array<int> a;

    for (int i = 0; i < 11; i++) {
        a.push(std::rand() % 6);
    }

    std::cout << "Array: " << a << std::endl;
    std::cout << a.remove(2) << std::endl;
    std::cout << "Array: " << a << std::endl;
    return 0;
}

// g++ main.cpp -o main
//./main