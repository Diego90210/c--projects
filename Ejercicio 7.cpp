/*
Aplicando aritmética de punteros, 
desarrollar un programa que lea dos vectores. 
El primero, de M elementos, contendrá los códigos de los estudiantes que perdieron Cálculo integral. 
El segundo, de N elementos, contiene los códigos de los estudiantes que perdieron Programación Básica. 
Se debe crear e imprimir otro arreglo que contendrá los códigos de los estudiantes 
que perdieron tanto Cálculo integral como Programación. 
*/

#include <iostream>
using namespace std;

void leer (int vector1[], int m, int vector2[], int n){
    int *p, *q, i=0, contador=0, j=0;
    p = vector1;
    q = vector2;

    cout<<"Estudiantes que perdieron calculo integral"<<endl;
    for (i=0; i<m; i++){
        cout<<"Ingrese el codigo del estudiante No. "<<i+1<<": ";
        cin>>*(p+i);
    }

    cout<<"Estudiantes que perdieron Programacion basica"<<endl;
    for (i=0; i<n; i++){
        cout<<"Ingrese el codigo del estudiante No. "<<i+1<<": ";
        cin>>*(q+i);
    }

    for (i=0; i<m; i++){
        for (j=0; j<n; j++){
            if (*(p+i) == *(q+j)){
                contador++;
            }
        }
    }
    
    int ambos[contador], *r;
    r = ambos;

    for (i=0; i<m; i++){
        for (j=0; j<n; j++){
            if (*(p+i) == *(q+j)){
                *r = *(p+i);
                r++;
            }
        }
    }

    r = &ambos[0];

    cout<<"Estudiantes que perdieron ambas"<<endl;
    for (i=0; i<contador; i++){
        cout<<"Codigo: "<<*(r+i)<<endl;
    }

}


int main(){
    int m, n;
    cout<<"No. de estudiantes que perdieron calculo integral: ";
    cin>>m;
    cout<<"No. de estudiantes que perdieron programacion basica: ";
    cin>>n;
    int vector1[m], vector2[n];

    leer (vector1, m, vector2, n);
}