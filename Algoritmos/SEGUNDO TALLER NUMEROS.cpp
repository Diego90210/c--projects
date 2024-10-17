/*INTEGRANTES:
DIEGO ANDRES MARTINEZ FLOREZ      0222120002
ROBERTO JUNIOR MARTINEZ PATERNINA 0222120018
EVARISTO JOSE FERIA PEREZ         0222120023
*/
#include <iostream>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include <math.h>
using namespace std;
int main()
{	system("color 70");
	int x,y,lim,opc,llenado=1,N,divisores=0,sumaP1=0,sumaP2=0;
	long long max=0, min=99999999999999999,f;
	float prom_compu=0,compuesto=0,primos=0,ingresados=0,adivinados=0,fermat=0,mersenne=0,germain=0,porprim=0;
	int pp,hola=0;
	char abc; 
	bool familia=true;
	do
	{   system("cls"); setlocale(LC_ALL,"Spanish");
		cout<<"\n\t CURIOSIDADES Y FAMILIARIDAD DE LOS MAGICOS NUMEROS PRIMOS\n"<<endl;
	
		cout<<" 1. NUMERO A ANALIZAR."<<endl;
		cout<<" 2. CURIOSIDADES DE LOS NUMEROS PRIMOS."<<endl;
		cout<<" 3. FAMILIARIDAD DE LOS NUMEROS PRIMOS."<<endl;
		cout<<" 4. LOS NUMEROS PRIMOS MAS FAMOSOS."<<endl;
		cout<<" 5. ESTADISTICAS."<<endl;
		cout<<" 6. SALIR."<<endl;
		do //Validacion de menu principal
		{	cout<<" OPCION: "; cin>>opc;
			if(opc<1 || opc>6) //Verifica que los valores introducidos esten dentro del rango permitido
			{Beep(1000,1000);} //Alarma para avisar que el valor ingresado no esta dentro del rango permitido
		}while(opc<1 || opc>6);
		
		switch(opc)
		{
			case 1 : cout<<"\n A. USUARIO."<<endl;
					   cout<<" B. MAQUINA."<<endl;
					 do //validacion de menu #1
					 {cout<<" OPCION: "; cin>>abc;
					 abc=toupper(abc); //Para asegurar que los caracteres introducidos siempre esten en mayuscula
					 }while(abc!='A' && abc!='B');
					 switch(abc) //Condicional para la opcion escogida
					 {              //Utilizar un numero ingresado por el usuario
					 	case 'A' : 	do{cout<<" INGRESE UN NUMERO MAYOR A UNO: "; cin>>N;} //Validacion de que el numero sea mayor a 1
					 				while(N<=1);
					 				ingresados++; //Contador para numeros ingresados
					 				llenado=0; //Centinela para verificar que se ha ingresado un numero
						 			cout<<"\n NUMERO INGRESADO: "<<N<<endl;
									 system("pause");
						 			break;
					 	
					 	case 'B' : 
						 		do
								{ 	system("color 70"); //limite mayor a uno a tener en cuenta para generar un numero aleatorio
									cout<<" INGRESE UN NUMERO MAYOR A UNO: "; cin>>lim;
									if(lim<=1)
									{Beep(500,600); system("color 04");}
								}while(lim<=1); //Validacion de que el numero sea mayor a 1
								lim+=1;
								x=1+rand()%(lim-1); //Numero aleatorio [1 es el limite inferior y (lim) el limite superior]
								N=x; //Variable para guardar el numero generado
								x*=10; /*Se le agrega el Numero 0 a la derecha del numero multiplicandolo por 10*/
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
												  //de la tabla del nueve se mostrara un mensaje diciendo que se equivoco
									{cout<<" RESULTADO INCORRECTO, REALIZAR NUEVAMENTE"<<endl;
									 Beep(700,600); system("color 04"); system("pause");}
						
								}while((x-y)%9!=0 || x-y<=0 || x-y>=82); /*Validacion de que la resta sea hecha por un producto de 9 y que se haya
																			usado un producto de 9 del rango deseado*/
								cout<<"\n ¡CORRECTO! ¡SIGUE ASI! \n"<<endl;
								cout<<" RESULTADO :"<<y<<endl; 
								cout<<" AHORA A LOS NUMEROS DE LA IZQUIERDA ("<<(y/10)<<") SUMELE EL ULTIMO DIGITO DE LA DERECHA ("<<y%10<<")"<<endl;
								//Ultima accion a realizar por el ususario
								do
								{   system("color 70");
									cout<<" RESPUESTA: "; cin>>y;
									if(N!=y) //En caso de ser un resultado incorrecto se mostrara un mensaje diciendo que se ha equivocado
									{cout<<" RESULTADO INCORRECTO, REALIZAR NUEVAMENTE"<<endl;
									 Beep(700,600); system("color 04"); //El Beep se activara cuando se haya equivocado y despues cambiara de color
									 system("pause");}
								}while(N!=y);
								if(N==y)
								{ system("cls"); /*El FOR se repetira una cantidad de i veces para borrar y mostrar
													creando un efecto de parpadeo, que tambian cambia el fondo de la pantalla*/
									for(int i=1; i<=8; i++)
									{ 	system("color 07"); Sleep(150); 
										cout<<"\n\t ¡HA ADIVINADO EL NUMERO!"<<endl;
										cout<<"\t RESPUESTA: "<<N<<endl; 
										system("color 70");Sleep(100); //El Sleep pausa momentaneamente el FOR para que pueda verse bien el mensaje
										Beep(700,100);  system("cls");
									}
									adivinados++; //Contador de numeros adivinados
								}
						break;}	llenado=0;/*Variable centinela para verificar que la opcion uno ha sido realizada previamente*/
						if(llenado==0)
						{   if(N>max) //Optener el numero mayor
							{max=N;}
							if(N<min) //Obtener el numero menor
							{min=N;}
							familia=true; //Asumimos que el numero es primo
       									 for(int divisor=2; divisor<=N/2; divisor++)
       									 {
       								     	if(N%divisor==0) 
       								     	{ //Si se encuentra otro divisor en el numero, entonces el valor de "familia" cambiara a false y se terminara el ciclo
       								         familia=false;
        							        break;
        							    	 }
      									  }
      									  if(familia) //Si familia es verdadero entonces el contador de numeros primos aumentara
      									  {primos++;}
      									  else{compuesto++;} //Caso contrario, el contador de numeros compuestos aumentara
      									 
      							familia=true; //Mersenne
       									 for(int divisor=2; divisor<=N/2; divisor++) //Primero se haya si el numero es primo
       									 {
       								     	if(N%divisor==0)
       								     	{
       								         familia=false;
        							        break;
        							    	 }
      									  }
						 			if(familia) 
						 			{
       									 for(int divisor=2; divisor<=((2*N)-1)/2; divisor++) /*Si  el numero (n) es primos, entonces se buscara si
																								2n-1 tambien es primo*/
       									 {
       								     	if(((2*N)-1)%divisor==0)
       								     	{
       								         familia=false;
        							        break;
        							    	 }
      									  }
      									  if(familia)
      									  {mersenne++;} //en caso de que n y n2-1 sean primos, la variable de mersena aumentará
      								}
      								
      							familia=true; //Germain
       									 for(int divisor=2; divisor<=N/2; divisor++) //primero se encuentra si n es primo
       									 {
       								     	if(N%divisor==0)
       								     	{
       								         familia=false;
        							        break;
        							    	 }
      									  }
      						
      							     if(familia)
      							     {	
       									 for(int divisor=2; divisor<=((2*N)+1)/2; divisor++) //si n es primo, despues se busca si 2n+1 tambien es primo
       									 {
       								     	if(((2*N)+1)%divisor==0)
       								     	{
       								         familia=false;
        							        break;
        							    	 }
      									  }
      									  if(familia) //si n y 2n+1 son primos, la variable de germain aumentara
      									  {germain++;}
									 }
									 
									  pp=0; //Variable iteradora para exponente
						           while(pp<=N/2) //Fermat
								   {familia=true;
       									 for(int divisor=2; divisor<=N/2; divisor++) //Se buscara si n es primo
       									 {
       								     	if(N%divisor==0)
       								     	{
       								         familia=false;
        							        break;
        							    	 }
      									  }
						 			if(familia) 
						 			{
       									 for(int divisor=2; divisor<=(pow(2,(pow(2,pp)))+1)/2; divisor++) //si n es primo, se buscara si 2^2^pp es igual a n
       									 { f=(pow(2,(pow(2,pp)))+1);
       								     	if(f%divisor==0)
       								     	{
       								         familia=false;
        							        break;
        							    	 }
      									  }
      									  if(familia)
      									  {fermat++; break;} //en caso de que 2^2^pp sea igual a n, el contador de fermat aumentara
									}
									else {break;}
									pp++;
									}
						}
									
					 			   
						break; 
													
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
												/*EL IF mostrara todos los primos encontrados entre 1 y N, un numero primo solo tiene 2 divisores*/
												if(divisores==2)
												{cout<<i<<"-";}
											}cout<<endl; Beep(700,500);
											system("pause"); break;
								
								case 'B' : /**/
											hola=0; //centinela para verificar que el numero se pueda descomponer
											if(N<=3) //validacion de que el numero sea mayor a 3 o un par mayor a 2
											{system("color 04");
											cout<<"\n "<<N<<" NO SE PUEDE DESCOMPONER EN NUMEROS";
											Beep(700,500); Sleep(500); system("color 70");}
											cout<<endl;
											if(N>3)
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
																el IF hara que se salga del FOR interno con un BREAK*/
															if(sumaP1+sumaP2==N)
															{break; }
															
														}
														if(sumaP1+sumaP2==N && sumaP1>=sumaP2)
														{ //MOSTRAR EL RESULTADO
															hola=1; //cambiar el valor de la variable centinela
															cout<<" DESCOMPISICION DE "<<N<<": "<<endl;
															cout<<" "<<sumaP1<<"+"<<sumaP2<<endl; Sleep(400);
														}
													}
												}
												if(hola==0) //Si la variable centinela continua con su valor original es porque no se encontro
															//2 primos por el cual sse pudiera descomponer el numero
												{cout<<"\n NO SE PUEDE DESCOMPONER EL NUMERO "<<N<<" EN NUMEROS PRIMOS"<<endl;}
											}
							} 
							
						}
						/*En caso de que "llenado" sea 1, significa que no se ha ingresado o generado un numero y no se realizara esta opcion*/
						else {cout<<" NO SE HA INGRESADO O GENERADO NINGUN NUMERO \n"<<endl; 
						}system("pause");break;
						
			case 3 : if(llenado==0)
					{cout<<"\n FAMILIARIDAD DE NUMEROS PRIMOS."<<endl;
					   cout<<" A. PRIMOS GEMELOS."<<endl;
					   cout<<" B. PRIMOS PRIMOS."<<endl;
					   cout<<" C. PRIMOS TRILLIZOS."<<endl;
					   cout<<" D. PRIMOS CUATRILLIZOS."<<endl;
					   cout<<" E. PRIMOS SEXTILLIZOS."<<endl;
					   do //validacion de menu #3
					 {cout<<" OPCION: "; cin>>abc;
					 abc=toupper(abc);
					 }while(abc!='A' && abc!='B' && abc!='C' && abc!='D' && abc!='E');
					 
					 switch(abc) 
					 {
					 	case 'A' : pp=1; hola=0; //centinela para verificar que el numero es primo e iterador para encontrar la familiaridad
						 			while(pp<=N) 
									{ familia=true;  
									 for(int divisor=2; divisor<=pp/2; divisor++) 
										{
											if(pp%divisor==0) 
											{
											  familia=false; break;
											}
										}
		
									 if(familia && (pp+2)<=N)
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
									 for(int divisor=2; divisor<=pp/2; divisor++) //numero/2 porque el mayor divisor de un numero se encuentra entre 1 y la mitad de este.
										{
											if(pp%divisor==0) //Significa que el numero es divisible entre un numero que no es 1 y el mismo. No es Primo.
											{
											  familia=false; //Si encontramos m�s de un divisor entonces asumimos que el numero no es primo.
											  break; //Detenemos el ciclo si encontramos un que el numero no es primo.
											}
										}
		
									 if(familia && (pp+4)<=N) //Si primo=true y el numero + 4 menor al numero introducido
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
					 	case 'C' :	pp=1; hola=0;
						 			while(pp<=N) //buscar la forma de trillizos (p,p+2,p+6)
									{ familia=true; 
									 for(int divisor=2; divisor<=pp/2; divisor++) //p
										{
											if(pp%divisor==0) 
											{
											  familia=false; break;
											}
										}
									if(familia && (pp+2)<=N) //p+2
									 {
										familia=true;
										for(int divisor=2; divisor<=(pp+2)/2; divisor++) 
										{
											if((pp+2)%divisor==0)
												{  familia=false;	break;	}
										}
									if(familia && (pp+6)<=N) //p+6
									{
										familia=true;
										for(int divisor=2; divisor<=(pp+6)/2; divisor++)
										{
											if((pp+6)%divisor==0)
											{	familia=false; break;}
										}
									}
									
										if(familia && (pp+6)<=N && (pp+2)<=N)
										{
											if(pp!=1)
											{cout<<endl<<" "<<pp<<", "<<pp+2<<" Y "<<pp+6<<" SON PRIMOS TRILLIZOS."<<endl;
											hola=1;}
									}
									}		
									pp++;
									}
									pp=1;
						 			while(pp<=N) //Buscar la forma de trillizos (p,p+4,p+6)
									{ familia=true; 
									 for(int divisor=2; divisor<=pp/2; divisor++) 
										{
											if(pp%divisor==0) 
											{
											  familia=false; break;
											}
										}
									if(familia && (pp+4)<=N)
									 {
										familia=true;
										for(int divisor=2; divisor<=(pp+4)/2; divisor++) 
										{
											if((pp+4)%divisor==0)
												{  familia=false;	break;	}
										}
									if(familia && (pp+6)<=N)
									{
										familia=true;
										for(int divisor=2; divisor<=(pp+6)/2; divisor++)
										{
											if((pp+6)%divisor==0)
											{	familia=false; break;}
										}
									}
									
										if(familia && (pp+6)<=N && (pp+4)<=N)
										{
											if(pp!=1)
											{cout<<endl<<" "<<pp<<", "<<pp+4<<" Y "<<pp+6<<" SON PRIMOS TRILLIZOS."<<endl;
												hola=1;}
									}
									}		
									pp++;
									}
									if(hola==0)
									{cout<<"\n LOS NUMEROS ENTRE 1 Y "<<N<<" NO POSEEN PRIMOS TRILLIZOS"<<endl;}
									break;
						case 'D' : 	pp=1; hola=0;
						 			while(pp<=N) //buscar la forma de Cuatrillizos (p,p+2,p+6,p+8)
									{ familia=true; 
									 for(int divisor=2; divisor<=pp/2; divisor++) //p
										{
											if(pp%divisor==0) 
											{
											  familia=false; break;
											}
										}
									if(familia && (pp+2)<=N) //p+2
									 {
										familia=true;
										for(int divisor=2; divisor<=(pp+2)/2; divisor++) 
										{
											if((pp+2)%divisor==0)
												{  familia=false;	break;	}
										}
									if(familia && (pp+6)<=N) //p+6
									{
										familia=true;
										for(int divisor=2; divisor<=(pp+6)/2; divisor++)
										{
											if((pp+6)%divisor==0)
											{	familia=false; break;}
										}
									}
									if(familia && (pp+8)<=N) //p+6
									{
										familia=true;
										for(int divisor=2; divisor<=(pp+8)/2; divisor++)
										{
											if((pp+8)%divisor==0)
											{	familia=false; break;}
										}
									}
									
										if(familia && (pp+6)<=N && (pp+2)<=N && (pp+8)<=N)
										{
											if(pp!=1)
											{cout<<endl<<" "<<pp<<", "<<pp+2<<", "<<pp+6<<" Y "<<pp+8<<" SON PRIMOS CUATRILLIZOS."<<endl;
											hola=1;}
									}
									}		
									pp++;
									}
									if(hola==0)
									{cout<<"\n LOS NUMEROS ENTRE 1 Y "<<N<<" NO POSEEN PRIMOS CUATRILLIZOS"<<endl;}
									break;
					 	case 'E' : pp=1; hola=0;
						 			while(pp<=N) 
									{ familia=true; 
									 for(int divisor=2; divisor<=pp/2; divisor++) //p
										{
											if(pp%divisor==0) 
											{
											  familia=false; break;
											}
										}
									if(familia && (pp+4)<=N) 
									 {
										familia=true;
										for(int divisor=2; divisor<=(pp+4)/2; divisor++) 
										{
											if((pp+4)%divisor==0)
												{  familia=false;	break;	}
										}
									if(familia && (pp+6)<=N) //p+6
									{
										familia=true;
										for(int divisor=2; divisor<=(pp+6)/2; divisor++)
										{
											if((pp+6)%divisor==0)
											{	familia=false; break;}
										}
									
									}
									
									if(familia && (pp+10)<=N) //p+6
									{
										familia=true;
										for(int divisor=2; divisor<=(pp+10)/2; divisor++)
										{
											if((pp+10)%divisor==0)
											{	familia=false; break;}
										}
									}
									if(familia && (pp+12)<=N) //p+6
									{
										familia=true;
										for(int divisor=2; divisor<=(pp+12)/2; divisor++)
										{
											if((pp+12)%divisor==0)
											{	familia=false; break;}
										}
									}
									if(familia && (pp+16)<=N) //p+6
									{
										familia=true;
										for(int divisor=2; divisor<=(pp+16)/2; divisor++)
										{
											if((pp+16)%divisor==0)
											{	familia=false; break;}
										}
									}	if(familia && (pp+6)<=N && (pp+4)<=N && (pp+10)<=N && (pp+12)<=N && (pp+16)<=N)
										{
											if(pp!=1)
											{cout<<endl<<" "<<pp<<", "<<pp+4<<", "<<pp+6<<", "<<pp+10<<", "<<pp+12<<", y "<<pp+16<<" SON PRIMOS SEXTILLIZOS."<<endl;
											hola=1;}                                                                               
										}
								}
									pp++;
									}
									if(hola==0)
									{cout<<"\n LOS NUMEROS ENTRE 1 Y "<<N<<" NO POSEEN PRIMOS SEXTILLIZOS"<<endl;}
									break;
					 }
					}
					else {cout<<" NO SE HA INGRESADO O GENERADO NINGUN NUMERO \n"<<endl; }system("pause");break;
			case 4 : if(llenado==0)
					{
						cout<<"\n A. PRIMOS DE FERMAT."<<endl;
					      cout<<" B. PRIMOS DE MERSENNE."<<endl;
					      cout<<" C. PRIMOS DE GERMAIN."<<endl;
					   do //validaci�n de menu #1
					 {cout<<" OPCION: "; cin>>abc;
					 abc=toupper(abc);
					 }while(abc!='A' && abc!='B' && abc!='C');
					 switch(abc)
					 {
					 	case 'A' : pp=0; //iterador del exponente n de 2^2^n
						           while(pp<=N/2)
								   {familia=true; 
       									 for(int divisor=2; divisor<=N/2; divisor++)
       									 {
       								     	if(N%divisor==0)
       								     	{
       								         familia=false;
        							        break;
        							    	 }
      									  }
						 			if(familia)
						 			{
       									 for(int divisor=2; divisor<=(pow(2,(pow(2,pp)))+1)/2; divisor++)
       									 { f=(pow(2,(pow(2,pp)))+1);
       								     	if(f%divisor==0)
       								     	{
       								         familia=false;
        							        break;
        							    	 }
      									  }
      									  if(familia) //Una ves enncontrado que 2^2^pp es igual a n se mostrara un mensaje
      									  {cout<<"\n "<<N<<" ES UN NUMERO PRIMO DE FERMAT"<<endl;}
      									  else {cout<<"\n "<<N<<" NO ES UN NUMERO PRIMO DE FERMAT"<<endl;} //caso contrario se dira que el numero no es un primo de fermat
      									  break;
									}
									else {cout<<"\n "<<N<<" NO ES UN NUMERO PRIMO"<<endl;break;} //si se encuentra que n no es primo se mostrara este mensaje
									pp++;
									}
									 break;
					 	case 'B' : familia=true;
       									 for(int divisor=2; divisor<=N/2; divisor++)
       									 {
       								     	if(N%divisor==0)
       								     	{
       								         familia=false;
        							        break;
        							    	 }
      									  }
						 			if(familia)
						 			{
       									 for(int divisor=2; divisor<=((2*N)-1)/2; divisor++)
       									 {
       								     	if(((2*N)-1)%divisor==0)
       								     	{
       								         familia=false;
        							        break;
        							    	 }
      									  }
      									  if(familia) //Se encuentra si n y 2n-1 son primos
      									  {cout<<"\n "<<N<<" Y "<<((2*N)-1)<<" (2n-1) SON NUMEROS PRIMOS DE MERSENNE"<<endl;} //en caso de serlo se mostrara el mensaje de que son primos de mersenne
      									  else {cout<<"\n "<<N<<" Y "<<((2*N)-1)<<" (2n-1) NO SON NUMEROS PRIMOS DE MERSENNE"<<endl;}//caso contrario se dira que no son
									}
									else {cout<<"\n "<<N<<" NO ES UN NUMERO PRIMO"<<endl;} //si n no es primo de evitara buscar 2n-1
									break;
						case 'C' :  familia=true;
       									 for(int divisor=2; divisor<=N/2; divisor++)
       									 {
       								     	if(N%divisor==0)
       								     	{
       								         familia=false;
        							        break;
        							    	 }
      									  }
      						
      							     if(familia)
      							     {	
       									 for(int divisor=2; divisor<=((2*N)+1)/2; divisor++)
       									 {
       								     	if(((2*N)+1)%divisor==0)
       								     	{
       								         familia=false;
        							        break;
        							    	 }
      									  }
      									  if(familia) //Se encuentra si n y 2n+1 son primos
      									  {cout<<"\n "<<N<<" Y "<<((2*N)+1)<<" (2n+1) SON NUMEROS PRIMOS DE GERMAIN."<<endl;} //en caso de serlo se mostrara el mensaje de que son primos de germain
      									  else {cout<<"\n "<<N<<" NO ES UN NUMERO PRIMO DE GERMAIN"<<endl;}//caso contrario se dira que no son
									 }
									 else {cout<<"\n "<<N<<" NO ES UN NUMERO PRIMO"<<endl;} //si n no es primo de evitara buscar 2n+1
      							     break;
      							     
									
					 }system("pause");	break;                                                        
						
					}
					else {cout<<"\n NO SE HA INGRESADO O GENERADO NINGUN NUMERO \n"<<endl; }system("pause");break;
			case 5 : cout<<endl;
					if(primos>0) //en caso de que el contador de primos no haya aumentado ni una sola vez, su valor se mantendra en 0
					{porprim=(primos*100)/(ingresados+adivinados);}//una vez que la variable  de primos haya aumentado, se hara la respectiva operacion para encontrar el porcentaje
					if(compuesto>0) //en caso de que el contador de compuesto no haya aumentado ni una sola vez, su valor se mantendra en 0
					{prom_compu=(compuesto)/(ingresados+adivinados);}//una vez que la variable  de compuesto haya aumentado, se hara la respectiva operacion para encontrar el promedio
					 cout<<" NUMEROS INGRESADOS: "<<ingresados<<endl;//mostrar la cantidad de numeros ingresados
					 cout<<" NUMEROS ADIVINADOS: "<<adivinados<<endl;//mostrar la cantidad de numeros adivinados
					 cout<<" PORCENTAJE DE NUMEROS PRIMOS: "<<porprim<<"%"<<endl;//mostrar el porcentaje de numeros primos
					 cout<<" PROMEDIO DE NUMEROS COMPUESTOS: "<<prom_compu<<endl;//mostrar El promedio de numeros compuestos
					 cout<<" NUMEROS DE FERMAT: "<<fermat<<endl; //mostrar la cantidad de numeros primos de fermat
					 cout<<" NUMEROS DE MERSENNE: "<<mersenne<<endl;//mostrar la cantidad de numeros primos de mersenne
					 cout<<" NUMEROS DE GERMAIN: "<<germain<<endl; //mostrar la cantidad de numeros primos de germain
					 cout<<" VALOR MAXIMO: "<<max<<endl;//mostrar el valor mayor ingresado
					 if(min==99999999999999999) //En caso de que no se haya ingresado ningun valor, se mostrara un mensaje diciendo que el valor minimo es 0 
					 {cout<<" VALOR MINIMO: 0"<<endl;}
					 else{cout<<" VALOR MINIMO: "<<min<<endl;}//Una vez que se haya ingresado por lo menos un numero, se mostrara el valor minimo ingresado
					 system("pause");	break;
			case 6 : //Unica opcion en donde el programa podra terminar
					 system("cls"); system("color 01"); 
					 cout<<" HA SALIDO DEL PROGRAMA "<<endl;
					 Beep(500,500);
					 system("pause"); return 0;	break; //return 0 para finalizar el programa
		
		}
	}while(opc!=6); //validacion para que el programa se siga repitiendo hasta que se ingrese el valor de 6
}
