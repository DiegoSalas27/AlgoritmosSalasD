#include <iostream>

using namespace std;

void imprimirTriangulo(int, int);
int main()
{
	int num = 5;
	imprimirTriangulo(num, num);
	return 0;
}
void imprimirTriangulo(int x, int y)
{
	if(x > 0)
	{
		cout << "*";
		imprimirTriangulo(--x, y);
	}
	else
	{
		if(y > 0)
		{
			x = y;
			cout << endl;
			imprimirTriangulo(--x, --y);
		}
	}
}
