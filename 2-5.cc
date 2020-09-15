/*
    2.5 Sum Lists: You have two numbers represented by a linked list,
        where each node contains a single digit. The digits are stored
        in reverse order, such that the 1's digit is at the head of the
        list. Write a function that adds the two numbers and returns
        the sum as a linked list.
        Suppose the digits are stored in reverse order. Repeat the problem.
*/

// assuming no leading zeros!

#include <iostream>
#include "ll.h"

// time : O(n + m)
// requires operator+ and operator* to be overloaded for type T
template <typename T>
T sumLists(const LinkedList<T>& l1, const LinkedList<T>& l2) {
    T sum{0};
    int factor = 1;
    auto it1 = l1.head, it2 = l2.head;
    for(;it1 && it2; it1 = it1->next, it2 = it2->next, factor *= 10) {
        sum += factor * (it1->data + it2->data);
    }
    while(it1) {
        sum += factor * it1->data;
        factor *= 10;
        it1 = it1->next;
    }
    while(it2) {
        sum += factor * it2->data;
        factor *= 10;
        it2 = it2->next;
    }
    return sum;
}


template <typename T>
std::pair<T, int> calcNum(const Node<T>* n, int factor = 1) {
    T num = n->data;
    T sum = 0;
    if(n->next) {
        auto next = calcNum(n->next, factor);
        sum += next.first;
        factor = 10 * next.second;
    }
    return std::make_pair(sum + num * factor, factor);
}

// is size known? if so then precompute factor
// assuming size is not known
// time: O(n + m)
template <typename T>
T reverseSumLists(const LinkedList<T>& l1, const LinkedList<T>& l2) {
    auto p1 = calcNum(l1.head);
    auto p2 = calcNum(l2.head);
    return p1.first + p2.first;
}

int main() {
    std::pair<LinkedList<int>, LinkedList<int>> tests[] = {
        std::make_pair(LinkedList<int>{7,1,6}, LinkedList<int>{5,9,2}),
        std::make_pair(LinkedList<int>{6,1}, LinkedList<int>{2,9,5,4}),
        std::make_pair(LinkedList<int>{1}, LinkedList<int>{9,5,4}),
        std::make_pair(LinkedList<int>{6,1,3,3,1}, LinkedList<int>{5,4}),
        std::make_pair(LinkedList<int>{1}, LinkedList<int>{3})
    };
    std::cout << "Forward sums:\n";
    for(auto const& it : tests) {
        std::cout << sumLists(it.first, it.second) << std::endl;
    }
    std::cout << "Reverse sums:\n";
    for(auto const& it : tests) {
        std::cout << reverseSumLists(it.first, it.second) << std::endl;
    }
}