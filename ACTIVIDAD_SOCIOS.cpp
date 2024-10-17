#include <iostream>
#include <string.h>
using namespace std;
//*************************************************
// Declaracion de structs

struct fec
{
    int dia;
    int mes;
    int anio;
};

struct factu{
    long num_factura; 
    long ced_factu;
    char concepto [50];
    long vlr_consumo;
    fec fecha_consumo;
    bool estado=false; //False para facturas pendientes, True para canceladas
};

struct asociado{
    long ced_socio;
    long ced_asociado;
    char nombre_asociado [50];
    char parentesco [50];
    int edad;
    char sexo [15];
    bool est_asociado=true;//False para Asociados desuscritos, True para  Asociados los aun suscritos
};


struct socio{
	long cedula;
	char nombre[50];
	long f_disponibles;
	int tipo_suscrip;
    int num_asociados=0;
    int cont_factu=0;
    bool est_socio=true;//False para Socios desuscritos, True para  Socios los aun suscritos
    asociado asociados [3600];
    factu factura [9000];
}socios[900];

//*************************************************
// Declaracion de prototipos de Funciones
void afiliar_socio (struct socio socios [], int &x);
void registrar_asociado (struct socio socios [], int x, int &cont_asociados);
void registrar_consumo (struct socio socios [], int x, int cont_asociados, int &conteo_facturas);
void pagar_factura (struct socio socios [], int x, int conteo_facturas);
void aumentar_fondos (struct socio socios [], int x);
void eliminar (struct socio socios[], int &x, int &cont_asociados);
void modificar (struct socio socios[], int x, int cont_asociados);
void consultar (struct socio socios[], int x,int cont_asociados);
void orden_ascen(struct socio socios[],int n);
void orden_descen(struct socio socios[],int n);

//*************************************************

void orden_ascen(struct socio socios[],int n){
	
	struct socio aux;
	float comp;
	for(int x=0; x<n; x++){
		
		for(int y=0; y<n-x; y++){
			
			comp=strcmp(socios[y].nombre,socios[y+1].nombre);
			
			if(comp>0 ){
						
					aux = socios[y];
					socios[y] = socios[y+1];
					socios[y+1] = aux;
				}
				
		}	
	}
}
void orden_descen(struct socio socios[],int n){
	
	struct socio aux;
	for(int x=0; x<n; x++){
		
		for(int y=0; y<n-x; y++){
			
			if(socios[y].num_asociados<socios[y+1].num_asociados ){
						
					aux = socios[y];
					socios[y] = socios[y+1];
					socios[y+1] = aux;
				}
				
		}	
	}
}


int main(){
    setlocale (LC_ALL, "spanish");
    int op, x=0, cont_asociados=0, conteo_facturas=0;
    char opc;
    do{
        do{
            system("cls");
            cout<<"1. Afiliar un socio al club"<<endl;
            cout<<"2. Registrar Asociado"<<endl;
            cout<<"3. Registrar Consumo"<<endl;
            cout<<"4. Pagar Una Factura"<<endl;
            cout<<"5. Aumentar Fondos de la Cuenta De Un Socio"<<endl;
            cout<<"6. Cancelar Suscripción Socio o Asociado"<<endl;
            cout<<"7. Modificar Información Socio o Asociado"<<endl;
            cout<<"8. Consultas"<<endl;
            cout<<"9. Salir"<<endl;
            cout<<"Ingrese una opción: "; cin>>op;

            if (op<1 or op>9){
                cout<<"Debe ingresar dentro del rango [1-9]!!!"<<endl;
                system("pause");
                system("cls");
            }
        }while(op<1 or op>9);
        
        system("cls");
        switch (op){
            case 1: afiliar_socio (socios, x);
            break;
            case 2: 
                if (x>0){
                    registrar_asociado (socios , x, cont_asociados);
                }
                else{
                    cout<<"Debe afiliar al menos 1 socio para acceder a esta opción"<<endl;
                    system("pause");
                    system("cls");
                }
            break;
            case 3:
                if (x>0){
                    registrar_consumo (socios, x, cont_asociados, conteo_facturas);
                }
                else{
                    cout<<"Debe afiliar al menos 1 socio para acceder a esta opción"<<endl;
                    system("pause");
                    system("cls");
                }
            break;
            case 4:
                if (x>0){
                    pagar_factura (socios, x, conteo_facturas);
                }
                else{
                    cout<<"Debe afiliar al menos 1 socio para acceder a esta opción"<<endl;
                    system("pause");
                    system("cls");
                }
            break;
            case 5:
                if (x>0){
                    aumentar_fondos (socios , x);
                }
                else{
                    cout<<"Debe afiliar al menos 1 socio para acceder a esta opción"<<endl;
                    system("pause");
                    system("cls");
                }
            break;
            case 6:
                if (x>0){
							 eliminar (socios , x , cont_asociados);
                }
                else{
                    cout<<"Debe afiliar al menos 1 socio para acceder a esta opción"<<endl;
                    system("pause");
                    system("cls");
                }
            break;
            case 7:
                if (x>0){
                    		modificar (socios,x,cont_asociados);
                }
                else{
                    cout<<"Debe afiliar al menos 1 socio para acceder a esta opción"<<endl;
                    system("pause");
                    system("cls");
                } 
            break; 
            case 8:
            if(x>0){
                    do{
                        cout<<"1. Consultar Un Socio"<<endl;
                        cout<<"2. Lista de Personas Autorizadas Por Un Socio"<<endl;
                        cout<<"3. Listado de Socios Activos"<<endl;
                        cout<<"4. Listado de Socios Retirados"<<endl;
                        cout<<"5. Listado de Facturas Pendiente Por Pagar"<<endl;
                        cout<<"Ingrese una opción: "; cin>>op;

                        if (op<1 or op>5){
                            cout<<"Debe ingresar dentro del rango [1-5]!!!"<<endl;
                            system("pause");
                            system("cls");
                        }
                    }while(op<1 or op>5);
                    
                    switch (op){
                        case 1:
                            do{
                                cout<<"a. Información Socio"<<endl;
                                cout<<"b. Estado de Cuenta"<<endl;
                                cout<<"Ingrese una opción: "; cin>>opc;
                                opc = tolower(opc);

                                if (opc!='a' && opc!='b'){
                                    cout<<"Debe ingresar a ó b!!!"<<endl;
                                    system("pause");
                                    system("cls");
                                }
                            }while(opc!='a' && opc!='b');

                            switch(opc){
                                case 'a':
                                break;
                                case 'b':
                                break;
                            } 
                        break;
                        case 2:
                        break;
                        case 3:
                        break;
                        case 4:
                        break;
                        case 5:
                        break;
                    }
                break;
            }
            else{
                cout<<"Debe registrar al menos 1 socio para acceder a esta opción"<<endl;
                system("pause");
                system("cls");
            }
            case 9: exit (0);
        }
    }while(op!=9);
}
	//---------------------------------------------
void afiliar_socio (struct socio socios [], int &x){
    
    static int socios_regulares=0;
    static int socios_vip=0;
	int sw, st;
    char aux_nombre [50];

    do{
        sw=1;
        st=1;
        system("cls");
        cout<<"Registro No. "<<x+1<<endl;
        cout<<"Cédula del socio: "; 
        cin>>socios[x].cedula;
        for (int i=0; i<x; i++){
            if (socios[x].cedula == socios[i].cedula){
                cout<<"La cédula ingresada ya está registrada!!!"<<endl;
                sw=0;
                system("pause");
                system("cls");
                break;
            }
        }	
	    if(sw==1){
            cout<<"Nombre del socio: ";
            fflush (stdin);
            gets (socios[x].nombre);

            strcpy (aux_nombre, socios[x].nombre);
            for (int i=0; i<strlen(socios[x].nombre); i++){
                aux_nombre[i] = toupper (aux_nombre[i]);
                socios[x].nombre[i] = aux_nombre[i];
            }
        
            do{
                st=1;
                sw=1;
                cout<<"Tipo de suscripción [1.Regular - 2.VIP]: ";
                cin>>socios[x].tipo_suscrip;

                if (socios[x].tipo_suscrip<1 or socios[x].tipo_suscrip>2){
                    cout<<"Ingrese dentro del rango [1-2]!!!"<<endl;
                    system("pause");
                    system("cls");
                    st=0;
                }

                if (socios[x].tipo_suscrip == 1){
                    socios_regulares++;
                }
                else{
                    if (socios[x].tipo_suscrip == 2){
                        if ((((socios_regulares+socios_vip)/5)*2)>=(socios_vip+1)){
                            socios_vip++;
                        }
                        else{
                            system("cls");
                            cout<<"Se ha sobrepasado la cantidad de socios VIP permitidos!!!"<<endl;
                            sw=0;
                            system("pause");
                        }
                    } 
                }
            }while(st==0);

            if(sw==1){
                st=1;
                cout<<"Fondos disponibles: ";
                cin>>socios[x].f_disponibles;
                
                if (socios[x].tipo_suscrip==1){
                    if (socios[x].f_disponibles<300000){
                        system("cls");
                        cout<<"El monto inicial mínimo para miembros regulares es de $300 000"<<endl;
                        st=0;
                        system("pause");
                    }
                    else{
                        if (socios[x].f_disponibles>2000000){
                            system("cls");
                            cout<<"El monto inicial máximo para miembros regulares es de $2 000 000"<<endl;
                            st=0;
                            system("pause");
                        }
                    }
                }
                else{
                    if (socios[x].tipo_suscrip==2){
                        if (socios[x].f_disponibles<1000000){
                            system("cls");
                            cout<<"El monto inicial para miembros VIP debe ser de $1 000 000"<<endl;
                            st=0;
                            system("pause");
                        }
                        else{
                            if (socios[x].f_disponibles>5000000){
                                system("cls");
                                cout<<"El monto inical máximo para miembros VIP es de $5 000 000"<<endl;
                                st=0;
                                system("pause");
                            }
                        }
                    }
                }
            }
            
            if (sw==1 && st==1){
                cout<<"El registro se ha realizado con éxito"<<endl;
                x++;
            }
            else{
                cout<<"El registro no se ha realizado correctamente"<<endl;
            }

            cout<<endl;
            cout<<"¿Desea realizar un nuevo registro? [0 = Si] - [Otro# = No]: ";
            cin>>sw;
            system("pause");
        }
        else{
            cout<<"¿Desea realizar un nuevo registro? [0 = Si] - [Otro# = No]: ";
            cin>>sw;
        }
    }while(sw==0);
}
	//---------------------------------------------
void registrar_asociado (struct socio socios [], int x, int &cont_asociados){
    int op, sw=0, cont=0, in_socio, st=1, i=0;
    long cedula_socio, aux_cedula;
    char nombre_socio [50], aux_nombre [50];

    do{
        st=1;
        cout<<"Registro de asociados"<<endl;
        do{
            sw=1;
            cout<<"Consultar socio por [1-Nombre] [2-Cédula]: ";
            cin>>op;

            if (op<1 or op>2){
                sw=0;
                cout<<"Ingrese dentro del rango [1-2]!!!"<<endl;
                system("pause");
                system("cls");
            }
        }while(sw==0);

        if (op==1){
            sw=0;
            cout<<"Ingrese el nombre del socio: ";
            fflush (stdin);
            gets (nombre_socio);

            for (int i=0; i<strlen(nombre_socio); i++){
                nombre_socio[i] = toupper (nombre_socio[i]);
            }

            for (int i=0; i<x; i++){
                if (strcmp(nombre_socio, socios[i].nombre) == 0){
                    in_socio=i;
                    sw=1;
                    break;
                }
            }
        }
        else{
            sw=0;
            cout<<"Ingrese la cédula del socio: ";
            cin>>cedula_socio;

            for (i=0; i<x; i++){
                if (cedula_socio == socios[i].cedula){
                    in_socio=i;
                    sw=1;
                    break;
                }
            }
        }

        if (sw==1){
            system("cls");
            cout<<"Información del socio"<<endl;
            cout<<"Nombre: "<<socios[in_socio].nombre<<endl;
            cout<<"Cédula: "<<socios[in_socio].cedula<<endl;
            cout<<"Fondos: "<<socios[in_socio].f_disponibles<<endl;

            if (socios[in_socio].f_disponibles<=0){
                cout<<"El socio no posee los fondos suficientes"<<endl;
                st=0;
            }
        }
        else{
            st=0;
            if (op==1){
                cout<<"No se ha encontrado el nombre del socio"<<endl;
            }
            else{
                cout<<"No se ha encontrado la cédula del socio"<<endl;
            }
            system("pause");
            system("cls");
        }

        if (st==1){
            cout<<endl;
            cout<<"Información del asociado"<<endl;
            cout<<"Ingrese la cédula del asociado: ";
            cin>>aux_cedula;

            for (i=0; i<x; i++){
                for (int j=0; j<cont_asociados; j++){
                    if (aux_cedula == socios[i].asociados[socios[j].num_asociados].ced_asociado){
                        st=0;
                        break;
                    }
                }
            }

            for (i=0; i<x; i++){
                if (aux_cedula == socios[i].cedula){
                    st=0;
                    break;
                }
            }
                
            if (st==0){
                system("cls");
                cout<<"La cédula del asociado ya se encuentra registrada "<<endl;
                system("pause");
            }
            else{
                if (st==1){
                    cout<<"Nombre del asociado: ";
                    fflush (stdin);
                    gets (socios[in_socio].asociados[socios[in_socio].num_asociados].nombre_asociado);
                    fflush (stdin);
                    cout<<"Parentesco del asociado: ";
                    gets (socios[in_socio].asociados[socios[in_socio].num_asociados].parentesco);
                    fflush (stdin);
                    cout<<"Sexo del asociado: ";
                    gets (socios[in_socio].asociados[socios[in_socio].num_asociados].sexo);
                    socios[in_socio].num_asociados++;
                    socios[in_socio].asociados[socios[in_socio].num_asociados].ced_asociado = aux_cedula;
                    cout<<endl;
                    cout<<"El registro ha sido exitoso"<<endl;
                }
            }
        }
        system("cls");
        cout<<"¿Desea registrar otro asociado? [0: Si] [Otro #: No]: ";
        cin>>sw;
        system("pause");
        system("cls");
    }while(sw==0);
}
	//---------------------------------------------
void registrar_consumo (struct socio socios [], int x, int cont_asociados, int &conteo_facturas){

    int sw, op, in_socio, st=0, aux_factu, aux_cedu, aux_dia, aux_mes, aux_anio;
    char aux_concepto [50];
    long aux_valor_consumo;
    bool verifica=false;
    long cedula_socio;
    char nombre_socio [50];
    do{
        cout<<"Registrar un consumo"<<endl;
        do{
            sw=1;
            cout<<"Consultar socio por [1-Nombre] [2-Cédula]: ";
            cin>>op;

            if (op<1 or op>2){
                sw=0;
                cout<<"Ingrese dentro del rango [1-2]!!!"<<endl;
                system("pause");
                system("cls");
            }
        }while(sw==0);

        if (op==1){
            sw=0;
            cout<<"Ingrese el nombre del socio: ";
            fflush (stdin);
            gets (nombre_socio);

            for (int i=0; i<strlen(nombre_socio); i++){
                nombre_socio[i] = toupper (nombre_socio[i]);
            }

            for (int i=0; i<x; i++){
                if (strcmp(nombre_socio, socios[i].nombre) == 0){
                    in_socio=i;
                    sw=1;
                    break;
                }
            }
        }
        else{
            sw=0;
            cout<<"Ingrese la cédula del socio: ";
            cin>>cedula_socio;
            for (int i=0; i<x; i++){
                if (cedula_socio == socios[i].cedula){
                    in_socio=i;
                    sw=1;
                    break;
                }
            }
        }

        if (sw==1){
            system("cls");
            cout<<"Información del socio"<<endl;
            cout<<"Nombre: "<<socios[in_socio].nombre<<endl;
            cout<<"Cédula"<<socios[in_socio].cedula<<endl;
            cout<<"Fondos: "<<socios[in_socio].f_disponibles<<endl;
                    
            if (socios[in_socio].f_disponibles<=0){
                cout<<"El socio no posee los fondos suficientes"<<endl;
                sw=0;
            }
        }
        else{
            if (sw!=1){
                sw=0;
                system("pause");
                system("cls");

                if (op==1){
                    cout<<"No se ha encontrado el nombre del socio"<<endl;
                }
                else{
                    cout<<"No se ha encontrado la cédula del socio"<<endl;
                }
            }
        }

        if (sw==1){
            sw=0;
            do{
                cout<<"Ingrese el número de la factura: ";
                cin>>aux_factu;
            }while(aux_factu<=0);

            for (int i=0; i<x; i++){
                for (int j=0; j<socios[i].cont_factu; j++){
                    if (aux_factu == socios[i].factura[j].num_factura){
                        st=1;
                    }
                } 
            }

            if (st==1){
                cout<<"El número de la factura ya se encuentra en uso"<<endl;
            }
            else{
                sw=0;
                cout<<"Cédula de la persona que realizó el consumo: ";
                cin>>aux_cedu;

                for (int i=0; i<x; i++){
                    for (int j=0; j<cont_asociados; j++){
                        if (aux_cedu == socios[i].asociados[socios[j].num_asociados].ced_asociado){
                            sw=1;
                            break;
                        }
                    }
                }

                for (int i=0; i<x; i++){
                    if (aux_cedu == socios[i].cedula){
                        sw=1;
                        break;
                    }
                }

                if (sw==1){
                    verifica=true;
                    cout<<"Concepto de la factura: ";
                    fflush(stdin);
                    gets (aux_concepto);
                    cout<<"Valor de la factura: "; 
                    cin>>aux_valor_consumo;

                    if ((aux_valor_consumo<=0) or (aux_valor_consumo>socios[in_socio].f_disponibles)){
                        verifica=false;
                    }

                    if (verifica){
                        cout<<endl;
                        cout<<"Fecha del consumo"<<endl;
                        cout<<"Ingrese el día del consumo: ";
                        cin>>aux_dia;
                        cout<<"Ingrese el mes del consumo: ";
                        cin>>aux_mes;
                        cout<<"Ingrese el año [2000 - 2023]: ";
                        cin>>aux_anio;

                        if ((aux_dia<=0) or (aux_dia>31) or (aux_mes>12) or (aux_mes<=0) or (aux_anio<=0) or (aux_anio<2000) or (aux_anio>2023)){
                            cout<<"Ha ingresado un valor erróneo para las fechas (<=0)"<<endl;
                            verifica=false;
                            system("pause");
                            system("cls");
                        }
                    }
                    else{
                        cout<<"Ha ingresado un valor de consumo erróneo en la factura"<<endl;
                        system("pause");
                        system("cls");
                    }   
                }
                else{
                    verifica==false;
                    cout<<"La cédula digitada no se ha encontrado"<<endl;
                    system("pause");
                    system("cls");
                }  
            }
        }
        if (verifica==false){
            cout<<"No se ha registrado la factura"<<endl;
            system("pause");
            system("cls");
        }
        else{
            cout<<endl;
            cout<<"Se ha registrado correctamente la factura"<<endl;

            socios[in_socio].factura[socios[in_socio].cont_factu].num_factura = aux_factu;
            socios[in_socio].factura[socios[in_socio].cont_factu].ced_factu = aux_cedu;
            strcpy(socios[in_socio].factura[socios[in_socio].cont_factu].concepto, aux_concepto);
            socios[in_socio].factura[socios[in_socio].cont_factu].vlr_consumo = aux_valor_consumo;
            socios[in_socio].factura[socios[in_socio].cont_factu].fecha_consumo.dia = aux_dia;
            socios[in_socio].factura[socios[in_socio].cont_factu].fecha_consumo.mes = aux_mes;
            socios[in_socio].factura[socios[in_socio].cont_factu].fecha_consumo.anio = aux_anio;
            socios[in_socio].cont_factu++;
            conteo_facturas++;

            system("pause");
            system("cls");
        }
        cout<<"¿Desea registrar otra factura? [0: Si] [Otro #: No]: ";
        cin>>st;
        system("pause");
        system("cls");
    }while(st==0);
}
	//---------------------------------------------
void pagar_factura (struct socio socios [], int x, int conteo_facturas){
    int sw, op, in_socio, numero_factura, cont_facturas_pendientes, salida;
    int num_factu_pendientes [50];
    int pag;
    bool exito=false, bandera;
    char nombre_socio [50];
    do{
        bandera=false;
        cout<<"Pago de facturas"<<endl;
        cont_facturas_pendientes=0;
        do{
            sw=1;
            cout<<"Consultar factura por [1-Nombre de socio] [2-Número de factura]: ";
            cin>>op;

            if (op<1 or op>2){
                sw=0;
                cout<<"Ingrese dentro del rango [1-2]!!!"<<endl;
                system("pause");
                system("cls");
            }
        }while(sw==0);
        sw=0;
        if (op==1){
            sw=0;
            cout<<"Ingrese el nombre del socio: ";
            fflush (stdin);
            gets (nombre_socio);

            for (int i=0; i<strlen(nombre_socio); i++){
                nombre_socio[i] = toupper (nombre_socio[i]);
            }

            for (int i=0; i<x; i++){
                if (strcmp(nombre_socio, socios[i].nombre) == 0){
                    in_socio=i;
                    sw=1;
                    break;
                }
            }
            if (sw==0){
                cout<<"No se encontró el nombre del socio"<<endl;
            }
        }
        else{
            cout<<"Ingrese el número de la factura: ";
            cin>>numero_factura;
            for (int i=0; i<x; i++){
                for (int j=0; j<socios[i].cont_factu; j++){
                    if ((numero_factura == socios[i].factura[j].num_factura) && (socios[i].factura[j].estado == false)){
                        cout<<"Número de factura: "<<socios[i].factura[j].num_factura<<endl;
                        cout<<"Cédula de la persona que realizó el consumo: "<<socios[i].factura[j].ced_factu<<endl;
                        cout<<"Concepto: "<<socios[i].factura[j].concepto<<endl;
                        cout<<"Valor de la factura: "<<socios[i].factura[j].vlr_consumo<<endl;
                        cout<<"Fecha: "<<socios[i].factura[j].fecha_consumo.dia<<"/"<<socios[i].factura[j].fecha_consumo.mes<<"/"<<socios[i].factura[j].fecha_consumo.anio<<endl;
                        bandera=true;
                        do{
                            cout<<"¿Desea pagar la factura? [1-Si] [2-No]: "<<endl;
                            cin>>pag;
                        }while(1<pag or pag>2);

                        if (pag==1){
                            if (socios[i].f_disponibles>=socios[i].factura[j].vlr_consumo){
                                socios[i].f_disponibles = socios[i].f_disponibles - socios[i].factura[j].vlr_consumo;
                                cout<<"El pago de la factura fue exitoso"<<endl;
                                cout<<"Nuevo saldo: "<<socios[i].f_disponibles<<endl;
                                socios[i].factura[j].estado = true;
                                exito = true;
                                system("pause");
                                system("cls");
                            }
                            else{
                                cout<<"No posee suficientes fondos para pagar la factura"<<endl;
                                system("pause");
                                system("cls");
                            }
                        }
                    }
                }  
            }
            if (bandera==false){
                cout<<"No se encontró el número de la factura"<<endl;
                system("pause");
                system("cls");
            }
        }

        if (sw==1){
            exito = false;
            system("cls");
            cout<<"Información del socio"<<endl;
            cout<<"Nombre: "<<socios[in_socio].nombre<<endl;
            cout<<"Cédula"<<socios[in_socio].cedula<<endl;
            cout<<"Fondos: "<<socios[in_socio].f_disponibles<<endl;

            cout<<"Facturas pendientes"<<endl<<endl;
            for (int i=0; i<socios[in_socio].cont_factu; i++){
                if (socios[in_socio].factura[i].estado == false){
                    cout<<"Número de factura: "<<socios[in_socio].factura[i].num_factura<<endl;
                    cout<<"Cédula de la persona que realizó el consumo: "<<socios[in_socio].factura[i].ced_factu<<endl;
                    cout<<"Concepto: "<<socios[in_socio].factura[i].concepto<<endl;
                    cout<<"Valor de la factura: "<<socios[in_socio].factura[i].vlr_consumo<<endl;
                    cout<<"Fecha: "<<socios[in_socio].factura[i].fecha_consumo.dia<<"/"<<socios[in_socio].factura[i].fecha_consumo.mes<<"/"<<socios[in_socio].factura[i].fecha_consumo.anio<<endl;
                    num_factu_pendientes[i]=socios[in_socio].factura[i].num_factura;
                    cont_facturas_pendientes++;
                    cout<<endl;
                }
            }

            if (cont_facturas_pendientes>0){
                cout<<"Digite el número de la factura a pagar: ";
                cin>>numero_factura;
                for (int i=0; i<cont_facturas_pendientes; i++){
                    if ((numero_factura == num_factu_pendientes[i]) && (socios[in_socio].f_disponibles>=socios[in_socio].factura[i].vlr_consumo)){
                        socios[in_socio].factura[i].estado = true;
                        socios[in_socio].f_disponibles = socios[in_socio].f_disponibles - socios[in_socio].factura[i].vlr_consumo;
                        exito = true;
                        break;
                    }
                }

                if (exito){
                    cout<<"El pago de la factura fue exitoso"<<endl;
                    cout<<"Nuevo saldo: "<<socios[in_socio].f_disponibles<<endl;
                    system("pause");
                    system("cls");
                }
                if (exito == false){
                    cout<<"No posee suficientes fondos para pagar la factura"<<endl;
                    system("pause");
                    system("cls");
                }
                
            }
        }
        cout<<"¿Desea pagar otra factura? [1=Si] [Otro num=No]: ";
        cin>>salida;
        system("pause");
        system("cls");
    }while(salida==1);
}
	//---------------------------------------------
void aumentar_fondos (struct socio socios [], int x){
    int op, in_socio, sw;
    long cedula_socio, fondos;
    bool nom, cd;
    char nombre_socio [50];
    do{
        do{
            cout<<"Consultar socio por [1-Nombre] [2-Cédula]: ";
            cin>>op;

            if (op<1 or op>2){
                cout<<"Ingrese dentro del rango [1-2]!!!"<<endl;
                system("pause");
                system("cls");
            }
        }while(op<1 or op>2);

        nom=false;
        cd=false;

        switch (op){
            case 1:
                cout<<"Ingrese el nombre del socio: ";
                fflush (stdin);
                gets (nombre_socio);

                for (int i=0; i<strlen(nombre_socio); i++){
                    nombre_socio[i] = toupper (nombre_socio[i]);
                }

                for (int i=0; i<x; i++){
                    if (strcmp(nombre_socio, socios[i].nombre) == 0){
                        in_socio=i;
                        nom=true;
                        break;
                    }
                }
            break;
            case 2:
                cout<<"Ingrese la cédula del socio: ";
                cin>>cedula_socio;
                for (int i=0; i<x; i++){
                    if (cedula_socio == socios[i].cedula){
                        in_socio=i;
                        cd=true;
                        break;
                    }
                }
            break;
        }

        if ((cd==true) or (nom==true)){
            system("cls");
            cout<<"Información del socio"<<endl;
            cout<<"Nombre: "<<socios[in_socio].nombre<<endl;
            cout<<"Cédula"<<socios[in_socio].cedula<<endl;
            cout<<"Fondos: "<<socios[in_socio].f_disponibles<<endl;

            do{
                cout<<"Ingrese el monto que desea agregar a sus fondos: ";
                cin>>fondos;

                if (fondos<=0){
                    cout<<"Se debe ingresar un dato mayor que cero"<<endl;
                    system("pause");
                    system("cls");
                }
            }while(fondos<=0);
            
            if (socios[in_socio].tipo_suscrip == 1){
                if ((socios[in_socio].f_disponibles + fondos)>2000000){
                    cout<<"El monto máximo para el fondo de miembros regulares es de $2 000 000"<<endl;
                    cout<<"El aumento de fondos no se ha realizado"<<endl;
                    system("pause");
                    system("cls");
                }
                else{
                    cout<<"Su aumento de fondos ha sido éxitoso"<<endl;
                    socios[in_socio].f_disponibles = socios[in_socio].f_disponibles + fondos;
                    cout<<"Su nuevo saldo es de: $"<<socios[in_socio].f_disponibles<<endl;
                    system("pause");
                    system("cls");
                }
            }
            else{
                if (socios[in_socio].tipo_suscrip == 2){
                    if ((socios[in_socio].f_disponibles + fondos)>5000000){
                        cout<<"El monto máximo para el fondo de miembros regulares es de $5 000 000"<<endl;
                        cout<<"El aumento de fondos no se ha realizado"<<endl;
                    }
                    else{
                        cout<<"Su aumento de fondos ha sido éxitoso"<<endl;
                        socios[in_socio].f_disponibles = socios[in_socio].f_disponibles + fondos;
                        cout<<"Su nuevo saldo es de: $"<<socios[in_socio].f_disponibles<<endl;
                        system("pause");
                        system("cls");
                    }
                }
            }

        }
        else{
            if (cd==false){
                cout<<"No se ha encontrado la cédula del socio"<<endl;
            }
            else if (nom==false){
                cout<<"No se ha encontrado el nombre del socio"<<endl;
            }
            
        }
        cout<<"¿Desea realizar otro aumento de fondos? [1=Si] [Otro num=No]: ";
        cin>>sw;
        system("pause");
        system("cls");
    }while(sw==1);
}
	//---------------------------------------------
void eliminar (struct socio socios[], int &x, int &cont_asociados){
    long aux_ced;
    bool sw, st;
    int indice1, indice2, exito, op;
    do{
        sw=false;
        st=false;
        exito = true;
        cout<<"Ingrese la cédula del socio o del asociado que desea eliminar: ";
        cin>>aux_ced;

        for (int i=0; i<x; i++){
            for (int j=0; j<cont_asociados; j++){
                if (aux_ced == socios[i].asociados[socios[j].num_asociados].ced_asociado){
                    indice1 = i;
                    indice2 = j;
                    st=true;
                    break;
                }
            }
        }

        for (int i=0; i<x; i++){
            if (aux_ced == socios[i].cedula){
                indice1 = i;
                sw=true;
                break;
            }
        }

        if (st){

            cout<<endl;
            cout<<"Información del asociado"<<endl;
            cout<<"Nombre: "<<socios[indice1].asociados[indice2].nombre_asociado<<endl;
            cout<<"Cédula: "<<socios[indice1].asociados[indice2].ced_asociado<<endl;
            cout<<"Cédula del socio: "<<socios[indice1].asociados[indice2].ced_socio<<endl;
            cout<<"Parentesco: "<<socios[indice1].asociados[indice2].parentesco<<endl;
            cout<<"Edad: "<<socios[indice1].asociados[indice2].edad<<endl;
            cout<<"Sexo: "<<socios[indice1].asociados[indice2].sexo<<endl;

            for (int i=0; i<socios[indice1].cont_factu; i++){
                if (socios[indice1].factura[i].estado == false){
                    exito = false;
                }
            }
        }
        else{
            if (sw){
                cout<<endl;
                cout<<"Información del socio"<<endl;
                cout<<"Nombre: "<<socios[indice1].nombre<<endl;
                cout<<"Cédula"<<socios[indice1].cedula<<endl;
                cout<<"Fondos: "<<socios[indice1].f_disponibles<<endl;

                for (int i=0; i<socios[indice1].cont_factu; i++){
                    if (socios[indice1].factura[i].estado == false){
                        exito = false;
                    }
                }

            }
            else{
                cout<<endl;
                cout<<"La cédula del socio o asociado no se ha encontrado"<<endl;
            }
        }
        
        if (exito){

            do{
                cout<<endl;
                cout<<"¿Está seguro de querer eliminar a ésta persona? [1=Si] [2=No]: ";
                cin>>op;

                if (op<1 or op>2){
                    cout<<"Ingrese dentro del rango [1-2]!!!"<<endl;
                    system("pause");
                    system("cls");
                }
            }while (op<1 or op>2);

            if (op == 1){
                if (st){
                    socios[indice1].asociados[indice2].est_asociado = false;
                    cout<<"El asociado ha sido eliminado de la base de datos"<<endl;
                    system("pause");
                    system("cls");
                }
                else{
                    if (sw){
                        socios[indice1].est_socio = false;
                        cout<<"El socio ha sido eliminado de la base de datos"<<endl;
                        system("pause");
                        system("cls");
                    }
                }
            }
        }
        else{
            cout<<"El socio tiene facturas pendientes"<<endl;
            system("pause");
            system("cls");
        }
        cout<<"¿Desea eliminar otro socio o asociado ? [1=Si] [Otro num=No]: ";
        cin>>op;

    }while(op==1);
}
	//---------------------------------------------
void modificar (struct socio socios[], int x, int cont_asociados){
    long aux_ced;
    bool sw, st,ln;
    int indice1, indice2, exito, op;
    do{
        sw=false;
        st=false;
        exito = false;
        cout<<"Ingrese la cédula del socio o del asociado que desea modificar datos: ";
        cin>>aux_ced;

        for (int i=0; i<x; i++){
            for (int j=0; j<cont_asociados; j++){
                if (aux_ced == socios[i].asociados[socios[j].num_asociados].ced_asociado){
                    indice1 = i;
                    indice2 = j;
                    st=true;
                    break;
                }
            }
        }

        for (int i=0; i<x; i++){
            if (aux_ced == socios[i].cedula){
                indice1 = i;
                sw=true;
                break;
            }
        }

        if (st){

            cout<<endl;
            cout<<"Información actual del asociado"<<endl;
            cout<<"Nombre: "<<socios[indice1].asociados[indice2].nombre_asociado<<endl;
            cout<<"Cédula: "<<socios[indice1].asociados[indice2].ced_asociado<<endl;
            cout<<"Cédula del socio: "<<socios[indice1].asociados[indice2].ced_socio<<endl;
            cout<<"Parentesco: "<<socios[indice1].asociados[indice2].parentesco<<endl;
            cout<<"Edad: "<<socios[indice1].asociados[indice2].edad<<endl;
            cout<<"Sexo: "<<socios[indice1].asociados[indice2].sexo<<endl;
            
            exito=true;
        }
        else{
            if (sw){
                cout<<endl;
                cout<<"Información actual del socio"<<endl;
                cout<<"Nombre: "<<socios[indice1].nombre<<endl;
                cout<<"Cédula"<<socios[indice1].cedula<<endl;
                cout<<"Fondos: "<<socios[indice1].f_disponibles<<endl;
				
				exito=true;
            }
            else{
                cout<<endl;
                cout<<"La cédula del socio o asociado no se ha encontrado"<<endl;
            }
        }
        
        if (exito){

                cout<<endl;
                system("pause");
            
				if(st)
				{
					cout<<"Información para modificar del asociado"<<endl;
    		        cout<<"Nombre: ";fflush(stdin); 
						gets(socios[indice1].asociados[indice2].nombre_asociado);
					do{
						cout<<"Cédula"; 
						cin>>socios[indice1].asociados[indice2].ced_asociado;
						for (int i=0; i<x; i++){
							
							for (int j=0; j<cont_asociados; j++){
								
								if (socios[indice1].asociados[indice2].ced_asociado==socios[i].cedula && indice1!=i && indice2!=j){
    	            				cout<<"La cédula ingresada ya está registrada!!!"<<endl;
        	        				cout<<"Ingresar nuevamente la cedula!!!"<<endl;
            	    				sw=true;
                					system("pause");
                					system("cls");
                					break;
            					}
            					if (socios[indice1].asociados[indice2].ced_asociado==socios[i].asociados[j].ced_asociado && indice1!=i && indice2!=j){
    	            				cout<<"La cédula ingresada ya está registrada!!!"<<endl;
        	        				cout<<"Ingresar nuevamente la cedula!!!"<<endl;
            	    				ln=true;
                					system("pause");
                					system("cls");
                					break;
            					}
							}
 					           
            			}
						
					}while(ln);
						
    	        	cout<<"Parentesco: ";fflush(stdin); 
						gets(socios[indice1].asociados[indice2].parentesco);
    	        	do{	cout<<"Edad: "; 
						cin>>socios[indice1].asociados[indice2].edad;
    	        		}while(socios[indice1].asociados[indice2].edad<=0);
        	    	cout<<"Sexo: ";fflush(stdin); gets(socios[indice1].asociados[indice2].sexo);
				}
				
				if(sw)
				{
					cout<<endl;
					cout<<"Información para modificar del socio"<<endl;
					cout<<"Nombre: ";fflush(stdin); 
						gets(socios[indice1].nombre);
					do{
						cout<<"Cédula"; 
							cin>>socios[indice1].cedula;
						for (int i=0; i<x; i++){
 				           if (socios[indice1].cedula == socios[i].cedula && indice1!=i){
                				cout<<"La cédula ingresada ya está registrada!!!"<<endl;
                				cout<<"Ingresar nuevamente la cedula!!!"<<endl;
                				ln=true;
                				system("pause");
                				system("cls");
                				break;
            				}
            				for (int j=0; j<cont_asociados; j++){
	            				if (socios[indice1].cedula ==socios[i].asociados[j].ced_asociado && indice1!=i && indice2!=j){
    		            				cout<<"La cédula ingresada ya está registrada!!!"<<endl;
        		        				cout<<"Ingresar nuevamente la cedula!!!"<<endl;
            		    				ln=true;
                						system("pause");
                						system("cls");
                						break;
            					}
            				}
            			}
						
					}while(ln);
				}
            

            if (op == 1){
                if (st){
                    socios[indice1].asociados[indice2].est_asociado = false;
                    cout<<"La informacion del asociado se ha modificado exitosamente"<<endl;
                    system("pause");
                    system("cls");
                }
                else{
                    if (sw){
                        socios[indice1].est_socio = false;
                        cout<<"La informacion del socio se ha modificado exitosamente"<<endl;
                        system("pause");
                        system("cls");
                    }
                }
            }
        }
        
        cout<<"¿Desea eliminar otro socio o asociado ? [1=Si] [Otro num=No]: ";
        cin>>op;

    }while(op==1);
}

void consultar (struct socio socios[], int x,int cont_asociados){
	
	int op,indice1,indice2;
	char abc;
	long cd;
	bool sw;
	
	cout<<"\n\t CONSULTAS"<<endl;
	
	do{
	
	cout<<" 1. Consultar Un Socio."<<endl;
	cout<<" 2. Lista de Personas Autorizadas Por Un Socio."<<endl;
	cout<<" 3. Listado de Socios Activos."<<endl;
	cout<<" 4. Listado de Socios Retirados."<<endl;
	cout<<" 5. Listado de Facturas Pendiente Por Pagar."<<endl;
	
	cout<<" Opcion: "; cin>>op;
	
	if(op<1 || op>2)
	cout<<" Valor ingresado invalido!!!"<<endl;
	
	system("pause");
	system("cls");
	
	}while(op<1 || op>2);
	
	switch(op)
	{
		case 1 :	sw=false;
					cout<<"\n Cedula de socio: "; cin>>cd;
					
					for (int i=0; i<x; i++){
	            	if (cd == socios[i].cedula){
    	            	sw=true;
        	        	break;
        	        	indice1=i;
            			}
        			}
        			
        			if(sw)
					{
						cout<<" Nombre: "<<socios[indice1].nombre<<endl;
						cout<<" Cedula: "<<socios[indice1].cedula<<endl;
						if(socios[indice1].tipo_suscrip==1)
							cout<<" Suscripcion: REGULAR"<<endl;
								
						if(socios[indice1].tipo_suscrip==2)
							cout<<" Suscripcion: VIP"<<endl;
						
					
						switch(abc)
						{
							case  'a' :	
										cout<<" Asociados"<<endl;
										for(int i=0; i<cont_asociados; i++)
										{
											cout<<" Asociado No."<<i+1<<endl;
											cout<<" Nombre: "<<socios[indice1].asociados[i].nombre_asociado<<endl;
											cout<<" Parentesco: "<<socios[indice1].asociados[i].parentesco<<endl;
											cout<<endl;
										}
									
										break;
							case  'b' :
										cout<<" Fondos Disponibles: $"<<socios[indice1].f_disponibles<<endl;
										cout<<" Facturas Pendientes:"<<endl;
										
										for(int i=0; i<socios[indice1].cont_factu; i++ )
										{
											if(socios[indice1].factura[i].estado==false)
											{
												cout<<" Numero de Factura: "<<socios[indice1].factura[i].num_factura<<endl;
												cout<<" Concepto: "<<socios[indice1].factura[i].concepto<<endl;
												cout<<" Valor: $"<<socios[indice1].factura[i].vlr_consumo<<endl;
												cout<<" Fecha: "<<socios[indice1].factura[i].fecha_consumo.dia<<"/";
												cout<<socios[indice1].factura[i].fecha_consumo.mes<<"/";
												cout<<socios[indice1].factura[i].fecha_consumo.anio<<endl;
											}
										}
										
										break;
						}
					}
					else{
							cout<<" Cedula de socio no encontrada"<<endl;
							system("pause");
					}
					
					break;
		case 2 :	sw=false;
					cout<<"\n Cedula de socio: "; cin>>cd;
					
					for (int i=0; i<x; i++){
	            	if (cd == socios[i].cedula){
    	            	sw=true;
        	        	break;
        	        	indice1=i;
            			}
        			}
        			
        			if(sw)
					{	cout<<" Asociados"<<endl;
						for(int i=0; i<cont_asociados; i++)
						{
							cout<<" Asociado No."<<i+1<<endl;
							cout<<" Nombre: "<<socios[indice1].asociados[i].nombre_asociado<<endl;
							cout<<" cedula: "<<socios[indice1].asociados[i].ced_asociado<<endl;
							cout<<" edad: "<<socios[indice1].asociados[i].edad<<endl;
							cout<<endl;
						}
				
					}
					else{
							cout<<" Cedula de socio no encontrada"<<endl;
							system("pause");
					}
					
					break;
					
		case 3 :	orden_ascen(socios,x);
					
					cout<<"\n\tSOCIOS ACTIVOS\n"<<endl;
					for(int i=0; i<x; i++){
						
						if(socios[i].est_socio)
						{
							cout<<" Nombre: "<<socios[i].nombre<<endl;
							cout<<" Cedula: "<<socios[i].cedula<<endl;
							cout<<" Fondos: $"<<socios[i].f_disponibles<<endl;
							if(socios[i].tipo_suscrip==1)
							cout<<" Suscripcion: REGULAR"<<endl;
								
							if(socios[i].tipo_suscrip==2)
							cout<<" Suscripcion: VIP"<<endl;
							
							cout<<" Cant. Asociados: "<<socios[i].num_asociados<<endl;
						}
						cout<<endl;
					}
					break;
		case 4 :	orden_descen(socios,x);
					cout<<"\n\tSOCIOS RETIRADOS\n"<<endl;
					for(int i=0; i<x; i++){
						
						if(socios[i].est_socio==false)
						{
							cout<<" Nombre: "<<socios[i].nombre<<endl;
							cout<<" Cedula: "<<socios[i].cedula<<endl;
							cout<<" Fondos: $"<<socios[i].f_disponibles<<endl;
							if(socios[i].tipo_suscrip==1)
							cout<<" Suscripcion: REGULAR"<<endl;
								
							if(socios[i].tipo_suscrip==2)
							cout<<" Suscripcion: VIP"<<endl;
							
							cout<<" Cant. Asociados: "<<socios[i].num_asociados<<endl;
						}
						cout<<endl;
					}
					break;
		case 5 :	
					cout<<"\n\tFACTURAS PENDIENTES\n"<<endl;
					for(int i=0; i<x; i++ ){
						for(int j=0; j<socios[j].cont_factu; j++ ){
							if(socios[indice1].factura[i].estado==false){
								cout<<" Numero de Factura: "<<socios[i].factura[j].num_factura<<endl;
								cout<<" Cedula Socio: "<<socios[i].factura[j].ced_factu<<endl;
								cout<<" Concepto: "<<socios[i].factura[j].concepto<<endl;
								cout<<" Valor: $"<<socios[i].factura[j].vlr_consumo<<endl;
								cout<<" Fecha: "<<socios[i].factura[j].fecha_consumo.dia<<"/";
								cout<<socios[i].factura[j].fecha_consumo.mes<<"/";
								cout<<socios[i].factura[j].fecha_consumo.anio<<endl;
							}
						}
					}
					
					break;
		
	}
}
