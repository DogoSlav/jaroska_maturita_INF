#include <iostream>
#include <cmath>

using namespace std;

double rovnice(double x){
    return pow(x, 5) - 3 * pow(x, 4) - 23 * pow(x, 3) + 51 * x * x + 94 * x - 120;
}

double derivace(double x){
    return 5 * pow(x, 4) - 12 * pow(x, 3) - 23 * 3 * x * x + 51 * 2 * x + 94;
}

int main(){

}
