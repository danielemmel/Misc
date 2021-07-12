//
// Created by Daniel on 02.05.2021.
//

#ifndef MAXHEAP_SORTING_MAXHEAP_H
#define MAXHEAP_SORTING_MAXHEAP_H

#include <vector>
#include <unordered_set>
#include <stdexcept>
#include "../utils.h"
#include <algorithm>
#include <limits>
#include "../summing.h"
#include <type_traits>

template<class T>
class maxHeap {
    static_assert(std::is_arithmetic<T>::value, "Given template type must be a numeric type!");

private:
    struct VectorWrapper {
        std::vector<T> vec;
        T sum = 0;
        size_t hash = 0;

        VectorWrapper(const std::vector<T> &vector, T sum, size_t hash) {
            this->vec = vector;
            this->sum = sum;
            this->hash = hash;
        }
    };

    using VectorArray = std::vector<VectorWrapper>;
    using Vec = std::vector<T>;

    VectorArray elements;
    std::unordered_set<size_t> hashValues;

    size_t getUnorderedHash(const std::vector<T> &vec) {
        std::hash<std::string> hasher;
        std::string sum;
        std::vector<T> sorted_vec = vec;
        std::sort(sorted_vec.begin(), sorted_vec.end());
        for (auto elem: sorted_vec) {
            sum += std::to_string(elem);
        }
        return hasher(sum);
    }

    void upHeapify(size_t i) {
        size_t current = i;
        size_t parent = getParent(current);
        while (current && (elements.at(current).sum > elements.at(parent).sum)) {
            std::swap(elements.at(current), elements.at(parent));
            current = parent;
            parent = getParent(current);
        }
    }

    void downHeapify(size_t i) {
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
            std::swap(elements.at(largest), elements.at(i));
            downHeapify(largest);
        }
    }

    static size_t getLeftChild(size_t current) {
        return 2 * current + 1;
    }

    static size_t getRightChild(size_t current) {
        return 2 * current + 2;
    }

    static size_t getParent(size_t current) {
        if (current == 0)
            return 0;
        return (current - 1) / 2;
    }


public:
    bool insert(const std::vector<T> &vec) {
        T total;
        try {
            // attempt calculation of sum of vector for total order
            total = sum<T>(vec);
        }
        catch (const std::exception &e) {
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

    bool remove(const std::vector<T> &vec) {
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

    std::vector<T> extract() noexcept(false) {
        if (elements.empty())
            throw std::out_of_range("Cannot extract element from an empty heap");
        Vec res = elements.front().vec;
        this->remove(res);
        return res;
    }

    maxHeap() = default;

};

#endif //MAXHEAP_SORTING_MAXHEAP_H
