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
	string nombremax, funmax, oficinamax, maxdepen, maxtipo;
	bool llenado=false,existente,k;
	int opc, ofti,min,aux, tipofi, minlogi=0, minre=0, minfi=0;
	int auxofi[n], ofi, maxllamada=0, fun , max=0;
	float can_llamada[3],logi=0, re=0, fi=0;
	int v_local[3]={0,0,0}, m_local[3]={0,0,0}, v_celu[3]={0,0,0}, v_inter[3]={0,0,0};
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
					{	max=0;
						system("cls");
						cout<<"\n Nombre del Funcionario: "; fflush(stdin);
						getline(cin,nombre[i]);
						
						funcionario=nombre[i]; //Se usa una variable auxiliar para guardar el nombre
						for(j=0; j<funcionario.length(); j++)//se usa la funcion.lengh() para encontrar la longitud de la cadena
						{
							funcionario[j]=toupper(funcionario[j]);//Convierte el elemento i de la cadena en mayuscula
						}
						nombre[i]=funcionario;//Se cambia el contenido del vector que ahora llevara el nombre en mayuscula
						
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
							case 1: logi++;//Contador de llamadas por departamento
									minlogi+=OCT[i][1]; //Acumulador de minutos por departamento
							break;
							case 2: re++;//Contador de llamadas por departamento
									minre+=OCT[i][1]; //Acumulador de llamadas por departamento
							break;
							case 3: fi++;//Contador de llamadas por departamento
									minfi+=OCT[i][1];//Acumulador de llamadas por departamento
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
							v_local[ofi-1]++;//Cantidad de llamadas locales por dependencias
							if (v_local[ofi-1]>m_local[0])//Comparacion para encontrar La mayor cantidad de llamdas entre las dependencias
							{
								m_local[0]=v_local[ofi-1];
								m_denombre[0]=oficina[ofi-1];
							}
						}
						else
						{
							if(ofti==2)
							{
								v_celu[ofi-1]++;//Cantidad de llamadas celulares por dependencias
								if (v_celu[ofi-1]>m_local[1])//Comparacion para encontrar La mayor cantidad de llamdas entre las dependencias
								{
									m_local[1]=v_celu[ofi-1];
									m_denombre[1]=oficina[ofi-1];
								}
							}
							else
							{
								if(ofti==3)
								{
									v_inter[ofi-1]++;//Cantidad de llamadas internacionales por dependencias
									{
										if(v_inter[ofi-1]>m_local[2])//Comparacion para encontrar La mayor cantidad de llamdas entre las dependencias
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
							maxllamada = OCT[i][1]; //Duracion.
							nombremax = nombre[i]; //Funcionario.
							maxdepen = oficina[i]; //Dependencia.
							maxtipo = llamada[i]; //Tipo de llamada.
						}	
						fun=0; //contador de llamadas por funcionario
						for(j=i-1; j>=0; j--)
						{ fun++;
							if(funcionario==nombre[j])//encontrar si el funcionario ha realizado una llamda antes
							{fun++;}//aumentar el contador si el funcionario ha hecho mas de uan llamda
							if(fun>max)//si el numero de llamadas realizadas es mayor al registrador por cada funcionario 
							{	max=fun;//Se le asignara como valor maxima la cantidad de llamas realizadas por el funcionario
								funmax=nombre[i];//Se guardara el nombre del funcionario
								oficinamax=oficina[(OCT[i][0])-1];//Y la dependencia donde realizo la ultima llamada
							}
							
						}
					}
					
					llenado=true;//Variable centinela
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
								//Mostrar el reporte por oficina; funcionario, cantidad de minutos, y tipo de llamada
								cout<<setw(20)<<"NOMBRE"<<setw(6)<<"MINUTOS"<<setw(10)<<"T. LLAMADA"<<endl;
								
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
								
								//Mostar reporte por tipo de llamada; Funcionario y oficina
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
									//mostrar llamadas por oficina, y cantidad de minutos por oficina
									
									cout<<setw(30)<<"LOGISTICA"<<setw(20)<<"RECURSOS HUMANOS"<<setw(15)<<"FINANCIERO"<<endl;
									cout<<"Cant. Llamadas"<<setw(14)<<logi<<setw(15)<<re<<setw(15)<<fi<<endl;
									cout<<"Cant. Minutos"<<setw(15)<<minlogi<<setw(15)<<minre<<setw(15)<<minfi<<endl;
									
									break;
								} break;
							case 'C' :  total_llamada=0; existente=false;
										cout<<" Nombre del funcionario: "; fflush(stdin);
										getline(cin,funcionario);//Leer el nombre del funcionario a buscar
										for(i=0; i<funcionario.size(); i++)//.size() y .length() cumplen la misma funcion de encontrar la longitud de una cadena de caracteres
										{
											funcionario[i]=toupper(funcionario[i]);//colocar el elemento i de la cadena en mayuscula
										}
										for(i=0; i<funcionario.size(); i++)
										{
											if(funcionario==nombre[i])//encontrar el nombre del funcionario
											{existente=true; break;}//usar una variable centinela para validar la existencia del funcionario
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
															case 1: total_llamada+=(OCT[i][1]*80);	break;//Suma total del valor de global de las llamadas
															case 2: total_llamada+=(OCT[i][1]*800);	break;
															case 3: total_llamada+=(OCT[i][1]*1500); break;
														}
												}	
											}//Mostrar oficina, tipo de llamada, y cantidad de minutos
												cout<<setw(20)<<"DEPENDENCIA"<<setw(15)<<"T. DE LLAMADA"<<setw(10)<<"MINUTOS"<<endl;
											for(i=0; i<n; i++)
											{
												if(funcionario==nombre[i])//validar que solo sean las llamadas hechas por el funcionario
												{
													cout<<setw(20)<<oficina[(OCT[i][0])-1]<<setw(15)<<llamada[(OCT[i][2])-1]<<setw(10)<<OCT[i][1]<<endl;
												}
											}
											//mostrar total a pagar
											cout<<" Total a pagar por llamadas: $"<<total_llamada<<endl;
										}//Mostrar en caso de que el funcionario no exista
										else{cout<<"\n\t EL FUNCIONARIO NO ESTA REGISTRADO"<<endl;}
										break;
							case 'D' : total_llamada=0;
							//Mostrar Oficina, funcionario, tipo de llamadas y cantidad de minutos
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
											{	//sumar la cantidad de minutos por tipo de llamada de la oficina de logistica
												case 1: can_llamada[0]+=(OCT[i][1]);	break;
												case 2: can_llamada[1]+=(OCT[i][1]);	break;
												case 3: can_llamada[2]+=(OCT[i][1]);	break;
											}
										}
									}
									for(i=0; i<3; i++)
										{can_llamada[i]=0;}
									gasto_llamada[0]=(can_llamada[0]*80)+(can_llamada[1]*800)+(can_llamada[2]*1500);
									//mostrar cantidad de minutos por tipo de lllamada y total a pagar por oficina
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
										
									for(i=0; i<3; i++)
										{can_llamada[i]=0;}
										
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
						cout<<"\n\t NO SE HA REALIZADO EL REGISTRO DE LLAMADAS!"<<endl;
					}
					break;
			case 3:
					if(llenado)
					{
						system("cls");
						cout<<"\nDependencias que realizaron el mayor numero de llamadas por tipo\n";
						cout<<"Local: "<<m_denombre[0]<<endl;
						cout<<"Celular: "<<m_denombre[1]<<endl;
						cout<<"Internacional: "<<m_denombre[2]<<endl;
						cout<<"\nMonto a pagar de Dependencias que realizaron el mayor numero de llamadas por tipo\n";
						cout<<"Local: "<<m_local[0]*80<<endl;
						cout<<"Celular: "<<m_local[1]*800<<endl;
						cout<<"Internacional: "<<m_local[2]*1500<<endl;
						
						cout<<"\nLlamada de mayor duracion\n";
						cout<<"Funcionario: "<<nombremax<<endl;
						cout<<"Dependencia: "<<maxdepen<<endl;
						cout<<"Tipo de llamada: "<<maxtipo<<endl;
						cout<<"Tiempo de duracion: "<<maxllamada<<" minutos"<<endl;
						for(i=0; i<3; i++)
						{gasto_llamada[i]=0;}
						for(i=0; i<3; i++)
						{can_llamada[i]=0;}
						for(i=0; i<3; i++)
						{
							switch(OCT[i][2])
							{
								case 1 : gasto_llamada[0]+=OCT[i][1]*80;
										can_llamada[0]+=OCT[i][1];break;
								case 2 : gasto_llamada[1]+=OCT[i][1]*800; 
										can_llamada[0]+=OCT[i][1];break;
								case 3 : gasto_llamada[2]+=OCT[i][1]*150; 
										can_llamada[0]+=OCT[i][1];break;
							}
						}
						can_llamada[0]/=logi;
						can_llamada[1]/=re;
						can_llamada[2]/=fi;
						cout<<"\n\t MONTO A PAGAR Y PROMEDIO POR LLAMADAS\n";
						cout<<setw(23)<<"LOCAL"<<setw(15)<<"CELULAR"<<setw(20)<<"INTERNACIONAL"<<endl;
	 				 	cout<<"MONTO A PAGAR"<<setw(10)<<gasto_llamada[0]<<setw(15)<<gasto_llamada[1]<<setw(15)<<gasto_llamada[2]<<endl;
	 				  	cout<<"PROMEDIO"<<setw(15)<<can_llamada[0]<<setw(15)<<can_llamada[1]<<setw(15)<<can_llamada[2]<<endl;
	 				  	
	 				  	cout<<"\n\t FUNCIONARIO CON MAYOR NUMERO DE LLAMADAS"<<endl;
	 				  	cout<<setw(20)<<"NOMBRE"<<setw(20)<<"OFICINA"<<setw(20)<<"CANT. LLAMADAS"<<endl;
	 				  	cout<<setw(20)<<nombremax<<setw(20)<<oficinamax<<setw(15)<<max<<endl; 
	 				  	
						system("pause");
						break;
					}
					else
					{
						cout<<"\n\t NO SE HA REALIZADO EL REGISTRO DE LLAMADAS!"<<endl;
					}
					break;
			case 4: exit; break;
		}
		system("pause");
	}while(opc!=4);
	
}
