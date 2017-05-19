#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue<int>cola;
	cola.push(20);
	cola.push(30);
	cola.push(40);
	if(!cola.empty()){
		printf("Extremos son %d y %d", cola.front(), cola.back());
		cola.pop();
	}
	return 0;
}
