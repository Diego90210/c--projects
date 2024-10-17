/*Ejercicio propuesto Aritmética de Punteros Unidimensionales
Aplicando aritmética de punteros realizar las siguientes operaciones en un arreglo unidimensional 
de dimensión N, implementar un menú con las siguientes opciones:
1. Cargar el arreglo
2. Imprimir el arreglo
3. Imprimir el arreglo de forma inversa
4. Imprimir los elementos ubicados en las posiciones pares
5. Ordenar de manera ascendente el arreglo 
6. Buscar un elemento del vector
7. Calcular estadísticas (Promedio, porcentajes de números ceros, pares e impares)*/
#include <iostream>
using namespace std;
int menu();
bool cargar(int v[], int N);
void imprimir(int v[], int N);
void inversa(int v[], int N);
void pares(int v[], int N);
void ordenar(int v[], int N);
void buscar(int v[], int N);
void calcular(int v[], int N);
int main()
{
	int N;
	bool sw = false;//variable bandera para validar si se cargó o no datos en el arreglo
	setlocale(LC_ALL,"spanish");
	cout<<"Dimensión del arreglo: ";
	cin>>N;
	int v[N];
	int *p;
	int op;
	do
	{
		op = menu();
		switch(op)
		{
			case 1: sw = cargar(v, N); break;//Cargar el arreglo
			case 2: if(sw) //si sw es igual a true indica que se cargaron datos en el arreglo y se puede ejecutar el proceso
						imprimir(v, N); //Imprimir el arreglo
					else
						cout<<"Debe cargar datos en el arreglo"<<endl;
					break;
			case 3: if(sw) 
					inversa(v, N); //Imprimir el arreglo de forma inversa
					else
						cout<<"Debe cargar datos en el arreglo"<<endl;
					break;
			case 4: if(sw) 
						pares(v, N); 
						else
						cout<<"Debe cargar datos en el arreglo"<<endl;
						break;//Imprimir los elementos ubicados en las posiciones pares
			case 5: if(sw) 
						ordenar(v, N); 
					else
						cout<<"Debe cargar datos en el arreglo"<<endl;
						break;//Ordenar de manera ascendente el arreglo 
			case 6: if(sw) 
						buscar(v, N); 
					else
						cout<<"Debe cargar datos en el arreglo"<<endl;	
						break;//Buscar un elemento del vector
			case 7: if(sw) 
						calcular(v, N); 
					else
						cout<<"Debe cargar datos en el arreglo"<<endl;	
						break;//Calcular estadísticas (Promedio, porcentajes de números ceros, pares e impares)
			case 8: exit(0);
		}
		system("pause");
	}while(op!= 8);
	
	
}

int menu()
{
	int op;
	
	do
	{
		system("cls");
		cout<<"menú operaciones en el arreglo" <<endl;
		cout<<"1. Cargar el arreglo" <<endl;
		cout<<"2. Imprimir el arreglo" <<endl;
		cout<<"3. Imprimir el arreglo de forma inversa" <<endl;
		cout<<"4. Imprimir los elementos ubicados en las posiciones pares" <<endl;
		cout<<"5. Ordenar de manera ascendente el arreglo " <<endl;
		cout<<"6. Buscar un elemento del vector" <<endl;
		cout<<"7. Calcular estadísticas (Promedio, porcentajes de números ceros, pares e impares)" <<endl;
		cout<<"8. Salir"<<endl;	
		cout<<"Seleccione una operación: ";
		cin>>op;
	}while(op<1 || op>8);
	
	return op; 

}

bool cargar(int v[], int N)
{
	int *p, *q;
	int x=0;
	p = v;//apunta a la dirección del primer elemento del vector 
	q = &v[N-1]; //apunta a la dirección del ultimo elemento del vector 
	do
	{
		system("cls");
		cout<<"Ingrese un valor para la posición["<<x<<"]: ";
		cin>>*p;
		p++; 
		x++;	
	}while(p<=q);
	return true; //retornamos true para indicar que el arreglo ya está cargado
}

void imprimir(int v[], int N)
{
	int *p, *q;
	system("cls");
	p = v;//apunta a la dirección del primer elemento del vector 
	q = &v[N-1]; //apunta a la dirección del ultimo elemento del vector 
	cout<<"VALORES ALMACENADOS EN EL ARREGLO"<<endl;
	do
	{
		cout<<"[" <<*p <<"]";
		p++; 	
	}while(p<=q);
	cout<<"\n\n";
	
}

void inversa(int v[], int N)
{
	int *p, *q;
	imprimir(v,N);
	cout<<"\nARREGLO EN FORMA INVERSA"<<endl;
	p = v;//apunta a la dirección del primer elemento del vector 
	q = &v[N-1]; //apunta a la dirección del ultimo elemento del vector 
	do
	{
		cout<<"[" <<*q <<"]";
		q--; 	
	}while(q>=p);
	cout<<endl;
}

void pares(int v[], int N)
{
	int *p, *q;
	int x=0;
	system("cls");
	cout<<"VALORES EN LAS POSICIONES PARES"<<endl;
	p = v;//apunta a la dirección del primer elemento del vector 
	q = &v[N-1]; //apunta a la dirección del ultimo elemento del vector 
	do
	{
		cout<<"Posición["<<x<<"]: " <<*p <<endl;
		p +=2; 	
		x++;
	}while(p<=q);
}

void ordenar(int v[], int N)
{
	
}
void buscar(int v[], int N)
{
	int nro;
	int sw=0; //variable bandera para controlar si encontró o no el valor buscado
	int *p;
	system("cls");
	cout<<"ingrese el valor a buscar en el arreglo: ";
	cin>>nro;
	p = v;
	for(int x=0;x<N;x++)
	{
		if(*p == nro)
		{
			cout<<"Se encontró "<<nro <<" en la posición ["<<x<<"]"<<endl;
			sw=1;
			break;
		}
		p++;
	}
	if(sw==0)
		cout<<"No se encontró el número "<<nro <<" entre los datos almacenados "<<endl;
}
void calcular(int v[], int N)
{
	float sumatoria=0, ceros=0, pares=0, impares=0;
	int *p;
	p = v;
	system("cls");
	for(int x=1;x<=N;x++)
	{
		sumatoria += *p; //acumulamos cada valor para calcular el Promedio
		if(*p == 0) //evaluamos cada valor para contarlo para calcular el porcentaje de números ceros, pares e impares
		{
			ceros++;
		}
		else if(*p%2 == 0)
			 {
			 	pares++;
			 }
			 else
			 {
			 	impares++;
			 }
	 	p++; 
	}
	cout<<"***** ESTADÍSTICAS *****"<<endl;
	cout<<"PROMEDIO: "<<sumatoria/N <<endl;
	cout<<"PORCENTAJE DE CEROS: "<<ceros*100/N <<"%\n";
	cout<<"PORCENTAJE DE NÚMEROS PARES: "<<pares*100/N <<"%\n";
	cout<<"PORCENTAJE DE NÚMEROS IMPARES: "<<impares*100/N <<"%\n";
}
