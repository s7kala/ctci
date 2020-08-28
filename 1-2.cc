/*
    1.2 Check Permutation: Given two strings, write a method to decide if one
    is a permutation of the other.
*/

#include <iostream>
#include <cstring>
#include <algorithm>

// assume eASCII strings
// linear time
bool checkPermutation(const std::string& s1, const std::string& s2) {
    if(s1.length() != s2.length())
        return false;
    int charCount[256];
    bool isPermutation = true;
    memset(charCount, 0, sizeof(charCount));
    for(auto const& it : s1)
        charCount[it]++;
    for(auto const& it : s2) {
        if(--charCount[it] < 0) {
            isPermutation = false;
            break;
        }
    }

    return isPermutation;
}


bool checkPermutation2(const std::string& s1, const std::string& s2) {
    if(s1.length() != s2.length())
        return false;
    bool isPermutation = true;
    std::string s3 = s1;
    std::string s4 = s2;
    std::sort(s3.begin(), s3.end());
    std::sort(s4.begin(), s4.end());
    for(int i = 0; i < s3.length(); ++i) {
        if(s3.at(i) != s4.at(i)) {
            isPermutation = false;
            break;
        }
    }
    return isPermutation;
}


int main() {
    std::pair<std::string, std::string> tests[] = {
        std::make_pair("hello", "olhel"), 
        std::make_pair("permute", "root"), 
        std::make_pair("root", "root"), 
        std::make_pair("racecar", "racecar"), 
        std::make_pair("hehe", "hoho")
    };

    std::cout << "Results from function 1:\n";
    for(auto const& it : tests) {
        std::cout << checkPermutation(it.first, it.second) << std::endl;
    }

    std::cout << "Results from function 2:\n";
    for(auto const& it : tests) {
        std::cout << checkPermutation2(it.first, it.second) << std::endl;
    }


}