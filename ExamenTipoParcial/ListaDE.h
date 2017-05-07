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
		void operator --(int dummy) { aux = aux->prev; }
		bool operator !=(Iterador it) { return aux != it.aux; }
		Persona operator *() { return aux->elemento ; }
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
		return ultimo->next;
	}
	int getTamannio() {
		return n;
	}
	Persona *siguiente(int pos) {
		if (pos < 0 || pos > n) return 0;
		if (n == 0) return 0;
		int c = 1;
		Nodo *aux = inicio;
		while (c++ <= pos)
		{
			aux = aux->next;
		}
		aux = aux->next;
		return aux->elemento;
	}
	Persona *anterior(int pos) {
		if (pos <= 0 || pos > n) return 0;
		if (n == 0) return 0;
		int c = 1;
		Nodo *aux = inicio;
		while (c++ < pos)
		{
			aux = aux->next;
		}
		return aux->elemento;

	}
	bool insertarPersonaInicio(Persona *persona) {

		Nodo *nuevo = new Nodo(persona, inicio, nullptr);
		if (nuevo == nullptr)return false;
		if (inicio == nullptr) { inicio = ultimo = nuevo; ++n; return true; }
		inicio->prev = nuevo;
		inicio = nuevo;
		++n;
		return true;
	}
	Persona *getElemento(int pos) {
		if (pos < 0 || pos > n) return 0;
		if (n == 0) return 0;
		int c = 1;
		Nodo *aux = inicio;
		while (c++ <= pos)
		{
			aux = aux->next;
		}
		return aux->elemento;
	}
	void registrarDatos()
	{
		Nodo *aux = inicio;
		ofstream archivo("personas.csv");
		if (!archivo.is_open()) return;
		int i = 1;
		while (aux != nullptr) {
			archivo << i << ".- " << aux->elemento->toCSV();
			aux = aux->next;
			i++;
		}
	}
};