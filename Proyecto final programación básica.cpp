#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
//Diego Andrés Martínez Florez: 0222120002.
//José David Torres Acevedo: 0222120038.
//Roberto Junior Martínez Paternina: 0222120018.

struct alergia{
    char ingrediente [50];
};

struct fecha{

    int dia;
    int mes;
    int anio;
};

struct acudiente {

    long dni;
    char nombre[80];
    long telefono;
    char direccion[100];
    char relacion [200];
};

struct Estudiante {
    long matricula;
    char nombre[80];
    fecha f_nacimiento;
    acudiente familiar[80];
    bool activo;// solo puede ser 1 o 0
    fecha fechaIngreso;
    fecha fechaBaja;
    int cant_acudientes;
    int cant_alergias;
    alergia alergias[20];
};

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
    plato pla[100];
};

int main();

void ingresar_menu (int &cant_menu, int cant_platos);
char menu1();
void cad_mayus (char *cad);
int menu_gestion_academica();
int menu_gestion_restaurante();
bool veri_plato (char *nombre_plato);
bool veri_menu(int cant_menu);
void registro_platos (int &cant_platos);
void registro_estudiante ();
bool val_fam (long );
bool veri_estudiante (long );
void registro_acudientes ();

char menu1(){
    char opc;
    do{
        cout<<"A. GESTÍON RESTAURANTE"<<endl;
        cout<<"B. GESTIÓN ACADÉMICA"<<endl;
        cout<<"C. SALIR"<<endl;
        cout<<"Ingrese una opción: "<<endl;
        cin>>opc;
        opc = toupper (opc);
    }while((opc!='A') && (opc!='B') && (opc!='C'));
    return opc;
}

int main(){
    //Crear archivos acá
    ofstream a1 ("platos.txt", ios::out | ios::binary);
    if (a1.fail()){
        cout<<"Error al abrir el archivo platos.txt para escritura"<<endl;
        system("pause");
        exit(0);
    }
    a1.close();

    ofstream a2 ("menus.txt", ios::out | ios::binary);
    if (a2.fail()){
        cout<<"Error al abrir el archivo menus.txt para escritura"<<endl;
        system("pause");
        exit(0);
    }
    a2.close();

    ofstream a3 ("estudiantes.txt", ios::out | ios::binary);
    if (a3.fail()){
        cout<<"Error al abrir el archivo estudiantes.txt para escritura"<<endl;
        system("pause");
        exit(0);
    }
    a3.close();

    char opc;
    int op, cant_menu=0, cant_platos=0;

    do{
        opc = menu1();
        switch (opc){
            case 'A':
                do{
                    op = menu_gestion_restaurante();
                    switch (op){
                        case 1: 
                            ingresar_menu (cant_menu, cant_platos);
                            break;
                        case 2: 
                            registro_platos(cant_platos);
                            break;
                        case 3: 
                            break;
                        case 4: 
                            break;
                        case 5: 
                            break;
                        case 6: break;
                    }
                }while(op!=6);
            break;

            case 'B':
                do{
                    op = menu_gestion_academica();
                    switch (op){
                        case 1: registro_estudiante();
                            break;
                        case 2: 
                            break;
                        case 3: registro_acudientes();
                            break;
                        case 4:
                            break;
                        case 5:
                            break;
                        case 6:
                            break;
                        case 7: 
                            break;
                    }
                }while(op!=7);
            break;

            case 'C':
                exit(0);
            break;
        }
    }while(opc!='C');
}

int menu_gestion_restaurante(){
    int op;
    do{
        cout<<"1. Ingresar menú"<<endl;
        cout<<"2. Registro de platos"<<endl;
        cout<<"3. Asignación menú por estudiante"<<endl;
        cout<<"4. Facturación"<<endl;
        cout<<"5. Consulta"<<endl;
        cout<<"6. Salir"<<endl;
        cout<<"Ingrese una opción: "<<endl;
        cin>>op;
    }while(op<1 or op>6);
    return op;
}

int menu_gestion_academica(){
    int op;
    do{
        system("cls");
        cout<<"1. Matrícula"<<endl;
        cout<<"2. Dar de baja matrícula"<<endl;
        cout<<"3. Registro de acudientes"<<endl;
        cout<<"4. Cálculo pago mensualidad"<<endl;
        cout<<"5. Registro de pago mensualidad"<<endl;
        cout<<"6. Consultas"<<endl;
        cout<<"7. Salir"<<endl;
        cout<<"Ingrese una opción: "<<endl;
        cin>>op;
    }while(op<1 or op>7);
    return op;
}

bool veri_menu(int num_menu){
    menu menus;
    ifstream a ("menus.txt", ios::in | ios::binary);
    if (a.fail()){
        cout<<"Error al abrir el archivo platos.txt para lectura"<<endl;
        system("pause");
        exit(0);
    }
    a.read (reinterpret_cast <char *> (&menus), sizeof (menu));
    while(!a.eof()){
        if (num_menu == menus.num_menu){
            return true;
        }
        a.read (reinterpret_cast <char *> (&menus), sizeof (menu));
    }
    a.close();
    return false;
}

void ingresar_menu(int &cant_menu, int cant_platos){
    menu menus;
    int salir;
    int i;
    char aux_nombre[100];
    cout<<"Ingresar menú"<<endl;
    do{
        i=0;
        do{
            cout<<"Número del menú: ";
            cin>>menus.num_menu;
        }while(menus.num_menu<=0);
        
        if (veri_menu(menus.num_menu)){ 
            cout<<"El número del menú ya se encuentra registrado"<<endl;
            system("pause");
        }
        else{
            do{
                cout<<"Ingrese el nombre del plato: ";
                fflush (stdin);
                gets (aux_nombre);
                cad_mayus (aux_nombre);
                
                if (veri_plato(aux_nombre)){
                    strcpy(menus.pla[i].nombre_plato, aux_nombre);
                    i++;
                }
                else{
                    cout<<"No se ha encontrado el nombre del plato"<<endl;
                    system("pause");
                }
                cout<<"Desea agregar otro plato ? [1-Si] [Otro valor-No]: ";
                cin>>salir;
            }while(salir==1);
            ofstream a ("menus.txt", ios::app | ios::binary);
            a.write (reinterpret_cast <char *> (&menus), sizeof (menu));
            a.close();
            cant_menu++;
        }
        cout<<"Desea registrar otro menú ? [1-Si] [Otro valor-No]: ";
        cin>>salir;
    }while(salir==1);
}

bool veri_plato (char *nombre_plato){
    plato platos;
    ifstream a ("platos.txt", ios::in | ios::binary);
    if (a.fail()){
        cout<<"Error al abrir el archivo platos.txt para lectura"<<endl;
        system("pause");
        exit(0);
    }

    a.read (reinterpret_cast <char *> (&platos) , sizeof(plato));
    while(!a.eof()){
        if ((strcmp(nombre_plato, platos.nombre_plato)) == 0){
            return true;
        }
        a.read (reinterpret_cast <char *> (&platos) , sizeof(plato));
    }
    a.close();
    return false;
}

void registro_platos (int &cant_platos){
    //agregar un precio a los platos, para luego sumar dichos precios en el menú.
    plato platos;
    int salir;
    do{
        cout<<"Registro de platos"<<endl;
        cout<<"Nombre del plato: "; 
        gets(platos.nombre_plato);
        
        cad_mayus(platos.nombre_plato);

        if (veri_plato(platos.nombre_plato)){
            cout<<"El plato ya se encuentra registrado"<<endl;
            system("pause");
        }
        else{
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
            cant_platos++;
        }
        cout<<"Desea registrar otro plato ? [1-Si] [Otro valor-No]: ";
        cin>>salir;
    }while(salir==1);
}

void cad_mayus (char *cad){
    for (int i=0; i<strlen(cad); i++){
        cad[i]=toupper(cad[i]);
    }
}

void registro_estudiante (){
    Estudiante estudiantes;
    int salir;
    do{
        system("cls");
        cout<<"Ingrese el número de la matricula: ";
        cin>>estudiantes.matricula;

        if (veri_estudiante(estudiantes.matricula)){
            cout<<"El estudiante ya se encuentra registrado";
            system("pause");
        }
        else{
            cout<<"Nombre del estudiante: ";
            fflush (stdin);
            gets (estudiantes.nombre);

            cad_mayus (estudiantes.nombre);

            cout<<"Fecha de nacimiento del estudiante"<<endl;
            cout<<"Dia: "; 
            cin>>estudiantes.f_nacimiento.dia;
            cout<<"Mes: "; 
            cin>>estudiantes.f_nacimiento.mes;
            cout<<"Año: "; 
            cin>>estudiantes.f_nacimiento.anio;

            cout<<endl;

            cout<<"Fecha de ingreso a la guardería"<<endl;
            cout<<"Dia: "; 
            cin>>estudiantes.fechaIngreso.dia;
            cout<<"Mes: "; 
            cin>>estudiantes.fechaIngreso.mes;
            cout<<"Año: "; 
            cin>>estudiantes.fechaIngreso.anio;

            cout<<"Cantidad de ingredientes a la que el niño es alérgico: ";
            cin>>estudiantes.cant_alergias;

            for (int i=0; i<estudiantes.cant_alergias; i++){
                cout<<"Ingrediente No. "<<i+1<<endl;
                cout<<"Nombre: ";
                fflush (stdin);
                gets (estudiantes.alergias[i].ingrediente);
                cout<<endl;
            }
            estudiantes.activo = true;
            ofstream a3 ("estudiantes.txt", ios::app | ios::binary);
            if (a3.fail()){
                cout<<"Error al abrir el archivo estudiantes.txt para escritura"<<endl;
                system("pause");
                exit(0);
            }
            a3.write (reinterpret_cast <char *> (&estudiantes), sizeof (Estudiante));
            a3.close();
        }
        cout<<"Desea registrar otro estudiante [1-Si] [Otro Valor-No]: ";
        cin>>salir;
    }while(salir==1);
}

bool veri_estudiante(long cod)
{
    Estudiante matri;
    ifstream archivo_est("estudiantes.txt", ios::in | ios::binary);
    if (archivo_est.fail())
    {
        cout<<"ERROR para abrir archivo estudiantes.txt"<<endl;
        system("pause");
        exit(0);
    }
    archivo_est.read(reinterpret_cast<char *>(&matri), sizeof(Estudiante));
    while(!archivo_est.eof())
    {
        if((cod == matri.matricula) && (matri.activo==true))
        {
            return true;
        }
        archivo_est.read(reinterpret_cast<char *>(&matri), sizeof(Estudiante));
    }
    archivo_est.close();
    return false;
}

bool val_fam(long cod)
{
    Estudiante ID;
    ifstream archivo_est("estudiantes.txt", ios::in | ios::binary);
    if (archivo_est.fail())
    {
        cout<<"ERROR para abrir archivo estudiantes.txt"<<endl;
        system("pause");
        exit(0);
    }
    archivo_est.read(reinterpret_cast<char *>(&ID), sizeof(Estudiante));
    while(!archivo_est.eof())
    {
        for (int i=0; i<ID.cant_acudientes; i++){
            if(cod == ID.familiar[i].dni)
            {
                return true;
            }
        }
        archivo_est.read(reinterpret_cast<char *>(&ID), sizeof(Estudiante));
    }
    archivo_est.close();
    return false;
}

void registro_acudientes(){
    Estudiante estudiantes;
    int salir;
    int i;
    bool sw;
    do{
        system("cls");
        cout<<"Ingrese la matricula del alumno: ";
        cin>>estudiantes.matricula;

        if (veri_estudiante(estudiantes.matricula)){
            do{
                i=0;
                sw=false;
                cout<<"Acudiente No. "<<i+1<<endl;
                cout<<"Nombre: ";
                fflush (stdin);
                gets (estudiantes.familiar[i].nombre);
                cad_mayus (estudiantes.familiar[i].nombre);
                cout<<"DNI: ";
                cin>>estudiantes.familiar[i].dni;

                for (int j=0; j<i; j++){
                    if (estudiantes.familiar[i].dni == estudiantes.familiar[j].dni){
                        sw=true;
                        break;
                    }
                }
                if (sw){
                    cout<<"Ya ha ingresado el mismo acudiente previamente"<<endl;
                    system("pause");
                }
                cout<<"Dirección: ";
                fflush (stdin);
                gets (estudiantes.familiar[i].direccion);
                cout<<"Teléfono: ";
                cin>>estudiantes.familiar[i].telefono;
                cout<<"Relacion: ";
                fflush (stdin);
                gets (estudiantes.familiar[i].relacion);
                cout<<endl;
                i++;
                estudiantes.cant_acudientes = i;
                cout<<"Desea registrar otro acudiente ? [1-Si] [Otro valor-No]: ";
                cin>>salir;
            }while((salir==1) && (i<80));
        }
        else{
            cout<<"No se ha encontrado la matricula del alumno"<<endl;
            system("pause");
        }
        cout<<endl;
        cout<<"Desea registrar el acudiente de otro niño ? [1-Si] [Otro valor-No]: ";
        cin>>salir;
    }while(salir==1);
}






