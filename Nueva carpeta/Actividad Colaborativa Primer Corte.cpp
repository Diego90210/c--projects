//Diego Andrés Martínez Florez: 0222120002.
//Roberto Junior Martínez Paternina: 0222120018.
//José David Torres Acevedo: 0222120038.

/*
Este programa permite al usuario seleccionar diferentes opciones y funciones para trabajar con números, 
utilizando recursividad en varias de ellas y con una estructura modular que permite 
una mayor eficiencia en el código. 

El programa contempla las siguientes funcionalidades:
1. Un menú con varias opciones.
2. Una biblioteca con funciones comunes y repetitivas para determinar los tipos de números.
3. Cada proceso se ha implementado en una función que reciba como parámetro el/los números(s) y retorna un resultado 
para validar que se cumple la condición en el main.
4. implementación de recursividad en varias funciones, incluyendo la conversión de binario a decimal, 
de decimal a binario, la suma de divisores y divisores propios, la suma de dígitos y la potencia.
5. El programa sólo podrá salir al seleccionar la opción correspondiente, 
por lo que cada vez que se ejecute una opción, se retorna al menú de inicio.
*/

#include <iostream>
#include "Libreria_taller.h"
#include <ctype.h>
#include <math.h>
using namespace std;

int main(){

    setlocale(LC_ALL, "spanish");
    char op;
    int option, num, num2;
    float opt;
    
    do{
        do{
            cout<<"A. LOS TERRIBLES"<<endl;
            cout<<"B. LOS ENVIDIADOS"<<endl;
            cout<<"C. LOS MÁS CERCANOS"<<endl;
            cout<<"D. SALIR"<<endl;
            cout<<"Ingrese una opcion: ";
            cin>>op;
            op = toupper (op);
        }while (op!= 'A' && op!= 'B' && op!= 'C' && op!= 'D');
        
        system ("cls");
        switch (op){
            case 'A':
            {
                do{
                    cout<<"Ingrese un número: ";
                    cin>>num;

                    if (num<0){
                        cout<<"El número debe ser mayor o igual a cero!"<<endl;
                    }
                }while(num<0);

                do{
                    cout<<"1. Número Malvado"<<endl;
                    cout<<"2. Número Odioso"<<endl;
                    cout<<"3. Número Ambicioso"<<endl;
                    cout<<"4. Número Curioso"<<endl;
                    cout<<"5. Número Infeliz"<<endl;
                    cout<<"Ingrese una opcion: ";
                    cin>>option;
                }while(option <1 or option>5); 
                
                switch (option){
                    case 1:
                        if (malvado(num)){
                            cout<<"El número "<<num<<" es malvado"<<endl;
                        }
                        else{
                            cout<<"El número "<<num<<" no es malvado"<<endl;
                        }
                    break;

                    case 2: 
                        if (odioso(num)){
                            cout<<"El número "<<num<<" es un número odioso"<<endl;
                        }
                        else{
                            cout<<"El número "<<num<<" no es un número odioso"<<endl;
                        }
                    break;
                    case 3:
                        if (ambicioso(num)){
                            cout<<"El número "<<num<<" es un número ambicioso"<<endl;
                        }
                        else{
                            cout<<"El número "<<num<<" no es un número ambicioso"<<endl;
                        }

                    break;
                    case 4:
                        if (curioso(num)){
                            cout<<"El número "<<num<<" es un número curioso"<<endl;
                        }
                        else{
                            cout<<"El número "<<num<<" no es un número curioso"<<endl;
                        }
                    break;
                    case 5:
                        if (feliz(num) == false){
                            cout<<"El número "<<num<<" es un número infeliz"<<endl;
                        }
                        else{
                            cout<<"El número "<<num<<" no es un número infeliz"<<endl;
                        }
                        
                    break;
                }
            }
            break;

            case 'B':
                system("cls");
                do{
                    cout<<"Ingrese un número: ";
                    cin>>num;
                    if (num<0){
                        cout<<"El número debe ser mayor o igual a cero!"<<endl;
                    }
                }while(num<0); 

                do{
                    cout<<"1. Número Feliz"<<endl;
                    cout<<"2. Número Perfecto"<<endl;
                    cout<<"3. Número Semiperfecto"<<endl;
                    cout<<"4. Número Poderoso"<<endl;
                    cout<<"5. Número Narcisista"<<endl;
                    cout<<"Ingrese una opcion: ";
                    cin>>option;
                }while(option <1 or option>5);

                switch (option){
                    case 1:
                        if (feliz(num)){
                            cout<<"El número "<<num<<" es un número feliz"<<endl;
                        }
                        else{
                            cout<<"El número "<<num<<" no es un número feliz"<<endl;
                        } 
                    break;
                    case 2:
                        if (perfecto(num)){
                            cout<<"El número "<<num<<" es un número perfecto"<<endl;
                        }
                        else{
                            cout<<"El número "<<num<<" no es un número perfecto"<<endl;
                        }
                    break;
                    case 3:
                        if (semi_perfecto(num)){
                            cout<<"El número "<<num<<" es un número semiperfecto"<<endl;
                        }
                        else{
                            cout<<"El número "<<num<<" no es un número semiperfecto"<<endl;
                        }
                    break;
                    case 4: 
                        if (poderoso(num)){
                            cout<<"El número "<<num<<" es un número poderoso"<<endl;
                        }
                        else{
                            cout<<"El número "<<num<<" no es un número poderoso"<<endl;
                        }
                    break;
                    case 5:
                        if (narcisista(num)){
                            cout<<"El número "<<num<<" es un número narcisista"<<endl;
                        }
                        else{
                            cout<<"El número "<<num<<" no es un número narcisista"<<endl;
                        }
                    break;
                }
            break;

            case 'C':

                do{
                    cout<<"1. Números Primos"<<endl;
                    cout<<"2. Números Coprimos"<<endl;
                    cout<<"3. Números Amigos"<<endl;
                    cout<<"4. Números novios o casi amigos"<<endl;
                    cout<<"5. Números Sociables"<<endl;
                    cout<<"Ingrese una opcion: ";
                    cin>>option;
                }while(option <1 or option>5);

                if (option!=5){
                    cout<<"Ingrese un número: ";
                    cin>>num;

                    cout<<"Ingrese otro número: ";
                    cin>>num2;
                }

                switch (option){
                    case 1: system("cls");
                        do{
                            cout<<"1. Primos Gemelos"<<endl;
                            cout<<"2. Primos Primos"<<endl;
                            cout<<"3. Primos sexy"<<endl;
                            cout<<"Ingrese una opción: ";
                            cin>>option;
                        }while(option<1 or option>3); 

                        if (option == 1){
                            if (primo_gemelos(num, num2)){
                                cout<<"Los números "<<num<<" y "<<num2<<" son primos gemelos"<<endl;
                            }
                            else{
                               cout<<"Los números "<<num<<" y "<<num2<<" no son primos gemelos"<<endl; 
                            }
                        }
                        else{
                            if (option == 2){
                                if (primos_primos (num, num2)){
                                    cout<<"Los números "<<num<<" y "<<num2<<" son primos primos"<<endl;
                                }
                                else{
                                    cout<<"Los números "<<num<<" y "<<num2<<" no son primos primos"<<endl; 
                                }
                            }
                            else{
                                if (primos_sexys (num, num2)){
                                    cout<<"Los números "<<num<<" y "<<num2<<" son primos sexys"<<endl;
                                }
                                else{
                                    cout<<"Los números "<<num<<" y "<<num2<<" no son primos sexys"<<endl; 
                                }
                            }
                        }
                    break;
                    case 2: 
                        if (coprimos (num, num2)){
                            cout<<"Los números "<<num<<" y "<<num2<<" son coprimos"<<endl;
                        }
                        else{
                            cout<<"Los números "<<num<<" y "<<num2<<" no son coprimos"<<endl; 
                        }
                    break;
                    case 3:
                        if (amigos (num, num2)){
                            cout<<"Los números "<<num<<" y "<<num2<<" son números amigos"<<endl;
                        }
                        else{
                            cout<<"Los números "<<num<<" y "<<num2<<" no son números amigos"<<endl; 
                        } 
                    break;
                    case 4:
                        if (novios (num, num2)){
                            cout<<"Los números "<<num<<" y "<<num2<<" son números novios"<<endl;
                        }
                        else{
                            cout<<"Los números "<<num<<" y "<<num2<<" no son números novios"<<endl; 
                        }
                    break;
                    case 5:
                        do{
                            cout<<"Ingrese un número: ";
                            cin>>num;
                            if (num<0){
                                cout<<"El número debe ser mayor o igual a cero!"<<endl;
                            }
                        }while(num<0);

                        if (sociables (num)){
                            cout<<"El número "<<num<<" es número sociable"<<endl;
                        }
                        else{
                            cout<<"El número "<<num<<" no es número sociable"<<endl;
                        }
                    break;
                }
            break;
            case 'D': exit(0);
        }
        system("pause");
        system("cls");
    }while (op!='D');
}
