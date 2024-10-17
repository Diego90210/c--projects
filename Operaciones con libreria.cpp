#include <iostream>
#include "Mi_Libreria.h"
using namespace std;


int menu(){
    int op;
    do{
        cout<<"1. Potencia"<<endl;
        cout<<"2. Suma de Digitos de un numero"<<endl;
        cout<<"3. Suma de divisores propios de un numero"<<endl;
        cout<<"4. Cantidad de digitos de un numero"<<endl;
        cout<<"5. Cantidad de divisores propios de un numero"<<endl;
        cout<<"6. Numero primo"<<endl;
        cout<<"7. Numero perfecto"<<endl;
        cout<<"8. Numeros amigos"<<endl;
        cout<<"9. Numero Narcisista"<<endl;
        cout<<"10. Numero Abundante o deficiente"<<endl;
        cout<<"11. Salir."<<endl;
        cout<<"Seleccione una opcion: ";
        cin>>op;
    }while(op<1 or op>11);

    return op;
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



int main(){
    int op, a, b;
    setlocale(LC_ALL, "spanish");
    do{
        system("cls");
        op=menu();
        switch(op){
        case 1: 
            cout<<"Ingrese la base de la potencia a calcular: ";
            cin>>a;
            cout<<"Ingrese el exponente: ";
            cin>>b;
            cout<<a<<"^"<<b<<" = "<<potencia(a,b)<<endl;
        break;
        case 2: 
            cout<<"Ingrese un numero: ";
            cin>>a;
            cout<<"Suma de los digitos de "<<a<<" = "<<suma_digitos(a)<<endl;
        break;
        case 3: 
            cout<<"Ingrese un numero: ";
            cin>>a;
            cout<<"Suma de los divisores propios de "<<a<<" = "<<suma_divisores(a)<<endl;
        break;
        case 4:
            cout<<"Ingrese un numero: ";
            cin>>a; 
            cout<<"Cantidad de digitos de "<<a<<" = "<<cant_digitos(a)<<endl;
        break;
        case 5:
            cout<<"Ingrese un numero: ";
            cin>>a; 
            cout<<"Cantidad de divisores propios de "<<a<<" = "<<cant_divisores(a)<<endl;
        break;
        case 6: 
            cout<<"Ingrese un numero: ";
            cin>>a; 
            if (cant_divisores(a) == 1){
                cout<<a<<" es un numero primo"<<endl;
            }
            else{
                cout<<a<<" no es un numero primo"<<endl;
            }
        break;
        case 7: 
            cout<<"Ingrese un numero: ";
            cin>>a;

            if (suma_divisores(a)==a){
                cout<<a<<" es un numero perfecto"<<endl;
            }
            else{
                cout<<a<<" no es un numero perfecto"<<endl;
            }
        break;
        case 8:
            cout<<"Ingrese un numero: ";
            cin>>a;
            cout<<"Ingrese otro numero: ";
            cin>>b;

            if ((suma_divisores(a)==b) && (suma_divisores(b)==a)){
                cout<<a<<" y "<<b<<" son numeros amigos"<<endl;
            }
            else{
                cout<<a<<" y "<<b<<" NO son numeros amigos"<<endl;
            }
        break;
        case 9:
            cout<<"Ingrese un numero: ";
            cin>>a;
            if (narcisista(a)==a){
                cout<<a<<" es un numero narcisista"<<endl;
            }
            else{
                cout<<a<<" no es un numero narcisista"<<endl;
            }
        break;
        case 10:
            cout<<"Ingrese un numero: ";
            cin>>a;
            b = suma_divisores(a);
            if (b>a){
                cout<<a<<" es un numero abundante"<<endl;
            }
            else{
                if (b<a){
                    cout<<a<<" es un numero deficiente"<<endl;
                }
                else{
                    if (b==a){
                        cout<<a<<" es un numero perfecto"<<endl;
                    }
                }
            }
        break;
        case 11:
            exit(0);
        }
        system("pause");
    }while(op!=11);

}
