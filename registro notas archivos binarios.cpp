/*A partir de la explicaci�n del programa resuelto en clase desarrolle una soluci�n para que se implementen los siguientes procesos:
Registro de Notas - SUPERCOCO 
1)Registro de estudiantes 
2)Registro de asignaturas 
3)Registro de notas
4)Visualizar resultados
5)Salir

Nota: Debe validar que no se registren m�s de un estudiante y asignatura con el mismo c�digo, y para poder realizar el registro de una nota debe estar registrado el estudiante y la asignatura

En la opci�n de visualizar resultados el c�digo del estudiante, nombre, asignatura, nota de cada parcial, nota definitiva, promedio del grupo, nota definitiva m�s alta y m�s baja y el porcentaje de estudiantes reprobados.

Considere los siguientes datos definidos en las estructuras para los archivos
struct datos_personales{
    char nombre[50];
    long cod_est;
    char sexo;
    long cod_prog;
};//datos_personales alumno;    
   
struct novedad{
    long cod_est;
    long cod_asig;
    float np1;
    float np2;
    float np3;
};//novedad notas;

struct pensum{
    long cod_asig;
    char nombre[30];
    int creditos;
};//pensum asignatura*/


#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctype.h>
using namespace std;

struct datos_personales{
    char nombre[50];
    long cod_est;
    char sexo;
    long cod_prog;
};//datos_personales alumno;    
   
struct novedad{
    long cod_est;
    long cod_asig;
    float np1;
    float np2;
    float np3;
};//novedad notas;

struct pensum{
    long cod_asig;
    char nombre[30];
    int creditos;
};//pensum asignatura


void reg_est();
bool val_est(long );
void reg_mat();
bool val_mat(long);
void reg_notas();
void reporte();	

int main()
{
	//crear archivos en blancos cada vez que se ejecute el programa
	ofstream archivoe("estudiante.txt", ios::out | ios::binary);
	if (archivoe.fail())
	{
		cout<<"ERROR para abrir archivp estudiante.txt"<<endl;
		system("pause");
		exit(0);
	}
	archivoe.close();
	
	ofstream archivom("materias.txt", ios::out | ios::binary);
	if (archivom.fail())
	{
		cout<<"ERROR para abrir archivo materias.txt"<<endl;
		system("pause");
		exit(0);
	}
	archivom.close();
		
	ofstream archivon("notas.txt", ios::out | ios::binary);
	if (archivon.fail())
	{
		cout<<"ERROR para abrir archivo notas.txt"<<endl;
		system("pause");
		exit(0);
	}
	archivon.close();
//*******************************************************************************
	int opc, sw1=0, sw2=0, sw3=0;
	do
	{
		system("cls");
		cout<<"Registro de Notas - SUPERCOCO "<<endl;
		cout<<"1)Registro de estudiantes "<<endl;
		cout<<"2)Registro de asignaturas "<<endl;
		cout<<"3)Registro de notas"<<endl;
		cout<<"4)Visualizar resultados"<<endl;
		cout<<"5)Salir"<<endl;
		do
		{
			cout<<"Seleccione una opci�n: ";
			cin>>opc;
		}while(opc<1 || opc>5);
		
		switch(opc)
		{
			case 1: 
				reg_est();
				sw1=1;
				break;
			case 2: 
				reg_mat();
				sw2=1;
				break;
			case 3:
				if(sw1==1 && sw2 ==1)
				{
					reg_notas();
					sw3=1;
				}
				else 
				{
					cout<<"No se han registrado estudiantes o asignaturas no se puede hacer registro de notas" <<endl;
					system("pause");	
				}
				break;
			case 4:
				if(sw3==0)
				{
					cout<<"No se han registrado notas no se puede generar reporte" <<endl;
					system("pause");
				}
				else 
					reporte();
				break;
			case 5:
				exit(0);
		}
		
	}while(opc);
}

void reg_est()
{
	datos_personales alumno;
	int continuar;
	
	do
	{
		system("cls");
		do
		{
			cout<<"C�digo del estudiante: "; 	cin>>alumno.cod_est;
		}while(alumno.cod_est<=0);
		
		
		if(val_est(alumno.cod_est) )
		{
			cout<<"\nEstudiante ya est� registrado "<<endl;
			system("pause");
		}
		else
		{ 
			do
			{
				cout<<"Nombre: "; 	fflush(stdin); 	gets(alumno.nombre);
			}while(alumno.nombre[0]=='\0');
			
			do
			{
				cout<<"Sexo [F]emenino - [M]asculino: "; cin>>alumno.sexo;	
			}while(toupper(alumno.sexo)!= 'F' and toupper(alumno.sexo)!= 'M');
			
			do
			{
				cout<<"C�digo del programa: "; cin>>alumno.cod_prog;
			}while(alumno.cod_prog<=0);
			
			//escribir informaci�n en el archivo
			ofstream archivo("estudiante.txt", ios::app | ios::binary);
			if (archivo.fail())
			{
				cout<<"ERROR para abrir archivp estudiante.txt"<<endl;
				system("pause");
				exit(0);
			}
			archivo.write(reinterpret_cast<char *>(&alumno), sizeof(datos_personales));
			archivo.close();
		}
		cout<<"1. Desea registrar otro estudiante - cualquier otro valor terminar: ";
		cin>>continuar;
	}while(continuar==1);
	
}

bool val_est(long cod)
{
	datos_personales alumno;
	ifstream archivo("estudiante.txt", ios::in | ios::binary);
	if (archivo.fail())
	{
		cout<<"ERROR para abrir archivp estudiante.txt"<<endl;
		system("pause");
		exit(0);
	}
	archivo.read(reinterpret_cast<char *>(&alumno), sizeof(datos_personales));
	while(!archivo.eof())
	{
		if(cod == alumno.cod_est)
		{
			cout<<alumno.nombre;
			return true;	
		}
		archivo.read(reinterpret_cast<char *>(&alumno), sizeof(datos_personales));	
	}	
	archivo.close();
	return false;
}
void reg_mat()
{
	pensum asignatura;
	int continuar;
	
	do
	{
		system("cls");
		do
		{
			cout<<"C�digo de la asignatura: ";
			cin>>asignatura.cod_asig;	
		}while(asignatura.cod_asig<=0);
		
		if(val_mat(asignatura.cod_asig) )
		{
			cout<<"\nasignatura ya est� registrada "<<endl;
			system("pause");
		}
		else
		{ 
			cout<<"Nombre: "; fflush(stdin); gets(asignatura.nombre);
			cout<<"Creditos: "; cin>>asignatura.creditos;
			//escribir informaci�n en el archivo
			ofstream archivo("materias.txt", ios::app | ios::binary);
			if (archivo.fail())
			{
				cout<<"ERROR para abrir archivo materias.txt"<<endl;
				system("pause");
				exit(0);
			}
			archivo.write(reinterpret_cast<char *>(&asignatura), sizeof(pensum));
			archivo.close();
		}
		cout<<"1. Desea registrar otra asignatura - cualquier otro valor terminar: ";
		cin>>continuar;
	}while(continuar==1);
		
}
bool val_mat(long cod )
{
	pensum asignatura;
	ifstream archivo("materias.txt", ios::in | ios::binary);
	if (archivo.fail())
	{
		cout<<"ERROR para abrir archio materias.txt"<<endl;
		system("pause");
		exit(0);
	}
	archivo.read(reinterpret_cast<char *>(&asignatura), sizeof(pensum));
	while(!archivo.eof())
	{
		if(cod == asignatura.cod_asig)
		{
			cout<<asignatura.nombre;
			return true;	
		}
		archivo.read(reinterpret_cast<char *>(&asignatura), sizeof(pensum));	
	}	
	archivo.close();
	return false;
}

void reg_notas()
{
	novedad notas;
	int continuar;
	do
	{
		system("cls");
		cout<<"C�digo del estudiante: ";
		cin>>notas.cod_est;
		
		if(! val_est(notas.cod_est) )
		{
			cout<<"Estudiante no est� registrado"<<endl;
			system("pause");	
		}
		else
		{
			cout<<"\nC�digo de la asignatura: ";
			cin>>notas.cod_asig;
			if(! val_mat(notas.cod_asig) )
			{
				cout<<"Materia no est� registrado"<<endl;
				system("pause");	
			}
			else
			{
				cout<<"\nNota Parcial 1: "; cin>>notas.np1;
				cout<<"Nota Parcial 2: "; cin>>notas.np2;
				cout<<"Nota Parcial 3: "; cin>>notas.np3;
				cout<<"Definitiva: "<<notas.np1*0.3 + notas.np2*0.3 + notas.np3*0.4 <<endl;
			}
			//escribir archivo 
			ofstream archivo("notas.txt", ios::app | ios::binary);
			if (archivo.fail())
			{
				cout<<"ERROR para abrir archivo notas.txt"<<endl;
				system("pause");
				exit(0);
			}
			archivo.write(reinterpret_cast<char *>(&notas), sizeof(novedad));
			archivo.close();
		}
		cout<<"Continuar registro de notas 1.SI - cualquier otro valor NO: ";
		cin>>continuar;
		
	}while(continuar == 1);
	
}

void reporte()
{
	novedad notas;
	float def, acum=0, def_max=0, def_min=5, reprob=0, e=0;
	
	system("cls");
	ifstream archivo("notas.txt",ios::in |ios::binary);
	if(archivo.fail())
	{
		cout<<"Error al abrir el archivo notas para lectura"<<endl;
		system("pause");
		exit(0);
	}
	cout<<setw(30)<<"ESTUDIANTE"<<setw(20)<<"ASIGNATURA"<<setw(10)<<"PARCIAL 1"<<setw(10)<<"PARCIAL 2"<<setw(10)<<"PARCIAL 3"<<setw(12)<<"DEFINITIVA" <<endl;
	archivo.read(reinterpret_cast<char *>(&notas), sizeof(novedad));
	while(!archivo.eof())
	{
		e++;//contar la cantidad de notas registradas 
		cout<<setw(30);
		val_est(notas.cod_est);
		cout<<setw(20);
		val_mat(notas.cod_asig);
		def = notas.np1*0.3 + notas.np2*0.3 + notas.np3*0.4 ;
		cout<<setw(10)<<notas.np1<<setw(10)<<notas.np2<<setw(10)<<notas.np3<<setw(12)<<def<<endl;
		//promedio del grupo
		acum += def;
		//nota definitiva m�s alta y m�s baja
		if(def > def_max) 
		{ def_max = def;  } 
		if(def < def_min) 
		{ def_min = def;  } 
		//porcentaje de estudiantes reprobados.
		if(def <3.0)
		{ reprob++; }
		archivo.read(reinterpret_cast<char *>(&notas), sizeof(novedad));
		
	}
	archivo.close();
	cout<<"Promedio: " <<acum/e <<endl;
	cout<<"Nota definitiva m�s alta: "<<def_max  <<"\ty m�s baja: "<<def_min <<endl;
	cout<<"Porcentaje de estudiantes reprobados: " <<reprob*100/e <<"%\n";
	system("pause");
}
