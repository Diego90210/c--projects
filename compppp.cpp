#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;



int main(){
	char cad1[20], cad2[20];
	int num1;
	float num2;
	cout<<"Ingrese una cadena: ";
	gets(cad1);
	
	cout<<"Ingrese otra cadena: ";
	gets(cad2);
	
	num1 = atoi(cad1);
	num2 = atof(cad2);
	
	cout<<"Suma: "<<(num1+num2)<<endl;
	
}
