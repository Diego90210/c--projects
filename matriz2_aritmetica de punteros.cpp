#include <iostream>
using namespace std;
void llenar(int *p, int *q)
{
	do{
		cout<<"Ingrese un numero";
		cin>>*p;
		p++;
	}while(p<=q);
}
void imprimir(int *p, int *q, int M)
{
	int col=1;
	do{
		cout<<"[" <<*p <<"]" ;
		p++;
		col++;//por cada número que se muestre incrementamos col para ir llevando la cuenta de las columnas
		//validamos si el valor de col es igual al ingresado para las columnas para realizar un salto de línea para mostrar la siguiente fila
		if(col == M)
		{
			col=1;
			cout<<endl;
		}
	}while(p<=q);
}
int main()
{
	int N, M;
	cout<<"Cantidad de filas: ";
	cin>>N;
	cout<<"Cantidad de columnas";
	cin>>M;
	int mat[N][M];
	int *p, *q, op;
	do{
		p = &mat[0][0];
		q= &mat[N-1][M-1];
		system("cls");
		cout<<"1. llenar " <<endl;
		cout<<"2. imprimir " <<endl;
		cout<<"3. exit" <<endl;
		cout<<"Seleccione una operacion: ";
		cin>>op;
		switch(op)
		{
			case 1:
				llenar(p, q); break;
			case 2: 
				imprimir(p, q, M);system("pause");
		}
	}while(op>=1 && op<=2);
}
