#include <iostream>
#include "Lista.h"
using std::cout;
using std::endl;
int main() {
	cout << "Hola mundo" << endl;
	Lista<int>* heap = new Lista<int>();
	heap->insertar(new int(8));
	heap->insertar(new int(5));
	heap->insertar(new int(12));
	heap->insertar(new int(6));
	heap->insertar(new int(7));
	heap->insertar(new int(18));
	heap->mostrar();

	/*heap->CrearHeap();*/
	/*heap->mostrar();*/

	system("pause");
	return 0;
}