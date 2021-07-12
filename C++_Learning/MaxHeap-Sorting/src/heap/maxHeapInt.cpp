//
// Created by Daniel on 01.05.2021.
//
#include <stdexcept>
#include "maxHeapInt.h"
#include "../utils.h"
#include <vector>
#include <algorithm>
#include "../summing.h"

using Vec = std::vector<int>;

size_t getUnorderedHash(const Vec &vec) {
    std::hash<std::string> hasher;
    std::string sum;
    Vec sorted_vec = vec;
    std::sort(sorted_vec.begin(), sorted_vec.end());
    for (int elem: sorted_vec) {
        sum += std::to_string(elem);
    }
    return hasher(sum);
}

size_t maxHeap::getLeftChild(size_t current) noexcept(false) {
    return 2 * current + 1;
}

size_t maxHeap::getRightChild(size_t current) noexcept(false) {
    return 2 * current + 2;
}

size_t maxHeap::getParent(size_t current) {
    if (current == 0)
        return 0;
    return (current - 1) / 2;
}

void maxHeap::upHeapify(size_t i) {
    size_t current = i;
    size_t parent = getParent(current);
    while (current && (elements.at(current).sum > elements.at(parent).sum)) {
        std::swap(elements.at(current), elements.at(parent));
        current = parent;
        parent = getParent(current);
    }
}

void maxHeap::downHeapify(size_t i) {
    // get children
    size_t left = getLeftChild(i);
    size_t right = getRightChild(i);
    size_t largest = i;

    // determine larger child, if any
    if (left < this->elements.size() && this->elements.at(left).sum > this->elements.at(largest).sum)
        largest = left;
    if (right < this->elements.size() && this->elements.at(right).sum > this->elements.at(largest).sum)
        largest = right;

    if (largest != i) {
        // switch larger child and continue heapifying downwards
        std::swap(this->elements.at(largest), this->elements.at(i));
        downHeapify(largest);
    }
}

bool maxHeap::insert(const Vec &vec) {
    int total;
    try {
        // attempt calculation of sum of vector for total order
        total = sum<int>(vec);
    }
    catch (const std::runtime_error &e) {
        // catch overflow and underflow during sum calculation
        print(e.what());
        return false;
    }
    size_t hash = getUnorderedHash(vec);
    // check whether this vector already exists in the heap via the hash
    if (hashValues.find(hash) != hashValues.end()) {
        return false;
    }
    // add hash to seen values
    hashValues.insert(hash);
    // construct new element and insert it
    VectorWrapper wrapper(vec, total, hash);
    elements.push_back(wrapper);

    // restore heap property
    upHeapify(elements.size() - 1);
    return true;
}

bool maxHeap::remove(const Vec &vec) {
    for (size_t i = 0; i < elements.size(); ++i) {
        if (vec == elements.at(i).vec) {
            // remove the element
            // first, swap last element to this position and remove former last element
            elements.at(i) = elements.at(elements.size() - 1);
            // remove hash from observed hashes
            hashValues.erase(elements.back().hash);
            elements.pop_back();

            // stop if we removed the last element
            if (elements.size() <= i)
                return true;
            // restore heap property
            if (elements.at(i).sum > elements.at(getParent(i)).sum)
                upHeapify(i);
            else
                downHeapify(i);
            return true;
        }
    }
    return false;
}

Vec maxHeap::extract() noexcept(false) {
    if (elements.empty())
        throw std::out_of_range("Cannot extract element from an empty heap");
    Vec res = elements.front().vec;
    this->remove(res);
    return res;
}


void maxHeap::printHashes() {
    if (hashValues.empty())
        return;
    print("Currently seen hashes:");
    for (auto &val : hashValues) {
        printf("%lu\n", val);
    }
}

void maxHeap::printContents() {
    size_t current = 0;
    for (const auto &elem : this->elements) {
        printf("Element at position %lu has sum %d and is: \n", current, elem.sum);
        printVector(elem.vec);
        current++;
    }
}

