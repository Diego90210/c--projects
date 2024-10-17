#include <iostream>
#include <math.h>
#include <windows.h>
#include <string.h>
using namespace std;

struct datos
{
	char apellidos[50];
	char nombres[50];
	int anio_nac;
	float peso;
	float estatura;
	char genero;
	float imc;
	int edad;
};

void cargar(struct datos personas[], int N);
int calcular_edad(int nac);
float calcular_imc(float peso, float alt);
void imprimir(struct datos personas[], int N);

int main()
{
	int N;
	cout<<"Cantidad de personas a calcular el IMC: ";
	cin>>N;
	datos personas[N];
		
	cargar(personas, N);
	imprimir(personas, N);
	
}

void cargar(struct datos personas[], int N)
{
	for(int x=0; x<N; x++)
	{
		system("cls");
		cout<<"Registrando datos persona No. "<<x+1 <<endl;
		cout<<"Apellidos: "; fflush(stdin); gets(personas[x].apellidos);
		cout<<"Nombres: "; fflush(stdin); gets(personas[x].nombres);
		cout<<"Año de nacimiento: ";cin>>personas[x].anio_nac;
		cout<<"Peso [Kg]: "; cin>>personas[x].peso;
		cout<<"Altura [Mt]"; cin>>personas[x].estatura;
		cout<<"Genero"; cin>>personas[x].genero;
		personas[x].imc= calcular_imc(personas[x].peso,personas[x].estatura );
		cout<<"IMC = "<<personas[x].imc;
		personas[x].edad= calcular_edad(personas[x].anio_nac);
		system("pause");
	}
	cout<<"***** REGISTRO DE DATOS EXITOSO ********"<<endl;
	Sleep(2000);
	
}

int calcular_edad(int nac)
{
	return 2023 - nac ;
}

float calcular_imc(float peso, float alt)
{
	return peso/pow(alt,2);
}

void imprimir(struct datos personas[], int N)
{
	system("cls");
	for(int x=0; x<N; x++)
	{
		cout<<"Nombre: " <<strcat(personas[x].nombres, personas[x].apellidos);
		cout<<"Año de nacimiento: "<<personas[x].anio_nac;
		cout<<"Peso [Kg]: "<<personas[x].peso;
		cout<<"Altura [Mt]"<<personas[x].estatura;
		cout<<"Genero" <<personas[x].genero;
		cout<<"IMC: "<<personas[x].imc;
		cout<<"Edad: "<<personas[x].edad;
		
	}	
	system("pause");
}
