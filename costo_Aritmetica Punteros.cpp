/*Se tienen los costos de producción de dulces correspondientes a los 12 meses del año anterior.
Dulces

Enero	
Febrero	
.	
.	
.	
Diciembre	

Elaborar un programa que pueda proporcionar la siguiente información:

a) ¿En qué mes (número) se registró el mayor costo de producción?

b) ¿Cuál es el Promedio Anual de los costos de producción?

c) ¿En qué mes se registró el menor costo de producción?*/

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
	cout<<*mmay <<" Corresponde al mes con mayor costo de producción por $" <<*may <<endl;
	cout<<*mmen <<" Corresponde al mes con menor costo de producción por $" <<*men <<endl;
}
