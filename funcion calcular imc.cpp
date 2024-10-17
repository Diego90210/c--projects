/*El índice de masa corporal es un índice calculado con base al peso y a la altura de nuestro cuerpo. Se interpreta teniendo en cuenta los rangos de la siguiente tabla:
Menos de 18.5 = Bajo peso
Entre 18.5 y 24.9 = Peso normal
Entre 25 y 29.9 = sobrepeso
De 30 en adelante = obesidad
Para calcular el índice de masa corporal se aplica la siguiente fórmula:
IMC = Peso (Kg) / Altura (Mt)^2

Desarrollar un programa que implemente una función que reciba como parámetro el peso y la altura y retorne el IMC.  
En la función para calcular el IMC se debe calcular la potencia del cuadrado de la altura mediante una función, que reciba como parámetros la altura y el exponente (cuadrado) y retorne la potencia de la altura  
*/
#include <iostream>
using namespace std;

float potencia(float b, float e);
float calcular_imc(float p, float a);

int main()
{
	int salida;
	float p, a, imc;
	do
	{
		cout<<"Peso [Kg]: "; cin>>p;
		cout<<"Altura [mt]: "; cin>>a;
		imc = calcular_imc(p,a);
		cout<<"Indice de Masa Corporal: "<<imc <<" Estado: ";
		if(imc<18.5)//Menos de 18.5 = Bajo peso
		{ cout<<"Bajo peso"<<endl;	}
		else if(imc<25)//Entre 18.5 y 24.9 = Peso normal
		{ cout<<"Peso Normal"<<endl; }
		else if(imc <30)//Entre 25 y 29.9 = sobrepeso
		{ cout<<"SobrePeso"<<endl;	}
		else //De 30 en adelante = obesidad	
		{ cout<<"Obesidad"<<endl; }
		cout<<"Desea Calcular el IMC de otra persona [1]SI cualquier otro valor NO: ";
		cin>>salida;
	}while(salida == 1);	
}

/**************************************/
float potencia(float b, float e)
{
	float p=1;
	for(int x=1; x<=e; x++)
	{ p = p*b; }; //p*=b;
	return p;	
}
float calcular_imc(float p, float a)
{
	return p/potencia(a,2);
}
