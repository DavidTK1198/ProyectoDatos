#pragma once
#include <sstream>
using std::string;
template <class T>
class Nodo {
private:
	Nodo<T>* anterior;
	Nodo<T>* siguinte;
	T* objetoPtr;
public:
	Nodo(T*, Nodo*);
	virtual ~Nodo();
	T* getObjetoPtr();
	Nodo* getSiguiente();
	Nodo* getAnterior();
	void setAnterior(Nodo*);
	void setObjetoPtr(T*);
	void setSiguiente(Nodo*);
};

template<class T>
Nodo<T>::Nodo(T* ptr, Nodo* nod) :
	objetoPtr(ptr), sig(nod)
{}

template<class T>
Nodo<T>::~Nodo() {
	delete objetoPtr;
}

template<class T>
T* Nodo<T>::getObjetoPtr() {
	return objetoPtr;
}

template<class T>
Nodo<T>* Nodo<T>::getSiguiente() {
	return sig;
}

template<class T>
 Nodo<T>* Nodo<T>::getAnterior()
{
	return anterior;
}

template<class T>
 void Nodo<T>::setAnterior(Nodo* an)
{
	 anterior = an;
}

template<class T>
void Nodo<T>::setObjetoPtr(T* ptr) {
	objetoPtr = ptr;
}

template<class T>
void Nodo<T>::setSiguiente(Nodo* nod) {
	sig = nod;
}

//-----------------------Heap-----------------


template <class T>
class Heap {
private:

	Nodo<T>* primero;
	

public:
	Heap();
	virtual ~Heap();
	void limpiaHeap();
	bool empty();
	bool insertar(T*);
	bool eliminar();
	void Heapify();
	void CrearHeap();
	T* getPadre();
	T* getHijoIz();
	T* getHijoDer();

};

template <class T>
Heap<T>::Heap() {
	primero = NULL;
	actual = NULL;
	ultimo = NULL;
	n = 0;
}

template <class T>
Heap<T>::~Heap() {
	this->limpiaHeap();
}

template<class T>
void Heap<T>::limpiaHeap() {
	Nodo<T>* actuall = NULL;
	while (primero != NULL)
	{
		actuall = primero;
		n--;
		primero = actuall->getSiguiente(); 
		delete actuall;
	}
}
template<class T>
bool Heap<T>::empty()
{
	return primero == NULL;
}


template<class T>
bool Heap<T>::insertar(T* p)
{
	
}



