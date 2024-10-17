/*Diseñar un programa que permita registrar los empleados de las diferentes sucursales que tiene una empresa.
Por cada sucursal se debe registrar: nit, dirección, nombre del gerente y la información de sus empleados. Por cada empleado se debe registrar:  ID, nombre, fecha de nacimiento, cargo y salario . El aplicativo se debe soportar en los procesos definidos en el siguiente menú

Gestión Sucursales Empresas XYZ
1. Ingresar Datos de Sucursal
2. Listado de Sucursales y Empleados
3. Consultar una Sucursal y sus empleados
4. Salir */
#include <iostream>
# define e 100

using namespace std;
struct fecha
{
	int dia;
	int mes;
	int anio;	
};

struct emple
{
	long id;
	char nombre[50];
	char cargo[30];
	long salario;
	fecha fec_nac;
};

struct sucur
{
	long nit;
	char dir[80];
	char gerente[50];
	int cant_emp;
	emple empleados[e];
};
/**********************************************/
void ingresar(sucur sucursales[], int N);
void listado(struct sucur sucursales[], int N);
void consulta(struct sucur sucursales[], int N);
/**********************************************/
int main()
{
	int N;
	cout<<"Cantidad de sucursales: ";
	cin>>N;
	sucur sucursales[N];
	int op;
	do
	{
		system("cls");
		cout<<"Gestión Sucursales Empresas XYZ"<<endl;
		cout<<"1. Ingresar Datos de Sucursal"<<endl;
		cout<<"2. Listado de Sucursales y Empleados"<<endl;
		cout<<"3. Consultar una Sucursal y sus empleados"<<endl;
		cout<<"4. Salir"<<endl;
		cout<<"Seleccione una opción: ";
		cin>>op;
		switch(op)
		{
			case 1://Ingresar Datos de Sucursal
				ingresar(sucursales, N); break;
			case 2://Listado de Sucursales y Empleados
				listado(sucursales, N); break;
			case 3:
				consulta(sucursales, N); break;
			case 4:
				exit(0);
			default: 
				cout<<"Opción incorrecta"<<endl;
				system("pause");
			
		}
	}while(op!=4);	
}

void ingresar(sucur sucursales[], int N)
{
	system("cls");
	for(int x=0; x<N; x++)//RECORRE EL VECTOR DE REGISTRO DE LAS SUCURSALES
	{
		cout<<"Registro Datos Sucural #"<<x+1 <<endl;
		cout<<"Nit: ";cin>>sucursales[x].nit;
		cout<<"Dirección: "; fflush(stdin); gets(sucursales[x].dir);
		cout<<"Gerente: "; fflush(stdin); gets(sucursales[x].gerente);
		cout<<"Cantidad de empleados: "; cin>>sucursales[x].cant_emp;
		for(int i=0; i<sucursales[x].cant_emp; i++)//RECORRE EL VECTOR DE REGISTRO DEL CAMPO EMPLEADOS
		{
			cout<<"Ingrese los datos del empleado No."<<i+1<<endl;
			cout<<"ID: "; 
			cin>>sucursales[x].empleados[i].id;
			cout<<"Nombre: "; fflush(stdin); gets(sucursales[x].empleados[i].nombre);
			cout<<"Cargo: "; fflush(stdin); gets(sucursales[x].empleados[i].cargo);
			cout<<"Salario: $"; 
			cin>>sucursales[x].empleados[i].salario;
			cout<<"Fecha Nacimiento"<<endl;
			cout<<"Día: "; cin>>sucursales[x].empleados[i].fec_nac.dia;
			cout<<"Mes: "; cin>>sucursales[x].empleados[i].fec_nac.mes;
			cout<<"Año: "; cin>>sucursales[x].empleados[i].fec_nac.anio;
		}
	}	
}
void listado(struct sucur sucursales[], int N)
{
	system("cls");
	for(int x=0; x<N; x++)//RECORRE EL VECTOR DE REGISTRO DE LAS SUCURSALES
	{
		cout<<"Registro Datos Sucural #"<<x+1 <<endl;
		cout<<"Nit: " <<sucursales[x].nit <<endl;
		cout<<"Dirección: " <<sucursales[x].dir <<endl;
		cout<<"Gerente: "<<sucursales[x].gerente<<endl;
		cout<<"Cantidad de empleados: "<<sucursales[x].cant_emp<<endl;
		//cout<<"ID Nombre Cargo Salario Fecha nacimiento
		for(int i=0; i<sucursales[x].cant_emp; i++)//RECORRE EL VECTOR DE REGISTRO DEL CAMPO EMPLEADOS
		{
			cout<<sucursales[x].empleados[i].id <<"\t"<<sucursales[x].empleados[i].nombre<<"\t"<<sucursales[x].empleados[i].cargo<<"\t"<<sucursales[x].empleados[i].salario<<"\t"<<sucursales[x].empleados[i].fec_nac.dia<<sucursales[x].empleados[i].fec_nac.mes<<sucursales[x].empleados[i].fec_nac.anio <<endl;
		}
		cout<<endl;	
	}	
	system("pause");
}
void consulta(struct sucur sucursales[], int N)
{
	long xnit;
	int sw=0;
	system("cls");
	cout<<"Ingrese el nit de la empresa a consultar: ";
	cin>>xnit;
	for(int x=0; x<N; x++)
	{
		if(sucursales[x].nit == xnit)
		{
			sw=1;
			cout<<"Registro Datos Sucural #"<<x+1 <<endl;
			cout<<"Nit: " <<sucursales[x].nit <<endl;
			cout<<"Dirección: " <<sucursales[x].dir <<endl;
			cout<<"Gerente: "<<sucursales[x].gerente<<endl;
			cout<<"Cantidad de empleados: "<<sucursales[x].cant_emp<<endl;
			//cout<<"ID Nombre Cargo Salario Fecha nacimiento
			for(int i=0; i<sucursales[x].cant_emp; i++)//RECORRE EL VECTOR DE REGISTRO DEL CAMPO EMPLEADOS
			{
				cout<<sucursales[x].empleados[i].id <<"\t"<<sucursales[x].empleados[i].nombre<<"\t"<<sucursales[x].empleados[i].cargo<<"\t"<<sucursales[x].empleados[i].salario<<"\t"<<sucursales[x].empleados[i].fec_nac.dia<<sucursales[x].empleados[i].fec_nac.mes<<sucursales[x].empleados[i].fec_nac.anio <<endl;
			}
			break;	
		}
		if(sw == 0)
		{
			cout<<"Sucursal consultada no está registrada "<<endl;	
		}	
		system("pause");
	}	
}

