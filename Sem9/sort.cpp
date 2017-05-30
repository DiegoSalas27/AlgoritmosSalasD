#include <time.h>
#include <fstream>

#include "sort.h"

int main() {
	ifstream dat("datos.in");
	if (!dat.is_open()) exit(-1);
	
	vector<int> v;
	int elem;
	while (dat >> elem) {
		v.push_back(elem);
	}
	cout << "Datos leidos correctamente... ahora ordenando!\n";
	
	clock_t ini = clock();
	auto comp = [](int a, int b) { return a - b; };
	ordInsercion<int>(v, comp);
	clock_t fin = clock();
	cout << (isSorted<int>(v, comp) ? "Arreglo ordenado ascendentemente\n" : "Arreglo ordenado descendentemente\n");
	cout << "Tiempo: " <<  ((fin - ini) / CLOCKS_PER_SEC) << endl;
	
	ofstream datOrdenado("datiños.txt");
	if(!datOrdenado.is_open()) exit(-1);
	int x = v.size();
	for(int i = 0; i < v.size(); i++, x--){
		datOrdenado << v[x] << endl;
	}
	
	return 0;
}
