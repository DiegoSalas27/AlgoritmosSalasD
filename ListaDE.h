#pragma once
#include "Persona.h"

template <class T>

class ListaDE {
	struct Nodo {
		Persona *elemento;
		Nodo *prev;
		Nodo *next;
		Nodo(Persona *elemento = nullptr, Nodo *next = nullptr, Nodo *prev = nullptr) : elemento(elemento), next(next), prev(prev) {}
	};
public:
	Nodo *inicio;
	Nodo *ultimo;
	int n;
public:
	class Iterador {
		Nodo *aux;
	public:
		Iterador(Nodo *aux = nullptr) : aux(aux) {}
		void operator ++(int dummy) { aux = aux->next; }
		bool operator !=(Iterador it) { return aux != it.aux; }
		T operator *() { return aux->elemento; }
	};
public:
	ListaDE() :inicio(nullptr), ultimo(nullptr), n(n) {}
	~ListaDE() {
		while (inicio != nullptr) {
			Nodo *aux = inicio;
			inicio = inicio->next;
			delete aux;
		}
	}
	Iterador inicial() {
		return inicio;
	}
	Iterador finalito() {
		return ultimo;
	}
	int getTamannio() {
		return n;
	}
	Persona *getElemento(string nombre) {
		Nodo *aux = inicio;
		while (aux != nullptr)
		{
			if (aux->elemento->getNombre() == nombre)
				return aux->elemento;
			else {
				aux = aux->next;
			}
		}
		return nullptr;
	}
	bool insertarPersonaInicio(string nombre, string direccion, string telefono, string edad) {
		/*vector<string>nombres;
		vector<string>direcciones;
		vector<string>telefonos;
		vector<int>edades;
		vector<int>numCom;*/

		Persona *elemento;

		/*nombres.push_back(nombre);
		telefonos.push_back(telefono);
		direcciones.push_back(direccion);
		edades.push_back(edad);
		numCom.push_back(elemento->getNumCom());*/

		elemento = new Persona(nombre, direccion, telefono, edad);
		Nodo *nuevo = new Nodo(elemento, inicio, nullptr);
		if (nuevo == nullptr)return false;
		if (inicio == nullptr) { inicio = ultimo = nuevo; ++n; return true; }
		inicio->prev = nuevo;
		inicio = nuevo;
		++n;
		return true;
	}
	Persona *numeroGanador() {
		int *numeroGanadorsito;
		for (int i = 0; i < 6; i++) {
			numeroGanadorsito[i] = rndbtwn(0, 9);
		}
		Nodo *aux = inicio;
		while (aux != nullptr) {
			for (int i = 0; i < 6; i++)
			{
				if (aux->elemento->getNumCom()[i] == numeroGanadorsito[i] && aux->elemento->getNumCom()[i+1] == numeroGanadorsito[i+1]
					&& aux->elemento->getNumCom()[i + 2] == numeroGanadorsito[i + 2]) {
					return aux->elemento;
				}
				else {
					aux = aux->next;
				}
			}
			
		}
		return nullptr;
	}
};