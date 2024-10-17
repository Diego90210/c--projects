#include <iostream>
#include <cmath>

using namespace std;

int decimalToBinary(int decimal) {
    if (decimal == 0) {
        return 0;
    }

    int binary = 0;
    int power = 0;
    while (decimal > 0) {
        int remainder = decimal % 2;
        binary += remainder * pow(10, power);
        decimal /= 2;
        power++;
    }

    return binary;
}

int main() {
    int decimal = 10;
    int binary = decimalToBinary(decimal);
    cout << decimal << " en binario es " << binary << endl;
    return 0;
}

