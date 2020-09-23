#include <iostream>
#include "Heap.h"
using std::cout;
using std::endl;
int main() {
	cout << "Hola mundo" << endl;
	Heap<int>* heap = new Heap<int>();
	heap->insertar(new int(8));
	heap->insertar(new int(5));
	heap->insertar(new int(12));
	heap->insertar(new int(6));
	heap->insertar(new int(7));
	heap->insertar(new int(18));
	heap->mostrar();

	//heap->CrearHeap();

	system("pause");
	return 0;
}