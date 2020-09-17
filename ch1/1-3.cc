/*
    1.3 URLify: Write a method to replace all spaces in a string with '%20'. You may assume that
        the string has sufficient space at the end to hold the additional characters, and that
        you are given the 'true' length of the string.
*/

#include <iostream>

std::string URLify(const std::string& s) {
    std::string url;
    for(auto const& it : s) {
        if(it == ' ') 
            url.append("%20");
        else
            url.push_back(it);
    }
    return url;
}

int main() {
    std::string tests[] = {"Mr John Smith"};
    for(auto& it : tests) {
        std::cout << URLify(it) << std::endl;
    }
    
}