#include <iostream>
#include "Array.h"
#include "SList.h"
#include <vector>
#include <cstdlib>

int main(int argc, const char * argv[]) {
    std::cout << std::boolalpha;
    SList<int> list;
    std::cout << list.empty() << std::endl;
    return 0;
}

// g++ main.cpp -o main
//./main