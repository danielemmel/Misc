//
// Created by Daniel on 01.05.2021.
//

#ifndef MAXHEAP_SORTING_MAXHEAPINT_H
#define MAXHEAP_SORTING_MAXHEAPINT_H

#include <vector>
#include <map>
#include <unordered_set>

class maxHeap {
private:
    struct VectorWrapper {
        std::vector<int> vec;
        int sum = 0;
        size_t hash = 0;

        VectorWrapper(const std::vector<int> &vector, int sum, size_t hash) {
            this->vec = vector;
            this->sum = sum;
            this->hash = hash;
        }
    };

    using VectorArray = std::vector<VectorWrapper>;

    VectorArray elements;
    std::unordered_set<size_t> hashValues;

    void upHeapify(size_t current);

    void downHeapify(size_t i);

    static size_t getLeftChild(size_t current);

    static size_t getRightChild(size_t current);

    static size_t getParent(size_t current);


public:
    bool insert(const std::vector<int> &vec);

    bool remove(const std::vector<int> &vec);

    std::vector<int> extract() noexcept(false);

    void printContents();

    void printHashes();

    maxHeap() = default;

};

#endif //MAXHEAP_SORTING_MAXHEAPINT_H
