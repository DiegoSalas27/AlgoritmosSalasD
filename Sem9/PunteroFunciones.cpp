/*#include <iostream>

//variables dentro de funciones estan en la pila de llamadas
//las variables globales estan en la memoria estatica

//la firma es cuando ambas funciones tienen misma cantidad de parametros del mismo tipo de dato y retornan el mismo tipo de dato

//ejemplo de firma

using namespace std;

float potencia(float m, int n){
	float p = 1;
	for(int i = 0; i < n; ++i){
		p *= m;
	}
	return p;
}

float mostrar(float x, int y){
	for(int i = 0; i < y; ++i){
		cout << x << " ";
	}
	return 0.f;
}
int  main()
{
	float (*ptrFun)(float, int);
	ptrFun = potencia;
	cout << "4^3 :" << ptrFun(4, 3) << endl;
	
	ptrFun = mostrar; //se pueden enviar funciones como parametros o funciones como atributos de una clase
	//la ventaja de tener una funcion como atributo es que puedes tener un comportamiento dinamico para una clase
	ptrFun = mostrar;
	ptrFun(2.3, 5);
	
	return 0;
}*/



#include <iostream>

using namespace std;

int y;

float potencia(float m, int n) {
    float p = 1;
    for (int i = 0; i < n; ++i) {
        p *= m;
    }
    return p;
}

float mostrar(float x, int y) {
    for (int i = 0; i < y; ++i) {
        cout << x << " ";
    }
    return 0.f;
}

int main() {
    int x;
    int *ptrInt;
    int *ptrInt2;
    int *ptrInt3;
    
    ptrInt = &x;
    ptrInt2 = &y;
    ptrInt3 = new int;
    
    float (*ptrFun)(float, int);
    
    ptrFun = potencia;
    cout << "4^3 = " << ptrFun(4, 3) << endl;
    
    ptrFun = mostrar;
    ptrFun(2.3, 5);
    
    return 0;
};
