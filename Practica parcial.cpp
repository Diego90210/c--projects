#include <iostream>
#include <fstream>
using namespace std;

struct carrera{
    long id;
    long salario=0;
    int carr[7];
};

struct taxista{
    long id;
    char nombre[50];
    long telefono;
};

void registrar_taxista (int &cant_taxistas);
bool veri_taxista (long id_taxista);
void generar_nomina();
void consulta_taxista();

int main(){
    ofstream a1 ("taxistas.txt", ios::app | ios::binary);
    if (a1.fail()){
        cout<<"Error al abrir el archivo taxistas.txt para escritura"<<endl;
        system("pause");
        exit(0);
    }
    a1.close();

    ofstream a2 ("carreras.txt", ios::out | ios::binary);
    if (a2.fail()){
        cout<<"Error al abrir el archivo pagos.txt para escritura"<<endl;
        system("pause");
        exit(0);
    }
    a2.close();

    int op, cant_taxistas=0;
    do{
        cout<<"1. Registrar taxista"<<endl;
        cout<<"2. Generar nomina"<<endl;
        cout<<"3. Consultar taxista"<<endl;
        cout<<"4. Reporte de nomina"<<endl;
        cout<<"5. Salir"<<endl;
        cout<<"Ingrese una opcion: ";
        cin>>op;

        switch (op){
            case 1: registrar_taxista (cant_taxistas);
                break;
            case 2: generar_nomina();
                break;
            case 3:
                break;
            case 4:
                break;
            case 5: exit(0);
                break;
            default:
                cout<<"Debe ingresar dentro del rango [1-5]";
                system("pause");
        }
    }while(op!=5);
    
}

void registrar_taxista (int &cant_taxistas){
    system("cls");
    taxista taxistas;
    int salir;
    do{
        cout<<"Ingrese el ID del taxista: ";
        cin>>taxistas.id;

        if (veri_taxista(taxistas.id)){
            cout<<endl;
            cout<<"El id del taxista ya se encuentra registrado";
        }
        else{
            cout<<"Nombre: ";
            fflush (stdin);
            gets(taxistas.nombre);

            cout<<"Telefono: ";
            cin>>taxistas.telefono;

            ofstream a ("taxistas.txt", ios::app | ios::binary);
            if (a.fail()){
                cout<<"Error al abrir el archivo taxistas.txt para escritura"<<endl;
                system("pause");
                exit(0);
            }
            a.write (reinterpret_cast <char *> (&taxistas), sizeof (taxista));
            a.close();
            cant_taxistas++;
        }
        cout<<"Desea registrar otro taxista ? [1-Si] [Otro num-No]: ";
        cin>>salir;
    }while(salir==1);
}

bool veri_taxista (long id_taxista){
    taxista taxistas;
    ifstream a ("taxistas.txt", ios::in | ios::binary);
    if (a.fail()){
        cout<<"Error al abrir el archivo taxistas.txt para lectura"<<endl;
        system("pause");
        exit(0);
    }
    a.read (reinterpret_cast <char *> (&taxistas), sizeof (taxista));
    while(!a.eof()){
        if (id_taxista == taxistas.id){
            return true;
        }
        a.read (reinterpret_cast <char *> (&taxistas), sizeof (taxista));
    }
    a.close();
    return false;
}

void generar_nomina(){
    system("cls");
    carrera carreras;
    int salir;
    cout<<"Ingrese el id del taxista: ";
    cin>>carreras.id;
    do{
        if (veri_taxista (carreras.id)){
            for (int i=0; i<7; i++){
                cout<<"Cantidad de carreras del dia "<<i+1<<": ";
                cin>>carreras.carr[i];

                if (carreras.carr[i]<=10){
                    carreras.salario += carreras.carr[i]*2000;
                }
                else{
                    if (carreras.carr[i]<30){
                        carreras.salario += carreras.carr[i]*4000;
                    }
                    else{
                        carreras.salario += carreras.carr[i]*5000;
                    }
                }
            }
            ofstream a ("carreras.txt", ios::app | ios::binary);
            if (a.fail()){
                cout<<"Error al abrir el archivo taxistas.txt para escritura"<<endl;
                system("pause");
                exit(0);
            }
            a.write (reinterpret_cast <char *> (&carreras), sizeof (carrera));
            a.close();
        }
        else{
            cout<<"El id ingresado no se encuentra registrado"<<endl;
        }
        cout<<"Desea generar otra nomina ? [1-Si] [Otro valor-No]: ";
        cin>>salir;
    }while(salir==1);
}

void mostrar_nombre(){
    
}

void consulta_taxista(){
    carrera carreras;
    taxista taxistas;
    long aux_id;
    int salir;
    do{
        cout<<"Ingrese el id del taxista: ";
        cin>>aux_id;

        if (veri_taxista(aux_id)){
            ifstream a ("taxistas.txt", ios::in | ios::binary);
            if (a.fail()){
                cout<<"Error al abrir el archivo taxistas.txt para lectura"<<endl;
                system("pause");
                exit(0);
            }
            a.read (reinterpret_cast <char *> (&taxistas), sizeof (taxista));
            while(!a.eof()){
                if (aux_id == taxistas.id){
                    break;
                }
                a.read (reinterpret_cast <char *> (&carreras), sizeof (carrera));
            }
            a.close();

            cout<<"Nombre del taxista: "<<taxistas.nombre<<endl;

            ifstream a1 ("carreras.txt", ios::in | ios::binary);
            if (a.fail()){
                cout<<"Error al abrir el archivo carreras.txt para lectura"<<endl;
                system("pause");
                exit(0);
            }
            a.read (reinterpret_cast <char *> (&carreras), sizeof (carrera));
            while(!a.eof()){
                if (aux_id == carreras.id){
                    break;
                }
                a.read (reinterpret_cast <char *> (&carreras), sizeof (carrera));
            }
            a.close();

            for (int i=0; i<7; i++){
                cout<<"Cantidad de carreras en el dia #"<<i+1<<": "<<carreras.carr[i]<<endl;
            }
            cout<<"Salario del taxista: "<<carreras.salario<<endl;
        }
        else{
            cout<<"No se ha encontrado el id ingresado"<<endl;
            system("pause");
        }
        cout<<"Desea consultar otro taxista [1-si] [Otro valor-No]: ";
        cin>>salir;
    }while(salir==1);
}

