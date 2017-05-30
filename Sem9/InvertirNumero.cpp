#include <iostream>

using namespace std;

void invertirNumero(int);
int main()
{
	invertirNumero(14256);
	return 0;
}
void invertirNumero(int num){
	int digito = 0;
	while(num != 0)
	{
		digito = digito * 10 + num % 10;
		num = num / 10;
	}
	cout << digito;
}
