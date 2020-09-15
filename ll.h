#ifndef LL_H
#define LL_H

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
    int size = 0;
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
        size++;
    }
    void pushFront(const T& t) {
        Node<T>* front = new Node<T>(t);
        front->next = head;
        head = front;
        if(!tail) tail = front;
        size++;
    }
    T popBack() {
        if(size == 0) throw std::out_of_range("LinkedList empty");
        if(size == 1) {
            LinkedList<T> temp;
            swapLL(*this, temp);
            size--;
            return temp.head->data;
        }
        auto curr = head;
        for(int ctr = size - 1; ctr > 1; curr = curr->next, ctr--);
        auto data = curr->next->data;
        delete curr->next;
        curr->next = nullptr;
        tail = curr;
        size--;
        return data;
    }
    T popFront() {
        if(size == 0) throw std::out_of_range("LinkedList empty");
        if(size == 1) {
            LinkedList<T> temp;
            swapLL(*this, temp);
            size--;
            return temp.head->data;
        }
        auto newHead = head->next;
        auto data = head->data;
        head->next = nullptr;
        delete head;
        head = newHead;
        size--;
        return data;
    }
    ~LinkedList() {
        delete head;
    }
    template <typename type>
    friend std::ostream& operator<<(std::ostream& os, const LinkedList<type>&);
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T>& l) {
    for(auto it = l.head; it; it = it->next) {
        os << it->data << ' ';
    }
    os << std::endl;
    return os;
}

template <typename T>
void swapLL(LinkedList<T>& l1, LinkedList<T>& l2) {
    using std::swap;
    swap(l1.head, l2.head);
    swap(l1.tail, l2.tail);
}

#endif
