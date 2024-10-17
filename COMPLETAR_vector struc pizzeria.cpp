/* Implementar un programa con que satisfaga los procesos para el siguiente men�: 

PIZZER�A MA DOUCE� SOFTWRE PARA GESTI�N DE PRODUCCI�N
A. ASIGNACI�N DE COSTOS (FIJO, VARIABLE, INGREDIENTE EXTRA)
B. INGRESAR DATOS DEL PEDIDO
C. CONSULTAR UN PEDIDO
D. MODIFICAR UN PEDIDO
E. REPORTE DE PEDIDOS ORDENADO ASCENDENTEMENTE POR CLIENTE
F. REPORTE DE PEDIDOS ORDENADO DESCENDENTEMENTE POR COSTO DE PRODUCCI�N
G. SALIR

El departamento de producci�n de una pizzer�a que surte almacenes de cadenas y supermercados, han solicitado el desarrollo de un programa para gestionar el proceso de producci�n de las pizzas. El departamento de producci�n recibe el pedido teniendo en cuenta la siguiente informaci�n. La pizzer�a vende pizzas en tres tama�os:
� Peque�a (10 pulg. De di�metro)
� Mediana (12 pulg. De di�metro)
� Grandes (16 pulg. De di�metro)

Una pizza puede ser sencilla (con s�lo salsa y un solo ingrediente: carne, jam�n, pollo, etc), o con ingredientes extras, tales como pepinillos, champi�ones o cebollas, etc

El programa solicitado a trav�s de la opci�n de pedido, registrar los datos del pedido de un d�a y calcular el costo y precio de venta de una pizza, con base a los datos del pedido, d�ndole el tama�o y el n�mero de ingredientes extras

Se sabe que el precio de venta ser� 1.5 veces el costo total, que viene determinado por el �rea de la pizza, m�s el n�mero de ingredientes.

Debe implementar una funci�n que reciba como datos el tama�o, y el n�mero de ingredientes extras.
En particular el costo total se calcula sumando:
- un costo fijo de preparaci�n
- un costo base variable que es proporcional al tama�o de la pizza
- un costo adicional por cada ingrediente extra. Por simplicidad se supone que cada ingrediente extra tiene el mismo costo por unidad de �rea.*/
#include <iostream>
#include <iomanip>
#include <string.h>
#include <locale>
using namespace std;

/******************************************************************/
struct costo
{
	
}costos;

struct ped
{
	
};
/**************************************************************/
char menu();
int datos_ped(struct ped pedidos[]);
void consultar(struct ped pedidos[], int x);
void modificar(struct ped pedidos[], int x);
void ord_cliente(struct ped pedidos[], int x);
void ord_costo(struct ped pedidos[], int x);
/***************************************************************/
int main()
{
	setlocale(LC_ALL, "spanish");
	ped pedidos[10000];
	char opc;
	int x;
	
	do
	{
	
		system("cls");	
		opc = menu();
		switch(toupper(opc))
		{
			case 'A':
				cout<<"ASIGNACI�N DE COSTOS (FIJO, VARIABLE, INGREDIENTE EXTRA)" <<endl;
				cout<<"Costo fijo de preparaci�n: $"; cin>>costos.c_fijo;
				cout<<"Costo base variable que es proporcional al tama�o de la pizza" <<endl;
				cout<<"Peque�a :"; cin>>costos.c_peq;
				cout<<"Mediana :"; cin>>costos.c_med;
				cout<<"Grande :"; cin>>costos.c_gra;
				cout<<"Costo adicional ingrediente extra: $" ; cin>>costos.c_extra;
				break;
			case 'B'://INGRESAR DATOS DEL PEDIDO
				x= datos_ped(pedidos);
				break;
			case 'C'://CONSULTAR UN PEDIDO
				consultar(pedidos, x);
				break;
			case 'D'://MODIFICAR UN PEDIDO
				modificar(pedidos, x);
				break;
			case 'E':
				ord_cliente(pedidos, x);
				break;
			case 'F':
				ord_costo(pedidos, x);
				break;
			case 'G':
					exit(0);
		}//switch
		
	}while(toupper(opc) != 'G');
}
//PROTOTIPO DE FUNCIONES 
/************************************************************************/
char menu()
{
	char opc;
	setlocale(LC_ALL, "spanish");
	do
	{
		system("cls");
		cout<<"PIZZER�A MA DOUCE� SOFTWRE PARA GESTI�N DE PRODUCCI�N" <<endl;
		cout<<"A. ASIGNACI�N DE COSTOS (FIJO, VARIABLE, INGREDIENTE EXTRA)" <<endl;
		cout<<"B. INGRESAR DATOS DEL PEDIDO" <<endl;
		cout<<"C. CONSULTAR UN PEDIDO" <<endl;
		cout<<"D. MODIFICAR UN PEDIDO" <<endl;
		cout<<"E. REPORTE DE PEDIDOS ORDENADO ASCENDENTEMENTE POR CLIENTE" <<endl;
		cout<<"F. REPORTE DE PEDIDOS ORDENADO DESCENDENTEMENTE POR COSTO DE PRODUCCI�N" <<endl;
		cout<<"G. SALIR" <<endl;
		cout<<"Seleccione el proceso a realizar: ";
		cin>>opc;
	}while(toupper(opc)<65 || toupper(opc)>71);//validamos que se ingrese un caracter entre A y G
	
	return opc;
}
/************************************************************************/
int datos_ped(struct ped pedidos[])
{
	static int x=0;
	int salir;

	do
	{
		system("cls");
		
		x++;
		cout<<"Desea registrar el pedido de otra pizza: 1.SI - Cualquier valor terminar"<<endl;
		cin>>salir;
	}while(salir== 1);
	return x;
}
/************************************************************************************/
void consultar(struct ped pedidos[], int x)
{
	system("cls");
	int num_p;
	int sw=0;
	
	
	system("pause");
}
/************************************************************************************/
void modificar(struct ped pedidos[], int x)
{
	system("cls");
	int num_p;
	int sw=0, rta; , c_variable;
	cout<<"Ingrese el n�mero del pedido a consultar: ";
	cin>>num_p;
	
	system("pause");
}
/************************************************************************************/
void ord_cliente(struct ped pedidos[], int x)//ascendentemente por cliente
{
	
	
	system("pause");
}
/************************************************************************************/
void ord_costo(struct ped pedidos[], int x)
{

	system("pause");
}
/************************************************************************************/
