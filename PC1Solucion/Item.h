#pragma once
#include <sstream>
#include <string>

using namespace std;

class Item {
private:
	string producto;
	float cantidad;
public:
	Item(string producto = "", float cantidad = 0) :producto(producto), cantidad(cantidad) {}
	string getProducto() { return producto; }
	float getCantidad() { return cantidad; }

	void setProducto(string producto) { this->producto = producto; }
	void setCantidad(float cantidad) { this->cantidad = cantidad; }

	string toString() {
		stringstream ss;
		ss << producto << "," << cantidad << endl;
		return ss.str();
	}
};