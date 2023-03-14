#include <time.h>
#include <algorithm>	
#include <cstdarg>
#include <cstring>
#include <iostream>
#include <stdlib.h>
#include "Sort.h"

Sort::Sort(int nr, int mini, int maxi)
{
    this->vect.clear();
    srand(time(NULL));
    int dif = maxi - mini + 1, newnr;
    while (nr--)
    {
        newnr = rand() % dif + mini;
        this->vect.push_back(newnr);
    }
    this->len = this->vect.size();
}
Sort::Sort(initializer_list<int> L)
{
    this->vect.clear();
    for (auto it : L)
        this->vect.push_back(it);
    this->len = this->vect.size();
}
Sort::Sort(int* w, int nrofel)
{
    this->vect.clear();
    for (int i = 0; i < nrofel; ++i)
        this->vect.push_back(*w + i);
    this->len = this->vect.size();
}
Sort::Sort(int count, ...)
{
    va_list args;
    va_start(args, count);
    this->vect.clear();
    int ind = 0;
    va_arg(args, int);
    while (ind < count)
    {
        this->vect.push_back(va_arg(args, int));
        ind++;
    }

    va_end(args);
    this->len = this->vect.size();
}
Sort::Sort(char* ptr)
{
    this->vect.clear();
    char* p = strtok(ptr, ","), * q;
    int ind, nr;
    while (p != NULL)
    {
        q = p;
        ind = 0; nr = 0;
        while (q + ind != NULL)
        {
            nr = nr * 10 + *(q + ind) - '0';
            ind++;
        }
        if (q != NULL)
            vect.push_back(nr);

        p = strtok(NULL, ",");
    }
    this->len = this->vect.size();
}

void Sort::InsertSort(bool ascendent)
{
	int i, key, j;
	for (i = 0; i < this->len; i++)
	{
		key = this->vect[i];
		j = i - 1;


		while (j >= 0 && this->vect[j] > key)
		{
			this->vect[j + 1] = this->vect[j];
			j = j - 1;
		}
		this->vect[j + 1] = key;
	}

}

void Sort::QuickSort(bool ascendent)
{
	sort(this->vect.begin(), this->vect.end());
}

void Sort::BubbleSort(bool ascendent)
{
	bool ok;
	int i, aux;
	int* p;
	this->len = this->vect.size();
	do {
		ok = 0;
		for(int i=0; i<this->len-1; ++i)
			if (this->vect[i] > this->vect[i+1])
			{
				aux = this->vect[i];
				this->vect[i] = this->vect[i + 1];
				this->vect[i + 1] = aux;
				ok = 1;
			}

	} while (ok);
}

void Sort::Print()
{
	for (auto it : this->vect)
		cout << it << ' ';
}

int  Sort::GetElementsCount()
{
	return this->len;
}

int  Sort::GetElementFromIndex(int index)
{
	if (index >= len)
		return -1;
	return this->vect[index];
}