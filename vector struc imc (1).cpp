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
	char estado[50];
	int edad;
};

void cargar(struct datos personas[], int N);
int calcular_edad(int nac);
float calcular_imc(float peso, float alt);
void imprimir(struct datos personas[], int N);
int menu();

int main()
{
	int N;
	setlocale(LC_ALL, "spanish");
	cout<<"Cantidad de personas a calcular el IMC: ";
	cin>>N;
	datos personas[N];
	
    int opc;
    do{
       opc = menu();
       switch(opc)
    	{
        case 1: cargar(personas, N);; break;
        case 2: imprimir(personas, N); break;
    	case 3: exit(0);
		}  
    }while(opc >=1 && opc <= 3);
}
		
	
int menu()
{
	int opc;
	do
	{
		system("cls");
		cout<<"Menu principal" <<endl;
		cout<<"1. Cargar Datos"<<endl;
		cout<<"2. Reporte IMC"<<endl;
		cout<<"3. Salir"<<endl; 
		cout<<"Seleccionar una opción ";
		cin>>opc;	
	}while(opc<1 || opc>3);
	return opc;
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
		cout<<"IMC = "<<personas[x].imc<<endl;
		if(personas[x].imc < 18.5)//Por debajo de 18.5 Por debajo del peso
         { strcpy(personas[x].estado, "BAJO PESO");}
         else if(personas[x].imc < 25)// 18.5 a 24.9 Saludable
         { strcpy(personas[x].estado, "SALUDABLE");}
         else if(personas[x].imc < 30)// 25.0 a 29.9 Con sobrepeso
         { strcpy(personas[x].estado, "SOBREPESO");}
         else if(personas[x].imc <=40)// 30.0 a 39.9 Obeso
          { strcpy(personas[x].estado, "OBESO");}
         else //Más de 40 Obesidad extrema o de alto riesgo
          { strcpy(personas[x].estado, "OBESIDAD EXTREMA");}   
		
		
		
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
		cout<<"Nombre: " <<strcat(personas[x].nombres, personas[x].apellidos) <<endl;
		cout<<"Año de nacimiento: "<<personas[x].anio_nac<<endl;
		cout<<"Peso [Kg]: "<<personas[x].peso<<endl;
		cout<<"Altura [Mt]"<<personas[x].estatura<<endl;
		cout<<"Genero" <<personas[x].genero<<endl;
		cout<<"IMC: "<<personas[x].imc<<endl;
		cout<<"Condición Física: "<<personas[x].estado <<endl;
		cout<<"Edad: "<<personas[x].edad<<endl;	
	}	
	system("pause");
}
