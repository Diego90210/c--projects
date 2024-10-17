//Librerias
#include <iostream>
#include <string.h>
using namespace std;

struct fec
{
    int dia;
    int mes;
    int anio;
};

struct factu{
	int n_factura=0;
    long ced_factu;
    char concepto [50];
    long vlr_consumo;
    fec fecha_consumo;
    bool estado=false;
};

struct asociado{
    long ced_socio;
    long ced_asociado;
    char nombre_asociado [50];
    char parentesco [50];
    int edad;
    char sexo [15];
};

struct socio{
	long cedula;
	char nombre[50];
	long f_disponibles;
	int tipo_suscrip;
    int num_asociados=0;
	int num_factu=0;
    asociado asociados [3600];
    factu factura [9000];
}socios[900];

//*********************************************************************
//Structs

struct fecha
{
	int dia;
	int mes;
	int year;
};

struct factura
{
	int num_fact=0;
	char concep[80];
	long vlr;
	fecha data;
	bool estado; //false para pendiente, true para cancelado
	
};

struct asociados
{
	long ced;
	char nombre[50];
	char parent[30];
	int edad;
	char gen[20];
};

struct registro
{
	long ced;
	char nombre[50];
	long fondo;
	int tips;
	asociados dufen[900];
	factura consu[100];
	int cant_fact=0; //Cantidad de facturas por socios
};
struct club
{
	registro socios[900];
	int cant_so; //Cantidad total de socios
	int regular; //Cantidad total de socios regulares
	int vip; //Cantidad total de vips
	factura consu;
	int cant_fact=0; //Cantidad de facturas total
};


void autorizacion(struct club cl)
{	
	int n,abc,x;
	char name[50];
	bool exito;
	long cd;
	
	cout<<"\n REGISTRO DE ASOCIADOS\n"<<endl;
	cout<<" CONSULTAR SOCIO AFILIADO POR:"<<endl;
	cout<<" 1. NOMBRE."<<endl;
	cout<<" 2. CEDULA."<<endl;
	do
	{
		cout<<" OPCION: "; cin>>abc;
	}while(abc<1 || abc>2);
	
	//------------------------------------
	switch(abc)
	{
		case 1 : 	exito=false;
					cout<<" NOMBRE DE SOCIO: "; fflush(stdin);
					gets(name);
					
					for(int i=0; i<strlen(name);i++)
					{name[i]=toupper(name[i]);} 
					//-----------------------------------
					for(int i=0; i<cl.cant_so;i++)
					{
						if(name==cl.socios[i].nombre)
						{exito=true; x=i;
						 break;}
					}
					break;
		
		case 2 : 	exito=false;
					cout<<" NUMERO DE CEDULA DE SOCIO: "; cin>>cd;
					
					for(int i=0; i<cl.cant_so; i++)
					{
						if(cd==cl.socios[i].ced)
						{
							exito=true; x=i;
							break;
						}
					}
					break;
	}
	
	//-----------------------------------
	
	if(exito)
	{
		cout<<" CANTIDAD DE ASOCIADOS A REGISTRAR: "; cin>>n;
		//-----------------------------------
		
		for(int i=0; i<n; i++)
		{	
			
			cout<<" NOMBRE DE ASOCIADO No"<<i+1<<": "; fflush(stdin);
			gets(cl.socios[x].dufen[i].nombre);
			cout<<" CEDULA: "; cin>>cl.socios[x].dufen[i].ced;
			do{
				cout<<" EDAD: "; cin>>cl.socios[x].dufen[i].edad;
			}while(cl.socios[x].dufen[i].edad<0);
			
			cout<<" PARENTESCO: "; fflush(stdin);
			gets(cl.socios[x].dufen[i].parent);
			cout<<" SEXO: "; fflush(stdin);
			gets(cl.socios[x].dufen[i].gen);
			
			                      
		}
	}
}
//**********************************************************************		
void consumo(struct club cl)
{
	int abc,x;
	long cd,vlr;
	char name[50];
	bool exito;
	int y=cl.cant_fact;
	cout<<"\n FACTURACION DE CONSUMOS\n"<<endl;
	
	cout<<" CONSULTAR SOCIO AFILIADO POR:"<<endl;
	cout<<" 1. NOMBRE."<<endl;
	cout<<" 2. CEDULA."<<endl;
	do
	{
		cout<<" OPCION: "; cin>>abc;
	}while(abc<1 || abc>2);
	
	//------------------------------------
	switch(abc)
	{
		case 1 : 	exito=false;
					cout<<" NOMBRE DE SOCIO: "; fflush(stdin);
					gets(name);
					
					for(int i=0; i<strlen(name);i++)
					{name[i]=toupper(name[i]);} 
					//-----------------------------------
					for(int i=0; i<cl.cant_so;i++)
					{
						if(name==cl.socios[i].nombre)
						{exito=true; x=i;
						 break;}
					}
					break;
		
		case 2 : 	exito=false;
					cout<<" NUMERO DE CEDULA DE SOCIO: "; cin>>cd;
					
					for(int i=0; i<cl.cant_so; i++)
					{
						if(cd==cl.socios[i].ced)
						{
							exito=true; x=i;
							break;
						}
					}
					break;
	}
	
	if(exito)
	{	
			
		cout<<" FACTURA N0."<<cl.cant_fact+1<<endl;
		cout<<" CEDULA SOCIO: "<<cl.socios[x].ced<<endl;
		cout<<" CONCEPTO DE CONSUMO: "; fflush(stdin);
		gets(cl.socios[x].consu[y].concep);
		cout<<" VALOR CONSUMO: "; cin>>vlr;
		
		cout<<" FECHA: "<<endl;
		cout<<" DAY: "; cin>>cl.socios[x].consu[y].data.dia;
		cout<<" MONTH: "; cin>>cl.socios[x].consu[y].data.mes;
		cout<<" YEAR: "; cin>>cl.socios[x].consu[y].data.year;
		
	}
	else{
		cout<<" SOCIO NO ENCONTRADO"<<endl;
	}
	if(cl.socios[x].fondo<vlr)
		{
			cout<<"\n FACTURA NO GENERADA POR FONDOS INSUFICIENTES"<<endl;
			exito=false;
		}
	else
	{
		cout<<"\n FACTURA GENERADA"<<endl;
		cout<<" ESTADO: PENDIENTE"<<endl;
		cl.socios[x].consu[y].estado=false;
		cl.cant_fact++;
		cl.socios[x].consu[y].vlr=vlr;
		cl.socios[x].consu[y].num_fact=	cl.cant_fact;
		cl.socios[x].cant_fact++;
		cout<<" NUMERO DE FACTURA: "<<cl.socios[x].consu[y].num_fact<<endl;
		cout<<" VALOR DE DEUDA: "<<cl.socios[x].consu[y].vlr<<endl;
	}
}

//**********************************************************************
void pagos(struct club cl)
{
	int abc,x;
	long num;
	char name[50];
	bool exito;
	int y;
	cout<<"\n PAGO DE FACTURAS\n"<<endl;
	
	cout<<" CONSULTAR FACTURA POR:"<<endl;
	cout<<" 1. NOMBRE."<<endl;
	cout<<" 2. NUMERO DE FACTURA."<<endl;
	do
	{
		cout<<" OPCION: "; cin>>abc;
	}while(abc<1 || abc>2);
	
	//------------------------------------
	switch(abc)
	{
		case 1 : 	exito=false;
					cout<<" NOMBRE DE SOCIO: "; fflush(stdin);
					gets(name);
					
					for(int i=0; i<strlen(name);i++)
					{name[i]=toupper(name[i]);} 
					//-----------------------------------
					for(int i=0; i<cl.cant_so;i++)
					{
						if(name==cl.socios[i].nombre)
						{exito=true; x=i;
						 break;}
					}
					
					if (exito)
					{
						cout<<"\n FACTURAS A NOMBRE DE: "<<name<<endl;
						for(int i=0; i<cl.socios[x].cant_fact; i++)
						{cout<<"	-"<<cl.socios[x].consu[i].num_fact<<endl;}
						cout<<" NUMERO DE FACTURA A PAGAR: "; cin>>num;
						
						for(int i=0; i<cl.cant_so; i++)
						{
							if(num==cl.socios[x].consu[i].num_fact)
							{
								exito=true; y=i;
								break;
							}
						}
					}
					else {cout<<"\n NUMERO DE FACTURA NO ENCONTRADO"<<endl;	}
						break;
		
		case 2 : 	exito=false;
					cout<<"\n NUMERO DE FACTURA: "; cin>>num;
					
					for(int i=0; i<cl.cant_so; i++)
					{
						for(int j=0; j<cl.socios[i].cant_fact; j++)
						{
							if(num==cl.socios[i].consu[j].num_fact)
							{
								exito=true; x=i; y=j;
								break;
							}
						}
						if(exito)
						{break;}
					}
					if(exito==false)
					{cout<<"\n NUMERO DE FACTURA NO ENCONTRADO"<<endl;	}
					break;
	}
	
	if(exito)
	{	
		if(cl.socios[x].consu[y].vlr<=cl.socios[x].fondo)
		{
			cout<<"\n FACTURA EMCONTRADA.";
			cout<<" FACTURA N0."<<cl.socios[x].consu[y].num_fact<<endl;
			cout<<" CEDULA SOCIO: "<<cl.socios[x].ced<<endl;
			cout<<" CONCEPTO DE CONSUMO: "<<cl.socios[x].consu[y].concep<<endl;
			cout<<" VALOR CONSUMO: "<<cl.socios[x].consu[y].vlr<<endl;
	
			cout<<" FECHA: "<<endl;
			cout<<" DAY: "<<cl.socios[x].consu[y].data.dia;
			cout<<" MONTH: "<<cl.socios[x].consu[y].data.mes;
			cout<<" YEAR: "<<cl.socios[x].consu[y].data.year;
		
			cout<<" ESTADO: CANCELADO"<<endl;
		
			cl.socios[x].fondo-=cl.socios[x].consu[y].vlr;
		}
		else{cout<<" ERROR EN OPERACION, FONDOS INSUFICIENTES"<<endl;}
	}
	
	else{cout<<" ERROR EN OPERACION, NO SE ECONTRARON DATOS RELACIONADOS"<<endl;}
}
//**********************************************************************
void aumento_fondo(struct club cl)
{
	int abc,x;
	long cd,vlr;
	char name[50];
	bool exito;
	int y=cl.cant_fact;
	cout<<"\n AUMENTO DE FONDO\n"<<endl;
	
	cout<<" CONSULTAR SOCIO AFILIADO POR:"<<endl;
	cout<<" 1. NOMBRE."<<endl;
	cout<<" 2. CEDULA."<<endl;
	do
	{
		cout<<" OPCION: "; cin>>abc;
	}while(abc<1 || abc>2);
	
	//------------------------------------
	switch(abc)
	{
		case 1 : 	exito=false;
					cout<<" NOMBRE DE SOCIO: "; fflush(stdin);
					gets(name);
					
					for(int i=0; i<strlen(name);i++)
					{name[i]=toupper(name[i]);} 
					//-----------------------------------
					for(int i=0; i<cl.cant_so;i++)
					{
						if(name==cl.socios[i].nombre)
						{exito=true; x=i;
						 break;}
					}
					break;
		
		case 2 : 	exito=false;
					cout<<" NUMERO DE CEDULA DE SOCIO: "; cin>>cd;
					
					for(int i=0; i<cl.cant_so; i++)
					{
						if(cd==cl.socios[i].ced)
						{
							exito=true; x=i;
							break;
						}
					}
					break;
	}
	
		if(exito)
		{
			cout<<" NOMBRE: "<<cl.socios[x].nombre<<endl;
			cout<<" CEDULA: "<<cl.socios[x].ced<<endl;
			cout<<" MONTO A AGREGAR: $"; cin>>vlr;
			if(vlr+cl.socios[x].fondo>2000000 && cl.socios[x].tips==2)
			{cout<<" ERROR, EL MONTO A AGREGAR SOBREPASA EL TOPE MAXIMO DE LA CUENTA"<<endl;}
			else if(vlr+cl.socios[x].fondo>5000000 && cl.socios[x].tips==1)
				{cout<<" ERROR, EL MONTO A AGREGAR SOBREPASA EL TOPE MAXIMO DE LA CUENTA"<<endl;}
				else
					{
						cl.socios[x].fondo+=vlr;
						cout<<" NUEVO FONDO: $"<<cl.socios[x].fondo<<endl;
					}
		}
		else
			{
				cout<<" SOCIO NO ENCONTRADO"<<endl;
			}
}