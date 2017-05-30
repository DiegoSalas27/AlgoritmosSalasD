#include <iostream>

using namespace std;

int Fibbonacci(int);
int main()
{
	int num = 2;
	cout << Fibbonacci(num);
	return 0;
}
Fibbonacci(int n)
{
	if(n == 0 || n == 1)
	return n;
	else
	return(Fibbonacci(n-1) + Fibbonacci(n-2));
}
