#pragma once

#include "Contact.h"

class Cunoscut :public Contact {
private:

	std::string nr_telefon;
public:


	void fordebug() {
		cout << "Pe cunoscut il cheama " << this->nume << '\n';
		cout << "Si aceasta persoana are nr. de telefon: ";
		
		cout <<nr_telefon<< '\n';
	}

	void SetName(string str) {
		nume = str;
	}
	int ifeq(Cunoscut B)
	{
		if (B.typeOfContact() != this->typeOfContact())
			return 0;
		if (B.Nume() != this->Nume())
			return 0;
		if (!(B.nr_telefon == this->nr_telefon))
			return 0;
		return 1;
	}
	Cunoscut() {
		nr_telefon = "0777-777-777";
		nume = "unknown";
		tp = tipdecontact::cunoscut;
	}
	Cunoscut(string name) {
		nume = name;
		nr_telefon = "0777-777-777";
		tp = tipdecontact::cunoscut;
	}
	Cunoscut(string name,string nr) {
		nr_telefon = nr;
		nume = name;
		tp = tipdecontact::cunoscut;
	}
	~Cunoscut() {
		nr_telefon.clear();
	}

	std::string Nume()
	{
		return this->nume;
	}

};