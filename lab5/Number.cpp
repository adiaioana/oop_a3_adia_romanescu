#pragma once
#include "Number.h"
#include <fstream>
using namespace std;
ofstream fout("a.txt");

Number::Number(const char* value, int base)
{

	fout << "OPA1";

	first = new char[25];
	for (int i = 0; i < strlen(value); ++i)
	{
		first[i] = value[i];
		first[i + 1] = '\0';
	}
	nr_digits = strlen(value);
	curr_base = base;
}
Number::Number(int value)
{

	fout << "OPA2";

	delete first;
	first = new char;
	first[0] = '\0';
	nr_digits = 0;
	while (value)
	{
		first[nr_digits] = value % 10;
		value /= 10;
		nr_digits++;
	}

	for (int i = 0; i < nr_digits / 2; ++i)
	{
		char aux = first[i];
		first[i] = first[nr_digits - 1 - i];
		first[nr_digits - 1 - i] = aux;
	}
}


Number::~Number()
{
	fout << "OPA3";
	delete[] first;
	first = nullptr;
}

void Number::SwitchBase(int newBase)
{
	fout << "OPA4";
	long long x = this->to_Base10();
	this->curr_base = newBase;
	this->from_Base10(x);
}

void Number::Print()
{
	fout << "OPA5";
	for (int i = 0; i < this->nr_digits; ++i)
		cout<< this->first[i];
	cout << endl;
}

int Number::GetDigitsCount()
{
	fout << "OPA6";
	return this->nr_digits;
}// returns the number of digits for the current number

int  Number::GetBase()
{
	fout << "OPA6";
	return this->curr_base;
}


long long Number::to_Base10()
{

	fout << "OPA7";
	long long n = 0;
	long long p = 1;
	int exp = 0;
	for (int i = this->nr_digits - 1; i >= 0; i--)
	{
		if (this->first[i] >= '0' && this->first[i] <= '9')
			n = n + p * (this->first[i] - '0');
		else n = n + p * (this->first[i] - 'A' + 10);
		p = p * this->curr_base;
		exp++;
	}
	return n;
}
void Number:: from_Base10(long long x)
{

	fout << "OPA8";
	if (this->curr_base == 0)
	{
		fout << "BAI" << '\n';
	}
	this->nr_digits = 0;
//	delete this->first;
	this->first = new char[25];
	char ch;
	int exp = 0;

	while (x>0)
	{
		if (x % this->curr_base > 9)
			ch = (x % this->curr_base) - 10 + 'A';
		else ch = (x % this->curr_base) + '0';
		x /= this->curr_base;
		this->first[exp] = ch; exp++;
		this->first[exp] = '\0';
	}
	//cout <<"OF > "<< this->first << '\n';
	this->nr_digits = exp;
}


char Number:: operator[](int index)
{

	fout << "OPA9";
	return first[index];
}

bool Number:: operator < (Number K)
{

	fout << "OPA10";
	long long x1 = this->to_Base10();
	long long x2 = K.to_Base10();
	return (x1 < x2);
}

bool Number:: operator == (Number K)
{
	fout << "OPA11";
	long long x1 = this->to_Base10();
	long long x2 = K.to_Base10();
	return (x1 ==x2);
}
bool Number:: operator > (Number K)
{
	fout << "OPA12";
	long long x1 = this->to_Base10();
	long long x2 = K.to_Base10();
	return (x1 > x2);
}

Number& Number:: operator = (const char* ptr)
{

	fout << "OPA13";
	int lg = strlen(ptr);
	this->nr_digits = strlen(ptr);
	delete this->first;
	this->first = new char[25];
	for (int i = 0; i < this->nr_digits; ++i)
		this->first[i] = ptr[i];
	return (*this);
}


Number& Number:: operator = (char str[])
{
	fout << "OPA14";
	int lg = strlen(str);
	this->nr_digits = strlen(str);
	delete this->first;
	this->first = new char[25];
	for (int i = 0; i < this->nr_digits; ++i)
		this->first[i] = str[i];
	return (*this);
}

Number& Number:: operator = (int K)
{
	fout << "OPA15";
	from_Base10(K);
	return (*this);
}

Number::Number (Number&& K)
{
	fout << "OPA16";
	this->curr_base = K.curr_base;
	this->nr_digits = K.nr_digits;
	

	memcpy(this->first, K.first, this->nr_digits);
	K.first = nullptr;
}
Number:: Number ( Number& K)
{

	fout << "OPA17";
	this->curr_base = K.curr_base;
	this->nr_digits = K.nr_digits;

	fout << K.first;

	//delete this->first;
	this->first = new char[25];
	memcpy(this->first, K.first, this->nr_digits);
}

Number& Number::operator = ( Number & K)
{
	fout << "OPA18";
	this->curr_base = K.curr_base;
	this->nr_digits = K.nr_digits;

	memcpy(this->first, K.first, this->nr_digits);
	return (*this);
}
Number& Number::operator=(Number&& a)
{

	fout << "OPA19";
	this->nr_digits = a.nr_digits;
	this->curr_base = a.curr_base;
	memcpy(this->first, a.first, this->nr_digits);
	a.first = nullptr;
	return(*this);
}
void Number:: operator -- ()
{
	fout << "OPA20";
	if (this->nr_digits == 1)
		return;
	this->nr_digits--;
}

void Number::operator--(int val)
{
	fout << "OPA21";
	if (this->nr_digits == 1)
		return;
	for (int i = 0; i < this->nr_digits - 1; ++i)
		this->first[i] = this->first[i + 1];
	this->nr_digits--;
}

Number::Number()
{
	fout << "OPA22";
	this->curr_base = 0;
	this->first = new char[25];
	this->nr_digits = 1;
}

Number operator+(Number A, Number B)
{
	fout << "OPA23";
	long long x1 = A.to_Base10();
	long long x2 = B.to_Base10();
	long long x = x1 + x2;
	Number C;
	C.curr_base = max(A.curr_base, B.curr_base);
	C.from_Base10(x);
	return C;
}

Number& Number::operator+=(Number A)
{
	fout << "OPA24";
	long long x1 = this->to_Base10();
	long long x2 = A.to_Base10();
	
	this->curr_base = max(this->curr_base, A.curr_base);
	this->from_Base10(x1 + x2);
	
	return (*this);
}


Number operator-(Number A, Number B)
{
	fout << "OPA25";
	long long x1 = A.to_Base10();
	long long x2 = B.to_Base10();
	long long x = x1 - x2;

	Number C;
	C.curr_base = max(A.curr_base, B.curr_base);
	C.from_Base10(x);
	return C;
}

