#pragma once
template <class T>
class Nodo {
private:
	Nodo<T>* anterior;
	Nodo<T>* siguinte;
	T* objetoPtr;
public:
	Nodo(T*, Nodo<T>*,Nodo<T>*);
	virtual ~Nodo();
	T* getObjetoPtr();
	Nodo<T>* getSiguiente();
	Nodo<T>* getAnterior();
	void setAnterior(Nodo<T>*);
	void setObjetoPtr(T*);
	void setSiguiente(Nodo<T>*);
};


template<class T>
 Nodo<T>::Nodo(T* v, Nodo<T>* n, Nodo<T>* p)
{
	 this->objetoPtr = v;
	 this->anterior = p;
	 this->siguinte = n;
}

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
	return this->siguinte;
}

template<class T>
 Nodo<T>* Nodo<T>::getAnterior()
{
	return anterior;
}

template<class T>
 void Nodo<T>::setAnterior(Nodo<T>* an)
{
	 anterior = an;
}

template<class T>
void Nodo<T>::setObjetoPtr(T* ptr) {
	objetoPtr = ptr;
}

template<class T>
void Nodo<T>::setSiguiente(Nodo<T>* nod) {
	this->siguinte = nod;
}

//-----------------------Lista-----------------


template <class T>
class Lista {
private:

	Nodo<T>* primero;
	Nodo<T>* actual;
	int cantidad;
	

public:
	Lista();
	virtual ~Lista();
	int getCantidad();
	void limpiaHeap();
	Nodo<T>* getFront();
	bool empty();
	bool insertar(T*);
	//bool eliminar();
	void mostrar();

};

template <class T>
Lista<T>::Lista() {
	primero = nullptr;
	actual = nullptr;
	cantidad = 0;
}

template <class T>
Lista<T>::~Lista() {
	this->limpiaHeap();
}

template<class T>
int Lista<T>::getCantidad()
{
	return cantidad;
}

template<class T>
void Lista<T>::limpiaHeap() {
	Nodo<T>* actuall = NULL;
	while (primero != NULL)
	{
		actuall = primero;
		cantidad--;
		primero = actuall->getSiguiente(); 
		delete actuall;
	}
}
template<class T>
Nodo<T>* Lista<T>::getFront()
{
	return primero;
}
template<class T>
bool Lista<T>::empty()
{
	return primero == NULL;
}


template<class T>
bool Lista<T>::insertar(T* p)
{
	Nodo<T>* aux = nullptr;
	actual = primero;

	if (primero == nullptr) {
		this->primero = new Nodo<T>(p, nullptr, nullptr);
		return true;
	}
	while (actual->getSiguiente()) {
		actual = actual->getSiguiente();
	}
	aux = new Nodo<T>(p, nullptr, actual);
	this->cantidad++;
	actual->setSiguiente(aux);
	return true;
	
}


template<class T>
void Lista<T>::mostrar()
{
	actual = primero;
	while (actual) {
		std::cout << *actual->getObjetoPtr() << std::endl;
		actual = actual->getSiguiente();
	}
}



