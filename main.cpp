#include <iostream>
#include <vector>
#include "heap.hpp"

int main() {
    std::vector<int> ints = {4, 1, 3, 2, 16, 32, 9, 10, 14, 8, 7};

    heap<int> heapp(ints);

    std::cout << heapp;
}