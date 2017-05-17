#include <iostream>

using namespace std;

void ordInsercion (int a[], int n)
{
	int aux, k;
	for (int i=1; i<n; i++)
	{
		aux = a[i];
		k = i-1;
		while (k >= 0 && aux < a[k])
		{
			a[k+1] = a[k];
			k--;
		}
		a[k+1] = aux;
	}
}

int main()
{
	int arreglo[] = {1,4,2,3,5};
	ordInsercion(arreglo, 5);
	for(int i = 0; i < 5; i++)
	cout << arreglo[i] << " ";
	return 0;
}

//Mejor Caso = O(n), Caso Promedio = o(n+d), Peor Caso = O(n^2)
