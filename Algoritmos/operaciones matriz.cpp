/*Nos piden crear una matriz de N×N de números enteros que inicialmente está vacía, nos
piden hacer un menú con estas opciones:
? Rellenar TODA la matriz de números, se debe pedir al usuario.
? Suma de una fila que se pedirá al usuario (controlar que elija una correcta)
? Suma de una columna que se pedirá al usuario (controlar que elija una correcta)
? Sumar la diagonal principal (ver ejemplo)
? Sumar la diagonal inversa (ver ejemplo)
? La media de todos los valores de la matriz*/
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "SPANISH");
	int N, f,c;
	float suma=0, media;
	cout<<"Dimensión de la matriz cuadrada: ";
	cin>>N;
	int mat[N][N];
	int opc;
	do
	{
		cout<<"1. Rellenar TODA la matriz de números, se debe pedir al usuario."<<endl;
		cout<<"2.Suma de una fila que se pedirá al usuario (controlar que elija una correcta)"<<endl;
		cout<<"3. Suma de una columna que se pedirá al usuario (controlar que elija una correcta)"<<endl;
		cout<<"4. Sumar la diagonal principal (ver ejemplo)"<<endl;
		cout<<"5. Sumar la diagonal inversa (ver ejemplo)"<<endl;
		cout<<"6. La media de todos los valores de la matriz"<<endl;
		cout<<"7. Salida"<<endl;
		cout<<"Seleccione un proceso: ";
		cin>>opc;
		if(opc<1 || opc>7)
		{
			cout<<"Debe seleccionar una opción correcta"<<endl;
		}
		else
		{
			switch (opc)
			{
				case 1: // Rellenar TODA la matriz de números
					 //recorrer el arreglo bidimensional y guardar los numeros que se leen en cada posición 
					 for(f=0; f<N; f++)
					 {
					 	for(c=0; c<N; c++)
					 	{
					 		cout<<"Ingrese un número posición["<<f<<"]["<<c<<"]: ";
					 		cin>>mat[f][c];
						}
					 }
					 //mostrar la matriz 
					 system("cls");
					 for(f=0; f<N; f++)//recorre las filas 
					 {
					 	for(c=0; c<N; c++)//recorre las columnas 
					 	{
					 		cout<<"["<<mat[f][c]<<"]";	
						}
						cout<<endl;
					 }
					 
					 system("pause");
					 break;
				case 2: //Suma de una fila que se pedirá al usuario (controlar que elija una correcta)
					suma =0;
					do
					{
						system("cls");
						cout<<"Indique la fila a sumar: ";
						cin>>f;	
					}while(f<0 || f>=N);
					//sumar o acumular cada valor que se encuentra en cada posición de la columna que indique c
					for(c=0; c<N; c++)
					{
						suma = suma + mat[f][c];
					}
					cout<<"Sumatoria de la fila: "<<f <<" = "<<suma <<endl;
					system("pause");
					break;
					
				case 3: //Suma de una columna que se pedirá al usuario (controlar que elija una correcta)
				suma =0;
					do
					{
						system("cls");
						cout<<"Indique la columna a sumar: ";
						cin>>c;	
					}while(c<0 || c>=N);
					//sumar o acumular cada valor que se encuentra en cada posición de la columna que indique c
					for(f=0; f<N; f++)
					{
						suma = suma + mat[f][c];
					}
					cout<<"Sumatoria de la columna: "<<c <<" = "<<suma <<endl;
					system("pause");
					break;
				case 4://Suma de la diagonal principal.
				suma=0; 
					for (f=0; f<N; f++)
					{
						for(c=0; c<N; c++)
						{
							if (f==c)
							{
								suma+=mat[f][c];
							}
						}
					}
					system("cls");
				cout<<"La suma de la diagonal principal es: "<<suma<<endl;
				break;
				
				case 5: //Suma de la diagonal secundaria.
					suma=0;
					for (f=0; f<N; f++)
					{
						for(c=0; c<N; c++)
						{
							if ((f+c==(N-1)))
							{
								suma+=mat[f][c];
							}
						}
					}
					system("cls");
					cout<<"La suma de la diagonal secundaria es: "<<suma<<endl;
				break;
				case 6:
					suma=0;
					for (f=0; f<N; f++)
					{
						for(c=0; c<N; c++)
						{
							suma+=mat[f][c];
						}
					}
					cout<<"La suma de todos los valores de la matriz es: "<<suma<<endl;
					cout<<"La media de todos los valores de la matriz es: "<<(suma/(N*N))<<endl;
				break;
				case 7: exit(0);
			}
		}
		system("pause");
		system("cls");
	}while(opc!= 7 );
	
	
	
}

