#include <iostream>

using namespace std;

class CVector{
	private:
		int *vec;
		int nele;
	public:
		void (*onProcesar)(int);	
	public:
		CVector(){nele = 10; vec = new int[nele];
		for(int i = 0; i < nele; i++)
		vec[i] = i;
		onProcesar = NULL;
		}
		~CVector(){}
		void mostrarGenerico()
		{
			for(int i = 0; i < nele; i++)
			onProcesar(vec[i]);
		}
};
void imprimirDato(int dato){
	cout << dato << " ";
}
int main()
{
	CVector *vec = new CVector();
	vec->onProcesar = imprimirDato;
	vec->mostrarGenerico();
	delete vec;
	return 0;
}
