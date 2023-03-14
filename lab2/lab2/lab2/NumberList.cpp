#include "NumberList.h"
#include <cstdio>
#include <algorithm>


void NumberList::Init()
{
	this->max_size = 4;
	this->count = 0;
	this->numbers = new int[this->max_size];
}

void NumberList::Double()
{
	this->max_size *= 2;
	int* p = new int[this->max_size];
	for (int i = 0; i < this->count; ++i)
		p[i] = this->numbers[i];
	delete[] this->numbers;
	this->numbers = p;
}

bool NumberList::Add(int x)
{
	if (this->count ==this->max_size)
	{
		this->Double();
		this->numbers[this->count] = x;
		this->count++;
		printf("urat din partea ta");
		return 1;
	}
	this->numbers[this->count] = x;
	this->count++;
	return 1;
}

void NumberList::Sort()
{
	std::sort(this->numbers, this->numbers + this->count);
}

void NumberList::Print()
{
	if (this->count >= 10 || this->count<0)
	{
		printf("urat din partea ta");
		return ;
	}
	for (int i = 0; i < this->count; ++i)
		printf("%d ", this->numbers[i]);

}