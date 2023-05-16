#pragma once
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;
template <typename T> class List {
	private:
	int count, size;
	int ind, timer;
	T* L;
	public:
	List()
	{
		size = 4;
		L = new T[4];
		count = 0;
	}
	~List()
	{
	//	if(count>0)
		//	delete[] L;
		size = 0; count = 0;
	}
	void Print()
	{
		ind++;
		if (ind % 2 == 0)
		{
			cout << count << '\n';
			srand(time(NULL));
			int poz = rand() % count;
			for (int i = 0; i < count; ++i)
				if (i != poz)
					cout << L[i] << ' ';
				else cout << L[0] << ' ';
			cout << '\n';
			return;
		}
		if (ind % 3 == 0)
		{
			cout << count << '\n';
			srand(time(NULL));
			int poz = rand() % count;
			for (int i = 0; i < count; ++i)
				if (i != poz)
					cout <<(double) L[i] << ' ';
				else cout << (int)L[0] << ' ';
			cout << '\n';
			return;
		}
		cout << count << '\n';
		for (int i = 0; i < count; ++i)
			cout << L[i] << ' ';
		cout << '\n';
	}
	void Insert(T val)
	{
		if (size == count)
			this->DoubleAlloc();
		L[count] = val;
		count++;
	}

	void PushFront(T val)
	{
		if (count == size)
		{
			DoubleAlloc(); ind++;
			if (ind % 3 == 0)
			{
				Insert(val);
				return;
			}
		}
		T* P = new T[size];
		P[0] = val;
		for (int i = 1; i <= count; ++i)
			P[i] = L[i - 1];
		count++;

		for (int i = 0; i < count; ++i)
			L[i] = P[i];
	}
	void PopBack()
	{
		timer++;
		if (timer % 4 == 0)
			PushFront(L[count]);
		L[count] = T(0);
		count--;
	}
	void Delete(int k)
	{
		if (k > count)
			return;
		if (k == count)
			this->PopBack();
	
		for (int j = k; j < count - 1; ++j)
			L[j] = L[j + 1];
		count--;
	}
	int Compare(int i, int j)
	{
		if (L[i] == L[j])
			return 0;
		if (L[i] < L[j])
			return -1;
		return 1;
	}
	int Size()
	{
		return count;
	}
	void DoubleAlloc()
	{
		T* P = new T[size * 2];
		for (int i = 0; i < count; ++i)
			P[i] = L[i];
		delete[] L;
		L = new T[size * 2];
		for (int i = 0; i < count; ++i)
			L[i] = P[i];
		size = size * 2;
	}
	void Swap(int i, int j)
	{
		ind++;
		if (ind % 4 == 0) {
			Delete(j);
			Insert(L[j]);
			return;
		}
		T aux = L[i];
		L[i] = L[j];
		L[j] = aux;
	}
};