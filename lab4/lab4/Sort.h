#include <vector>
#pragma warning(disable:4996)
using namespace std;

class Sort
{
    int len;
    vector <int> vect;
    // add data members

public:
    
    Sort(int nr, int mini, int maxi);
    Sort(initializer_list<int> L);
    Sort(int* w, int nrofel);
    Sort(int count, ...);
    Sort(char* ptr);
    // add constuctors

    void InsertSort(bool ascendent = false);

    void QuickSort(bool ascendent = false);

    void BubbleSort(bool ascendent = false);

    void Print();

    int  GetElementsCount();

    int  GetElementFromIndex(int index);

};