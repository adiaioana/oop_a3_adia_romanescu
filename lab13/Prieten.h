#pragma once
#include "Contact.h"
using namespace std;
class Prieten : public Contact {
private:
	data_calendaristica data_nasterii;
	adresa acasa;
	std::string nr_telefon;
public:

	void SetName(string str)
	{
		nume = str;
	}
	
	Prieten() {
		nume = "unknown";
		nr_telefon = "0777-777-777";
		data_nasterii = data_calendaristica();
		acasa = adresa();
		tp = tipdecontact::prieten;
	}
	Prieten(string name) {
		nume = name;
		nr_telefon = "0777-777-777";
		data_nasterii = data_calendaristica();
		acasa = adresa();
		tp = tipdecontact::prieten;
	}
	Prieten(string name, string nr, data_calendaristica datacal, adresa adr) {
		nume = name;
		nr_telefon = nr;
		data_nasterii = datacal;
		acasa = adr;
		tp = tipdecontact::prieten;
	}
	int ifeq(Prieten B)
	{
		if (B.typeOfContact() != this->typeOfContact())
			return 0;
		if (B.Nume() != this->Nume())
			return 0;
		if (!(B.data_nasterii == this->data_nasterii))
			return 0;
		if (!(B.acasa == this->acasa))
			return 0;
		if (!(B.nr_telefon == this->nr_telefon))
			return 0;
		return 1;
	}
	~Prieten() {
		nr_telefon.clear();
		acasa.clear();
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
	adresa UndeSta()
	{
		return acasa;
	}
	std::string Telefon()
	{
		return nr_telefon;
	}
	void fordebug() {
		cout << "Pe prieten il cheama " << this->nume << '\n';
		cout << "Si aceasta persoana sta la adresa ";
		acasa.print();
		cout << '\n' << "Si s-a nascut ";
		data_nasterii.print();
		cout << '\n';
		cout << " si are si nr. de telefon: " << nr_telefon << '\n';
	}

};