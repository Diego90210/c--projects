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
	
	string oficina[]={"Logistica","Recursos Humanos","financiero"};
    string llamada[]={"Local", "Celular","Internacional"};
	string nombre[n];
	string auxnombre;
	string nombremax;
	string m_denombre[3];
	bool llenado=false;
	int opc, ofti, tipofi, minlogi=0, minre=0, minfi=0, maxllamada=0, maxdepen, maxtipo, ofi;
	int logi=0, re=0, fi=0;
	int OCT[n][3], auxofi[n];
	int mayorlo=0, mayorce=0, mayori=0, m_local[3]={0,0,0};
	int v_local[3], v_celu[3], v_inter[3];
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
						do{cout<<" OPCION: "; cin>>ofi;
						}while(ofi<1 || ofi>3);
						OCT[i][0]=ofi;
						
						
						do{cout<<"\nCantidad de minutos de la llamada: "; cin>>OCT[i][1];
						}while(OCT[i][1]<0);
						
						switch (ofi) //Cantidad de llamadas por departamento y minutos acumulados por departamento.
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
						
						if (ofti == 1)
						{
							v_local[ofi-1]++;
							if (v_local[ofi-1]>m_local[0])
							{
								m_local[0]=v_local[ofi-1];
								m_denombre[0]=oficina[ofi-1];
							}
						}
						else
						{
							if(ofti==2)
							{
								v_celu[ofi-1]++;
								if (v_celu[ofi-1]>m_local[1])
								{
									m_local[1]=v_celu[ofi-1];
									m_denombre[1]=oficina[ofi-1];
								}
							}
							else
							{
								if(ofti==3)
								{
									v_inter[ofi-1]++;
									{
										if(v_inter[ofi-1]>m_local[2])
										{
											m_local[2]=v_inter[ofi-1];
											m_denombre[2]=oficina[ofi-1];
										}
									}
								}
							}
						}
						
						
						if (OCT[i][1] > maxllamada)
						{
							maxllamada = OCT[i][1]; //Duración.
							nombremax = nombre[i]; //Funcionario.
							maxdepen = OCT[i][0] ; //Dependencia.
							maxtipo = OCT[i][2] ; //Tipo de llamada.
						}
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
									
									case 3:
									for (i=0; i<n; i++)
									{
										if ((OCT[i][2]-1) == 2)
										{
											cout<<setw(20)<<nombre[i]<<setw(10)<<oficina[(OCT[i][0])-1]<<endl;
										}	
									}
									system("pause");
									break;
								}
								system("pause");
								cout<<"\nCantidad de llamadas logistica: "<<logi<<endl;
								cout<<"Cantidad de llamadas recursos humanos: "<<re<<endl;
								cout<<"Cantidad de llamadas financiero: "<<fi<<endl;
								cout<<"\nCantidad de minutos consumidos por logistica: "<<minlogi<<endl;
								cout<<"Cantidad de minutos consumidos por recursos humanos: "<<minre<<endl;
								cout<<"Cantidad de minutos consumidos por financiero: "<<minfi<<endl;
								break;
								//FALTA MONTO A PAGAR
							
							case 'C' :
								
								break;
							
							case 'D' :
								
								break;
						}
					}
					else{
						cout<<"\n\t ¡NO SE HA REALIZADO EL REGISTRO DE LLAMADAS!"<<endl;
					}
					break;
			case 3: 
					system("cls");
					cout<<"\nDependencias que realizaron el mayor numero de llamadas por tipo\n";
					cout<<"Local: "<<m_denombre[0]<<endl;
					cout<<"Celular: "<<m_denombre[1]<<endl;
					cout<<"Internacional: "<<m_denombre[2]<<endl;
					//FALTA EL MONTO A PAGAR.
					
					cout<<"\nLlamada de mayor duracion\n";
					cout<<"Funcionario: "<<nombremax<<endl;
					cout<<"Dependencia: "<<maxdepen<<endl;
					cout<<"Tipo de llamada: "<<maxtipo<<endl;
					cout<<"Tiempo de duracion: "<<maxllamada<<" minutos"<<endl;
					
					system("pause");
					break;
			case 4:
				break;
		}
	}while(opc!=4);
	
}
