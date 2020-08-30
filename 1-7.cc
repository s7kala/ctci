/*
    1.7 Rotate Matrix: Given an image represented by an NxN matrix, where each pixel
        in the image is 4 bytes, write a method to rotate the image by 90 degrees.
        Can this be done in place?
*/

#include <iostream>
#include <vector>

void rotateMatrix(std::vector<std::vector<int>>& image) {
    std::vector<std::vector<int>> rotatedImage;
    int n = image.size();
    for(int i = 0; i < n; ++i) {
        std::vector<int> row;
        for(int j = 0; j < n; ++j) {
            row.emplace_back(image[n - 1 - j][i]);
        }
        rotatedImage.emplace_back(row);
    }
    image = rotatedImage;
}

// rotate by cycles
void rotateMatrixInPlace(std::vector<std::vector<int>>& image) {
    int size = image.size();
    for(int i = 0; i < size/2; ++i) {
            for(int j = i; j < size - 1; ++j) {
            int top = image[i][j];
            image[i][j] = image[size - 1 - j][i];
            image[size - 1 - j][i] = image[size - 1 - i][size - 1 - j];
            image[size - 1 - i][size - 1 - j] = image[j][size - 1 - i];
            image[j][size - 1 - i] = top;
        }
    }
}


int main() {
    std::vector<std::vector<int>> test;
    std::vector<std::vector<int>> test2;
    int size = 5;
    for(int i = 0; i < size; ++i) {
        std::vector<int> row;
        for(int j = 0; j < size; ++j) {
            row.emplace_back(10*i + j);
        }
        test.emplace_back(row);
        test2.emplace_back(row);
    }
    rotateMatrix(test);
    rotateMatrixInPlace(test2);
    std::cout << "Result of rotateMatrix:\n";
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            std::cout << test.at(i).at(j);
            if(j != size - 1) std::cout << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << "Result of rotateMatrixInPlace:\n";
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            std::cout << test.at(i).at(j);
            if(j != size - 1) std::cout << ' ';
        }
        std::cout << std::endl;
    }

}