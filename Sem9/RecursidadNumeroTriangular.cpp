#include <iostream>
//codigo de recursividad para calcular numeros triangulares
using namespace std;

int numTriangular(int);
int main()
{
	int num;
	cout << "Ingrese numero:\n";
	cin >> num;
	cout << "El numero triangular correspondientes es: ";
	cout << numTriangular(num);
	return 0;
}
numTriangular(int n)
{
	if(n == 1)
	return 1;
	else
	return (n+ numTriangular(n - 1));
}
