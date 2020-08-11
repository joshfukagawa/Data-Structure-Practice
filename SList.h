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
        if (index < size && index >= 0) {
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
    int push_front (T val) {
        SListNode<T>* new_node = new SListNode <T>(val);
        if (head == nullptr && tail == nullptr) {
            //if list is empty
            //point head and tail to new node
            head = new_node;
            tail = new_node;
            return ++size;
        } else {
            //if list is not empty
            //head gets pushed behind new node
            new_node->next = head;
            //new node becomes head
            head = new_node;
            return ++size;
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
    T front () {
        return head->data;
    }
    T back () {
        return tail->data;
    }
    int insert (int index, T value) {
        if (index >= size || index < 0) {
            //throw error if index is out of range (size must be at least 1)
            throw std::out_of_range("Error, invalid index");
        }

        if (index == 0) {
            return push_front(value);
        } else {
            //track current index
            int curr_idx = 0;
            //create new node
            SListNode<T>* new_node = new SListNode<T>(value);
            //iterate through nodes and stop at previous idx
            SListNode<T>* preceed_idx = head;
            while (curr_idx < (index - 1)) {
                preceed_idx = preceed_idx->next;
                curr_idx++;
            }
            //point new node's next to the previous item at index
            new_node->next = preceed_idx->next;
            preceed_idx->next = new_node;
            return ++size;
        }
    }
        T erase (int index) {
        if (index >= size || index < 0) {
            //throw error if index is out of range (size must be at least 1)
            throw std::out_of_range("Error, invalid index");
        }

        if (index == 0) {
            return pop_front();
        } else {
            //track current index
            int curr_idx = 0;
            //iterate through nodes and stop at previous idx
            SListNode<T>* preceed_idx = head;
            while (curr_idx < (index - 1)) {
                preceed_idx = preceed_idx->next;
                curr_idx++;
            }
            //save temporary reference to target and data
            SListNode<T>* target = preceed_idx->next;
            T temp_data = target->data;
            //point preceeding node's next to the item after
            preceed_idx->next = target->next;
            delete target;
            return temp_data;
        }
    }
    T n_from_end(int n) {
        if (n > size || n < 1) {
            //throw error if index is out of range (size must be at least 1)
            throw std::out_of_range("Error, invalid n");
        }

        //track current item num
            int curr_index = 0;
            //iterate through nodes and stop at previous idx
            SListNode<T>* curr_node = head;
            while (size - curr_index != n) {
                curr_node = curr_node->next;
                curr_index++;
            }

            return curr_node->data;
    }
};
#endif /* SList_h */
