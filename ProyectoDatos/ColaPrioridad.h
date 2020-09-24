#pragma once
#include "Lista.h"
template <class T>
class ColaPrioridad {
public:
	ColaPrioridad(bool=true);
	ColaPrioridad(&ColaPrioridad);
	ColaPrioridad(&Lista<T>);

private:
	bool compara(T& obj_a, T& obj_b);
	bool tipo;
	

};

template<class T>
 ColaPrioridad<T>::ColaPrioridad(bool)
{
}

template<class T>
bool ColaPrioridad<T>::compara(T& obj_a, T& obj_b)
{
	return  (obj_a > obj_b) ? true : false;
}
