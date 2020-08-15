#include <iostream>
#include "Array.h"
#include "SList.h"
#include "DynamicQueue.h"
#include <vector>
#include <cstdlib>

int main(int argc, const char * argv[]) {
    std::cout << std::boolalpha;
    DynamicQueue<int> q;

    for (int i = 0; i < 7; i++) {
        q.enqueue((i + 1));
        std::cout << q << std::endl;
    }


    return 0;
}

// g++ main.cpp -o main
//./main