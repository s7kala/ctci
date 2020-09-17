/*
    1.4 Palindrome Permutation: Given a string, write a function to check if it is a permutation of a
        palindrome.
*/

#include <iostream>
#include <unordered_map>

// linear time
bool isPalindromePermutation(const std::string& s) {
    std::unordered_map<char, int> charCount;
    int odd = 0;
    bool ispalperm = false;
    for(auto const& it : s) {
        if(++charCount[it] % 2) odd++;
        else odd--;
    }

    if(odd < 2) ispalperm = true;
    return ispalperm;
}

int main() {
    std::string tests[] = {"tactcoa", "hello", "notpermutable", "racecar", "veell", "rdara", "ciivc", "hehao"};
    for(auto const& it : tests) {
        std::cout << isPalindromePermutation(it) << std::endl;
    }

}