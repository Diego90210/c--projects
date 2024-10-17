#include <iostream>
#include <string.h>
# define e 100
using namespace std;

void menu(int *);
//*********************************************************************
//Structs

struct registro
{
	long ced;
	char nombre[50];
	long fondo;
	int tips;
};

struct asociados
{
	long ced;
	long socio_ced;
	char nombre[50];
	char parent[30];
	int edad;
	char gen[20];
};

struct club
{
	registro socios[e];
	int cant_so;
	int regular;
	int vip;
	asociados dufen[e];
};


//*********************************************************************
//Declaracion de prototio de Funciones

void afiliaccion(struct club cl);
void autorizacion(struct club cl);
//*********************************************************************

int main()
{	bool llenado=false;	
	int opc;
	club cl;
	do
	{	
		menu(&opc);
		system("pause");
		system("cls");
		switch(opc)
		{
			case 1 : 	afiliaccion(cl);
						llenado=true;
						system("pause");
						cl.cant_so=cl.vip+cl.regular;
						break;
						
			case 2 : 	if(llenado)
						{autorizacion(cl);}
						else{cout<<" NO SE HAN AFILIADO SOCIOS"<<endl;}
						system("pause");
						break;
			case 3 : 
						
						system("pause");
						break;
			case 4 : 
						system("pause");
						break;
			case 5 : 
						system("pause");
						break;
			case 6 : 
						system("pause");
						break;
			case 7 : 
						system("pause");
						break;
			case 8 : 
						system("pause");
						break;
						
			case 9 : 	system("pause");
						exit(0);
						break;
		}
	}while(opc!=9);
	
}
//**********************************************************************

void menu(int *opc)
{
	system("cls");
	cout<<"\n\tCLUB SOCIAL LOS PROPIOS\n"<<endl;
	cout<<" 1. Afiliar un socio al club"<<endl;
	cout<<" 2. Registrar Asociado."<<endl;
	cout<<" 3. Registrar Consumo."<<endl;
	cout<<" 4. Pagar Una Factura."<<endl;
	cout<<" 5. Aumentar Fondos de la Cuenta De Un Socio."<<endl;
	cout<<" 6. Cancelar Suscripcion Socio."<<endl;
	cout<<" 7. Modificar Informacion Socio."<<endl;
	cout<<" 8. Consultas."<<endl;
	cout<<" 8. SALIR."<<endl;
	cout<<" Opcion: "; cin>>*opc;
}
//**********************************************************************

void afiliaccion(struct club cl)
{	int x=0,con; 
	bool exito;
	cl.vip=0;
	cl.regular=0;
	
	//-----------
	do
	{	exito=true;
		cout<<"\n Afiliacion de socios\n"<<endl;
		cout<<" Numero de cedula: "; cin>>cl.socios[x].ced;
		cout<<" Nombre: "; fflush(stdin); 
		gets(cl.socios[x].nombre);
		
		for(int i=0; i<strlen(cl.socios[x].nombre); i++)
		{cl.socios[x].nombre[i]=toupper(cl.socios[x].nombre[i]);}
		
		do
		{
			cout<<" Fondos Disponibles: "; cin>>cl.socios[x].fondo;
		}while(cl.socios[x].fondo<0);
		do
		{cout<<" Suscripción 1.VIP 2.REGULAR: "; cin>>cl.socios[x].tips;
		}while(cl.socios[x].tips<1 || cl.socios[x].tips>2);
		//-----------
		if(cl.socios[x].tips==1)
		{		//Verificacion de fondos suficientes
			if(cl.socios[x].fondo<1000000 || cl.socios[x].fondo>5000000)
			{exito=false;} //Verificacion del limite de vips
				else if((((cl.regular+cl.vip)/5)*2>=cl.vip+1 ))
					{cl.vip++;}
						else{exito=false;}
		}
		//-----------
		if(cl.socios[x].tips==2)
		{	//Verificacion de fondos suficientes
			if(cl.socios[x].fondo<300000 || cl.socios[x].fondo>2000000)
			{exito=false;}
			else {cl.regular++;}
		}
		//-----------
			for(int i=0; i<x; i++)
			{	//Encontrar la cedula ya se encuentra registrada
				if(cl.socios[x].ced==cl.socios[i].ced)
				{
					exito=false;
					cout<<" NUMERO DE CEDULA DE SOCIO DUPLICADO"<<endl;
					break;
				}
			}

		//-----------
		if(exito)
		{
			cout<<" REGISTRO DE ASOCIADO EXITOSO"<<endl;
			x++;
		}
			else{cout<<" REGISTRO DE ASOCIADO ERRONEO"<<endl;	}
		//-----------
		do{		cout<<"¿ Desea Afiliar otro socio? 1.SI 2.NO: "; cin>>con;
		}while(con<1 || con>2);
		
	}while(con==1);
	
}
//**********************************************************************

void autorizacion(struct club cl)
{	
	int n,abc;
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
					for(int i=0; i<cl.cant_so;i++)
					{
						if(name==cl.socios[i].nombre)
						{exito=true;}
					}
					break;
		
		case 2 : 	exito=false;
					cout<<" NUMERO DE CEDULA DE SOCIO: "; cin>>cd;
					for(int i=0; i<cl.cant_so; i++)
					{
						if(cd==cl.socios[i].ced)
						{
							exito=true;
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
		if(abc==1)
			{	
				
				
				
				for(int j=0; j<cl.cant_so; j++)
				{
					if(cd==cl.socios[j].ced)
					{
						cl.dufen[i].socio_ced=cl.socios[j].ced;
						break;
					}
				}
				
			}
			else
			{cl.dufen[i].socio_ced=cd;}
		}
		//-----------------------------------
		for(int i=0; i<n; i++)
		{	
			
			cout<<" NOMBRE DE ASOCIADO No"<<i+1<<": "; fflush(stdin);
			gets(cl.dufen[i].nombre);
			cout<<" CEDULA: "; cin>>cl.dufen[i].ced;
			do{
				cout<<" EDAD: "; cin>>cl.dufen[i].edad;
			}while(cl.dufen[i].edad<0);
			
			cout<<" PARENTESCO: "; fflush(stdin);
			gets(cl.dufen[i].parent);
			cout<<" SEXO: "; fflush(stdin);
			gets(cl.dufen[i].gen);
			
			                      
		}
	}
}
			                      