#include <iostream>
#include <cmath>

using namespace std;

double f(double x){
    return pow(x, 5) - 3 * pow(x, 4) - 23 * pow(x, 3) + 51 * x * x + 94 * x - 120;
}

bool jeTamKoren(double a, double b){
    return a * b < 0;
}

double puleni(double a, double b, double presnost = 0.01){
    if (f(b) == 0) return b;
    if (f(a) == 0) return a;

    while (abs(a - b) > presnost){
        double mid = (a + b) / 2.00;

        if (f(mid) == 0) return mid;

        if (jeTamKoren(f(mid), f(b))){
            a = mid;
        }
        else{
            b = mid;
        }
    }

    return (a + b) / 2.00;
}

void separace(int start, int end, double posun = 0.21){
    for (double i = start; i + posun < end; i += posun){
        if (jeTamKoren(f(i), f(i + posun))){
            double out = puleni(i, i + posun);
            cout << out << "   ";
            cout << f(out) << endl;
            
        }
    }
}

int main(){
    separace(-1000, 1000);
}
