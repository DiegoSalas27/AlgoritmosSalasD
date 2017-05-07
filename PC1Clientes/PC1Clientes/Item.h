#pragma once
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Item
{
private:
	string producto;
	float cantidad;
public:
	~Item() {}
	Item(string producto = "", float cantidad = 0) :producto(producto), cantidad(cantidad) {}

	string toString()
	{
		stringstream ss;
		ss << producto << "," << cantidad;
		return ss.str();
	}
	string getProducto() { return producto; }
	float getCantidad() { return cantidad; }
	void setProducto(string pro) { producto = pro; }
	void setCantidad(float can) { cantidad = can; }
};