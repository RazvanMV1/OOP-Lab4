class Sort
{
    int* elements;
    int numElements;
public:
    // add constuctors
    Sort(const int, int);
    Sort(const int*, int);
    Sort(int, ...);
    Sort(int, int, int);
    Sort(const char*);
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};
