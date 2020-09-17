/*
    2.4 Partition: Write code to partition a linked list around a value x,
        such that all nodes less than x come before all nodes greater than
        or equal to x. If x is contained within the list, the values of x
        only need to be after the elements less than x.
*/

#include <iostream>
#include "ll.h"

// linear time, linear space
// requires operator< to be overloaded for type T
template <typename T>
void partition(LinkedList<T>& l, int x) {
    LinkedList<T> partitioned;
    for(auto it = l.head; it; it = it->next) {
        if(it->data < x) {
            partitioned.pushFront(it->data);
        }
        else partitioned.pushBack(it->data);
    }
    l = partitioned;
}

int main() {
    LinkedList<int> l{3,5,8,5,10,2,1};
    int x = 5;
    partition(l, x);
    std::cout << l;
}