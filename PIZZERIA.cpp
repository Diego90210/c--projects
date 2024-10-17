#include <iostream>
using namespace std;

struct costo{
	int fijo;
	int pequena;
	int mediana;
	int grande;
	int extra;
}costos;

struct ped{
    int num_ped;
	char cliente [45];
    int pizza_tipo;
    int ing_extra;
    long costo_prod;
    long precio_venta;
}pedidos[1000];

void ctos (struct costo costos, int x){
	cout<<"Ingrese el precio fijo de produccion: ";
	cin>>costos.fijo;
	cout<<"Ingrese el precio de la pizza pequena: ";
	cin>>costos.pequena;
	cout<<"Ingrese el precio de la pizza mediana: ";
	cin>>costos.mediana;
	cout<<"Ingrese el precio de la pizza grande: ";
	cin>>costos.grande;
	cout<<"Ingrese el precio del ingrediente extra: ";
	cin>>costos.extra;
}

void gest_pedido (struct ped pedidos []){
    static int x=0;
    int sw=0;

    do{
        cout<<"Cliente No. "<<x+1<<endl;
        fflush(stdin);
        cout<<"Nombre: ";
        gets (pedidos[x].cliente);
        
        do{
            cout<<"Tipo de pizza [1-Pequeña] [2-Mediana] [3-Grande]: ";
            cin>>pedidos[x].pizza_tipo;
        }while(pedidos[x].pizza_tipo < 1 or pedidos[x].pizza_tipo>3);

        do{
            cout<<"Cantidad de ingredientes extras: ";
            cin>>pedidos[x].ing_extra;
        }while(pedidos[x].ing_extra < 0);

        pedidos[x].num_ped = x+1;
        pedidos[x].costo_prod = calc_costo (pedidos[x].pizza_tipo, pedidos[x].ing_extra); 
        pedidos[x].precio_venta = pedidos[x].costo_prod * 1.5;
        x++;

        cout<<"Desea registrar otro pedido ? [1-Si] [Otro valor-No]: ";
        cin>>sw;
    }while(sw==1);
}

long calc_costo (int pizza_tipo, int ing_extra){
    int c_variable;

    switch (pizza_tipo){
        case 1: c_variable = costos.pequena;
        break;
        case 2: c_variable = costos.mediana;
        break;
        case 3: c_variable = costos.grande;
        break;
    }
    return costos.fijo + c_variable + (ing_extra * costos.extra);
}

void consultar_ped (int x){
    int consu_ped, sw=0;
    cout<<"Numero de pedido a consultar: ";
    cin>>consu_ped;

    for (int i=0; i<x; i++){
        if (consu_ped == pedidos[i].num_ped){
            sw = 1;
            break;
        }
    }

    if (sw==1){
        cout<<"Cliente: "<<pedidos[consu_ped].cliente<<endl;
		cout<<"Tipo de pizza "<<endl;
		
        switch(pedidos[consu_ped].pizza_tipo){
			case 1:cout<<"\t- Pequeña (10 pulg. De diámetro)"<<endl;break;
			case 2:cout<<"\t- Mediana (12 pulg. De diámetro)"<<endl;break;
			case 3:cout<<"\t- Grandes (16 pulg. De diámetro)"<<endl;
		}
        cout<<"Cantidad de Ingredientes extras: "<<pedidos[consu_ped].ing_extra <<endl;
		cout<<"Costo de producción: "<<	pedidos[consu_ped].costo_prod <<endl;
		cout<<"Precio de venta: "<<	pedidos[consu_ped].precio_venta<<endl;
    }
    else{
        cout<<"No se encontró el pedido"<<endl;
    }
}

void modficar_ped (int x){
    int mod_ped, sw=0, rta;
    cout<<"Numero de pedido a modificar: ";
    cin>>mod_ped;

    for (int i=0; i<x; i++){
        if (mod_ped == pedidos[i].num_ped){
            sw = 1;
            break;
        }
    }

    if (sw==1){
        cout<<"Nombre: "<<pedidos[mod_ped].cliente<<endl;
        cout<<"Desea modificar el nombre del cliente ? [1-Si] [Otro-No]: ";
        cin>>rta;

        if (rta == 1){
            cout<<"Ingrese el nombre del cliente: ";
            gets (pedidos[mod_ped].cliente);
        }

        cout<<"Tipo de pizza "<<endl;
        switch(pedidos[mod_ped].pizza_tipo){
			case 1:cout<<"\t- Pequeña (10 pulg. De diámetro)"<<endl;break;
			case 2:cout<<"\t- Mediana (12 pulg. De diámetro)"<<endl;break;
			case 3:cout<<"\t- Grandes (16 pulg. De diámetro)"<<endl;
		}
        cout<<"Desea modificar el tipo de pizza? [1-Si] [Otro valor-No]: ";

        if (rta == 1){
            do{
                cout<<"Tipo de pizza [1-Pequeña] [2-Mediana] [3-Grande]: ";
                cin>>pedidos[mod_ped].pizza_tipo;
            }while(pedidos[mod_ped].pizza_tipo < 1 or pedidos[mod_ped].pizza_tipo>3);
        }

        cout<<"Cantidad de ingredientes extras: "<<pedidos[mod_ped].ing_extra<<endl;

        cout<<"Desea modificar la cantidad de ingredientes extras ? [1-Si] [Otro Valor-No]: ";
        cin>>rta;

        if (rta == 1){
            do{
                cout<<"Cantidad de ingredientes extras: ";
                cin>>pedidos[mod_ped].pizza_tipo;
            }while(pedidos[mod_ped].pizza_tipo);
        }

        pedidos[mod_ped].costo_prod = calc_costo (pedidos[mod_ped].pizza_tipo, pedidos[mod_ped].ing_extra);
        cout<<"Costo de producción: "<<pedidos[mod_ped].costo_prod<<endl; 
        pedidos[mod_ped].precio_venta = pedidos[mod_ped].costo_prod * 1.5;
        cout<<"Precio: "<<pedidos[mod_ped].precio_venta<<endl;
    }
    else{
        cout<<"No se encontró el pedido"<<endl;
    }
}

/* FALTAN FUNCIONES DE: 
REPORTE DE PEDIDOS ORDENADO ASCENDENTEMENTE POR CLIENTE.
REPORTE DE PEDIDOS ORDENADO DESCENDENTEMENTE POR COSTO DE PRODUCCIÓN.
*/







