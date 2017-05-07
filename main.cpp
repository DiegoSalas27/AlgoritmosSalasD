#include "ListaDE.h"

int main()
{
	ListaDE<Persona*>lde;
	Persona *oPersona;
	int *numeroGanadorsito = new int[6];

	string nombre, direccion, telefono, edad;
	do {
		cout << "\nIngrese nombres: "; getline(cin, nombre);
		if (nombre == "") break;
		cout << "\nIngrese direccion: "; getline(cin, direccion);
		cout << "\nIngrese telefono: "; getline(cin, telefono);
		cout << "\nIngrese edad: "; getline(cin, edad);
		lde.insertarPersonaInicio(nombre, direccion, telefono, edad);
		oPersona = lde.getElemento("ana");
	} while (nombre != "");

	numeroGanadorsito = oPersona->getNumCom();

	ListaDE<Persona*>::Iterador it = lde.inicial();
	for (; it != lde.finalito(); it++)
	{
		cout << *it << endl;
	}


	Persona *personilla = lde.numeroGanador();
	cout << personilla->getNombre() << endl;

	delete personilla, oPersona;
	system("pause");
	return 0;
}