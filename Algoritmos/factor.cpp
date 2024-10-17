#include <iostream>
using namespace std;
int main(){
	int factorial=1, limite;
	
	cout<<"Ingrese el limite: ";
	cin>>limite;
	
	for (int i=1; i<=limite; i++)
	{
		factorial*=i;
		cout<<"\nEl factorial de "<<i<<" es: "<<factorial;
	}

	
	return 0;
}
