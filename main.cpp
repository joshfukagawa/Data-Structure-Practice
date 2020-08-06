#include <iostream>
#include "Array.h"
#include "SList.h"
#include <vector>
#include <cstdlib>

int main(int argc, const char * argv[]) {
    std::cout << std::boolalpha;
    SList<int> list;
    list.push_front(2);
    list.push_front(6);
    list.push_front(5);
    list.push_front(0);

    std::cout << list << std::endl;
    return 0;
}

// g++ main.cpp -o main
//./main