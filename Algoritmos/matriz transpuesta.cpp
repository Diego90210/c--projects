#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int N, M, f,c;
	long acumulador=0;
	setlocale(LC_ALL,"spanish" );
	do
	{
		cout<<"Ingrese la dimensión filas: ";
		cin>>N;	
	}while(N<=0);
	
	do
	{
		cout<<"Ingrese la dimensión columnas: ";
		cin>>M;	
	}while(M<=0);
	int matriz[N][M];
	
	cout<<"Cargar datos en la matriz"<<endl;
	for(f=0; f<N; f++)
	{
		for(c=0; c<M; c++)
		{
			cout<<"Ingrese un número para la posición ["<<f<<"]["<<c<<"]: ";
			cin>>matriz[f][c];
		}
	}
	system("cls");
	cout<<"Matriz Ingresada"<<endl;
	for(f=0; f<N; f++)
	{
		for(c=0; c<M; c++)
		{
			cout<<"["<<setw(5)<<matriz[f][c]<<"]";
		}
		cout<<endl;
	}
	cout<<"\nMatriz transpuesta"<<endl;
	for(f=0; f<M; f++)
	{
		for(c=0; c<N; c++)
		{
			cout<<"["<<setw(5)<<matriz[c][f]<<"]";
		}
		cout<<endl;
	}
	system("pause");
}
