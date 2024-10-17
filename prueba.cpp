#include <iostream>
#include <math.h>
using namespace std;

int x=100;

int funcion2 (int a, int b, int c){
	x = (b+x)%a;
	return x;
}

int funcion3 (int x, int y, int &z){
	static int a=5;
	z++;
	x = funcion2(a, y, z);
	a+=(a*z)%y+x;
	return a;
}

int main(){
	int a=5, b=3, c=0;
	for(int x=1; x<=3; x++){
		c = funcion3(x, a, b);
	}
	x = x + pow(c,2);
	c = x%7;
	cout<<"a = "<<a;
	cout<<"\n b = "<<b;
	cout<<"\n c = "<<c;
	cout<<"\n x = "<<x;
	
}
