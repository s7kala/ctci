/*
    2.3 Delete Middle Node: Implement an algorithm to delete a node in the
        middle of a singly linked list, given only access to that node.
*/

#include <iostream>
#include "ll.h"

// constant time
template <typename T>
void deleteMiddleNode(Node<T>* middle) {
    auto temp = middle->next;
    if(temp) {
        middle->data = temp->data;
        middle->next = temp->next;
        temp->next = nullptr;
        delete temp;
    } else throw std::invalid_argument("The middle cannot be the end of the LinkedList");
}

int main() {
    LinkedList<int> l{1,2,3,4,5};
    auto middle = l.head;
    for(int ctr = l.size/2; ctr; ctr--, middle = middle->next);
    deleteMiddleNode(middle);
    l.size--;
    for(auto it = l.head; it; it = it->next) {
        std::cout << it->data << std::endl;
    }
}

