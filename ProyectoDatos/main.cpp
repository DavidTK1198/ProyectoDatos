#include <iostream>
#include "Lista.h"
#include "ColaPrioridad.h"
#include "Persona.h"
using std::cout;
using std::endl;
//Referencias
//Data Structuresand
//Algorithms in C++
// pag 344-345
template<class T>
void mostrarContenido(ColaPrioridad<T>& p);
void HospitalEsperanza();
void ParqueInfantilMin();

int main() {
	cout << "-------------------------------------------------------------" << endl;
	cout << "----------------------PROBANDO LOS ENUNCIADOS----------------" << endl;

	HospitalEsperanza();
	system("pause");
	system("cls");
	cout << "---------------------" << endl;
	ParqueInfantilMin();
	system("pause");
	system("cls");
	cout << "Utilizando constructor copia de la cola de prioridad" << endl;
	ColaPrioridad<Persona>* colita = new ColaPrioridad<Persona>();
	Persona* per = new Persona("David", "123", 21);
	Persona* per2 = new Persona("Daniel", "1234", 65);
	Persona* per3 = new Persona("Marco", "555", 45);
	colita->insertar(per);
	colita->insertar(per2);
	colita->insertar(per3);
	ColaPrioridad<Persona>* prueba = new ColaPrioridad<Persona>(*colita);
	mostrarContenido(*colita);
	system("pause");
	system("cls");
	cout << "Mostrando la cola con tipo de dato String recibiendo una lista doblemente enlazada como parametro..." << endl;
	Lista<string>* heap = new Lista<string>();
	heap->insertar(new string("Diana"));
	heap->insertar(new string("Melissa"));
	heap->insertar(new string("David"));
	heap->insertar(new string("Daniel"));
	heap->insertar(new string("Solissss"));
	ColaPrioridad<string>* colaa = new ColaPrioridad<string>(*heap,true);
	mostrarContenido(*colaa);
	delete colita;
	delete prueba;
	delete heap;
	delete colaa;
	system("pause");
	return 0;
}

template<class T>
void mostrarContenido(ColaPrioridad<T>& p)
{
	T* elemento = nullptr;
	while (!p.isEmpty()) {
		elemento = p.remove();
		cout << *elemento << endl;
		delete elemento;
	}
	

}

void HospitalEsperanza()
{
	cout << "Bienvenido al Hospital Esperanza" << endl;
	Persona* per = new Persona("David", "123", 21);
	cout << per->getCed() << endl;
	cout << per->getNombre() << endl;
	cout << "-----------------------" << endl;
	Persona* per2 = new Persona("Daniel", "1234", 65);
	cout << per2->getCed() << endl;
	cout << per2->getNombre() << endl;
	cout << "-----------------------" << endl;
	Persona* per3 = new Persona("Marco", "555", 45);
	cout << per3->getCed() << endl;
	cout << per3->getNombre() << endl;
	cout << "-----------------------" << endl;
	Persona* per4 = new Persona("Martin", "999", 78);
	cout << per4->getCed() << endl;
	cout << per4->getNombre() << endl;
	cout << "-----------------------" << endl;

	cout << "Orden de atencion de pacientes segun su prioridad...." << endl;
	ColaPrioridad<Persona>* colita = new ColaPrioridad<Persona>();
	colita->insertar(per);
	colita->insertar(per2);
	colita->insertar(per3);
	colita->insertar(per4);

	cout << "Mostrando a los pacientes segun prioridad maxima" << endl;
	mostrarContenido(*colita);
	
}

void ParqueInfantilMin()
{
	cout << "Bienvenido al Parque Infantil La Carpio" << endl;
	Persona* per = new Persona("David", "123", 3);
	cout << per->getCed() << endl;
	cout << per->getNombre() << endl;
	cout << "-----------------------" << endl;
	Persona* per2 = new Persona("Daniel", "1234", 9);
	cout << per2->getCed() << endl;
	cout << per2->getNombre() << endl;
	cout << "-----------------------" << endl;
	Persona* per3 = new Persona("Marco", "555", 5);
	cout << per3->getCed() << endl;
	cout << per3->getNombre() << endl;
	cout << "-----------------------" << endl;
	Persona* per4 = new Persona("Martin", "999", 8);
	cout << per4->getCed() << endl;
	cout << per4->getNombre() << endl;
	cout << "-----------------------" << endl;

	cout << "Orden de acceso de los ninios segun su edad...." << endl;
	ColaPrioridad<Persona>* colita = new ColaPrioridad<Persona>(false);
	colita->insertar(per);
	colita->insertar(per2);
	colita->insertar(per3);
	colita->insertar(per4);

	cout << "Mostrando a los ninios segun prioridad minima" << endl;
	mostrarContenido(*colita);


}
