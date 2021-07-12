//
// Created by Daniel on 27.04.2021.
//
#include "algorithms.h"

void sortRange(std::vector<int> &vec, size_t start, size_t end, bool asc) {
    // only continue if the current vector range contains more than one elements
    if (start < end) {
        // select pivot element simply as the last in the vector
        int pivot = vec.at(end);
        size_t partition_end = start;
        // calculate end of current partition and realign vector
        for (size_t i = start; i < end; i++) {
            if ((asc && vec.at(i) < pivot) || (!asc && vec.at(i) > pivot)) {
                std::swap(vec.at(partition_end), vec.at(i));
                partition_end++;
            }
        }
        // bring pivot element into the middle of the vector
        std::swap(vec.at(partition_end), vec.at(end));
        // redo sorting for the smaller and bigger value range
        // also make sure that partition_end does not underflow
        sortRange(vec, start, (partition_end > 0) ? partition_end - 1 : 0, asc);
        sortRange(vec, partition_end + 1, end, asc);
    }
}

void quickSort(std::vector<int> &vec, bool asc) {
    // nothing to be done in this case
    if (vec.empty() || vec.size() == 1)
        return;
    sortRange(vec, 0, vec.size() - 1, asc);
}
