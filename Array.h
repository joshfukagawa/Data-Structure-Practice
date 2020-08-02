#include <stdexcept>
#ifndef Array_h
#define Array_h
template <class T>
class Array {
    //overload stream insertion operator
    friend std::ostream& operator<< (std::ostream &out, const Array<T> &array) {
        out << '[';
        for (int i = 0; i < array.s; i++) {
            out << array.arr[i] << ((i != array.s-1) ? (", ") : ("")) ;
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
        //resize if at capacity
        if (s == c) {
            resize((c*=2));
        }
        arr[s++] = el;
        return s;
    }
    //insert an item at an existing index and returns the new length
    int insert(int idx, T el) {
        //Throw err if index is out of range
        if (idx >= s || idx < 0) {
            throw std::out_of_range("Error, index does not exist");
        }
        //resize if at capacity
        if (s == c) {
            resize((c*=2));
        }
        //insert item and shift trailing right
        for (int i = s + 1; i >= idx; i--) {
            arr[i] = (i != idx) ? (arr[i-1]) : (el);
        }
        return ++s;
    }
    //insert an item at index 0 and return size
    int prepend(T el) {
        return insert(0, el);
    }
    //remove item from last index and return it
    T pop() {
        return delete_idx(s-1);
    }
    //
    T delete_idx(int idx) {
        //throw err if empty
        if (s == 0) {
            throw std::length_error("Error, the array is empty");
        }
        //throw error if invalid idx
        if (idx >= s || idx < 0) {
            throw std::out_of_range("Error, index does not exist");
        }
        //save reference to item to delete
        T deleted_item = arr[idx];
        //remove item by shift trailing left
        for (int i = idx; i < s; i++) {
            arr[i] = arr[i + 1];
        }
        //decrement size
        s--;
        //resize if were at 1/4 capacity
        if ((s) == (c * 0.25)) {
            resize((c*=0.5));
        }
        return deleted_item;
    }
};
#endif /* Array_h */
