#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

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
	string numCom;
public:
	Persona(string nombre = "vacio", string direccion ="vacio", string telefono ="vacio", string edad = "vacio", string numCom =""): nombre(nombre), direccion(direccion),
		telefono(telefono), edad(edad), numCom(numCom) {}
	~Persona() {}
	string getNombre() { return nombre; }
	string getDireccion() { return direccion; }
	string getTelefono() { return telefono; }
	string getEdad() { return edad; }
	string getNumCom() { return numCom; }
	string toCSV()
	{
		stringstream ss;
		ss << nombre << "," << direccion << "," << telefono << "," << edad << "," << numCom << endl;
		return ss.str();
	}
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