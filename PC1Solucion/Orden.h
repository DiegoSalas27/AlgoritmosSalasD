#pragma once
#include "Item.h"

class Orden {
private:
	long numero;
	float total;
	Item *oItem;
public:
	Orden(long numero = 0, float total = 0, string producto = "", float cantidad = 0) :numero(numero), total(total) { oItem = new Item(producto, cantidad); }
	long getNumero() { return numero; }
	float getTotal() { return total; }

	void setNumero(long numero) { this->numero = numero; }
	void setTotal(float total) { this->total = total; }
	Item *getoItem() { return oItem; }
	string toString() {
		stringstream ss;
		ss << numero << "," << total << endl;
		return ss.str();
	}
};