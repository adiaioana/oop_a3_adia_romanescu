#pragma once
#include "Contact.h"
#include "Cunoscut.h"
#include "Coleg.h"
#include "Prieten.h"
#include <vector>
class Agenda {
	private:
	std::vector<Contact> L;
	
	public:
	std::vector<Contact> DoarPrietenii()
	{
		vector <Contact> P;
		P.clear();
		for (int i = 0; i < L.size(); ++i)
			if (L[i].typeOfContact() == "prieten")
			{
				Prieten A;
				A.SetName(L[i].Nume());
				P.push_back(A);
			}
		return P;
	}
	int NrContacte() {
		return L.size();
	}

	int ExistaContact(Contact A)
	{
		for (int i = 0; i < L.size(); ++i)
		{
			if (L[i].Nume() == L[i].Nume() && L[i].typeOfContact() == L[i].typeOfContact())
			{
				if (A.ifeq(L[i]))
					return 1;
			}
		}
		return 0;
	}
	void fordebug_list() {
		for (int i = 0; i < L.size(); ++i) {
			//cout << "Contactul i: " << '\n';
			//cout << L[i].Nume() << '\n';
			//L[i].fordebug();
			cout << '\n';
		}
	}
	int ExistaContact(std::string str)
	{
		for (int i = 0; i < L.size(); ++i)
		{
			Contact A = L[i];
			if (A.Nume() == str)
				return 1;
		}
		return 0;
	}
	void erase(std::string name)
	{
		for(int i=0; i<L.size(); ++i)
			if (L[i].Nume() == name)
			{
				swap(L[i], L[L.size() - 1]);
				L.pop_back();
				return;
			}
	}
	void insert(Contact A)
	{
		L.push_back(A);
	}
};