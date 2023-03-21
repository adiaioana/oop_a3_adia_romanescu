#include <iostream>
#include <cstring>

class Number
{

private:
	char* first;
	int curr_base, nr_digits;


	long long to_Base10();
	void from_Base10(long long x);
	friend Number operator + (Number A, Number B);
	friend Number operator-(Number A, Number B);

public:

	Number();
	Number(const char* value, int base); // where base is between 2 and 16
	Number(int value);
	~Number();
	Number(Number&& K);
	Number( Number& K);


	bool operator < (Number K);
	bool operator == (Number K);
	bool operator > (Number K);
	char operator[](int index);
	Number& operator = (const char* ptr);
	Number& operator = ( Number & K);
	Number& operator=(Number&& a);
	Number& operator+=(Number A);
	Number& operator = (char str[]);
	Number& operator = (int K);
	void operator -- (int val);
	void operator -- ();
	void SwitchBase(int newBase);

	void Print();

	int  GetDigitsCount(); // returns the number of digits for the current number

	int  GetBase(); // returns the current base

};