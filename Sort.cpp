#include "Sort.h"
#include <iostream>
#include <cstdarg>
#include <cstring>

using namespace std;

Sort::Sort(const int arr[], int numElements) { //Existing array constructor
    elements = new int[numElements];
    for (int i = 0; i < numElements; ++i) {
        elements[i] = arr[i];
    }
}

Sort::Sort(const int* initList, int numElements) {
    elements = new int[numElements];

    for (int i = 0; i < numElements; ++i) {
        elements[i] = initList[i];
    }
}

Sort::Sort(int numElements, ...) {  //Variadic parameter constructor
    elements = new int[numElements]; 
    va_list args;
    va_start(args, numElements);
    for (int i = 0; i < numElements; ++i) {
        int value = va_arg(args, int);
        elements[i] = value;
    }
    va_end(args);
}

Sort::Sort(int numElements, int minValue, int maxValue) { //Random constructor
    elements = new int[numElements];

    for (int i = 0; i < numElements; ++i) {
        elements[i] = rand() % (maxValue - minValue + 1) + minValue;
    }
}


Sort::Sort(const char* str) {  //String constructor
    elements = new int[strlen(str)];
    int num = 0;
    int index = 0;
    for (const char* c = str; *c; ++c) {
        if (*c == ',') {
            elements[index++] = num;
            num = 0;
        }
        else if (*c >= '0' && *c <= '9') {
            num = num * 10 + (*c - '0');
        }
    }
    if (num != 0) {
        elements[index++] = num;
    }
}



void Sort::InsertSort(bool ascendent) {
    for (int i = 1; i < numElements; ++i) {
        int key = elements[i];
        int j = i - 1;

        while (j >= 0 && (ascendent ? elements[j] > key : elements[j] < key)) {
            elements[j + 1] = elements[j];
            j = j - 1;
        }
        elements[j + 1] = key;
    }
}

int partition(int* elements, int low, int high, bool ascendent) {
    int pivot = elements[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if ((ascendent && elements[j] <= pivot) || (!ascendent && elements[j] >= pivot)) {
            ++i;
            swap(elements[i], elements[j]);
        }
    }
    swap(elements[i + 1], elements[high]);
    return i + 1;
}

void quickSort_(int* elements, int low, int high, bool ascendent) {
    if (low < high) {
        int partitionIndex = partition(elements, low, high, ascendent);
        quickSort_(elements, low, partitionIndex - 1, ascendent);
        quickSort_(elements, partitionIndex + 1, high, ascendent);
    }
}


void Sort::QuickSort(bool ascendent)
{
    quickSort_(this->elements, 0, this->numElements - 1, ascendent);
}

void Sort::BubbleSort(bool ascendent = false)
{
    if (ascendent == false)
    {
        for (int i = 0; i < this->numElements - 1; ++i) {
            for (int j = 0; j < this->numElements - i - 1; ++j) {
                if (this->elements[j] > this->elements[j + 1]) {
                    int temp = this->elements[j];
                    this->elements[j] = this->elements[j + 1];
                    this->elements[j + 1] = temp;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < this->numElements - 1; ++i) {
            for (int j = 0; j < this->numElements - i - 1; ++j) {
                if (this->elements[j] < this->elements[j + 1]) {
                    int temp = this->elements[j];
                    this->elements[j] = this->elements[j + 1];
                    this->elements[j + 1] = temp;
                }
            }
        }
    }
}
void Sort::Print()
{
    for (int i = 0;i <= this->numElements;i++)
        cout << this->elements[i] << ' ';
}
int Sort::GetElementsCount()
{
    return this->numElements;
}
int Sort::GetElementFromIndex(int index)
{
    return this->elements[index];
}