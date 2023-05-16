#include "List.h"
#include <iostream>
using namespace std;

template <typename T> void Sort(List<T> L)
{
	if (L.Size() == 0)
		return;
	
	for(int i=0; i<L.Size(); ++i)
		for (int j = i+1; j < L.Size(); ++j)
			if (L.Compare(i, j) > 0)
				L.Swap(i, j);
}

int main()
{
	List<int> L1;
	int n, x;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> x;
		L1.Insert(x);
	}

	Sort(L1);
	L1.Print();
	return 0;
}