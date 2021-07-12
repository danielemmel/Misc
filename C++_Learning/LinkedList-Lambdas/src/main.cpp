#include <iostream>
#include "MyLinkedList.h"
#include "Lambdas.h"
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>

void test() {
    MyLinkedList<int> list{};
    std::vector<int> vec{};
    srand(time(nullptr));
    int values[1000];

    for (int &value : values) {
        value = rand() % 50;
    }

    // filling MyLinkedList
    for (int val : values) {
        if (!list.remove(val))
            list.insert(val);
    }
    print("List content:");
    print(list.toString());

    //filling normal vector
    for (int val : values) {
        // search for element and remove if found
        auto it = std::find(vec.begin(), vec.end(), val);
        if (it != vec.end())
            vec.erase(it);
        else {
            vec.push_back(val);
        }
    }
    print("Vector content:");
    std::cout << "{";
    for (int val : vec) {
        std::cout << val;
        // this case only occurs at last element since element values are unique here
        if (val != vec.back())
            std::cout << ',';
    }
    std::cout << "}" << std::endl;

}

int main(int argc, char **argv) {
    test();
    return 0;
}
