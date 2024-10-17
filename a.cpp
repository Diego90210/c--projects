#include <iostream>
using namespace std;

void wagstaff(int num_ramdom) {
    int potencia=0;
	int numdivisores=0;
	long long wagstaff=2;		
						
	for(int i=1; i<num_ramdom; i++){
		wagstaff=wagstaff*2;
	}
	potencia=wagstaff;
	wagstaff=(wagstaff+1)/3;
						
	for(int i=2; (i*i)<=wagstaff; i++){
		if((wagstaff%i==0) && (i!=wagstaff)){
			numdivisores++; 
		}
	}
	
	if (numdivisores>0){
		cout<<"El número NO "<<num_ramdom<<" es un primo de Wagstaff"<<endl;
	}
	else{
		cout<<"El número "<<num_ramdom<<" es un primo de Wagstaff"<<endl;
	}
	
}

int main() {
    int numero;
	
	cout<<"Ingrese un número: ";
	cin>>numero;
	wagstaff (numero);
}

