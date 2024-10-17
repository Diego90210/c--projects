#include <iostream>
#include <math.h>
using namespace std;

struct paci
{
    char nombre [20];
    char apellido [20];
    char genero;
    int ano_nacimiento;
    float peso;
    float altura;
}paciente[100];

void pedir_datos(int x){
    fflush (stdin);
    cout<<"Ingrese su nombre: ";
    gets (paciente[x].nombre);
    fflush(stdin);

    cout<<"Ingrese su apellido: ";
    gets (paciente[x].apellido);

    cout<<"Ingrese su genero: ";
    cin>>paciente[x].genero;

    cout<<"Ingrese su año de nacimiento: ";
    cin>>paciente[x].ano_nacimiento;

    cout<<"Ingrese su peso: ";
    cin>>paciente[x].peso;

    cout<<"Ingrese su altura: ";
    cin>>paciente[x].altura;
}

float imc (int peso, int x){
    float imc;
    imc = (paciente[x].peso/pow(paciente[x].altura, 2));
    return imc;
}

int edad (int ano_nacimiento, int x){
    int edad;
    edad = 2023 - paciente[x].ano_nacimiento;
    return edad;
}

void mostrar (struct paci paciente[], int x){
    float indice;
    cout<<"Nombre: "<<paciente[x].nombre<<endl;
    cout<<"Apellido: "<<paciente[x].apellido<<endl;
    cout<<"Genero: "<<paciente[x].genero<<endl;
    cout<<"Edad: "<<edad(paciente[x].ano_nacimiento, x)<<endl;
    cout<<"Peso: "<<paciente[x].peso<<endl;
    cout<<"Altura: "<<paciente[x].altura<<endl;
    
    indice = imc (paciente[x].peso, x);
    cout<<"Su IMC es: "<<indice<<". ";

    if (indice < 18.5){
        cout<<"Usted tiene bajo peso."<<endl;
    }
    else{
        if (indice < 25){
            cout<<"Usted tiene peso normal."<<endl;
        }
        else{
            if (indice < 30){
                cout<<"Usted tiene sobrepeso."<<endl;
            }
            else{
                cout<<"Usted tiene obesidad."<<endl;
            }
        }
    }  
}

int main(){
    int x=0, sw;
    do{
        pedir_datos(x);
        mostrar (paciente, x);
        system("pause");
        system("cls");

        cout<<"Desea registrar un paciente ? [1-Si] [Otro num-No]: ";
        cin>>sw;
        x++;
    }while (sw==1);
}