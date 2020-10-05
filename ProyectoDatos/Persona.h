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

	Persona(string = "", string = "", int = 0);
	Persona(const Persona&);
	friend ostream& operator <<(ostream&, Persona&);
	operator int  const ();
private:
	string nombre;
	string ced;
	int edad;
	
};

