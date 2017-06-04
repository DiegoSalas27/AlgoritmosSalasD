#include <iostream>

using namespace std;

int N = 10;
int *arreglo = new int[N];

void guardarArreglo()
{
	for(int i = 0; i < N; i++)
		arreglo[i]= i;
}

void imprimirPares()
{
	for(int i = 0; i < N; i++)
	{
		if(arreglo[i] % 2 == 0)
		cout << arreglo[i] << " ";
	} cout << endl;
}
void imprimirImpares()
{
	for(int i = 0; i < N; i++)
	{
		if(arreglo[i] % 2 != 0)
		cout << arreglo[i] << " ";
	} cout << endl;
}
void imprimirDatos(bool (*debeImprimir)(int))
{
	for(int i = 0; i < N; i++)
	if(debeImprimir(arreglo[i]))
	cout << arreglo[i] << " ";
	cout << endl;
}
bool esPar(int a)
{
	return a % 2 == 0;
}
bool esImpar(int a)
{
	return a % 2 != 0;
}
int main()
{
	guardarArreglo();
	cout << "Imprimiendo pares: \n";
	imprimirPares();
	cout << "\nImprimiendo impares: \n";
	imprimirImpares();
	cout << "\nImprimiendo los pares: \n";
	imprimirDatos(esPar);
	cout << "\nImprimiendo los impares: \n";\
	imprimirDatos(esImpar);
	return 0;
}
