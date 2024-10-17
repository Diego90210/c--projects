#include <iostream>
using namespace std;

void SelectionSort (int array [], int x){
	//indice_menor corresponde a la posición del número 
	//más pequeño.
	int indice_menor, aux, i, j;
	for (i=0; i<x; i++){
		indice_menor=i;
		for (j=i+1; j<x; j++){
			if (array[j]<array[indice_menor]){
				indice_menor=j;
			}
		}
	}
	if (indice_menor!=i){
		aux = array[i];
		array[i] = array[indice_menor];
		array[indice_menor] = aux;
	}
}
