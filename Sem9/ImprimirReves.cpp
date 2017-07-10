#include <iostream>

using namespace std;

void imprimirAlreves(int);
int main()
{
	imprimirAlreves(12345);
	return 0;
}
void imprimirAlreves(int num){
	if(num == 0)
	 return;
	 else{
	 cout << num % 10;
	 imprimirAlreves(num / 10);
	 }
}
