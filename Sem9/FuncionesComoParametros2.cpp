#include <iostream>
#include <fstream>

using namespace std;

int N = 10;
int *arreglo = new int[N];
ofstream archivo("arreglo.txt");

void guardarArreglo()
{
	for(int i = 0; i < N; i++)
		arreglo[i]= i;
}

void imprimirDatos(bool (*debeImprimir)(int), void (*hacerAlgo)(int)){
	for(int i = 0; i < N; i++)
	{
		if(debeImprimir(arreglo[i]))
			hacerAlgo(arreglo[i]);
	}
}
bool esPar(int a){
	return a % 2 == 0;
}
bool esImpar(int a){
	return a % 2 != 0;
}
void imprimirEnLinea(int a){
	cout << a << "\n";
}
void imprimirconEspacio(int a){
	cout << a << " ";
}
void guardarEnArchivo(int a){
	archivo << a << endl;
}
int main()
{
	guardarArreglo();
	cout << "Pares impresos en linea: \n";
	imprimirDatos(esPar, imprimirEnLinea);
	cout << "\nPares impresos con espacio: \n";
	imprimirDatos(esPar, imprimirconEspacio);
	cout << "\nPares guardados en archivos: \n";
	imprimirDatos(esPar, guardarEnArchivo);
	
	return 0;
}
