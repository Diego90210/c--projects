/* Elaborar un algoritmo que forme dos arreglos relacionados que almacenen los códigos de los N  artículos que se venden en un almacén y la existencia (número de unidades existentes) de cada  uno de los artículos, ejemplo: 
Del artículo con código 101 hay 30 unidades en existencia; del artículo con código 200 hay 40  unidades y así sucesivamente. 
Por cada proveedor o cliente que llega al almacén se genera un registro con los siguientes datos: a. Tipo de transacción [1 para proveedor (recibo); 2 para cliente (venta)] 
b. Código del artículo transado 
c. Número de unidades transadas (recibidas o vendidas) 
Al final se deben mostrar los códigos de los artículos y las existencias de cada uno de ellos, es decir,  los arreglos de códigos y de existencias actualizados. En caso de que la cantidad vendida supere la  existencia, la operación se debe anular, y se debe emitir un mensaje de error al usuari
*/
#include <iostream>
using namespace std;

int main()
{
	int N,x, continuar, sw, tipo_tran;
	long cod, unid;
	do
	{
		cout<<"Cantidad de articulos: ";
		cin>>N;	
	}while(N<=0);
	
	long codigo[N];
	long existencias[N];
	
	cout<<"Cargando valores actuales de existencia"<<endl;
	for(x=0; x<N; x++)
	{
		cout<<"Registro datos articulo # "<<x+1 <<endl;
		cout<<"Codigo: "; cin>>codigo[x];
		cout<<"Cantidad en existencia: "; cin>>existencias[x];
	}
	do
	{
		system("cls");
		sw=0;
		cout<<"Codigo de articulo a transar: ";
		cin>>cod;
		for(x=0; x<N; x++)
		{
			if(cod == codigo[x])
			{
				sw=1;
				do
				{
					cout<<"Tipo de transacción [1 para proveedor (recibo); 2 para cliente (venta)] :";	
					cin>>tipo_tran;
				}while(tipo_tran<1 || tipo_tran>2);
				do
				{
					cout<<"Número de unidades transadas (recibidas o vendidas) ";
					cin>>unid;
				}while(unid<=0);
				
				if(tipo_tran == 1)
				{
					existencias[x] += unid;
				}
				else
				{
					if(unid > existencias[x])
					{
						cout<<"Cantidad en existencia insufiente" <<endl;
					}
					else
					{
						existencias[x] -= unid;
					}
				}
				break;
			}//if 	
		}//for
		if(sw==0)
		{
			cout<<"Articulo no está registrado"<<endl;
		}
		cout<<"Desea registrar la transacción de otro articulo: 1.SI - 0.Salir: ";
		cin>>continuar;
	}while(continuar == 1);
	
	system("cls");
	for(x=0; x<N; x++)
	{
		cout<<"Producto #"<<x+1 <<"\tCodigo:"<<codigo[x]<<"\tCantidad en existencia: "<<existencias[x]<<endl;
	}	
}
