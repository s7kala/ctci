/*
    1.4 Palindrome Permutation: Given a string, write a function to check if it is a permutation of a
        palindrome.
*/

#include <iostream>
#include <cstring>

// assume eASCII string
// linear time
bool isPalindromePermutation(const std::string& s) {
    int charCount[256];
    int odd = 0;
    bool ispalperm = false;
    std::memset(charCount, 0, sizeof(charCount));
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