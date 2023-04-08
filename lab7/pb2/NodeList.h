
#include <fstream>
#include <iostream>
std::ofstream fout("A.txt");

template <typename tp> class NodeList {

public:

	int size;
	int max_size;
	tp* list;

	void swap(int i, int j)
	{
		tp aux = this->list[i];
		this->list[i] = this->list[j];
		this->list[j] = aux;

		return;
	}
	NodeList()
	{
		fout << "N1" << '\n';
		this->max_size = 4;
		this->list = new tp[this->max_size];
		this->size = 0;
	}
	void print1()
	{
		fout << "N!" << '\n';
		fout << this->size << '\n';
		for (int i = 0; i < this->size; ++i)
			fout << this->list[i] << ' ';
		fout << '\n';
	}
	void NodeInsert(tp A)
	{

		fout << "N3" << '\n';
		if (this->size == this->max_size)
		{
			this->Double();
			this->list[this->size] = A;
			this->size++;
			return;
		}

		this->list[this->size] = A;
		this->size++;
	}
	void NodeDelete()
	{
		fout << "N4" << '\n';
		this->size--;
	}
	void Double()
	{
		fout << "N5" << '\n';
		tp* aux = new tp[this->max_size * 2];
		for (int i = 0; i < this->max_size; ++i)
		{
			aux[i] = this->list[i];
		}
		delete[] list;

		this->list = aux;
		this->max_size *= 2;
	}
	tp operator[](int ind)
	{
		fout << "N6" << '\n';
		if (ind > this->size)
			return tp(0);
		return tp(this->list[ind]);
	}
};

