#ifndef MAXHEAP_SORTING_UTILS_H
#define MAXHEAP_SORTING_UTILS_H

// easier printing
#include <iostream>
#include <vector>

#define print(x) (std::cout << x << std::endl)


void printVector(const std::vector<int> &vec);

void printTwoDimArray(int **arr, unsigned int x_len, unsigned int y_len);

// generates and returns vector with size entries in the range of [0; max_value)
std::vector<int> generateRandomIntVector(unsigned int size, unsigned int max_value);

#endif //MAXHEAP_SORTING_UTILS_H