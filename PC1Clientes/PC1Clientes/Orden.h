#include "Item.h"
#include <vector>
#include <Iterator>

class Orden
{
private:
	long numero;
	float total;
	Item *oItem;
public:
	~Orden() {}
	Orden(long numero = 0, float total = 0, string producto = "", float cantidad = 0) :numero(numero), total(total) { oItem = new Item(producto, cantidad); }
	string toString()
	{
		stringstream ss;
		ss << numero << "," << total;
		return ss.str();
	}
	long getNumero() { return numero; }
	float getTotal() { return total; }
	void setNumero(long num) { numero = num; }
	void setTotal(float tot = 0) { total = tot + 1; }
	Item *getOItem2() { return oItem; }
};