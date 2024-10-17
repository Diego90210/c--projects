#include <iostream>
#include <fstream>
using namespace std;

struct v
{
	string prod;
	int vu;
	int cant;
	long total;
};

void crear_arch(struct v ventas[], int N)
{
	ofstream a("ventas.txt");
	if (a.fail())
	{
		cout<<"Error al crear el archivo ventas.txt" <<endl;
		system("pause");	
		exit(0);
	}
	for(int x=0; x<N; x++)
	{
		//escribiendo la información de cada elemento del vector de struct en el archivo ventas.txt
		a<<ventas[x].prod<<";"<<ventas[x].cant<<";"<<ventas[x].vu<<";"<<ventas[x].total<<endl;	
	}
	a.close();//cerramos el archivo una vez hemos terminado de escribir	
}

void leer_arch()
{
	v aux;
	ifstream a("ventas.txt");
	if (a.fail())
	{
		cout<<"Error al abrir el archivo ventas.txt para lectura" <<endl;
		system("pause");	
		exit(0);
	}
	//leemos el primer registro del archivo ventas.txt y lo copiamos a la variable aux 
	a>>aux.prod;
	while (!a.eof())
	{
		cout<<aux.prod <<endl;	
		a>>aux.prod; //skip	
	}
	a.close();
}

int main()
{
	int N, op;
	cout<<"Cantidad de ventas a registrar: ";
	cin>>N;
	v ventas[N];
	
	for(int x=0; x<N; x++)
	{
		cout<<"Registro de Ventas #"<<x+1 <<endl;
		cout<<"Nombre del articulo: ";
		fflush(stdin); getline(cin, ventas[x].prod);
		cout<<"Valor unitario: $"; cin>>ventas[x].vu;
		cout<<"Cantidad: "; cin>>ventas[x].cant;
		ventas[x].total = ventas[x].vu * ventas[x].cant;
		cout<<"Total: $"<<ventas[x].total <<endl;
	}
	do
	{
		cout<<"1. Crear Archivo de texto "<<endl;
		cout<<"2. Leer archivo de texto" <<endl;
		cout<<"3. Salir "<<endl;
		cout<<"Seleccione proceso: ";
		cin>>op;
		switch(op)
		{
			case 1: crear_arch(ventas, N); break;
			case 2: leer_arch(); break;
			case 3: exit(0);
		}
	}while(op != 3);
}

