#include <iostream>
#include <fstream>
#include <vector>
#include "Cliente.h"

class gestorCliente {
private:
	vector<Cliente*>clientes;
public:
	~gestorCliente() {
	for (int i = 0; i < clientes.size(); i++) {
		delete clientes[i];
	}
}
	void registrarCliente(long dni, string nombre, string apellido, long numero, float total, string producto, float cantidad)
	{
		clientes.push_back(new Cliente(dni, nombre, apellido, numero, total, producto, cantidad));
	}
	bool eliminarCliente(long dni) {
		for (int i = 0; i < clientes.size(); i++) {
			if (clientes[i]->getDni() == dni)
			{
				clientes.erase(clientes.begin() + i);
				return true;
			}
			else
				cout << "\nEl dni ingresado no existe.\n";
				return false;
		}
	}
	bool listarOrden(string apellido) {
		for (int i = 0; i < clientes.size(); i++) {
			if (clientes[i]->getApellido() == apellido) {
				cout << clientes[i]->getoOrden()->getNumero() << endl;
				cout << clientes[i]->getoOrden()->getTotal() << endl;
				return true;
			}
			else
				cout << "\nEl apellido ingresado no existe.\n";
			return false;
		}
	}
	bool modificarDato(string producto, string cambio, float cantidad) {
		for (int i = 0; i < clientes.size(); i++) {
			if (clientes[i]->getoOrden()->getoItem()->getProducto() == producto) {
				clientes[i]->getoOrden()->getoItem()->setProducto(cambio);
				clientes[i]->getoOrden()->getoItem()->setCantidad(cantidad);
				return true;
			}
			else
				cout << "\nEl dni ingresado no existe.\n";
		}
		return false;
	}
	Orden *orden(string producto) {
		for (int i = 0; i < clientes.size(); i++) {
			if (clientes[i]->getoOrden()->getoItem()->getProducto() == producto)
			{
				return clientes[i]->getoOrden();
			}
		}
		return nullptr;
	}
	void guardarDatos() {
		ofstream archivoC("clientes.csv");
		ofstream archivoI("items.csv");
		ofstream archivoO("ordenes.csv");
		if (!archivoC.is_open()) return;
		if (!archivoI.is_open()) return;
		if (!archivoO.is_open()) return;
		for (int i = 0; i < clientes.size(); i++) {
			archivoC << i << ".- " << clientes[i]->toString();
			archivoO << i << ".- " << clientes[i]->getoOrden()->toString();
			archivoI << i << ".- " << clientes[i]->getoOrden()->getoItem()->toString();
		}
		archivoC.close();
		archivoI.close();
		archivoO.close();
	}
	void leerDatos() {
		ifstream archivoC("clientes.csv");
		ifstream archivoO("ordenes.csv");
		ifstream archivoI("items.csv");

		if (!archivoC.is_open()) return;
		if (!archivoI.is_open()) return;
		if (!archivoO.is_open()) return;

		string producto;
		float cantidad;
		long numero;
		float total;
		long dni;
		string nombre;
		string apellido;
		string linea, num;
		while (getline(archivoC, linea)) {
			stringstream ss(linea);
			getline(ss, num, ','); dni = atol(num.c_str());
			getline(ss, nombre, ',');
			getline(ss, apellido);
		while (getline(archivoI, linea)) {
			stringstream ss(linea);
			getline(ss, producto, ',');
			getline(ss, num); cantidad = stof(num.c_str());
		while (getline(archivoO, linea)) {
			stringstream ss(linea);
			getline(ss, num, ','); numero = atol(num.c_str());
			getline(ss, num); total = stof(num.c_str());
			clientes.push_back(new Cliente(dni, nombre, apellido, numero, total, producto, cantidad));
				}
	     	}
		}
		
		archivoC.close();
		archivoI.close();
		archivoO.close();
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
			cout << clientes[i]->getoOrden()->toString() << endl;
			cout << "Item " << i << endl;
			cout << "******" << endl;
			cout << clientes[i]->getoOrden()->getoItem()->toString() << endl << endl;
		}
	}
};

int main()
{
	gestorCliente *gc = new gestorCliente();
	Orden *oOrden;

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
		cout << "8.- Obtener informacion guardada." << endl;
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
				gc->registrarCliente(dni, nom, ap, num, 1, prod, cant);
			} while (nom != "x");
			cout << "Gracias por usar nuestro servicio.\n";
			gc->guardarDatos(); break;
		case 2:
			cout << "Ingrese dni: "; cin >> dni;
			gc->eliminarCliente(dni);
			break;
		case 3:
			cout << "Ingrese apellido: "; cin >> ap;
			gc->listarOrden(ap);
		case 4:
			cout << "Ingrese producto: "; cin >> prod;
			cout << "Ingrese nuevo nombre: "; cin >> nom;
			cout << "Ingrese cantidad: "; cin >> cant;
			gc->modificarDato(nom, prod, cant);
		case 5:
			cout << "Ingrese nombre de producto: "; cin >> prod;
			oOrden = gc->orden(prod);
			cout << oOrden->getNumero() << endl << oOrden->getTotal() << endl; break;
		case 6:
			gc->mostrarDatos(); break;
		case 7:
			cout << "Gracias por tu preferencia.\n";
			verdad = false;
			return 0;
			break;
		case 8:
			gc->leerDatos();
			gc->mostrarDatos();
			break;
		}
	}
	delete gc;
	system("pause");
	return 0;
	system("pause");
	return 0;
}
