#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int rndbtwn(int a, int b) {
	return rand() % (b - a + 1) + a;
}

class Persona {
private:
	string nombre;
	string direccion;
	string telefono;
	string edad;
	int *numCom;
	int *elem;
public:
	Persona(string nombre = "vacio", string direccion ="vacio", string telefono ="vacio", string edad = "vacio"): nombre(nombre), direccion(direccion),
		telefono(telefono),
		edad(edad) {
		elem = new int; *elem = 6; numCom = new int[*elem];
	}
	~Persona() {}
	string getNombre() { return nombre; }
	string getDireccion() { return direccion; }
	string getTelefono() { return telefono; }
	string getEdad() { return edad; }
	int *getElem() { return this->elem; }
	int *getNumCom() {
		for (int i = 0; i < 6; i++)
		{
			numCom[i] = rndbtwn(1, 9); 
		}
		return this->numCom;
	}
	void imprimir() { cout << nombre << " " << direccion << " " << telefono << " " << edad; }
};

//void cargarDatos(vector<string>&nombres)
//{
//	string dato;
//	ifstream archivo("nombres.txt");
//	while (getline(archivo, dato)) { nombres.push_back(dato); }
//	archivo.close();
//}
//void vaciarDatos(vector<string>nombres) {
//	nombres.clear();
//}