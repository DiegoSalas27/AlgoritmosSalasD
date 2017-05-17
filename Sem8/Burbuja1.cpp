#include <iostream>

using namespace std;

void ordBurbujaModificado (int a[], int n)
{
	bool ordenado;
	for (int i=0; i < n-1; i++)
	{
		ordenado = true;
		for (int j=0; j < n - (i + 1); j++)
		{
			if (a[j] > a[j+1])
			{
				int aux = a[j];
				a[j] = a[j+1];
				a[j+1] = aux;
				ordenado = false;
			}
		}
		if (ordenado) break;
	}
}

int main()
{
	int Numeros [] = {2,3,5,4,1};
	ordBurbujaModificado(Numeros, 5);
	for(int i = 0; i < 5; i++)
	cout << Numeros[i] << " ";
	return 0;
}

//Mejor caso = O(n), Caso promedio = O(n^2), Peor caso = O(n^2)
