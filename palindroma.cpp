#include <iostream>
#include <string.h>
using namespace std;

bool palindroma (char *cad1){
	int largo = strlen (cad1);
	
	for(int i=0; i<largo/2; i++){
		if (cad1[i]!=cad1[largo-i-1]){ //[largo-i-1] inicia desde el final de la cadena.
			return false;
		}
	}
	return true;
}

int main(){
	char cad1 [20];
	cout<<"Ingrese una cadena: ";
	gets (cad1);
	if (palindroma(cad1)){
		cout<<cad1<<" es una palabra palindroma"<<endl;
	}
	else{
		cout<<cad1<<" no es una palabra palindroma"<<endl;
	}
	
}
