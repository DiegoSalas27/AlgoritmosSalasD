#include <iostream>
using namespace std;

template <class T>

struct Nodo{
	T elemento;
	int h;
	Nodo *izq;
	Nodo *der;
public:
	Nodo(){
		h = 0;
		izq = nullptr;
		der = nullptr;
		int hi = (izq == nullptr ? -1 : izq->h);
		int hd = (der == nullptr ? -1 : der->h);
		this->h = 1 + (hi > hd ? hi : hd);
	}
};
template <class T>
class ArbolAVL{
	Nodo<T>* raiz;
	void(*procesar)(T);
	int(*comparar)(T, T);
	int len;

	int _alturaArbol(Nodo<T>* nodo){
		if (nodo == nullptr) return -1;
		return nodo->h;
	}
	void _fixAltura(Nodo<T>* nodo){
		nodo->h = 1 + (_alturaArbol(nodo->der) > _alturaArbol(nodo->izq) ? _alturaArbol(nodo->der) : _alturaArbol(nodo->izq));
	}
	void _enOrden(Nodo<T>* nodo){
		if (nodo == nullptr) return;
		_enOrden(nodo->izq);
		procesar(nodo->elemento);
		_enOrden(nodo->der);
	}
	void _rotarIzquierda(Nodo<T>*& nodo){
		Nodo<T>* y = nodo->der;
		nodo->der = y->izq;
		y->izq = nodo;
		nodo = y;
		_fixAltura(nodo->izq);
		_fixAltura(nodo);
	}
	void _rotarDerecha(Nodo<T>*& nodo){
		Nodo<T>* x = nodo->izq;
		nodo->izq = x->der;
		x->der = nodo;
		nodo = x;
		_fixAltura(nodo->der);
		_fixAltura(nodo);
	}
	void _balancearNodo(Nodo<T>*& nodo){
		if (_alturaArbol(nodo->izq) - _alturaArbol(nodo->der) > 1){
			if (_alturaArbol(nodo->izq->der)> _alturaArbol(nodo->izq->izq)){
				_rotarIzquierda(nodo->izq);
			}
			_rotarDerecha(nodo);
		}
		else if (_alturaArbol(nodo->der) - _alturaArbol(nodo->izq) > 1){
			if (_alturaArbol(nodo->der->izq) > _alturaArbol(nodo->der->der)){
				_rotarDerecha(nodo->der);
			}
			_rotarIzquierda(nodo);
		}
	}
	bool _insertarNodo(Nodo<T>*& nodo, T e){
		if (nodo == nullptr){
			nodo = new Nodo<T>();
			nodo->elemento = e;
			len++;
		}
		else if (comparar(e, nodo->elemento) < 0){
			_insertarNodo(nodo->izq, e);
		}
		else{
			_insertarNodo(nodo->der, e);
		}
		_balancearNodo(nodo);
		_fixAltura(nodo);
		return true;
	}
	T _buscarElemento(Nodo<T>* nodo, T e){
		if (nodo == nullptr) return 0;
		if (comparar(e, nodo->elemento) == 0)
			return nodo->elemento;
		else
			return _buscarElemento(comparar(e, nodo->elemento) > 0 ? nodo->der : nodo->izq, e);
	}
public:
	ArbolAVL(void(*procesar)(T), int(*comparar)(T, T)){
		this->procesar = procesar;
		this->comparar = comparar;
		len = 0;
		raiz = nullptr;
	}
	bool insertarNodo(T e){
		return _insertarNodo(raiz, e);
	}
	void enOrden(){
		_enOrden(raiz);
	}
	int numNodos(){
		return len;
	}
	int alturaArbol(){
		return _alturaArbol(raiz);
	}
	T buscarElemento(T e){
		return _buscarElemento(raiz, e);
	}
};
void imprimir(int e){
	cout << " " << e;
}
int compararElementos(int a, int b){
	return a - b;
}
int main()
{
	ArbolAVL<int>* arbol = new ArbolAVL<int>(imprimir, compararElementos);
	for (int i = 0; i < 5; i++){
		arbol->insertarNodo(i);
		cout << arbol->buscarElemento(i) << " ";
	}
	cout << "\nEnOrden: "; arbol->enOrden();
	cout << "\nNumero elementos: " << arbol->numNodos();
	cout << "\nAltura arbol: " << arbol->alturaArbol();

	system("pause");
	return 0;
}