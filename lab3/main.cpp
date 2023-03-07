#include "Canvas.h"
#include <iostream>
using namespace std;

int main()
{
	Canvas C = Canvas(100, 100);
	//C.Clear();
	C.DrawRect(10,10,40,40, 'A');
	C.Print();
	return 0;
}