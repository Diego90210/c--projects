#include <iostream>
#include <fstream>
using namespace std;

struct Taxista{
	long codigo;
	char nombre[50];
	char telefono[15];
};

struct Salario{
	long codigo;
	int carreras[7];
	float pago;
};

void menu();
bool validarIdTaxista(long id);
void registrarSocio();
void generarNomina();
void consultarTaxista();
int main(){
	//ifstream ios::in
	ofstream archivo1("taxistas.txt", ios::app | ios::binary);
	if(archivo1.fail()){
		cout<<"Error al abrir el archivo taxistas.txt"<<endl;
		exit(0);
	}
	archivo1.close();
	ofstream archivo2("salarios.txt", ios::app | ios::binary);
	if(archivo2.fail()){
		cout<<"Error al abrir el archivo salarios.txt"<<endl;
		exit(0);
	}
	archivo2.close();
	menu();
}
void menu(){
	int opc;
	do{
		cout<<" === MENU PRINCIPAL ==="<<endl;
		cout<<"1. Registrar socio"<<endl;
		cout<<"2. Generar nomina"<<endl;
		cout<<"3. Consultar taxista"<<endl;
		cout<<"4. Reporte de nomina"<<endl;
		cout<<"5. Salir"<<endl;
		cout<<"Ingrese una opcion: ";
		cin>>opc;
		switch(opc){
			case 1:
				registrarSocio();
				break;
			case 2:
				generarNomina();
				break;
			case 3:
				consultarTaxista();
				break;
			case 4:
				break;
			case 5:
				cout<<"Saliendo. . ."<<endl;
				break;
		}
	}while(opc != 5);
}

bool validarIdTaxista(long id){
	Taxista taxista;
	ifstream archivo("taxistas.txt", ios::in | ios::binary);
	if(archivo.fail()){
		cout<<"Error al abrir el archivo taxistas.txt"<<endl;
		exit(0);
	}
	archivo.read(reinterpret_cast<char*>(&taxista), sizeof(Taxista));
	while(!archivo.eof()){
		if(taxista.codigo == id){
			return true;
		}
		archivo.read(reinterpret_cast<char*>(&taxista), sizeof(Taxista));
	}
	return false;
}

void registrarSocio(){
	Taxista taxista;
	char continuar;
	do{
		cout<<" === REGISTRAR SOCIO ==="<<endl;
		do{
			cout<<"Ingrese el id: "; cin>>taxista.codigo;
			if(validarIdTaxista(taxista.codigo)){
				cout<<"Error: el id ya fue registrado"<<endl;
				continue;
			}
			break;
		}while(true);
		cout<<"Ingrese el nombre: "; fflush(stdin); gets(taxista.nombre);
		cout<<"Ingrese el telefono: "; fflush(stdin); gets(taxista.telefono);
		cout<<"desea ingresar otro usuario S/N: "; cin>>continuar;
		ofstream archivo("taxistas.txt", ios::app | ios::binary);
		if(archivo.fail()){
			cout<<"Error al abrir el archivo taxistas.txt"<<endl;
			exit(0);
		}
		archivo.write(reinterpret_cast<char*>(&taxista), sizeof(Taxista));
		archivo.close();
		continuar = toupper(continuar);
	}while(continuar == 'S');
}

void generarNomina(){
	Salario salario;
	char continuar;
	do{
		cout<<" === GENERAR NOMINA ==="<<endl;
		do{
			cout<<"Ingrese el id del taxista: "; cin>>salario.codigo;
			if(!validarIdTaxista(salario.codigo)){
				cout<<"El taxista no esta registrado"<<endl;
				continue;
			}
			break;
		}while(true);
		salario.pago = 0;
		for(int i = 0; i < 7; i++){
			cout<<"Ingrese la cantidad de carreras en el dia #"<<i+1<<": ";
			cin>>salario.carreras[i];

			if(salario.carreras[i] <= 10){
				salario.pago += salario.carreras[i] * 2000;
			}
			else if(salario.carreras[i] <= 30){
				salario.pago += salario.carreras[i] * 4000;
			}
			else{
				salario.pago += salario.carreras[i] * 5000;
			}
		}
		cout<<"desea ingresar otro usuario S/N: "; cin>>continuar;
		continuar = toupper(continuar);
		ofstream archivo("salarios.txt", ios::app | ios::binary);
		if(archivo.fail()){
			cout<<"Error al abrir el archivo salarios.txt"<<endl;
			exit(0);
		}
		archivo.write(reinterpret_cast<char*>(&salario), sizeof(Salario));
		archivo.close();
		system("pause");
	}while(continuar == 'S');
}


void consultarTaxista(){
	char continuar;
	long codigo;
	Taxista taxista;
	Salario salario;
	do{
		cout<<" === CONSULTAR TAXISTA ==="<<endl;
		do{
			cout<<"Ingrese el id del taxista: "; cin>>codigo;
			if(!validarIdTaxista(codigo)){
				cout<<"El taxista no esta registrado"<<endl;
				continue;
			}
			break;
		}while(true);
	}while(continuar == 'S');
	ifstream archivoLec("taxistas.txt", ios::in | ios::binary);
	if(archivoLec.fail()){
		cout<<"Error al abrir el archivo taxistas.txt"<<endl;
		exit(0);
	}
	archivoLec.read(reinterpret_cast<char*>(&taxista), sizeof(Taxista));
	while(!archivoLec.eof()){
		if(taxista.codigo == codigo){
			
			break;
		}
		archivoLec.read(reinterpret_cast<char*>(&taxista), sizeof(Taxista));
	}
	
	cout<<"Nombre del taxista: "<<taxista.nombre<<endl;
	ifstream archivo("salarios.txt", ios::in | ios::binary);
	if(archivo.fail()){
		cout<<"Error al abrir el archivo salarios.txt"<<endl;
		exit(0);
	}
	archivo.read(reinterpret_cast<char*>(&salario), sizeof(Salario));
	while(!archivo.eof()){
		//salario -> id -> break -> salario
		if(salario.codigo == codigo){
			break;
		}
		archivo.read(reinterpret_cast<char*>(&salario), sizeof(Salario));
	}
	for(int i = 0; i < 7; i++){
		cout<<"Cantidad de carreras en el dia #"<<i+1<<": "<<salario.carreras[i]<<endl;
	}
	cout<<"Salario del taxista: "<<salario.pago<<endl;
	system("pause");
}
