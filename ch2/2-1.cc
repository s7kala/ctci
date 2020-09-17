/*
    2.1 Remove Dups: Write code to remove duplicates from an unsorted linked list. How
        would you solve this problem if a temporary buffer is not allowed?
*/

#include <iostream>
#include <unordered_set>
#include "ll.h"

// linear time
template <typename T>
void removeDups(LinkedList<T>& ll) {
    std::unordered_set<T> ht;
    LinkedList<T> unique;
    for(auto curr = ll.head; curr; curr = curr->next) {
        if(ht.find(curr->data) == ht.end()) {
            unique.pushBack(curr->data);
            ht.insert(curr->data);
        }
    }
    ll = unique;
}

// quadratic time
template <typename T>
void removeDups2(LinkedList<T>& ll) {
    for(auto curr = ll.head; curr; curr = curr->next) {
        auto it = curr;
        auto ahead = it->next;
        while(ahead) {
            if(ahead->data == curr->data) {
                it->next = ahead->next;
                ahead->next = nullptr;
                delete ahead;
                ahead = it->next;
                continue;
            }
            it = it->next;
            ahead = ahead->next;
        }
    }
}

int main() {
    LinkedList<int> l{1,3,4,1,7,4,5,5,2};
    auto l2 = l;
    removeDups(l);
    removeDups2(l2);
    for(auto it = l.head, it2 = l2.head; it && it2; it = it->next, it2 = it2->next) {
        std::cout << it->data << ' ' << it2->data << std::endl;
    }

}