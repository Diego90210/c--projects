#include <iostream>
using namespace std;
int main()
{
	int numeros[3][3];
	int f, c;
	
	for (f=0; f<3; f++)
	{
		for(c=0; c<3; c++)
		{
			cout<<"Ingrese un numero: ";
			cin>>numeros[f][c];
		}
	}
	
	for (f=0; f<3; f++)
	{
		for(c=0; c<3; c++)
		{
			cout<<"["<<numeros[f][c]<<"]";
		}
		cout<<endl;
	}
	
	
	
	
	
	
	
	
	return 0;
}
