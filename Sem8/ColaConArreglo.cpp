#include <iostream>

using namespace std;

const int size = 10;

class Queue{
	private:
		int front; //indice final
		int back; //indice inicial (rear/trasero)
		char items[size]; //guarda el item en la cola
	public:
		Queue();
		~Queue();
		bool vacio();
		bool lleno();
		void enColar(char); //Agrega un item al final de la cola
		void desEncolar(); //borra un item de la cola
		char getFront();
		char getRear();	
		void mostrar();
};

Queue :: Queue(){
	front = -1;
	back = -1;
}
Queue :: ~Queue(){
    delete[]items;
}
bool Queue :: vacio(){
	return bool(back == front && front == -1);
}
bool Queue :: lleno(){
	return bool(back == size - 1);
}
void Queue::enColar(char elemento){
	if(lleno())
		cout << "\nLa cola esta llena, no es posible insertar!\n";
		else{
			if(front == -1)
			front = 0;
			cout << "\nDato ingresado: " << elemento;
			back++;
			items[back] = elemento;
		}
	}
void Queue::desEncolar(){
	if(vacio()){
		cout << "\nNo se puede eliminar item, la cola esta vacia!\n";
	}
	else{
		cout << "Elemento eliminado: " << items[front];
		front++;
		if(front == back && back == size - 1 || (front - 1 == back))
		front = back = - 1;
	}
}
char Queue::getFront(){
	return items[front];
}
char  Queue::getRear(){
	return items[back];
}
void Queue::mostrar(){
	if(back == front && front == -1)
	{
		cout << "\nLa cola esta vacia";
		return;
	}
	for(int i = front; i <= back; i++)
	cout << items[i] << " ";
}

int main ()
{
	 int choose;
	 char value;
      Queue queue;
      while(1)
        {
      cout<<"\n";
      cout<<"\n\t\t MENU\n\n";
      cout<<"1:ADD, 2:REMOVE, 3:SHOW, 4:EXIT";
      cout<<"\nChoose the menu: ";
      cin>>choose;

          switch(choose)
          {
               case 1: cout <<"enter the element: ";
  					   cin >> value;
  					   queue.enColar(value);
   					   break;
               case 2: queue.desEncolar(); break;
               case 3: queue.mostrar(); break;
                           case 4:
                exit(0);
                break;

            default:
                cout<<"\nInvalid Input. Try again! \n";
                break;
        }
    }
    return 0;
}
