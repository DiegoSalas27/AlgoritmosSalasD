#include <iostream>

using namespace std;

template <class T> 
class Listita{
	struct Nodo{
		T e;
		Nodo *next;
		Nodo(T e = 0, Nodo *next = NULL):e(e), next(next){}
	};
	Nodo *ini;
public:
	Listita() :ini(NULL) {}
	void prepend(T e){
		ini = new Nodo(e, ini);
	}
	void mostrarRec(){
		_mostrarRec(ini);
	}
private:
	void _mostrarRec(Nodo *aux){
		if(aux != NULL){
			cout << aux->e << " ";
			_mostrarRec(aux->next);
		}
	}
};
int main()
{
	Listita<int>* l = new Listita<int>;
	for(int i = 0; i < 10; i++){
		l->prepend(i);
	}
	l->mostrarRec();
	return 0;
}
