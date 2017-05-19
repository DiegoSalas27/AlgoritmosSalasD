#include <iostream>
#include <stdlib.h>
using namespace std;

struct Nodo{
	int elemento;
	struct Nodo *next;	
} *front = NULL, *rear = NULL;

void enColar(int);
void desEncolar();
void mostrar();

int main()
{
	int eleccion, valor;
	system("cls");
	printf("\n :: Cola implementada usando lista enlazada ::\n");
	while(1){
		printf("\n***MENU***\n");
		printf("1.- encolar\n2.- desencolar\n3.- mostrar\n4.- salir\n");
		printf("\nElija opcion: ");
		scanf("%d", &eleccion);
		switch(eleccion){
			case 1: printf("\nElija valor: ");
		        	scanf("%d", &valor);
					enColar(valor);
					break;
			case 2: desEncolar(); break;
			case 3: mostrar(); break;
			case 4: exit(0);
			default: printf("\nIngrese un numero valido!\n");
		}
   }
   return 0;
}

void enColar(int valor){
	struct Nodo *nuevo;
	nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
	nuevo->elemento = valor;
	nuevo->next = NULL;
	if(front == NULL){
		front = rear = nuevo;
	}
	else{
		rear->next = nuevo;
		rear = nuevo;
	}
	printf("\nInsercion realizada!");
}
void desEncolar(){
	if(front == NULL)
	printf("\nLa cola esta vacia, no es posible eliminar!\n");
	else{
		struct Nodo *temp = front;
		printf("\nElemento eliminado: %d ", front->elemento);
		front = front->next;
		free(temp);
	}
}
void mostrar(){
	if(front == NULL)
	printf("\nLa cola esta vacia!\n");
	else{
		struct Nodo *temp = front;
		while(temp->next != NULL){
			printf("%d-->", temp->elemento);
			temp = temp->next;
		}
		 printf("%d-->NULL\n",temp->elemento);
	}
}
