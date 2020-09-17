/*
    1.5 One Away: There are three types of edits that can be performed on strings:
        insert, remove or replace a character. Given two strings, write a function
        to check if they are one edit (or zero edits) away
*/

#include <iostream>
#include <math.h>
#include <unordered_map>

// linear time
bool oneAway(const std::string& s1, const std::string& s2) {
    if(abs(int(s1.size() - s2.size())) > 1)
        return false;
    std::unordered_map<char, int> charCount;
    bool isOneAway = true;
    for(auto const& it : s1) {
        charCount[it]++;
    }
    int edits = 0;
    for(auto const&it : s2) {
        if(--charCount[it] < 0) {
            if(++edits > 1) {
                isOneAway = false;
                break;
            }
        }
    }
    return isOneAway;
}

int main() {
    std::pair<std::string, std::string> tests[] = {
        std::make_pair("pale", "ple"),
        std::make_pair("pales", "pale"),
        std::make_pair("pale", "bale"),
        std::make_pair("pale", "bake")
    };
    
    for(auto const& it : tests) {
        std::cout << oneAway(it.first, it.second) << std::endl;
    }
    
}