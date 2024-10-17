#include <iostream>
#include <ctype.h>
#include <iomanip>
using namespace std;
int main()
{
	int n, i, j;
	
	cout<<"\n \t IM&EX S.A.\n\n";
	cout<<" TOTAL DE LLAMADAS REALIZADAS: "; cin>>n;
	
	string nombre[n],funcionario;
	string oficina[]={"Logistica","Recursos Humanos","Financiero"};
	string llamada[]={"Local", "Celular","Internacional"};
	string m_denombre[3];
	string nombremax;
	bool llenado=false,existente,k;
	int opc, ofti,min,aux, tipofi, minlogi=0, minre=0, minfi=0;
	int logi=0, re=0, fi=0, auxofi[n], ofi, maxllamada=0, maxdepen, maxtipo;
	int can_llamada[3], v_local[3], m_local[3]={0,0,0}, v_celu[3], v_inter[3];
	long total_llamada, gasto_llamada[3];
	int OCT[n][3];
	char abc;
	setlocale(LC_ALL,"spanish");
	do
	{ system("cls");
		cout<<"\n\tCONTROL DE LLAMADAS - CENTRO DE COMUNICACIONES\n\n"<<endl;
		cout<<"1. Registro de llamadas "<<endl;
		cout<<"2. Reportes"<<endl;
		cout<<"3. Estadisticas "<<endl;
		cout<<"4. Salir"<<endl;
		do{cout<<" Opcion: "; cin>>opc;}
		while(opc<1 || opc>4);
		
		switch(opc)
		{
			case 1: for(i=0; i<n; i++)
					{
						system("cls");
						cout<<"\n Nombre del Funcionario: "; fflush(stdin);
						getline(cin,nombre[i]);
						
						funcionario=nombre[i];
						for(j=0; j<funcionario.length(); j++)
						{
							funcionario[j]=toupper(funcionario[j]);
						}
						nombre[i]=funcionario;
						
						cout<<"\nOFICINA: "<<endl;
						cout<<" 1. Logistica."<<endl;
						cout<<" 2. Recursos humanos."<<endl;
						cout<<" 3. Financiero."<<endl;
						do{cout<<" OPCION: "; cin>>OCT[i][0];
						}while(OCT[i][0]<1 || OCT[i][0]>3);
						ofi = OCT[i][0];
						
						do{cout<<"\nCantidad de minutos de la llamada: "; cin>>OCT[i][1];
						}while(OCT[i][1]<0 or OCT[i][1]>30);
						
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
						
						cout<<"\nTIPO DE LLAMADA"<<endl;
						cout<<" 1. Local."<<endl;
						cout<<" 2. Celular."<<endl;
						cout<<" 3. Internacional."<<endl;
						do{cout<<" OPCION: "; cin>>OCT[i][2];
						}while(OCT[i][2]<1 || OCT[i][2]>3);
						ofti = OCT[i][2];
						
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
						cout<<"\n CONSULTAS: "<<endl;
						cout<<" A. Consulta por Oficina."<<endl;
						cout<<" B. Consultas por tipo de llamada."<<endl;
						cout<<" C. Consultas llamadas por funcionario"<<endl;
						cout<<" D. Reporte de llamadas."<<endl;
						do{cout<<" Opcion: "; cin>>abc; abc=toupper(abc);
						}while(abc!='A' && abc!='B'&& abc!='C'&& abc!='D');
						switch(abc)
						{
							case 'A' :system("cls");
								cout<<"\n OFICINA"<<endl;
								cout<<" 1. Logistica."<<endl;
								cout<<" 2. Recursos humanos."<<endl;
								cout<<" 3. Financiero."<<"\n";
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
								cout<<" 1. Local."<<endl;
								cout<<" 2. Celular."<<endl;
								cout<<" 3. Internacional."<<"\n";
								do
								{
									cout<<"Opcion: "; cin>>ofti;
								}while(ofti<1 || ofti>3);
								
								system("cls");
											cout<<setw(20)<<"NOMBRE"<<setw(10)<<"OFICINA"<<endl;
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
									system("pause");
									cout<<"\nCantidad de llamadas logistica: "<<logi<<endl;
									cout<<"Cantidad de llamadas recursos humanos: "<<re<<endl;
									cout<<"Cantidad de llamadas financiero: "<<fi<<endl;
									cout<<"\nCantidad de minutos consumidos por logistica: "<<minlogi<<endl;
									cout<<"Cantidad de minutos consumidos por recursos humanos: "<<minre<<endl;
									cout<<"Cantidad de minutos consumidos por financiero: "<<minfi<<endl;
									break;
								}
							case 'C' :  total_llamada=0; existente=false;
										cout<<" Nombre del funcionario: "; fflush(stdin);
										getline(cin,funcionario);
										for(i=0; i<funcionario.size(); i++)
										{
											funcionario[i]=toupper(funcionario[i]);
										}
										for(i=0; i<funcionario.size(); i++)
										{
											if(funcionario==nombre[i])
											{existente=true;}
										}
										if(existente)
										{
											cout<<" FUNCIONARIO: "<<funcionario<<endl;
											for(i=0; i<n; i++)
											{
												if(funcionario==nombre[i])
												{
													switch(OCT[i][2])
														{
															case 1: total_llamada+=(OCT[i][1]*80);	break;
															case 2: total_llamada+=(OCT[i][1]*800);	break;
															case 3: total_llamada+=(OCT[i][1]*1500); break;
														}
												}	
											}
												cout<<setw(20)<<"DEPENDENCIA"<<setw(15)<<"T. DE LLAMADA"<<setw(10)<<"MINUTOS"<<endl;
											for(i=0; i<n; i++)
											{
												if(funcionario==nombre[i])
												{
													cout<<setw(20)<<oficina[(OCT[i][0])-1]<<setw(15)<<llamada[(OCT[i][2])-1]<<setw(10)<<OCT[i][1]<<endl;
												}
											}
											cout<<" Total a pagar por llamadas: $"<<total_llamada<<endl;
										}
										else{cout<<"\n\t EL FUNCIONARIO NO ESTA REGISTRADO"<<endl;}
							
							case 'D' : total_llamada=0;
										cout<<setw(25)<<"DEPENDENCIA"<<setw(20)<<"FUNCIONARIO"<<setw(15)<<"T. DE LLAMADA"<<setw(10)<<"MINUTOS"<<endl;
										for(i=0; i<n; i++)
										{
											cout<<setw(20)<<oficina[(OCT[i][0])-1]<<setw(25)<<nombre[i]<<setw(15)<<llamada[(OCT[i][2])-1]<<setw(10)<<OCT[i][1]<<endl;
										}
										for(i=0; i<3; i++)
										{can_llamada[i]=0;}
										cout<<"\n\t MONTO A PAGAR POR DEPENDENCIAS: "<<endl;
										cout<<"\n OFICINA DE LOGISTICA: "<<endl;
									for(i=0; i<n; i++)
									{
										if(OCT[i][0]==1)
										{
											switch(OCT[i][2])
											{
												case 1: can_llamada[0]+=(OCT[i][1]);	break;
												case 2: can_llamada[1]+=(OCT[i][1]);	break;
												case 3: can_llamada[2]+=(OCT[i][1]);	break;
											}
										}
									}
									for(i=0; i<3; i++)
										{can_llamada[i]=0;}
									gasto_llamada[0]=(can_llamada[0]*80)+(can_llamada[1]*800)+(can_llamada[2]*1500);
									
										cout<<setw(10)<<"LOCAL"<<setw(10)<<"CELULAR"<<setw(15)<<"INTERNACIONAL"<<setw(10)<<"MONTO A PAGAR"<<endl;
										cout<<setw(10)<<can_llamada[0]<<setw(10)<<can_llamada[1]<<setw(15)<<can_llamada[2]<<setw(10)<<"$"<<gasto_llamada[0]<<endl;
										cout<<"\n OFICINA DE RECURSOS HUMANOS: "<<endl;
									for(i=0; i<3; i++)
										{can_llamada[i]=0;}
									for(i=0; i<n; i++)
									{
										if(OCT[i][0]==2)
										{
											switch(OCT[i][2])
											{
												case 1: can_llamada[0]+=(OCT[i][1]);	break;
												case 2: can_llamada[1]+=(OCT[i][1]);	break;
												case 3: can_llamada[2]+=(OCT[i][1]);	break;
											}
										}
									}
									gasto_llamada[1]=(can_llamada[0]*80)+(can_llamada[1]*800)+(can_llamada[2]*1500);
									
										cout<<setw(10)<<"LOCAL"<<setw(10)<<"CELULAR"<<setw(15)<<"INTERNACIONAL"<<setw(10)<<"MONTO A PAGAR"<<endl;
										cout<<setw(10)<<can_llamada[0]<<setw(10)<<can_llamada[1]<<setw(15)<<can_llamada[2]<<setw(10)<<"$"<<gasto_llamada[1]<<endl;
										cout<<"\n OFICINA FINANCIERA: "<<endl;
									for(i=0; i<n; i++)
									{
										if(OCT[i][0]==3)
										{
											switch(OCT[i][2])
											{
												case 1: can_llamada[0]+=(OCT[i][1]);	break;
												case 2: can_llamada[1]+=(OCT[i][1]);	break;
												case 3: can_llamada[2]+=(OCT[i][1]);	break;
											}
										}
									}
									gasto_llamada[2]=(can_llamada[0]*80)+(can_llamada[1]*800)+(can_llamada[2]*1500);
										cout<<setw(10)<<"LOCAL"<<setw(10)<<"CELULAR"<<setw(15)<<"INTERNACIONAL"<<setw(10)<<"MONTO A PAGAR"<<endl;
										cout<<setw(10)<<can_llamada[0]<<setw(10)<<can_llamada[1]<<setw(15)<<can_llamada[2]<<setw(10)<<"$"<<gasto_llamada[2]<<endl;		
						}
					}
					else{
						cout<<"\n\t Â¡NO SE HA REALIZADO EL REGISTRO DE LLAMADAS!"<<endl;
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
			case 4: exit; break;
		}
		system("pause");
	}while(opc!=4);
	
}
