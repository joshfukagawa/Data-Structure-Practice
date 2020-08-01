#include <stdexcept>
#ifndef Array_h
#define Array_h
template <class T>
class Array {
    //overload stream insertion operator
    friend std::ostream& operator<< (std::ostream &out, const Array<T> &array) {
        out << '[';
        for (int i = 0; i < array.c; i++) {
            out << array.arr[i] << ((i != array.c-1) ? (", ") : ("")) ;
        }
        out << ']';
        return out;
    }
private:
    T* arr;
    int s;
    int c;
    void resize(int new_capacity) {
        //create new array
        T* new_arr = new T[new_capacity];
        //copy over old elements
        for (int i = 0; i < s; i++) {
            new_arr[i] = arr[i];
        }
        //free memory
        delete[] arr;
        //reassign to new array
        arr = new_arr;
    }
public:
    //default constructor
    Array() {
        s = 0;
        c = 16;
        arr = new T[c];
    }
    //single arg constructor
    Array(int size) {
        //init size to zero
        s = 0;
        c = 16;

        //if input size is > 16, increase c by factor of 2
        if (size > c) {
            while (size > c) {
                c*=2;
            }
        }
        //initialize arr to array of c capacity
        arr = new T[c];
    };
    //return size
    int size() {
        return s;
    };
    //return capacity
    int capacity() {
        return c;
    }
    //returns boolean if size == 0
    bool is_empty () {
        return s == 0;
    }
    //returns item at index (with boundschecking)
    T at (int i) {
        if (i < 0 || i >= c){
            throw std::out_of_range("Error, index out of range");
        }
        return arr[i];
    }

    //adds an item to end of array and returns new length
    int push(T el) {
        if (s == c) {
            resize((c*=2));
        }
        arr[s++] = el;
        return s;
    }
    //insert an item at an index and returns the new length
    int insert(int idx, T el) {
        if (s == c) {
            resize((c*=2));
        }
        for (int i = s + 1; i >= idx; i--) {
            arr[i] = (i != idx) ? (arr[i-1]) : (el);
        }
        return ++s;
    }
};
#endif /* Array_h */
