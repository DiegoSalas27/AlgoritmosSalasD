#include <iostream>

using namespace std;\

void ordSeleccion(int a[], int n)
{
	int k, menor;
	for(int i = 0; i < n - 1; i++)
	{
		k = i;
		menor = a[i];
		for(int j = i + 1; j < n; j++)
		{
			if(a[j] < menor)
			{
				menor = a[j];
				k = j;
			}
		}
		a[k] = a[i];
		a[i] = menor;
	}
}
int main()
{
	int arreglo [] = {2, 4, 3, 1};
	int n = 4;
	ordSeleccion(arreglo, n);
	for(int i = 0; i < 4; i++)
	cout << arreglo[i] << " ";
	return 0;
}

//Mejor Caso = O(n^2), Caso Promedio = O(n^2), Peor Caso = O(n^2)
