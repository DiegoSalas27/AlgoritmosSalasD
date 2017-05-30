#include <iostream>
//El numero no se almacena en ninguna variable, solo se muestra
using namespace std;

void invertirNumero(int n){
	cout << n % 10;
	 if(n > 10) invertirNumero(n/10);	
}

int main()
{
	invertirNumero(1234);
	return 0;
}
