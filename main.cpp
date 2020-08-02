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
    std::cout << a.find(20) << std::endl;
    return 0;
}

// g++ main.cpp -o main
//./main