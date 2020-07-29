#include <iostream>
#include "Array.h"
int main(int argc, const char * argv[]) {
    std::cout << std::boolalpha;

    Array<int> a;

    std::cout << a << std::endl;
    return 0;
}

// g++ main.cpp -o main
//./main