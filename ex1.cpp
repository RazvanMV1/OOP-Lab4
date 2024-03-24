#include <iostream>
#include "Sort.h"

using namespace std;

int main() {
    Sort list1(5, 1, 100);
    cout << "Random values list: ";
    list1.Print();

    Sort list2{ 5, 20, 3, 10, 7 };
    cout << "Initialization list: ";
    list2.Print();

    int arr[] = { 50, 30, 10, 40, 20 };
    Sort list3(arr, sizeof(arr) / sizeof(arr[0]));
    cout << "Existing array: ";
    list3.Print();

    Sort list4(6, 10, 20, 30, 40, 50, 60);
    std::cout << "Variadic parameters: ";
    list4.Print();

    const char* str = "10,40,100,5,70";
    Sort list5(str);
    std::cout << "String values: ";
    list5.Print();

    return 0;
}