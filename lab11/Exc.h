#include <exception>
using namespace std;
#pragma once
class exceptie_out_of_Array : public exception {
	virtual const char* what() const throw() {
		return "Value out of Array: Index exceeds capacity";
	}
};
class exceptie_out_of_Array_s : public exception { ///technically, not an error
	virtual const char* what() const throw() {
		return "Value isn't initialized in Array: Index exceeds size";
	}
};

class exceptie_invalid_index : public exception {
	virtual const char* what() const throw() {
		return "Invalid index: Negative value";
	}
};

class exceptie_diff_capacity : public exception {
	virtual const char* what() const throw() {
		return "= between two objects of different capacities";
	}
};
class exceptie_accesare_Lista_vida : public  exception {
	virtual const char* what() const throw() {
		return "Accessing a NULL List";
	}
};