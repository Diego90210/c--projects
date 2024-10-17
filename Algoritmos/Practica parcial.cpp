#include <iostream>
using namespace std;
int main()
{
	int n, clasificacion, horas, pclasi;
	long basico, extra=0;
	
	do{
		cout<<"Ingrese el numero de vendedores: "; cin>>n;
	}while(n<=0);
	
	cout<<endl;
	for (int i=1; i<=n; i++){
		cout<<"Vendedor No."<<i<<endl;
		do
		{
			cout<<"Ingrese su clasificacion 1[Especializado] - 2[Entretenimiento]: "; cin>>clasificacion;
			cout<<"Ingrese las horas trabajadas: "; cin>>horas;
		}while(clasificacion<1 or clasificacion>2 or horas<=0);
		
		switch (clasificacion)
		{
			case 1: pclasi=20000;
			break;
			case 2: pclasi=15000;
		}
		
		if(horas<=40)
		{
			basico=pclasi*horas;
		}
		else
		{
			basico=pclasi*40;
			extra=(pclasi*(horas-40))*0.25;
		}
		system("cls");
		//cout<<""
	}
	
	
	
	
	
	
	
	
	
	
	return 0;
}
