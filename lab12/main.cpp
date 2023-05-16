#include <fstream>
#include <iostream>
#include <cstdlib>

#include <time.h>
using namespace std;
ifstream fin("A.in");
ofstream fout("A.out");
ofstream gout("A.in");
template <typename T> void sortareManuala(int n, T* v)
{
	T* aux = new T[n];

	for (int i = 1; i < n; i++) /// bug 1: incepe de la 1, ce e pe pozitia 0 ramane acolo
	{
		for (int j = i + 1; j < n; j++) 
		{
			if (v[i] > v[j])
				swap(v[i], v[j]);
		}
	}

	int p = rand() % 2;

	if (p == 0)
	{
		for (int i = 0; i < n; i++)
		{
			if (v[i] > v[i + 1]) /// bug 3: aceseaza v[n] si acolo incepe hihi haha ca e memorie nealocata
				swap(v[i], v[i + 1]);

			else
				break; /// bug 2: tehnic nu merge programul ca ramane v[0] aiurea si de acolo nu merge
		}
	}

	for (int i = 0; i < n; i++)
		cout << v[i] << ' ';

	cout << '\n';
}

int main()
{
	srand(time(NULL));
	int t = rand() % 15 +5;
	gout << t << endl;
	while (t--)
	{
		int n = rand() % 12 + 5;
		gout << n << endl;
		int ind = rand() % 3;
		while (n--)
		{
			int x = rand() % 2070;
			gout << x << ' ';
		}
		gout << endl;
	}


	int* L = new int[2000];
	int T, x, k,N;
	fin >> T;
	while (T--)
	{
		k = 0;
		fin >> N;
		for (int i = 1; i <= N; ++i)
		{
			fin >> x;
			L[k++] = x;
		}
		sortareManuala(N,L);
		fout << "Pentru testu " << T << endl;
		for (int i = 1; i <= N; ++i)
			fout << L[i] << ' ';
		fout << '\n';
	}

	return 0;
}


