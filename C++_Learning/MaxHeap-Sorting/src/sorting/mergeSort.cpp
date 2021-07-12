//
// Created by Daniel on 28.04.2021.
//
#include "algorithms.h"
#include "../utils.h"

std::vector<int> mergeVectors(std::vector<int> left, std::vector<int> right, bool asc) {
    std::vector<int> res;
    // append current smallest/largest element to result
    while (!left.empty() && !right.empty()) {
        if ((asc && left.front() < right.front()) || (!asc && left.front() > right.front())) {
            res.push_back(left.front());
            left.erase(left.begin());
        } else {
            res.push_back(right.front());
            right.erase(right.begin());
        }
    }
    // append remaining elements
    if (!left.empty()) {
        do {
            res.push_back(left.front());
            left.erase(left.begin());
        } while (!left.empty());
    } else {
        do {
            res.push_back(right.front());
            right.erase(right.begin());
        } while (!right.empty());
    }

    return res;
}

std::vector<int> mergeSort(std::vector<int> &vec, bool asc) {
    // recursive case in which the vector is trivially sorted
    if (vec.size() <= 1)
        return vec;

    // split up into two parts
    std::vector<int> left;
    std::vector<int> right;
    for (size_t i = 0; i < vec.size(); i++) {
        if (i < vec.size() / 2)
            left.push_back(vec.at(i));
        else
            right.push_back(vec.at(i));
    }

    // recursively sort both parts
    left = mergeSort(left, asc);
    right = mergeSort(right, asc);

    // merge both sorted parts back together
    return mergeVectors(left, right, asc);
}

