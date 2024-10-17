/* Un alumno desea saber cual será su calificación final en la materia de Programación Básica. Dicha calificación se compone de los siguientes porcentajes:
55% del promedio de sus tres calificaciones parciales.
30% de la calificación del examen final.
15% de la calificación de un trabajo final.
Implementar una función que reciba como parámetros el promedio de los tres parciales, la calificación del examen final,  la calificación del trabajo final y retorne la calificación definitiva de la asignatura, con la cual debe indicar si el estudiante aprobó o reprobó la asignatura, teniendo en cuenta que la nota mínima aprobatoria es 3.0. y que el rango de calificación es esta entre 0 y 5, por lo que se solicita implementar otra función que lea el valor y retorne dicha calificación si es un valor correcto. 
*/

#include <iostream>
using namespace std;

//declaración Y prototipo  de la  función

float calc_def(float prom, float ef, float tf)
{
	return prom*0.55+ef*0.30+tf*0.15;
}


int main()
{
	float p1, p2,p3, prom, ef, tf, def;
	cout<<"Ingrese la califiación del primer parcial: ";
	cin>>p1;
	cout<<"Ingrese la califiación del segundo parcial: ";
	cin>>p2;
	cout<<"Ingrese la califiación del tercer parcial: ";
	cin>>p3;
	cout<<"Ingrese la califiación del examen final: ";
	cin>>ef;
	cout<<"Ingrese lacalifiación del trabajo final: ";
	cin>>tf;
	prom = (p1+p2+p3)/3;
	def = calc_def(prom, ef, tf); //invocar a la funcion
	cout<<"Nota Definitiva: "<<def <<endl;
	if(def>=3.0)
	{
		cout<<"Estudiante aprobó"<<endl;
	}
	else
	{
		cout<<"Estudiante reprobó"<<endl;	
	}
}

