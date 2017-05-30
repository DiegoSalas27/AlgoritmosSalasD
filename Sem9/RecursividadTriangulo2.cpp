#include <iostream>
#include <string>

using namespace std;
//Imprimir Triangulo de 5 * 5
void imprimirTriangulo(int numCar, string entrada, string actual){
	if(actual.size() == numCar)
	cout << actual << endl;
	else{
		cout << actual << endl;
		actual += entrada;
		imprimirTriangulo(numCar, entrada, actual);
	}
}
int main()
{
	imprimirTriangulo(5, "*", "*");
	return 0;
}
