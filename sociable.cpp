#include <iostream>

int sumOfProperDivisors(int num, int i = 1, int suma = 0) {
    if (i == num) {
        return suma; 
    }
    if (num % i == 0){
        suma += i;
    }
    return sumOfProperDivisors(num, i + 1, suma);
}

bool isSociable(int n) {
    int curNum = n;
    int nextNum;
    for (int i = 1; i <= 15; ++i) {  // Max. 15 iterations
        nextNum = sumOfProperDivisors(curNum);
        if (nextNum == n) {
            return true;
        }
        curNum = nextNum;
    }
    return false;
}

int main() {
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;
    if (isSociable(n)) {
        std::cout << n << " is a sociable number.\n";
    } else {
        std::cout << n << " is not a sociable number.\n";
    }
    return 0;
}

