#include <iostream>
using namespace std;

int sumOfSquaresOfDigits(int n) {
    int sum = 0;
    while(n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    if(n == 1) {
        return true;
    } else if(n == 4) {
        return false;
    } else {
        return isHappy(sumOfSquaresOfDigits(n));
    }
}

int main (){
	int n;
	cout<<"Ingrese un numero: ";
	cin>>n;
	
	if (isHappy(n)){
		cout<<"Es un numero feliz"<<endl;
	}
	else{
		cout<<"No es un numero feliz"<<endl;
	}
}
