#include "Orden.h"

class Cliente
{
private:
	Orden *ordenes2;
	long dni;
	string nombre;
	string apellido;
public:
	~Cliente() {}
	Cliente(long dni = 0, string nombre = "", string apellido = "", long numero = 0, float total = 0, string producto = "", float cantidad = 0) :
		dni(dni), nombre(nombre), apellido(apellido) { ordenes2 = new Orden(numero, total, producto, cantidad); }
	string toString()
	{
		stringstream ss;
		ss << dni << "," << nombre << "," << apellido;
		return ss.str();
	}
	long getDni() { return dni; }
	string getNombre() { return nombre; }
	string getApellido() { return apellido; }
	void setDni(long dni) { this->dni = dni; }
	void setNombre(string nom) { nombre = nom; }
	void setApellido(string ap) { apellido = ap; }
	Orden *getOrdenes2() { return ordenes2; }
};