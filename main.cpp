#include <iostream>
#include "Array.h"
#include "SList.h"
#include <vector>
#include <cstdlib>

int main(int argc, const char * argv[]) {
    std::cout << std::boolalpha;
    SList<int> list;

    for (int i = 0; i < 3; i++) {
        list.push_front(i*3);
    }


    std::cout << list << std::endl;
    std::cout << list.pop_front() << std::endl;
    std::cout << list << std::endl;
    std::cout << list.pop_front() << std::endl;
    std::cout << list << std::endl;
    std::cout << list.pop_front() << std::endl;
    std::cout << list << std::endl;
    return 0;
}

// g++ main.cpp -o main
//./main