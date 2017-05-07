#include "ListaDE.h"

int main()
{
	ListaDE<Persona*>lde;
	Persona *oPersona;

	string nombre, direccion, telefono, edad, num;
	string numeroGanador = "123456";
	do {
		cout << "\nIngrese nombres: "; getline(cin, nombre);
		if (nombre == "") break;
		cout << "\nIngrese direccion: "; getline(cin, direccion);
		cout << "\nIngrese telefono: "; getline(cin, telefono);
		cout << "\nIngrese edad: "; getline(cin, edad);
		do {
			cout << "\nIngrese numero de Compra: "; getline(cin, num);
		} while (num.length() != 6);
		oPersona = new Persona(nombre, direccion, telefono, edad, num);
		lde.insertarPersonaInicio(oPersona);
	} while (nombre != "");

	ListaDE<Persona*>::Iterador it; 
	

	vector<Persona*>superGanadores;
	vector<Persona*>ganadores;
	vector<Persona*>ganadoresPorSuerte;
	vector<Persona*>ganadoresPorSuerte2;

	int i = 0;
	int cont = 0;
	bool gano = false;
	bool siguienteMayor = false;
	bool siguienteMenor = false;
	double monto = 20000;
	double montoSueper = 100000;

	cout << "\nJugadores\n";
	cout << "---------\n";

	for (it = lde.inicial(); it != lde.finalito(); it++, i++)
	{
		cout << lde.getElemento(i)->getNombre() << endl;
	}
	cout << endl;
	i = 0;
	for (it = lde.inicial(); it != lde.finalito(); it++, i++)
	{
		if (siguienteMayor)
		{
			ganadoresPorSuerte.push_back(lde.getElemento(i));
			siguienteMayor = false;
		}
		if (siguienteMenor)
		{
			ganadoresPorSuerte2.push_back(lde.getElemento(i));
			siguienteMenor = false;
		}
		if (lde.getElemento(i)->getNumCom() == numeroGanador)
		{
			superGanadores.push_back(lde.getElemento(i));
			if (i > 0)
			{
				ganadoresPorSuerte.push_back(lde.getElemento(i - 1));
				
			}
			gano = true;
			if (gano)
		    siguienteMayor = true;
		}
		if (!gano)
		{
			for (int j = 0; j < 6; j++)
			{
				if (lde.getElemento(i)->getNumCom()[j] == numeroGanador[j])
				{
					cont++;
				}
			}
			if (cont >= 4)
			{
				if (i > 0)
				{
					ganadoresPorSuerte2.push_back(lde.getElemento(i - 1));
					siguienteMenor = true;
				}
				ganadores.push_back(lde.getElemento(i));
				cont = 0;
			}
		}
		gano = false;
	}
	
	cout << "\nLos ganadores del premio gordo son:\n\n";
	for (int i = 0; i < superGanadores.size(); i++)
	{
		cout << superGanadores[i]->getNombre() << " recibe: s/." << montoSueper / superGanadores.size() << endl;
	}
	cout << "\nLos ganadores del premio menor son:\n\n";
	for (int i = 0; i < ganadores.size(); i++)
	{
		cout << ganadores[i]->getNombre() << " recibe: " << monto << endl;
	}
	cout << "\nLos que se la llevaron facil son:\n\n";
	for (int i = 0; i < ganadoresPorSuerte.size(); i++)
	{
		cout << ganadoresPorSuerte[i]->getNombre() << " recibe: s/." << (10 * montoSueper) / 100 << endl;
	}
	for (int i = 0; i < ganadoresPorSuerte2.size(); i++)
	{
		cout << ganadoresPorSuerte2[i]->getNombre() << " recibe: s/." << (10 * monto) / 100 << endl;
	}
	cout << endl;

	lde.registrarDatos();

	delete oPersona;
	system("pause");
	return 0;
}