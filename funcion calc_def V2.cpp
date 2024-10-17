/* Un alumno desea saber cual ser� su calificaci�n final en la materia de Programaci�n B�sica. Dicha calificaci�n se compone de los siguientes porcentajes:
55% del promedio de sus tres calificaciones parciales.
30% de la calificaci�n del examen final.
15% de la calificaci�n de un trabajo final.
Implementar una funci�n que reciba como par�metros el promedio de los tres parciales, la calificaci�n del examen final,  la calificaci�n del trabajo final y retorne la calificaci�n definitiva de la asignatura, con la cual debe indicar si el estudiante aprob� o reprob� la asignatura, teniendo en cuenta que la nota m�nima aprobatoria es 3.0. y que el rango de calificaci�n es esta entre 0 y 5, por lo que se solicita implementar otra funci�n que lea el valor y retorne dicha calificaci�n si es un valor correcto. 
*/

#include <iostream>
using namespace std;

//declaraci�n Y prototipo  de la  funci�n

float calc_def(float prom, float ef, float tf)
{
	return prom*0.55+ef*0.30+tf*0.15;
}


int main()
{
	float p1, p2,p3, prom, ef, tf, def;
	cout<<"Ingrese la califiaci�n del primer parcial: ";
	cin>>p1;
	cout<<"Ingrese la califiaci�n del segundo parcial: ";
	cin>>p2;
	cout<<"Ingrese la califiaci�n del tercer parcial: ";
	cin>>p3;
	cout<<"Ingrese la califiaci�n del examen final: ";
	cin>>ef;
	cout<<"Ingrese lacalifiaci�n del trabajo final: ";
	cin>>tf;
	prom = (p1+p2+p3)/3;
	def = calc_def(prom, ef, tf); //invocar a la funcion
	cout<<"Nota Definitiva: "<<def <<endl;
	if(def>=3.0)
	{
		cout<<"Estudiante aprob�"<<endl;
	}
	else
	{
		cout<<"Estudiante reprob�"<<endl;	
	}
}

