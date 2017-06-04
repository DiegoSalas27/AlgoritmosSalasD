#include <stdio.h>

void imprimirPares(int N)
{
	for(int i = 2; i <= N; i+=2){
		printf(" %d", i);
	}
}
void imprimirImpares(int N)
{
	for(int i = 1; i <= N; i+= 2){
		printf(" %d", i);
	}
}

int main()
{
	int N;
	printf("\nIngrese un numero: ");
	scanf("%d", &N);
	
	void (*ptrFuncion)(int);
	
	if(N % 2 == 0)
	ptrFuncion = imprimirPares;
	else
	ptrFuncion = imprimirImpares;
	ptrFuncion(N);
	
	return 0;
}
