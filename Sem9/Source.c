#include <stdio.h>

int main()
{
	float x, y, z;
	y = 10.0;
	z = x + y;
	/*valor inesperado: error de ejecucion*/
	printf("El valor de z es: %f\n", z);
	getchar();
	return 0;
}
