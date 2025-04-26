#include <iostream>

using namespace std;

// unsigned char je typ promenne kde se uklada jednobajtove cislo <0;255> POZOR chape se opravdu jako char, pri vyposovani to muze delat problem

void prevod10do2(unsigned char vstup, char *vystup){

    // index je 7 coz je posledni index pole vystup, binarni cislo budeme zapisovat od konce
    int index = 7;
    while (vstup != 0){

        // modulo 2, pokud je 1 tak na binarnim cisle bude 1 jinak 0
        if (vstup % 2 == 1){
            vystup[index] = '1';
        }
        else{
            vystup[index] = '0';
        }

        // delime a posunujeme index
        vstup /= 2;
        index--;
    }
}

void prevod2do10(char *vstup, unsigned char *vystup){
    // pozor vystup je v tomto pripade pointer
    int exponent = 1;
    int out = 0;
    // zaciname zase od konce
    for (int index = 7; index >= 0; index--){
        if (vstup[index] == '1'){
            out += exponent;
        }
        exponent *= 2;
    }

    // pozor at neulozime nas vystup jako pointer
    *vystup = out;
}

// testovaci funkce
void vypisBinarniCislo(char* cislo){
    for (int i = 0; i < 8; i++){
        cout << cislo[i];
    }
    cout << endl;
}

int main(){
    char binarni_cislo[8];
    unsigned char cislo = 230;

    prevod10do2(cislo, binarni_cislo);
    vypisBinarniCislo(binarni_cislo);
    
    // cislo posilame jako adresu
    prevod2do10(binarni_cislo, &cislo);

    // pretypujeme char
    cout << (int)cislo << endl;

    return 0;
}
