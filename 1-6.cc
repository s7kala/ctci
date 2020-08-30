/*
    1.6 String Compression: Implement a method to perform basic string compression using
        the counts of repeated characters. Eg "aabcccccaaa" -> "a2b1c5a3". If the "compressed"
        string would not become smaller than the original string, return the original string.
        Assumption: The string consists only of A-Z and a-z
*/

#include <iostream>

std::string compress(const std::string& s) {
    std::string rle;
    for(int i = 1; i < s.length(); ++i) {
        int count = 1;
        while(s[i] == s[i-1]) {
            count++;
            i++;
        }
        rle.push_back(s[i-1]);
        rle.append(std::to_string(count));
    } 
    if(rle.length() >= s.length())
        return s;
    return rle;
}


int main() {
    std::string tests[] = {
        "aabcccccaaa"
    };

    for(auto const& it : tests) {
        std::cout << compress(it) << std::endl;
    }
}