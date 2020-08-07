#include "SListNode.h"
#include <stdexcept>
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
    T value_at(int index) {
        if (index < size) {
            SListNode<T>* current_node = head;
            for (int pos = 0; pos < index; pos++) {
                //traverse for pos < index
                current_node = current_node->next;
            }
        return current_node->data;
        } else {
            throw std::out_of_range("Error, index does not exist");
        }
    }
    void push_front (T val) {
        SListNode<T>* new_node = new SListNode <T>(val);
        if (head == nullptr && tail == nullptr) {
            //if list is empty
            //point head and tail to new node
            head = new_node;
            tail = new_node;
            size++;
        } else {
            //if list is not empty
            //head gets pushed behind new node
            new_node->next = head;
            //new node becomes head
            head = new_node;
            size++;
        }
    }
    T pop_front () {
         if (head == nullptr && tail == nullptr) {
             //if list is empty, throw exception
             throw std::out_of_range("Error, empty list");
         }

         if (head == tail) {
            //if list only has one item left
            //copy data
            T temp_data = head->data;
            //delete node
            delete head;
            //set head and tail to null
            head = nullptr;
            tail = nullptr;
            //decrement size
            size--;
            //return deleted data
            return temp_data;
         } else {
             //list has more than one item
            //create temp ref to node and data
            T temp_data = head->data;
            SListNode<T>* temp_node = head;
            //set head to the next node
            head = temp_node->next;
            //delete old head node
            delete temp_node;
            //decrement size
            size--;
            //return deleted data
            return temp_data;
         }
    }
    int push_back(T val) {
        SListNode<T>* new_node = new SListNode<T>(val);
        if (head == nullptr && tail == nullptr) {
            //if list is empty, set head and tail to new node
            head = new_node;
            tail = new_node;
            return ++size;
        } else {
            //if list is not empty
            //push new node past tail
            tail->next = new_node;
            //new node becomes tail
            tail = new_node;
            return ++size;
        }
    }
     T pop_back () {
         if (head == nullptr && tail == nullptr) {
             //if list is empty, throw exception
             throw std::out_of_range("Error, empty list");
         }

         if (head == tail) {
            //if list only has one item left
            T temp_data = tail->data;
            //set head and tail to null, decrement size, and return data
            delete tail;
            head = nullptr;
            tail = nullptr;
            size--;
            return temp_data;
         } else {
             //list has more than one item
            T temp_data = tail->data;
            SListNode<T>* temp_node = tail;
            //search for item that preceeds tail
            SListNode<T>* preceed_tail = head;
            while (preceed_tail->next->next != nullptr) {
                preceed_tail = preceed_tail->next;
            }
            //set next of preceeding tail to null
            preceed_tail->next = nullptr;
            //preceed tail becomes tail
            tail = preceed_tail;
            //delete former tail
            delete temp_node;
            //return former data
            return temp_data;
         }
    }
    T front() {
        return head->data;
    }
    T back() {
        return tail->data;
    }
};
#endif /* SList_h */
