#include <iostream>

using namespace std;

void columnas(int);
void filas(int);
int main()
{
	filas(5);
	return 0;
}
void columnas(int n)
{
	if(n == 0)
	return;
	else{
		cout << "*";
		columnas(--n);
	}
}
void filas(int n)
{
	if(n == 0)
	return;
	else{
		columnas(n);
		cout << endl;
		filas(--n);
	}
}
