#include <iostream>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
using namespace std;
int main()
{	system("color 70");
	int x,y,lim,opc,llenado=1,N,divisores=0,sumaP1=0,sumaP2=0;
	int pp,hola=0; //Se usara para la familiaridad
	char abc; /*Se puede usar la misma variable para cada sub-opcion de las opciones del menu ya que esta 
	al ser ingresada de nuevo adopta el valor nuevo, esto sin afectar el programa y optimizandolo al usar menos espacio de memoria*/
	bool familia=true; //Se usará para la familiaridad
	do
	{   system("cls"); setlocale(LC_ALL,"Spanish");
		cout<<"\n\t CURIOSIDADES Y FAMILIARIDAD DE LOS MAGICOS NUMEROS PRIMOS\n"<<endl;
	
		cout<<" 1. NUMERO A ANALIZAR."<<endl;
		cout<<" 2. CURIOSIDADES DE LOS NUMEROS PRIMOS."<<endl;
		cout<<" 3. FAMILIARIDAD DE LOS NUMEROS PRIMOS."<<endl;
		cout<<" 4. LOS NUMEROS PRIMOS MAS FAMOSOS."<<endl;
		cout<<" 5. ESTADISTICAS."<<endl;
		cout<<" 6. SALIR."<<endl;
		do //Validación de menu
		{
			cout<<" OPCION: "; cin>>opc;
			if(opc<1 || opc>6)
			{Beep(1000,1000);}
		}while(opc<1 || opc>6);
		
		switch(opc)
		{
			case 1 : cout<<"\n A. USUARIO."<<endl;
					 cout<<" B. MAQUINA."<<endl;
					 do //validación de menu #1
					 {cout<<" OPCION: "; cin>>abc;
					 abc=toupper(abc);
					 }while(abc!='A' && abc!='B');
					 switch(abc)
					 {              //Utilizar un numero ingresado por el usuario
					 	case 'A' : 	do{cout<<" INGRESE EL NUMERO: "; cin>>N;}
					 				while(N<=0);
					 				llenado=0;
						 			cout<<"\n NUMERO INGRESADO: "<<N<<endl;
									 system("pause");
						 			break;
					 	
					 	case 'B' : 
						 		do
								{ 	system("color 70"); //limite mayor a uno a tener en cuenta para generar un numero aleatorio
									cout<<" INGRESE UN NUMERO MAYOR A UNO: "; cin>>lim;
									if(lim<=1)
									{Beep(500,600); system("color 04");}
								}while(lim<=1);
								lim+=1;
								x=1+rand()%(lim-1); //Numero aleatorio
								N=x; //Variable para guardar el numero generado
								x*=10; /*agregar un cero a la derecha del numero generado, por esta accion se debe guardar el valor generado
										en otra variable*/
								cout<<"\n "<<x; //mostrar numero con el 0 al final
								cout<<"\n A CONTINUACION, RESTE AL NUMERO ("<<x<<") UN NUMERO DE LA TABLA DEL 9\n"<<endl;
								cout<<" ---------------"<<endl;//mostrar tabla del 9
								cout<<" |  TABLA DEL 9 |"<<endl;
								cout<<" |--------------|"<<endl;
								cout<<" |  9x1  |  09  |"<<endl;
								cout<<" |--------------|"<<endl;
								cout<<" |  9x2  |  18  |"<<endl;
								cout<<" |--------------|"<<endl;
								cout<<" |  9x3  |  27  |"<<endl;
								cout<<" |--------------|"<<endl;
								cout<<" |  9x4  |  36  |"<<endl;
								cout<<" |--------------|"<<endl;
								cout<<" |  9x5  |  45  |"<<endl;
								cout<<" |--------------|"<<endl;
								cout<<" |  9x6  |  56  |"<<endl;
								cout<<" |--------------|"<<endl;
								cout<<" |  9x7  |  63  |"<<endl;
								cout<<" |--------------|"<<endl;
								cout<<" |  9x8  |  72  |"<<endl;
								cout<<" |--------------|"<<endl;
								cout<<" |  9x9  |  81  |"<<endl;
								cout<<"  --------------\n"<<endl;
								/*SOLO SE USAN PRODUCTOS DE 9 POSITIVOS Y MENORES O IGUALES A 81 PORQUE CON LOS DEMAS SE DEBE 
								  EMPLEAR UNA MECANICA DIFERENTE*/
								do
								{	system("color 70"); //ingresar resultado de la resta
									cout<<" RESULTADO DE LA RESTA: "; cin>>y;
									if((x-y)%9!=0)//en caso de ser una resta usada con un numero que no es producto
												  //de la tabla del nueve
									{cout<<" RESULTADO INCORRECTO, REALIZAR NUEVAMENTE"<<endl;
									 Beep(700,600); system("color 04"); system("pause");}
						
								}while((x-y)%9!=0 || x-y<=0 || x-y>=90);
								
								cout<<"\n Â¡CORRECTO! Â¡SIGUE ASI! \n"<<endl;
								cout<<" RESULTADO :"<<y<<endl; //Ultima accion a realizar por el ususario
								cout<<" AHORA A LOS NUMEROS DE LA IZQUIERDA ("<<(y/10)<<") SUMELE EL ULTIMO DIGITO DE LA DERECHA ("<<y%10<<")"<<endl;
								do
								{   system("color 70");
									cout<<" RESPUESTA: "; cin>>y;
									if(N!=y)
									{cout<<" RESULTADO INCORRECTO, REALIZAR NUEVAMENTE"<<endl;
									 Beep(700,600); system("color 04"); system("pause");}
								}while(N!=y);
								if(N==y)
								{ system("cls"); /*El FOR se repetira una cantidad de i veces para borrar y mostrar
													creando un efecto de parpadeo, que tambian cambia el fondo de la pantalla*/
									for(int i=1; i<=10; i++)
									{ 	system("color 07"); Sleep(150); 
										cout<<"\n\t Â¡HA ADIVINADO EL NUMERO!"<<endl;
										cout<<"\t RESPUESTA: "<<N<<endl; 
										system("color 70");Sleep(100); //El Sleep pausa momentaneamente el FOR para que pueda verse bien el mensaje
										Beep(700,100);  system("cls");
									}
								}
						break;}	llenado=0;	break; /*La variable "llenado" cambiara de 1 a 0 cuando se halla ingresado
													 o generado por maquina el numero a analizar*/
			case 2 :	if(llenado==0)/*Una vez que se haya ingresado o generado el numero se podra permitir realizar las otras opciones del menu*/
						{	
							cout<<"\n A. Entre un numero y su doble siempre, pero siempre encontraras al"<<endl;
							     cout<<" menos un numero primo."<<endl;
					 		  cout<<" B. Todos los numeros mayores que dos siempre se pueden"<<endl;
								 cout<<" descomponer en la suma de dos numeros primos."<<endl;
					 		do//Validacion de menu#2
							 	{cout<<" OPCION: "; cin>>abc;
					 			abc=toupper(abc);
					 			}while(abc!='A' && abc!='B');
					 		switch(abc)
							{
								case 'A' : 	cout<<"\n NUMEROS PRIMOS ENTRE 1 Y "<<N<<": \n"<<endl;
											/*El FOR buscara todos los numeros primos que estan 
											  entre 1 y N (la variable donde se guardo el numero ingresado o generado)
											*/
											for(int i=1; i<=N; i++)
											{ divisores=0;
												for(int k=1; k<=i; k++)
												{
													if(i%k==0)
													{divisores++;}
												}
												/*EL IF mostrara todos los primos encontrados entre 1 y N*/
												if(divisores==2)
												{cout<<i<<"-";}
											}cout<<endl; Beep(700,500);
											system("pause"); break;
								
								case 'B' : /*en caso de que el numero sea menor o igual a 3 no se descompondra en una suma de primos
											(Como el 1 no es un primo el 3 no se puede descomponer en dos primos)*/
											if(N<=3)
											{system("color 04");
											cout<<"\n "<<N<<" No se puesde descomponer en números primos";
											Beep(700,500); Sleep(500); system("color 70");}
											if(N>2)
											{	/*El primer FOR buscara un numero primo menor a N*/
												for(int i=1; i<=N; i++)
												{ divisores=0; sumaP1=0;
													for(int k=1; k<=i; k++)
													{
														if(i%k==0)
														{divisores++;}
													}
													if(divisores==2)
													{ //Variable donde se guarada el primer primo menor a N
														sumaP1+=i; 
														/*El segundo FOR iniciara despues de hallarse el primer primo menor a N
														  y este buscara el segundo numero primo (sumaP2) menor a N que se sumara con 
														  sumaP1 (primer numero primo encontrado)*/
														for(int j=1; j<=N; j++)
														{
															divisores=0; sumaP2=0;
															for(int l=1; l<=j; l++)
															{
																if(j%l==0)
																{divisores++;}
															}
															if(divisores==2)
															{
																sumaP2+=j;
															}/*Si se encuentran los numeros sumaP1 y sumaP2 que sumados sean igual a N
																el IF hara que se salga del FOR interno*/
															if(sumaP1+sumaP2==N)
															{	break;
															}
														}
														if(sumaP1+sumaP2==N)
														{ //MOSTRAR EL RESULTADO Y SALIR DEL PRIMER FOR CON BREAK
															cout<<"\n DESCOMPISICION DE "<<N<<": "<<endl;
															cout<<" "<<sumaP1<<"+"<<sumaP2<<endl; system("pause"); break;
														}
													}
												}
											}
							} 
						}/*En caso de que "llenado" sea 1, significa que no se ha ingresado o generado un numero y no se realizara esta opcion*/
						else {cout<<" NO SE HA INGRESADO O GENERADO NINGUN NUMERO \n"<<endl; 
						}system("pause");break;
			case 3 : if(llenado==0)
					{cout<<"\n FAMILIARIDAD DE NUMEROS PRIMOS."<<endl;
					   cout<<" A. PRIMOS GEMELOS."<<endl;
					   cout<<" B. PRIMOS PRIMOS."<<endl;
					   cout<<" C. PRIMOS CUATRILLIZOS."<<endl;
					   cout<<" D. PRIMOS SEXTILLIZOS."<<endl;
					   do //validación de menu #3
					 {cout<<" OPCION: "; cin>>abc;
					 abc=toupper(abc);
					 }while(abc!='A' && abc!='B' && abc!='C' && abc!='D');
					 
					 switch(abc)
					 {
					 	case 'A' : pp=1; hola=0;
						 			while(pp<=N)
									{ familia=true; 
									 for(int divisor=2; divisor<=pp/2; divisor++) 
										{
											if(pp%divisor==0) 
											{
											  familia=false; break;
											}
										}
		
									 if(familia && (pp+2)<N)
									 {
										familia=true;
										for(int divisor=2; divisor<=(pp+2)/2; divisor++) 
										{
											if((pp+2)%divisor==0)
												{  familia=false;	break;	}
										}
										if(familia)
										{
											if(pp!=1)
											{cout<<endl<<" "<<pp<<" Y "<<pp+2<<" SON PRIMOS GEMELOS."<<endl;
											 hola=1;}
										}
									}
									pp++;
									}
									if(hola==0)
									{cout<<"\n LOS NUMEROS ENTRE 1 Y "<<N<<" NO POSEEN PRIMOS GEMELOS"<<endl;}
					 				break;
					 	case 'B' :  pp=1; hola=0;
						 			while(pp<=N)//Mientras que el numero a verificar sea menor que el limite propuesto
									{ familia=true; //Asumimos de plano que el numero introducido es primo.
									 for(int divisor=2; divisor<=pp/2; divisor++) //pp/2 porque el mayor divisor de un numero se encuentra entre 1 y la mitad de este.
										{
											if(pp%divisor==0) //Significa que el numero es divisible entre un numero que no es 1 y el mismo. No es Primo.
											{
											  familia=false; //Si encontramos más de un divisor entonces asumimos que el numero no es primo.
											  break; //Detenemos el ciclo si encontramos que el numero tiene mas de dos divisores.
											}
										}
		
									 if(familia && (pp+4)<N) //Si familia=true y el numero + 4 menor al numero introducido
									 {
										familia=true; //El numero es primo.
										for(int divisor=2; divisor<=(pp+4)/2; divisor++) 
										{
											if((pp+4)%divisor==0)
												{  familia=false;  break;	}
										}
										if(familia)
										{	
											if(pp!=1)
											{cout<<endl<<" "<<pp<<" Y "<<pp+4<<" SON PRIMOS PRIMOS."<<endl; hola=1;}
										}
									}
									pp++;
									}
									if(hola==0)//EN CASO DE NO HABER NINGUN PRIMO PRIMO
									{cout<<"\n LOS NUMEROS ENTRE 1 Y "<<N<<" NO POSEEN PRIMOS PRIMOS"<<endl;}
					 				break;
					 	case 'C' :
					 				break;
					 	case 'D' :
					 				break;
					 }
					}
					else {cout<<" NO SE HA INGRESADO O GENERADO NINGUN NUMERO \n"<<endl; 
						}system("pause");break;
			case 4 :	break;
			case 5 :	break;
			case 6 : //Unica opcion en donde el programa podra terminar
					 system("cls"); system("color 04"); 
					 cout<<" HA SALIDO DEL PROGRAMA "<<endl;
					 Beep(500,500);
					 system("pause");	break;
		
		}
	}while(opc!=6);
}
