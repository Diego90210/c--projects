#include <iostream>
using namespace std;
int main(){
	long n, bandera=1, aux, suma=0, max=0, min=9999999;
	float porcentaje, num=0, harshad=0;
	cout<<"Numeros de Harshad"<<endl;
	do
	{
		suma=0;
		cout<<"\nIngrese un numero: ";
		cin>>n;
		
		if(n<=9)
		{
			cout<<"EL NUMERO DEBE SER MAYOR A 9";
			cout<<"\n";
		}
		else
		{
			aux=n;
			num++;
			while(aux>0)
			{
				suma+=(aux%10);
				aux/=10;
			}
			if (n%suma == 0)
			{
				harshad++;
				cout<<n<<" es un numero de Harshad"<<endl; 
				system("Pause");
				
				if(n>max)
				{
					max=n;
				}
				if(n<min)
				{
					min=n;
				}
			}
			else
			{
				cout<<n<<" NO es un numero de Harshad"<<endl;
				system("pause"); 
			}
			system("cls");
			do
			{
				cout<<"Desea ingresar otro numero ? [1: Si] - [0: No]: ";
				cin>>bandera;
			}while(bandera!=1 && bandera!=0);
		}
	}while(bandera==1);
	
	porcentaje = (harshad/num)*100;
	system("cls");
	cout<<"Cantidad de numeros ingresados: "<<num<<endl;
	cout<<"Cantidad de numeros de Harshad: "<<harshad<<endl;
	cout<<"El porcentaje de numeros de Harshad es : "<<porcentaje<<endl;
	cout<<"Mayor numero de Harshad introducido: "<<max<<endl;
	cout<<"Menor numero de Harshad introducido: "<<min<<endl;
	
	return 0;
}
