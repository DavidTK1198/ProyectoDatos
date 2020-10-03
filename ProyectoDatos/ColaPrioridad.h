#pragma once
template <class T>
class ColaPrioridad {
public:

	ColaPrioridad(bool=true);
	ColaPrioridad(const ColaPrioridad<T> &cl);
	ColaPrioridad(const Lista<T>& ls);//falta hacerlo
	bool isEmpty();
	bool insertar(T*&);
	bool eliminar();
	T peek();
private:
	bool compara(T& obj_a, T& obj_b);
	bool tipo;
	int getHijoIz(int);
	Lista<T>* contenedor;
	void MaxHeapify(int);
	void MinHeapify(int);
	void Intercambio(int, int);
	void CrearHeap(Lista<T>*);
	int getPadre(int);
	int getHijoDer(int);
	void SiftUp();
};

template<class T>
ColaPrioridad<T>::ColaPrioridad(bool m)
{
	this->heap = new Lista<T>();
	this->tipo = m;
}

template<class T>
ColaPrioridad<T>::ColaPrioridad( const ColaPrioridad<T> &cl) {
	
}

template<class T>
 ColaPrioridad<T>::ColaPrioridad(const Lista<T>& ls)
{
}


template<class T>
bool ColaPrioridad<T>::isEmpty()
{
	return this->Contenedor->empty();
}

template<class T>
bool ColaPrioridad<T>::insertar(T*& obj)
{
	this->contenedor->insertar(obj);
	this->SiftUp(contenedor->getCantidad());
	return true;
}

template<class T>
bool ColaPrioridad<T>::eliminar()
{
	return this->contenedor->eliminar();
}

template<class T>
 T ColaPrioridad<T>::peek()
{
	return contenedor->elemento();
}

template<class T>
bool ColaPrioridad<T>::compara(T& obj_a, T& obj_b)
{
	return  (obj_a > obj_b) ? true : false;
}

template<class T>
void ColaPrioridad<T>::MaxHeapify(int i)
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
 void ColaPrioridad<T>::MinHeapify(int i)//debatir
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
int ColaPrioridad<T>::getHijoIz(int i)
{

	Nodo<T>* actual;
	actual = contenedor->getFront();
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
void ColaPrioridad<T>::CrearHeap(Lista<T>* ls)
{
	int n = (contenedor->getCantidad() / 2 - 1); //Revisar minuciosamente
	for (int i = n; i >= 0; i--) {
		this->Heapify(i);
	}
}

template<class T>
int ColaPrioridad<T>::getPadre(int i)
{
	Nodo<T>* actual;
	actual = contenedor->getFront();
	int contador = 0;
	int ayudante = ((i - 1) / 2);
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
int ColaPrioridad<T>::getHijoDer(int i)
{

	Nodo<T>* actual;
	actual = contenedor->getFront();
	int contador = 0;
	int ayudante = ((i * 2) + 2);
	while (actual != nullptr) {

		if (contador == ayudante) {
			return ayudante;
		}
		contador++;
		actual = actual->getSiguiente();
	}
	return -1;//ColaPrioridad... return -1// return (5)
}

template<class T>
inline void ColaPrioridad<T>::SiftUp()
{
	Nodo<T>* aux = contenedor->getBack();
	while (aux)
		aux = aux->getAnterior();
}

template<class T>
void ColaPrioridad<T>::Intercambio(int mayor, int i)
{
	T* aux = nullptr;
	T* aux2 = nullptr;
	T* temporal = nullptr;
	Nodo<T>* ayudante = nullptr;
	Nodo<T>* actual;
	actual = contenedor->getFront();
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



//Referencia
//https://www.softwaretestinghelp.com/priority-queue-in-cpp/