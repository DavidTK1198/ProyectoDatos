#pragma once
#include <sstream>
#include <iostream>
using std::ostream;
using std::string;
using std::stringstream;
class Persona
{
public:
	string getNombre();
	string getCed();
	int getEdad();
	void setEdad(int);
	void setNombre(string);
	void setCedula(string);
	Persona();
	Persona(string = "", string = "", int = 0);
	friend ostream& operator <<(ostream&, Persona&);
	bool operator == (Persona&);
	bool operator > (Persona&);
	bool operator < (Persona&);
	bool operator >= (Persona&);
private:
	string nombre;
	string ced;
	int edad;
	
};

