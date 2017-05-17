#include <iostream>
//Algoritmo de busqueda binaria

using namespace std;

int busquedaBinaria(int arreglo[], int nElementos, int nBuscado)
{
	//Definimos dos variables que indiquen el rando de busqueda
	int limiteInferior = 0;
	int limiteSuperior = nElementos - 1;
	//Inicializamos la posicion en - 1(no encontrado)
	int posicion = -1;
	//Mientras no lo encuentre o haya evaluado todas las posibilidades
		int i = 1;
	while((posicion == -1) && (limiteSuperior >= limiteInferior))
	{
		int medio = (limiteInferior + limiteSuperior)/2;
		cout << "\nEl valor medio enla iteracion: " << i << " es: " << medio << endl;
		if(arreglo[medio] == nBuscado)
		{posicion = medio;}
		else if (arreglo[medio] < nBuscado)
		{limiteInferior = medio + 1;}//El valor esta en la mitad superior
		else
		{limiteSuperior = medio - 1;} //El valor esta en la mitad inferior
		i++;
	}
	return posicion;
}
int main()
{
	int arreglo[100];
	for(int i = 0; i < 100; i++)
	{
		arreglo[i] = i;
	}
	int posicion = busquedaBinaria(arreglo, 100, 43);
	cout << "\nEl numero buscado se encuentra en la posicion: " << posicion;
	return 0;
}
