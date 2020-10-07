#include <iostream>
#include "Lista.h"
#include "ColaPrioridad.h"
#include "Persona.h"
using std::cout;
using std::endl;
int main() {
	cout << "Hola mundo" << endl;
	ColaPrioridad<Persona>* colita = new ColaPrioridad<Persona>();
	Persona* per = new Persona("David", "123", 21);
	Persona* per2 = new Persona("Daniel", "1234", 65);
	Persona* per3 = new Persona("Marco", "555", 45);
	colita->insertar(per);
	colita->insertar(per2);
	colita->insertar(per3);
	ColaPrioridad<Persona>* prueba = new ColaPrioridad<Persona>(*colita);
	colita->mostrar();
	cout << "--------------------------------------------------------" << endl;
	colita->eliminar();
	colita->mostrar();
	cout << "----------------------------------------------------------" << endl;
	cout << "------------------------------DATOS DEL CONSTRUCTOR COPIA--------------------" << endl;
	prueba->mostrar();
	Lista<int>* heap = new Lista<int>();
	heap->insertar(new int(8));
	heap->insertar(new int(5));
	heap->insertar(new int(12));
	heap->insertar(new int(7));
	heap->insertar(new int(18));

	ColaPrioridad<int>* colaa = new ColaPrioridad<int>(*heap,false);

	cout << "----------------------------------------------------" << endl;
	cout << "Probando crear heap..." << endl;
	colaa->mostrar();


	system("pause");
	return 0;
}