#pragma once
#include "Orden.h"

class Cliente {
private:
	long dni;
	string nombre;
	string apellido;
	Orden *oOrden;
public:
	Cliente(long dni = 0, string nombre = "", string apellido = "", long numero = 0, float total = 0, string producto = "", float cantidad = 0) :
		dni(dni), nombre(nombre), apellido(apellido) {
		oOrden = new Orden(numero, total, producto, cantidad);
	}
	long getDni() { return dni; }
	string getNombre() { return nombre; }
	string getApellido() { return apellido; }
	Orden *getoOrden() { return oOrden; }

	void setDni(long dni) { this->dni = dni; }
	void setNombre(string nombre) { this->nombre = nombre; }
	void setApellido(string apellido) { this->apellido = apellido; }

	string toString() {
		stringstream ss;
		ss << dni << "," << nombre << "," << apellido << endl;
		return ss.str();
	}
}; 