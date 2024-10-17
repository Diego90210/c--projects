#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct ingre{
    char nombre_ingrediente[100];
};

struct plato{
    char nombre_plato [100];
    int cant_ingredientes;
    ingre ingrediente[30];
};

struct menu{
    int num_menu;
    int cant_plato;
    plato pla;
};

void leer();

int main(){
    plato platos;
    cout<<"Registro de platos"<<endl;
    cout<<"Nombre del plato: "; 
    gets(platos.nombre_plato);
    
    do{
        cout<<"Número de ingredientes: ";
        cin>>platos.cant_ingredientes;
    }while(platos.cant_ingredientes<=0);

    for (int i=0; i<platos.cant_ingredientes; i++){
        cout<<"Ingrese el nombre del ingrediente #"<<(i+1)<<": ";
        fflush (stdin);
        gets(platos.ingrediente[i].nombre_ingrediente);
    }

    ofstream a ("platos.txt", ios::app | ios::binary);
    if (a.fail()){
        cout<<"Error al abrir el archivo platos.txt para escritura"<<endl;
        system("pause");
        exit(0);
    }
    a.write (reinterpret_cast <char *> (&platos), sizeof (plato));

    a.close();
    leer();
}

void leer (){
    plato platos;
    ifstream a ("platos.txt", ios::in | ios::binary);
    if (a.fail()){
        cout<<"Error al abrir el archivo para lectura"<<endl;
		system("pause");
		exit(0);
    }
    a.read (reinterpret_cast <char *> (&platos), sizeof (plato));

    while(!a.eof()){
        cout<<setw(20);
        cout<<platos.nombre_plato;
        for (int i=0; i<platos.cant_ingredientes; i++){
            cout<<platos.ingrediente[i].nombre_ingrediente;
        }
        a.read (reinterpret_cast <char *> (&platos), sizeof (plato));
    }
    a.close();
    system("pause");
}