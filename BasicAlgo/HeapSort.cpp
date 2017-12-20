//
// Created by root on 12/20/17.
//



void adjustHeap(int data[], int hole, int len, int value)
{
    int second_child = hole;
    while (second_child < (len - 1) / 2) {
        second_child = (hole + 1) << 1;
        if (data[second_child] < data[second_child - 1]) {
            --second_child;
        }
        data[hole] = data[second_child];
        hole = second_child;
    }
    data[hole] = value;
}

void makeHeap(int data[], int len)
{
    if (len < 2) {
        return;
    }
    int parent = (len - 1)/2;
    while (true) {
        adjustHeap(data, parent, len, data[parent]);
        if (parent == 0)
            return;
        --parent;
    }
}
