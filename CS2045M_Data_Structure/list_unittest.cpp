#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include "list.h"
#include "test_common.h"

using namespace std;

void TestEmptyList() {
    CASE_TITLE();

    List<int> list;
    std::cout << list.ToString() << std::endl;

    TEST_EQUAL(list.Empty(), true);
    TEST_EQUAL(list.Size(), 0);
    int front = 0;
    TEST_EQUAL(list.Front(front), false);
    int back = 0;
    TEST_EQUAL(list.Back(back), false);
}
void TestPushFront() {
    CASE_TITLE();

    //15 -> 14 -> 13
    List<int> list;
    list.PushFront(13);
    list.PushFront(14);
    list.PushFront(15);
    std::cout << list.ToString() << std::endl;
    
    TEST_EQUAL(list.Size(), 3);
    int front = 0;
    TEST_EQUAL(list.Front(front), true);
    TEST_EQUAL(front, 15);
    int back = 0;
    TEST_EQUAL(list.Back(back), true);
    TEST_EQUAL(back, 13);
}

void TestPushBack() {
    CASE_TITLE();

    //13 -> 14 -> 15
    List<int> list;
    list.PushBack(13);
    list.PushBack(14);
    list.PushBack(15);
    std::cout << list.ToString() << std::endl;
    
    TEST_EQUAL(list.Size(), 3);
    int front = 0;
    TEST_EQUAL(list.Front(front), true);
    TEST_EQUAL(front, 13);
    int back = 0;
    TEST_EQUAL(list.Back(back), true);
    TEST_EQUAL(back, 15);
}

void TestPopFront() {
    CASE_TITLE();

    //13 -> 14 -> 15
    List<int> list;
    list.PushBack(13);
    list.PushBack(14);
    list.PushBack(15);
    std::cout << list.ToString() << std::endl;

    int val = 0;
    TEST_EQUAL(list.PopFront(val), true);
    TEST_EQUAL(val, 13);
    TEST_EQUAL(list.PopFront(val), true);
    TEST_EQUAL(val, 14);
    TEST_EQUAL(list.PopFront(val), true);
    TEST_EQUAL(val, 15);
    TEST_EQUAL(list.PopFront(val), false);
}

void TestPopBack() {
    CASE_TITLE();

    //13 -> 14 -> 15
    List<int> list;
    list.PushBack(13);
    list.PushBack(14);
    list.PushBack(15);
    std::cout << list.ToString() << std::endl;

    int val = 0;
    TEST_EQUAL(list.PopBack(val), true);
    TEST_EQUAL(val, 15);
    TEST_EQUAL(list.PopBack(val), true);
    TEST_EQUAL(val, 14);
    TEST_EQUAL(list.PopBack(val), true);
    TEST_EQUAL(val, 13);
    TEST_EQUAL(list.PopBack(val), false);
}

void TestGetAndSet() {
    CASE_TITLE();

    List<int> list;
    for (int i = 0; i < 10; ++i) {
        list.PushBack(i);
    }
    cout << list.ToString() << endl;

    //test Get
    int val = 0;
    TEST_EQUAL(list.Get(100, val), false);
    TEST_EQUAL(list.Get(5, val), true);
    TEST_EQUAL(val, 5);

    //test Set
    val = 17;
    TEST_EQUAL(list.Set(100, val), false);
    TEST_EQUAL(list.Set(5, val), true);
    cout << list.ToString() << endl;
    TEST_EQUAL(list.Get(5, val), true);
    TEST_EQUAL(val, 17);
}

void TestInsertAndRemove() {
    CASE_TITLE();

    List<int> list;
    for (int i = 0; i < 10; ++i) {
        list.PushBack(i);
    }
    cout << list.ToString() << endl;

    //test Remove
    int val = 0;
    TEST_EQUAL(list.Remove(100, val), false);
    TEST_EQUAL(list.Remove(5, val), true);
    TEST_EQUAL(val, 5);
    TEST_EQUAL(list.Size(), 9);
    cout << list.ToString() << endl;

    //test Insert
    val = 17;
    TEST_EQUAL(list.Insert(100, val), false);
    TEST_EQUAL(list.Insert(2, val), true);
    int val2 = 0;
    TEST_EQUAL(list.Get(2, val2), true);
    TEST_EQUAL(val2, 17);
    TEST_EQUAL(list.Size(), 10);
    cout << list.ToString() << endl;
}

void TestTraverse() {
    CASE_TITLE();

    List<int> list;
    for (int i = 0; i < 10; ++i) {
        list.PushBack(i);
    }
    cout << list.ToString() << endl;

    //in sequence
    List<int>::ListNode* p = list.GetHead();
    cout << "in sequence: ";
    while(p) {
        cout << p->data << " ";
        p = list.GetNext(p);
    }
    cout << endl;

    //in reverse
    p = list.GetTail();
    cout << "in reverse: ";
    while(p) {
        cout << p->data << " ";
        p = list.GetPrev(p);
    }
    cout << endl;
}

void TestClearList() {
    CASE_TITLE();

    List<int> list;
    for (int i = 0; i < 10; ++i) {
        list.PushBack(i);
    }
    cout << list.ToString() << endl;

    list.Clear();
    cout << list.ToString() << endl;
    assert(list.Size() == 0);
    TEST_EQUAL(list.Empty(), true);
    TEST_EQUAL(list.Size(), 0);
    int front = 0;
    TEST_EQUAL(list.Front(front), false);
    int back = 0;
    TEST_EQUAL(list.Back(back), false);
}

int main() {
    TestEmptyList();

    TestPushFront();
    TestPushBack();

    TestPopFront();
    TestPopBack();

    TestGetAndSet();
    TestInsertAndRemove();

    TestTraverse();

    TestClearList();

    cout << "All tests passed!" << endl;
    return 0;
}