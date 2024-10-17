#include <iostream>
using namespace std;

long long potencia(int a, int b){
    int p=1;

    for (int i=1; i<=b; i++){
        p*=a;
    }
    return p;
}

long suma_digitos(int a){
    long sumatoria=0;

    do{
        sumatoria+=(a%10);
        a/=10;
    }while(a>0);

    return sumatoria;
}

long suma_divisores(int a){
    int divisores=0;
    for (int i=1; i<a; i++){
        if (a%i == 0){
            divisores+=i;
        }
    }
    return divisores;
}

int cant_digitos(int a){
    int contador=0;
    do{
        a%10;
        contador++;
        a/=10;
    }while(a>0);
    return contador;
}

int cant_divisores(int a){
    int divisores=0;
    for (int i=1; i<a; i++){
        if (a%i == 0){
            divisores++;
        }
    }
    return divisores;  
}

double raiz_cuadrada(double n){
    //Se utiliza el método de aproximación de raíces de Newton.
    double a = n;
    double b = 1;
    double error = 0.00001; //La presición del resultado.

    while ((a-b)>error){
        a = (a+b)/2;
        b = n/a;
    }
    return a;
}

long narcisista(int a){
    long sumatoria=0;
    int exp = cant_digitos(a);
    int digito;

    do{
        digito=a%10;
        sumatoria += potencia (digito, exp);
        a/=10;
    }while(a>0);

    return sumatoria;
}



