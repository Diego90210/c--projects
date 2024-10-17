#include <iostream>
using namespace std;

int validar (int a1, int a2);
void bisiesto (int b1, int b2, float &bi, float &nobi);

int main(){
	int ano1, ano2; 
	float bi=0, nobi=0;
	
	cout<<"Ingrese un año: "; 
	cin>>ano1;
	cout<<"Ingrese otro año (debe ser mayor al primero): ";
	cin>>ano2;
	
	ano2 = validar(ano1, ano2);
	
	bisiesto(ano1, ano2, bi, nobi);
	
	cout<<"\n\nNumero de años bisiestos: "<<bi;
	cout<<"\nNumero de años no bisiestos: "<<nobi;
	cout<<"\nPorcentaje de años bisiestos: "<<((bi/(ano2 - ano1)) * 100);
	cout<<"\nPorcentaje de años no bisiestos: "<<((nobi/(ano2 - ano1)) * 100);
}

int validar (int a1, int a2){ //Mejorable verificando que se introduzcan bien los años.
	do{
		if (a1>=a2){
			cout<<"\nEl segundo año debe ser mayor al primero.";
			cout<<"\nIngrese nuevamente el segundo año: "; 
			cin>>a2;
		}
		else{
			break;
		}
	}while(true);
	
	return a2;
}

void bisiesto (int b1, int b2, float &bi, float &nobi){
	for (int i=b1; i<=b2; i++){
		if ((i%4==0) or (i%400==0) && ((i%100)!=0)){
			cout<<"\n"<<i<<" es un año bisiesto.";
			bi++;
		}
		else{
			cout<<"\n"<<i<<" no es un año bisiesto.";
			nobi++;
		}
	}
}



