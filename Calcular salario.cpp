#include <iostream>
using namespace std;

void ausencias (int &ho, int &he);
long calcular_salario (int &ho, int &he, int vlr_hora);

int main(){
	int n, horas, vlr_hora, ho, he;
	long salario;
	do{
		cout<<"Cantidad de empleados: "<<endl;
		cin>>n;
	}while(n<=0);
	
	for (int i=1; i<=n; i++){
		cout<<"Horas trabajadas: "<<endl;
		cin>>horas;
		
		cout<<"Salario por hora: "<<endl;
		cin>>vlr_hora;
		
		if (horas>48){
			he = horas - 48;
			ho = horas - he;
		}
		else{
			he=0;
			ho=horas;
		}
		
		salario=calcular_salario (ho, he, vlr_hora);
		cout<<"El salario del empleado "<<i<<" es: "<<salario<<endl;
		cout<<"Horas reportadas: "<<ho;
		cout<<"Horas extras: "<<he;
	}
}

long calcular_salario (int &ho, int &he, int vlr_hora){
	ausencias (ho, he);
	return ho*vlr_hora + (he*vlr_hora)*1.75;
}

void ausencias (int &ho, int &he){
	int ha;
	cout<<"Horas de ausencia: ";
	cin>>ha;
	
	if (ha>=he){
		ha = ha - he;
		he = 0;
		ho = ho - ha;
	}
	else{
		he = he-ha;
	}
}

