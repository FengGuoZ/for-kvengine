#include "list.h"

template <typename T>
List<T>::List() {
    mHead = new ListNode();
    mTail = new ListNode();
    mHead->next = mTail;
    mTail->prev = mHead;
}

template <typename T>
List<T>::~List() {
    ListNode* p = mHead;
    while(p) {
        ListNode* tmp = p->next;
        delete p;
        p = tmp;
    }
}

template <typename T>
void List<T>::PushFront(const T& val) {
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

template <typename T>
void List<T>::PushBack(const T& val) {
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

template <typename T>
bool List<T>::PopFront(T& val) {
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

template <typename T>
bool List<T>::PopBack(T& val) {
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

template <typename T>
bool List<T>::Back(T& val) {
    if (this->Empty()) {
        return false;
    }
    val = mTail->prev->data;
    
    return true;
}

template <typename T>
bool List<T>::Front(T& val) {
    if (this->Empty()) {
        return false;
    }
    val = mHead->next->data;
    return true;
}

template <typename T>
typename List<T>::ListNode* List<T>::GetPos(size_t pos) {
   if (pos >= mSize)
   {
       return nullptr;
   }
   
   List<T>::ListNode* p = mHead->next;
   while (pos && p != mTail) {
       p = p->next;
       --pos;
   }

   return p;
}

template <typename T>
bool List<T>::Insert(const size_t pos, const T& val) {
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

template <typename T>
bool List<T>::Remove(const size_t pos, T& val) {
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

template <typename T>
bool List<T>::Get(const size_t pos, T& val) {
    ListNode* p = this->GetPos(pos);
    if (!p) {
        return false;
    }
    val = p->data;

    return true;
}

template <typename T>
bool List<T>::Set(const size_t pos, const T& val) {
    ListNode* p = this->GetPos(pos);
    if (!p) {
        return false;
    }
    p->data = val;

    return true;
}

template <typename T>
void List<T>::Clear() {
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

template <typename T>
std::string List<T>::ToString() const {
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