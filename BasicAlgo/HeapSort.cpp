#include <algorithm>
#include <iostream>

/**
 * push value to heap
 * @param start
 * @param hole
 * @param top
 * @param value = *(stat + hole)
 */
void pushHeap(int *start, int hole, int top, int value) {
    int parent = (hole - 1) / 2;
    while (hole > top && *(start + parent) < value) {
        *(start + hole) = *(start + parent);
        hole = parent;
        parent = (hole - 1) / 2;
    }
    *(start + hole) = value;
}

/**
 * Adjust heap
 * @param start
 * @param hole
 * @param len
 * @param value
 */
void adjustHeap(int *start, int hole, int len, int value) {
    int second_child = hole;
    int top_index = hole;
    while (second_child < (len - 1) / 2) {
        second_child = (second_child + 1) << 1;
        if (*(start + second_child) < *(start + second_child - 1)) {
            --second_child;
        }
        *(start + hole) = *(start + second_child);
        hole = second_child;
    }
    if ((len & 0x01) == 0 && second_child == (len - 2) / 2) {
        second_child = (second_child + 1) * 2;
        *(start + hole) = *(start + second_child - 1);
        hole = second_child - 1;
    }
    pushHeap(start, hole, top_index, value);
}


/**
 * make data as Heap
 * @param data
 * @param len
 */
void makeHeap(int *data, int len) {
    if (len < 2) {
        return;
    }
    int parent = (len - 2) / 2;
    while (true) {
        int value = *(data + parent);
        adjustHeap(data, parent, len, value);
        if (parent == 0)
            return;
        --parent;
    }
}

/**
 * use heap sort to sort data's elements
 * @param data
 * @param len
 */
void doHeapSort(int *data, int len) {
    makeHeap(data, len);
    for (int i = 0; i < len; ++i) {
        std::swap(data[0], data[len - i - 1]);
        adjustHeap(data, 0, len - i - 1, data[0]);
    }
}

int main() {
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    makeHeap(data, 10);

    std::for_each(data, data + 10, [](int x) { std::cout << x << " "; });
    std::cout << std::endl;
    doHeapSort(data, 10);
    std::for_each(data, data + 10, [](int x) { std::cout << x << " "; });
    return 0;
}
