#include "Ordenes.h"

class Cliente{
	long dni;
	string nombre, apellido;
	vector<Orden*> ordenes;
public:
	Cliente(long dni, string nombre, string apellido) {
		this->dni = dni;
		this->nombre = nombre;
		this->apellido = apellido;
	}
	string toString(){
		stringstream ss;
		ss << apellido << " " << nombre << " " << dni;
		return ss.str();
	}
	void agregarOrden(Orden *ordenes){ this->ordenes.push_back(ordenes); }
	vector<Orden*> getOrdenes(){ return ordenes; }
	long getDni(){ return dni; }
	string getNombre(){ return nombre; }
	string getApellido(){ return apellido; }
};