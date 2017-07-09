#ifndef _ARBOLB_H__#
#define _ARBOLB_H__

template<class T>
struct Nodo{
	T elemento;
	Nodo *izq;
	Nodo *der;
	int h;
public:
	Nodo(){
		h = 0;
		izq = nullptr;
		der = nullptr;
	}
};

template<class T, class P, class C> // P para funcion procesar y C para funcion comparar
class ArbolAVL{
	Nodo<T>* raiz;
	P procesar; //templates de punteros a funciones o lambdas
	C comparar;
private:
	void _rotarIzq(Nodo<T>* x, Nodo<T>*& y, Nodo<T>*& p){ //p es el padre de x
		p = y;
		x->der = y->izq;
		p->izq = x;
	}
	void _rotarDer(Nodo<T>*& x, Nodo<T>* y, Nodo<T>*& p){ //p es padre de y
		p = x;
		y->izq = x->der;
		p->der = y;
	}
	bool _insertar(Nodo<T>*& nodo, T e){
		if (nodo == nullptr){
			nodo = new Nodo<T>(); // h = 0
			nodo->elemento = e;
		}
		else if (comparar(e, nodo->elemento) < 0){
			_insertar(nodo->izq, e);
		}
		else //if (comparar(e, nodo->elemento > 0)
			_insertar(nodo->der, e);
		int hi = _altura(nodo->izq);
		int hd = _altura(nodo->der);
		int d = hd - hi;
		if (d > 1) {//pesado a la derecha
			int hni = _altura(nodo->der->izq);
			int hnd = _altura(nodo->der->der);
			if (hni > hnd){ //zig zag derecha izquierda
				_rotarDer(nodo->der->izq, nodo->der, nodo->der);
			}
			_rotarIzq(nodo, nodo->der, nodo);
		}
		else if (d < -1){ //pesado a la izquierda
			int hni = _altura(nodo->izq->der);
			int hnd = _altura(nodo->izq->izq);
			if (hnd > hni){ //zig zag izq der
				_rotarIzq(nodo->izq, nodo->izq->der, nodo->izq);
			}
			_rotarDer(nodo->izq, nodo, nodo);
		}
		hi = _altura(nodo->izq);
		hd = _altura(nodo->der);
		nodo->h = 1 + (hi > hd ? hi : hd);
		return true;	
	}
	void _enOrden(Nodo<T>* nodo){
		if (nodo == nullptr) return;
		_enOrden(nodo->izq);
		procesar(nodo->elemento);
		_enOrden(nodo->der);
	}
	void _enPostOrden(Nodo<T>* nodo){
		if (nodo == nullptr) return;
		_enPostOrden(nodo->izq);
		_enPostOrden(nodo->der);
		procesar(nodo->elemento);
	}
	void _enPreOrden(Nodo<T>* nodo){
		if (nodo == nullptr) return;
		procesar(nodo->elemento);
		_enPreOrden(nodo->izq);
		_enPreOrden(nodo->der);
	}
	int _altura(Nodo<T>* nodo){
		if (nodo == nullptr) return -1;
		return nodo->h;
	}
	T _buscar(Nodo<T>* nodo, T e, C comparar){
		if (nodo == nullptr) return 0;
		if (comparar(e, nodo->elemento) == 0){
			return nodo->elemento;
		}
		else{
			return _buscar(comparar(e, nodo->elemento) > 0 ? nodo->der : nodo->izq, e, comparar);
		}
	}
	Nodo<T> _quitarMenor(Nodo<T>* nodo, Nodo<T>*& vinc){
		if (nodo == nullptr) return nullptr;
		if (nodo->izq == nullptr){
			vinc = nodo->der;
			nodo->der = nullptr;
			return nodo;
		}
		else{
			return _quitarMenor(nodo->izq, nodo->izq);
		}
	}
	Nodo<T> _quitarMayor(Nodo<T>* nodo, Nodo<T>*& vinc){
		if (nodo == nullptr) return  nullptr;
		if (nodo->der == nullptr){
			vinc = nodo->izq;
			nodo->izq = nullptr;
			return nodo;
		}
		else{
			return _quitarMayor(nodo->der, nodo->der);
		}
	}
	bool _eliminar(T e, Nodo<T>* nodo, Nodo<T>*& vinc){
		if (comparar(e, nodo->elemento) == 0){
			int hi = _altura(nodo->izq);
			int hd = _altura(nodo->der);
			if (hi == -1 && hd == -1){
				vinc = nullptr;
				delete nodo;
				return true;
			}
			else if (hi > hd){
				Nodo<T>* reemplazo = _quitarMayor(nodo->izq, nodo->izq);
				reemplazo->izq = nodo->izq;
				reemplazo->der = nodo->der;
				vinc = reemplazo;
				delete nodo;
				return true;
			}
			else{
				Nodo<T>* reemplazo = _quitarMenor(nodo->der, nodo->der);
				reemplazo->izq = nodo->izq;
				reemplazo->der = nodo->der;
				vinc = reemplazo;
				delete nodo;
				return true;
			}
		}
		else if (comparar(e, nodo->elemento) > 0 && nodo->der != nullptr){
			return _eliminar(e, nodo->der, nodo->der);
		}
		else if (comparar(e, nodo->elemento) < 0 && nodo->izq != nullptr){
			return _eliminar(e, nodo->izq, nodo->izq);
		}
		else
			return false;
		
	}
public:
	ArbolAVL(P funcion1, C funcion2){
		this->procesar = funcion1;
		this->comparar = funcion2;
		raiz = nullptr;
	}
	bool insertar(T e){
		return _insertar(raiz, e);
	}
	void enOrden(){
		_enOrden(raiz);
	}
	void enPreOrden(){
		_enPreOrden(raiz);
	}
	void enPostOrden(){
		_enPostOrden(raiz);
	}
	int altura(){
		_altura(raiz);
	}
	T buscar(T e, C comparar){
		return _buscar(raiz, e, comparar);
	}
	bool eliminar(T e){
		return _eliminar(e, raiz, raiz);
	}
};

#endif