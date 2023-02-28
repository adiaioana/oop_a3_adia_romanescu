#include <iostream>
#include <cstring>
#include <cstdio>

char numero[232];
int A[232], S[232];


int max(int x, int y)
{
	if (x > y)
		return x;
	return y;
}

void to_number(int V[], char *p)
{
	V[0] = 0;

	while (*p!= '\0' )
	{
		V[++V[0]] = *p - '0'; p++;
	}
	for (int i = V[0], j = 1; j < i; j++, i--)
	{
		int aux = V[i];
		V[i] = V[j];
		V[j] = aux;
	}
}


void to_add(int S[], int V[])
{
	/// tin minte numerele inversate
	int T = 0;
	for (int i = S[0]+1; i <= V[0]; i++)
	    S[i]=0;
	for(int i= V[0] +1; i<=S[0]; ++i)
	    V[i]=0;
	for (int i = 1; i <= max(S[0], V[0]); i++)
	{
	    if(i<=S[0])
		    S[i] = S[i] + V[i] + T;
		else S[i]=V[i]+T;
		
		if (S[i] > 9)
			T = 1, S[i] -= 10;
		else T = 0;
	}

    if(V[0]>S[0])
        S[0]=V[0];
    
	if (T)
	{
	    S[0]++;
		S[S[0]] = 1;
		T=0;
	}
}


int main()
{
	FILE* ptr = fopen("in.txt", "r+");
	S[0] = 1; S[1] = 0;
   // int n;
	//std::cin >> n;
	while (fscanf(ptr, "%s", numero)>0)
	{
	    
	//	if(numero[0]=='\0')
	//	    break;
		to_number(A, numero);
		to_add(S, A);
		
	/*	printf("%d", S[0]);
		printf("/n");
	for (int i = 1; i <=S[0]; i++)
		printf("%d", S[i]);
		printf("/n");*/
		
	}

	for (int i = 1, j = S[0]; i <= j; i++, j--)
	{
		int aux = S[i];
		S[i] = S[j];
		S[j] = aux;
	}
	for (int i = 1; i <=S[0]; i++)
		printf("%d", S[i]);
}
