#include <stdexcept>
#include <iostream>
#ifndef FixedQueue_h
#define FixedQueue_h

template <class T>
class FixedQueue {
    //overload stream insertion operator
    // friend std::ostream& operator<< (std::ostream &out, const FixedQueue<T> &q) {
    //     if (q.empty()) {
    //         out << "{ Empty }";
    //         return out;
    //     }
    //     int temp_read = q.read;
    //     while(temp_read - write != 1 || temp_read - write != -1) {
    //       out << "{" << storage[temp_read] << "}";
    //       temp_read = temp
    //     }
    //     return out;
    // }
private:
  int write;
  int read;
  int capacity;
  T* storage;
public:
    FixedQueue(int size) {
      //initialize new array with user-defined size
      write = 0;
      read = 0;
      storage = new T[size + 1];
      capacity = size + 1;
    }
    int enqueue(T val) {
      if (full()) {
        //throw error if queue is full
        throw std::length_error("Error: Queue is full");
      }

      storage[write] = val;
      write = ((write + 1) % capacity);
      std::cout << val << " was added to the queue!" << std::endl;
      return write;
    }
    T dequeue() {
        if (empty()) {
        //throw error if queue is empty
        throw std::length_error("Error: Queue is empty");
      }

      T temp_data = storage[read];
      read = ((read + 1) % capacity);
      return temp_data;
    }
    bool empty() {
      return  (read == write);
    }
    bool full() {
      return ((write + 1) % capacity == read);
    }
};
#endif /* FixedQueue_h */
