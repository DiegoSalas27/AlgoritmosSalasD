#include <iostream>
using namespace std;
#define MAX 10

template <class T>

struct Nodo{
	T elemento;
	Nodo *izq;
	Nodo *der;
	int h;
public:
	Nodo(){
		izq = nullptr;
		der = nullptr;
		h = 0;
	}
};
template <class T>

class BinarySearchTree{
	Nodo<T>*root;
	void(*procesar)(T);
	int(*comparar)(T, T);
	int len;
	bool _insertar(Nodo<T>*& nodo, T e){
		if (nodo == nullptr){
			nodo = new Nodo<T>();
			nodo->elemento = e;
			len++;
		}
		else if (comparar(e, nodo->elemento) < 0)
			_insertar(nodo->izq, e);
		else
			_insertar(nodo->der, e);
		int hi = _alturaNodo(nodo->izq);
		int hd = _alturaNodo(nodo->der);
		nodo->h = 1 + (hi > hd ? hi : hd);
		return true;
	}
	int _alturaNodo(Nodo<T>* nodo){
		if (nodo == nullptr) return -1;
		return nodo->h;
	}
	T _buscarNodo(Nodo<T>* nodo, T e){
		if (nodo == nullptr) return 0;
		if (comparar(e, nodo->elemento) == 0)
			return nodo->elemento;
		else
			return _buscarNodo(comparar(e, nodo->elemento) > 0 ? nodo->der : nodo->izq, e);
	}
	void _enOrden(Nodo<T>* nodo){
		if (nodo == nullptr) return;
		_enOrden(nodo->left);
		procesar(nodo->elemento);
		_enOrden(nodo->der);
	}
	void _postOrden(Nodo<T>* nodo){
		if (nodo == nullptr) return;
		_postOrden(nodo->izq);
		_postOrden(nodo->der);
		procesar(nodo->elemento);
	}
	void _preOrden(Nodo<T>* nodo){
		if (nodo == nullptr) return;
		procesar(nodo->elemento);
		_preOrden(nodo->izq);
		_preOrden(nodo->der);
	}
public:
	BinarySearchTree(void(*procesar)(T), int(*comparar)(T, T)){
		this->procesar = procesar;
		this->comparar = comparar;
		len = 0;
		root = nullptr;
	}
	bool insertar(T e){
		return _insertar(root, e);
	}
	void enOrden(){
		_enOrden(root);
	}
	void postOrden(){
		_postOrden(root);
	}
	void preOrden(){
		_preOrden(root);
	}
	T buscarNodo(T e)
	{
		return _buscarNodo(root, e);
	}
	int alturaArbol()
	{
		return _alturaNodo(root);
	}
	int tammannio()
	{
		return len;
	}
};

void imprimir(int e){
	cout << " " << e;
}
int compararElemento(int a, int b){
	return a - b;
}
int main()
{
	BinarySearchTree<int>* arbol = new BinarySearchTree<int>(imprimir, compararElemento);
	for (int i = 10; i < 20; i++){
		arbol->insertar(i);
		cout << arbol->buscarNodo(i) << " ";
	}
	for (int i = 0; i < 9; i++){
		arbol->insertar(i);
		cout << arbol->buscarNodo(i) << " ";
	}
	cout << endl << "Numero de elementos: " << arbol->tammannio();
	cout << endl << "Altura del arbol: " << arbol->alturaArbol() << endl;
	system("pause");
	return 0;
}