#pragma once
#include "NodeList.h"
std::ofstream gout("B.txt");
using namespace std;
template <typename tp> class Heap {

	public:
		int dim;
		NodeList <tp> L;
		Heap()
		{
			dim = 0;
		}
	
		void make_heap(int nr, tp* head)
		{
			std::cout << "H3" << '\n';
			int lg = 0;
			//gout << "TEST make_heap1 > "<<nr<<' ';
			while (lg < nr)
			{
				//gout << head[lg] << ' ';
				L.NodeInsert(head[lg]);
				lg++;
			}
			dim = nr;
			//gout << endl;
			int ind, str;
			NodeList<tp>  auxL;
			L.print1();
			for (int i = 0; i < dim; ++i)
			{
				auxL.NodeInsert(this->L[i]);
				ind = i;
				while (ind > 0)
				{
					str = ind / 2 - (1 - ind % 2);
					cout<<str<<' '<<ind<<' '<<auxL[str] << ' ' << auxL[ind] << '\n';
					if (auxL[str] < auxL[ind])
					{
						auxL.swap(str,ind);
					}

					ind = str;
				}
				auxL.print1();
			}
			this->L = auxL;
		}


		void make_heap()
		{
			std::cout << "H6" << '\n';
			int ind, str;
			NodeList<tp>  auxL;
			for (int i = 0; i < dim; ++i)
			{
				auxL.NodeInsert(this->L[i]);
				ind = i;
				while (ind > 0)
				{
					str = ind / 2 - (1 - ind % 2);
					if (auxL[str] < auxL[ind])
					{
						auxL.swap(str,ind);
					}
					ind = str;
				}
			}

			this->L = auxL;
		}

		void print()
		{
			std::cout << "H5" << '\n';
			gout << this->dim << '\n';
			for (int i = 0; i < this->dim; ++i)
				gout << this->L[i] << ' ';
			gout << '\n';
		}
		void sort_heap()
		{

			std::cout << "H4" << '\n';
			NodeList<tp> auxL;
			NodeList<tp> locL;
			for (int i = 0; i < this->dim; ++i)
				locL.NodeInsert(this->L[i]);

			while (this->dim > 0)
			{
				auxL.NodeInsert(this->L[0]);
				L.swap(0,dim-1);
				L.NodeDelete();
				dim--;
				int ind = 0;
				while (ind < dim)
				{
					int st = ind * 2 + 1;
					int dr = ind * 2 + 2;
					if (dr < dim)
					{
						if (L[ind] < max(L[st], L[dr]))
						{
							if (L[st] < L[dr])
							{
								L.swap(ind, dr);
								ind = dr;
							}
							else {
								L.swap(ind, st);
								ind = st;
							}
						}
						else if (L[ind] < L[st])
						{
							L.swap(ind, st);
							ind = st;
						}
						else if (L[ind] < L[dr]) {
							L.swap(ind, dr);
							ind = dr;
						}
					}
					else if(st<dim){
						if (L[ind] < L[st])
						{
							L.swap(ind, st);
							ind = st;
						}
					}
					else break;
				}
			}

			/// reverse ca ii descrescator
			for (int i = 0; i < auxL.size / 2; ++i)
				auxL.swap(i,auxL.size - 1 - i);
			this->dim = auxL.size;
			for (int i = 0; i < this->dim; ++i)
				L.NodeInsert(auxL[i]);
			L.size = this->dim;
		}
		tp operator[](int ind)
		{
			return tp(this->L[ind]);
		}
};

