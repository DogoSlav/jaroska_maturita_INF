#include <iostream>
#include <fstream>

using namespace std;

void nactiMatici(double matice[][4],string cesta_k_souboru){
    ifstream FILE(cesta_k_souboru);

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 4; j++){
            FILE >> matice[i][j];
        }
    }

    FILE.close();
}

void vypisMatici(double matice[][4]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 4; j++){
            cout << matice[i][j] << " ";
        }
        cout << endl;
    }
}

void vynasobRadek(double matice[][4], int radek, double nasobek){
    for (int i = 0; i < 4; i++){
        matice[radek][i] *= nasobek;
    }
}

void odectiRadky(double matice[][4], int horni_radek, int dolni_radek){
    for (int i = 0; i < 4; i++){
        matice[dolni_radek][i] -= matice[horni_radek][i];
    }
}

void pocitejMatici(double matice[][4]){
    for (int i = 0; i < 3; i++){
        vynasobRadek(matice, i, 1 / (double)matice[i][i]);
        for (int j = i + 1; j < 3; j++){
            vynasobRadek(matice, j, matice[i][i] / matice[j][i]);
            odectiRadky(matice, i, j);
        }
    }

    for (int i = 2; i >= 0; i--){
        vynasobRadek(matice, i, 1 / (double)matice[i][i]);
        for (int j = i - 1; j >= 0; j--){
            vynasobRadek(matice, j, matice[i][i] / matice[j][i]);
            odectiRadky(matice, i, j);
        }
    }
}

int main(){
    double matice[3][4];

    nactiMatici(matice, "rovnice.txt");
    pocitejMatici(matice);
    vypisMatici(matice);

    return 0;
}
