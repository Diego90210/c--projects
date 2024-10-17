/*Para cada uno de los empleados se tienen los siguientes datos:
Nombre del empleado.
Salario básico por hora.
Horas ordinarias trabajadas.
Horas extras diurnas trabajadas.
Horas extras nocturnas trabajadas.
Horas extras dominicales trabajadas

Teniendo en cuenta que las horas extras tienen los siguientes recargos:
Horas extras diurnas: 25%.
Horas extras nocturnas: 50%.
Horas extras dominicales: 75%.
Y que el 10% de retención en la fuente se aplica a las horas extras trabajadas, solo si el valor devengado por este concepto es superior a $200.000.

Se debe implementar un programa con las siguientes opciones
NOMINA
1. Registro de empleados (No pueden estar registrados más de un empleado con el mismo id)
2. Cargar datos nomina (pedir el id y validar que esté registrado)
3. Generar nómina
4. Consultar un empleado (pedir el id y mostrar Salario básico por hora, horas ordinarias, horas extras diurnas, nocturnas y dominicales, retención en la fuente, salario básico, salario extras, salario neto
5. Reporte de nómina (mostrar id, nombre, total horas extras, salario extras, retención en la fuente salario neto*/
#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
using namespace std;
/*************************************************/
struct trabajador
{
	long id;
	char nom[50];
	char cargo[50];
	char dependencia[50];
};

struct nomina
{
	long id;
	int sbh; //Salario básico por hora.
	int ho; //Horas ordinarias trabajadas.
	int hedi;//Horas extras diurnas trabajadas.
	int hen;//Horas extras nocturnas trabajadas.
	int hedo;//Horas extras dominicales trabajadas
	long she;//salario por horas extras
	long sb; //salario basico;
	long sn; //salario neto
	long rf; //retención en la fuente
};
/*************************************************/
int menu();
bool val_emp(long wid, char* nom);
bool val_nomina(long wid);
void reg_emp();
void reg_nom();
void cal_nom();
void cons_emp();
void rep_nom();
void open_file();
/*************************************************/
int main()
{
	int op;
	open_file();
	setlocale(LC_ALL,"spanish");
	do
	{
		system("cls");
		switch(menu())
		{
			case 1: reg_emp(); break;
			case 2: reg_nom(); break;
			case 3: cal_nom(); break;
			case 4: cons_emp(); break;
			case 5: rep_nom(); break;
			case 6: exit(0);
		}
	}while(op!=6);	
}
/*************************************************/
int menu()
{
	int opc;
	do
	{
		system("cls");
		cout<<"NOMINA"<<endl;
		cout<<"1. Registro de empleados"<<endl;
		cout<<"2. Cargar datos nomina"<<endl;
		cout<<"3. Generar nómina"<<endl;
		cout<<"4. Consultar un empleado"<<endl;
		cout<<"5. Reporte de nómina"<<endl;
		cout<<"6. Salir "<<endl;
		cout<<"Seleccionar el proceso a realizar: ";
		cin>>opc;
	}while(opc<1 || opc>6);
	return opc;
}
/*************************************************/
bool val_emp(long wid, char *nom)
{
	trabajador empleado;
	ifstream file("empleados.txt",ios::in |ios::binary);
	if(file.fail())
	{
		cout<<"Error para leer el archivo empleados.txt"<<endl; 
		system("pause");
		exit(0);	
	}
	file.read(reinterpret_cast<char*>(&empleado),sizeof(trabajador));
	while(!file.eof())
	{
		if(wid == empleado.id)
		{
			strcpy(nom,empleado.nom);
			file.close(); 
			return true;
		}
		file.read(reinterpret_cast<char*>(&empleado),sizeof(trabajador));
	}
	file.close();
	return false;
}
/*************************************************/
void reg_emp()
{
	trabajador empleado;
	int salida;
	do
	{
		cout<<"Registro de empleados: "<<endl;
		cout<<"Id: ";
		cin>>empleado.id;
		if(val_emp(empleado.id, empleado.nom))
		{
			cout<<"Empleado: "<<empleado.nom <<" ya está registrado"<<endl;
		}
		else
		{
			cout<<"Nombre: "; fflush(stdin); gets(empleado.nom);
			cout<<"Cargo: ";  fflush(stdin); gets(empleado.cargo);
			cout<<"Dependencia: ";  fflush(stdin); gets(empleado.dependencia);
			ofstream file("empleados.txt",ios::app | ios::binary);
			if(file.fail())
			{
				cout<<"Error para escribir en el archivo empleados.txt"<<endl; 
				system("pause");
				exit(0);	
			}
			file.write(reinterpret_cast<char*>(&empleado),sizeof(trabajador));	
			file.close();	
		}
		cout<<"1.Continuar registro de otro empleado - Cualquier otro valor finalizar: ";
		cin>>salida;
	}while(salida == 1);
}
/*************************************************/
void reg_nom()
{
	nomina pago;
	char nom[50];
	int salida;
	long wid;
	
	do
	{
		system("cls");
		cout<<"REGISTRO DATOS DE NÓMINA"<<endl;
		cout<<"ID del empleado: "; cin>>wid;
		if(val_emp(wid,nom))
		{
			/*invocar función para validar que empleado no tenga datos registrados*/
			if(val_nomina(wid))
			{
				cout<<"Empleado " <<nom <<" ya tiene un registro de datos para la nómina" <<endl;
			}
			else
			{
				pago.id = wid;
				cout<<"Empleado: "<<nom <<endl;
				cout<<"Salario básico por hora: "; cin>>pago.sbh;
				cout<<"Horas ordinarias trabajadas:"; cin>>pago.ho;
				cout<<"Horas extras diurnas trabajadas: "; cin>>pago.hedi;
				cout<<"Horas extras nocturnas trabajadas: "; cin>>pago.hen;
				cout<<"Horas extras dominicales trabajadas: "; cin>>pago.hedo;	
				ofstream file("nomina.txt",ios::app|ios::binary);
				if(file.fail())
				{ 
					cout<<"Error para escribir en el archivo nomina.txt"<<endl;
					system("pause");
					exit(0);
				};
				file.write(reinterpret_cast<char *>(&pago),sizeof(nomina));
				file.close();
			}	
		}
		else
		{
			cout<<"Empleado no está registrado "<<endl;
		}
		cout<<"Desea registrar los datos de otro empleado [1] - cualquier otro valor terminar: ";
		cin>>salida;
	}while(salida==1);
	
	
}
/*************************************************/
void cal_nom()
{
	system("cls");
	nomina pago;
	char nom[50];
	ifstream file("nomina.txt",ios::in | ios::binary);
	if(file.fail())
	{
		cout<<"Error al leer el archivo nomina.txt"; 
		system("pause");
		exit(0);
	}
	file.read(reinterpret_cast<char *>(&pago), sizeof(nomina));
	while(!file.eof())
	{
		val_emp(pago.id, nom);
		cout<<"Nombre del empleado: "<<nom <<endl;
		cout<<"Salario básico por hora: "<<pago.sbh<<endl;
		cout<<"Horas ordinarias trabajadas:" <<pago.ho<<endl;
		cout<<"Horas extras diurnas trabajadas: "<<pago.hedi<<endl;
		cout<<"Horas extras nocturnas trabajadas: "<<pago.hen<<endl;
		cout<<"Horas extras dominicales trabajadas: "<<pago.hedo<<endl;	
		pago.she = (pago.hedi*(1.25*pago.sbh)) + (pago.hen*(1.5*pago.sbh)) + (pago.hedo*(1.75*pago.sbh));
		if(pago.she > 200000)
		{
			pago.rf = pago.she * 0.10;
		}
		pago.sb = pago.ho * pago.sbh;
		pago.sn = pago.sb + pago.she - pago.rf;
		cout<<"Salario Básico: $"<<pago.sb <<endl;
		cout<<"Salario Horas Extras: $"<<pago.she <<endl;
		cout<<"Retención en la Fuente: $"<<pago.rf <<endl;
		cout<<"Salario Neto: $"<<pago.sn <<"\n\n";
		
		file.read(reinterpret_cast<char *>(&pago), sizeof(nomina));	
	}
	file.close();
	system("pause");
}
/*************************************************/
void cons_emp()
{
	nomina pago;
	long wid;
	char nom[50];
	cout<<"Ingrese el Id del empleado a consultar: ";
	cin>>wid;
	if(val_emp(wid, nom))
	{
		ifstream file("nomina.txt",ios::in | ios::binary);
		if(file.fail())
		{
			cout<<"Error al leer el archivo nomina.txt"; 
			system("pause");
			exit(0);
		}
		file.read(reinterpret_cast<char *>(&pago), sizeof(nomina));
		while(!file.eof())
		{
			
			if(pago.id == wid)
			{
				cout<<"Nombre del empleado: "<<nom <<endl;	
				cout<<"Salario básico por hora: "<<pago.sbh<<endl;
				cout<<"Horas ordinarias trabajadas:" <<pago.ho<<endl;
				cout<<"Horas extras diurnas trabajadas: "<<pago.hedi<<endl;
				cout<<"Horas extras nocturnas trabajadas: "<<pago.hen<<endl;
				cout<<"Horas extras dominicales trabajadas: "<<pago.hedo<<endl;	
				pago.she = (pago.hedi*(1.25*pago.sbh)) + (pago.hen*(1.5*pago.sbh)) + (pago.hedo*(1.75*pago.sbh));
				if(pago.she > 200000)
				{
					pago.rf = pago.she * 0.10;
				}
				pago.sb = pago.ho * pago.sbh;
				pago.sn = pago.sb + pago.she - pago.rf;
				cout<<"Salario Básico: $"<<pago.sb <<endl;
				cout<<"Salario Horas Extras: $"<<pago.she <<endl;
				cout<<"Retención en la Fuente: $"<<pago.rf <<endl;
				cout<<"Salario Neto: $"<<pago.sn <<"\n\n";	
			}
			file.read(reinterpret_cast<char *>(&pago), sizeof(nomina));	
		}
		file.close();	
	}
	else
	{
		cout<<"Empleado no está registrado"<<endl;
	}
	system("pause");
}
/*************************************************/
void rep_nom()
{
	nomina pago;
	char nom[50];
	ifstream file("nomina.txt",ios::in |ios::binary);
	if(file.fail())	
	{
		cout<<"Error al leer el archivo nomina.txt"<<endl;
		system("pause");
		exit(0);
	}
	system("cls");
	cout<<setw(30)<<"EMPLEADO"<<setw(15)<<"Total HE"<<setw(15)<<"SALARIO HE"<<setw(15)<<"RETEFUENTE"<<setw(15)<<"NETO"<<endl;
	file.read(reinterpret_cast<char *>(&pago), sizeof(nomina));
	while(!file.eof())
	{
		val_emp(pago.id, nom);
		cout<<setw(30)<<nom;
		cout<<setw(15)<<pago.hedi+pago.hedo+pago.hen;
		pago.she = (pago.hedi*(1.25*pago.sbh)) + (pago.hen*(1.5*pago.sbh)) + (pago.hedo*(1.75*pago.sbh));
		if(pago.she>200000)
		{
			pago.rf = pago.she *0.10;
		}	
		cout<<setw(15)<<pago.she;
		cout<<setw(15)<<pago.rf;
		cout<<setw(15)<<pago.ho*pago.sbh + pago.she - pago.rf <<endl;
		file.read(reinterpret_cast<char *>(&pago), sizeof(nomina));
	}
	system("pause");
	file.close();
}
/**************************************************/
void open_file()
{
	ofstream file1("empleados.txt",ios::out | ios::binary);
	if(file1.fail())
	{
		cout<<"Error al crear archivo empleados.txt"<<endl;
		system("pause");
		exit(0);
	}
	file1.close();
	
	ofstream file2("nomina.txt",ios::out | ios::binary);
	if(file2.fail())
	{
		cout<<"Error al crear archivo nomina.txt"<<endl;
		system("pause");
		exit(0);
	}
}
/*************************************************/
bool val_nomina(long wid)
{
	nomina pago;
	ifstream file("nomina.txt",ios::in |ios::binary);
	if(file.fail())
	{
		cout<<"Error para leer el archivo nomina.txt"<<endl; 
		system("pause");
		exit(0);	
	}
	file.read(reinterpret_cast<char*>(&pago),sizeof(nomina));
	while(!file.eof())
	{
		if(wid == pago.id)
		{
			file.close(); 
			return true;
		}
		file.read(reinterpret_cast<char*>(&pago),sizeof(nomina));
	}
	file.close();
	return false;
}
/*************************************************/

