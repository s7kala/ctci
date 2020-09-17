/*
    1.8 Zero Matrix: Write an algorithm such that if an element in an MxN matrix
        is 0, its entire row and column are set to 0
*/

#include <iostream>
#include <vector>
#include <unordered_set>

// assumes nonempty matrix
void fillZerosColumns(std::vector<std::vector<int>>& matrix, int x) {
    int i = 0;
    int n = matrix.at(0).size();
    while(i < n) matrix.at(x).at(i++) = 0;
}

void fillZerosRows(std::vector<std::vector<int>>& matrix, int y) {
    int i = 0;
    int m = matrix.size();
    while(i < m) matrix.at(i++).at(y) = 0;
}

void zeroMatrix(std::vector<std::vector<int>>& matrix) {
    std::unordered_set<int> zeroColumns;
    std::unordered_set<int> zeroRows;
    int m = matrix.size();
    for(int i = 0; i < m; ++i) {
        int n = matrix.at(i).size();
        for(int j = 0; j < n; ++j) {
            if(matrix.at(i).at(j) == 0) {
                if(zeroColumns.find(j) == zeroColumns.end())
                    fillZerosColumns(matrix, i);
                if(zeroRows.find(i) == zeroRows.end())
                    fillZerosRows(matrix, j);
            }    
        }
    }
}

int main() {
    std::vector<std::vector<int>> test{
        {3,9,4,0},
        {2,0,0,3},
        {4,0,2,0}
    };
    zeroMatrix(test);
    for(auto const& row : test) {
        for(auto const& element : row) {
            std::cout << element;
            if(&element - &row[0] != row.size() - 1) std::cout << ' ';
        }
        std::cout << std::endl;
    }
}