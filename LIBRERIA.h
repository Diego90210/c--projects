#include<iostream>
#include<ctype.h>
using namespace std;

/*
This function returns a true value if the read value
is invalid or it´s out of the limits, if both limits 
are 0, it is assumed that there are no limits
*/
bool validarFloat(float min, float max, float valor);
bool rangeint(int lower, int upper, int &datum);
bool rangelong1(long lower, long upper, long &datum);
bool rangelong(long long lower, long long upper, long long &datum);
bool rangefloat(float lower, float upper, float &datum);
bool rangedouble(double lower, double upper, double &datum);

/*
This function returns a true value if the read value
is invalid, or it is bigger than the limit. if both
are 0, it is assumed that there are no limits
*/
bool upint(int upper, int &datum);
bool uplong(long long upper, long long &datum);
bool upfloat(float upper, float &datum);
bool updouble(double upper, double &datum);

/*
This function returns a true value if the read value 
is invalid or it is smaller than the limit
*/
bool lowint(int lower, int &datum);
bool lowlong(long long lower, long long &datum);
bool lowfloat(float lower, float &datum);
bool lowdouble(double lower, double &datum);

/*
This function organizes an array on a ascendant way 
using the bubble sort method 
*/
void double_bubble(double array[], int size);
void float_bubble(float array[], int size);
void int_bubble(int array[], int size);
void long_bubble(long array[], int size);

/*
This function deletes all the spaces in a chain and 
converts every character in its lower format
*/
int strlength(char chain[]);
void strlower(char chain[]);
void strcopy(char destiniy[], char source[]);
void strformat(char chain[]);



/*********************************************************************************************/
/*
This group of functions validate if the read datum is
within a range o if it is really a number
*/
//||||||||||||||||||||||||||||||||||||
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
bool rangeint(int lower, int upper, int &datum)
{
	setlocale(LC_ALL,"spanish");
	
	cin>>datum;
	if(cin.fail())
	{
		cin.clear();//Se limpia el error
		cin.ignore(10000,'\n');//Se salta los caracteres hasta el enter
		cout<<"Por favor, Ingrese solo números."<<endl;
		return true;
	}
	else//Si hay un rango
	if(lower!=0 || upper!=0)
	{
		if(datum<lower || datum>upper)//Si el dato esta fuera del rango
		{
			cout<<"Ingrese un valor válido."<<endl;
			return true;
		}
	}
	
	return false;
}
/*********************************************************************************************/
bool rangelong(long long lower, long long upper, long long &datum)
{
	setlocale(LC_ALL,"spanish");
	
	cin>>datum;
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(10000,'\n');
		cout<<"Por favor, Ingrese solo números."<<endl;
		return true;
	}
	else
	if(lower!=0 || upper!=0)
	{
		if(datum<lower || datum>upper)
		{
			cout<<"Ingrese un valor válido."<<endl;
			return true;
		}
	}
	
	return false;
}
/**************************************************************************************************/
bool rangelong1(long lower, long upper, long &datum)
{
	setlocale(LC_ALL,"spanish");
	
	cin>>datum;
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(10000,'\n');
		cout<<"Por favor, Ingrese solo números."<<endl;
		return true;
	}
	else
	if(lower!=0 || upper!=0)
	{
		if(datum<lower || datum>upper)
		{
			cout<<"Ingrese un valor válido."<<endl;
			return true;
		}
	}
	
	return false;
}
/*********************************************************************************************/
bool validarFloat(float min, float max, float valor) {
    return valor >= min && valor <= max;
}

bool rangefloat(float lower, float upper, float &datum)
{
		setlocale(LC_ALL,"spanish");
	
	cin>>datum;
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(10000,'\n');
		cout<<"Por favor, Ingrese solo números."<<endl;
		return true;
	}
	else
	if(lower!=0 || upper!=0)
	{
		if(datum<lower || datum>upper)
		{
			cout<<"Ingrese un valor válido."<<endl;
			return true;
		}
	}
	
	return false;
}
/*********************************************************************************************/
bool rangedouble(double lower, double upper, double &datum)
{
	setlocale(LC_ALL,"spanish");
	
	cin>>datum;
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(10000,'\n');
		cout<<"Por favor, Ingrese solo números."<<endl;
		return true;
	}
	else
	if(lower!=0 || upper!=0)
	{
		if(datum<lower || datum>upper)
		{
			cout<<"Por favor, ingrese un valor válido."<<endl;
			return true;
		}
	}
	
	return false;
}
/*********************************************************************************************/
bool upint(int upper, int &datum)
{
	setlocale(LC_ALL, "spanish");
	
	cin>>datum;
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(10000,'\n');
		cout<<"Por favor, ingrese solo números."<<endl;
		return true;
	}
	else
	if(datum>upper)
	{
		cout<<"Por favor, ingrese un valor válido."<<endl;
		return true;
	}
	
	return false;
}
/*********************************************************************************************/
bool uplong(long long upper, long long &datum)
{
	setlocale(LC_ALL, "spanish");
	
	cin>>datum;
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(10000,'\n');
		cout<<"Por favor, ingrese solo números."<<endl;
		return true;
	}
	else
	if(datum>upper)
	{
		cout<<"Por favor, ingrese un valor válido."<<endl;
		return true;
	}
	
	return false;
}
/*********************************************************************************************/
bool upfloat(float upper, float &datum)
{
	setlocale(LC_ALL, "spanish");
	
	cin>>datum;
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(10000,'\n');
		cout<<"Por favor, ingrese solo números."<<endl;
		return true;
	}
	else
	if(datum>upper)
	{
		cout<<"Por favor, ingrese un valor válido."<<endl;
		return true;
	}
	
	return false;
}
/*********************************************************************************************/
bool updouble(double upper, double &datum)
{
	setlocale(LC_ALL, "spanish");
	
	cin>>datum;
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(10000,'\n');
		cout<<"Por favor, ingrese solo números."<<endl;
		return true;
	}
	else
	if(datum>upper)
	{
		cout<<"Por favor, ingrese un valor válido."<<endl;
		return true;
	}
	
	return false;
}
/*********************************************************************************************/
bool lowint(int lower, int &datum)
{
	setlocale(LC_ALL, "spanish");
	
	cin>>datum;
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(10000,'\n');
		cout<<"Por favor, ingrese solo números."<<endl;
		return true;
	}
	else
	if(datum<lower)
	{
		cout<<"Por favor, ingrese un valor válido."<<endl;
		return true;
	}
	
	return false;
}
/*********************************************************************************************/
bool lowlong(long long lower, long long &datum)
{
	setlocale(LC_ALL, "spanish");
	
	cin>>datum;
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(10000,'\n');
		cout<<"Por favor, ingrese solo números."<<endl;
		return true;
	}
	else
	if(datum<lower)
	{
		cout<<"Por favor, ingrese un valor válido."<<endl;
		return true;
	}
	
	return false;
}

bool lowfloat(float lower, float &datum)
{
	setlocale(LC_ALL, "spanish");
	
	cin>>datum;
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(10000,'\n');
		cout<<"Por favor, ingrese solo números."<<endl;
		return true;
	}
	else
	if(datum<lower)
	{
		cout<<"Por favor, ingrese un valor válido."<<endl;
		return true;
	}
	
	return false;
}
/*********************************************************************************************/
bool lowdouble(double lower, double &datum)
{
	setlocale(LC_ALL, "spanish");
	
	cin>>datum;
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(10000,'\n');
		cout<<"Por favor, ingrese solo números."<<endl;
		return true;
	}
	else
	if(datum<lower)
	{
		cout<<"Por favor, ingrese un valor válido."<<endl;
		return true;
	}
	
	return false;
}
/*
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
||||||||||||||||||||||||||||||||||||||||||||||||||
*/
/*********************************************************************************************/

//||||||||||||||||||||||||||||||||||||
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

/*This group of functions is for the strings
handle
*/

/*
This function converts a caracter chain in a one format,
deleting the spaces and going to lower
*/

int strlength(char chain[])
{
	int length=0;
	
	while(chain[length]!='\0')
		length++;
		
	return length;
}
/*********************************************************************************************/
void strlower(char chain[])
{
	for(int i=0; chain[i]!='\0'; i++)
	{
		if(chain[i]>=65 && chain[i]<=90)
		{
			chain[i]+=32;
		}
	}
}
/*********************************************************************************************/
void strcopy(char destiny[], char source[])
{
	int i;
	for(i=0; source[i]!='\0'; i++)
	{
		destiny[i]= source[i];
	}
	
	destiny[i]='\0';
}
/*********************************************************************************************/
void strformat(char chain[])
{
	setlocale(LC_ALL,"spanish");
	int length= strlength(chain);
	
	if(length == 0)
	{
		return;
	}
	
	
	char new_chain[length];
	int fill;
	
	
	fill=0;
	for(int position=0; chain[position]!='\0'; position++)
	{
		if((chain[position]>=65 && chain[position]<=90) || (chain[position]>=97 && chain[position]<=122))
		{
			new_chain[fill]=chain[position];
			fill++;
		}
	}
	
	new_chain[fill]='\0';
	
	strlower(new_chain);
	strcopy(chain,new_chain);
}
/*********************************************************************************************/
/*
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
||||||||||||||||||||||||||||||||||||||||||||||||||
*/

/*
This group of functions are worthly to array handle
*/
//||||||||||||||||||||||||||||||||||||
// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

//This functions organizes a numeric array in ascendant way
void double_bubble(double array[], int size)
{
	double aux;
	
	for(int position=1; position<size; position++)
	{
		for(int current=0; current<size-position; current++)
		{
			if(array[current]>array[current+1])
			{
				aux=array[current];
				array[current]=array[current+1];
				array[current+1]=aux;
			}
		}
	}
}
/*********************************************************************************************/
void float_bubble(float array[], int size)
{
	float aux;
	
	for(int position=1; position<size; position++)
	{
		for(int current=0; current<size-position; current++)
		{
			if(array[current]>array[current+1])
			{
				aux=array[current];
				array[current]=array[current+1];
				array[current+1]=aux;
			}
		}
	}
}
/*********************************************************************************************/
void long_bubble(long array[], int size)
{
	long aux;
	
	for(int position=1; position<size; position++)
	{
		for(int current=0; current<size-position; current++)
		{
			if(array[current]>array[current+1])
			{
				aux=array[current];
				array[current]=array[current+1];
				array[current+1]=aux;
			}
		}
	}
}
/*********************************************************************************************/
void int_bubble(int array[], int size)
{
	int aux;
	
	for(int position=1; position<size; position++)
	{
		for(int current=0; current<size-position; current++)
		{
			if(array[current]>array[current+1])
			{
				aux=array[current];
				array[current]=array[current+1];
				array[current+1]=aux;
			}
		}
	}
}
/*********************************************************************************************/
/*
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
||||||||||||||||||||||||||||||||||||||||||||||||||

*/
