#include <iostream>

using namespace std;

int factorial(int);
int main()
{
	int num;
	cout << "Ingrese un numero: ";
	cin >> num;
	cout << "\nEl factorial de " << num << " es: ";
	cout << factorial(num);
	return 0;
}
factorial(int n)
{
	if(n == 0 || n == 1)
	return 1;
	else
	return (n*factorial(n - 1));
}
