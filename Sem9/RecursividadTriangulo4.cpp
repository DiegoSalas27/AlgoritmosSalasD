#include <iostream>
#include <string>
/*      *
       **
      ***
     **** 
    ***** */
using namespace std;

void imprimirP(int i , int j, string car);
int main()
{
	imprimirP(5, 5, "*");
	return 0;
}
void imprimirP(int i , int j, string car){
	if(i > 1)
	{
		cout << " ";
		imprimirP(--i, j, car);
	}
	else if(i == 1){
		cout << car << endl;
		car += "*";
		i = j;
		imprimirP(--i, --j, car);
	}
}
