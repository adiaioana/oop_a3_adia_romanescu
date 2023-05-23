#pragma once

#include "Contact.h"

class Coleg : public Contact {
private:
	data_calendaristica data_nasterii;
	std::string firma;
	std::string nr_telefon;
public:
	Coleg() {
		nr_telefon = "0777-777-777";
		data_nasterii = data_calendaristica();
		firma = "ANAF";
		nume = "unknown";
		tp = tipdecontact::coleg;
	}
	Coleg(string name) {
		nume = name;
		nr_telefon = "0777-777-777";
		data_nasterii = data_calendaristica();
		firma = "ANAF";
		tp = tipdecontact::coleg;
	}
	Coleg(string name, string fir, string nr, data_calendaristica datacal)
	{
		nr_telefon = nr;
		firma = fir;
		nume = name;
		data_nasterii = datacal;
		tp = tipdecontact::coleg;
	}
	~Coleg() {
		nr_telefon.clear();
		firma.clear();
		data_nasterii.clear();
	}

	std::string Nume()
	{
		return this->nume;
	}
	data_calendaristica CandS_aNascut()
	{
		return data_nasterii;
	}

	void SetName(string str) {
		nume = str;
	}
	int ifeq(Coleg B)
	{
		if (B.typeOfContact() != this->typeOfContact())
			return 0;
		if (B.Nume() != this->Nume())
			return 0;
		if (!(B.data_nasterii == this->data_nasterii))
			return 0;
		return 1;
	}
	std::string UndeLucreaza()
	{
		return firma;
	}
	std::string Telefon()
	{
		return nr_telefon;
	}
	void fordebug() {
		cout << "Pe coleg il cheama " << this->nume << '\n';
		cout << "Si aceasta persoana lucreaza la "<<firma;
		cout << '\n' << "Si s-a nascut ";
		data_nasterii.print();
		cout << '\n';
		cout << " si are si nr. de telefon: " << nr_telefon << '\n';
	}
};