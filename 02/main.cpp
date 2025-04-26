#include <iostream>

using namespace std;

/*
    char je reprezentovan je reprezentovan jako cislo podle ASCII znaku, muzeme s nim pracovat jako s cisly

    napr.

    char znak = 65;

    cout << znak; 

    /////// output ////// ascii znak 65 je 'A'
    A
*/

string dekoduj(const string &text, const string &klic){

    // fuknce funguje obdobne jak zakoduj(), ale misto pricitani posunu ho odecitame
    int delka_textu = text.size();
    int delka_klice = klic.size();

    // ASCCI kod 'A' je 65, kdyz ho tedy odecteme dostaneme cisla 0-25 podle znaku v abecede
    int posun_na_nulu = 65; // muze byt taky posun_na_nulu = 'A';

    string desifrovany_text;

    for (int i = 0; i < text.size(); i++){
        // ziskavame cislo 0-25 podle toho kolaty je to znak v abecede
        int cislo_znaku_v_abecede = text[i] - posun_na_nulu;

        // ziskame o kolik se ma aktualni znak posunout 
        int posun = klic[i % delka_klice] - posun_na_nulu + 1; // vezmeme znak z klice odecteme 65 -> cislo 0-25 -> pricteme 1 -> cisla 1-26 to je o kolik se ma posunout

        // odecitame posun do naseho znaku
        cislo_znaku_v_abecede -= posun;

        // pokud nas posun pujde do zaporneho cisla napriklad 0 je A a posun doleva 1, tak vysledek musi byt 25 - tedy Z
        if (cislo_znaku_v_abecede < 0){
            cislo_znaku_v_abecede = 26 - cislo_znaku_v_abecede;
        }

        // vracime cislo do formatu velkych pismen
        desifrovany_text += cislo_znaku_v_abecede + posun_na_nulu;
    }

    return desifrovany_text;

}

string zakoduj(const string &text, const string &klic){
    int delka_textu = text.size();
    int delka_klice = klic.size();

    // ASCCI kod 'A' je 65, kdyz ho tedy odecteme dostaneme cisla 0-25 podle znaku v abecede
    int posun_na_nulu = 65; // muze byt taky posun_na_nulu = 'A';

    string sifrovany_text;

    // pro kazdy znak v textu
    for (int i = 0; i < delka_textu; i++){
        // ziskavame cislo 0-25 podle toho kolaty je to znak v abecede
        int cislo_znaku_v_abecede = text[i] - posun_na_nulu;

        // ziskame o kolik se ma aktualni znak posunout 
        int posun = klic[i % delka_klice] - posun_na_nulu + 1; // vezmeme znak z klice odecteme 65 -> cislo 0-25 -> pricteme 1 -> cisla 1-26 to je o kolik se ma posunout

        // pricitame posun do naseho znaku
        cislo_znaku_v_abecede += posun;

        // pro pripad kdychom meli naprklad znak Z posunout o 2, tak dostaneme 25 + 2, coz je 27 mimo abecedu, musime tedy dat modulo coz bude 1 a to bude druhy znak abecedy
        cislo_znaku_v_abecede %= 26;

        // nakonec pridame znak do vysledku a vracime cislo do formatu velkych pismen
        sifrovany_text += cislo_znaku_v_abecede + posun_na_nulu;
    }

    return sifrovany_text;
}

int main(){
    string text, klic, output;

    cin >> text >> klic;
    cout << zakoduj(text, klic) << endl;
    cout << dekoduj(zakoduj(text, klic), klic) << endl;

    return 0;
}
