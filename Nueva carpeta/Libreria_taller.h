//Diego Andrés Martínez Florez: 0222120002.
//Roberto Junior Martínez Paternina: 0222120018.
//José David Torres Acevedo: 0222120038.

#include <iostream>
#include <math.h>
using namespace std;

int decimal_binario(int num){
    if (num == 0){
        return 0;
    }
	else{
        return (num % 2 + 10 * decimal_binario(num/2));
    }
}

int binario_decimal(int num) {
    if (num==0){
        return 0;
    } 
	else{
        return (num%10) + 2 * binario_decimal(num / 10); 
    }
}

int suma_divisores(int num, int i) {
    if (i>num){
        return 0;
    }
    if (num%i == 0){
        return i + suma_divisores(num, i + 1);
    }
    return suma_divisores(num, i + 1);
}

int suma_divisores_propios(int num, int i = 1, int suma = 0) {
    if (i == num) {
        return suma; 
    }
    if (num % i == 0){
        suma += i;
    }
    return suma_divisores_propios(num, i + 1, suma);
}

int suma_digitos(int num) {
    if (num<10) {
        return num;
    }
    else{
        return num % 10 + suma_digitos(num/10);
    }
}

long potencia (int base, int exponente){
    if (exponente==0){
        return 1;
    }
    else{
        return base * potencia(base, exponente-1);
    }
}

bool malvado(int num){
    int binario, contar_unos=0;
    binario = decimal_binario(num);

    while (binario>0){
        if (binario%2 == 1){
            contar_unos++;
        }
        binario/=10;
    }

    if (contar_unos%2 == 0){
        return true;
    }
    else{
        return false;
    }
}

bool odioso (int num){
    int binario, contar_unos=0;
    binario = decimal_binario(num);

    while (binario>0){
        if (binario%2 == 1){
            contar_unos++;
        }
        binario/=10;
    }

    if (contar_unos%2 == 1){
        return true;
    }
    else{
        return false;
    }
}

bool perfecto (int num){
    if ((suma_divisores_propios (num)) == num){
        return true;
    }
    else{
        return false;
    }
}

bool ambicioso (int num){ //Se puede optimizar.
    int divi1, divi2, divi3;

    divi1 = suma_divisores_propios(num);
    divi2 = suma_divisores_propios(divi1);
    divi3 = suma_divisores_propios (divi2);

    if (perfecto (divi3)){
        return true;
    }
    else{
        return false;
    }
}

bool curioso (int num){ //se puede optimizar.
    int potencia, ultimo_digito_cuadrado;
    potencia = pow (num,2);
    ultimo_digito_cuadrado = pow ((potencia%10), 2);

    if (ultimo_digito_cuadrado == num){
        return true;
    }
    else{
        return false;
    }
}

int suma_digitos_cuadrado (int num){
    int sum=0, digito;
    while (num>0){
        digito = num%10;
        sum+=digito*digito;
        num/=10;
    }
    return sum;
}

bool feliz (int num){
    if (num == 1){
        return true;
    }
    else{
        if (num == 4){
            return false;
        }
        else{
            return feliz (suma_digitos_cuadrado(num));
        }
    }
}

bool semi_perfecto (int num){
    int sum, j;
    for (int i=1; i<=(num/2); i++){
        sum = i;
        j = i+1;
        while ((sum<num) && (j<=(num/2))){
            sum+=j;
            j++;
        }
        if (sum == num){
            return true;
        }
    }
    return false;
}

int cant_digitos(int a){
    int contador=0;
    do{
        a%10;
        contador++;
        a/=10;
    }while(a>0);
    return contador;
}

bool poderoso(int num){

    int x,y,suma=0,digito=0;
    y=num; x=num;

    digito = cant_digitos (num);

    for(int exp=digito; exp>0; exp--){
        y=x%10; 
        x/=10; 
        if(exp>0){
            suma=suma+pow(y,exp);
        }   
    }

    if(num==suma){
        return true; 
    }
    else{
        return false;
    }
}

bool narcisista(int num){
    long sumatoria=0;
    int a=num;
    int exp = cant_digitos(a);
    int digito;

    do{
        digito=a%10;
        sumatoria += potencia (digito, exp);
        a/=10;
    }while(a>0);

    if (num == sumatoria){
        return true;
    }
    else{
        return false;
    }
}

bool primo_gemelos (int x, int y){
    bool p1 = true, p2 = true;
    int divisor;
	for(divisor=2; divisor<=(x/2); divisor++){
		if((x%divisor)==0){
			p1=false; 
            break;
		}
	}
	for(divisor=2; divisor<=(y/2); divisor++){
		if((y%divisor)==0){
		    p2=false; 
            break;
		}
	}
	if(p2 && p1){
		if((y==(x+2)) || (x==(y+2))){
            return true;
        }
        else{
            return false;
        }
	}

    return false;
}

bool primos_primos (int x, int y){
    bool p1=true, p2 = true;
    int divisor;
	for(divisor=2; divisor<=x/2; divisor++){
		if(x%divisor==0){
			p1=false; break;
		}
	}
	for(divisor=2; divisor<=y/2; divisor++){
		if(y%divisor==0){
			p2=false; break;
		}
	}
	if(p2 && p1){
		if(y==x+4 || x==y+4){
            return true;
        }
        else{
            return false;
        }
	}

    return false;
}

bool primos_sexys (int x, int y){
    bool p1=true, p2=true;
    int divisor;
	for(divisor=2; divisor<=x/2; divisor++){
		if(x%divisor==0){
			p1=false; break;
		}
	}
	for(divisor=2; divisor<=y/2; divisor++){
		if(y%divisor==0){
			p2=false; break;
		}
	}
	if(p2 && p1){
		if(y==x+6 || x==y+6){
            return true;
        }
        else{
            return false;
        }
	}
	else{	
        return false;
    }
}

bool coprimos (int x, int y)
{
    bool p1=true;
    for(int divisor=2; divisor<=x/2; divisor++){
        if(x%divisor==0){
            for(int diva=2; diva<=y/2; diva++){
                if(y%diva==0 && divisor==diva){ 
                    p1=false;
                }
            }
        }
    }
    return p1;
}

bool amigos (int x, int y)
{
    int suma1=1, suma2=1;
    for(int divisor=2; divisor<=x/2; divisor++){
        if(x%divisor==0){
            suma1+=divisor;
        }
    }
    for(int divisor=2; divisor<=y/2; divisor++){
        if(y%divisor==0){
            suma2+=divisor;
        }
    }
    if(suma2==x && suma1==y){
        return true;
    }
    else{
        return false;
    }
}

bool novios (int x, int y)
{
    int suma1=1, suma2=1, suma3=1+x+y;
    bool p1;
    for(int divisor=2; divisor<=x; divisor++){
        if(x%divisor==0){
              suma1+=divisor;
        }
    }
    for(int divisor=2; divisor<=y; divisor++){
        if(y%divisor==0){
            suma2+=divisor;
        }
    }
    if(suma1==suma2 && suma2==suma3){
        return true;
    }
    return false;
}

int sum_divisores_propios(int n) {
    int suma = 0;
    for (int i = 1; i <= n/2; ++i) {
        if (n % i == 0) {
            suma += i;
        }
    }
    return suma;
}

bool sociables (int x)
{   int y = x;
    int suma1;
    for (int i = 1; i <= 15; ++i) {  
        suma1 = sum_divisores_propios(y); //Debido a que la función suma_divisores_propios (versión recursiva)
        if (suma1 == x) {                 //es llamada multiples veces la memoria se desborda.
            return true;                  //Por lo que no fue optimo utilizarla en éste caso.
        }                                 //Como consecuencia, se tuvo que recurrir a una función que cumple el     
        y = suma1;                        //Mismo objetivo, pero, sin ser recursiva. Pedimos comprensión en la situación.
    }                                     //Posdata: La versión recursiva de la función si fue utilizada en el resto del programa.
    return false;
}
