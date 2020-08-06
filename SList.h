#include "ListNode.h"
#ifndef SList_h
#define SList_h

template <class T>
class SList {
    //overload stream insertion operator
    friend std::ostream& operator<< (std::ostream &out, const SList<T> &list) {
        if (list.size == 0) {
            out << "{ Empty }";
            return out;
        }

        return out;
    }
private:
    ListNode<T>* head;
    ListNode<T>* tail;
    int size;
public:
    SList() {
      head = nullptr;
      tail = nullptr;
      size = 0;
    }
    int size () {
        return size;
    }
};
#endif /* SList_h */
