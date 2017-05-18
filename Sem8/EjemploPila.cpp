#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<int>pila;
	pila.push(20);
	if(!pila.empty()){
		printf("\nEl numero de la pila es %d", pila.top());
		pila.pop();
	}
	if(pila.empty())
	printf("\nLa pila esta vacia.");
	return 0;
}
