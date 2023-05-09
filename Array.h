#pragma once
#include "Exc.h"
#include "ArrayIterator.h"
#include <iostream>
#include <fstream>
using namespace std;
ofstream fout("debug_file1.txt");
exceptie_invalid_index exceptie_1;
exceptie_out_of_Array exceptie_2;
exceptie_out_of_Array_s exceptie_3;
exceptie_diff_capacity exceptie_4;
exceptie_accesare_Lista_vida exceptie_5;
class Compare {

public:

	virtual int CompareElements(void* e1, void* e2) = 0;

};



template<class T>

class Array {

	private:

	T** List; // lista cu pointeri la obiecte de tipul T*
	int Capacity; // dimensiunea listei de pointeri
	int Size; // cate elemente sunt in lista

	public:

	class Comp : public Compare {
	public:
		virtual int CompareElements(void* e1, void* e2)
		{
			T* a1 = (T*)(e1); T* a2 = (T*)(e2);
			if (*a1 == *a2)
				return 0;
			if (*a1 < *a2)
				return -1;
			return 1;
		}
	};
	

	Array(); // Lista nu e alocata, Capacity si Size = 0
	~Array(); // destructor
	Array(int capacity); // Lista e alocata cu 'capacity' elemente
	Array( Array<T>& otherArray); // constructor de copiere
	
	inline void DoubleAlloc();
	T& operator[] (int index); // arunca exceptie daca index este out of range
	const Array<T>& operator+=(const T& newElem); // adauga un element de tipul T la sfarsitul listei si returneaza this
	const Array<T>& Insert(int index, const T& newElem); // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	const Array<T>& Insert(int index, Array<T> otherArray); // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	const Array<T>& Delete(int index); // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
	bool operator==(Array<T>& otherArray);

	void Sort(); // sorteaza folosind comparatia intre elementele din T
	void Sort(int(*compare)(const T&, const T&)); // sorteaza folosind o functie de comparatie
	void Sort(Compare* comparator); // sorteaza folosind un obiect de comparatie
	// functii de cautare - returneaza pozitia elementului sau -1 daca nu exista

	int BinarySearch(const T& elem); // cauta un element folosind binary search in Array
	int BinarySearch(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind binary search si o functie de comparatie
	int BinarySearch(const T& elem, Compare* comparator);//  cauta un element folosind binary search si un comparator


	int Find(const T& elem); // cauta un element in Array
	int Find(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind o functie de comparatie
	int Find(const T& elem, Compare* comparator);//  cauta un element folosind un comparator

	int GetSize();
	int GetCapacity();


	void Print();
	ArrayIterator<T> GetBeginIterator();
	ArrayIterator<T> GetEndIterator();
	
	auto begin() {
		return GetBeginIterator();
	}
	auto end()	{
		return GetEndIterator();
	}

};

template<class T>
inline Array<T>::Array()
{
	fout << "CODE 1: Array constructed: simple" << '\n';
	Capacity = 4;
	Size = 0;
	List = new T * [Capacity];
}

template<class T>
inline Array<T>::~Array()
{
	fout << "CODE 4: Array deconstructed: simple" << '\n';
	delete[] List;
	Size = 0; Capacity = 4;
}

template<class T>
inline Array<T>::Array(int capacity)
{

	fout << "CODE 2: Array constructed with capacity" << '\n';
	Capacity = capacity;
	List = new T * [Capacity];
	Size = 0;
}

template<class T>
inline Array<T>::Array ( Array<T>& otherArray)
{
	fout << "CODE 3: Array constructed: another array" << '\n';
	//delete[] this->List;
	int cap = otherArray.GetCapacity();
	if(this->List!=nullptr)
		this->List= new T * [cap];

	else {
		delete[] List;
		this->List = new T * [cap];
	}
	for (int i = 0; i < otherArray.GetSize(); ++i)
	{
		this->List[i] = &otherArray[i];
	}
	this->Size = otherArray.GetSize();
	this->Capacity = otherArray.GetCapacity();
}

template<class T>
inline void Array<T>::DoubleAlloc()
{
	fout << "CODE 5: Double Alloc" << '\n';
	T** aux = new T * [Capacity * 2];
	for (int i = 0; i < Size; ++i)
		aux[i] = List[i];
	delete[] List;
	List = new T * [Capacity * 2];
	for (int i = 0; i < Size; ++i)
		List[i] = aux[i];
	Capacity *= 2;
}

template<class T>
inline T& Array<T>::operator[](int index)
{
	fout << "CODE 6: Accessing "<<index << '\n';
	try {
		if (index > this->Capacity)
			throw exceptie_2;
		if (index > this->Size) ///technically, not an error
			throw exceptie_3;
	}

	catch (exception& e) {
		cout << "Exceptie: " << e.what() << endl;
	}
	return *(this->List[index]);
}

template<class T>
inline const Array<T>& Array<T>::operator+=(const T& newElem)
{
	fout << "CODE 7: Adding " <<newElem<< '\n';
	try{
	if (this->Size >= this->Capacity)
		DoubleAlloc();
	T* val=new T;
	*val = newElem;
	List[Size] = val;
	Size++;
	}
	catch (exception& e) {
		cout << "Exceptie: " << e.what() << endl;
	}
	return *this;
}

template<class T>
inline const Array<T>& Array<T>::Insert(int index, const T& newElem)
{
	fout << "CODE 8: Adding " << newElem <<" on "<<index << '\n';
	try {
		if (index < 0)
			throw exceptie_1;
		if (index > Capacity)
			throw exceptie_2;
		if (index > Size) ///technically, not an error
			throw exceptie_3;

		if (Size == Capacity)
			DoubleAlloc();
		T** aux = new T * [Capacity];
		for (int i = index, j = 0; i < Size; ++i, ++j)
			aux[j] = List[i];
		T* val = new T;
		*val = newElem;

		List[index] = val;
		Size++;
		for (int i = index + 1, j = 0; i < Size; ++i, ++j)
			List[i] = aux[j];
	}
	catch (exception& e) {
		cout << "Exceptie: " << e.what() << endl;

	}
	return *this;
}

template<class T>
inline const Array<T>& Array<T>::Insert(int index, Array<T> otherArray)
{
	fout << "CODE 9: Adding another Array on " << index << '\n';
	try {
		if (index < 0)
			throw exceptie_1;
		if (index > Capacity)
			throw exceptie_2;
		if (index > Size) ///technically, not an error
			throw exceptie_3;

		while (Size + otherArray.GetSize() > Capacity) {
			int a = Size;
			int b = Capacity;
			this->DoubleAlloc();
		}
			
		T** aux = new T * [Capacity];
		for (int i = index, j = 0; i < Size; ++i, ++j)
			aux[j] = List[i];

		for (int i = index, j = 0; j < otherArray.GetSize(); ++i, ++j)
			List[i] = &otherArray[j];
		for (int i = index + otherArray.GetSize(), j = 0; i < Size + otherArray.GetSize(); ++j, ++i)
			List[i] = aux[j];
		Size += otherArray.GetSize();
	}
	catch (exception& e) {

		cout << "Exceptie: " << e.what() << endl;
	}
	return *this;
}

template<class T>
inline const Array<T>& Array<T>::Delete(int index)
{
	fout << "CODE 10: Deleting " << index << '\n';
	try {
		if (index < 0)
			throw exceptie_1;
		if (index > Capacity)
			throw exceptie_2;
		if (index > Size) ///technically, not an error
			throw exceptie_3;


		for (int i = index + 1; i < Size; ++i)
			List[i - 1] = List[i];
		delete List[Size - 1];;
		Size--;
	}

	catch (exception& e) {

		cout << "Exceptie: " << e.what() << endl;
	}
	return this;
}

template<class T>
inline bool Array<T>::operator==(Array<T>& otherArray)
{

	fout << "CODE 11: Copying another Array "<< '\n';
	if (otherArray.GetSize() != Size)
		return false;

	for (int i = 0; i < otherArray.GetSize(); ++i)
		if (*this->List[i] != otherArray[i])
			return false;
	return true;
}

template<class T>
inline void Array<T>::Sort()
{
	fout << "CODE 12: Sorting Array : simple" << '\n';
	for(int i=0; i<Size-1; ++i)
		for(int j=i+1; j<Size; ++j)
			if (*List[i] > *List[j])
			{
				T aux = *List[i];
				*List[i] = *List[j];
				*List[j] = aux;
			}
	return;
}

template<class T>
inline void Array<T>::Sort(int(*compare)(const T&, const T&))
{
	fout << "CODE 13: Sorting Array : with function" << '\n';
	for (int i = 0; i < Size - 1; ++i)
		for (int j = i + 1; j < Size; ++j)
			if (compare(*List[i],*List[j])>0)
			{
				T aux = *List[i];
				*List[i] = *List[j];
				*List[j] = aux;
			}
	return;
}

template<class T>
inline void Array<T>::Sort(Compare* comparator)
{
	fout << "CODE 14: Sorting Array : with class" << '\n';
	for (int i = 0; i < Size - 1; ++i)
		for (int j = i + 1; j < Size; ++j)
			if (comparator->CompareElements(List[i],List[j])>0)
			{
				T aux = *List[i];
				*List[i] = *List[j];
				*List[j] = aux;
			}
	return;

}

template<class T>
inline int Array<T>::BinarySearch(const T& elem)
{
	fout << "CODE 19: Binary Search : simple" << '\n';
	int st, dr, mij, sol=-1;
	st = 0; dr = Size - 1;
	while (st <= dr)
	{
		mij = (st + dr) / 2;
		if (*this->List[mij] < elem)
			st = mij + 1;
		else if (*this->List[mij] > elem)
			dr = mij - 1;
		else {
			sol = mij;
			break;
		}
	}
	return sol;
}

template<class T>
inline int Array<T>::BinarySearch(const T& elem, int(*compare)(const T&, const T&))
{
	fout << "CODE 20: Binary Search : comp func" << '\n';

	int st, dr, mij, sol = -1;
	st = 0; dr = Size - 1;
	while (st <= dr)
	{
		mij = (st + dr) / 2;
		if (compare(*this->List[mij], elem)<0)
			st = mij + 1;
		else if (compare(*this->List[mij], elem) >0)
			dr = mij - 1;
		else {
			sol = mij;
			break;
		}
	}
	return sol;
}

template<class T>
inline int Array<T>::BinarySearch(const T& elem, Compare* comparator)
{
	fout << "CODE 21: Binary Search : comp class" << '\n';
	int st, dr, mij, sol = -1;
	st = 0; dr = Size - 1;
	while (st <= dr)
	{
		mij = (st + dr) / 2;
		if (comparator->CompareElements(*this->List[mij], elem) < 0)
			st = mij + 1;
		else if (comparator->CompareElements(*this->List[mij], elem) > 0)
			dr = mij - 1;
		else {
			sol = mij;
			break;
		}
	}
	return sol;
}

template<class T>
inline int Array<T>::Find(const T& elem)
{
	fout << "CODE 22: Find: simple" << '\n';
	for (int i = 0; i < Size; ++i) {
		//fout << i << ' ' << *List[i] << ' ' << elem << '\n';
		if (*List[i] == elem)
			return i;
	}
	return -1;
}

template<class T>
inline int Array<T>::Find(const T& elem, int(*compare)(const T&, const T&))
{
	fout << "CODE 23: Find: comp func" << '\n';
	for (int i = 0; i < Size; ++i)
		if (compare(*List[i],elem)==0)
			return i;
	return -1;
}

template<class T>
inline int Array<T>::Find(const T& elem, Compare* comparator)
{
	fout << "CODE 24: Find: comp class" << '\n';
	for (int i = 0; i < Size; ++i)
		if (comparator->CompareElements(*List[i],elem)==0)
			return i;
	return -1;
}

template<class T>
inline int Array<T>::GetSize()
{
	fout << "CODE 14: Getting size= "<<Size << '\n';
	return Size;
}

template<class T>
inline int Array<T>::GetCapacity()
{
	fout << "CODE 15: Getting capacity= " << Capacity << '\n';
	return Capacity;
}

template<class T>
inline void Array<T>::Print()
{
	fout << "CODE 16: Printing Array" << '\n';
	cout << Size << '\n';
	for (int i = 0; i < Size; ++i)
		cout << *List[i] << ' ';
	cout << '\n';
}

template<class T>
inline ArrayIterator<T> Array<T>::GetBeginIterator()
{
	fout << "CODE 17: Getting begin it " << '\n';
	try {
		if (Size == 0)
			throw exceptie_5;
	}

	catch (exception& e) {
		cout << "Exceptie: " << e.what() << endl;
	}
	return ArrayIterator<T>(this->List);
}

template<class T>
inline ArrayIterator<T> Array<T>::GetEndIterator()
{
	fout << "CODE 18: Getting end it " << '\n';
	try {
		if (Size == 0)
			throw exceptie_5;
	}
	catch (exception& e) {
		cout << "Exceptie: " << e.what() << endl;
	}
	ArrayIterator<T> K(this->List + this->Size);
	return ArrayIterator<T>(K);
}
