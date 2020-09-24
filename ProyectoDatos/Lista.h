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
	void limpiaHeap();
	bool empty();
	bool insertar(T*);
	//bool eliminar();
	void Heapify(int);
	void CrearHeap();
	int getPadre(int i);
	int getHijoIz(int i);
	int getHijoDer(int i);
	void Intercambio(int, int);
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
void Lista<T>::Heapify(int i)
{
	int izq = this->getHijoIz(i);//index vectores...
	int der = this->getHijoDer(i);//nodo 3 
	int mayor = 0;
	if (izq == -1 || der == -1) {
		return;
	}

	if (izq > i) {
		mayor = izq;
	}
	else {
		mayor = i;
	}
	if (der > mayor) {
		mayor = der;
	}

	if (mayor != i) {
		this->Intercambio(mayor, i);
		this->Heapify(mayor);
	}

}

template<class T>
void Lista<T>::CrearHeap()
{
	int n = (this->cantidad / 2-1); //Revisar minuciosamente
	for (int i = n; i >= 0; i--) {
		this->Heapify(i);
	}
}

template<class T>
int Lista<T>::getPadre(int i)
{
	
	actual = primero;
	int contador = 0;
	int ayudante = ((i - 1)/ 2);
	while (actual != nullptr) {
		
		if (contador == ayudante) {
			return ayudante;
		}
		contador++;
		actual = actual->getSiguiente();
	}
	return -1;
}

template<class T>
int Lista<T>::getHijoIz(int i)
{
	
	actual = primero;
	int contador = 0;
	int ayudante = ((i * 2) + 1);
	while (actual != nullptr) {
		
		if (contador == ayudante) {
			return ayudante;
		}
		contador++;
		actual = actual->getSiguiente();
	}
	return -1;
}

template<class T>
int Lista<T>::getHijoDer(int i)
{
	
	actual = primero;
	int contador = 0;
	int ayudante = ((i * 2) + 2);
	while (actual != nullptr) {
		
		if (contador == ayudante) {
			return ayudante;
		}
		contador++;
		actual = actual->getSiguiente();
	}
	return -1;//lista... return -1// return (5)
 }

template<class T>
void Lista<T>::Intercambio(int mayor, int i)
{
	T* aux = nullptr;
	T* aux2 = nullptr;
	T* temporal = nullptr;
	Nodo<T>* ayudante = nullptr;
	actual = primero;
	int contador = 0;
	int contador2 = 0;
	while (actual != nullptr) {
		if (mayor < i) {
			if (contador == mayor) {
				aux = actual->getObjetoPtr();
				ayudante = actual;
			}
			if (contador2 == i) {
				aux2 = actual->getObjetoPtr();
				actual->setObjetoPtr(aux);
				ayudante->setObjetoPtr(aux2);
			}
		}
		else {
			if (contador == i) {
				aux = actual->getObjetoPtr();
				ayudante = actual;
			}
			if (contador2 == mayor) {
				aux2 = actual->getObjetoPtr();
				actual->setObjetoPtr(aux);
				ayudante->setObjetoPtr(aux2);
			}
		}
		actual = actual->getSiguiente();
		contador2++;
		contador++;
	}

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



