
//Diego Andres Martinez Florez: 0222120002.

#include <iostream>
#include <string.h>
using namespace std;

struct fecha{
	int dia;
	int mes;
	int anio;
};

struct cambio{
	int tipo_conversion;
	int tipo_transaccion;
	long tasa_cambio;
	long long valor_convertido;
	fecha fechas;
};

struct cliente{
	int tipo_doc;
	int cont_cambios=0;
	int num_cambios=0;
	long long num_doc;
	char nombre[50];
	char direccion[50];
	int tel;
	cambio cambios[5000];
}clientes[900];

void registro (int &x){
	int salir;
	do{
		int aux_tipo_doc;
		long long aux_num_doc;
		bool sw=true;
		system("cls");
		cout<<"Registro de clientes"<<endl;
		cout<<"Cliente No. "<<x+1<<endl;
		do{
			cout<<endl;
			cout<<"Tipo de documento: "<<endl;
			cout<<"1. Nacional"<<endl;
			cout<<"2. Extranjero"<<endl;
			cout<<"3. Otro"<<endl;
			cout<<"Ingrese una opcion: ";
			cin>>aux_tipo_doc;
		}while(aux_tipo_doc<1 or aux_tipo_doc>3);
		
		cout<<endl;
		cout<<"Numero de documento: ";
		cin>>aux_num_doc;
		
		for (int i=0; i<x; i++){
			if (aux_num_doc==clientes[i].num_doc){
				sw=false;
				break;
			}
		}
		
		if (sw){
			cout<<endl;
			cout<<"Nombre: ";
			fflush(stdin);
			gets(clientes[x].nombre);
			
			for (int i=0; i<(strlen(clientes[x].nombre)); i++){
				clientes[x].nombre[i] = toupper(clientes[x].nombre[i]);
			}
			
			cout<<"Direccion: ";
			fflush(stdin);
			gets (clientes[x].direccion);
		
			do{
				cout<<"Telefono: ";
				cin>>clientes[x].tel;
				
				if (clientes[x].tel<=0){
					cout<<"Ingrese un telefono valido"<<endl;
				}
			}while(clientes[x].tel<=0);
			
			clientes[x].tipo_doc = aux_tipo_doc;
			
			cout<<"El registro se ha realizado con exito"<<endl;
			x++;
			system("pause");
			system("cls");
		}
		else{
			cout<<"El documento ingresado ya se encuentra registrado"<<endl;
			cout<<"No se ha realizado el registro"<<endl;
		}
		
		cout<<"Desea registrar otro cliente: [1-Si] [Otro num-No]: ";
		cin>>salir;
	}while(salir==1);
	
}

void conversion(struct cliente clientes[], int x, int &num_factu){
	int salir;
	do{
		long long aux_num_doc, aux_valor_cambiar, conversion;
		long aux_tasa_cambio;
		int aux_tipo_conversion, indice, aux_tipo_transaccion;
		int aux_dia, aux_mes, aux_anio;
		bool sw=false;
		cout<<"Efectuar conversion"<<endl;
		cout<<"Ingrese su numero de documento: ";
		cin>>aux_num_doc;
			
		for (int i=0; i<x; i++){
			if (aux_num_doc==clientes[i].num_doc){
				sw=true;
				indice=i;
				break;
			}
		}
		
		if (sw){
			do{
				cout<<"Tipo de conversion: ";
				cout<<"1. Peso - Dolar americano"<<endl;
				cout<<"2. Peso - Euro"<<endl;
				cout<<"3. Euro - Peso"<<endl;
				cout<<"4. Dolar Americano - Peso"<<endl;
				cout<<"ingrese una opcion: ";
				cin>>aux_tipo_conversion;
			}while(aux_tipo_conversion<1 or aux_tipo_conversion>4);
			
			do{
				cout<<"Tipo de transaccion: ";
				cout<<"1. Compra";
				cout<<"2. Venta";
				cout<<"Ingrese una opcion: ";
				cin>>aux_tipo_transaccion;
			}while(aux_tipo_transaccion<1 or aux_tipo_transaccion>2);
						
			switch (aux_tipo_transaccion){
				case 1:
					do{
						cout<<"Ingrese el valor a cambiar: ";
						cin>>aux_valor_cambiar;
					}while(aux_valor_cambiar<=0);
					
					do{
						cout<<"Ingrese la tasa de cambio: ";
						cin>>aux_tasa_cambio;
					}while(aux_tasa_cambio<=0);
					
					cout<<endl;
					do{
						cout<<"Fecha"<<endl;
						cout<<"Dia: ";
						cin>>aux_dia;
						cout<<"Mes: ";
						cin>>aux_mes;
						cout<<"Anio: ";
						cin>>aux_anio;
					}while((aux_dia<=0) or (aux_anio<=0) or (aux_mes<=0));
					
					conversion = aux_valor_cambiar / aux_tasa_cambio;
					clientes[indice].cambios[clientes[indice].cont_cambios].valor_convertido = conversion;
					clientes[indice].cambios[clientes[indice].cont_cambios].fechas.dia = aux_dia;
					clientes[indice].cambios[clientes[indice].cont_cambios].fechas.mes = aux_mes;
					clientes[indice].cambios[clientes[indice].cont_cambios].fechas.anio = aux_anio;
					clientes[indice].cambios[clientes[indice].cont_cambios].tipo_conversion = aux_tipo_conversion;
					clientes[indice].cambios[clientes[indice].cont_cambios].tipo_transaccion = aux_tipo_transaccion;
					clientes[indice].cont_cambios++;
					
					cout<<"Conversion efectuada con exito: $"<<conversion<<endl;
					num_factu++;
					system("pause");
					system("cls");
				break;
				
				case 2: 
					do{
						cout<<"Ingrese el valor a cambiar: ";
						cin>>aux_valor_cambiar;
					}while(aux_valor_cambiar<=0);
					
					do{
						cout<<"Ingrese la tasa de cambio: ";
						cin>>aux_tasa_cambio;
					}while(aux_tasa_cambio<=0);
					
					cout<<endl;
					do{
						cout<<"Fecha"<<endl;
						cout<<"Dia: ";
						cin>>aux_dia;
						cout<<"Mes: ";
						cin>>aux_mes;
						cout<<"Anio: ";
						cin>>aux_anio;
					}while((aux_dia<=0) or (aux_anio<=0) or (aux_mes<=0));
					
					conversion = aux_valor_cambiar*aux_tasa_cambio;
					clientes[indice].cambios[clientes[indice].cont_cambios].valor_convertido = conversion;
					clientes[indice].cambios[clientes[indice].cont_cambios].fechas.dia = aux_dia;
					clientes[indice].cambios[clientes[indice].cont_cambios].fechas.mes = aux_mes;
					clientes[indice].cambios[clientes[indice].cont_cambios].fechas.anio = aux_anio;
					clientes[indice].cambios[clientes[indice].cont_cambios].tipo_conversion = aux_tipo_conversion;
					clientes[indice].cambios[clientes[indice].cont_cambios].tipo_transaccion = aux_tipo_transaccion;
					clientes[indice].cont_cambios++;
					
					cout<<"Conversion efectuada con exito: $"<<conversion<<endl;
					num_factu++;
					system("pause");
					system("cls");
				break;
			}
		}
		else{
			cout<<"Numero de documento no encontrado"<<endl;
		}
		cout<<"Desea realizar otra conversion [1-Si] [Otro num-No]: ";
		cin>>salir;
	}while(salir==1);
	
}

void consulta (struct cliente clientes [], int x, int num_factu){
	int op, aux_num_doc, indice;
	bool sw=false;
	char op2;
	
	cout<<"Consultas"<<endl;
	cout<<"1. Consultar por cliente"<<endl;
	cout<<"2. Consultar todos los clientes"<<endl;
	cout<<"3. Estadisticas"<<endl;
	cout<<"Ingrese una opcion: ";
	cin>>op;
	
	switch (op){
		case 1:
			cout<<"Ingrese la cedula del cliente: ";
			cin>>aux_num_doc;
			
			for (int i=0; i<x; i++){
				if (aux_num_doc==clientes[i].num_doc){
					sw=true;
					indice=i;
					break;
				}
			}
			
			if (sw){
				cout<<"Nombre del cliente: "<<clientes[indice].nombre<<endl;
				for (int i=0; i<clientes[indice].cont_cambios; i++){
					cout<<"Valor convertido: "<<clientes[indice].cambios[i].valor_convertido<<endl;
					cout<<"Fecha: "<<clientes[indice].cambios[i].fechas.dia<<" / "<<clientes[indice].cambios[i].fechas.mes<<" / "<<clientes[indice].cambios[i].fechas.anio<<endl;
				}
				system("pause");
				system("cls");
			}
			else{
				cout<<"No se ha encontrado la cedula del cliente"<<endl;
			}
		break;
		
		case 2: 
			
		break;
		
		case 3:
			cout<<"Estadisticas por cambio de divisa";
			cout<<"1. Peso - Dolar americano"<<endl;
			cout<<"2. Peso - Euro"<<endl;
			cout<<"3. Euro - Peso"<<endl;
			cout<<"4. Dolar Americano - Peso"<<endl;
			cout<<"ingrese una opcion: ";
			cin>>op;
			
			cout<<"a. Cantidad de clientes que solicitaron cambio"<<endl;
			cout<<"b. Total efectuado por cambio a peso, euro, dolar"<<endl;
			cin>>op2;
			
			switch (op){
				case 1:	
				break;
				case 2:
				break;
				case 3:
				break;
				case 4:
				break;
				default: cout<<"Ingrese dentro del rango"<<endl;
			}
		break;
	}
	
}

int main(){
	char op;
	int x=0, num_factu=0;
	do{
		system("cls");
		cout<<"a. REGISTRAR CLIENTES"<<endl;
		cout<<"b. CONVERSION"<<endl;
		cout<<"c. CONSULTA"<<endl;
		cout<<"d. Salir"<<endl;
		cout<<"Ingrese una opcion: ";
		cin>>op;
		
		op = tolower(op);
		
		switch (op){
			case 'a': 
				registro(x);
			break;
				
			case 'b':
				if (x>0){
					conversion (clientes, x, num_factu);
				}	
			break;
			
			case 'c':
				consulta(clientes, x, num_factu);
			break;
			
			case 'd': exit(0);
			
			default: 
				cout<<"Debe ingresar a, b, c, o d"<<endl;
			break;
		}
	}while(op!='d');
}
