#include "utils.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

void printVector(const std::vector<int> &vec) {
    std::cout << '{';
    if (vec.empty())
        goto end;

    for (int i = 0; i < vec.size() - 1; i++) {
        std::cout << vec.at(i) << ',';
    }
    std::cout << vec.at(vec.size() - 1);
    end:
    print('}');
}

void printTwoDimArray(int **arr, unsigned int x_len, unsigned int y_len) {
    for (unsigned int i = 0; i < y_len; i++) {
        for (unsigned int j = 0; j < x_len; j++) {
            std::cout << arr[j][i] << ',';
        }
        std::cout << std::endl;
    }
    for (unsigned int j = 0; j < x_len; j++)
        std::cout << "--";
    std::cout << std::endl;
}

std::vector<int> generateRandomIntVector(unsigned int size, unsigned int max_value) {
    std::vector<int> res;
    if (size == 0)
        return res;
    srand(time(nullptr));
    do {
        res.push_back(rand() % max_value);
        size--;
    } while (size);
    return res;
}
