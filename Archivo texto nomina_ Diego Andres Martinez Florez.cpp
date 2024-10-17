//Diego Andres Martinez Florez: 0222120002.

#include <iostream>
#include <string.h>
#include <fstream>
#include <iomanip>
using namespace std;
struct nomina{
	char nombre[50];
	long Id;
	int ht;
	int vh;
	int he=0;
	long salario_ord;
	long salario_extra;
	char eps[50];
	char nom_pension[50];
	long salud;
	long pension;
	long neto;
	bool estado_nomina = false; 
}nominas[100];
int menu();
void ingresar(struct nomina nominas[], int &cont_empleados);
void calcular(struct nomina nominas[], int cont_empleados);
void consultas(struct nomina nominas[], int cont_empleados);
void consulta_empleado (struct nomina nominas[], int cont_empleados); 
void reporte_nomina (struct nomina nominas[], int cont_empleados);
void reporte_horas_extra (struct nomina nominas[], int cont_empleados);
void banco(struct nomina nominas[], int cont_empleados);
void generar_archivo (struct nomina nominas[], int cont_empleados);
void imprimir_archivo (struct nomina nominas[], int cont_empleados); 
void pila(struct nomina nominas[], int cont_empleados);
void generar_pila (struct nomina nominas[], int cont_empleados);
void imprimir_pila (struct nomina nominas[], int cont_empleado);
//*******************************************************************************************
int main()
{
	int opc, cont_empleados=0;
	do
	{
		system("cls");
		opc = menu();
		switch(opc)
		{
			case 1: ingresar(nominas, cont_empleados); break;
			case 2:
				if (cont_empleados>0){
					calcular(nominas, cont_empleados); 
				}
				else{
					system("cls");
					cout<<"Debe registrar al menos un empleado para acceder a esta opción"<<endl;
					system("pause");
				}
			break;
			case 3:
				if (cont_empleados>0){
					consultas(nominas, cont_empleados);
				}
				else{
					system("cls");
					cout<<"Debe registrar al menos un empleado para acceder a esta opción"<<endl;
					system("pause");
				}
			break;
			case 4:
				if (cont_empleados>0){
					banco(nominas, cont_empleados);
				}
				else{
					system("cls");
					cout<<"Debe registrar al menos un empleado para acceder a esta opción"<<endl;
					system("pause");
				}
			break;
			case 5:pila(nominas, cont_empleados);break;
			case 6:exit(0);
		}
	}while(opc!=6);
}
//********************************************************
int menu(){
	int opc;
	setlocale(LC_ALL,"spanish");
	do
	{
		system("cls");
		cout<<"Pago de Nomina" <<endl;
		cout<<"1.Ingresar Datos Nomina" <<endl;
		cout<<"2.Calcular Nomina" <<endl;
		cout<<"3.Consultas" <<endl;
		cout<<"4.Información Banco" <<endl;
		cout<<"5.Pago de Pila"<<endl;
		cout<<"6.Salir"<<endl;
		cout<<"Seleccione un proceso: ";
		cin>>opc;
	}while(opc<1 || opc>6);
	return opc;
}
//********************************************************
void ingresar(struct nomina nominas[], int &cont_empleados)
{
	int sw, salida;
	nomina aux;
	do{
		system("cls");
		sw=0;
		cout<<"Ingresando datos del empleado No. "<<cont_empleados+1<<endl;
		do{
			cout<<"ID: ";
			cin>>aux.Id;

			if (aux.Id<=0){
				cout<<"El ID debe ser mayor que cero (0)"<<endl;
				system("pause");
			}
		}while(aux.Id<=0);
		
		for (int i=0; i<cont_empleados; i++){ //Verifica si el ID ingresado ya se encuentra registrado.
			if (aux.Id == nominas[i].Id){
				sw=1;
				break;
			}
		}

		if (sw==1){
			cout<<"El ID ingresado ya se encuentra registrado"<<endl;
			system("pause");
			system("cls");
		}
		else{
			cout<<"Nombre del trabajador: ";
			fflush(stdin); 
			gets(aux.nombre);

			for (int i=0; aux.nombre[i]!='\0'; i++){ //Convierte la cadena a mayúsculas para facilitar procesos.
				aux.nombre[i] = toupper (aux.nombre[i]);
			}

			do{
				cout<<"Horas trabajadas: ";
				cin>>aux.ht;

				if (aux.ht<=0){
					cout<<"Las horas trabajadas deben ser mayores a cero (0)"<<endl;
					system("pause");
				}
			}while(aux.ht<=0);

			do{
				cout<<"Valor hora: ";
				cin>>aux.vh;

				if (aux.vh<=0){
					cout<<"El valor de la hora debe ser mayor a cero (0)"<<endl;
					system("pause");
				}
			}while(aux.vh<=0);

			cout<<"Nombre de la EPS: ";
			fflush(stdin); 
			gets(aux.eps);

			cout<<"Empresa administradora de fondo de pensión: ";
			fflush(stdin);
			gets(aux.nom_pension);

			//Se guardan los datos ingresados.
			nominas[cont_empleados].Id = aux.Id;
			strcpy (nominas[cont_empleados].nombre, aux.nombre);
			nominas[cont_empleados].ht = aux.ht;
			nominas[cont_empleados].vh = aux.vh;
			strcpy (nominas[cont_empleados].eps, aux.eps);
			strcpy (nominas[cont_empleados].nom_pension, aux.nom_pension);
			cont_empleados++; 
			cout<<"Registro exítoso"<<endl;
			system("pause");
		}

		cout<<"Desea registrar otro empleado ? [1-Si] [Otro Num-No]: ";
		cin>>salida;
	}while(salida==1);
	
}
//********************************************************
void calcular(struct nomina nominas[], int cont_empleados)
{
	system("cls");
	int sw, in_empleado, salida;
	nomina aux;
	do{
		sw=0;
		cout<<"Calcular nómina"<<endl;
		cout<<"Ingrese el ID del empleado: ";
		cin>>aux.Id;

		for (int i=0; i<cont_empleados; i++){ //Encuentra el ID del empleado.
			if (aux.Id == nominas[i].Id){
				in_empleado=i; 
				sw=1;
				break;
			}
		}

		if (sw==1){
			if (nominas[in_empleado].ht>40){
				nominas[in_empleado].he = nominas[in_empleado].ht - 40;
			}
			else{
				nominas[in_empleado].he=0;
			}
			nominas[in_empleado].salario_ord = (nominas[in_empleado].ht - nominas[in_empleado].he)*nominas[in_empleado].vh;
			nominas[in_empleado].salario_extra = nominas[in_empleado].he * (nominas[in_empleado].vh *2);
			aux.neto = nominas[in_empleado].salario_ord + nominas[in_empleado].salario_extra;
			nominas[in_empleado].salud = aux.neto*0.04;
			nominas[in_empleado].pension = aux.neto*0.04;
			nominas[in_empleado].neto = aux.neto - (nominas[in_empleado].salud + nominas[in_empleado].pension);
			nominas[in_empleado].estado_nomina = true;

			cout<<endl;
			cout<<"ID: "<<nominas[in_empleado].Id<<endl;
			cout<<"Nombre: "<<nominas[in_empleado].nombre<<endl;
			cout<<"Horas ordinarias trabajadas: "<<(nominas[in_empleado].ht - nominas[in_empleado].he)<<endl;
			cout<<"Horas extras trabajadas: "<<nominas[in_empleado].he<<endl;
			cout<<"Valor de la hora: "<<nominas[in_empleado].vh<<endl;
			cout<<"Salario ordinario: "<<nominas[in_empleado].salario_ord<<endl;
			cout<<"Salario horas extra: "<<nominas[in_empleado].salario_extra<<endl;
			cout<<"Descuento por salud y pensión: "<<(nominas[in_empleado].salud + nominas[in_empleado].pension)<<endl;
			cout<<"Neto a pagar: "<<nominas[in_empleado].neto<<endl;
			system("pause");
			system("cls");
		}
		else{
			cout<<endl;
			cout<<"El ID ingresado no se ha encontrado"<<endl;
		}
		cout<<endl;
		cout<<"Desea generar otra nómina? [1-Si] [Otro num-No]: ";
		cin>>salida;
		system("cls");
	}while(salida==1);

}

void consulta_empleado (struct nomina nominas[], int cont_empleados){
	int aux_id, in_empleado, sw;
	system("cls");
	sw=0;
	cout<<"Ingrese el id del empleado: ";
	cin>>aux_id;

	for (int i=0; i<cont_empleados; i++){
		if (aux_id == nominas[i].Id){
			if (nominas[i].estado_nomina == true){
				in_empleado = i;
				sw=1;
			}
		}
	}

	if (sw==1){
		cout<<endl;
		cout<<"ID: "<<nominas[in_empleado].Id<<endl;
		cout<<"Nombre: "<<nominas[in_empleado].nombre<<endl;
		cout<<"Horas ordinarias trabajadas: "<<(nominas[in_empleado].ht - nominas[in_empleado].he)<<endl;
		cout<<"Horas extras trabajadas: "<<nominas[in_empleado].he<<endl;
		cout<<"Valor de la hora: "<<nominas[in_empleado].vh<<endl;
		cout<<"Salario ordinario: "<<nominas[in_empleado].salario_ord<<endl;
		cout<<"Salario horas extra: "<<nominas[in_empleado].salario_extra<<endl;
		cout<<"Descuento por salud y pensión: "<<(nominas[in_empleado].salud + nominas[in_empleado].pension)<<endl;
		cout<<"Neto a pagar: "<<nominas[in_empleado].neto<<endl;
		system("pause");
		system("cls");
	}
	else{
		cout<<"El ID ingresado no se ha encontrado o la nómina del empleado no ha sido generada"<<endl;
		system("pause");
		system("cls");
	}
}

void reporte_nomina (struct nomina nominas[], int cont_empleados){
	int indice_menor, comparar, i, j;
	nomina aux;
	//Ordenamiento por selección.
	for (i=0; i<(cont_empleados-1); i++){ //No llegamos hasta el final del arreglo, ya que esté estará ordenado en ese punto.
		indice_menor = i;

		for (j=i+1; j<cont_empleados; j++){ //Comparamos el actual elemento "menor" con los demás elementos.
			comparar = strcmp (nominas[indice_menor].nombre, nominas[j].nombre);
			if (comparar>0){ //Si se encuentra un elemento menor que el actual, el indice cambia su valor al elemento encontrado.
				indice_menor = j;
			}
		}

		if (indice_menor!=i){ //Si el indice del elemento menor es diferente al actual, realizamos un "cambio".
			aux = nominas[i];
			nominas[i] = nominas[indice_menor];
			nominas[indice_menor] = aux;
		}
	}
	cout<<endl;
	for (int i=(cont_empleados-1); i>=0; i--){
		if (nominas[i].estado_nomina == true){
			cout<<"ID: "<<nominas[i].Id<<endl;
			cout<<"Nombre: "<<nominas[i].nombre<<endl;
			cout<<"Horas ordinarias trabajadas: "<<(nominas[i].ht - nominas[i].he)<<endl;
			cout<<"Horas extras trabajadas: "<<nominas[i].he<<endl;
			cout<<"Valor de la hora: "<<nominas[i].vh<<endl;
			cout<<"Salario ordinario: "<<nominas[i].salario_ord<<endl;
			cout<<"Salario horas extra: "<<nominas[i].salario_extra<<endl;
			cout<<"Descuento por salud y pensión: "<<(nominas[i].salud + nominas[i].pension)<<endl;
			cout<<"Neto a pagar: "<<nominas[i].neto<<endl;
			cout<<"-------------------------------------------------------"<<endl;
		}
	}
	system("pause");
	system("cls");
}

void reporte_horas_extra (struct nomina nominas[], int cont_empleados){
	int i, j, indice_menor;
	float sum_extra=0, emple_extra=0, no_extra=0, porcentaje=0, prom_extra=0;

	nomina aux;

	for (i=0; i<(cont_empleados-1); i++){
		indice_menor = i;
		for (j=i+1; i<cont_empleados; j++){
			if ((nominas[indice_menor].he)>nominas[j].he){
				indice_menor = j;
			}
		}
		if (indice_menor!=i){
			aux = nominas[i];
			nominas[i] = nominas[indice_menor];
			nominas[indice_menor] = aux;
		}
	}

	for (int x=0; x<cont_empleados; x++){
		if ((nominas[x].he>0) && (nominas[x].estado_nomina == true)){
			cout<<endl;
			cout<<"ID: "<<nominas[x].Id<<endl;
			cout<<"Nombre: "<<nominas[x].nombre<<endl;
			cout<<"Horas extras: "<<nominas[x].he<<endl;
			cout<<"Salario horas extras: "<<nominas[x].salario_extra<<endl;
			sum_extra+=nominas[x].salario_extra;
			emple_extra++;
		}

		if ((nominas[x].he==0) && (nominas[x].estado_nomina == true)){
			no_extra++;
		}
	}

	porcentaje=(no_extra/cont_empleados)*100;
	prom_extra=sum_extra/emple_extra;
	cout<<"Porcenjate de empleados sin horas extras: "<<porcentaje<<"%"<<endl;
	cout<<"Promedio de horas extras: "<<prom_extra<<endl;
	system("pause");
}

void consultas(struct nomina nominas[], int cont_empleados)
{
	int op;
	system("cls");
	do{
		cout<<"1. Consulta a un empleado"<<endl;
		cout<<"2. Reporte nómina"<<endl;
		cout<<"3. Reporte horas extras"<<endl;
		cout<<"Ingrese una opción: ";
		cin>>op;
	}while(op<1 || op>3);

	switch (op){
		case 1: consulta_empleado (nominas, cont_empleados);
		break;
		case 2:	reporte_nomina (nominas, cont_empleados);
		break;
		case 3: reporte_horas_extra (nominas, cont_empleados);
		break;
	}
} 

void generar_archivo (struct nomina nominas[], int cont_empleados){
	ofstream a("nomina.txt");
	long total_nom=0;
	if (a.fail()){
		cout<<"Error al crear el archivo nominas.txt"<<endl;
		system("pause");
		exit(0);
	}
	for (int i=0; i<cont_empleados; i++){
		if (nominas[i].estado_nomina==true){
			total_nom+=nominas[i].neto;
		}
	}
	for (int i=0; i<cont_empleados; i++){
		if (nominas[i].estado_nomina==true){
			a<<"Nombre: "<<nominas[i].nombre<<" ; "<<" ID: "<<nominas[i].Id<<" ; "<<" Salario: "<<nominas[i].neto<<endl;
		}
	}
	a<<"Total nomina: "<<total_nom<<endl;
	a<<"Cantidad de empleados: "<<cont_empleados<<endl;
	a.close();
}

void imprimir_archivo (struct nomina nominas[], int cont_empleados){
	system("cls");
	nomina aux;
	ifstream a("nomina.txt");
	if (a.fail()){
		cout<<"Error al abrir el archivo nomina.txt para lectura"<<endl;
		system("pause");
		exit(0);
	}
	a>>aux.nombre;
	while (!a.eof()){
		cout<<aux.nombre<<endl;
		a>>aux.nombre;
	}
	system("pause");
	a.close();
}

void banco(struct nomina nominas[], int cont_empleados)
{
	system("cls");
	int op;
	static int sw=0;
	do{
		cout<<"1. Generar un archivo de texto al banco"<<endl;
		cout<<"2. Imprimir un archivo de texto enviado al banco"<<endl;
		cout<<"Ingrese una opción: ";
		cin>>op;
	}while(op<1 || op>2);

	switch (op){
		case 1:
			sw=1;	
			generar_archivo (nominas, cont_empleados);
		break;
		case 2:	
			if (sw==1){
				imprimir_archivo (nominas, cont_empleados);
			}
			else{
				system("cls");
				cout<<"Primero debe generar el archivo antes de imprimirlo"<<endl;
				system("pause");
			}
		break;
	}
}

void generar_pila (struct nomina nominas[], int cont_empleados){
	ofstream a("pila.txt");
	if (a.fail()){
		cout<<"Error al crear el archivo pila.txt"<<endl;
		system("pause");	
		exit(0);
	}
	for (int i=0; i<cont_empleados; i++){
		if (nominas[i].estado_nomina == true){
			a<<"Nombre: "<<nominas[i].nombre<<" ; "<<"ID: "<<nominas[i].Id<<" ; "<<"EPS: "<<nominas[i].eps<<" ; "<<"Aporte salud: "<<nominas[i].salud<<" ; "<<"Empresa pension: "<<nominas[i].nom_pension<<" ; "<<"Aporte pensión: "<<nominas[i].pension<<endl;
		}
	}
	a.close();
}

void imprimir_pila (struct nomina nominas[], int cont_empleado){
	system("cls");
	ifstream a("pila.txt");
	nomina aux;
	if (a.fail()){
		cout<<"Error al abrir el archivo pila.txt para lectura"<<endl;
		system("pause");	
		exit(0);
	}
	a>>aux.nombre;
	while (!a.eof()){
		cout<<aux.nombre<<endl;
		a>>aux.nombre;
	}
	system("pause");
	a.close();
}

void pila(struct nomina nominas[], int cont_empleados)
{	int op;
	static int sw=0;
	system("cls");
	do{
		cout<<"1.Generar archivo de texto para pago de pila"<<endl;
		cout<<"2.Imprimir archivo pila"<<endl;
		cout<<"Ingrese una opción: ";
		cin>>op;
	}while(op<1 || op>2);

	switch (op){
		case 1:
			sw=1;
			generar_pila (nominas, cont_empleados);
		break;
		case 2: 
			if (sw==1){
				imprimir_pila (nominas, cont_empleados);
			}
			else{
				system("cls");
				cout<<"Primero debe generar el archivo antes de imprimirlo"<<endl;
				system("pause");
			}
		break;
	}
}
//********************************************************
