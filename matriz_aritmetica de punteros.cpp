#include <iostream>
using namespace std;

int main()
{
	int N, M;
	cout<<"Cantidad de filas: ";
	cin>>N;
	cout<<"Cantidad de columnas";
	cin>>M;
	int mat[N][M];
	int *p;
	p = &mat[0][0];
	do{
		cout<<"Ingrese un numero";
		cin>>*p;
		p++;
	}while(p<=&mat[N-1][M-1]);
	p  = &mat[0][0];
	do{
		cout<<"[" <<*p <<"]" ;
		p++;
	}while(p<=&mat[N-1][M-1]);
}
