/*
    2.2 Return Kth to Last: Implement an algorithm to find the kth to
        last element of a singly linked list.
*/

#include <iostream>
#include "ll.h"

/*  augment LinkedList struct to hold size of ll
    alternatively, iterate ll to first get size then iterate again
    Either way, time complexity is linear
*/
template <typename T>
T kthToLast(const LinkedList<T>& l, int k) {
    int ctr = l.size - k;
    if(k == 0 || ctr < 0) throw std::out_of_range("Element out of range");
    auto curr = l.head;
    for(int ctr = l.size - k; ctr && curr; ctr--, curr = curr->next);
    return curr->data;
}

// use two pointers k spaces apart
// linear time
template <typename T>
T kthToLast2(const LinkedList<T>& l, int k) {
    if(k == 0 || l.size - k < 0) throw std::out_of_range("Element out of range");
    auto runner = l.head;
    int ctr = k;
    for(int ctr = k; ctr; --ctr, runner = runner->next);
    auto curr = l.head;
    for(; runner; curr = curr->next, runner = runner->next);
    return curr->data;
}

int main() {
    LinkedList<int> l{1,2,3,4,5};
    for(int i = l.size; i > 0; --i) {
        std::cout << kthToLast2(l, i) << std::endl;
    }
}
