#include <iostream>
#include <fstream>

using namespace std;

struct Clovek{
    char jmeno[30], prijmeni[30];
    char rodneCislo[11];
};

void vytvorBinarniSoubor(string &nazev){
    ofstream OUT(nazev, ios::binary);
    OUT.close();
}

// data jsou jako reference ten & tam muze byt a nemusi
void zapisNaKonec(const string &cesta_k_souboru, Clovek &data){
    // out - zapis, binary - binarni soubor, app - pridani na konec
    ofstream OUT(cesta_k_souboru, ios::out | ios::binary | ios::app);

    // toto pretypovani bohuzel musi byt
    OUT.write((char *)&data, sizeof(data));
    
    OUT.close();
}

void vytvorUzivatele(const string &cesta_k_souboru){
    Clovek data;
    cout << "Jmeno: ";
    cin >> data.jmeno;
    cout << "Prijimeni: ";
    cin >> data.prijmeni;
    cout << "rodne cislo: ";
    cin >> data.rodneCislo;

    zapisNaKonec(cesta_k_souboru, data);
}

void vypisZeSouboru(const string &cesta_k_souboru){
    ifstream FILE(cesta_k_souboru, ios::binary);
    Clovek data;

    while(FILE.read((char *)&data, sizeof(Clovek))){
        cout << data.jmeno << " " << data.prijmeni << " " << data.rodneCislo << endl;
    }
    FILE.close();
}

int main(){
    vytvorUzivatele("binary.bin");
    vytvorUzivatele("binary.bin");
    vypisZeSouboru("binary.bin");

    return 0;
}
