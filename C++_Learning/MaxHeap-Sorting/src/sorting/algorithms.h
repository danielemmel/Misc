#ifndef MAXHEAP_SORTING_ALGORITHMS_H
#define MAXHEAP_SORTING_ALGORITHMS_H


#include <vector>

void bubbleSort(std::vector<int> &vec, bool asc);

void quickSort(std::vector<int> &vec, bool asc);

std::vector<int> mergeSort(std::vector<int> &vec, bool asc);

#endif //MAXHEAP_SORTING_ALGORITHMS_H