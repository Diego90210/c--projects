#include <iostream>
using namespace std;

bool primos(int x, int y, int abc)
{	
	bool p2,p1;
	switch(abc) 
	{			//Primos Gemelos
	 	case 1 :	p1=true;
		 			for(int divisor=2; divisor<=x/2; divisor++) 
						{
							if(x%divisor==0) 
							{
							  p1=false; break;
							}
						}
		 			
		 			p2=true;
		 			for(int divisor=2; divisor<=y/2; divisor++) 
						{
							if(y%divisor==0) 
							{
							  p2=false; break;
							}
						}
		 			if(p2 && p1)
		 			{
		 				if(y==x+2 || x==y+2)
		 				{return true;}
					}
					else{	return false;}
		 			
		 			break;
		 		//Primos Primos
	 	case 2 :  p1=true;
		 			for(int divisor=2; divisor<=x/2; divisor++) 
						{
							if(x%divisor==0) 
							{
							  p1=false; break;
							}
						}
		 			
		 			p2=true;
		 			for(int divisor=2; divisor<=y/2; divisor++) 
						{
							if(y%divisor==0) 
							{
							  p2=false; break;
							}
						}
	 			if(p2 && p1)
		 			{
		 				if(y==x+4 || x==y+4)
		 				{return true;}
					}
					else{	return false;}
		 			
		 			break;
		 			
		 			//Primos Sexys
		case 3 :  p1=true;
	 			for(int divisor=2; divisor<=x/2; divisor++) 
						{
						if(x%divisor==0) 
							{
							  p1=false; break;
							}
						}
				 			
		 			p2=true;
		 			for(int divisor=2; divisor<=y/2; divisor++) 
						{
							if(y%divisor==0) 
							{
							  p2=false; break;
							}
						}
		 			if(p2 && p1)
		 			{
		 				if(y==x+6 || x==y+6)
		 				{return true;}
					}
					else{	return false;}
					 			
		 			break;
						 
		}
}



int main(){
	int n, m;
	cout<<"Ingrese un numero: ";
	cin>>n;
	
	cout<<"Ingrese otro numero: ";
	cin>>m;
}
