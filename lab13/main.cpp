#pragma once
#include "Agenda.h"


using namespace std;
vector<data_calendaristica> lista_dati;
vector<adresa> lista_adrese;
string mat[10] = { "Adia" , "Vivi", "Miha", "Matei", "ovidio" };
/*
void init() {
	lista_dati.push_back(data_calendaristica("12/12/1900"));
	lista_dati.push_back(data_calendaristica("13/11/1902"));
	lista_dati.push_back(data_calendaristica("11/9/1901"));

	lista_adrese.push_back({"strada casa",2,"B3",2,0});
	lista_adrese.push_back({"strada bloc",3,"\0",0,1});
}*/
int main()
{
	 Prieten A;
	 Coleg B;
	 Cunoscut C;
	 A.SetName(mat[0]);
	 B.SetName(mat[1]);
	 C.SetName(mat[2]);

	A.fordebug();

	Agenda Fac;
	Fac.insert(A);
	Fac.insert(B);
	Fac.insert(C);

	Fac.fordebug_list();

	return 0;
}