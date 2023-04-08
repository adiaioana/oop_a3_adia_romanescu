#include "Heap.h"
int N = 10;
int v[] = { 35, 33, 42, 10, 14, 19, 27, 44, 26, 31 };
int main()
{
	/*
	folosesc A.txt si consola pentru debug
	A.txt > procesele cu NodeList
	consola > procesele cu Heap
	B.txt Am afisarea de la print Heap
	*/
	Heap<int> A;
	A.make_heap(10, v);
	A.print();
	A.sort_heap();
	A.print();

	return 0;
}