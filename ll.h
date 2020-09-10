#ifndef LL_H
#define LL_H

#include <vector>
#include <utility>

template <typename T>
struct Node {
    T data;
    Node<T>* next = nullptr;
    Node<T>* prev = nullptr;
    Node(T data, Node<T>* next = nullptr, Node<T>* prev = nullptr): 
        data{data}, next{next}, prev{prev} {}
    ~Node() {
        delete next;
    }
};

template <typename T>
struct LinkedList {
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    LinkedList(): head{nullptr}, tail{nullptr} {}
    LinkedList(std::initializer_list<T> List) {
        for(auto const& it : List) {
            pushBack(it);
        }
    }
    LinkedList(const LinkedList<T>& other) {
        for(auto curr = other.head; curr; curr = curr->next) {
            pushBack(curr->data);
        }
    }
    LinkedList& operator=(LinkedList<T> other) {
        swapLL(*this, other);
        return *this;
    }
    void pushBack(const T& t) {
        Node<T>* end = new Node<T>(t);
        if(tail) {
            tail->next = end;
            tail = end;
        } else {
            head = end;
            tail = end;
        }
    }
    void pushFront(const T& t) {
        Node<T>* front = new Node<T>(t);
        front->next = head;
        head = front;
    }
    ~LinkedList() {
        delete head;
    }
};

template <typename T>
void swapLL(LinkedList<T>& l1, LinkedList<T>& l2) {
    using std::swap;
    swap(l1.head, l2.head);
    swap(l1.tail, l2.tail);
}

#endif
