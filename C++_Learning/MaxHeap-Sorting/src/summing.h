//
// Created by Daniel on 03.05.2021.
//

#ifndef MAXHEAP_SORTING_SUMMING_H
#define MAXHEAP_SORTING_SUMMING_H

#include <type_traits>
#include <vector>
#include <limits>

template<typename T>
T sum(const std::vector<T> &vec) {
    T sum = 0;
    for (T elem : vec) {
        if (std::is_integral<T>::value) {
            // handle potential overflows and underflows
            if (std::is_unsigned<T>::value) {
                // handle overflow for unsigned variants
                if (sum + elem < sum)
                    throw std::overflow_error("Overflow occurred during sum calculation");
            } else {
                // handle underflow and overflow for signed variants
                if (elem < 0 && (sum < (std::numeric_limits<T>::min() - elem)))
                    throw std::underflow_error("Underflow occurred during sum calculation");
                else if (elem > 0 && (sum > (std::numeric_limits<T>::max() - elem)))
                    throw std::overflow_error("Overflow occurred during sum calculation");
            }
        }
        sum += elem;
    }
    return sum;
}

#endif //MAXHEAP_SORTING_SUMMING_H
