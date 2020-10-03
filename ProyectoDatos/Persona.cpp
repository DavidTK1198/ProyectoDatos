#include "Persona.h"

string Persona::getNombre()
{
    return this->nombre;
}

string Persona::getCed()
{
    return this->ced;
}

int Persona::getEdad()
{
    return this->edad;
}

void Persona::setEdad(int eda)
{
    this->edad = eda;
}

void Persona::setNombre(string nom)
{
    this->nombre = nom;
}

void Persona::setCedula(string cedu)
{
    this->ced = cedu;
}


Persona::Persona(string ced, string nom, int eda)
{
    this->ced = ced;
    this->nombre = nom;
    this->edad = eda;
}

Persona::operator int const()
{
    return edad;
}

ostream& operator<<(ostream& os, Persona&)
{
    return os;
}
