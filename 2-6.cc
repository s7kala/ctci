/*
    2.3 Palindrome: Implement a function to check if a linked list is
        a palindrome.
*/

#include <iostream>
#include <stack>
#include "ll.h"

// linear time
// assumes length of list is unknown
template <typename T>
bool isPalindrome(const LinkedList<T>& l) {
    std::stack<T> rev;
    bool isPal = true;
    // assume size of l is unknown
    auto turt = l.head;
    auto runner = l.head;
    for(; runner && runner->next; turt = turt->next, runner = runner->next) {
        rev.push(turt->data);
        runner = runner->next;
    }
    // move turt to the beginning of the second half
    if(runner) turt = turt->next;
    while(!rev.empty()) {
        if(turt->data != rev.top()) {
            isPal = false;
            break;
        }
        rev.pop();
        turt = turt->next;
    }
    return isPal;
}

int main() {
    LinkedList<int> tests[] = {
        {1,2,3,2,1}, 
        {1,2,3,4,5},
        {2,3,2,95},
        {2,2},
        {1}
    };
    for(auto it : tests)
        std::cout << isPalindrome(it) << std::endl;
}