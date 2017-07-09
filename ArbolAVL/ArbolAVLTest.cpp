#include "avl.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

#define MAX 10
using namespace std;

void imprimir(int e){
	cout << " " << e;
}
int buscar(vector<int> v, int e){
	for (int i = 0; i < v.size(); ++i){
		if (v[i] == e){
			return v[i];
		}
	}
}
typedef function<void(int)> LambdaProc;
typedef function<int(int, int)> LambdaComp;
//typedef ArbolAVL<int, LambdaProc, LambdaComp> Arbolito;

int main(){
	srand(time(0));
	auto impr = [](int i){ cout << i << " "; };
	auto comparar = [](int a, int b){return a - b; };
	ArbolAVL<int, LambdaProc, LambdaComp> *arbol = new ArbolAVL<int, LambdaProc, LambdaComp>(impr, comparar);

	vector<int> arreglito(MAX);
	for (int i = 0; i < MAX; ++i){
		arbol->insertar(i + 1);
		arreglito[i] = i + 1;
	}
	arbol->eliminar(2);
	cout << "EnOrden: ";
	arbol->enOrden();
	cout << endl;
	cout << "EnPostOrden: ";
	arbol->enPostOrden();
	cout << endl;
	cout << "EnPreOrden: ";
	arbol->enPreOrden();
	//long start = clock();
	//cout << buscar(arreglito, MAX) << endl;
	//cout << "Tiempo busqueda lineal en arreglo: " << (clock() - start) << endl;
	//start = clock();
	//cout << arbol->buscar(MAX, comparar) << endl;
	//cout << "Tiempo busqueda binaria en AVLTree: " << (clock() - start) << endl;

	system("pause");
	return 0;
}
