#include "Array.h"
#include "ArrayIterator.h"
#include <iostream>
#include <exception>
using namespace std;

int main()
{
	Array<int> Arr;
	int a = 2, b = 3, c = 4;
	Arr += c; 
	Arr += a;
	Arr.Insert(1, 3);
	
	cout << "Testing it" << '\n';
	for (auto it : Arr) {
		cout <<*it << ' ';
	}
	cout << '\n';
	Arr.Print();
	Arr.Sort();
	Arr.Print();
	cout << "Is " << b<< " in Array?" <<" Find= "<< Arr.Find(b) <<" BinSearch= " << Arr.BinarySearch(b) << '\n';
	
	Array<int> Nxt;
	Nxt.Insert(0, 6);
	Nxt += 9;
	Nxt += -974;
	Nxt += -4829;
	Array <int> Aux(Nxt);
	if (Aux == Nxt)
	{
		cout << "Merge programul" << '\n';
	}

	Aux.Print();
	Nxt.Sort();
	Nxt.Print();
	Arr.Insert(2, Nxt);
	Arr.Print();
	return 0;
}