#include <iostream>
using namespace std;

float tiempo (float vel1, float vel2, float dis);

int main(){
	float v1, v2, distancia;
	
	do{
		cout<<"Ingrese la velocidad del primer vehiculo: ";
		cin>>v1;
		cout<<"\nIngrese la velocidad del segundo vehiculo: ";
		cin>>v2;
	}while(v1>=v2);
	
	do{
		cout<<"\nIngrese la distancia que hay entre los vehiculos: ";
		cin>>distancia;
	}while(distancia<=0);
	
	cout<<"\nTiempo que toma el vehiculo 2 en alcanzar al primero: "<<tiempo (v1, v2, distancia);
	
}

float tiempo (float vel1, float vel2, float dis){
	float t_alcance;
	
	t_alcance=(dis/(vel1+vel2))*60;
	
	return t_alcance;
	
}
