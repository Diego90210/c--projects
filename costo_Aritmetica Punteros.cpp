/*Se tienen los costos de producci�n de dulces correspondientes a los 12 meses del a�o anterior.
Dulces

Enero	
Febrero	
.	
.	
.	
Diciembre	

Elaborar un programa que pueda proporcionar la siguiente informaci�n:

a) �En qu� mes (n�mero) se registr� el mayor costo de producci�n?

b) �Cu�l es el Promedio Anual de los costos de producci�n?

c) �En qu� mes se registr� el menor costo de producci�n?*/

#include <iostream>
using namespace std;

int main()
{
	float costo[12];
	string mes[] = {"enero", "Febrero","Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "septiembre", "octubre", "Noviembre", "diciembre"};
	float *c, *may,*men, acum=0;
	string *m, *mmen, *mmay;
	int cont=0;
	c = costo;
	m = mes;
	do{
		cout<<"Ingrese el costo del mes " <<cont+1 <<" : $"<<endl;
		cin>>*c;
		acum += *c;
		if(cont == 0)
		{
			may =c;
			men =c;
		}
		else 
		{
			if(*c > *may )
			{			
				may = c;
				mmay = m;	
			}	
			if(*c < *men )
			{			
				men = c;
				mmen = m;	
			}
		}
		*c++; 
		*m++;
		cont++;
	}while(cont <3);
	cout<<"Promedio: " <<acum/12 <<endl;
	cout<<*mmay <<" Corresponde al mes con mayor costo de producci�n por $" <<*may <<endl;
	cout<<*mmen <<" Corresponde al mes con menor costo de producci�n por $" <<*men <<endl;
}
