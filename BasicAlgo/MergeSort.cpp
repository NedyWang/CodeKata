//
// Created by root on 12/21/17.
//

void doMerge(int *first, int startIndex, int midIndex, int endIndex)
{
    int *data = new int[endIndex - startIndex];

    int secondIndex = midIndex;
    int index = 0;

    while (startIndex < midIndex && secondIndex < endIndex) {
        if (*(first + startIndex) < *(first + secondIndex)) {
            data[index++] = *(first + startIndex++);
        }
        else {
            data[index++] = *(first + secondIndex++);
        }
    }

    while (startIndex < midIndex) {
        data[index++] = *(first + startIndex++);
    }

    while (secondIndex < endIndex) {
        data[index++] = *(first + secondIndex++);
    }

    memncpy(first + startIndex, data,  (endIndex - startIndex)* sizeof(*first));
    delete []data;
}

void doMergeSort(int *first, int startIndex, int endIndex)
{
    if (startIndex >= endIndex) return;
    int midIndex = (startIndex + endIndex) / 2 + 1;
    doMergeSort(first, startIndex, midIndex);
    doMergeSort(first, midIndex+1, endIndex);
    doMerge(first, startIndex, midIndex, endIndex);
}

void mergeSort(int *first, int len)
{
    doMergeSort(first, 0, len - 1);
}
