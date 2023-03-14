#include "NumberList.h"
#include <cstdio>
int N,x;
int main()
{
	NumberList OK;
	OK.Init();
	scanf_s("%d", &N, 4);

	for (int i = 1; i <= N; ++i)
	{
		scanf_s("%d", &x, 4);
		OK.Add(x);
	}
	OK.Sort();
	OK.Print();
	return 0;
}
