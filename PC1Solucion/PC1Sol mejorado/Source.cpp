#include "cliente.h"

class gestorCliente{
	Item *items;
	Orden *ordenes;
	vector<Cliente*>clientes;
public:
	~gestorCliente(){
		for (int i = 0; i < clientes.size(); i++){
			delete clientes[i];
		}
	}
	// j e i empiezan en 0
	void registrarDatos(long dni, string nombre, string apellido, long numero, float total, string producto, float cantidad, int i, int j){
		clientes.push_back(new Cliente(dni, nombre, apellido));
		ordenes = new Orden(numero, total);
		items = new Item(producto, cantidad);
		clientes[i]->agregarOrden(ordenes);
		clientes[i]->getOrdenes()[j]->agregarItem(items);
	}
	bool eliminar(long dni){
		for (int i = 0; i < clientes.size(); i++){
			if (clientes[i]->getDni() == dni)
			{
				clientes.erase(clientes.begin() + i);
				return true;
			}
			else
			{
				cout << "Cliente no existe";
				return false;
			}
		}
	}
	void ListarOrden(string apellido){
		for (int i = 0; i < clientes.size(); i++){
			if (clientes[i]->getApellido() == apellido)
			{
				for (int j = 0; j < clientes[i]->getOrdenes().size(); j++)
				{
					cout << clientes[i]->getOrdenes()[j]->toString() << endl;
				}
			}
		}
	}
	//insertar apellido, numero de orden y de item
	bool modificarDatos(string apellido, int j, int y, string pro, float cant){
		for (int i = 0; i < clientes.size(); i++){
			if (clientes[i]->getApellido() == apellido)
			{
				clientes[i]->getOrdenes()[j]->getItems()[y]->setProducto(pro);
				clientes[i]->getOrdenes()[j]->getItems()[y]->setCantidad(cant);
				return true;
			}
			else
			{
				cout << "Item no existe";
				return false;
			}
		}
		cout << "Cliente no existe";
		return false;
	}
	Orden *buscar(string pro){
		for (int i = 0; i < clientes.size(); i++)
		{
			for (int j = 0; j < clientes[i]->getOrdenes().size(); j++)
			{
				for (int k = 0; k < clientes[i]->getOrdenes()[j]->getItems().size(); k++)
				{
					if (clientes[i]->getOrdenes()[j]->getItems()[k]->getProducto() == pro)
					{
						return clientes[i]->getOrdenes()[j];
					}
				}
			}
		}
		return nullptr;
	}
	void guardarDatos(){
		ofstream archivoC("clientes.txt");
		ofstream archivoO("ordenes.txt");
		ofstream archivoI("items.txt");
		if (!archivoC.is_open()) return;
		if (!archivoO.is_open()) return;
		if (!archivoI.is_open()) return;
		for (int i = 0; i < clientes.size(); i++){
			archivoC << i+1 << ".- " << clientes[i]->toString() << endl;
			for (int j = 0; j < clientes[i]->getOrdenes().size(); j++){
				archivoO << "Cliente: " << i+1 << ".- " << clientes[i]->getOrdenes()[j]->toString() << endl;
				for (int k = 0; k < clientes[i]->getOrdenes()[j]->getItems().size(); k++){
					archivoI << "Orden: " << j+1 << ".- " << clientes[i]->getOrdenes()[j]->getItems()[k]->toString() << endl;
				}
			}
		}
		archivoO.close();
		archivoI.close();
		archivoC.close();
	}
	void leerDatos()
	{
		ifstream archivoC("clientes.txt");
		ifstream archivoO("ordenes.txt");
		ifstream archivoI("items.txt");
		if (!archivoC.is_open()) return;
		if (!archivoO.is_open()) return;
		if (!archivoI.is_open()) return;
		long dni;
		string nombre, apellido;
		long numero;
		float total;
		string producto;
		float cantidad;
		string linea, num;
		while (getline(archivoC, linea)){
			stringstream ss(linea);
			getline(ss, num, ','); dni = atol(num.c_str());
			getline(ss, nombre, ',');
			getline(ss, apellido);
			clientes.push_back(new Cliente(dni, nombre, apellido));
		}
		while (getline(archivoO, linea)){
			stringstream ss(linea);
			getline(ss, num, ','); numero = atol(num.c_str());
			getline(ss, num); total = atof(num.c_str());
			for (int i = 0; i < clientes.size(); i++){
				clientes[i]->getOrdenes().push_back(new Orden(numero, total));
			}
		}
		while (getline(archivoI, linea)){
			stringstream ss(linea);
			getline(ss, producto, ',');
			getline(ss, num); cantidad = atof(num.c_str());
			for (int i = 0; i < clientes.size(); i++){
				for (int j = 0; j < clientes[i]->getOrdenes().size(); j++)
				{
					clientes[i]->getOrdenes()[j]->getItems().push_back(new Item(producto, cantidad));
				}
			}
		}
		archivoO.close();
		archivoI.close();
		archivoC.close();
	}
};

int main()
{
	gestorCliente *gc = new gestorCliente();

	long dni;
	string nombre, apellido;
	long numero;
	float total;
	string producto;
	float cantidad;
	int j, i;
	do
	{
		cout << "Ingrese nombre: "; getline(cin, nombre);
		if (nombre == "") break;
		cout << "\nIngrese apellido: "; getline(cin, apellido);
		cout << "\nIngrese dni: "; cin >> dni;
		cout << "\nIngrese numero de orden: "; cin >> numero;
		cout << "\nIngrese total de ordenes: "; cin >> total;
		cout << "\nIngrese nombre de producto: "; cin >> producto;
		cout << "\nIngrese cantidad de items: "; cin >> cantidad;
		cout << "\nIngrese numero de cliente: "; cin >> i;
		cout << "\nIngrese numero de orden: "; cin >> j;
		cin.ignore();
		gc->registrarDatos(dni, nombre, apellido, numero, total, producto, cantidad, i, j);
	} while (nombre != "");
	cout << "\narigato";
	gc->guardarDatos();
	system("pause");
	return 0;
}