/*
Crear un vector de registro para n empleados (mínimo 3), se debe ingresar desde
teclado utilizando el nombre, las horas trabajadas, valor de la hora. la edad, el sueldo.
Sabiendo que cuando las horas de trabajo exceden de 40, el resto se considera horas
extras y que éstas se pagan al doble de una hora normal cuando no exceden de 8; si
las horas extras exceden de 8 se pagan las primeras 8 al doble de lo que se paga una
hora normal y el resto al triple.
Crear un menú con las siguientes opciones, definiendo una función para cada opción.
a) Ingresar datos: Ingresa los datos en el vector
b) Calcular: calcular el salario por concepto de horas extras, horas ordinarias
c) Consultar : Se debe visualizar el vector de registro ordenado
 ascendente por nombre y el total de la nómina cancelado por la empresa
 descendentemente por total horas extras con el promedio de horas extras
cancelado por la empresa
*/

#include <iostream>
#include <ctype.h>
using namespace std;

struct empleado
{
    char nombre[40];
    int horas_trabajadas;
    int vlr_hora;
    int edad;
    long sueldo;
}empleados[50];


int main(){
    bool sw = false;
    char op;
    do{
        cout<<"MENU"<<endl;
        cout<<"a) Ingresar datos"<<endl;
        cout<<"b) Calcular"<<endl;
        cout<<"c) Consultar"<<endl;
        cout<<"Ingrese su opcion: ";
        cin>>op;
        op = tolower(op);
    }while (op!='a' && op!='b' && op!='c');

    switch (op){
        case 'a': 
        break;
    

    }
    
}