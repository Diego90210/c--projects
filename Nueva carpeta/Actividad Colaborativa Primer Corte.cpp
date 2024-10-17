//Diego Andr�s Mart�nez Florez: 0222120002.
//Roberto Junior Mart�nez Paternina: 0222120018.
//Jos� David Torres Acevedo: 0222120038.

/*
Este programa permite al usuario seleccionar diferentes opciones y funciones para trabajar con n�meros, 
utilizando recursividad en varias de ellas y con una estructura modular que permite 
una mayor eficiencia en el c�digo. 

El programa contempla las siguientes funcionalidades:
1. Un men� con varias opciones.
2. Una biblioteca con funciones comunes y repetitivas para determinar los tipos de n�meros.
3. Cada proceso se ha implementado en una funci�n que reciba como par�metro el/los n�meros(s) y retorna un resultado 
para validar que se cumple la condici�n en el main.
4. implementaci�n de recursividad en varias funciones, incluyendo la conversi�n de binario a decimal, 
de decimal a binario, la suma de divisores y divisores propios, la suma de d�gitos y la potencia.
5. El programa s�lo podr� salir al seleccionar la opci�n correspondiente, 
por lo que cada vez que se ejecute una opci�n, se retorna al men� de inicio.
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
            cout<<"C. LOS M�S CERCANOS"<<endl;
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
                    cout<<"Ingrese un n�mero: ";
                    cin>>num;

                    if (num<0){
                        cout<<"El n�mero debe ser mayor o igual a cero!"<<endl;
                    }
                }while(num<0);

                do{
                    cout<<"1. N�mero Malvado"<<endl;
                    cout<<"2. N�mero Odioso"<<endl;
                    cout<<"3. N�mero Ambicioso"<<endl;
                    cout<<"4. N�mero Curioso"<<endl;
                    cout<<"5. N�mero Infeliz"<<endl;
                    cout<<"Ingrese una opcion: ";
                    cin>>option;
                }while(option <1 or option>5); 
                
                switch (option){
                    case 1:
                        if (malvado(num)){
                            cout<<"El n�mero "<<num<<" es malvado"<<endl;
                        }
                        else{
                            cout<<"El n�mero "<<num<<" no es malvado"<<endl;
                        }
                    break;

                    case 2: 
                        if (odioso(num)){
                            cout<<"El n�mero "<<num<<" es un n�mero odioso"<<endl;
                        }
                        else{
                            cout<<"El n�mero "<<num<<" no es un n�mero odioso"<<endl;
                        }
                    break;
                    case 3:
                        if (ambicioso(num)){
                            cout<<"El n�mero "<<num<<" es un n�mero ambicioso"<<endl;
                        }
                        else{
                            cout<<"El n�mero "<<num<<" no es un n�mero ambicioso"<<endl;
                        }

                    break;
                    case 4:
                        if (curioso(num)){
                            cout<<"El n�mero "<<num<<" es un n�mero curioso"<<endl;
                        }
                        else{
                            cout<<"El n�mero "<<num<<" no es un n�mero curioso"<<endl;
                        }
                    break;
                    case 5:
                        if (feliz(num) == false){
                            cout<<"El n�mero "<<num<<" es un n�mero infeliz"<<endl;
                        }
                        else{
                            cout<<"El n�mero "<<num<<" no es un n�mero infeliz"<<endl;
                        }
                        
                    break;
                }
            }
            break;

            case 'B':
                system("cls");
                do{
                    cout<<"Ingrese un n�mero: ";
                    cin>>num;
                    if (num<0){
                        cout<<"El n�mero debe ser mayor o igual a cero!"<<endl;
                    }
                }while(num<0); 

                do{
                    cout<<"1. N�mero Feliz"<<endl;
                    cout<<"2. N�mero Perfecto"<<endl;
                    cout<<"3. N�mero Semiperfecto"<<endl;
                    cout<<"4. N�mero Poderoso"<<endl;
                    cout<<"5. N�mero Narcisista"<<endl;
                    cout<<"Ingrese una opcion: ";
                    cin>>option;
                }while(option <1 or option>5);

                switch (option){
                    case 1:
                        if (feliz(num)){
                            cout<<"El n�mero "<<num<<" es un n�mero feliz"<<endl;
                        }
                        else{
                            cout<<"El n�mero "<<num<<" no es un n�mero feliz"<<endl;
                        } 
                    break;
                    case 2:
                        if (perfecto(num)){
                            cout<<"El n�mero "<<num<<" es un n�mero perfecto"<<endl;
                        }
                        else{
                            cout<<"El n�mero "<<num<<" no es un n�mero perfecto"<<endl;
                        }
                    break;
                    case 3:
                        if (semi_perfecto(num)){
                            cout<<"El n�mero "<<num<<" es un n�mero semiperfecto"<<endl;
                        }
                        else{
                            cout<<"El n�mero "<<num<<" no es un n�mero semiperfecto"<<endl;
                        }
                    break;
                    case 4: 
                        if (poderoso(num)){
                            cout<<"El n�mero "<<num<<" es un n�mero poderoso"<<endl;
                        }
                        else{
                            cout<<"El n�mero "<<num<<" no es un n�mero poderoso"<<endl;
                        }
                    break;
                    case 5:
                        if (narcisista(num)){
                            cout<<"El n�mero "<<num<<" es un n�mero narcisista"<<endl;
                        }
                        else{
                            cout<<"El n�mero "<<num<<" no es un n�mero narcisista"<<endl;
                        }
                    break;
                }
            break;

            case 'C':

                do{
                    cout<<"1. N�meros Primos"<<endl;
                    cout<<"2. N�meros Coprimos"<<endl;
                    cout<<"3. N�meros Amigos"<<endl;
                    cout<<"4. N�meros novios o casi amigos"<<endl;
                    cout<<"5. N�meros Sociables"<<endl;
                    cout<<"Ingrese una opcion: ";
                    cin>>option;
                }while(option <1 or option>5);

                if (option!=5){
                    cout<<"Ingrese un n�mero: ";
                    cin>>num;

                    cout<<"Ingrese otro n�mero: ";
                    cin>>num2;
                }

                switch (option){
                    case 1: system("cls");
                        do{
                            cout<<"1. Primos Gemelos"<<endl;
                            cout<<"2. Primos Primos"<<endl;
                            cout<<"3. Primos sexy"<<endl;
                            cout<<"Ingrese una opci�n: ";
                            cin>>option;
                        }while(option<1 or option>3); 

                        if (option == 1){
                            if (primo_gemelos(num, num2)){
                                cout<<"Los n�meros "<<num<<" y "<<num2<<" son primos gemelos"<<endl;
                            }
                            else{
                               cout<<"Los n�meros "<<num<<" y "<<num2<<" no son primos gemelos"<<endl; 
                            }
                        }
                        else{
                            if (option == 2){
                                if (primos_primos (num, num2)){
                                    cout<<"Los n�meros "<<num<<" y "<<num2<<" son primos primos"<<endl;
                                }
                                else{
                                    cout<<"Los n�meros "<<num<<" y "<<num2<<" no son primos primos"<<endl; 
                                }
                            }
                            else{
                                if (primos_sexys (num, num2)){
                                    cout<<"Los n�meros "<<num<<" y "<<num2<<" son primos sexys"<<endl;
                                }
                                else{
                                    cout<<"Los n�meros "<<num<<" y "<<num2<<" no son primos sexys"<<endl; 
                                }
                            }
                        }
                    break;
                    case 2: 
                        if (coprimos (num, num2)){
                            cout<<"Los n�meros "<<num<<" y "<<num2<<" son coprimos"<<endl;
                        }
                        else{
                            cout<<"Los n�meros "<<num<<" y "<<num2<<" no son coprimos"<<endl; 
                        }
                    break;
                    case 3:
                        if (amigos (num, num2)){
                            cout<<"Los n�meros "<<num<<" y "<<num2<<" son n�meros amigos"<<endl;
                        }
                        else{
                            cout<<"Los n�meros "<<num<<" y "<<num2<<" no son n�meros amigos"<<endl; 
                        } 
                    break;
                    case 4:
                        if (novios (num, num2)){
                            cout<<"Los n�meros "<<num<<" y "<<num2<<" son n�meros novios"<<endl;
                        }
                        else{
                            cout<<"Los n�meros "<<num<<" y "<<num2<<" no son n�meros novios"<<endl; 
                        }
                    break;
                    case 5:
                        do{
                            cout<<"Ingrese un n�mero: ";
                            cin>>num;
                            if (num<0){
                                cout<<"El n�mero debe ser mayor o igual a cero!"<<endl;
                            }
                        }while(num<0);

                        if (sociables (num)){
                            cout<<"El n�mero "<<num<<" es n�mero sociable"<<endl;
                        }
                        else{
                            cout<<"El n�mero "<<num<<" no es n�mero sociable"<<endl;
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
