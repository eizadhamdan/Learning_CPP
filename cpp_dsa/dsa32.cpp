// code for merge sort

#include <iostream>
#include "dsa31.cpp"

using namespace std;

void mergeSort(int array[], int leftIndex, int rightIndex)
{
    if (leftIndex >= rightIndex) return;
    int midIndex = leftIndex + (rightIndex - leftIndex) / 2;
    mergeSort(array, leftIndex, midIndex);
    mergeSort(array, midIndex + 1, rightIndex);

    merge(array, leftIndex, midIndex, rightIndex);
}

int main()
{
    int myArray[] = {3, 1, 4, 2};

    int size = sizeof(myArray) / sizeof(myArray[0]);
    int leftIndex = 0;
    int rightIndex = size - 1;

    mergeSort(myArray, leftIndex, rightIndex);

    for(auto value : myArray)
    {
        cout << value << " ";
    }
    cout << endl;

}