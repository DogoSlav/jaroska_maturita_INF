#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream FILE("vypoved.txt");
    ofstream VYSTUP("skutecne.txt");
    string radek;
    string hledany = " ne";

    while (getline(FILE, radek)){
        // funkci find a erase jsem nasel na c++ reference
        size_t pozice;
        // zjistime na ktere pozici je dalsi ne, jinak cyklus konci a mame vysledny string
        while ((pozice = radek.find(hledany)) != string::npos){
            radek.erase(pozice + 1, 2);
        }

        VYSTUP << radek << endl;
    }

    FILE.close();
    VYSTUP.close();
}
