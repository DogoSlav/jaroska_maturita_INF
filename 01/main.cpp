#include <iostream>

using namespace std;

int getNum(char c){
    return c - '0';
}

char getChar(int i){
    i += '0';
    return i;
}

int main(){
    string cislo1, cislo2, vysledek;

    cin >> cislo1;
    cin >> cislo2;

    // budeme pocitat s tim ze cislo 1 je delsi nez cislo 2
    if (cislo1.length() < cislo2.length()) swap(cislo1, cislo2);


    // otocime cisla tak aby se nam s nimi lepe pocitalo 123 -> 321
    for (int i = 0; i < cislo1.size() / 2; i++){
        swap(cislo1[i], cislo1[cislo1.size() - i - 1]);
    }

    for (int i = 0; i < cislo2.size() / 2; i++){
        swap(cislo2[i], cislo2[cislo2.size() - i - 1]);
    }

    // budeme scitat znak po znaku handler nam bude hlidat jestli si nemame z prechozi operace neco drzet naprklad 8 + 7 bude na poslednim znaku 5 a handler nam bude drzet tu 1
    int handler = 0;

    // v tomto cyklu budeme scitat prave 2 zadane cisla, ale jen do te doby nez nam to kratsi cislo dojde napr 100 + 55, tak cyklus pujde jen 2 krat 
    for (int i = 0; i < cislo2.size(); i++){
        // getNum nam vytvori z charu cislo
        int num = getNum(cislo1[i]) + getNum(cislo2[i]) + handler;

        vysledek += getChar(num % 10); // soucet 2 cisel vymodulime 10 a prevedme na znak

        // vytvorime novy zbytek pro dalsi scitani
        handler = num / 10;
    }


    // pocitame jen s handlerem a tim delsim cislem, cislo 2 nam uz doslo
    for (int i = cislo2.size(); i < cislo1.size(); i++){
        int num = getNum(cislo1[i]) + handler;

        vysledek += getChar(num % 10); 

        handler = num / 10;
    }

    // pripad kdy nam zbyde zbytek napriklad u 1 + 99 
    if (handler){
        vysledek += getChar(handler);
    }

    // vysledny string zase otocime a vypiseme
    for (int i = 0; i < vysledek.size() / 2; i++){
        swap(vysledek[i], vysledek[vysledek.size() - i - 1]);
    }

    cout << vysledek << endl;

    return 0;
}
