/*
Desarrollar un programa que lea por teclado los elementos 
de dos matrices de enteros y crea otra matriz con la suma de las dos. 
Se usarán tres funciones.

Función leerMatriz que se usará dos veces para leer por teclado los datos de cada matriz.
Función sumarMatrices que realiza la suma de las dos matrices.
Función mostrarResultado que se usa tres veces para mostrar por pantalla las tres matrices.
*/

#include <iostream>
using namespace std;

void leerMatriz (int matriz[][2], int, int);
void mostrarResultado (int matriz[][2], int, int);
int sumarMatrices (int m1[][2], int, int, int m2[][2], int, int, int m3[][2], int, int);

int main(){
	const int filas=2, columnas=2;
	
	int m1[filas][columnas], m2[filas][columnas], m3[filas][columnas]={0};
	
	leerMatriz(m1, filas, columnas);
	mostrarResultado (m1, filas, columnas);
	
	leerMatriz(m2, filas, columnas);
	mostrarResultado (m2, filas, columnas);
	
	sumarMatrices (m1, filas, columnas, m2, filas, columnas, m3, filas, columnas);
	
	for (int i=0; i<filas; i++){
		for (int j=0; j<columnas; j++){
			cout<<m3[i][j]<<"  ";
		}
		cout<<"\n";
	}
	
	
}

void leerMatriz(int matriz[][2], int filas, int columnas){
	for (int i=0; i<filas; i++){
		for (int j=0; j<columnas; j++){
			cout<<"Digite un numero "<<"["<<i<<"]"<<"["<<j<<"]: ";
			cin>>matriz[i][j];
		}
	}
	cout<<"\n";
}

void mostrarResultado (int matriz[][2], int filas, int columnas){
	for (int i=0; i<filas; i++){
		for (int j=0; j<columnas; j++){
			cout<<matriz[i][j]<<"  ";
		}
		cout<<"\n";
	}
	system("pause");
}

int sumarMatrices (int m1[][2], int f1, int c1, int m2[][2], int f2, int c2, int m3[][2], int f3, int c3){
	for (int i=0; i<2; i++){
		for (int j=0; j<2; j++){
			m3[i][j] = m1[i][j] + m2[i][j];
		}
	}
}



