#include <iostream>
using namespace std;

int main()
{
	int costo, costo_iva, zona;
	cout<<"Indique la zona a la que viajará [1,2,3]: ";
	cin>>zona;
	cout<<"Costo del boleto [Sin IVA]: ";
	cin>>costo;
	if(zona == 1)
	{
		costo_iva = costo*1.10;
	}
	else
	{
		if(zona == 2)
		{
			costo_iva = costo * 1.15;
		}
		else
		{
			if(zona == 3)
			{
				costo_iva = costo * 1.22;	
			}
			else
			{
				cout<<"Zona está errada, debe ser 1,2,o 3"<<endl;
				costo_iva = costo;
			}	
		}	
	}
	cout<<"Costo del Boleto con IVA: "<<costo_iva <<endl;
}
