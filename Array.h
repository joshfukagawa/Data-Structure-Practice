#ifndef Array_h
#define Array_h
template <class T>
class Array {
private:
    T* arr;
    int s;
    int c;
public:
    Array(int size) {
        s = 0;
        c = 16;
        arr = new T[16];
    };
    int size() {
        return s;
    };
};

#endif /* Array_h */
