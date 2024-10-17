#include <iostream>
#include <ctype.h>
#include <iomanip>
using namespace std;
int main()
{
	int n, i, j;
	
	cout<<"\n \t IM&EX S.A.\n\n";
	do
	{
		cout<<" TOTAL DE LLAMADAS REALIZADAS: "; cin>>n;
	}while(n<=0);
	
	string oficina[]={"Logistica","Recursos Humanos","finaciero"};
    string llamada[]={"Local", "Celular","Internacional"};
	string nombre[n];
	string auxnombre;
	bool llenado=false;
	int opc, ofti, tipofi, minlogi=0, minre=0, minfi=0;
	int logi=0, re=0, fi=0;
	int OCT[n][3], auxofi[n];
	char abc;
	setlocale(LC_ALL,"spanish");
	do
	{ system("cls");
		cout<<"\n\tCONTROL DE LLAMADAS – CENTRO DE COMUNICACIONES\n\n";
		cout<<"1. Registro de llamadas "<<"\n";
		cout<<"2. Reportes"<<"\n";
		cout<<"3. Estadísticas "<<"\n";
		cout<<"4. Salir"<<"\n";
		do{cout<<" Opcion: "; cin>>opc;}
		while(opc<1 || opc>4);
		
		switch(opc)
		{
			case 1: system("cls");
			 for(i=0; i<n; i++)
					{
						system("cls");
						cout<<"\n Nombre de Funcionario: "; fflush(stdin);
						getline(cin,nombre[i]);
						
						auxnombre=nombre[i];
						for(j=0; j<auxnombre.length(); j++)
						{
							auxnombre[j]=toupper(auxnombre[j]);
						}
						nombre[i]=auxnombre;
						cout<<"\n";
						cout<<" OFICINA: "<<endl;
						cout<<" 1. Logística."<<endl;
						cout<<" 2. Recursos humanos."<<endl;
						cout<<" 3. Financiero."<<endl;
						do{cout<<" OPCION: "; cin>>ofti;
						}while(ofti<1 || ofti>3);
						OCT[i][0]=ofti;
						
						
						do{cout<<"\nCantidad de minutos de la llamada: "; cin>>OCT[i][1];
						}while(OCT[i][1]<0);
						
						switch (ofti) //Cantidad de llamadas por departamento y minutos acumulados por departamento.
						{
							case 1: logi++;
									minlogi+=OCT[i][1]; 
							break;
							case 2: re++;
									minre+=OCT[i][1]; 
							break;
							case 3: fi++;
									minfi+=OCT[i][1];
							break; 
						}
						
						cout<<"\nTIPO DE LLAMADA: "<<endl;
						cout<<" 1. Local."<<endl;
						cout<<" 2. Celular."<<endl;
						cout<<" 3. Internacional."<<endl;
						do{cout<<" OPCION: "; cin>>ofti;
						}while(ofti<1 || ofti>3);
						OCT[i][2]=ofti;
						
					}
					llenado=true;
					break;
			case 2: if(llenado)
					{
						system("cls");
						cout<<"\n CONSULTAS: "<<endl;
						cout<<" A. Consulta por Oficina."<<endl;
						cout<<" B. Consultas por tipo de llamada."<<endl;
						cout<<" C. Consultas llamadas por funcionario"<<endl;
						cout<<" D. Reporte de llamadas."<<endl;
						do{cout<<" Opcion: "; cin>>abc; abc=toupper(abc);
						}while(abc!='A' && abc!='B'&& abc!='C'&& abc!='D');
						switch(abc)
						{
							case 'A' :
								system("cls");
								cout<<"Ingrese el tipo de oficina (1: Logistica - 2: Recursos humanos - 3: Financiero)"<<"\n";
								do
								{
									cout<<"Opcion: "; cin>>ofti;
								}while(ofti<1 || ofti>3);
								
								system ("cls");
								switch(ofti)
								{
									case 1: 
										for (i=0; i<n; i++)
										{
											if ((OCT[i][0]-1) == 0)
											{
												cout<<setw(20)<<nombre[i]<<setw(6)<<OCT[i][1]<<setw(10)<<llamada[(OCT[i][2])-1]<<endl;
											}
										}
										system ("pause");
									break;
									case 2:
										for (i=0; i<n; i++)
										{
											if ((OCT[i][0]-1) == 1)
											{
												cout<<setw(20)<<nombre[i]<<setw(6)<<OCT[i][1]<<setw(10)<<llamada[(OCT[i][2])-1]<<endl;
											}
										}
										system ("pause");
									 break;
									case 3:
										for (i=0; i<n; i++)
										{
											if ((OCT[i][0]-1) == 2)
											{
												cout<<setw(20)<<nombre[i]<<setw(6)<<OCT[i][1]<<setw(10)<<llamada[(OCT[i][2])-1]<<endl;
											}
										}
										system ("pause");
								}
								break;
							
							case 'B':
								cout<<"Ingrese el tipo de llamada (1: Local - 2: Celular - 3: Internacional)"<<"\n";
								do
								{
									cout<<"Opcion: "; cin>>ofti;
								}while(ofti<1 || ofti>3);
								
								system("cls");
								switch (ofti)
								{
									case 1: 
									for (i=0; i<n; i++)
									{
										if ((OCT[i][2]-1) == 0)
										{
											cout<<setw(20)<<nombre[i]<<setw(10)<<oficina[(OCT[i][0])-1]<<endl;
										}	
									}
									system("pause");
									break;
									
									case 2: 
									for (i=0; i<n; i++)
									{
										if ((OCT[i][2]-1) == 1)
										{
											cout<<setw(20)<<nombre[i]<<setw(10)<<oficina[(OCT[i][0])-1]<<endl;
										}	
									}
									system("pause");
									break;
