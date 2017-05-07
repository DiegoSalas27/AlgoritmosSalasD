#include <fstream>
#include "Cliente.h"


class GestionarPedidos
{
	vector <Cliente*>clientes;

public:
	~GestionarPedidos() {
		for (int i = 0; i < clientes.size(); i++)
		{
			delete clientes[i];
		}
	}
	void agregarPedido(long dni = 0, string nom = "", string ap = "", long numero = 0, float total = 0, string producto = "", float cantidad = 0)
	{
		clientes.push_back(new Cliente(dni, nom, ap, numero, total, producto, cantidad));
	}
	int buscarDni(long dni)
	{
		for (int i = 0; i < clientes.size(); i++)
		{
			if (clientes[i]->getDni() == dni)
				return i;
		} return -1;
	}
	int buscarApellido(string apellido)
	{
		for (int i = 0; i < clientes.size(); i++)
		{
			if (clientes[i]->getApellido() == apellido)
				return i;
		} return -1;
	}
	bool eliminarCliente(long dni)
	{
		int pos = buscarDni(dni);
		if (pos != -1)
		{
			clientes.erase(clientes.begin() + pos);
			return true;
		}
		else
		{
			cout << "\nEl dni ingresado no existe.\n";
			return false;
		};
	}
	bool listarOrden(string apellido)
	{
		int pos = buscarApellido(apellido);
		if (pos != 1)
		{
			cout << clientes[pos]->getOrdenes2()->toString() << endl;
			return true;
		}
		else
		{
			cout << "\nEl apellido ingresado no existe.\n";
			return false;
		}
	}
	bool modificarItem(long dni, string prod, float cant)
	{
		int pos = buscarDni(dni);
		if (pos != 1)
		{
			clientes[pos]->getOrdenes2()->getOItem2()->setProducto(prod);
			clientes[pos]->getOrdenes2()->getOItem2()->setCantidad(cant);
			return true;
		}
		else
		{
			cout << "\nEl dni ingresado no existe.\n";
			return false;
		}
	}
	Item *buscarItem(string prod)
	{
		for (int i = 0; i < clientes.size(); i++)
		{
			if (clientes[i]->getOrdenes2()->getOItem2()->getProducto() == prod)
			{
				return (clientes[i]->getOrdenes2()->getOItem2());
			}
		}
	}
	void guardarDatos()
	{
		ofstream archivoC("clientes.txt");
		ofstream archivoO("ordenes.txt");
		ofstream archivoI("items.txt");
		if (!archivoC.is_open()) return;
		if (!archivoO.is_open()) return;
		if (!archivoI.is_open()) return;
		for (int i = 0; i < clientes.size(); i++)
		{
			archivoC << i+1 << ".- " << clientes[i]->toString() << endl;
			archivoO << i+1 << ".- " << clientes[i]->getOrdenes2()->toString() << endl;
			archivoI << i+1 << ".- " << clientes[i]->getOrdenes2()->getOItem2()->toString() << endl;
		}

		archivoC.close();
		archivoO.close();
		archivoI.close();
	}
	void leerDatos()
	{
		ifstream archivoC("clientes.csv");
		ifstream archivoO("ordenes.csv");
		ifstream archivoI("items.csv");
		if (!archivoC.is_open()) return;
		if (!archivoO.is_open()) return;
		if (!archivoI.is_open()) return;
		int cont = 0;
		long dni, num;
		float tot, cant;
		string nom, ap, prod;
		string linea, nume;
		while (cont <= clientes.size())
		{
			while (getline(archivoC, linea))
			{
				stringstream ss(linea);
				getline(ss, nume, ','); dni = atol(nume.c_str());
				getline(ss, nom, ',');
				getline(ss, ap, ',');	
				clientes.push_back(new Cliente(dni, nom, ap, 0, 0, 0, 0));
			}
			while (getline(archivoO, linea))
			{
				stringstream ss(linea);
				getline(ss, nume, ','); num = atol(nume.c_str());
				getline(ss, nume, ','); tot = stof(nume.c_str());
				clientes.push_back(new Cliente(0, 0, 0, num, tot, 0, 0));
			}
			while (getline(archivoI, linea))
			{
				cont -= 1;
				stringstream ss(linea);
				getline(ss, prod, ',');
				getline(ss, nume, ','); cant = stof(nume.c_str());
				clientes.push_back(new Cliente(0, 0, 0, 0, 0, prod, cant));
			}
			cont++;
		}
		archivoC.close();
		archivoO.close();
		archivoI.close();
	}
	void mostrarDatos()
	{
		for (int i = 0; i < clientes.size(); i++)
		{
			cout << "Cliente " << i << endl;
			cout << "*********" << endl;
			cout << clientes[i]->toString() << endl;
			cout << "Orden " << i << endl;
			cout << "*******" << endl;
			cout << clientes[i]->getOrdenes2()->toString() << endl;
			cout << "Item " << i << endl;
			cout << "******" << endl;
			cout << clientes[i]->getOrdenes2()->getOItem2()->toString() << endl << endl;
		}
	}
};

int main()
{
	GestionarPedidos *gp = new GestionarPedidos();
	Item *I;
	string nom, ap, prod;
	long dni, num;
	float cant, tot;
	bool verdad = true;
	int op;
	while (verdad)
	{
		cout << "Bienvenido a la tienda Jaimito" << endl;
		cout << "1.- Registrar datos del cliente." << endl;
		cout << "2.- Eliminar clientes por dni." << endl;
		cout << "3.- Listar orden por apellido del cliente." << endl;
		cout << "4.- Modificar datos de item." << endl;
		cout << "5.- Buscar item por nombre." << endl;
		cout << "6.- Mostrar datos." << endl;
		cout << "7.- Salir." << endl;
		cout << "OPCION: "; cin >> op;
		switch (op)
		{
		case 1:
			do
			{
				cout << "Ingrese nombre: "; cin >> nom;
				if (nom == "x") break;
				cout << "Ingrese apellido: "; cin >> ap;
				cout << "Ingrese dni: "; cin >> dni;
				cout << "Ingrese numero: "; cin >> num;
				cout << "Ingrese producto: "; cin >> prod;
				cout << "Ingrese cantidad: "; cin >> cant;
				gp->agregarPedido(dni, nom, ap, num, 1, prod, cant);
			} while (nom != "x");
			cout << "Gracias por usar nuestro servicio.\n";
			gp->guardarDatos(); break;
		case 2:
			cout << "Ingrese dni: "; cin >> dni;
			gp->eliminarCliente(dni);
			break;
		case 3:
			cout << "Ingrese apellido: "; cin >> ap;
			gp->listarOrden(ap); break;
		case 4:
			cout << "Ingrese dni: "; cin >> dni;
			cout << "Ingrese producto: "; cin >> prod;
			cout << "Ingrese cantidad: "; cin >> cant;
			gp->modificarItem(dni, prod, cant); break;
		case 5:
			cout << "Ingrese nombre de producto: "; cin >> prod;
			I = gp->buscarItem(prod);
			cout << I->getCantidad()<< endl; break;
		case 6:
			gp->mostrarDatos(); break;
		case 7:
			cout << "Gracias por tu preferencia.\n";
			verdad = false;
			return 0;
			break;
		}
	}
	delete gp;
	system("pause");
	return 0;
}