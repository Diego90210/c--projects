#include <iostream>
#include <string.h>
using namespace std;

int main(){
	char cad[30];
	cout<<"Ingrese una cadena: ";
	cin.getline (cad, 30, '\n');
	
	if (strlen(cad) > 10){
		cout<<cad<<endl;
	}
	
}
