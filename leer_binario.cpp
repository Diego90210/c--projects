/*Programa que permite leer un archivo binario y calcular la nómina total de una empresa, así como el sueldo mas alto y el mas bajo*/

#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <iomanip>

using namespace std;

struct empleados{
	char nombre[30];
	char cargo[30];
	long basico, salud, pension, sueldo;
	float horas;
	
	
};

int main(){
	empleados nomina;
	long max =0, min =999999, total=0;
	int ne=0;
	//abrirmos el archivo y verificamos que no haya problemas de apertura
	ifstream archivoE("NOMINA.TXT", ios::in | ios::binary);
	if(archivoE.fail()){
		cout<<"Error al abrir el archivo para leer"; system("pause"); exit(0);
	}
	archivoE.read(reinterpret_cast<char *> (&nomina), sizeof(empleados));//leer la información del primer registro del archivo
	cout<<setw(30)<<"NOMBRE" <<setw(30)<<"CARGO" <<setw(10)<<"BASICO" <<setw(10)<<"HORAS TRAB."  <<setw(10)<<"SUELDO"	<<setw(10) <<"PENSION"	<<setw(10) <<"SALUD"	<<setw(10) <<"NETO" <<endl;
	
	while(!archivoE.eof()){ //visualizamos el archivo
		ne++; //contador de empleados
		cout<<setw(30)<<nomina.nombre <<setw(30) <<nomina.cargo <<setw(10) <<nomina.sueldo <<setw(10)	<<nomina.horas <<setw(10) <<nomina.sueldo	<<setw(10)<<nomina.pension	<<setw(10) <<nomina.salud <<setw(10)	<<nomina.sueldo-nomina.pension-nomina.salud <<endl;
		total += nomina.sueldo-nomina.pension-nomina.salud;
		
		if(max <nomina.sueldo-nomina.pension-nomina.salud) //determinamos cual es el sueldo maximo
		   max = nomina.sueldo-nomina.pension-nomina.salud;
		
		if(min > nomina.sueldo-nomina.pension-nomina.salud) //determinamos cual es el sueldo minimo
		   min = nomina.sueldo-nomina.pension-nomina.salud;
		   
		   
		archivoE.read(reinterpret_cast<char *> (&nomina), sizeof(empleados)); //leer el siguiente registro
	}
	archivoE.close();
	cout<<endl <<"TOTAL NOMINA: $" <<total;
	cout<<endl <<"TOTAL EMPLEADOS:" <<ne ;
	cout<<endl <<"SUELDO MAXIMO:" <<max ;
	cout<<endl <<"SUELDO MINIMO:" <<min <<endl;

	system("pause");
	return 0;
	
}
