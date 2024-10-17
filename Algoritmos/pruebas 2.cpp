#include<iostream>
using namespace std;
int main()
{
	cout<<"<<<PRIMOS PRIMOS>>"<<endl<<endl;
	
	int limite;
	int numero=2, numero2;
	bool primo;
			
	cout<<"Ingrese el limite a buscar: ";
	cin>>limite;
	
	while(numero<=limite)//Mientras que el numero a verificar sea menor o igual al limite propuesto
	{
		primo=true; //Asumimos de plano que el numero introducido es primo.
		for(int divisor=2; divisor<=numero/2; divisor++) //numero/2 porque el mayor divisor de un numero se encuentra entre 1 y la mitad de este.
		{
			if(numero%divisor==0) //Significa que el numero es divisible entre un numero que no es 1 y el mismo. No es Primo.
			{
				primo=false; //Si encontramos más de un divisor entonces asumimos que el numero no es primo.
				break; //Detenemos el ciclo si encontramos un que el numero no es primo.
			}
		}
		
		if(primo && (numero+4)<limite) //Si primo=true y el numero + 4 menor al numero introducido
		{
			primo=true; //El numero es primo.
			
			for(int divisor=2; divisor<=(numero+4)/2; divisor++) 
			{
				if((numero+4)%divisor==0)
				{
					primo=false;
					break;	
				}
			}
			if(primo)
			{
				cout<<endl<<numero<<" Y "<<numero+4<<" Son primos primos."<<endl;
			}
		}
		
		numero++;
	}
	
}
