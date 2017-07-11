#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

class Item{
	string producto;
	float cantidad;
public:
	Item(string producto, float cantidad) : producto(producto), cantidad(cantidad){}
	string toString(){
		stringstream ss;
		ss << producto << " " << cantidad;
		return ss.str();
	}
	string getProducto(){ return producto; }
	float getCantdiad(){ return cantidad; }
	void setProducto(string pro){ producto = pro; }
	void setCantidad(float cant){ cantidad = cant; }
};