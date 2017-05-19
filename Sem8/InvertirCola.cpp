#include <iostream>
#include <queue>

//Programa para invertir una cola\
//FIFO
using namespace std;

int main(){
	queue<int>cola, cola2, cola3, cola4;
	cout << "\nCola ordenada\n";
	for(int  i = 0; i < 5; i++)
	{
		cola.push(i);		
		cout << cola.back() << " ";
	}
	while(!cola.empty()){
		while(cola.size() > 1){
			cola2.push(cola.front());
			cola.pop();
		}
		cola3.push(cola.front());
		cola.pop();
		cola = cola2;
		cola2 = cola4;
	}
	cout << "\nCola invertida\n";
	while(cola3.size() > 0)
	{
		cout << cola3.front() << " ";
		cola3.pop();
	}
		return 0;
}
