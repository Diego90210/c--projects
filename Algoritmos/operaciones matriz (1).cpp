#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int N, f,c;
	long acumulador=0;
	setlocale(LC_ALL,"spanish" );
	do
	{
		cout<<"Ingrese la dimensión de la matriz cuadrada: ";
		cin>>N;	
	}while(N<=0);
	
	int matriz[N][N];
	int opc;
	do
	{
		system("cls");
		cout<<"OPERACIONES CON MATRICES"<<endl;
		cout<<"1. Rellenar TODA la matriz "<<endl;
		cout<<"2. Suma de una fila"<<endl;
		cout<<"3. Suma de una columna"<<endl;
		cout<<"4. Sumar la diagonal principal"<<endl;
		cout<<"5. Sumar la diagonal inversa"<<endl;
		cout<<"6. La media de todos los valores de la matriz"<<endl;
		cout<<"7. Salir"<<endl;
		cout<<"Seleccione el proceso a realizar: ";
		cin>>opc;
		system("cls");
		switch(opc)
		{
			case 1:
				for(f=0; f<N; f++)
				{
					for(c=0; c<N; c++)
					{
						cout<<"Ingrese un número para la posición ["<<f<<"]["<<c<<"]: ";
						cin>>matriz[f][c];
					}
				}
				break;
			case 2:
				do
				{
					cout<<"Ingrese la fila a sumar: ";
					cin>>f;
				}while(f<0 || f>=N);
				
				for(c=0; c<N; c++)
				{
					acumulador += matriz[f][c];
				}
			
				cout<<"Sumatoria de los elementos de la fila "<<f<<" es: " <<acumulador<<endl;
				acumulador=0;
				break;
			case 3: 
				do
				{
					cout<<"Ingrese la columna a sumar: ";
					cin>>c;
				}while(c<0 || c>=N);
				
				for(f=0; f<N; f++)
				{
					acumulador += matriz[f][c];
				}
				cout<<"Sumatoria de los elementos de la fila "<<f<<" es: " <<acumulador<<endl;
				acumulador=0;
				break;
			case 4: 
				for(f=0; f<N; f++)
				{
					for(c=0; c<N; c++)
					{
						if(f == c)
						{
							acumulador += matriz[f][c];	
						}
					}
				}
				cout<<"sumatoria de la diagonal principal: " <<acumulador <<endl;
				acumulador =0;
				break;
			case 5: 
				for(f=0; f<N; f++)
				{
					for(c=0; c<N; c++)
					{
						if(f+c == N-1)
						{
							acumulador += matriz[f][c];	
						}
					}
				}
				cout<<"sumatoria de la diagonal secundaria: " <<acumulador <<endl;
				acumulador =0;
				break;
			case 6: 
				for(f=0; f<N; f++)
				{
					for(c=0; c<N; c++)
					{
						acumulador += matriz[f][c];	
					}
				}
				cout<<"Promedio: "<<acumulador/(f*c)<<endl;
				break;
			case 7: 
				exit(0);
		}
	
		for(f=0; f<N; f++)
		{
			for(c=0; c<N; c++)
			{
				cout<<"["<<setw(5)<<matriz[f][c]<<"]";
			}
			cout<<endl;
		}
		system("pause");	
	}while(opc != 7);
}
