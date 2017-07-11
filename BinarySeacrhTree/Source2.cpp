#include <iostream>
using namespace std;

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
	Nodo<T>*raiz;
	void(*procesar)(T);
	int(*comparar)(T, T);
	int len;

	void _insertarNodo(Nodo<T>*& nodo, T e){
		if (nodo == nullptr){
			nodo = new Nodo<T>();
			nodo->elemento = e;
			len++;
		}
		else if (comparar(e, nodo->elemento) < 0)
			_insertarNodo(nodo->izq, e);
		else
			_insertarNodo(nodo->der, e);
		int hi = _alturaArbol(nodo->izq);
		int hd = _alturaArbol(nodo->der);
		nodo->h = 1 + (hi > hd ? hi : hd);
	}
	int _alturaArbol(Nodo<T>* nodo){
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
		_enOrden(nodo->izq);
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
	Nodo<T>* _buscarMinimo(Nodo<T>* nodo){
		if (nodo == nullptr) return 0;
		while (nodo->izq != nullptr){ _buscarMinimo(nodo->izq); }
		return nodo;
	}
	Nodo<T>* _buscarMaximo(Nodo<T>* nodo){
		if (nodo == nullptr) return 0;
		while (nodo->der != nullptr) _buscarMinimo(nodo->der);
		return nodo;
	}
	Nodo<T>* _eliminarNodo(Nodo<T>*& nodo, T e){
		if (nodo == nullptr) return nullptr;
		if (comparar(e, nodo->elemento) < 0)
			_eliminarNodo(nodo->izq, e);
		else if (comparar(e, nodo->elemento) > 0)
			_eliminarNodo(nodo->der, e);
		else{
			//caso 1: no child
			if (nodo->izq == nullptr && nodo->der == nullptr)
			{
				delete nodo;
				nodo = nullptr;
				len--;
			}
			else if (nodo->izq == nullptr)
			{
				Nodo<T> *temp = nodo;
				nodo = nodo->der;
				delete temp;
				len--;
			}
			else if (nodo->der == nullptr)
			{
				Nodo<T> *temp = nodo;
				nodo = nodo->izq;
				delete temp;
				len--;
			}
		}
		return nodo;
	}
public:
	BinarySearchTree(void(*procesar)(T), int(*comparar)(T, T)){
		this->procesar = procesar;
		this->comparar = comparar;
		len = 0;
		raiz = nullptr;
	}
	void insertarNodo(T e){
		_insertarNodo(raiz, e);
	}
	int alturaArbol(){
		return _alturaArbol(raiz);
	}
	T buscarNodo(T e){
		return _buscarNodo(raiz, e);
	}
	void enOrden(){
		_enOrden(raiz);
	}
	void preOrden(){
		_preOrden(raiz);
	}
	void postOrden(){
		_postOrden(raiz);
	}
	int numElementos(){
		return len;
	}
	Nodo<T>* buscarMinimo(){
		return _buscarMinimo(raiz);
	}
	Nodo<T>* buscarMaximo(){
		return _buscarMaximo(raiz);
	}
	Nodo<T>* eliminarNodo(T e){
		return _eliminarNodo(raiz, e);
	}
};
void imprimirDatos(int e){
	cout << " " << e;
}
int compararElementos(int a, int b){
	return a - b;
}
int main()
{
	BinarySearchTree<int>* arbol = new BinarySearchTree<int>(imprimirDatos, compararElementos);
	for (int i = 5; i < 10; i++){
		arbol->insertarNodo(i);
		cout << arbol->buscarNodo(i) << " ";
	}
	for (int i = 0; i < 5; i++){
		arbol->insertarNodo(i);
		cout << arbol->buscarNodo(i) << " ";
	}
	arbol->eliminarNodo(8);
	arbol->eliminarNodo(9);
	arbol->eliminarNodo(6);
	cout << "\nPostOrden: "; arbol->postOrden();
	cout << "\nPreOrden: "; arbol->preOrden();
	cout << "\nEnOrden: "; arbol->enOrden();

	cout << "\n\nAltura del arbol: " << arbol->alturaArbol();
	cout << "\nNumero de elementos: " << arbol->numElementos() << endl;
	system("pause");
	return 0;
}
