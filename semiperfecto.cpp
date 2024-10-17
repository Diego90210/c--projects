#include <iostream>
using namespace std;


bool isSemiperfect(int n) {
    for (int i = 1; i <= n/2; i++) {
        int sum = i;
        int j = i + 1;
        while (sum < n && j <= n/2) {
            sum += j;
            j++;
        }
        if (sum == n) {
            return true;
        }
    }
    return false;
}

int main (){
	int num;
	cout<<"Ingrese un número: ";
	cin>>num;
	
	if (isSemiperfect(num)){
        cout<<"El número "<<num<<" es un semi perfecto"<<endl;
    }
    else{
        cout<<"El número "<<num<<" no es un semi perfecto"<<endl;
    }
}
