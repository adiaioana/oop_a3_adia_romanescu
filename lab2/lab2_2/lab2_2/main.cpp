#include <iostream>
#include <cstdio>
#include "GlobalFunctions.h"
#include "Student.h"

#include <algorithm>
using namespace std;
int n;

Student Clasa[110];

float m = 0, h = 0, e = 0;
char* of;
int main() {

	scanf_s("%d", n, 7);
	for(int i=1; i<=n; ++i)
	{
		scanf_s("%s %f %f %f", of, m, h, e);
		Clasa[i].Init(i);
		Clasa[i].SetName(of);
		Clasa[i].SetEnglish(e);
		Clasa[i].SetHistory(h);
		Clasa[i].SetMath(m);
	}
	sort(Clasa + 1, Clasa + n + 1, CompareAverage);

	for (int i = 1; i <= n; ++i)
	{
		printf("%d %f", Clasa[i].GetInd(), Clasa[i].Average());
		printf("\n");
	}
	return 0;
}