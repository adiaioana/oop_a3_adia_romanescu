#pragma once
#include "Resurse.h"
#include <iostream>
class Contact {

	protected:
	std:: string nume;
	tipdecontact tp;
	public:
		Contact() {
			nume.clear();
		}
		~Contact() {
			nume.erase();
		}
		Contact(char *p) {
			nume.clear();
			int lg = strlen(p);
			for (int i = 0; i < lg; ++i)
				nume[i] = p[i], nume[i+1]='\0';
		}
		Contact(std::string str) {
			nume.clear();
			nume = str;
		}


		  std::string Nume();
		  std::string typeOfContact();
		 // void fordebug() ;
		  int ifeq(Contact A) ;
		  void SetName(string str);
};
