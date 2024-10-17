#include<iostream>
using namespace std;

int main()
{
	int n, *p, *q, *z, aux;
	cout<<"Dimension vector: ";
	cin>>n;
	int v[n];
	p=v;
	for(int x=0; x<n; x++)
	{
		cout<<"Valor para la posicion ["<<x<<"]: ";
		cin>>*p;
		p++;
	}
	//ordenar
	p=v;
	q=&v[n-1];
	do
	{
		z=p+1;
		do
		{
			if(*z<*p)//ascendente
			{
				aux = *p;
				*p = *z;
				*z = aux;
			}
			z++;
		}while(z<=q);
		p++;	
	}while(p<=q-1);
	
	cout<<"Vector Ordenado Ascendentemente"<<endl;
	p=v;
	q=&v[n-1];
	do
	{
		cout<<"["<<*p<<"]";
		p++;
	}while(p<=q);
	cout<<endl;
	
	
}
