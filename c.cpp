#include <iostream>
using namespace std;

bool isCurious(int n){
    int square = n * n;
    while(square > n){
        square /= 10;
    }
    return square == n;
}

int main(){
    int num;
    cout << "Ingrese un numero natural: ";
    cin >> num;
    if(isCurious(num)){
        cout << num << " es un numero curioso." << endl;
    } else {
        cout << num << " no es un numero curioso." << endl;
    }
    return 0;
}

