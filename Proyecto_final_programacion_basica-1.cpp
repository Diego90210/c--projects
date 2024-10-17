//Diego Andr�s Mart�nez Florez: 0222120002.
//Jos� David Torres Acevedo: 0222120038.
//Roberto Junior Mart�nez Paternina: 0222120018.

#include <iostream>
#include <string.h>
#include <fstream>
#include <ctime>
#include "LIBRERIA.h"
using namespace std;

struct alergia{
    char ingrediente [50];
};

struct fecha{

    int dia;
    int mes;
    int anio;
};
struct AsignacionMenu {
    int matricula;
	float precio_platos[5]; 
    int num_menu; 
	int plato_dia[5]; 
};

struct acudiente {
	
	long matricula;
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
    alergia alergias[500];
    bool estadoPago;
};

struct ingre{
    char nombre_ingrediente[100];
};

struct plato{
	float precio;
    char nombre_plato [100];
    int cant_ingredientes;
    ingre ingrediente[30];
};

struct menu{
    int num_menu;
    int cant_plato;
    char nombres_plato[100];
    plato pla[100];
};

void mostrar_menu(int nro_menu);
void consultaEstudiante(int numeroMatricula);
char menu_principal();
void menu_por_estudiante();
void restaurante();
void academica();
void crear_archivos();
void ingresar_menu ();
void listarEstudiantesActivos();
bool buscar_menu(int nromenu, menu *MENU);
void cad_mayus (char *cad);
int menu_gestion_academica();
int menu_gestion_restaurante();
void asignar_menu_estudiante();
bool veri_plato (const char* nombre_plato, const menu& MENU);
bool veri_plato1 (char *nombre_plato);
bool veri_menu(int cant_menu);
void registro_platos (int nro_menu);
void registro_estudiante ();
bool val_fam (long );
void darbaja ();
void listarEstudiantesConBaja();
void listar_carta();
bool veri_estudiante (long );
void registro_acudientes ();
void menu_consulta_restaurante();
int menu_consulta();


void crear_archivos(){
	ofstream menus, platillos, estudiantes, acudientes, bajas, asignaciones;
	
	menus.open("menus.txt",ios::out|ios::binary);
	if(menus.fail())
	{
		cout<<"No se pudo crear el archivo menus.txt "<<endl;
		exit(0);
	}
	
	bajas.open("estudiantes_bajas.txt",ios::out|ios::binary);
	if(menus.fail())
	{
		cout<<"No se pudo crear el archivo bajas.txt "<<endl;
		exit(0);
	}
	
	platillos.open("platillos.txt",ios::out|ios::binary);
	if(platillos.fail())
	{
		cout<<"No se pudo crear el archivo platillos.txt"<<endl;
		exit(0);
	}
	
	estudiantes.open("estudiantes.txt",ios::out|ios::binary);
	if(estudiantes.fail())
	{
		cout<<"No se pudo crear el archivo estudiantes.txt"<<endl;
		exit(0);
	}
	
	asignaciones.open("asignaciones.txt",ios::out|ios::binary);
	if(asignaciones.fail())
	{
		cout<<"No se pudo crear el archivo asignaciones.txt "<<endl;
		exit(0);
	}
	acudientes.open("acudientes.txt",ios::out|ios::binary);
	if(acudientes.fail())
	{
		cout<<"No se pudo crear el archivo acudientes.txt "<<endl;
		exit(0);
	}
}
int main(){
	setlocale(LC_ALL, "spanish");
	system("color 0a");
	bool archivos_creados=false;
	
	//Se crean los archivos
	ifstream archivo;
	
	//Verificiar si los archivos han sido creados
	archivo.open("menus.txt", ios::in|ios::binary);
	if(archivo.is_open())
		archivos_creados=true;
	archivo.close();
	
	archivo.open("platillos.txt", ios::in|ios::binary);
	if(archivo.is_open())
		archivos_creados=true;
	archivo.close();
	
	archivo.open("estudiantes.txt", ios::in|ios::binary);
	if(archivo.is_open())
		archivos_creados=true;
	archivo.close();
		
	archivo.open("acudientes.txt", ios::in|ios::binary);
	if(archivo.is_open())
		archivos_creados=true;
	archivo.close();
	
	archivo.open("estudiantes_bajas.txt", ios::in|ios::binary);
	if(archivo.is_open())
		archivos_creados=true;
	archivo.close();
	
	archivo.open("asignaciones.txt", ios::in|ios::binary);
	if(archivo.is_open())
		archivos_creados=true;
	archivo.close();
		
	//Si los archivos no han sido creados, o alguno de los archivos falla.
	if(archivos_creados==false)
	{
		cout<<"Archivos creados"<<endl;
		crear_archivos();
		system("PAUSE");
	}

    char opc;
    int op, nro_menu;
    bool salir=false;
    bool salir1 = false;
	while(true)	
	{
		switch(toupper(menu_principal()))
		{
			case 'A':
				{
					restaurante();
				}break;
			
			case 'B':
				{
					academica();
				}break;
			
			case 'C':
				{
					return 0;
				}break;
			
			default:
				{
					cout<<"\nOPCI�N INCORRECTA, INTENTE NUEVAMENTE"<<endl;
					system("pause");
				}break;
		}
	}
    
}
char menu_principal()
{
	char opc;
	
	system("cls");
	cout<<"GUARDER�A MI POBRE ANGELITO"<<endl;
	cout<<"BIENVENIDO "<<endl;
	cout<<"Men� Principal: "<<endl;
	cout<<"A. GESTI�N RESTAURANTE"<<endl;
	cout<<"B. GESTI�N ACAD�MICA"<<endl;
	cout<<"C. SALIR"<<endl;
	cout<<"Opci�n: ";	fflush(stdin);	cin>>opc;
	
	return opc;
}
void restaurante()
{
	int nro_menu;
	bool salir= false;
	while(!salir)
	{
		switch(menu_gestion_restaurante())
		{
				case 1:
					ingresar_menu();
					break;
				case 2:
					registro_platos(nro_menu);
					break;
				case 3:
					asignar_menu_estudiante();
					break;
				case 4:
					break;
				case 5:
					menu_consulta_restaurante();
					break;
				case 6:
					salir= true;
					break;
		}
	}
}
int menu_consulta()
{
	int op;
	
    	cout<<"Consultas: "<<endl;
        cout<<"1. Listar Carta"<<endl;
        cout<<"2. Men�"<<endl;
        cout<<"3. Men� por estudiante"<<endl;
        cout<<"4. Salir"<<endl;
        cout<<"Ingrese una opci�n: "<<endl;
        do
	{
		cout<<"\nOpci�n: ";
	}while(rangeint(1,4,op));
	return op;
}
void menu_consulta_restaurante()
{
	int nro_menu;
	bool salir= false;
	while(!salir)
	{
		switch(menu_consulta())
		{
				case 1:
					listar_carta();
					break;
				case 2:
					mostrar_menu(nro_menu);
					break;
				case 3:
					menu_por_estudiante();
					break;
				case 4:
					salir= true;
					break;
		}
	}
}
int menu_consulta_A()
{
	int op;
	
    	cout<<"Consultas: "<<endl;
        cout<<"1. Listar estudiantes activos"<<endl;
        cout<<"2. Listar estudiantes con baja"<<endl;
        cout<<"3. Reporte de Estado Financiero de estudiantes"<<endl;
        cout<<"4. Consulta por estudiante"<<endl;
        cout<<"5. Salir"<<endl;
        cout<<"Ingrese una opci�n: "<<endl;
        do
	{
		cout<<"\nOpci�n: ";
	}while(rangeint(1,5,op));
	return op;
}
void menu_consulta_academica()
{
	int nro_menu;
	bool salir= false;
	while(!salir)
	{
		switch(menu_consulta_A())
		{
				case 1:
					listarEstudiantesActivos();
					break;
				case 2:
					listarEstudiantesConBaja();
					break;
				case 3:
					break;
				case 4:
					consultaEstudiante(nro_menu);
					break;
				case 5:
					salir= true;
					break;
		}
	}
}

void academica()
{
	int nro_menu;
	bool salir= false;
	while(!salir)
	{
		switch(menu_gestion_academica())
		{
				case 1:
					registro_estudiante();
					break;
				case 2:
					darbaja();
					break;
				case 3:
					registro_acudientes();
					break;
				case 4:
					break;
				case 5:
					break;
				case 6:
					menu_consulta_academica();
					break;
				case 7:
					salir= true;
					break;
		}
	}
}
int menu_gestion_restaurante(){
    int op;
    
        cout<<"1. Ingresar men�"<<endl;
        cout<<"2. Registro de platos"<<endl;
        cout<<"3. Asignaci�n men� por estudiante"<<endl;
        cout<<"4. Facturaci�n"<<endl;
        cout<<"5. Consulta"<<endl;
        cout<<"6. Salir"<<endl;
        cout<<"Ingrese una opci�n: "<<endl;
        do
	{
		cout<<"\nOpci�n: ";
	}while(rangeint(1,6,op));
	return op;
}

int menu_gestion_academica(){
    int op;
    	system("cls");
        cout<<"1. Matr�cula"<<endl;
        cout<<"2. Dar de baja matr�cula"<<endl;
        cout<<"3. Registro de acudientes"<<endl;
        cout<<"4. C�lculo pago mensualidad"<<endl;
        cout<<"5. Registro de pago mensualidad"<<endl;
        cout<<"6. Consultas"<<endl;
        cout<<"7. Salir"<<endl;
    do{
        cout<<"Ingrese una opci�n: "<<endl;
        cout<<"\nOpci�n: ";
	}while(rangeint(1,7,op));
	return op;
}


void ingresar_menu(){
    menu MENU;
    plato PLATOS;
    int i,opcion, nromenu, cant_platos;
    char aux_nombre[100];
    static int registrados=0;
    cout<<"Ingresar men�"<<endl;
    while(true)
	{
		system("CLS");
		cout<<"AGREGAR MEN�"<<endl<<endl;
			do
			{
				do
				{
					cout<<"N�mero del men�: ";
				}while(rangeint(1,1000000, nromenu));
				
				if(buscar_menu(nromenu, &MENU))
				{
					cout<<"Ya ha ingresado ese men�"<<endl;
				}
			}while(buscar_menu(nromenu, &MENU));
			MENU.num_menu = nromenu;
			do
			{
				cout<<"Ingresar la cantidad de platos para el men�"<<endl;
				cout<<"NOTA: M�ximo 15 platos por men�"<<endl;
				cout<<"Cantidad de platos para el men�: ";
			}while(rangeint(1,15,MENU.cant_plato));
			
			
			//Escribir los datos en el archivo
			ofstream archivo("menus.txt",ios::app|ios::binary);
			if(archivo.fail())
			{
				cout<<"\nNo se pudo abrir el archivo menus.txt, terminando el programa"<<endl;
				exit(0);
			}
			
			archivo.write(reinterpret_cast<char*>(&MENU), sizeof(menu));
			archivo.close();
			
			cout
			<<"Los platos son agregados en la segunda opci�n"<<endl
			<<"�Desea ingresar otro men�?"<<endl
			<<"1. Si"<<endl
			<<"2. No";
		
		do
		{
			cout<<"\nOpci�n: ";
		}while(rangeint(1,2,opcion));
		
		if(opcion==2)
			break;
	}
}
bool buscar_menu(int nromenu, menu *MENU)
	{
		setlocale(LC_ALL,"spanish");
		
		//Abrir el archivo y verificar su correcta apertura
		ifstream archivo("menus.txt", ios::in|ios::binary);
		if(archivo.fail())
		{
			cout<<"\nNo se pudo abrir el archivo menus.txt, terminando el programa"<<endl;
			exit(0);
		}
		
		//Nos posicionamos en el primer bloque del archivo
		archivo.read(reinterpret_cast<char*>(MENU),sizeof(menu));
		while(!archivo.eof())
		{
			
			if(MENU->num_menu == nromenu)
			{
				archivo.close();
				return true;
			}
			archivo.read(reinterpret_cast<char*>(MENU),sizeof(menu));
		}
		
		//Si no est� registrado, se cierra el archivo y se devuelve un false
		archivo.close();
		return false;
	}
	
bool veri_plato(const char* nombre_plato, const menu& MENU) {
    for (int i = 0; i < MENU.cant_plato; i++) {
        if (strcmp(nombre_plato, MENU.pla[i].nombre_plato) == 0) {
            return true;
        }
    }
    return false;
}	

bool veri_plato1 (char *nombre_plato){
    plato PLATOS;
    ifstream archivo2 ("platillos.txt", ios::in | ios::binary);
    if (archivo2.fail()){
        cout<<"Error al abrir el archivo platillos.txt para lectura"<<endl;
        system("pause");
        exit(0);
    }

     	archivo2.read(reinterpret_cast<char*>(&PLATOS), sizeof(plato));
	    while (!archivo2.eof()) {
	        if (nombre_plato == PLATOS.nombre_plato) {
	            archivo2.close();
	            return true;
	        }
	        archivo2.read(reinterpret_cast<char*>(&PLATOS), sizeof(plato));
	    }
    
    archivo2.close();
    return false;
}

void registro_platos (int nro_menu){
    //agregar un los ingredientes de todos los platos dependiendo el men�
    plato PLATOS;
    menu MENU;
    ingre Nuevoingrediente;
    int cant_platos;
    char ingrediente, nombres[100];
    int opcion;
    int salir, nromenu;
    const int MAX_PLATOS = 100;
    plato platos[MAX_PLATOS]; // Arreglo para almacenar los platos registrados
    int contador_platos = 0;
    do {
	    do
			{
				do
				{
					cout<<"N�mero del men�: ";
				}while(rangeint(1,1000000, nromenu));
				
				if(!buscar_menu(nromenu, &MENU))
				{
					cout<<"El men� no existe"<<endl;
				}
				
			}while(!buscar_menu(nromenu, &MENU));
			cant_platos = 0;
			ofstream archivo2("platillos.txt", ios::app|ios::binary);
			if(archivo2.fail())
			{
				cout<<"\nNo se pudo abrir el archivo platillos.txt, terminando el programa"<<endl;
				exit(0);
			}for (int i = 0; i < MENU.cant_plato; i++) {
	    system("CLS");
	    cout << "Registro de platos" << endl;
	    cout << "Nombre del plato: ";
	    fflush(stdin);
	    gets(platos[contador_platos].nombre_plato);
	    cad_mayus(platos[contador_platos].nombre_plato);
	    
	    do {
	        cout << "Precio del plato: ";
	    } while (rangefloat(1, 10000000, PLATOS.precio));
		if (veri_plato(platos[contador_platos].nombre_plato, MENU)) {
            cout << "El plato ya se encuentra registrado en este men�" << endl;
            system("pause");
        } 
	    else {
	        ofstream archivo2("platillos.txt", ios::app | ios::binary);
	        if (archivo2.fail()) {
	            cout << "Error al abrir el archivo platillos.txt para escritura" << endl;
	            system("pause");
	            exit(0);
	        }
	        
	        do {
	            cout << "Cantidad de ingredientes del plato: " << platos[contador_platos].nombre_plato << endl;
	        } while (rangeint(1, 1000000, platos[contador_platos].cant_ingredientes));
	
	        for (int x = 0; x < platos[contador_platos].cant_ingredientes; x++) {
	            cout << "Ingrese el ingrediente #" << (x + 1) << " del plato: ";
	            fflush(stdin);
	            gets(platos[contador_platos].ingrediente[x].nombre_ingrediente);
	            platos[contador_platos].ingrediente[x] = Nuevoingrediente;
	            
	            ofstream archivo2("platillos.txt", ios::app | ios::binary);
	            if (archivo2.fail()) {
	                cout << "Error al abrir el archivo platillos.txt para escritura" << endl;
	                system("pause");
	                exit(0);
	            }
	            archivo2.write(reinterpret_cast<char*>(&platos[contador_platos].ingrediente[x]), sizeof(ingrediente));
	            archivo2.close();
	        }
	        
	        MENU.pla[i] = platos[contador_platos];
	        cout << "Plato registrado exitosamente" << endl;
	        archivo2.write(reinterpret_cast<char*>(&platos[contador_platos]), sizeof(plato));
	        archivo2.close();
	        contador_platos++;
	        cant_platos++;
	    }
}
	    cout
			<<"�Desea ingresar otros platos e ingredientes?"<<endl
			<<"1. Si"<<endl
			<<"2. No";
		
		do
		{
			cout<<"\nOpci�n: ";
		}while(rangeint(1,2,opcion));
		
		if(opcion==2)
			break;
	}while(true);
	
}

void cad_mayus (char *cad){
    for (int i=0; i<strlen(cad); i++){
        cad[i]=toupper(cad[i]);
    }
}

void registro_estudiante (){
    Estudiante ESTUDIANTES;
    int opcion;
    system("cls");
    while(true){
    	do{
			cout<<"N�mero de matr�cula: ";
		  }while(rangelong1(1,5000000, ESTUDIANTES.matricula));

        if (veri_estudiante(ESTUDIANTES.matricula)){
            cout<<"El estudiante ya se encuentra registrado";
            system("pause");
        }
        else{
            cout<<"Nombre del estudiante: ";
            fflush (stdin);
            gets (ESTUDIANTES.nombre);

            cad_mayus (ESTUDIANTES.nombre);

            cout<<"Fecha de nacimiento del estudiante"<<endl;
            cout<<"D�a: "; 
            cin>>ESTUDIANTES.f_nacimiento.dia;
            cout<<"Mes: "; 
            cin>>ESTUDIANTES.f_nacimiento.mes;
            cout<<"A�o: "; 
            cin>>ESTUDIANTES.f_nacimiento.anio;

            cout<<endl;

            cout<<"Fecha de ingreso a la guarder�a"<<endl;
            cout<<"Dia: "; 
            cin>>ESTUDIANTES.fechaIngreso.dia;
            cout<<"Mes: "; 
            cin>>ESTUDIANTES.fechaIngreso.mes;
            cout<<"A�o: "; 
            cin>>ESTUDIANTES.fechaIngreso.anio;

			do{
				cout<<"Cantidad de ingredientes a la que el ni�o es al�rgico: ";
			  }while(rangeint(0,500, ESTUDIANTES.cant_alergias));

            for (int i=0; i<ESTUDIANTES.cant_alergias; i++){
                cout<<"Ingrediente #"<<i+1<<": "<<endl;
                cout<<"Nombre: ";
                fflush (stdin);
                gets (ESTUDIANTES.alergias[i].ingrediente);
                cout<<endl;
            }
            ESTUDIANTES.activo = true;
            ofstream archivo3 ("estudiantes.txt", ios::app | ios::binary);
            if (archivo3.fail()){
                cout<<"Error al abrir el archivo estudiantes.txt para escritura"<<endl;
                system("pause");
                exit(0);
            }
            archivo3.write (reinterpret_cast <char *> (&ESTUDIANTES), sizeof (Estudiante));
            archivo3.close();
        }
        cout
			<<"�Desea ingresar otro estudiante?"<<endl
			<<"1. Si"<<endl
			<<"2. No";
		
		do
		{
			cout<<"\nOpci�n: ";
		}while(rangeint(1,2,opcion));
		
		if(opcion==2)
			break;
	}
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
    Estudiante ESTUDIANTES;
    acudiente ACUDIENTE;
    int salir;
    int i, cant_acu;
    bool sw;
    system("CLS");
    do{
        do{
			cout<<"N�mero de matr�cula del estudiante: ";
		  }while(rangelong1(1,5000000, ESTUDIANTES.matricula));


        if (veri_estudiante(ESTUDIANTES.matricula)){
                do{
				cout<<"Cantidad de acudientes a ingresar: ";
			  }while(rangeint(0,500, ESTUDIANTES.cant_acudientes));
                sw=false;
           		ACUDIENTE.matricula = ESTUDIANTES.matricula;
           		ofstream archivo_acudientes("acudientes.txt", ios::out | ios::app | ios::binary);
	            if (archivo_acudientes.fail()) {
	                cout << "Error al abrir el archivo acudientes.txt para escritura" << endl;
	                system("pause");
	                exit(0);
	            }
                for(int x; x< ESTUDIANTES.cant_acudientes; x++){
                	cout<<"Acudiente # "<<i+1<<endl;
                	do{
					cout<<"DNI: ";
				  }while(rangelong1(1,5000000, ESTUDIANTES.familiar[i].dni));

                for (int j=0; j<i; j++){
                    if (ESTUDIANTES.familiar[i].dni == ESTUDIANTES.familiar[j].dni){
                        sw=true;
                        break;
                    }
                }
                if (sw){
                    cout<<"Este acudiente ya est� registrado"<<endl;
                    system("pause");
               		 }
	                cout<<"Nombre: ";
	                fflush (stdin);
	                gets (ESTUDIANTES.familiar[i].nombre);
	                cad_mayus (ESTUDIANTES.familiar[i].nombre);
	                cout<<"Direcci�n: ";
	                fflush (stdin);
	                gets (ESTUDIANTES.familiar[i].direccion);
	                cout<<"Tel�fono: ";
	                cin>>ESTUDIANTES.familiar[i].telefono;
	                cout<<"Relaci�n con el ni�o: ";
	                fflush (stdin);
	                gets (ESTUDIANTES.familiar[i].relacion);
	                cout<<endl;
	                i++;
	                archivo_acudientes.write(reinterpret_cast<char*>(&ACUDIENTE), sizeof(acudiente));
				}
                
            archivo_acudientes.close();
            cout << "Los acudientes han sido agregados exitosamente." << endl;
            break;
        }
        else{
            cout<<"No se ha encontrado la matricula del alumno"<<endl;
            system("pause");
        }
        cout<<endl;
        cout<<"Registrar el acudiente de otro ni�o: [1-Si] [Otro valor-No]: ";
        cin>>salir;
    }while(salir==1);
}

void darbaja(){
	long matricula;
    bool encontrado = false;
    Estudiante ESTUDIANTES;
    system("cls");
    cout<<"Dar de baja a estudiantes"<<endl;
    do{
			cout<<"N�mero de matr�cula del estudiante a dar de baja:: ";
		}while(rangelong1(1,5000000, matricula));
		
    ifstream archivo3("estudiantes.txt", ios::in | ios::binary);
    if (archivo3.fail()) {
        cout << "Error al abrir el archivo estudiantes.txt para lectura" << endl;
        system("pause");
        exit(0);
    }

    ofstream archivo_temp("bajas.txt", ios::out | ios::binary | ios::app);
    if (archivo_temp.fail()) {
        cout << "Error al abrir el archivo bajas.txt para escritura" << endl;
        system("pause");
        exit(0);
    }

    while (archivo3.read(reinterpret_cast<char*>(&ESTUDIANTES), sizeof(Estudiante))) {
        if (ESTUDIANTES.matricula == matricula) {
            encontrado = true;
            int dia, mes, anio;
            cout << "Ingrese la fecha de baja: ";
            cout<<"D�a: "; 
            cin>>ESTUDIANTES.fechaBaja.dia;
            cout<<"Mes: "; 
            cin>>ESTUDIANTES.fechaBaja.mes;
            cout<<"A�o: "; 
            cin>>ESTUDIANTES.fechaBaja.anio;

            // Registrar la baja en un archivo
            ofstream archivo_bajas("estudiantes_bajas.txt", ios::out | ios::app);
            if (archivo_bajas.fail()) {
                cout << "Error al abrir el archivo estudiantes_bajas.txt para escritura" << endl;
                system("pause");
                exit(0);
            }

            archivo_bajas << "Matr�cula: " << ESTUDIANTES.matricula <<endl<< " - Nombre: " << ESTUDIANTES.nombre <<endl<<" - Fecha de baja: " << ESTUDIANTES.fechaBaja.dia<< "/" << ESTUDIANTES.fechaBaja.dia << "/" << ESTUDIANTES.fechaBaja.dia << endl;
            archivo_bajas.close();

            continue;  // Salta la escritura del estudiante encontrado
        }
        archivo_temp.write(reinterpret_cast<char*>(&ESTUDIANTES), sizeof(Estudiante));
    }

    archivo3.close();
    archivo_temp.close();

    if (encontrado) {
        remove("estudiantes.txt");
        rename("estudiantes_bajas.txt", "estudiantes.txt");

        cout << "El estudiante ha sido dado de baja exitosamente." << endl;
    } else {
        cout << "No se ha encontrado la matr�cula del alumno." << endl;
    }

    system("pause");
}

bool veri_menu(int num_menu) {
    menu MENU;
    ifstream archivo("menus.txt", ios::binary);
    
    if (archivo.fail()) {
        cout << "Error al abrir el archivo menus.txt para lectura" << endl;
        system("pause");
        exit(0);
    }
    
    bool encontrado = false;
    
    while (archivo.read(reinterpret_cast<char*>(&MENU), sizeof(menu))) {
        if (MENU.num_menu == num_menu) {
            encontrado = true;
            break;
        }
    }
    
    archivo.close();
    
    if (!encontrado) {
        cout << "El men� seleccionado no existe" << endl;
        return false;
    }
    
    return true;
}

void asignar_menu_estudiante() {
    menu MENU;
    const int MAX_PLATOS = 100; // Tama�o m�ximo del arreglo de platos
    plato platos[MAX_PLATOS]; // Arreglo para almacenar los platos registrados
    int contador_platos = 0;
    Estudiante ESTUDIANTES;
    AsignacionMenu asignacion;
    int matricula;
    int opcion;
    
    system("cls");
    cout << "Asignar men� por estudiante" << endl;
    
    do {
        do {
            cout << "N�mero de matr�cula del estudiante: ";
            cin >> matricula;
        } while (!veri_estudiante(matricula));

        // Obtener los platos del men� para cada d�a
        for (int i = 0; i < 5; i++) {
            cout << "D�a " << i+1 << endl;
            
            do {
                cout << "N�mero del men�: ";
                cin >> asignacion.num_menu;
            } while (!veri_menu(asignacion.num_menu));
            
            // Leer el men� desde el archivo
            ifstream archivo("menus.txt", ios::binary);
            if (archivo.fail()) {
                cout << "Error al abrir el archivo menus.txt para lectura" << endl;
                system("pause");
                exit(0);
            }
            
            bool encontrado = false;
            
            while (archivo.read(reinterpret_cast<char*>(&MENU), sizeof(menu))) {
                if (MENU.num_menu == asignacion.num_menu) {
                    // Verificar si el men� contiene ingredientes al�rgicos para el estudiante
                    bool contiene_alergia = false;
                    
                    for (int j = 0; j < MENU.cant_plato; j++) {
                        for (int k = 0; k < MENU.pla[j].cant_ingredientes; k++) {
                            for (int l = 0; l < ESTUDIANTES.cant_alergias; l++) {
                                if (strcmp(MENU.pla[j].ingrediente[k].nombre_ingrediente, ESTUDIANTES.alergias[l].ingrediente) == 0) {
                                    contiene_alergia = true;
                                    break;
                                }
                            }
                            
                            if (contiene_alergia) {
                                break;
                            }
                        }
                        
                        if (contiene_alergia) {
                            break;
                        }
                    }
                    
                    if (!contiene_alergia) {
                        encontrado = true;
                        break;
                    }
                }
            }
            
            archivo.close();
            
            if (!encontrado) {
                cout << "No hay men�s disponibles que no contengan ingredientes al�rgicos para el estudiante" << endl;
                system("pause");
                return;
            }
            
            // Solicitar al usuario el plato para el d�a correspondiente
            cout << "Plato para el d�a " << i+1 << ":" << endl;
            for (int j = 0; j < MENU.cant_plato; j++) {
                cout << j+1 << ". " << platos[contador_platos].nombre_plato  << endl;
            }
            do {
                cout << "Seleccione el n�mero del plato: ";
                cin >> asignacion.plato_dia[i];
            } while (asignacion.plato_dia[i] < 1 || asignacion.plato_dia[i] > MENU.cant_plato);
            
            // Guardar la asignaci�n en el archivo "asignaciones.txt"
            asignacion.matricula = matricula;
            asignacion.precio_platos[i] = MENU.pla[asignacion.plato_dia[i]-1].precio;
            
            ofstream archivo6("asignaciones.txt", ios::app | ios::binary);
            
            if (archivo6.fail()) {
                cout << "Error al abrir el archivo asignaciones.txt para escritura" << endl;
                system("pause");
                exit(0);
            }
            
            archivo6.write(reinterpret_cast<char*>(&asignacion), sizeof(AsignacionMenu));
            archivo6.close();
        }
        
        cout << "Men� asignado correctamente al estudiante" << endl;
        cout << "�Desea asignar otro men�? (1: S�, 2: No)" << endl;
        cout << "Opci�n: ";
        cin >> opcion;
        
        system("cls");
    } while (opcion == 1);
}

void listar_carta() {
	system("CLS");
    ifstream archivo("menus.txt", ios::in | ios::binary);
    if (archivo.fail()) {
        cout << "Error al abrir el archivo menus.txt para lectura" << endl;
        return;
    }

    menu MENU;
    archivo.read(reinterpret_cast<char*>(&MENU), sizeof(menu));
    while (!archivo.eof()) {
        cout << "N�mero de men�: " << MENU.num_menu << endl;
        cout << "Platos del men�: " << endl;
        for (int i = 0; i < MENU.cant_plato; i++) {
            cout << " - " << MENU.pla[i].nombre_plato << endl;
        }
        cout << endl;

        archivo.read(reinterpret_cast<char*>(&MENU), sizeof(menu));
    }

    archivo.close();
}
void mostrar_menu(int nro_menu) {
	system("CLS");
    ifstream archivo("menus.txt", ios::in | ios::binary);
    if (archivo.fail()) {
        cout << "Error al abrir el archivo menus.txt para lectura" << endl;
        return;
    }

    menu MENU;
    archivo.read(reinterpret_cast<char*>(&MENU), sizeof(menu));
    while (!archivo.eof()) {
        cout << "N�mero del men�: " << MENU.num_menu << endl;
        cout << "Platos del men�: " << endl;
        for (int i = 0; i < MENU.cant_plato; i++) {
            plato PLATO;
            archivo.read(reinterpret_cast<char*>(&PLATO), sizeof(plato));
            cout << " - " << PLATO.nombre_plato << endl;
            cout << "   Ingredientes: " << endl;
            for (int j = 0; j < PLATO.cant_ingredientes; j++) {
                ingre INGREDIENTE;
                archivo.read(reinterpret_cast<char*>(&INGREDIENTE), sizeof(ingre));
                cout << "    - " << INGREDIENTE.nombre_ingrediente << endl;
            }
        }
        cout << endl;

        archivo.read(reinterpret_cast<char*>(&MENU), sizeof(menu));
    }

    archivo.close();
}

void menu_por_estudiante() {
	system("cls");
    ifstream archivo("asignaciones.txt", ios::in | ios::binary);
    if (archivo.fail()) {
        cout << "Error al abrir el archivo asignaciones.txt para lectura" << endl;
        return;
    }

    AsignacionMenu asignacion;
    archivo.read(reinterpret_cast<char*>(&asignacion), sizeof(AsignacionMenu));
    while (!archivo.eof()) {
        cout << "Matr�cula: " << asignacion.matricula << endl;
        cout << "N�mero de men�: " << asignacion.num_menu << endl;
        cout << "Platos del men�: " << endl;
        for (int i = 0; i < 5; i++) {
            if (asignacion.plato_dia[i] != -1) {
                cout << "D�a " << (i + 1) << ": " << asignacion.plato_dia[i] << endl;
            }
        }
        cout << endl;

        archivo.read(reinterpret_cast<char*>(&asignacion), sizeof(AsignacionMenu));
    }

    archivo.close();
}
void listarEstudiantesConBaja() {
    Estudiante estudiante;
    system("cls");
    ifstream archivo_temp("estudiantes_bajas.txt", ios::binary);
    if (!archivo_temp) {
        cout << "Error al abrir el archivo de bajas.txt ." << endl;
        return;
    }

    cout << "Estudiantes con baja:" << endl;
    while (archivo_temp.read(reinterpret_cast<char*>(&estudiante), sizeof(Estudiante))) {
        if (estudiante.fechaBaja.dia != 0) {
            cout << "N�mero de matr�cula: " << estudiante.matricula << endl;
            cout << "Nombre: " << estudiante.nombre << endl;
            cout << "Fecha de ingreso: " << estudiante.fechaIngreso.dia << "/" << estudiante.fechaIngreso.mes << "/" << estudiante.fechaIngreso.anio << endl;
            cout << "Fecha de baja: " << estudiante.fechaBaja.dia << "/" << estudiante.fechaBaja.mes << "/" << estudiante.fechaBaja.anio << endl;
            cout << endl;
        }
    }

    archivo_temp.close();
}
void listarEstudiantesActivos() {
    Estudiante estudiante;
    system("cls");
    ifstream archivo2("estudiantes.txt", ios::binary);
    if (!archivo2) {
        cout << "Error al abrir el archivo de estudiantes.txt" << endl;
        return;
    }

    cout << "Estudiantes activos:" << endl;
    while (archivo2.read(reinterpret_cast<char*>(&estudiante), sizeof(Estudiante))) {
        if (estudiante.activo) {
            cout << "N�mero de matr�cula: " << estudiante.matricula << endl;
            cout << "Nombre: " << estudiante.nombre << endl;
            cout << "Acudiente: " << estudiante.familiar[0].nombre << endl;
            cout << "Tel�fono: " << estudiante.familiar[0].telefono << endl;
            cout << endl;
        }
    }

    archivo2.close();
}

void consultaEstudiante(int numeroMatricula) {
	
    Estudiante estudiante;
    system("cls");
    ifstream archivo("estudiantes.txt", ios::binary);
    if (!archivo) {
        cout << "Error al abrir el archivo de estudiantes.txt." << endl;
        return;
    }

    bool encontrado = false;
    while (archivo.read(reinterpret_cast<char*>(&estudiante), sizeof(Estudiante))) {
        if (estudiante.matricula == numeroMatricula) {
            encontrado = true;
            break;
        }
    }

    archivo.close();

        cout << "N�mero de matr�cula: " << estudiante.matricula << endl;
        cout << "Nombre: " << estudiante.nombre << endl;
        cout << "Fecha de ingreso: " << estudiante.fechaIngreso.dia << "/" << estudiante.fechaIngreso.mes << "/" << estudiante.fechaIngreso.anio << endl;

        cout << "Alergias: " << estudiante.cant_alergias << endl;
        cout << "Acudiente: " << estudiante.familiar[0].nombre << endl;
        //cout << "Valor de la mensualidad: " << estudiante.valorMensualidad << endl;

        if (estudiante.estadoPago) {
            cout << "Estado de pago: Paz y salvo" << endl;
        } else {
            cout << "Estado de pago: Moroso" << endl;
        }
}







