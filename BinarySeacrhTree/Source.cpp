#include <iostream>
#include "bst.h"
#define MAX 10
using namespace std;

void printTree(int e){
	cout << " " << e;
}

int compareElements(int a, int b){
	return a - b;
}
int main(){
	BinaryTree<int>* btree = new BinaryTree<int>(printTree, compareElements);
	for (int i = 0; i < MAX; ++i){
		btree->insert(i);
		cout << btree->search(i) << " ";
	}
	cout << endl << " Numero de elementos: " << btree->size();
	cout << endl << " Altura: " << btree->height() << endl;
	system("pause");
	return 0;
}