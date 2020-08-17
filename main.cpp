#include <iostream>
#include "Array.h"
#include "SList.h"
#include "DynamicQueue.h"
#include "FixedQueue.h"
#include <vector>
#include <cstdlib>

int main(int argc, const char * argv[]) {
    std::cout << std::boolalpha;
    FixedQueue<int> q(3);

    q.enqueue(1);
    q.enqueue(2);
    std::cout << q.dequeue() << " was removed!" << std::endl;
    q.enqueue(3);
    q.enqueue(4);
    std::cout << q.dequeue() << " was removed!" << std::endl;
    std::cout << q.dequeue() << " was removed!" << std::endl;
    std::cout << q.dequeue() << " was removed!" << std::endl;
    q.enqueue(5);
    q.enqueue(6);
    std::cout << q.dequeue() << " was removed!" << std::endl;
    std::cout << q.dequeue() << " was removed!" << std::endl;

    return 0;
}

// g++ main.cpp -o main
//./main