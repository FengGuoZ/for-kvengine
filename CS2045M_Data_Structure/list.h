// In all List operation, remember: first link new line, then modify old line
#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <sstream>

template <typename T>
class List {
public:
    struct ListNode {
        ListNode() = default;
        ListNode(const T& _data) : data(_data) {}
        T data;
        ListNode* next = nullptr;
        ListNode* prev = nullptr;
    };

    List();
    ~List();

    void PushFront(const T& val);
    void PushBack(const T& val);

    bool PopFront(T& val);
    bool PopBack(T& val);

    bool Back(T& val);
    bool Front(T& val);

    size_t Size() const {
        return mSize;
    }
    bool Empty() const {
        return mSize == 0;
    }

    ListNode* GetPos(size_t pos);

    ListNode* GetHead() {
        if (mSize == 0) {
            return nullptr;
        }
        return GetPos(0);
    }
    ListNode* GetTail() {
        if (mSize == 0) {
            return nullptr;
        }
        return GetPos(mSize - 1);
    }

    ListNode* GetNext(ListNode* node) {
        if (node == nullptr || node->next == mTail) {
            return nullptr;
        }

        return node->next;
    }

    ListNode* GetPrev(ListNode* node) {
        if (node == nullptr || node->prev == mHead) {
            return nullptr;
        }

        return node->prev;
    }

    bool Insert(const size_t pos, const T& val);
    bool Remove(const size_t pos, T& val);

    bool Get(const size_t pos, T& val);
    bool Set(const size_t pos, const T& val);

    void Clear();

    std::string ToString() const;

private:
    size_t mSize = 0;           //valid range [0, mSize)
    ListNode* mHead = nullptr;  //virtual head, no actual node
    ListNode* mTail = nullptr;  //virtual tail, no actual node
};

#include "list.cpp"
#endif  // LIST_H