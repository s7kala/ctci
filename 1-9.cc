/*
    1.9 String Rotation: Assume you have a method isSubstring which checks if
        one word is a substring of another. Given two strings, s1 and s2, write
        code to check if s2 is a rotation of s1 using only one call to isSubstring.
        Eg "waterbottle" is a rotation of "erbottlewat"
*/

#include <iostream>

bool isSubstring(const std::string& big, const std::string& small) {
    return big.find(small) != std::string::npos;
}

bool isRotation(const std::string& s1, const std::string& s2) {
    return isSubstring(s1 + s1, s2);
}

int main() {
    std::pair<std::string, std::string> tests[] = {
        std::make_pair("waterbottle", "erbottlewat"),
        std::make_pair("hello", "world"),
        std::make_pair("helloworld", "ldhellowor"),
        std::make_pair("rotate", "tatero"),
        std::make_pair("norotate", "yesrotate")
    };
    for(auto const& it : tests) {
        std::cout << isRotation(it.first, it.second) << std::endl;
    }
}