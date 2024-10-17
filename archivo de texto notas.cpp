/*Programa que permite realizar los procesos de creación y lectura de archivo de texto
a partir de la información registrada de los estudiantes de la asignatura programación cuyos datos 
correspondiente a codigo, nombre, nota parcial 1, parcial 2, parcial 3 y definitiva se encuentran 
en un vector de struct. Los porcentajes para calcular la definitiva son 30%,30% y 40% respectivamente
El archivo debe adicional contener el promedio del grupo, porcentaje de estudiantes aprobados y reprobados.*/

#include <iostream>
#include <fstream>//las funciones para escribir (ofstream) y leer (ifstream) un archivo de texto 
using namespace std;

struct datos
{
	long cod;
	string nombre;
	float p1;
	float p2;
	float p3; 
	float def;
};
//Declarar funciones 
void registrar(struct datos notas[], int N);
void crear_archivo(struct datos notas[], int N);
void leer_archivo();
//***********************************************************
int main()
{
	int N;
	setlocale(LC_ALL, "spanish");
	cout<<"Cantidad de estudiantes de la asignatura programación: ";
	cin>>N;
	datos notas[N];	
	int opc;
	do
	{
		system("cls");
		cout<<"REGISTRO DE NOTAS"<<endl;
		cout<<"1. Registrar notas de estudiates"<<endl;
		cout<<"2. Crear archivo de notas"<<endl;
		cout<<"3. Leer archivo de notas"<<endl;
		cout<<"4. Salir"<<endl;
		cout<<"Seleccione el proceso a realizar: ";
		cin>>opc;
		switch(opc)
		{
			case 1: registrar(notas, N); break;
			case 2: crear_archivo(notas, N); break;
			case 3: leer_archivo(); break;
			case 4: exit(0);
			default: cout<<"Opción es incorrecta"<<endl; system("pause");
		}
	}while(opc!= 4);
}
//****** PROTOTIPOS DE LAS FUNCIONES *******
void registrar(struct datos notas[], int N)
{
	for(int x=0; x<N; x++)
	{
		cout<<"Registrando notas estudiante #"<<x+1 <<endl;
		cout<<"Código: "; cin>>notas[x].cod;
		cout<<"Nombre: "; fflush(stdin); getline(cin, notas[x].nombre);
		cout<<"Nota parcial 1: "; cin>>notas[x].p1;
		cout<<"Nota parcial 2: "; cin>>notas[x].p2;
		cout<<"Nota parcial 3: "; cin>>notas[x].p3;
		notas[x].def = notas[x].p1*0.3 + notas[x].p2*0.3 + notas[x].p3*0.4;
		cout<<"Nota definitiva: "<<notas[x].def <<endl;
		system("pause");
	}
}
/**************************************************************/
void crear_archivo(struct datos notas[], int N)
{
	system("cls");
	float sumatoria=0, promedio;
	float aprob=0, reprob=0, porc_aprob, porc_reprob;
	//crear un archivo de texto y escribir la información del vector de registro en dicho archivo
	ofstream archivo("notas.txt");
	//validamos que no se presenten fallos al momento de abrir el archivo
	if(archivo.fail())//si hay fallo entrará por el if y mostrará el mensaje de error y sale del programa
	{
		cout<<"ERROR al abrir el archivo notas.txt para escritura"<<endl;
		system("pause");
		exit(0);
	}
 //continuará si no hay fallos al momento de abrir el archivo
 //recorrer el vector de registro y copiar cada uno de los registros en el archivo notas.txt
 for(int x=0; x<N; x++)
 {
 	//escribir en el archivo notas.txt
 	archivo<<notas[x].nombre<<";" <<notas[x].cod<<";" <<notas[x].p1<<";" <<notas[x].p2<<";" <<notas[x].p3<<";" <<notas[x].def<<endl;	
 	if(notas[x].def < 3.0)//para calcular los porcentajes
 	{
 		reprob++;
	}
    else
    {
    	aprob++;
	}
	sumatoria += notas[x].def; //calcular el promedio del grupo
 }
 //cuando sale de escribir todos los registros del vector de registro
 promedio = sumatoria/N; 
 porc_aprob = aprob*100/N;
 porc_reprob = reprob*100/N;
 //escribirlos en el archivo notas.txt
 archivo<<"Promedio_grupo:"<<promedio<<endl;
 archivo<<"Porcentaje_aprobados:"<<porc_aprob<<"%"<<endl;
 archivo<<"Porcentaje_reprobados:"<<porc_reprob<<"%\n";
 //cerrar el archivo
 archivo.close();
 cout<<"Se creó el archivo notas.txt de manera exitosa"<<endl;
 system("pause");	
}
/************************************************************/
void leer_archivo()
{
	system("cls");
	//abrir el archivo notas.txt para leerlo
	ifstream archivo("notas.txt");
	//validar que no hubo fallos al momento de abrir el archivo
	if(archivo.fail())//si hay fallo entrará por el if y mostrará el mensaje de error y sale del programa
	{
		cout<<"ERROR al abrir el archivo notas.txt para lectura"<<endl;
		system("pause");
		exit(0);
	}
 //sino hibo fallos continuará el proceso 
 //leer el primer registro del archivo para mostrarlo posteriormente en pantalla
 datos mostrar;
 archivo>>mostrar.nombre;  //lee un registro del archivo notas.txt y lo copia en la variable mostrar
 //recorrer todo el archivo 
 while(!archivo.eof())//verificamos que no se haya alcanzado el fin de archivo, cuando no hay mas información en el archivo para leer
 {
 	//mostrar la información que se leyó del archivo en la pantalla con un cout
 	cout<<mostrar.nombre<<endl;
 	//es volver a leer para avanzar al siguiente registro o línea del archivo, en caso de no hacerlo se genera un loop
 	archivo>>mostrar.nombre; 
 }
 //cerrar el archivo
 archivo.close();
 system("pause");	
}
