#include <iostream>
#include <locale.h>
using namespace std;

//Diego Andrés Martínez Florez: 0222120002.

int main(){
	
	string nombre;
	char op;
	long unidades[8], valoru, totalca, total_totalu;
	int i, j, centinela=1, min, aux, aux2, pos;
	float promedio, totalu, horas_encima=0;
	
	do
	{
		horas_encima=0;
		int indice[8]={1,2,3,4,5,6,7,8}; //Vector que guarda los indices para enumerar las horas.
		totalu=0; //Reinicia el total de las horas para evitar errores.
		system ("cls");
		fflush(stdin);
		
		cout<<"Ingrese el nombre del obrero: ";
		getline (cin, nombre);
		cout<<endl;
		
		for (i=0; i<8; i++) //Para introducir las unidades producidas en cada hora.
		{
			do
			{
				cout<<"Unidades producidas en la hora "<<i+1<<": ";
				cin>>unidades[i];
				
				if (unidades[i]>0) //Comprueba que el valor introducido no sea negativo, pues afecta la suma.
				{
					totalu+=unidades[i]; //Acumula las unidades producidas.
				}
			}while(unidades[i]<0); //Ciclo para evitar que se introduzcan valores negativos.
		}
		
		do
		{
			cout<<"\nIngrese el valor de la unidad: ";
			cin>>valoru;
		}while(valoru<=0); //Evita que se introduzcan valores iguales o menores a cero.
		
		totalca=totalu*valoru; //Total a cancelar por obrero.
		promedio = totalu/8;
		
		for(i=0; i<8; i++)
		{
			if(unidades[i]>promedio) //Verifica si las unidades producidas superan al promedio.
			{
				horas_encima++; //Horas en que la producción superó el promedio.
			}
		}
		
		system("cls");
		
		cout<<"\nREPORTE DE PAGO"<<endl;
		cout<<"Nombre del obrero: "<<nombre<<endl;
		cout<<"Total unidades producidas: "<<totalu<<endl;
		cout<<"Valor unidad: "<<valoru<<endl;
		cout<<"Total a cancelar: $"<<totalca<<endl;
		
		system("pause");
		system("cls");
		do
		{
			cout<<"Escoja un metodo para generar el reporte de produccion: "<<endl;
			cout<<"\nA) Seleccion directa"<<endl;
			cout<<"B) Ordenacion por burbuja"<<endl;
			cout<<"C) Ordenacion por insercion"<<endl;
			cout<<"\nOpcion: ";
			cin>>op;
			op = toupper (op);
		}while(op!='A' && op!='B' && op!='C'); //Evita que se introduzca un caracter diferente de los permitidos.
		
		switch(op) //Evalua la opcion escogida.
		{
			case 'A': //ordenacion por seleccion.
			{
				for (i=0; i<8; i++) //Recorre el arreglo.
				{
					min = i; //Encuentra el numero minimo.
					for (j=i+1; j<8; j++){ //Recorre desde la segunda posicion.
						if (unidades[j] < unidades[min]) //Si el numero de la derecha es menor al de la izquierda.
						{
							min=j; //Situamos el numero de la derecha como la posicion menor.
						}	
					}
					
					//Intercambio para ordenar las unidades producidas.
					aux = unidades[i]; 
					unidades[i] = unidades[min];
					unidades[min] = aux;
					
					//Intercambio para ordenar la hora en que se produjeron las unidades.
					aux2 = indice[i];	
					indice [i] = indice[min];
					indice[min] = aux2;
				}
					
			}break;
				
			case 'B': //ORDENACION POR BURBUJA.
			{
				for (i=0; i<7; i++) //Recorremos el arreglo hasta la penultima posicion.
				{
					for(j=i+1; j<8; j++) //Recorremos el arreglo una posicion siguiente a i.
					{
						if(unidades[j]>unidades[i]) //Si el elemento a la derecha es mayor al de la izquierda.
						{
							//Intercambio para ordenar las unidades producidas.
							aux = unidades[i];
							unidades[i] = unidades[j];
							unidades[j] = aux;
							//Intercambio para ordenar la hora en que se produjeron las unidades.
							aux2=indice[i];
							indice[i] = indice[j];
							indice [j] = aux2;
						}
					}
				}
				//Imprimimos el reporte.
				system("cls");
				cout<<"\n";
				cout<<"REPORTE DE PRODUCCION POR HORA"<<endl;
				for (i=0; i<8; i++)
				{
					cout<<" Produccion hora "<<indice[i]<<": "<<unidades[i]; 
					cout<<"\n";
				}
				cout<<"Promedio de produccion: "<<promedio<<endl;
				cout<<"Total de horas arriba del promedio: "<<horas_encima<<endl;
				system ("pause");
				system ("cls");	
			}break;
				
			case 'C': //Ordenacion por insercion.
			{
				for(i=0; i<8; i++) //Recorremos el arreglo.
				{
					pos=i; //Indice del arreglo.
					aux=unidades[i]; //Guardamos el numero que tenemos en la posicion "i" del arreglo.
					aux2=indice[i]; //Lo anterior aplicado al indice que indica las horas.
						
					while((pos>0) && (unidades[pos-1]>aux)) //Si el numero a la izquierda es mayor al numero actual.
					{
						//Realizamos el intercambio para ordenar las unidades y las horas en que fueron producidas.
						indice[pos] = indice[pos-1];
						unidades[pos] = unidades[pos-1];
						pos--;
					}
					//Actualizamos el numero a evaluar.
					unidades[pos]=aux; 
					indice[pos]=aux2;
				}
			}
			break;
		}
		
		system("cls");
		
		if (op!='B') 
		{
			//Imprimos el reporte de produccion por hora en forma descendente.
			cout<<"REPORTE DE PRODUCCION POR HORA"<<endl;
			for (i=7; i>=0; i--)
			{
				cout<<"Produccion hora "<<indice[i]<<": "<<unidades[i]; 
				cout<<"\n";
			}
			cout<<"Promedio de produccion: "<<promedio<<endl;
			cout<<"Total de horas arriba del promedio: "<<horas_encima<<endl;
			system("pause");
			system("cls");
		}
		
		do
		{
			cout<<"Desea registrar otro trabajador ? [1: Si] [0: No]: ";
			cin>>centinela;
		}while(centinela!=1 && centinela!=0); //Solo permite los valores 1 y 0.
		
	}while(centinela==1); //Ciclo controlado por la variable centinela. Repite el proceso para registrar a los trabajadores.
	
	 
	return 0;
}
