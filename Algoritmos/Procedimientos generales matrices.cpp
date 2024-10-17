#include <iostream>
using namespace std;
int main()
{
	int n, i, j, op;
	int suma=0;
	bool llenado=false;
	cout<<"Ingrese la dimension de la matriz cuadrada: ";
	cin>>n;
	
	system("cls");
	int matriz[n][n], sum=0, indice;
	
	do
	{
		cout<<"1.Rellenar TODA la matriz de numeros, se debe pedir al usuario "<<endl;
 		cout<<"2.Suma de una fila que se pedira al usuario "<<endl;
 		cout<<"3.Suma de una columna que se pedirá al usuario "<<endl; 
 		cout<<"4.Sumar la diagonal principal "<<endl; 
 		cout<<"5.Sumar la diagonal inversa "<<endl;
 		cout<<"6.La media de todos los valores de la matriz "<<endl;
 		cout<<"Opcion: ";
 		cin>>op;
 		
 		if(op<1 or op>6)
 		{
 			system("cls");
 			cout<<"Ingrese un valor dentro del rango [1-6]";
		}
		else
		{
			system("cls");
			switch(op)
			{
				case 1: 
				{
					for(i=0; i<n; i++)
					{
						for(j=0; j<n; j++)
						{
							cout<<"Ingrese un valor"<<" ["<<i<<"]"<<"["<<j<<"]: ";
							cin>>matriz[i][j];
						}
					}
					llenado=true;
				}
				break;
				
				case 2:
				{
					suma=0;
					system("cls");
					if (llenado==true)
					{
						do
						{
							cout<<"Ingrese la fila que desea sumar [recordar que la forma es n-1]: ";
							cin>>i;
						}while(indice<0 or indice>n);
						
						for(j=0; j<n; j++) 
						{ 
							suma+=matriz[i][j];
						}
						cout<<"La suma es: "<<suma;
					}
					else
					{
						cout<<"DEBE LLENAR LA MATRIZ PRIMERO! (Opcion 1)";
						return 0;
					}				
				}
				break;
			}
		}
	}while(op!=7);
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
