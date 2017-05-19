#include <iostream>
#include <stack>
#include <stdlib.h>
#include <time.h>

//LIFO

using namespace std;

int rndbtwn(int a, int b){
	return rand() % (b - a + 1) + a;
}
int main()
{
	stack<int>pila, pila2, pila3;
	cout << "\nPila original\n";
	for(int i = 0; i < 20; i++){
		pila.push(i);
		cout << pila.top() << " ";
	}
	while(!pila.empty()){
		if(rndbtwn(0, 20) > 10){
			pila2.push(pila.top());
		}
		else{
			pila3.push(pila.top());
		}
		pila.pop();
	}
	while(!pila2.empty()){
		pila.push(pila2.top());
		pila2.pop();
	}
	while(!pila3.empty()){
		pila.push(pila3.top());
		pila3.pop();
	}
	cout << "\nPila desordenada\n";
	while(!pila.empty()){
		cout << pila.top() << " ";
		pila.pop();
	}
	return 0;
}
