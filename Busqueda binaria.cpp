#include <iostream>
using namespace std;

void pedir_datos ();
void ordenar (int *, int);
bool busqueda_binaria (int *, int, int);

int main(){
	
	pedir_datos ();
	
}

void pedir_datos (){
	int n, *p;
	cout<<"Cantidad de elementos del arreglo: ";
	cin>>n;
	int vec[n];
	p = vec;
	
	for (int i=0; i<n; i++){
		cout<<"Ingrese un valor "<<"["<<i<<"]: ";
		cin>>*(p+i);
	}
	
	ordenar (p, n);
}

void ordenar (int *p, int n){
	int aux, num_bus;
	bool buscar;
	for (int i=0; i<n; i++){
		for (int j=0; j<(n-1); j++){
			if (*(p+j)> *(p+j+1)){
				aux = *(p+j);
				*(p+j) = *(p+j+1);
				*(p+j+1) = aux;
			}
		}
	}
	
	cout<<"Ingrese el numero a buscar: ";
	cin>>num_bus;
	buscar=busqueda_binaria (p, n, num_bus);

	if (buscar){
		cout<<"El numero "<<num_bus<<" se encuentra en el arreglo"<<endl;
	}
	else{
		cout<<"El numero "<<num_bus<<" no se encuentra en el arreglo"<<endl;
	}

}

bool busqueda_binaria (int *p, int n, int num_bus){
	
	int limite_inferior=0, limite_superior=n-1;
	int medio, valor_medio;
	
	while (limite_inferior<=limite_superior){
		medio = (limite_superior+limite_inferior)/2;
		valor_medio = *(p+medio);
		
		if (num_bus == valor_medio){
			return true;
		}
		else{
			if (num_bus<valor_medio){
				limite_superior = medio-1;
			}
			else{
				if (num_bus>valor_medio){
					limite_inferior = medio+1;
				}
			}
		}
	}
	return false;
}
