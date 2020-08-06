#include "SListNode.h"
#include <iostream>
#ifndef SList_h
#define SList_h

template <class T>
class SList {
    //overload stream insertion operator
    friend std::ostream& operator<< (std::ostream &out, const SList<T> &list) {
        if (list.head == nullptr && list.tail == nullptr) {
            out << "{ Empty }";
            return out;
        }
        SListNode<T>* current_node = list.head;
        while(current_node != nullptr) {
            out << "{ " <<(current_node)->data << " }  => ";
            current_node = current_node->next;
        }
        return out;
    }
private:
    SListNode<T>* head;
    SListNode<T>* tail;
    int size;
public:
    SList() {
      head = nullptr;
      tail = nullptr;
      size = 0;
    }
    int get_size () {
        return size;
    }
    bool empty () {
        return size == 0;
    }

    void push_front (T val) {
        SListNode<T>* new_node = new SListNode <T>(val);
        if (head == nullptr && tail == nullptr) {
            //if list is empty
            //point head and tail to new node
            head = new_node;
            tail = new_node;
        } else {
            //if list is not empty
            //head gets pushed behind new node
            new_node->next = head;
            //new node becomes head
            head = new_node;
        }
    }
};
#endif /* SList_h */
