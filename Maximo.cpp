#include <iostream>
using namespace std;


template <class TIPOD>
void maximo(TIPOD v1, TIPOD v2, TIPOD v3);

int main(){
    int num1 = 1;
    int num2 = 2;
    int num3 = 3;

    maximo(num1, num2, num3);


    return 0;
}

template <class TIPOD>
void maximo(TIPOD v1, TIPOD v2, TIPOD v3){
    int maxim;
    if ((v1>v2) && (v1>v3))
    {
        maxim = v1;
    }
    else
    {
        if ((v2>v1) && (v2>v3))
        {
            maxim = v2;
        }
        else
        {
            if ((v3>v1) && (v3>v2))
            {
                maxim = v3;
            }
        }
    }
    cout<<"El valor maximo es: "<<maxim<<endl;
}
