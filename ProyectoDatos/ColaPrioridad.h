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
	void mostrar();
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
	void SiftUpMenor();
};

template<class T>
ColaPrioridad<T>::ColaPrioridad(bool m)
{
	this->contenedor = new Lista<T>();
	this->tipo = m;
}

template<class T>
ColaPrioridad<T>::ColaPrioridad( const ColaPrioridad<T> &cl) {
	this->tipo = cl.tipo;
	this->contenedor = new Lista<T>(*cl.contenedor);
}

template<class T>
 ColaPrioridad<T>::ColaPrioridad(const Lista<T>& ls)
{
	 this->contenedor = new Lista<T>(&ls);
	 this->CrearHeap(contenedor);
	 this->tipo = true;
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
	if (contenedor->getCantidad() > 0) {
		if (tipo == true) {
			this->SiftUp();
		}
		else {
			this->SiftUpMenor();
		}
	}
	return true;
}

template<class T>
bool ColaPrioridad<T>::eliminar()
{
	bool m = this->contenedor->eliminar();
	if (m == true) {
		int n = ((contenedor->getCantidad() - 1) / 2); //Revisar minuciosamente  1
		for (int i = n; i >= 0; i--) {
			if (this->tipo == true) {
				this->MaxHeapify(i);
			}
			else {
				this->MinHeapify(i);
			}
		}
		return true;
	}
	return false;

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
	if (izq == -1 && der == -1) {
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
		this->MaxHeapify(mayor);
	}

}

template<class T>
 void ColaPrioridad<T>::MinHeapify(int i)//debatir
{
	 int izq = this->getHijoIz(i);//index vectores...
	 int der = this->getHijoDer(i);//nodo 3 
	 int menor = 0;
	 if (izq == -1 && der == -1) {
		 return;
	 }

	 if (izq < i && izq != -1) {
		 menor = izq;
	 }
	 else {
		 menor = izq;
	 }
	 if (der < menor && der != -1) {
		 menor  = der;
	 }

	 if (menor != i) {
		 this->Intercambio(menor, i);
		 this->MinHeapify(menor);
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
	int n = ((contenedor->getCantidad()-1)/2); //Revisar minuciosamente
	for (int i = n; i >= 0; i--) {
		if (this->tipo == true) {
			this->MaxHeapify(i);
		}
		else {
			this->MinHeapify(i);
		}
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
void ColaPrioridad<T>::SiftUp()
{
	Nodo<T>* aux = contenedor->getBack();
	int contador = contenedor->getCantidad();
	int contador2 = contador - 1;
	while (aux && contador2>=0) {
		if (!compara(*aux->getObjetoPtr(),*aux->getAnterior()->getObjetoPtr())) {
			return;
		}
		else {
			this->Intercambio(contador, contador2);
		}
		aux = aux->getAnterior();
		contador--;
		contador2--;
	}

}
template<class T>
void ColaPrioridad<T>::SiftUpMenor()
{
	Nodo<T>* aux = contenedor->getBack();
	int contador = contenedor->getCantidad();
	int contador2 = contador - 1;
	while (aux && contador2 >= 0) {
		if (!compara(*aux->getObjetoPtr(), *aux->getAnterior()->getObjetoPtr())) {
			this->Intercambio(contador, contador2);
		}
		else{
			return;
		}
		aux = aux->getAnterior();
		contador--;
		contador2--;
	}

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
template<class T>
void ColaPrioridad<T>::mostrar() {
	this->contenedor->mostrar();
}



//Referencia
//https://www.softwaretestinghelp.com/priority-queue-in-cpp/