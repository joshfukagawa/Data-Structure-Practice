#include <iostream>
#include "Array.h"
int main(int argc, const char * argv[]) {
    std::cout << std::boolalpha;

    Array<int> a;

    for (int i = 0; i < 11; i++) {
        a.push(i + 1);
    }

    std::cout << "Array: " << a.insert(4, 9000) << std::endl;
    return 0;
}

// g++ main.cpp -o main
//./main