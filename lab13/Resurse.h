#pragma once
#include <iostream>
#include <string>
using namespace std;

enum class tipdecontact {
	prieten = 0,
	coleg = 1,
	cunoscut = 2
};
struct data_calendaristica {
	int zi, luna, an;
	data_calendaristica(string str)
	{
		int cnt = 0;
		for(int i=0; i<str.size(); ++i)
			if(str[i]=='.' || str[i]=='/' )
				cnt++;
			else if(str[i]>='0' && str[i]<='9'){
				if(cnt==0)
					zi=zi*10+(str[i]-'0');
				else if(cnt==1)
					luna=luna*10+(str[i]-'0');
				else an=an*10+(str[i]-'0');
			}
	}
	bool operator== (data_calendaristica B)
	{
		return (B.zi == zi && B.an == an && B.luna == luna);
	}
	data_calendaristica() {
		zi = 25;
		luna = 12;
		an = 0;
	}
	void clear() {
		zi = luna = an = 0;
	}
	void print()
	{
		cout << " in ziua " << zi << ", luna " << luna << " si anul " << an << '\n';
	}
};
struct adresa {
	std::string strada;
	int nr_strada;
	std::string bloc;
	int nr_apartament;
	bool casa;
	bool operator == (adresa B)
	{
		return (((nr_apartament == B.nr_apartament && bloc == B.bloc ) || casa==B.casa)&& strada == B.strada && B.nr_strada == nr_strada);
	}
	void clear() {
		strada.clear();
		bloc.clear();
		nr_apartament = nr_strada = 0;
	}
	void print() {
		std::cout << "strada " << strada << " cu nr. " << nr_strada;
		if (!casa)
			std::cout << " la blocul " << bloc << " in apartamentul " << nr_apartament << '\n';
		else std::cout << " (la casa) " << '\n';
	}
	adresa() {
		strada = "Soseaua hihihaha";
		nr_apartament = 0;
		nr_strada = 20981;
		casa = 1;
	}
};
