#include <iostream>
#include "Lista.h"
#include "ColaPrioridad.h"
#include "Persona.h"
using std::cout;
using std::endl;
int main() {
	cout << "Hola mundo" << endl;
	Lista<int>* heap = new Lista<int>();
	Persona* per = new Persona("David", "123", 21);
	Persona* per2 = new Persona("Daniel", "1234", 21);
	
	int n = 8;
	if (*per ==*per2) {
		cout << "igual";
	}
	
	heap->insertar(new int(8));
	heap->insertar(new int(5));
	heap->insertar(new int(12));
	heap->insertar(new int(6));
	heap->insertar(new int(7));
	heap->insertar(new int(18));
	Lista<int>* e = new Lista<int>(*heap);
	
	heap->mostrar();
	cout << "----------------------------------Eliminando elemento---------------------" << endl;
	heap->eliminar();
	heap->mostrar();

	/*heap->CrearHeap();*/
	/*heap->mostrar();*/

	system("pause");
	return 0;
}