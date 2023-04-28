#pragma once
#include "Node.h"
#include <iostream>
template <typename tp> class DoubleLinkedList{
	
public:
	Node <tp>* first;
private:
	int count;
public:
	DoubleLinkedList();
	~DoubleLinkedList();
	void PushOnBack(tp data);
	tp PopFromBack();
	tp PopFromFront();
	int GetCount();
	void PushOnFront(tp data);
	void PrintAll(void printfunction(const tp& v));

};

template<typename tp>
inline DoubleLinkedList<tp>::DoubleLinkedList()
{
	this->count = 0;
	this->first = new Node <tp>;
	this->first->ant = this->first->succ = nullptr;
}

template<typename tp>
inline DoubleLinkedList<tp>::~DoubleLinkedList()
{
	if (this->count == 1)
	{
		this->count = 0;  delete first; return;
	}

	int i = 1; int size_aux = 0;
	Node <tp>* p = this->first,*q;
	while (p->succ != nullptr)
	{
		size_aux++;
		p = p->succ;
	}
	/// i ar trebui sa fie count
	q = p;
	while (this->count--)
	{
		q = q->ant;
		delete q->succ;
	}
}

template<typename tp>
inline void DoubleLinkedList<tp>::PushOnBack(tp data)
{
	Node <tp>* ul = new Node <tp>;
	ul->info = data; ul->ant = ul->succ = nullptr;
	
	if (this->count == 0)
	{
		this->count = 1;
		this->first = ul;
		return;
	}
	Node <tp>* p = this->first; int size_aux = 0;
	while (p->succ != nullptr)
	{
		size_aux++;
		p = p->succ;
	}
	ul->ant = p;
	p->succ = ul;
	this->count++;
}

template<typename tp>
inline tp DoubleLinkedList<tp>::PopFromBack()
{
	if (this->count == 0)
		return tp(0);
	if (this->count == 1)
	{
		count = 0;
		tp ans = first->info;
		first = nullptr;
		return ans;
	}
	tp ans = this->first->info;
	Node <tp>* p = this->first; int size_aux = 0;
	while (p->succ != nullptr)
	{
		size_aux++;
		p = p->succ;
		ans = p->info;
	}

	(p->ant)->succ = nullptr;
	delete p;
	this->count--;
	return tp(ans);
}

template<typename tp>
inline tp DoubleLinkedList<tp>::PopFromFront()
{
	if (this->size == 0)
		return tp(0);
	if (this->count == 1)
	{
		count = 0;
		tp ans = first->info;
		first = nullptr;
		return ans;
	}
	Node <tp>* p = first->succ;
	tp ans = first->info;
	delete first;
	first = p;
	first->ant = nullptr;
	return tp(ans);
}

template<typename tp>
inline int DoubleLinkedList<tp>::GetCount()
{
	int size_aux = 0;
	Node <tp>* p = this->first;
	while (p != nullptr)
	{
		size_aux++;
		p = p->succ;
	}

	if (size_aux != this->count)
		this->count = size_aux;
	return size_aux;
}

template<typename tp>
inline void DoubleLinkedList<tp>::PushOnFront(tp data)
{
	Node <tp>* p = new Node <tp>, *q;
	p->ant = nullptr; p->info = data; p->succ = nullptr;
	if (count == 0)
	{
		first = p; count=1;
		return;
	}
	first->ant = p;
	p->succ = first;
	first = p;
	count++;
}

template<typename tp>
inline void DoubleLinkedList<tp>::PrintAll(void printfunction(const tp & v))
{
	int size_aux = 0;
	Node <tp>* p = this->first;
	std::cout << "Printing Double Linked List of "<< count<<" element(s): " << std::endl;
	while (p != nullptr)
	{
		size_aux++;
		if (size_aux > count)
			return;
		printfunction(tp(p->info));
		p = p->succ;
	}
	std::cout << std::endl;
}
