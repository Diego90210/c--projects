/*Desarrollar un programa que permita calcular el salario que recibir� cada uno de los N empleados que tiene una empresa.
el c�lculo se realizar� a  partir del total de las horas reportadas y el salario por hora.
Tenga en cuenta que las horas reportadas exceden de 48, se consideran extras y tienen un recargo del 75% de una hora ordinaria. 

Por otro lado,  si el usuario tiene reportadas horas de ausencia, le ser�n restadas a las horas extras si las tiene, en caso de tener horas de ausencia y no tener horas extras, se le restar� a las horas ordinarias.

Se debe implementar una funci�n para calcular el salario la cual recibir� como par�metros por referencia las horas ordinarias y las horas extras y por valor el valor de la hora. Esta funci�n debe invocar a la funci�n ausencias.

La funci�n ausencias recibir� las horas extras y las ordinarias como par�metros por referencia y se validar�n con respecto a las horas de ausencia que se deben leer. */

#include <iostream>
using namespace std;

void ausencia(int &ho, int &he)
{
	int ha;
	cout<<"Cantidad horas de ausencia: ";
	cin>>ha;
	if(ha >0 )
	{
		if(he >= ha)
		{ 
			he = he - ha;
		}
		else
		{
			ha = ha - he;
			he =0; 
			ho = ho - ha;
		}
	}
}
/*********************************************************************/
long salario(int &ho, int &he, int vlr_h)
{
	ausencia(ho, he);
	return ho*vlr_h + he*vlr_h*1.75;		
}

using namespace std;
int main()
{
	int N; 
	char nombre[50];
	cout<<"Cantidad de empleados: ";
	cin>>N;
	int horas, vlr_h, he, ha, ho;
	
	for(int x=1; x<=N; x++)
	{
		cout<<"Nombre del empleado: ";
		fflush(stdin); gets(nombre);
		cout<<"Ingrese la cantidad de horas trabajadas: ";
		cin>>horas;
		cout<<"Valor de la hora: ";
		cin>>vlr_h;
		if(horas > 48)
		{ 
			he = horas - 48;
			ho = 48;
		}
		else
		{ 
			he =0;
			ho = horas;
		}
		cout<<"Horas ordinarias: "<<ho <<endl;
		cout<<"Horas extras: "<<he <<endl;
		system("pause");
		system("cls");
		cout<<"Empleado: "<<nombre <<endl;
		cout<<"Total horas reportadas: "<<horas <<endl;
		cout<<"Salario a cancelar: $"<<salario(ho, he, vlr_h) <<endl;
		cout<<"Horas ordinarias: "<<ho <<endl;
		cout<<"Horas extras: "<<he <<endl;
		system("pause");
	}
}
