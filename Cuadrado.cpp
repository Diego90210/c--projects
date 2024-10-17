/*Escriba una función llamada al_cuadrado() que calcule el cuadrado del valor que se le transmite y despliegue el resultado. 
La función deberá ser capaz de elevar al cuadrado números flotantes.*/
#include <iostream>
using namespace std;

void PedirDatos();
void al_cuadrado(float num);

float x;

int main(){
    PedirDatos();
    al_cuadrado(x);
}

void PedirDatos()
{
    cout<<"Digite un numero: ";
    cin>>x;
}

void al_cuadrado(float num){
    float cuadrado = num*num;
    cout<<"El cuadrado del numero es: "<<cuadrado;
}

