/*
Crear una función que convierta una cadena a mayúscula o minúscula según seleccione el usuario.
*/

#include <iostream>
using namespace std;

void mayus_minus (char *cad, int op){
	int i=0;
	if (op == 1){
		for (;cad[i]!='\0';){
			cad[i] = toupper (cad[i]);
			i++;
		}
	}
	else{
		for (;cad[i]!='\0';){
			cad[i] = tolower (cad[i]);
			i++;
		}
	}
}

int main(){
	char cad [100];
	int op;
	
	cout<<"Ingrese un cadena: ";
	gets(cad);
	
	do{
		cout<<"Convertir cadena a [1-Mayuscula] [2-Minuscula]: ";
		cin>>op;
	}while (op<1 or op>2);
	
	cout<<"Cadena normal: "<<cad<<endl;
	mayus_minus (cad, op);
	cout<<"Cadena actualizada: "<<cad<<endl;
}
