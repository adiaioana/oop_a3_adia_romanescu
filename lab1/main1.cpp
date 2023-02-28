#include <iostream>
#include <cstring>
#include <cstdio>

char numero[1002];
int A[1032], S[1032];


int max(int x, int y)
{
	if (x > y)
		return x;
	return y;
}

void to_number(int V[], char p[])
{
	V[0] = 0;
	int ind = 0;
	while (p[ind] != '\0')
	{
		V[++V[0]] = p[ind] - '0'; ind++;
	}
	for (int i = V[0], j = 1; j < i; j++, i--)
	{
		int aux = V[i];
		V[i] = V[j];
		V[j] = aux;
	}
}
void to_number2(int &x, char *p)
{
	x = 0;
	int ind = 0, lg= strlen(p);
	while (ind<lg)
	{
		x = x * 10 + ( p[ind] - '0');
		ind++;
	}
}

void to_add(int S[], int V[])
{
	/// tin minte numerele inversate
	int T = 0;
	for (int i = S[0] + 1; i <= V[0]; i++)
		S[i] = 0;
	for (int i = V[0] + 1; i <= S[0]; ++i)
		V[i] = 0;
	for (int i = 1; i <= max(S[0], V[0]); i++)
	{
		if (i <= S[0])
			S[i] = S[i] + V[i] + T;
		else S[i] = V[i] + T;

		if (S[i] > 9)
			T = 1, S[i] -= 10;
		else T = 0;
	}

	if (V[0] > S[0])
		S[0] = V[0];

	if (T)
	{
		S[0]++;
		S[S[0]] = 1;
		T = 0;
	}
}


int main()
{
	int suma = 0;
	FILE* ptr = fopen("in.txt", "r");
	S[0] = 1; S[1] = 0;
	// int n;
	 //std::cin >> n;
	while (fscanf(ptr, "%s", numero) > 0)
	{

		//	if(numero[0]=='\0')
		//	    break;
		//to_number(A, numero);
		int X;
		to_number2(X, numero);
		suma += X;
		//to_add(S, A);

		/*	printf("%d", S[0]);
			printf("/n");
		for (int i = 1; i <=S[0]; i++)
			printf("%d", S[i]);
			printf("/n");*/

	}
	printf("%d", suma);
	/*
	for (int i = 1, j = S[0]; i <= j; i++, j--)
	{
		int aux = S[i];
		S[i] = S[j];
		S[j] = aux;
	}
	for (int i = 1; i <= S[0]; i++)
		printf("%d", S[i]);*/
}
