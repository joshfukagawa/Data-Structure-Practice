#ifndef SListNode_h
#define SListNode_h

template <class T>
class SListNode {
  public:
    SListNode(T val) {
      data = val;
      next = nullptr;
    }
    T data;
    SListNode* next;
};
#endif /* SListNode_h */
