//Actividad individual, Juan Diego Bello Santiago 0221910021, Ing. Sistemas

#include<iostream>
#include<fstream>
#include<stdio.h>
#include<windows.h>
#include "Utilities.h"

using namespace std;


typedef struct 
{
	long long id;
	char nombre[50];
	char EPS[50];
	char pensiones[50];
}datos;

typedef struct
{
	long long id;
	double valor_hora;
	int extras;
	int ordinarias;
	int descuent_salud;
	int descuento_pension;
	double salario;
	double salario_extra;
	double neto;
}nomina;

/********************************************************************************************/
int menu();
void crear_ficheros();
int registrar();
/********************************************************************************************/

int main()
{
	setlocale(LC_ALL,"spanish");
	system("COLOR 90");
	
	int cantidad_empleados=0;
	
	crear_ficheros();
	
	while(true)
	{
		switch(menu())
		{
			case 1:
				{
					 cantidad_empleados =registrar();
					
				}break;
			
			case 2:
				{
					if(!cantidad_empleados)
					{
						cout<<"Por favor, ingrese los datos primero."<<endl;
						system("PAUSE");
						continue;
					}	
				}break;
			
			case 3:
				{
					if(!cantidad_empleados)
					{
						cout<<"Por favor, ingrese los datos primero."<<endl;
						system("PAUSE");
						continue;
					}				
				}break;
				
			case 4:
				{
					if(!cantidad_empleados)
					{
						cout<<"Por favor, ingrese los datos primero."<<endl;
						system("PAUSE");
						continue;
					}	
					
				}break;
			
			case 5:
				{
					if(!cantidad_empleados)
					{
						cout<<"Por favor, ingrese los datos primero."<<endl;
						system("PAUSE");
						continue;
					}	
					
				}break;
			
			case 6:
				{
					return 0;
				}break;
		}
	}
}
/********************************************************************************************/
//SECUNDARIAS

bool validar_empleado(long long id, char *nombre)
{
	datos trabajador;
	ifstream empleados;
	
	empleados.open("Empleados.dat",ios::in|ios::binary);
	
	if(empleados.fail())
	{
		cout<<"\nError al intentar válidar el empleado, no se pudo abrir el archivo"<<endl;
		exit(0);
	}
	
	empleados.read(reinterpret_cast<char*>(&trabajador), sizeof(datos));
	while(!empleados.eof())
	{
		if(trabajador.id==id)
		{
			strcpy(nombre,trabajador.nombre);
			empleados.close();
			return true;
		}
		
		empleados.read(reinterpret_cast<char *>(&trabajador), sizeof(datos));
	}
	
	empleados.close();
	return false;
}
/********************************************************************************************/

/********************************************************************************************/
int menu()
{
	setlocale(LC_ALL,"spanish");
	
	int opcion;
	
	system("CLS");
	
	cout<<"\t\tNÓMINA"<<endl<<endl;
	
	cout
	<<"1. Registrar"<<endl
	<<"2. Cálcular nómina"<<endl
	<<"3. Consultas"<<endl
	<<"4. Información banco"<<endl
	<<"5. Pago de pila"<<endl
	<<"6 Salir";
	
	do
	{
		cout<<"\nOpción: ";
	}while(rangeint(1,6,opcion));
	
	return opcion;
}
/********************************************************************************************/
void crear_ficheros()
{
	ofstream file1;
	
	file1.open("Empleados.dat", ios::out|ios::binary);
	
	if(file1.fail())
	{
		cout<<"No se pudo crear el archivo empleado.txt"<<endl;
		Sleep(2000);
		
		exit(0);
	}
	
	file1.close();
	
	ofstream file2;
	
	file2.open("Nomina.dat", ios::out|ios::binary);
	
	if(file2.fail())
	{
		cout<<"No se pudo crear el archivo Nomina.txt"<<endl;
		Sleep(2000);
		
		exit(0);
	}
	
	//Archivos creados
}
/********************************************************************************************/
int registrar()
{
	setlocale(LC_ALL,"spanish");
	
	static int cantidad_empleados=0;
	datos empleados;
	nomina pagos;
	long long id;
	char nombre[50];
	int opcion;
	
	while(true)
	{
		cantidad_empleados++;
		
		do
		{
			do
			{
				cout<<"\nIngrese el ID del empleado #"<<cantidad_empleados<<": ";
			}while(lowlong(1,id));
			
			if(validar_empleado(id,nombre))
			{
				cout<<"El empleado "<<nombre<<" ya se encuentra registrado"<<endl;
			}
			
		}while(validar_empleado(id,nombre));
		
		ofstream trabajadores, tabla;
		
		trabajadores.open("Empleados.dat",ios::app|ios::binary);
		
		if(trabajadores.fail())
		{
			cout<<"Error al abrir el archivo Empleados.dat"<<endl;
			exit(0);
		}
		
		empleados.id= id;
		
		cout<<"Ingrese el nombre del empleado: ";
		fflush(stdin);
		gets(empleados.nombre);
		
		cout<<"Ingrese la EPS del empleado: ";
		fflush(stdin);
		gets(empleados.EPS);
		
		cout<<"Ingrese la empresa de pensiones del empleado: ";
		fflush(stdin);
		gets(empleados.pensiones);
		
		trabajadores.seekp((cantidad_empleados-1)*sizeof(datos), ios::beg);
		trabajadores.write(reinterpret_cast<char*>(&empleados),sizeof(datos));
		
		do
		{
			cout<<"\nValor de la hora del empleado: ";
		}while(lowdouble(1,pagos.valor_hora));
		
		do
		{
			cout<<"\nHoras trabajadas del empleado: ";
		}while(lowint(1,pagos.ordinarias));
		
		tabla.open("Nomina.dat",ios::app|ios::binary);
		
		if(tabla.fail())
		{
			cout<<"Error al abrir el archivo Nomina.dat"<<endl;
			exit(0);
		}
		
		tabla.seekp((cantidad_empleados-1)*sizeof(nomina), ios::beg);
		
		tabla.write(reinterpret_cast<char*>(&pagos),sizeof(nomina));
		
		trabajadores.close();
		tabla.close();
		
		cout
		<<endl
		<<"¿Desea regitrar otro empleado?"<<endl
		<<"1. Si"<<endl
		<<"2. no";
		
		do
		{
			cout<<"\nOpción: ";
		}while(rangeint(1,2,opcion));
		
		if(opcion==2)
		{
			break;
		}
	}
	
	return cantidad_empleados;
}
/********************************************************************************************
void calcular_nomina()
{
	setlocale(LC_ALL,"spanish");
	
	
}
*/
