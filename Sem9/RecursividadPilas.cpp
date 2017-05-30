#include <iostream>

using namespace std;

template <class T> class Listita{
	struct Nodo{
		T e;
		Nodo *next;
		Nodo(T e = 0, Nodo *next = NULL):e(e), next(next){}
	};
	Nodo *ini;
	int n;
public:
	Listita() :ini(NULL), n(0){}
	void prepend(T e){
		ini = new Nodo(e, ini);
		++n;
	}
	void mostrarRec(){
		_mostrarRec(ini);
	}
	void mostrarRep(){
		T* pila = new T[n];
		int front = 0;
		Nodo *aux = ini;
		while(aux != NULL){
			pila[front++] = aux->e;
			aux = aux->next;
		}
		while (front != 0){
			cout << pila[--front] << " ";
		}
		delete[]pila;
	}
private:
	void _mostrarRec(Nodo *aux){
		if(aux != NULL){
			_mostrarRec(aux->next);
			cout << aux->e << " ";
		}
	}
};
int main()
{
	Listita<int>* l = new Listita<int>;
	for(int i = 0; i < 10; i++){
		l->prepend(i);
	}
	l->mostrarRep();
	cout << endl;
	l->mostrarRec();
	return 0;
}
