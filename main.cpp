#include <iostream>
#include "Array.h"
#include "SList.h"
#include <vector>
#include <cstdlib>

int main(int argc, const char * argv[]) {
    std::cout << std::boolalpha;
    SList<int> list;

    for (int i = 0; i < 7; i++) {
        list.push_back((i + 1) * 5);
    }


    std::cout << list << std::endl;
    std::cout << list.remove(35) << std::endl;
    std::cout << list << std::endl;
    return 0;
}

// g++ main.cpp -o main
//./main