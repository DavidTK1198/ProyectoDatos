#pragma once
#include "Heap.h"
template <class T>
class ColaPrioridad {
public:
	ColaPrioridad(bool=true);
	ColaPrioridad(&ColaPrioridad);

	ColaPrioridad(&Lista<T>);//falta hacerlo
	bool isEmpty();
	bool insertar(T*&);


private:
	bool compara(T& obj_a, T& obj_b);
	bool tipo;
	Heap* heap;

	

};

template<class T>
 ColaPrioridad<T>::ColaPrioridad(bool m)
{
	 this->heap = new Heap<T>(m);
	 this->tipo = m;
	

}

 template<class T>
bool ColaPrioridad<T>::isEmpty()
 {
	 return false;
 }

 template<class T>
 bool ColaPrioridad<T>::insertar(T*& obj)
 {

	 return false;
 }

template<class T>
bool ColaPrioridad<T>::compara(T& obj_a, T& obj_b)
{
	return  (obj_a > obj_b) ? true : false;
}

//Referencia
//https://www.softwaretestinghelp.com/priority-queue-in-cpp/