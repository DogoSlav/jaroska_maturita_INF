#include <iostream>

using namespace std;

// celkem zrejme

int mocnina(int zaklad, int exponent){
    if (exponent == 0) return 1;

    return zaklad * mocnina(zaklad, exponent - 1);
}

int faktorial(int n){
    if (n == 0) return 1;

    return n * faktorial(n - 1);
}

int main(){
    double e = 0;
    int x = 2;

    for (int i = 0; i < 11; i++){
        e += mocnina(x, i) / (double)faktorial(i);
    }

    cout << e << endl;

    return 0;
}
