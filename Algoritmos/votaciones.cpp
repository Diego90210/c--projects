/*Desarrollar una aplicación que permita registrar la cantidad de votos de una elección presidencial ficticia desarrollada en Colombia, en la que participan 4 partidos políticos. 
El conteo de votos debe limitarse a solamente los 7 municipios (Bogotá, Zipaquirá, Soacha, Girardot, Fusagasugá, Facatativá y Chía) más representativos que conforman el departamento 
de Cundinamarca. Finalmente, muestre a la autoridad electoral los siguientes resultados específicos:
a) Cantidad acumulada de votos que obtuvo cada partido entre los siguientes municipios: Bogota, Zipaquirá y Soacha.
b) Cantidad y porcentaje de votos que obtuvo cada partido en todo el departamento de Cundinamarca.
c) Determine el partido que gano en todo el departamento; o sino, debe indicar que hubo un empate y aclarar entre cuales de los partidos políticos se generó. Recordar que un empate
electoral puede darse entre 2 o más partidos del proceso electoral.*/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	setlocale(LC_ALL, "spanish");
	string municipio[]= {"Bogotá","Zipaquirá","Soacha","Girardot","Fusagasugá","Facatativá","Chía"};
	string partido[4];
	int votos[4][7];
	long total_partido[4];
	int p, m, empate=0;
	long total_votos=0, total=0, max=0;
	
	//cargar los arreglos
	for(p=0; p<4; p++) //referencia a la fila ==>partido
	{
		cout<<"Nombre del partido #"<<p+1 <<" : ";
		fflush(stdin); getline(cin, partido[p]);
		
		cout<<"Votaciones por municipio " <<endl;
		for(m=0; m<7; m++)//columna ==> municipio
		{
			cout<<"Votos en "<<municipio[m] <<": ";
			cin>>votos[p][m];
			total = total + votos[p][m]; //acumulando el total de votos del municipio de cundinamarca
		}
	}
	system("cls");
	cout<<"VOTACIONES DE PARTIDO POR MUNICIPIO" <<endl;
	for(p=0; p<4; p++)
	{
		for(m=0; m<7; m++)
		{
			cout<<"["<<votos[p][m]<<"]"; 	
		}
		cout<<endl;
	}
	
	//a) Cantidad acumulada de votos que obtuvo cada partido entre los siguientes municipios: Bogota, Zipaquirá y Soacha.
	for(p=0; p<4; p++)
	{
		total_votos = votos[p][0] + votos[p][1] + votos[p][2];
		cout<<"Cantidad acumulada de votos que obtuvo el  partido " <<partido[p] <<"  en los municipios: Bogota, Zipaquirá y Soacha ==> " <<total_votos <<endl;
	}
	
	//b) Cantidad y porcentaje de votos que obtuvo cada partido en todo el departamento de Cundinamarca.
	for(p=0; p<4; p++)
	{
		total_partido[p]= 0;
		for(m=0; m<7; m++)
		{
			total_partido[p] = total_partido[p] + votos[p][m];	//acumulando los votos totales del partido
		}
		cout<<"Total votos del partido " <<partido[p] <<" =	" <<total_partido[p] <<" equivalente al " <<total_partido[p]*100/total <<"%\n";
		if(total_partido[p] > max)
		{
			max = total_partido[p] ;
		}
	}	
	
	//Determine el partido que gano en todo el departamento; o sino, debe indicar que hubo un empate
	for(p=0; p<4; p++)
	{
		if(total_partido[p] == max)
		{
			cout<<"Ganador Partido " <<partido[p] <<" Con " <<total_partido[p] <<" votos " <<endl;
			empate++;
		}
	}
	if(empate>=2)
	{
		cout<<"Empate entre los "<<empate <<" partidos anteriores " <<endl;
	}
}



