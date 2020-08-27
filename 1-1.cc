/*
    1.1 Is Unique: Implement an algorithm to determine if a string has all unique characters.
        What if you cannot use additional data structures?
*/

#include <iostream>
#include <unordered_set>
#include <cstring>

bool isUnique(const std::string& str) {
    std::unordered_set<int> sigma;
    bool unique = true;
    for(auto const& it : str) {
        if(sigma.find(it) != sigma.end()) {
            unique = false;
            break;
        }
        sigma.insert(it);
    }
    return unique;
}

/*  - without additional data structures
    - only works for eASCII strings, not general arrays
    - also linear time
*/
bool isUnique2(const std::string& str) {
    int sigma[256];
    bool unique = true;
    std::memset(sigma, 0, sizeof(sigma));
    for(auto const& it : str) {
        if(sigma[it]) {
            unique = false;
            break;
        }
        sigma[it]++;
    }
    return unique;
}

int main() {
    std::string tests[] = {"hello", "world", "not unique", "uniq", "god tier"};
    std::cout << "Results for isUnique with hash table:\n";
    for(auto const& it : tests)
        std::cout << isUnique(it) << std::endl;
    
    std::cout << "Results for isUnique with array of booleans:\n";
    for(auto const& it : tests)
        std::cout << isUnique2(it) << std::endl;
}