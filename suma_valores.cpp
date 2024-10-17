#include <iostream>
#include <stdlib.h>
using namespace std;

void leer ();
int aleatorio();
int suma (int, int );

int main(){
    leer();
}

void leer (){
    int num, alea, sumatoria=0;
    bool decide;
    do
    {
        decide = false;
        do
        {
            cout<<"Ingrese un numero: ";
            cin>>num;
            if (num<1 or num>10){
                cout<<"Ingrese un numero dentro del rango (1-10)"<<endl;
                system("pause");
            }
        }while (num<1 or num>10);

        alea=aleatorio();
        sumatoria += suma (num, alea);
        
        cout<<"Numero aleatorio: "<<alea<<endl;
        cout<<"Sumatoria: "<<sumatoria<<endl;

        if (sumatoria<100){
            decide = true;
        }
        else{
            cout<<"Se ha superado el limite (100)."<<endl;
        }
        
    }while (decide==true);

}

int aleatorio(){
    int aleatorio;
    aleatorio = 1 + rand()%(10); //limite_inferior + rand()%(limite_superior + 1 - limite_inferior)
    return aleatorio;
}

int suma (int num, int alea){
    return (num+alea);
}





