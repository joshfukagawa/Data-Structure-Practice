#include "SListNode.h"
#include <stdexcept>
#include <iostream>
#ifndef DynamicQueue_h
#define DynamicQueue_h

template <class T>
class DynamicQueue {
    //overload stream insertion operator
    friend std::ostream& operator<< (std::ostream &out, const DynamicQueue<T> &q) {
        if (q.head == nullptr && q.tail == nullptr) {
            out << "{ Empty }";
            return out;
        }
        SListNode<T>* current_node = q.head;
        while(current_node != nullptr) {
            out << "{ " <<(current_node)->data << " }";
            if (current_node->next != nullptr) {
                out << " => ";
            }
            current_node = current_node->next;
        }
        return out;
    }
private:
    SListNode<T>* head;
    SListNode<T>* tail;
    int size;
public:
    DynamicQueue() {
      head = nullptr;
      tail = nullptr;
      size = 0;
    }
    int enqueue(T val) {
      SListNode<T>* new_node = new SListNode<T>(val);
      if (head == nullptr && tail == nullptr) {
        //if queue is empty set head and tail new node
        head = new_node;
        tail = new_node;
      } else {
        //if queue is not empty, add new node to tail
        tail->next = new_node;
        tail = new_node;
      }

      return ++size;
    }
};
#endif /* DynamicQueue_h */
