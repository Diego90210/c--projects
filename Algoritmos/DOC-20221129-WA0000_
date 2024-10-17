//ROBERTO JUNIOR MARTINEZ PATERNINA 	0222120018
//DIEGO ANDRES MARTINEZ FLOREZ			0222120002
#include <iostream>
#include <ctype.h>
#include <iomanip>
#include <windows.h>
using namespace std;
int main()
{	system("color 70");
	int n, i, j;
	
	cout<<"\n \t IM&EX S.A.\n\n";
	cout<<" TOTAL DE LLAMADAS REALIZADAS: "; cin>>n;
	
	string nombre[n],funcionario;
	string oficina[]={"Logistica","Recursos Humanos","Financiero"};
	string llamada[]={"Local", "Celular","Internacional"};
	string m_denombre[3];
	string nombremax,funmax,oficinamax;
	bool llenado=false,existente;
	int opc, ofti, minlogi=0, minre=0, minfi=0;
	int auxofi[n], ofi, maxllamada=0, maxdepen, maxtipo,fun,max=0;
	float can_llamada[3],logi=0, re=0, fi=0;
	int v_local[]={0,0,0}, m_local[]={0,0,0}, v_celu[]={0,0,0}, v_inter[]={0,0,0};
	long total_llamada, gasto_llamada[3],call[]={0,0,0},minutos[3];
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
			case 1: for(i=0; i<3; i++)
					{v_local[i]=0; m_local[i]=0; v_celu[i]=0; v_inter[i]=0;}
					max=0;//Mayor numero de llamadas
					for(i=0; i<n; i++)
					{	
						system("cls");
						cout<<"\n\t LLAMADA No."<<i+1<<endl;
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
									minlogi+=OCT[i][1]; //Acumulador de llamadas por departamento
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
							maxllamada = OCT[i][1]; //Duraci�n.
							nombremax = nombre[i]; //Funcionario.
							maxdepen = OCT[i][0] ; //Dependencia.
							maxtipo = OCT[i][2] ; //Tipo de llamada.
						}	
						
						fun=0;//contador de llamadas por funcionario
						for(j=i; j>=0; j--)
						{
							if(funcionario==nombre[j])	//encontrar si el funcionario ha realizado una llamda antes
							{fun++;}					//aumentar el contador si el funcionario ha hecho mas de uan llamda
							if(fun>max)					//si el numero de llamadas realizadas es mayor al registrador por cada funcionario 
							{	max=fun;				//Se le asignara como valor maxima la cantidad de llamas realizadas por el funcionario
								funmax=nombre[i];		//Se guardara el nombre del funcionario
								oficinamax=oficina[(OCT[i][0])-1];//Y la dependencia donde realizo la ultima llamada
							}
						}	
						
					}
					Sleep(700);
					llenado=true;//Variable centinela
					break;
			case 2: if(llenado)
					{ system("cls");
						cout<<"\n CONSULTAS: "<<endl;
						cout<<" A. Consulta por Oficina."<<endl;
						cout<<" B. Consultas por tipo de llamada."<<endl;
						cout<<" C. Consultas llamadas por funcionario"<<endl;
						cout<<" D. Reporte de llamadas."<<endl;
						do{cout<<" Opcion: "; cin>>abc; abc=toupper(abc);
						}while(abc!='A' && abc!='B'&& abc!='C'&& abc!='D');
						Sleep(500);
						switch(abc)
						{ 
							case 'A' :system("cls");
								cout<<"\n OFICINA"<<endl;
								cout<<" 1. Logistica."<<endl;
								cout<<" 2. Recursos humanos."<<endl;
								cout<<" 3. Financiero."<<"\n";
								do
								{cout<<"Opcion: "; cin>>ofti;
								}while(ofti<1 || ofti>3);
								Sleep(500);
								system ("cls");
								//Mostrar el reporte por oficina; funcionario, cantidad de minutos, y tipo de llamada
								cout<<setw(20)<<"NOMBRE"<<setw(15)<<"MINUTOS"<<setw(20)<<"T. LLAMADA"<<endl;
								
								switch(ofti)
								{
									case 1: 
										for (i=0; i<n; i++)
										{
											if ((OCT[i][0]-1) == 0)
											{cout<<setw(20)<<nombre[i]<<setw(15)<<OCT[i][1]<<setw(20)<<llamada[(OCT[i][2])-1]<<endl;}
										}
										system ("pause");
									break;
									case 2:
										for (i=0; i<n; i++)
										{
											if ((OCT[i][0]-1) == 1)
											{cout<<setw(20)<<nombre[i]<<setw(15)<<OCT[i][1]<<setw(20)<<llamada[(OCT[i][2])-1]<<endl;}
										}
										system ("pause");
									 break;
									case 3:
										for (i=0; i<n; i++)
										{
											if ((OCT[i][0]-1) == 2)
											{cout<<setw(20)<<nombre[i]<<setw(15)<<OCT[i][1]<<setw(20)<<llamada[(OCT[i][2])-1]<<endl;}
										}
										system ("pause");
								}
								break;
							
							case 'B': Sleep(500); system("cls"); 
								cout<<" 1. Local."<<endl;
								cout<<" 2. Celular."<<endl;
								cout<<" 3. Internacional."<<"\n";
								do
								{
									cout<<"Opcion: "; cin>>ofti;
								}while(ofti<1 || ofti>3);
								
								system("cls");
								//Mostar reporte por tipo de llamada; Funcionario y oficina
											cout<<setw(20)<<"NOMBRE"<<setw(20)<<"OFICINA"<<setw(15)<<"MINUTOS"<<endl;
								switch (ofti)
								{
									case 1: 
									for (i=0; i<n; i++)
									{
										if ((OCT[i][2]-1) == 0)
										{cout<<setw(20)<<nombre[i]<<setw(20)<<oficina[(OCT[i][0])-1]<<setw(15)<<OCT[i][1]<<endl;}	
									}
									system("pause");
									break;
									
									case 2: 
									for (i=0; i<n; i++)
									{
										if ((OCT[i][2]-1) == 1)
										{cout<<setw(20)<<nombre[i]<<setw(20)<<oficina[(OCT[i][0])-1]<<setw(15)<<OCT[i][1]<<endl;}	
									}
									system("pause");
									break;
									case 3: 
											for (i=0; i<n; i++)
											{
												if ((OCT[i][2]-1) == 2)
												{
													cout<<setw(20)<<nombre[i]<<setw(20)<<oficina[(OCT[i][0])-1]<<setw(15)<<OCT[i][1]<<endl;
												}	
											}
									break;
								} 
								for(i=0;i<3;i++)
								{call[i]=0;
								 gasto_llamada[i]=0;
								 can_llamada[i]=0; 
								}
								for(i=0; i<n; i++)
								{
									switch(OCT[i][0])
									{
										case 1: if(OCT[i][2]==ofti) 
										{		call[0]++; //Aumentar contador para el tipo de oficina
											 	can_llamada[0]+=OCT[i][1]; //Acumulador para minutos por oficina
												if(ofti==1 && OCT[i][2]==ofti) // if() para calcular el gasto de cada oficina de acuerdo al tipo de llamada
												{gasto_llamada[0]+=OCT[i][1]*80;}
												if(ofti==2)
												{gasto_llamada[0]+=OCT[i][1]*800;}
												if(ofti==3)
												{gasto_llamada[0]+=OCT[i][1]*1500;} 
										}
												break;
										case 2: if(OCT[i][2]==ofti)
										{		call[1]++; //Aumentar contador para el tipo de oficina
											 	can_llamada[1]+=OCT[i][1]; //Acumulador para minutos por oficina
												if(ofti==1 && OCT[i][2]==ofti) // if() para calcular el gasto de cada oficina de acuerdo al tipo de llamada
												{gasto_llamada[1]+=OCT[i][1]*80;}
												if(ofti==2)
												{gasto_llamada[1]+=OCT[i][1]*800;}
												if(ofti==3)
												{gasto_llamada[1]+=OCT[i][1]*1500;} 
										}
												break;
										case 3: if(OCT[i][2]==ofti)
										{		call[2]++; //Aumentar contador para el tipo de oficina
											 	can_llamada[2]+=OCT[i][1]; //Acumulador para minutos por oficina
												if(ofti==1 && OCT[i][2]==ofti) // if() para calcular el gasto de cada oficina de acuerdo al tipo de llamada
												{gasto_llamada[2]+=OCT[i][1]*80;}
												if(ofti==2)
												{gasto_llamada[2]+=OCT[i][1]*800;}
												if(ofti==3)
												{gasto_llamada[2]+=OCT[i][1]*1500;} 
										}
												break;
									}
								}
								//mostrar llamadas por oficina, cantidad de minutos por oficina, y monto a pagar de cada una según el tipo de llamada ya escogido
								cout<<"\n\t CANTIDAD DE LLAMADAS POR DEPENDENCIA SEGUN EL TIPO DE LLAMADA"<<endl;
									cout<<setw(30)<<"LOGISTICA"<<setw(20)<<"RECURSOS HUMANOS"<<setw(15)<<"FINANCIERO"<<endl;
									cout<<"Cant. Llamadas"<<setw(16)<<call[0]<<setw(20)<<call[1]<<setw(15)<<call[2]<<endl;
									cout<<"Cant. Minutos"<<setw(17)<<can_llamada[0]<<setw(20)<<can_llamada[1]<<setw(15)<<can_llamada[2]<<endl;
									cout<<"Monto a pagar"<<setw(17)<<gasto_llamada[0]<<setw(20)<<gasto_llamada[1]<<setw(15)<<gasto_llamada[2]<<endl;
									system("pause");
								
								
								
								break;
							case 'C' :  Sleep(500); system("cls");
										total_llamada=0; existente=false;
										cout<<" Nombre del funcionario: "; fflush(stdin);
										getline(cin,funcionario);//Leer el nombre del funcionario a buscar
										for(i=0; i<funcionario.size(); i++)//.size() y .length() cumplen la misma funcion de encontrar la longitud de una cadena de caracteres
										{
											funcionario[i]=toupper(funcionario[i]);//colocar el elemento i de la cadena en mayuscula
										}
										for(i=0; i<n; i++)
										{
											if(funcionario==nombre[i])//encontrar el nombre del funcionario
											{existente=true;}//usar una variable centinela para validar la existencia del funcionario
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
							case 'D' : Sleep(500); system("cls");
										total_llamada=0;
							//Mostrar Oficina, funcionario, tipo de llamadas y cantidad de minutos
										cout<<setw(25)<<"DEPENDENCIA"<<setw(20)<<"FUNCIONARIO"<<setw(15)<<"T. DE LLAMADA"<<setw(10)<<"MINUTOS"<<endl;
										for(i=0; i<n; i++)
										{
											cout<<setw(20)<<oficina[(OCT[i][0])-1]<<setw(25)<<nombre[i]<<setw(15)<<llamada[(OCT[i][2])-1]<<setw(10)<<OCT[i][1]<<endl;
										}
										
										for(i=0; i<3; i++)
										{can_llamada[i]=0;}//vaciar vector para usar nuevamente
										
										cout<<"\n\t MONTO A PAGAR POR DEPENDENCIAS: "<<endl;
										cout<<"\n OFICINA DE LOGISTICA: "<<endl;
									for(i=0; i<n; i++)
									{
										if(OCT[i][0]==1)
										{
											switch(OCT[i][2])
											{	//sumar la cantidad de minutos por tipo de llamada de la oficina de logistica
												case 1: can_llamada[0]+=(OCT[i][1]);	break;//minutos por local
												case 2: can_llamada[1]+=(OCT[i][1]);	break;//minutos por celular
												case 3: can_llamada[2]+=(OCT[i][1]);	break;//minutos por internacional
											}
										}
									}
										
									gasto_llamada[0]=(can_llamada[0]*80)+(can_llamada[1]*800)+(can_llamada[2]*1500);
									
									//mostrar cantidad de minutos por tipo de lllamada y total a pagar por oficina
										cout<<setw(10)<<"LOCAL"<<setw(10)<<"CELULAR"<<setw(15)<<"INTERNACIONAL"<<setw(10)<<"MONTO A PAGAR"<<endl;
										cout<<setw(10)<<can_llamada[0]<<setw(10)<<can_llamada[1]<<setw(15)<<can_llamada[2]<<setw(10)<<"$"<<gasto_llamada[0]<<endl;
										
										cout<<"\n OFICINA DE RECURSOS HUMANOS: "<<endl;
										
									for(i=0; i<3; i++)
										{can_llamada[i]=0;}//vaciar vector para usar nuevamente
										
									for(i=0; i<n; i++)
									{
										if(OCT[i][0]==2)
										{
											switch(OCT[i][2])
											{
												case 1: can_llamada[0]+=(OCT[i][1]);	break;//minutos por local
												case 2: can_llamada[1]+=(OCT[i][1]);	break;//minutos por celular
												case 3: can_llamada[2]+=(OCT[i][1]);	break;//minutos por internacional
											}
										}
									}
									gasto_llamada[1]=(can_llamada[0]*80)+(can_llamada[1]*800)+(can_llamada[2]*1500);
									
										cout<<setw(10)<<"LOCAL"<<setw(10)<<"CELULAR"<<setw(15)<<"INTERNACIONAL"<<setw(10)<<"MONTO A PAGAR"<<endl;
										cout<<setw(10)<<can_llamada[0]<<setw(10)<<can_llamada[1]<<setw(15)<<can_llamada[2]<<setw(10)<<"$"<<gasto_llamada[1]<<endl;
										
										cout<<"\n OFICINA FINANCIERA: "<<endl;
										
									for(i=0; i<3; i++)
										{can_llamada[i]=0;}//Vaciar vector para usar nuevamente
										
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
					else{cout<<"\n\t ¡NO SE HA REALIZADO EL REGISTRO DE LLAMADAS!"<<endl;}
					break;
			case 3:if(llenado)
					{ for(i=0; i<3; i++)
						{minutos[i]=0;}
						
					Sleep(500); system("cls");
					for(i=0; i<n; i++)
					{	if(m_denombre[0]==oficina[(OCT[i][0])-1]) //Encontrar el nombre de la oficina con mayor llamadas por tipo
						{minutos[0]+=OCT[i][1];} 
						if(m_denombre[1]==oficina[(OCT[i][0])-1])
						{minutos[1]+=OCT[i][1];}
						if(m_denombre[2]==oficina[(OCT[i][0])-1])
						{minutos[2]+=OCT[i][1];}
					}
					minutos[0]*=80; //Calcular el valor de cada tipo de llamada
					minutos[1]*=800;
					minutos[2]*=1500;
					//Mostrar estadisticas
					cout<<"\n\t Dependencias que realizaron el mayor numero de llamadas por tipo\n";
				cout<<setw(30)<<"LOCAL"<<setw(20)<<"CELULAR"<<setw(20)<<"INTERNACIONAL"<<endl;
	cout<<"OFICINA"<<setw(23)<<m_denombre[0]<<setw(20)<<m_denombre[1]<<setw(20)<<m_denombre[2]<<endl;
	cout<<"M. A PAGAR"<<setw(20)<<minutos[0]<<setw(20)<<minutos[1]<<setw(20)<<minutos[2]<<endl;

					cout<<"\n\tLLAMADA DE MAYOR DURACION\n";
					cout<<setw(20)<<"FUNCIONARIO"<<setw(20)<<"DEPENDENCIA"<<setw(15)<<"MINUTOS"<<setw(15)<<"T. LLAMADA"<<endl;
					cout<<setw(20)<<nombremax<<setw(20)<<oficina[maxdepen-1]<<setw(15)<<maxllamada<<setw(15)<<llamada[maxtipo-1]<<endl;
					
					for(i=0; i<3; i++)//Vaciar vectores para usar nuevamente
					{can_llamada[i]=0;gasto_llamada[i]=0; call[i]=0;}
					
					for(i=0; i<n; i++)
					{
						switch(OCT[i][2])//Encontrar la cantidad, monto a pagar y total de minutos de cada tipo de lllamada
						{
							case 1 : gasto_llamada[0]+=OCT[i][1]*80;//Monto a pagar
									 can_llamada[0]+=OCT[i][1]; //Minutos
									 call[0]++;					//Cantidad de llamadas
									 break;
							case 2 : gasto_llamada[1]+=OCT[i][1]*800; 
									 can_llamada[1]+=OCT[i][1];
									 call[1]++;
									 break;
							case 3 : gasto_llamada[2]+=OCT[i][1]*1500; 
									 can_llamada[2]+=OCT[i][1];
									 call[2]++;
									break;
						}
					}
					can_llamada[0]/=call[0]; //Promedio de Local
					can_llamada[1]/=call[1]; //Promedio de celular
					can_llamada[2]/=call[2]; //Promedio de internacional
					cout<<"\n\t MONTO A PAGAR Y PROMEDIO POR LLAMADAS"<<endl;
					cout<<setw(23)<<"LOCAL"<<setw(13)<<"CELULAR"<<setw(17)<<"INTERNACIONAL"<<endl;
 				 	cout<<"MONTO A PAGAR"<<setw(10)<<gasto_llamada[0]<<setw(13)<<gasto_llamada[1]<<setw(17)<<gasto_llamada[2]<<endl;
 				  	cout<<"PROMEDIO"<<setw(15)<<can_llamada[0]<<setw(13)<<can_llamada[1]<<setw(17)<<can_llamada[2]<<endl;
 				  	//Datos del funcionario con mayor numero de llamadas
 				  	cout<<"\n\t FUNCIONARIO CON MAYOR NUMERO DE LLAMADAS"<<endl;
 				  	cout<<setw(20)<<"NOMBRE"<<setw(20)<<"OFICINA"<<setw(20)<<"CANT. LLAMADAS"<<endl;
 				  	cout<<setw(20)<<funmax<<setw(20)<<oficinamax<<setw(15)<<max<<endl;
 				  	
					system("pause");
					}
					else
					{cout<<"\n\t ¡NO SE HA REALIZADO EL REGISTRO DE LLAMADAS!"<<endl;}
					break;
			case 4: exit; break;
		}
		system("pause");
	}while(opc!=4);
	
}