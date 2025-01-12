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

    List() {
        mHead = new ListNode();
        mTail = new ListNode();
        mHead->next = mTail;
        mTail->prev = mHead;
    }
    
    void PushFront(const T& val) {
        //create new tail
        ListNode* newNode = new ListNode();
        newNode->next = mHead;
        newNode->prev = nullptr;

        //modify old head
        mHead->data = val;
        mHead->prev = newNode;

        //move mHead
        mHead = newNode;
        mSize++;
    }

    void PushBack(const T& val) {
        // create new tail
        ListNode* newNode = new ListNode();
        newNode->prev = mTail;
        newNode->next = nullptr;

        // modify old tail
        mTail->data = val;
        mTail->next = newNode;

        // move mTail
        mTail = newNode;
        mSize++;
    }

    bool PopFront(T& val) {
        if (Empty()) {
            return false;
        }

        ListNode* target = mHead->next;
        target->prev->next = target->next;
        target->next->prev = target->prev;

        val = target->data;
        delete target;
        mSize--;

        return true;
    }

    bool PopBack(T& val) {
        if (Empty()) {
            return false;
        }

        ListNode* target = mTail->prev;
        target->prev->next = target->next;
        target->next->prev = target->prev;

        val = target->data;
        delete target;
        mSize--;

        return true;
    }

    bool Back(T& val) {
        if (this->Empty()) {
            return false;
        }
        val = mTail->prev->data;
        
        return true;
    }
    bool Front(T& val) {
        if (this->Empty()) {
            return false;
        }
        val = mHead->next->data;

        return true;
    }
    size_t Size() const {
        return mSize;
    }

    bool Empty() const {
        return mSize == 0;
    }

    bool Insert(const size_t pos, const T& val) {
        ListNode* p = this->GetPos(pos);
        if (!p) {
            return false;
        }

        //step1. link new
        ListNode* newNode = new ListNode(val);
        newNode->prev = p->prev;
        newNode->next = p;

        //step2. modify old link
        newNode->next->prev = newNode;
        newNode->prev->next = newNode;
        mSize++;

        return true;
    }

    bool Remove(const size_t pos, T& val) {
        ListNode* p = this->GetPos(pos);
        if (!p) {
            return false;
        }

        val = p->data;
        p->prev->next = p->next;
        p->next->prev = p->prev;

        delete p;
        mSize--;

        return true;
    }

    bool Get(const size_t pos, T& val) {
        ListNode* p = this->GetPos(pos);
        if (!p) {
            return false;
        }

        val = p->data;
        return true;
    }

    bool Set(const size_t pos, const T& val) {
        ListNode* p = this->GetPos(pos);
        if (!p) {
            return false;
        }

        p->data = val;
        return true;
    }

    void Clear() {
        ListNode* p = mHead->next;
        while(p != mTail) {
            ListNode* tmp = p->next;
            delete p;
            p = tmp;
        }

        //rest members
        mHead->next = mTail;
        mTail->prev = mHead;
        mSize = 0;
    }

    std::string ToString() const {
        std::ostringstream ss;
        ss << "List: [";
        for(ListNode* p = mHead->next; p != mTail; p = p->next) {
            ss << p->data;
            if (p->next != mTail) {
                ss << ", ";
            }
        }
        ss << "]";

        return ss.str();
    }
    ~List() {
        ListNode* p = mHead;
        while(p) {
            ListNode* tmp = p->next;
            delete p;
            p = tmp;
        }
    }
private:
    ListNode* GetPos(size_t pos) {
        if (pos >= mSize)
        {
            return nullptr;
        }
        
        ListNode* p = mHead->next;
        while (pos && p != mTail) {
            p = p->next;
            --pos;
        }

        return p;
    }

    size_t mSize = 0;           //valid range [0, mSize)
    ListNode* mHead = nullptr;  //virtual head, no actual node
    ListNode* mTail = nullptr;  //virtual tail, no actual node
};

#endif  // LIST_H