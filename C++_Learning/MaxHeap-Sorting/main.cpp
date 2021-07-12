#include "src/utils.h"
#include <vector>
#include "src/matrixmult.h"
#include "src/sorting/algorithms.h"
#include "src/heap/maxHeapInt.h"

void displayMatrixMult() {
    int **arr = new int *[4];
    for (int i = 0; i < 4; i++) {
        arr[i] = new int[4];
        for (int j = 0; j < 4; j++) {
            arr[i][j] = i + j;
        }
    }
    int **brr = new int *[4];
    for (int i = 0; i < 4; i++) {
        brr[i] = new int[4];
        for (int j = 0; j < 4; j++) {
            brr[i][j] = i * j - 1;
        }
    }

    int **crr = multiplyMatrices(arr, brr, 4, 4, 4);

    print("Multiplying Vector A:");
    printTwoDimArray(arr, 4, 4);
    print("With Vector B:");
    printTwoDimArray(brr, 4, 4);
    print("Result:");
    printTwoDimArray(crr, 4, 4);
}

void displayVectorSort() {
    auto v1 = generateRandomIntVector(50, 1000);
    auto v1_copy = std::vector<int>(v1);
    auto v2 = generateRandomIntVector(50, 1000);
    auto v2_copy = std::vector<int>(v2);
    auto v3 = generateRandomIntVector(50, 1000);

    print("Initial input to bubbleSort:");
    printVector(v1);
    bubbleSort(v1, true);
    print("Bubble-Sorted variant with ascending values:");
    printVector(v1);
    print("Bubble-Sorted variant with descending values:");
    bubbleSort(v1_copy, false);
    printVector(v1_copy);
    std::cout << '\n';

    print("Initial input to quickSort:");
    printVector(v2);
    quickSort(v2, true);
    print("Quick-Sorted variant with ascending values:");
    printVector(v2);
    print("Quick-Sorted variant with descending values:");
    bubbleSort(v2_copy, false);
    printVector(v2_copy);
    std::cout << '\n';

    print("Initial input to mergeSort:");
    printVector(v3);
    auto v = mergeSort(v3, true);
    print("Merge-Sorted variant with ascending values:");
    printVector(v);
    print("Merge-Sorted variant with descending values:");
    v = mergeSort(v3, false);
    printVector(v);
}

void displayMaxHeap() {
    maxHeap h;
    h.insert(std::vector<int>{1, 3, 2});
    h.insert(std::vector<int>{1, 3});
    h.insert(std::vector<int>{1});
    h.insert(std::vector<int>{1, 2, 3, 4});
    h.printContents();
    puts("\n");
    h.extract();
    h.remove(std::vector<int>{1, 2, 3, 4});
    h.printContents();
}

void runDemo() {
    displayMaxHeap();
    std::cout << '\n';
    displayVectorSort();
    std::cout << '\n';
    displayMatrixMult();
}


int main() {
    runDemo();
    return 0;
}
