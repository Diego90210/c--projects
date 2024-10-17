//Diego Andres Martinez Florez: 0222120002


#include <iostream>
using namespace std;
int main(){
	int n, op, i, j;
	
	do
	{
		cout<<"Ingrese la cantidad de vendedores: ";
		cin>>n;
	}while(n<=0);
	
	string nombre[n], aux_nombre;
	int computadoras[n][4];
	int valor_compu[4];
	int comision[n];
	int c_compu[n];
	long total[n];
	long cancelar_comi=0;
	bool llenado=false; //preguntar.
	long t_compu=0;
	float cla_compu[4]={0,0,0,0};
	float p_compu[4];
	long recaudo_compu[4];
	int aux;
	
	do	
	{
		system("cls");
		cout<<"1. Registro de ventas"<<endl;
		cout<<"2. Generar pago comisiones"<<endl;
		cout<<"3. Estadisticas"<<endl;
		cout<<"4. Salir"<<endl;
		do
		{
			cout<<"Opcion: ";
			cin>>op;
		}while(op<1 || op>4);
		
		switch (op)
		{
			case 1: 
			for(i=0; i<n; i++)
			{
				system("cls");
				cout<<"Vendedor No. "<<i+1<<"\n";
				cout<<"Ingrese el nombre del vendedor: ";
				fflush(stdin); getline(cin,nombre[i]);
				
				cout<<"Computadoras vendidas";
				cout<<"\nComputadoras de escritorio: "; cin>>computadoras[i][0]; 
				cout<<"Computadoras portatil: "; cin>>computadoras[i][1];
				cout<<"Workstantion: "; cin>>computadoras[i][2];
				cout<<"Mainframe: "; cin>>computadoras[i][3];
						
				if(i==0)
				{
					system("cls");
					cout<<"Ingrese los precios de los equipos"<<endl;
					cout<<"Computadoras de escritorio: "; cin>>valor_compu[0];
					cout<<"Computadoras portatil: "; cin>>valor_compu[1];
					cout<<"Workstation: "; cin>>valor_compu[2];
					cout<<"Mainframe: "; cin>>valor_compu[3];			
				}
				
				comision[i]=(((computadoras[i][0]*valor_compu[0])*0.08) + ((computadoras[i][1]*valor_compu[1])*0.1) + ((computadoras[i][2]*valor_compu[2])*0.15) + ((computadoras[i][3]*valor_compu[3])*0.2));
				
				c_compu[i]=computadoras[i][0]+computadoras[i][1]+computadoras[i][2]+computadoras[i][3];
				total[i]=(computadoras[i][0]*valor_compu[0]) + (computadoras[i][1]*valor_compu[1]) + (computadoras[i][2]*valor_compu[2]) + (computadoras[i][3]*valor_compu[3]);
				cancelar_comi+=total[i];
				t_compu+=c_compu[i];
				
				cla_compu[0]+=computadoras[i][0];
				cla_compu[1]+=computadoras[i][1];
				cla_compu[2]+=computadoras[i][2];
				cla_compu[3]+=computadoras[i][3];	
			}
			break;
			
			case 2: system("cls");
				
				cout<<"Reporte de ventas\n";
				for(i=0; i<n; i++)
				{
					if (i>0)
					{
						cout<<"\n";
					}
					cout<<"Vendedor No. "<<i+1<<endl;
					cout<<"Nombre del vendedor: "<<nombre[i]<<endl;
					cout<<"Cantidad de computadoras vendidas: "<<c_compu[i]<<endl; 
					cout<<"Total venta: "<<total[i]<<endl;
					cout<<"Comision a cancelar: "<<comision[i]<<endl;
					system("pause"); 
				}
			break;
			
			case 3:
				
					p_compu[0] = (cla_compu[0]/t_compu)*100; 
					p_compu[1] = (cla_compu[1]/t_compu)*100;
					p_compu[2] = (cla_compu[2]/t_compu)*100;
					p_compu[3] = (cla_compu[3]/t_compu)*100;
					
					recaudo_compu[0]=cla_compu[0]*valor_compu[0];
					recaudo_compu[1]=cla_compu[1]*valor_compu[1];
					recaudo_compu[2]=cla_compu[2]*valor_compu[2];
					recaudo_compu[3]=cla_compu[3]*valor_compu[3];
					
			 		system("cls");
					cout<<"Resumen de venta por linea de computadoras\n";
					cout<<"Cantidad de computadoras vendidas: "<<t_compu<<endl;
					cout<<"Porcentaje de computadoras de escritorio: "<<p_compu[0]<<endl;
					cout<<"Porcentaje de computadoras portatil: "<<p_compu[1]<<endl;
					cout<<"Porcentaje de Workstations: "<<p_compu[2]<<endl;
					cout<<"Porcentaje de Mainframe: "<<p_compu[3]<<endl;
					
					cout<<"\nRecaudo por tipo de computador\n";
					cout<<"computadoras de escritorio: "<<recaudo_compu[0]<<endl;
					cout<<"computadoras portatil: "<<recaudo_compu[1]<<endl;
					cout<<"Workstation: "<<recaudo_compu[2]<<endl;
					cout<<"Mainframe: "<<recaudo_compu[3]<<endl;
					
					system("pause");
					system("cls");
					
				for(i=0; i<n-1; i++) 
				{
					for(j=i+1; j<n; j++)
					{
						if(comision[j]>comision[i])
						{
							aux = comision[i];
							comision[i] = comision[j];
							comision[j] = aux;
				
							aux_nombre = nombre[i];
							nombre[i] = nombre[j];
							nombre[j] = aux_nombre;
						}
					}
				}
				
				for(i=0; i<n; i++)
				{
					cout<<"Vendedor No. "<<i+1<<endl;
					cout<<"Nombre del vendedor: "<<nombre[i]<<endl;
					cout<<"Comision pagada: "<<comision[i]<<endl;
					cout<<"\n";
				}
				system("pause");
			break;
			
			case 4:	break;
		}
			
	}while(op!=4);
	
			
	

	
	
	
	
	
	
	
	
	
	
	return 0;
}
