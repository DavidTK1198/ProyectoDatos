#include <iostream>
#include "Lista.h"
#include "ColaPrioridad.h"
#include "Persona.h"
using std::cout;
using std::endl;
int main() {
	cout << "Hola mundo" << endl;
	ColaPrioridad<Persona>* colita = new ColaPrioridad<Persona>(false);
	Lista<Persona>* heap = new Lista<Persona>();
	Persona* per = new Persona("David", "123", 21);
	Persona* per2 = new Persona("Daniel", "1234", 65);
	Persona* per3 = new Persona("Marco", "555", 45);
	colita->insertar(per2);
	colita->insertar(per);
	colita->insertar(per3);
	colita->mostrar();


	cout << "--------------------------------------------------------" << endl;
	colita->eliminar();
	colita->mostrar();




	/*int n = 8;
	if (*per ==*per2) {
		cout << "igual";
	}*/
	
	//heap->insertar(new int(8));
	//heap->insertar(new int(5));
	//heap->insertar(new int(12));
	//heap->insertar(new int(6));
	//heap->insertar(new int(7));
	//heap->insertar(new int(18));
	
	/*Lista<int>* e = new Lista<int>(*heap);*/
	
	heap->mostrar();
	cout << "----------------------------------Eliminando elemento---------------------" << endl;
	heap->eliminar();
	heap->mostrar();

	/*heap->CrearHeap();*/
	/*heap->mostrar();*/

	system("pause");
	return 0;
}