#include <iostream>
#include <string.h>
using namespace std;
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
    bool estado=false;
};

struct asociado{
    long ced_socio;
    long ced_asociado;
    char nombre_asociado [50];
    char parentesco [50];
    int edad;
    char sexo [15];
    bool est_asociado=true;
};

struct socio{
	long cedula;
	char nombre[50];
	long f_disponibles;
	int tipo_suscrip;
    int num_asociados=0;
    int cont_factu=0;
    bool est_socio=true;
    asociado asociados [3600];
    factu factura [9000];
}socios[900];

void afiliar_socio (struct socio socios [], int &x, int &socios_regulares, int &socios_vip);
void registrar_asociado (struct socio socios [], int x, int &cont_asociados);
void registrar_consumo (struct socio socios [], int x, int cont_asociados, int &conteo_facturas);
void pagar_factura (struct socio socios [], int x, int conteo_facturas);
void aumentar_fondos (struct socio socios [], int x);
void eliminar (struct socio socios[], int &x, int &cont_asociados, int &socios_regulares, int &socios_vip);
void modificar (struct socio socios[], int x, int cont_asociados, int &socios_regulares, int &socios_vip);
void consultar_socio(struct socio socios[], int x, char opc);
void personas_autorizadas (struct socio socios[], int x);
void socios_activos (struct socio socios[], int x);
void orden_descen(struct socio socios[],int n);
void orden_ascen(struct socio socios[],int n);
void socios_retirados (struct socio socios [], int n);
void listado_facturas (struct socio socios [], int x, int conteo_facturas, struct factu ordenada[]);


int main(){
    setlocale (LC_ALL, "spanish");
    int op, x=0, cont_asociados=0, conteo_facturas=0, socios_regulares=0, socios_vip=0;
    char opc;

    cout<<"El siguiente programa será un sistema completo de gestión de socios para el club"<<endl;
	cout<<",permitiendo registrar, modificar,"<<endl; 
	cout<<"consultar y realizar operaciones relacionadas con los socios,"<<endl; 
	cout<<"asociados, consumos y facturas."<<endl;
	cout<<endl;
    cout<<"Integrantes: "<<endl;
    cout<<"José David Torres Acevedo: 0222120038"<<endl;
    cout<<"Roberto Junior Martínez Paternina: 0222120018"<<endl;
    cout<<"Diego Andrés Martínez Florez: 0222120002"<<endl;
    cout<<"Programa: Ingeniería de sistemas"<<endl;
    system("pause");
    system("cls");

    do{
        factu ordenada [conteo_facturas];
        do{
            system("cls");
            cout<<"1. Afiliar un socio al club"<<endl;
            cout<<"2. Registrar Asociado"<<endl;
            cout<<"3. Registrar Consumo"<<endl;
            cout<<"4. Pagar Una Factura"<<endl;
            cout<<"5. Aumentar Fondos de la Cuenta De Un Socio"<<endl;
            cout<<"6. Cancelar Suscripción Socio"<<endl;
            cout<<"7. Modificar Información Socio"<<endl;
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
            case 1: afiliar_socio (socios, x, socios_regulares, socios_vip);
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
			        eliminar (socios, x, cont_asociados, socios_regulares, socios_vip);
                }
                else{
                    cout<<"Debe afiliar al menos 1 socio para acceder a esta opción"<<endl;
                    system("pause");
                    system("cls");
                }
            break;
            case 7:
                if (x>0){
                    modificar (socios, x, cont_asociados, socios_regulares, socios_vip);
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
                            system("cls");
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
                                    consultar_socio(socios, x, opc);
                                break;
                                case 'b':
                                    consultar_socio(socios, x, opc);
                                break;
                            } 
                        break;
                        case 2:
                           personas_autorizadas (socios, x);
                        break;
                        case 3:
                            socios_activos (socios, x);
                        break;
                        case 4:
                            socios_retirados (socios, x);
                        break;
                        case 5:
                            listado_facturas (socios , x, conteo_facturas, ordenada);
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


/*
Esta función permite afiliar un nuevo socio al club. 
Registra la información del socio, como la cédula, nombre, fondos disponibles y tipo de suscripción. 
Además, realiza las validaciones correspondientes, 
como verificar que no exista otro socio con la misma cédula y que el límite de socios VIP no se haya alcanzado.
*/

void afiliar_socio (struct socio socios [], int &x, int &socios_regulares, int &socios_vip){
    
	int sw, st, aux_suscrip;
    long aux_ced, aux_fondo;
    char aux_nombre [50];

    do{
        sw=1;
        st=1;
        system("cls");
        cout<<"Registro No. "<<x+1<<endl;
        cout<<"Cédula del socio: "; 
        cin>>aux_ced;
        for (int i=0; i<x; i++){
            if (aux_ced == socios[i].cedula){
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
            gets (aux_nombre);
        
            do{
                st=1;
                sw=1;
                cout<<"Tipo de suscripción [1.Regular - 2.VIP]: ";
                cin>>aux_suscrip;

                if (aux_suscrip<1 or aux_suscrip>2){
                    cout<<"Ingrese dentro del rango [1-2]!!!"<<endl;
                    system("pause");
                    system("cls");
                    st=0;
                }
            }while(st==0);

            if (aux_suscrip == 2){
                if ((((socios_regulares+socios_vip)/5)*2)>=(socios_vip+1)){
                    sw=1;
                }
                else{
                    system("cls");
                    cout<<"Se ha sobrepasado la cantidad de socios VIP permitidos!!!"<<endl;
                    sw=0;
                    system("pause");
                }
            } 
                
            if(sw==1){
                st=1;
                cout<<"Fondos disponibles: ";
                cin>>aux_fondo;
                
                if (aux_suscrip==1){
                    if (aux_fondo<300000){
                        system("cls");
                        cout<<"El monto inicial mínimo para miembros regulares es de $300 000"<<endl;
                        st=0;
                        system("pause");
                    }
                    else{
                        if (aux_fondo>2000000){
                            system("cls");
                            cout<<"El monto inicial máximo para miembros regulares es de $2 000 000"<<endl;
                            st=0;
                            system("pause");
                        }
                    }
                }
                else{
                    if (aux_suscrip==2){
                        if (aux_fondo<1000000){
                            system("cls");
                            cout<<"El monto inicial para miembros VIP debe ser de $1 000 000"<<endl;
                            st=0;
                            system("pause");
                        }
                        else{
                            if (aux_fondo>5000000){
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
                strcpy (socios[x].nombre, aux_nombre);
                
                for (int i=0; i<strlen(socios[x].nombre); i++){
                    aux_nombre[i] = toupper (aux_nombre[i]);
                    socios[x].nombre[i] = aux_nombre[i];
                }
                socios[x].cedula = aux_ced;
                socios[x].f_disponibles = aux_fondo;
                socios[x].tipo_suscrip = aux_suscrip;

                if (aux_suscrip == 1){
                    socios_regulares++;
                }
                else{
                    if (aux_suscrip == 2){
                        socios_vip++;
                    }
                }
                x++;
            }
            else{
                cout<<"El registro no se ha realizado correctamente"<<endl;
            }
        }
        cout<<endl;
        cout<<"¿Desea realizar un nuevo registro? [0 = Si] - [Otro# = No]: ";
        cin>>sw;
        system("pause");
        system("cls");
        
    }while(sw==0);
}

/*
Esta función permite registrar a una persona autorizada por un socio. 
Se solicita la información del socio y del asociado, como la cédula, nombre, parentesco, edad y sexo. 
Antes de realizar el registro, se validan condiciones, como la existencia del socio y fondos suficientes.
*/

void registrar_asociado (struct socio socios [], int x, int &cont_asociados){
    int op, sw=0, cont=0, in_socio, st=1, i=0, aux_edad;
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
                if ((strcmp(nombre_socio, socios[i].nombre) == 0) && (socios[i].est_socio == true)){
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
                if ((cedula_socio == socios[i].cedula) && (socios[i].est_socio == true)){
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

            do{
                cout<<"Ingrese la edad del asociado: ";
                cin>>aux_edad;
            }while(aux_edad<=0);
            
            for (i=0; i<x; i++){
                for (int j=0; j<cont_asociados; j++){
                    if (aux_cedula == socios[i].asociados[j].ced_asociado){
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
                    socios[in_socio].asociados[socios[in_socio].num_asociados].edad = aux_edad;
                    cout<<endl;
                    cout<<"El registro ha sido exitoso"<<endl;
                }
            }
        }
        system("pause");
        system("cls");
        cout<<"¿Desea registrar otro asociado? [0: Si] [Otro #: No]: ";
        cin>>sw;
        system("cls");
    }while(sw==0);
}

/*
Esta función registra un consumo en la cuenta de un socio. 
Se ingresan datos como la cédula o nombre del socio, 
el número de factura, la cédula de quien realizó el consumo, 
el concepto, el valor del consumo y la fecha. 
Se valida que el socio tenga fondos suficientes para pagar el consumo 
y se guarda la información en un vector de consumos.
*/

void registrar_consumo (struct socio socios [], int x, int cont_asociados, int &conteo_facturas){

    int sw, op, in_socio, st=0, aux_factu, aux_dia, aux_mes, aux_anio;
    char aux_concepto [50];
    long aux_valor_consumo, aux_cedu;
    bool verifica=false;
    long cedula_socio;
    char nombre_socio [50];
    do{
        cout<<"Registrar un consumo"<<endl;
        do{
            sw=1;
            st=0;
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
                if ((strcmp(nombre_socio, socios[i].nombre) == 0) && (socios[i].est_socio == true)){
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
                if ((cedula_socio == socios[i].cedula) && (socios[i].est_socio == true)){
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
                        break;
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
                        if (aux_cedu == socios[i].asociados[j].ced_asociado){
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
            
            cout<<"Cédula: "<<socios[in_socio].factura[socios[in_socio].cont_factu].ced_factu<<endl;
            cout<<"Concepto: "<<socios[in_socio].factura[socios[in_socio].cont_factu].concepto<<endl;
            cout<<"Número de factura: "<<socios[in_socio].factura[socios[in_socio].cont_factu].num_factura<<endl;
            cout<<"Valor de consumo: "<<socios[in_socio].factura[socios[in_socio].cont_factu].vlr_consumo<<endl;
            cout<<"Fecha: "<<socios[in_socio].factura[socios[in_socio].cont_factu].fecha_consumo.dia<<" / "<<socios[in_socio].factura[socios[in_socio].cont_factu].fecha_consumo.mes<<" / "<<socios[in_socio].factura[socios[in_socio].cont_factu].fecha_consumo.anio<<endl;
            socios[in_socio].cont_factu++;
            conteo_facturas++;
            cout<<endl;

            system("pause");
            system("cls");
        }
        cout<<"¿Desea registrar otra factura? [0: Si] [Otro #: No]: ";
        cin>>st;
        system("pause");
        system("cls");
    }while(st==0);
}

/*

Esta función permite pagar una factura pendiente. 
Se ingresa el nombre del socio o el número de factura y 
se muestra el detalle de la factura. Se actualiza el estado de la factura de "pendiente" a
"cancelado" y se realizan las actualizaciones necesarias en los fondos del socio.
*/

void pagar_factura (struct socio socios [], int x, int conteo_facturas){
    int sw, op, in_socio, cont_facturas_pendientes, salida;
    long numero_factura;
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
                if ((strcmp(nombre_socio, socios[i].nombre) == 0) && (socios[i].est_socio == true)){
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
                            cout<<"¿Desea pagar la factura? [1-Si] [2-No]: ";
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

            if (socios[in_socio].cont_factu>0){
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
            else{
                cout<<"El socio no tiene facturas por pagar"<<endl;
            }
        }
        cout<<"¿Desea pagar otra factura? [1=Si] [Otro num=No]: ";
        cin>>salida;
        system("pause");
        system("cls");
    }while(salida==1);
}

/*
Esta función permite aumentar los fondos de la cuenta de un socio. 
Se modifica este dato, teniendo en cuenta las restricciones mencionadas anteriormente, 
como el límite máximo de fondos según el tipo de suscripción.
*/


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
                    if ((strcmp(nombre_socio, socios[i].nombre) == 0) && (socios[i].est_socio == true)){
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
                    if ((cedula_socio == socios[i].cedula) && (socios[i].est_socio == true)){
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

/*
Esta función cancela la suscripción de un socio o elimina a un asociado. 
Se ingresa la cédula del socio o asociado y se verifica que no tenga facturas pendientes por pagar. 
En caso de cumplir con las condiciones, se realiza la baja del socio y sus asociados autorizados.
*/
void eliminar (struct socio socios[], int &x, int &cont_asociados, int &socios_regulares, int &socios_vip){
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
            for (int j=0; j<socios[i].num_asociados; j++){
                if ((aux_ced == socios[i].asociados[j].ced_asociado) && (socios[i].est_socio == true)){
                    indice1 = i;
                    indice2 = j;
                    st=true;
                    break;
                }
            }
        }

        for (int i=0; i<x; i++){
            if ((aux_ced == socios[i].cedula) && (socios[i].est_socio == true)){
                indice1 = i;
                sw=true;
                break;
            }
        }

        for (int i=0; i<socios[indice1].cont_factu; i++){
            if (socios[indice1].factura[i].estado == false){
                exito = false;
            }
        }

        if (socios[indice1].est_socio == true){

            if (st){
                cout<<endl;
                cout<<"Información del asociado"<<endl;
                cout<<"Nombre: "<<socios[indice1].asociados[indice2].nombre_asociado<<endl;
                cout<<"Cédula: "<<socios[indice1].asociados[indice2].ced_asociado<<endl;
                cout<<"Cédula del socio: "<<socios[indice1].asociados[indice2].ced_socio<<endl;
                cout<<"Parentesco: "<<socios[indice1].asociados[indice2].parentesco<<endl;
                cout<<"Edad: "<<socios[indice1].asociados[indice2].edad<<endl;
                cout<<"Sexo: "<<socios[indice1].asociados[indice2].sexo<<endl;
            }
            else{
                if (sw){
                    cout<<endl;
                    cout<<"Información del socio"<<endl;
                    cout<<"Nombre: "<<socios[indice1].nombre<<endl;
                    cout<<"Cédula"<<socios[indice1].cedula<<endl;
                    cout<<"Fondos: "<<socios[indice1].f_disponibles<<endl;
                }
                else{
                    cout<<endl;
                    cout<<"La cédula del socio o asociado no se ha encontrado"<<endl;
                    exito=false;
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
                        socios[indice1].num_asociados--;
                        cout<<"El asociado ha sido eliminado de la base de datos"<<endl;
                        system("pause");
                        system("cls");
                    }
                    else{
                        if (sw){
                            socios[indice1].est_socio = false;
                            cout<<"El socio ha sido eliminado de la base de datos"<<endl;
                            if (socios[indice1].tipo_suscrip == 1){
                                socios_regulares--;
                            }
                            else{
                                socios_vip--;
                            }
                            system("pause");
                            system("cls");
                        }
                    }
                }
                else{
                    system("cls");
                    system("pause");
                }
            }
            else{
                cout<<"El socio tiene facturas pendientes"<<endl;
                system("pause");
                system("cls");
            }
        }
        else{
            cout<<"El socio o asociado fue eliminado previamente"<<endl;
        }

        cout<<"¿Desea eliminar otro socio o asociado ? [1=Si] [Otro num=No]: ";
        cin>>op;
        system("pause");
        system("cls");

    }while(op==1);
}

/*
Esta función permite modificar la información de un socio o asociado. 
Se ingresa la cédula del socio o asociado y 
se verifica su existencia. Luego, se modifican los datos requeridos.
*/

void modificar (struct socio socios[], int x, int cont_asociados, int &socios_regulares, int &socios_vip){
    int op, indice1, indice2, aux_saldo, aux_edad, aux_regulares;
    long aux_ced;
    bool sw, st, sn;
    do{
        cout<<"Modificar información de socio o asociado"<<endl;
        cout<<"Ingrese la cédula del socio o del asociado que desea modificar: ";
        cin>>aux_ced;
        
        sw=false;
        st=false;
        
        for (int i=0; i<x; i++){
            if ((aux_ced == socios[i].cedula) && (socios[i].est_socio == true)){
                indice1 = i;
                sw=true;
                break;
            }
        }

        for (int i=0; i<x; i++){
            for (int j=0; j<socios[i].num_asociados; j++){
                if ((aux_ced == socios[i].asociados[j].ced_asociado) && (socios[i].est_socio == true)){
                    indice1 = i;
                    indice2 = j;
                    st=true;
                    break;
                }
            }
        }

        if (sw){
            cout<<endl;
            cout<<"Información del socio"<<endl;
            cout<<"Nombre: "<<socios[indice1].nombre<<endl;
            cout<<"Cédula"<<socios[indice1].cedula<<endl;
            cout<<"Fondos: "<<socios[indice1].f_disponibles<<endl;
            cout<<endl;
            do{   
                cout<<"1.Modificar cédula"<<endl;
                cout<<"2.Modificar el nombre"<<endl;
                cout<<"3.Modificar suscripción"<<endl;
                cout<<"4.Modificar fondos"<<endl;
                cout<<"Ingrese una opción: ";
                cin>>op;

                switch (op){
                    case 1:
                        system("cls");
                        cout<<"Ingrese la nueva cédula del socio: ";
                        cin>>aux_ced;

                        for (int i=0; i<x; i++){
                            if ((aux_ced == socios[i].cedula) && (socios[i].est_socio == true)){
                                indice1 = i;
                                sn=true;
                                break;
                            }
                        }

                        for (int i=0; i<x; i++){
                            for (int j=0; j<socios[i].num_asociados; j++){
                                if ((aux_ced == socios[i].asociados[j].ced_asociado) && (socios[i].est_socio == true)){
                                    indice1 = i;
                                    indice2 = j;
                                    sn=true;
                                    break;
                                }
                            }
                        }

                        if (sn){
                            cout<<"La cédula ingresada ya se encuentra registrada"<<endl;
                            system("pause");
                            system("cls");
                        }
                        else{
                            socios[indice1].cedula = aux_ced;
                        }

                    break;
                    case 2: 
                        system("cls");
                        cout<<"Ingrese el nuevo nombre del socio: ";
                        fflush (stdin);
                        gets (socios[indice1].nombre);
                    break;
                    case 3: 
                        system("cls");
                        cout<<"Ingrese su nueva suscripción [1-Regular] [2-VIP]: ";
                        cin>>op;

                        switch (op){
                            case 1:
                                if ((socios[indice1].tipo_suscrip == 2) && (socios[indice1].f_disponibles>=300000) && (socios[indice1].f_disponibles<=2000000)){
                                    socios[indice1].tipo_suscrip = 1;
                                }
                                else{
                                    if (socios[indice1].f_disponibles<3000000){
                                        cout<<"Para registrarse como regular su fondo debe ser mínimo de $300 000"<<endl;
                                        system("pause");
                                        system("cls");
                                    }

                                    if (socios[indice1].f_disponibles>2000000){
                                        cout<<"Para registrarse como regular su fondo debe ser máximo de $2 000 000"<<endl;
                                        system("pause");
                                        system("cls");
                                    }
                                }
                            break;
                            case 2:
                                if ((socios[indice1].tipo_suscrip == 1) && (socios[indice1].f_disponibles>=1000000) && (socios[indice1].f_disponibles<=5000000)){
                                    aux_regulares=0;
                                    aux_regulares=socios_regulares;
                                    aux_regulares--;
                                    if ((((aux_regulares+socios_vip)/5)*2)>=(socios_vip+1)){
                                        socios_vip++;
                                        socios_regulares--;
                                        socios[indice1].tipo_suscrip=2;
                                    }
                                    else{
                                        cout<<"Se ha sobrepasado el límite de socios VIP"<<endl;
                                    }
                                }
                                else{
                                    if (socios[indice1].f_disponibles<1000000){
                                        cout<<"Para registrarse como vip su fondo debe ser mínimo de $1 000 000"<<endl;
                                        system("pause");
                                        system("cls");
                                    }
                                }
                            break;
                            default:
                                cout<<"Ingrese dentro del rango [1-2]"<<endl;
                            break;
                        } 
                    break;
                    case 4:
                        system("cls");
                        cout<<"Ingrese el nuevo saldo del socio: ";
                        cin>>aux_saldo;

                        if (aux_saldo<0){
                            cout<<"El saldo no puede ser menor a cero"<<endl;
                            system("pause");
                            system("cls");
                        }
                        else{
                            if ((socios[indice1].tipo_suscrip == 1) && (aux_saldo<=2000000)){
                                socios[indice1].f_disponibles = aux_saldo;
                            }
                            else{
                                if ((socios[indice1].tipo_suscrip == 2) && (aux_saldo<=5000000)){
                                    socios[indice1].f_disponibles = aux_saldo;
                                }
                                else{
                                    cout<<"No es posible hacer la modificación de saldo"<<endl;
                                    system("pause");
                                    system("cls");
                                }
                            }
                        }
                    break;
                    default:
                        cout<<"Ingrese dentro del rango [1-3]"<<endl;
                        system("pause");
                        system("cls");
                    break;
                }
                cout<<"¿Desea modificar otro dato del socio? [1-Si] [Otro Num-No]: ";
                cin>>op;
                system("pause");
                system("cls");
                if (op!=1){
                    cout<<endl;
                    cout<<"Información del socio"<<endl;
                    cout<<"Nombre: "<<socios[indice1].nombre<<endl;
                    cout<<"Cédula"<<socios[indice1].cedula<<endl;
                    cout<<"Fondos: "<<socios[indice1].f_disponibles<<endl;
                    cout<<endl;
                    system("pause");
                    system("cls");
                }
            }while(op==1);
        }
        else{
            if (st){
                cout<<endl;
                cout<<"Información del asociado"<<endl;
                cout<<"Nombre: "<<socios[indice1].asociados[indice2].nombre_asociado<<endl;
                cout<<"Cédula: "<<socios[indice1].asociados[indice2].ced_asociado<<endl;
                cout<<"Cédula del socio: "<<socios[indice1].asociados[indice2].ced_socio<<endl;
                cout<<"Parentesco: "<<socios[indice1].asociados[indice2].parentesco<<endl;
                cout<<"Edad: "<<socios[indice1].asociados[indice2].edad<<endl;
                cout<<"Sexo: "<<socios[indice1].asociados[indice2].sexo<<endl;
                cout<<endl;
                do{
                    cout<<"1. Cédula del asociado"<<endl;
                    cout<<"2. Nombre del asociado"<<endl;
                    cout<<"3. Parentesco"<<endl;
                    cout<<"4. Edad"<<endl;
                    cout<<"5. Sexo"<<endl;
                    cout<<"Ingrese una opción: ";
                    cin>>op;

                    switch (op){
                        case 1: 
                            system("cls");
                            cout<<"Ingrese la nueva cédula del asociado: ";
                            cin>>aux_ced;

                            for (int i=0; i<x; i++){
                                for (int j=0; j<socios[i].num_asociados; j++){
                                    if ((aux_ced == socios[i].asociados[j].ced_asociado) && (socios[i].est_socio == true)){
                                        indice1 = i;
                                        indice2 = j;
                                        st=true;
                                        break;
                                    }
                                }
                            }

                            for (int i=0; i<x; i++){
                                if ((aux_ced == socios[i].cedula) && (socios[i].est_socio == true)){
                                    indice1 = i;
                                    sn=true;
                                    break;
                                }
                            }

                            if (st){
                                cout<<"La cédula ingresada ya se encuentra registrada"<<endl;
                                system("pause");
                                system("cls");
                            }
                            else{
                                socios[indice1].asociados[indice2].ced_asociado = aux_ced;
                            }
                        break;
                        case 2:
                            system("cls");
                            cout<<"Ingrese el nuevo nombre del asociado: ";
                            fflush (stdin);
                            gets (socios[indice1].asociados[indice2].nombre_asociado);
                        break;
                        case 3:
                            system("cls");
                            cout<<"Ingrese el nuevo parentesco del asociado: ";
                            fflush (stdin);
                            gets (socios[indice1].asociados[indice2].parentesco);
                        break;
                        case 4:
                            system("cls");
                            cout<<"Ingrese la nueva edad del asociado: ";
                            cin>>aux_edad;

                            if (aux_edad<=0){
                                cout<<"La edad ingresada es invalida"<<endl;
                                system("pause");
                                system("cls");
                            }
                            else{
                                socios[indice1].asociados[indice2].edad = aux_edad;
                            }
                        break;
                        case 5:
                            system("cls");
                            cout<<"Ingrese el nuevo sexo del asociado: ";
                            fflush (stdin);
                            gets (socios[indice1].asociados[indice2].sexo);
                        break;
                        default:
                            cout<<"Ingrese dentro del rango [1-5]"<<endl;
                            system("pause");
                            system("cls");
                        break;
                    }
                    cout<<"Desea modificar otro dato del asociado [1-Si] [Otro num-No]: ";
                    cin>>op;
                    system("cls");
                }while(op==1);
            }
            else{
                cout<<"La cédula no se ha encontrado"<<endl;
                system("pause");
                system("cls");
            }
        }
        cout<<"¿Desea modificar información de otro socio o asociado? [1-Si] [Otro Num-No]: ";
        cin>>op;
        system("cls");
    }while(op==1);
}

/*
Muestra información detallada de un socio, como su nombre, tipo de suscripción y asociados con su parentesco.
*/

void consultar_socio(struct socio socios[], int x, char opc){
    long aux_ced;
    int indice1;
    bool sn=false;
    switch (opc){
        case 'a': 
            cout<<"Ingrese la cédula del socio: ";
            cin>>aux_ced;

            for (int i=0; i<x; i++){
                if ((aux_ced == socios[i].cedula) && (socios[i].est_socio == true)){
                    indice1 = i;
                    sn=true;
                    break;
                }
            }

            if (sn){
                cout<<endl;
                cout<<"Información del socio"<<endl;
                cout<<"Nombre: "<<socios[indice1].nombre<<endl;
                cout<<"Tipo de suscripción: ";
                if (socios[indice1].tipo_suscrip == 1){
                    cout<<"Regular"<<endl;
                }
                else{
                    cout<<"VIP"<<endl;
                }

                if (socios[indice1].num_asociados>0){
                    for (int i=0; i<socios[indice1].num_asociados; i++){
                        cout<<"Nombre del asociado: "<<socios[indice1].asociados[i].nombre_asociado<<endl;
                        cout<<"Parentesco: "<<socios[indice1].asociados[i].parentesco<<endl;
                        cout<<endl;
                    }
                }
                else{
                    cout<<"El socio no tiene asociados registrados"<<endl;
                    system("pause");
                    system("cls");
                }
                system("pause");
                system("cls");
            }
            else{
                cout<<"La cédula del socio no se encuentra registrada"<<endl;
                system("pause");
                system("cls");
            }
        break;
        case 'b':
            cout<<"Ingrese la cédula del socio: ";
            cin>>aux_ced;

            for (int i=0; i<x; i++){
                if ((aux_ced == socios[i].cedula) && (socios[i].est_socio == true)){
                    indice1 = i;
                    sn=true;
                    break;
                }
            }

            if (sn){
                cout<<"Información del socio"<<endl;
                cout<<"Nombre: "<<socios[indice1].nombre<<endl;
                cout<<"Tipo de suscripción: ";
                if (socios[indice1].tipo_suscrip == 1){
                    cout<<"Regular"<<endl;
                }
                else{
                    cout<<"VIP"<<endl;
                }
                cout<<"Fondos disponibles: "<<socios[indice1].f_disponibles<<endl;

                if (socios[indice1].cont_factu>0){
                    for (int i=0; i<socios[indice1].cont_factu; i++){
                        if (socios[indice1].factura[i].estado == false){
                            cout<<"Número de factura: "<<socios[indice1].factura[i].num_factura<<endl;
                            cout<<"Cédula de la persona que realizó el consumo: "<<socios[indice1].factura[i].ced_factu<<endl;
                            cout<<"Concepto: "<<socios[indice1].factura[i].concepto<<endl;
                            cout<<"Valor de la factura: "<<socios[indice1].factura[i].vlr_consumo<<endl;
                            cout<<"Fecha: "<<socios[indice1].factura[i].fecha_consumo.dia<<"/"<<socios[indice1].factura[i].fecha_consumo.mes<<"/"<<socios[indice1].factura[i].fecha_consumo.anio<<endl;
                            cout<<endl;
                        }
                    }
                }
                system("pause");
                system("cls");
            }
            else{
                cout<<"La cédula del socio no se encuentra registrada"<<endl;
                system("pause");
                system("cls");
            }
        break;
    }
}


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

/*
Muestra un listado de los socios activos, incluyendo su cédula, nombre, 
tipo de suscripción, fondos disponibles y cantidad de asociados. 
El listado está ordenado ascendentemente por el nombre de los socios.
*/
void socios_activos (struct socio socios[], int x){
    orden_ascen(socios,x);
	cout<<"\n\tSOCIOS ACTIVOS\n"<<endl;
	for(int i=0; i<x; i++){
		if(socios[i].est_socio){
            cout<<" Nombre: "<<socios[i].nombre<<endl;
            cout<<" Cedula: "<<socios[i].cedula<<endl;
            cout<<" Fondos: $"<<socios[i].f_disponibles<<endl;
            if(socios[i].tipo_suscrip==1){
                cout<<" Suscripcion: REGULAR"<<endl;
            }
                               
            if(socios[i].tipo_suscrip==2){
                cout<<" Suscripcion: VIP"<<endl;
            }
            cout<<" Cant. Asociados: "<<socios[i].num_asociados<<endl;
        }
		cout<<endl;
    }
}

/*
Muestra la lista de personas autorizadas por un socio, mostrando su cédula, nombre y edad.
*/


void personas_autorizadas (struct socio socios[], int x){
    long aux_ced;
    int indice1;
    bool sn=false;
    cout<<"Ingrese la cédula del socio: ";
    cin>>aux_ced;

    for (int i=0; i<x; i++){
        if ((aux_ced == socios[i].cedula) && (socios[i].est_socio == true)){
            indice1 = i;
            sn=true;
            break;
        }
    }
    if ((sn==true) && (socios[indice1].num_asociados>0)){
        cout<<"Lista de personas autorizadas por el socio"<<endl;
        for (int i=0; i<socios[indice1].num_asociados; i++){
            cout<<"Cédula: "<<socios[indice1].asociados[i].ced_asociado<<endl;
            cout<<"Nombre: "<<socios[indice1].asociados[i].nombre_asociado<<endl;
            cout<<"Edad: "<<socios[indice1].asociados[i].edad<<endl;
            cout<<endl;
        }

    }
    else{
        if (sn==false){
            cout<<"No se ha encontrado la cédula del socio"<<endl;
            system("pause");
            system("cls");
        }
        else{
            if (socios[indice1].num_asociados<=0){
                cout<<"El socio no tiene asociados registrados"<<endl;
                system("pause");
                system("cls");
            }
        }
    }
}

/*
Muestra un listado de los socios retirados, 
incluyendo su cédula, nombre, tipo de suscripción, cantidad de asociados y fecha de retiro. 
El listado está ordenado descendentemente por la cantidad de asociados.
*/


void socios_retirados (struct socio socios [], int x){
    orden_descen(socios, x);
	cout<<"\n\tSOCIOS RETIRADOS\n"<<endl;
	for(int i=0; i<x; i++){
		if(socios[i].est_socio==false){
			cout<<" Nombre: "<<socios[i].nombre<<endl;
			cout<<" Cedula: "<<socios[i].cedula<<endl;
			cout<<" Fondos: $"<<socios[i].f_disponibles<<endl;
			if(socios[i].tipo_suscrip==1){
                cout<<" Suscripcion: REGULAR"<<endl;
            }
							
			if(socios[i].tipo_suscrip==2){
                cout<<" Suscripcion: VIP"<<endl;
            }
			cout<<" Cant. Asociados: "<<socios[i].num_asociados<<endl;
		}
		cout<<endl;
	}
}


/*
Genera un listado de todas las facturas pendientes por pagar, ordenado ascendentemente por la fecha. 
Incluye el detalle de cada factura y el monto total de las cuentas por cobrar.
*/

void listado_facturas (struct socio socios [], int x, int conteo_facturas, struct factu ordenada[]){
    int indice_menor, i, j;
    long total_pendiente=0;
    factu aux;
    system("cls");

    for (int i=0; i<x; i++){
        for (int j=0; j<socios[i].cont_factu; j++){
            ordenada[j].ced_factu = socios[i].factura[j].ced_factu;
            strcpy(ordenada[j].concepto, socios[i].factura[j].concepto);
            ordenada[j].fecha_consumo.dia = socios[i].factura[j].fecha_consumo.dia;
            ordenada[j].fecha_consumo.mes = socios[i].factura[j].fecha_consumo.mes;
            ordenada[j].fecha_consumo.anio = socios[i].factura[j].fecha_consumo.anio;
            ordenada[j].estado = socios[i].factura[j].estado;
            ordenada[j].num_factura = socios[i].factura[j].num_factura;
            ordenada[j].vlr_consumo = socios[i].factura[j].vlr_consumo;
        }
    }

    for (int i = 0; i < x - 1; i++) {
        for (int j = 0; j < x - i - 1; j++) {
            if (ordenada[j].fecha_consumo.anio> ordenada[j + 1].fecha_consumo.anio ||
                (ordenada[j].fecha_consumo.anio == ordenada[j + 1].fecha_consumo.anio && ordenada[j].fecha_consumo.mes > ordenada[j + 1].fecha_consumo.mes) ||
                (ordenada[j].fecha_consumo.anio == ordenada[j + 1].fecha_consumo.anio && ordenada[j].fecha_consumo.mes == ordenada[j + 1].fecha_consumo.mes && ordenada[j].fecha_consumo.dia > ordenada[j + 1].fecha_consumo.dia)) {

                aux = ordenada[j];
                ordenada[j] = ordenada[j + 1];
                ordenada[j + 1] = aux;
            }
        }
    }

    if (conteo_facturas>0){
        cout<<"Listado de facturas pendientes"<<endl;
        for (int i=0; i<conteo_facturas; i++){
            if (ordenada[i].estado == false){
                cout<<"Cédula: "<<ordenada[i].ced_factu<<endl;
                cout<<"Concepto: "<<ordenada[i].concepto<<endl;
                cout<<"Número de factura: "<<ordenada[i].num_factura<<endl;
                cout<<"Valor de consumo: "<<ordenada[i].vlr_consumo<<endl;
                cout<<"Fecha: "<<ordenada[i].fecha_consumo.dia<<" / "<<ordenada[i].fecha_consumo.mes<<" / "<<ordenada[i].fecha_consumo.anio<<endl;
                cout<<endl;
                total_pendiente+=ordenada[i].vlr_consumo;
            } 
        }
        cout<<"Total: "<<total_pendiente<<endl;
        system("pause");
    }
    
}




