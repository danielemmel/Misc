#include "algorithms.h"
#include <vector>
#include <algorithm>

void bubbleSort(std::vector<int> &vec, bool asc) {
    // empty vector needs not be sorted
    if (vec.empty())
        return;

    bool switch_occured;
    do {
        switch_occured = false;
        for (size_t i = 0; i < vec.size() - 1; i++) {
            if ((asc && vec.at(i) > vec.at(i + 1)) || (!asc && vec.at(i) < vec.at(i + 1))) {
                std::swap(vec.at(i), vec.at(i+1));
                switch_occured = true;
            }
        }
    } while (switch_occured);
}
