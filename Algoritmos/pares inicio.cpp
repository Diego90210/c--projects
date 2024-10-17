/*
Desarrollar un programa que llene un arreglo unidimensional con N valores enteros y los ordene
de la siguiente forma números pares al inicio, números impares al final. No se puede utilizar un
vector auxiliar.
*/
#include <iostream>
using namespace std;
int main(){
	int n, i, j, aux;
	
	cout<<"Digite la cantidad de valores a ingresar: ";
	cin>>n;
	
	int vec[n];
	
	for(i=0; i<n; i++)
	{
		cout<<i+1<<". Ingrese un valor: ";
		cin>>vec[i];
	}
	
	for (i=0; i<(n-1); i++) //Recorremos el arreglo hasta la penultima posicion.
	{
		for(j=i+1; j<n; j++) //Recorremos el arreglo una posicion siguiente a i.
		{
			if(vec[j]%2==0) //Si el elemento a la derecha es mayor al de la izquierda.
			{
				//Intercambio para ordenar las unidades producidas.
				aux = vec[i];
				vec[i] = vec[j];
				vec[j] = aux;
			}
		}
	}
	
	cout<<"\n";
	cout<<"Ordenando...."<<endl;
	for(i=0; i<n; i++)
	{
		cout<<"["<<vec[i]<<"]"; 
	}
	//Imprimimos el reporte.
	
	
	
	
	
	
	return 0;
}
