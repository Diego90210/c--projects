#include <iostream>
#include <ctype.h>
#include <iomanip>
using namespace std;
int main()
{
    int n, op, i, depen;
    cout<<"Bienvenido a IM&EX S.A."<<endl;
    cout<<"Ingrese el numero de llamadas: ";
    cin>>n;
    string funcionario[n], t_llamada[]={"Local", "Celular", "Internacional"}, ofi[]={"Logistica","Recursos Humanos","Financiera"}; 
    int mat[n][3], completo=0, cont_llama[3]={0,0,0}, sum_min[3]={0,0,0}, llamadas[3], total_llamada[3];
    char con;
    do
    {
        system("cls");
		do
        {
            cout<<"\nCONTROL DE LLAMADAS"<<endl;
            cout<<"1. Registro de llamadas"<<endl;
            cout<<"2. Reportes"<<endl;
            cout<<"3. Estadisticas"<<endl;
            cout<<"4. Salir"<<endl;
            cout<<" Digite la opcion: "; cin>>op;
        }while(op<1 or op>4);

        switch(op)
        {
            case 1: for(i=0; i<n; i++)
                    {
                        system("cls");
						cout<<"\n Nombre del Funcionario: "; fflush(stdin);
						getline(cin,funcionario[i]);

						do
                        {
                            cout<<"\nEscoja la oficina: "<<endl;
                            cout<<" 1. Logistica."<<endl;
                            cout<<" 2. Recursos humanos."<<endl;
                            cout<<" 3. Financiero."<<endl;
                            cout<<" OPCION: "; cin>>mat[i][0];
						}while(mat[i][0]<1 or mat[i][0]>3);
						
						do
                        {
                            cout<<"\nEscoja el tipo de llamada"<<endl;
                            cout<<" 1. Local."<<endl;
                            cout<<" 2. Celular."<<endl;
                            cout<<" 3. Internacional."<<endl;
                            cout<<" OPCION: "; cin>>mat[i][1];
						}while(mat[i][1]<1 or mat[i][1]>3);

                        do
                        {
                            cout<<"\nIngrese la cantidad de minutos: "; cin>>mat[i][2];
						}while(mat[i][2]<0 or mat[i][2]>30);

                        if (mat[i][0] == 1)
                        {
                            cont_llama[0]++;        //Cantidad de llamadas logistica.
                            sum_min[0]+=mat[i][2]; //Cantidad de minutos logistica.
                        }
                        else
                        {
                            if (mat[i][0] == 2)
                            {
                                cont_llama[1]++;        //Cantidad de llamadas celular.
                                sum_min[1]+=mat[i][2]; //Cantidad de minutos celular.
                            }
                            else
                            {
                                cont_llama[2]++;        //Cantidad de llamadas internacional.
                                sum_min[2]+=mat[i][2]; //Cantidad de minutos internacional.
                            }
                        }
				
                    }
                completo=1;
                break;
            
            case 2: if (completo==1)
                    {
                        do
                        {
                            cout<<"\n Consultar: "<<endl;
                            cout<<" A. Consulta por Oficina."<<endl;
                            cout<<" B. Consultas por tipo de llamada."<<endl;
                            cout<<" C. Consultas llamadas por funcionario"<<endl;
                            cout<<" D. Reporte de llamadas."<<endl;
                            cout<<"Opcion: "; cin>>con; con = toupper(con);
                        } while (con!='A' && con!='B' && con!='C' && con!='D');
                        
                        switch (con)
                        {
                            case 'A':
                                system("cls");
								do
                                {
                                    cout<<"\n OFICINA"<<endl;
                                    cout<<" 1. Logistica."<<endl;
                                    cout<<" 2. Recursos humanos."<<endl;
                                    cout<<" 3. Financiero."<<endl;
                                    cout<<"Opcion: ";
                                    cin>>depen;
                                } while (depen<1 or depen>3);
                                
                                cout<<setw(20)<<"Nombre"<<setw(6)<<"Minutos"<<setw(10)<<"T. Llamada"<<endl;
                                switch (depen)
                                {
                                    case 1: 
                                        for (i=0; i<n; i++)
                                        {
                                            if (mat[i][0] == 1)
                                            {
                                                cout<<setw(20)<<funcionario[i]<<setw(6)<<mat[i][1]<<setw(10)<<t_llamada[mat[i][1]]<<endl;
                                            }
                                        }
                                        system("pause");
                                        break;
                                    
                                    case 2:
                                        for (i=0; i<n; i++)
                                        {
                                            if (mat[i][0] == 2)
                                            {
                                                cout<<setw(20)<<funcionario[i]<<setw(6)<<mat[i][1]<<setw(10)<<t_llamada[mat[i][1]]<<endl;
                                            }
                                        }
                                        system("pause");
                                        break;
                                    
                                    case 3:
                                        for (i=0; i<n; i++)
                                        {
                                            if (mat[i][0] == 3)
                                            {
                                                cout<<setw(20)<<funcionario[i]<<setw(6)<<mat[i][1]<<setw(10)<<t_llamada[mat[i][1]]<<endl;
                                            }
                                        }
                                        system("pause");
                                        break;
                                }
                            break;

                            case 'B':
                                
								do
								{
                                    cout<<" 1. Local."<<endl;
								    cout<<" 2. Celular."<<endl;
								    cout<<" 3. Internacional."<<"\n";
									cout<<"Opcion: "; cin>>op;
								}while(op<1 or op>3);

                                
                                cout<<setw(20)<<"Nombre"<<setw(10)<<"Oficina"<<endl;
                                switch (op)
                                {

                                    case 1:
                                    for (i=0; i<n; i++)
									{
										if (mat[i][1] == 1)
										{
											cout<<setw(20)<<funcionario[i]<<setw(10)<<ofi[mat[i][0]]<<endl;
										}	
									}
                                    system("pause");
                                    break;

                                    case 2:
                                    for (i=0; i<n; i++)
									{
										if (mat[i][1] == 2)
										{
											cout<<setw(20)<<funcionario[i]<<setw(10)<<ofi[mat[i][0]]<<endl;
										}	
									}
                                    system("pause");
                                    break;

                                    case 3:
                                    for (i=0; i<n; i++)
									{
										if (mat[i][1] == 3)
										{
											cout<<setw(20)<<funcionario[i]<<setw(10)<<ofi[mat[i][0]]<<endl;
										}	
									}
                                    system("pause");
                                    break;

                                    cout<<setw(30)<<"Logistica"<<setw(20)<<"Recursos humanos"<<setw(15)<<"Financiera"<<endl;
									cout<<"Cant. Llamadas"<<setw(14)<<cont_llama[0]<<setw(15)<<cont_llama[1]<<setw(15)<<cont_llama[2]<<endl;
									cout<<"Cant. Minutos"<<setw(15)<<sum_min[0]<<setw(15)<<sum_min[1]<<setw(15)<<sum_min[2]<<endl;

                                    break;    
                                }
                                break;
                            
                            case 'C':
                            break;

                            case 'D': 
                                for(i=0; i<3; i++)
                                {
                                    llamadas[i]=0;
                                }
                            cout<<setw(25)<<"Oficina"<<setw(20)<<"Funcionario"<<setw(15)<<"T. De llamada"<<setw(10)<<"Minutos"<<endl;
                            for(i=0; i<n; i++)
							{
								cout<<setw(20)<<ofi[(mat[i][0])-1]<<setw(25)<<funcionario[i]<<setw(15)<<t_llamada[(mat[i][1])-1]<<setw(10)<<mat[i][2]<<endl;
							}
                            cout<<"\n Monto a pagar por dependencia: "<<endl;
						    cout<<"\n Logistica: "<<endl;
                            for(i=0; i<n; i++)
							{
								if(mat[i][0]==1)
								{
									switch(mat[i][1])
									{	
										case 1: llamadas[0]+=(mat[i][2]);	
                                        break;
										case 2: llamadas[1]+=(mat[i][2]);	
                                        break;
										case 3: llamadas[2]+=(mat[i][2]);	
                                        break;
									}
								}
							}
                            for(i=0; i<3; i++)
                            {
                                llamadas[i]=0;
                            }
                            total_llamada[0]=(llamadas[0]*80)+(llamadas[1]*800)+(llamadas[2]*1500);

                            cout<<setw(10)<<"Local"<<setw(10)<<"Celular"<<setw(15)<<"Internacional"<<setw(10)<<"Monto a pagar"<<endl;
							cout<<setw(10)<<llamadas[0]<<setw(10)<<llamadas[1]<<setw(15)<<llamadas[2]<<setw(10)<<"$"<<total_llamada[0]<<endl;
							cout<<"\n Recursos humanos: "<<endl;

                            for(i=0; i<3; i++)
                            {
                                llamadas[i]=0;
                            }
							
                            for(i=0; i<n; i++)
							{
								if(mat[i][0]==2)
								{
									switch(mat[i][1])
									{
										case 1: llamadas[0]+=(mat[i][2]);	
                                        break;
										case 2: llamadas[1]+=(mat[i][2]);	
                                        break;
										case 3: llamadas[2]+=(mat[i][2]);	
                                        break;
									}
								}
							}

                            total_llamada[1]=(llamadas[0]*80)+(llamadas[1]*800)+(llamadas[2]*1500);
                            cout<<setw(10)<<"Local"<<setw(10)<<"Celular"<<setw(15)<<"Internacional"<<setw(10)<<"Monto a pagar"<<endl;
							cout<<setw(10)<<llamadas[0]<<setw(10)<<llamadas[1]<<setw(15)<<llamadas[2]<<setw(10)<<"$"<<total_llamada[1]<<endl;
							
                            cout<<"\n Oficina Finanzas: "<<endl;
                            for(i=0; i<3; i++)
                            {
                                llamadas[i]=0;
                            }

                            for(i=0; i<n; i++)
							{
								if(mat[i][0]==3)
								{
									switch(mat[i][1])
									{
										case 1: llamadas[0]+=(mat[i][2]);	
                                        break;
										case 2: llamadas[1]+=(mat[i][2]);	
                                        break;
										case 3: llamadas[2]+=(mat[i][2]);	
                                        break;
									}
								}
							}
                            total_llamada[2]=(llamadas[0]*80)+(llamadas[1]*800)+(llamadas[2]*1500);
                            cout<<setw(10)<<"Local"<<setw(10)<<"Celular"<<setw(15)<<"Internacional"<<setw(10)<<"Monto a pagar"<<endl;
							cout<<setw(10)<<llamadas[0]<<setw(10)<<llamadas[1]<<setw(15)<<llamadas[2]<<setw(10)<<"$"<<total_llamada[2]<<endl;
                        }
                    }
                    else
                    {
                        system("cls");
                        cout<<"Debe completar el registro primero!!!";          
                    }
                    break;
        case 3: break;
        case 4: break;
        }
    } while (op!=4);
    















    return 0;
}