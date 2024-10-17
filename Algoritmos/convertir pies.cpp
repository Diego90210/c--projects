#include <iostream>
#include <locale.h>
using namespace std;

int main()
{
	float pies, pulgadas, yardas, cent, metros;
	setlocale(LC_ALL,"spanish");
	cout<<"Ingrese el valor expresado en pies: ";
	cin>>pies;
	yardas = pies/3;
	pulgadas = pies*12;
	cent = 2.54*pulgadas;
	metros = cent/100;
	cout<<pies <<" Pies equivalen a: "<<endl;
	cout<<yardas <<" Yardas "<<endl;
	cout<<pulgadas <<" Pulgadas"<<endl;
	cout<<cent <<" Centímetros"<<endl;
	cout<<metros <<" Metros"<<endl;
}
