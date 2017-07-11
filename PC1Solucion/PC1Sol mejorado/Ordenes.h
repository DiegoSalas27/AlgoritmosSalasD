#include "Item.h"

class Orden{
	long numero;
	float total;
	vector<Item*>items;
public:
	Orden(long numero, float total) :numero(numero), total(total){}
	string toString(){
		stringstream ss;
		ss << numero << " " << total;
		return ss.str();
	}
	void agregarItem(Item *item){ items.push_back(item); }
	vector<Item*>getItems(){ return items; }
};