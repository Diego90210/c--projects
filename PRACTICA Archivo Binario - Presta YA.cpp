#include<iostream>
#include<fstream>
#include <string.h>
#include <iomanip>
using namespace std;

/****************************************************************************/
//para asignar la fecha y hora del sistema 
time_t tiempo = time(0); // recibirá como parámetro un puntero nulo (es decir, NULL o 0) y devolverá el tiempo actual en una variable de tipo "time_t".
struct tm *tlocal = localtime(&tiempo); // devuelve un puntero hacia una estructura de tipo tm, que es la que utilizaremos en strftime.  
/***************************************************************************/
struct infoC
{
      long id;
      char nombre[80];
      long telefono;       
}cliente;

struct infoP
{
       long id_cliente;
       long num_prest;
       long valor_p;
       char fecha_hora[128];
       float ti;
}prestamo;

struct infoA
{
    long id_cliente;
    long num_prest;
    long valor_a;
    long saldo;
    char fecha_hora[128]; 
}abono;
//============================================================================================
int menu()
{
    int op;
    do{
       system("cls");
       cout<<"Presta YA" <<endl;
       cout<<"1. Registro de cliente" <<endl;
       cout<<"2. Registro Movimiento" <<endl;
       cout<<"3. Consulta" <<endl;
       cout<<"4. Salir" <<endl;
       cout<<"Accion a realizar: "; cin>>op;
    }while(op <1 || op >4);
    return op;      
}
/*****************************************************************/
void reg_cliente()
{ 
  
}
 //------------------------------------------------
void reg_cred()
{
 
}
// -----------------------------------------------------------------------------
void reg_abono()
{
   
}
//------------------------------------------------------ 
void cons1()
{
  
}
//***********************************************************************************************************************
void cons2()
{
	
}
//=============================================================================================================
int main(){
   for(;;){
       int opc, op;
       op = menu();
       switch(op)
       {
           case 1: reg_cliente(); break;
           
           case 2: 
               do{
 				  system("cls");
				  cout<<"REGISTRAR MOVIMIENTO " <<endl;	              	
                  cout<<"1. Registrar credito" <<endl;
                  cout<<"2. Registrar abono" <<endl;
                  cout<<"3. Salir" <<endl;
                  cout<<"Seleccione movimiento: "; cin>>opc;
               }while(opc<1 ||  opc >3);    
               switch(opc)
               {
                 case 1: reg_cred(); break;
                 case 2: reg_abono(); break;
               }
               break;
           	case 3:   
               do{
                  system("cls");
				  cout<<"CONSULTAR CREDITOS" <<endl;
				  cout<<"1. Un cliente" <<endl;
                  cout<<"2. Todos los clientes" <<endl;
                  cout<<"3. Salir" <<endl;
                  cout<<"Seleccione Tipo de Consulta: "; cin>>opc;
               }while(opc<1 ||  opc >3);    
               switch(opc)
               {
                 case 1: 
				 	cons1();
                 case 2: 
				 	cons2(); 
               }
               system("pause");
               break;   
           	case 4:  exit(0);  
        }//switch           
    } //for
       
}//main
