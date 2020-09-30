#pragma once
#include "Lista.h"
template <class T>
class Heap {
	private:
		Lista<T>* contenedor;	
		bool MinMax;
	public:
		Heap(bool mm) {
			this->contenedor = new Lista<T>();
			this->MinMax = mm;
		}
		virtual ~Heap() {
			delete contenedor;
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
			int n = (contenedor->getCantidad() / 2 - 1); //Revisar minuciosamente
			for (int i = n; i >= 0; i--) {
				this->Heapify(i);
			}
		}

		template<class T>
		int Lista<T>::getPadre(int i)
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
		int Lista<T>::getHijoIz(int i)
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
		int Lista<T>::getHijoDer(int i)
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
			return -1;//lista... return -1// return (5)
		}

		template<class T>
		void Lista<T>::Intercambio(int mayor, int i)
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
		void setMM(bool b) {
			this->MinMax = b;
		}
		template<class T>
		Nodo<T>* getPrimero() {
			this->contenedor->getFront();
		}
		template<class T>
		int getCantidad() {
			this->contenedor->getCantidad();
		}


};