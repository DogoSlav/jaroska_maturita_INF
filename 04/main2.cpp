#include <iostream>

using namespace std;

// nejvetsi spolecny delitel cisel a,b
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


int main(){
    int N;
    int pole[10];
    int nejvetsi_spolecny_delitel;


    // nacitame vstup
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> pole[i];
    }

    // prvni NSD se spocita v okrajovem pripade
    nejvetsi_spolecny_delitel = gcd(pole[0], pole[1]);

    // zbytek NSD se pocita v cyklu
    for (int i = 2; i < N; i++){
        nejvetsi_spolecny_delitel = gcd(nejvetsi_spolecny_delitel, pole[i]);
    }

    cout << nejvetsi_spolecny_delitel << endl;

    return 0;
}
