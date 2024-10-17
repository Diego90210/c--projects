/*
1. Cargar el arreglo
2. Imprimir el arreglo
3. Imprimir el arreglo de forma inversa
4. Imprimir los elementos ubicados en las posiciones pares
5. Ordenar de manera ascendente el arreglo 
6. Buscar un elemento del vector
7. Calcular estadísticas (Promedio, porcentajes de números ceros, pares e impares)
*/

#include <iostream>
using namespace std;

int menu ();
bool cargar (int vec[], int n);
void imprimir (int vec[], int n);
void inversa (int vec[], int n);
void pares (int vec[], int n);
void ascendente (int vec[], int n);
void buscar (int vec[], int n);
void estadisticas (int vec[],int n);
int main(){
	int n, op;
	bool sw=false;
	do{
		cout<<"Cantidad de elementos del arreglo: ";
		cin>>n;
	}while(n<=0);
	
	int vec[n];
	int *p;
	
	do{
		op = menu();
		
		switch (op){
			case 1: sw = cargar (vec, n);
			break;
			case 2: if(sw)
						imprimir (vec, n);
					else
						cout<<"Debe llenar el arreglo primero!"<<endl;
			break; 
			case 3: if(sw)
						inversa (vec, n);
					else
						cout<<"Debe llenar el arreglo primero!"<<endl;
			break;
			case 4: if(sw)
						pares (vec, n);
					else
						cout<<"Debe llenar el arreglo primero!"<<endl; 
			break;
			case 5: if(sw)
						ascendente (vec, n);
					else
						cout<<"Debe llenar el arreglo primero!"<<endl; 
			break;
			case 6: if(sw)
						buscar (vec, n);
					else
						cout<<"Debe llenar el arreglo primero!"<<endl; 
					break;
			case 7: if(sw)
						estadisticas (vec, n);
					else
						cout<<"Debe llenar el arreglo primero!"<<endl; 
					break;
			case 8: exit(0);
			
		}
		system("pause");
	}while (op);
	
}

int menu(){
	int op;
	do{
		system("cls");
		cout<<"menu operaciones en el arreglo" <<endl;
		cout<<"1. Cargar el arreglo" <<endl;
		cout<<"2. Imprimir el arreglo" <<endl;
		cout<<"3. Imprimir el arreglo de forma inversa" <<endl;
		cout<<"4. Imprimir los elementos ubicados en las posiciones pares" <<endl;
		cout<<"5. Ordenar de manera ascendente el arreglo " <<endl;
		cout<<"6. Buscar un elemento del vector" <<endl;
		cout<<"7. Calcular estadisticas (Promedio, porcentajes de numeros ceros, pares e impares)" <<endl;
		cout<<"8. Salir"<<endl;	
		cout<<"Seleccione una operacion: ";
		cin>>op;
	}while(op<1 or op>8);
	
	return op;
}

bool cargar (int vec[], int n){
	int *p;
	p = vec;

	for (int i=0; i<n; i++){
		cout<<"Ingrese un valor "<<"["<<i<<"]: ";
		cin>>*p;
		p++;
	}
	return true;
}

void imprimir (int vec[], int n){
	int *p;
	p = vec;

	for (int i=0; i<n; i++){
		cout<<"["<<i<<"]: "<<*p<<endl;
		p++;
	}
}

void inversa (int vec[], int n){
	int *p;
	p = &vec[n-1];

	for (int i=(n-1); i>=0; i--){
		cout<<"["<<i<<"]: "<<*p<<endl;
		p--;
	}
}

void pares (int vec[], int n){
	int *p;
	p = vec;
	
	for (int i=0; i<n; i+=2){
		cout<<"["<<i<<"]: "<<*p<<endl;
		p+=2;
	}
}

void ascendente (int vec[], int n){
	int *p, i, j, aux, min; //Selection sort.
	p = vec;

	for (i=0; i<(n-1); i++){ //No se itera hasta la ultima posicion, ya que esa estara ordenada al final.
		min=i; //Indice del menor valor del arreglo.
		for (j=i+1; j<n; j++){
			if (*(p+j)<*(p+min)){ //Comparamos los valores restantes a ver si alguno es menor al valor menor actual.
				min=j; //El nuevo valor se guarda en min.
			}
		}
		if (min!=i){ //Si el valor actual no esta en una posicion correcta lo cambiamos. 
			aux = *(p+i);
			*(p+i)=*(p+min);
			*(p+min)=aux;
		}
	}
	imprimir (vec, n);
}

void buscar (int vec[], int n){
	int buscar;
	cout<<"Ingrese el valor a buscar: ";
	cin>>buscar;
	int *p;
	bool encuentra = false;
	p=vec;

	for (int i=0; i<n; i++){
		if (*p == buscar){
			encuentra=true;
			break;
		}
		p++;
	}
	
	if (encuentra){
		cout<<"El numero "<<buscar<<" se encuentra en el arreglo."<<endl;
	}
	else{
		cout<<"El numero "<<buscar<<" no se encuentra en el arreglo."<<endl;
	}
}

void estadisticas (int vec[],int n){
	int *p; 
	float sum=0, ceros=0, pares=0, impares=0;
	p=vec;

	for (int i = 0; i < n; i++)
	{
		sum+=(*p);

		if ((*p)==0){
			ceros++;
		}

		if ((*p)%2 == 0){
			pares++;
		}
		else{
			impares++;
		}
		p++;
	}

	cout<<"Promedio de numeros: "<<(sum/n)<<endl;
	cout<<"Porcentaje de ceros: "<<((ceros/n)*100)<<endl;
	cout<<"Porcentaje de numeros pares "<<((pares/n)*100)<<endl;
	cout<<"Porcentaje de numeros impares "<<((impares/n)*100)<<endl;

}









