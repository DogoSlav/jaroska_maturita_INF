#include <iostream>
#include <fstream>

using namespace std;

void nactiMatici(int matice[5][5], string cesta_k_souboru){
    // otevreme slozku s matici
    ifstream FILE(cesta_k_souboru);

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            FILE >> matice[i][j];
        }
    }

    FILE.close();
}

void sectiMatice(int matice1[5][5], int matice2[5][5], int vysledna_matice[5][5]){
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            vysledna_matice[i][j] = matice1[i][j] + matice2[i][j];
        }
    }
}

void zapisMatici(int matice[5][5], string cesta_k_souboru){
    // otevreme slozku na zapis
    ofstream FILE(cesta_k_souboru);

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            FILE << matice[i][j] << " ";
        }
        FILE << endl;
    }

    FILE.close();
}

int main(){
    int MATA[5][5], MATB[5][5], MATC[5][5];

    nactiMatici(MATA, "MATA.TXT");
    nactiMatici(MATB, "MATB.TXT");
    sectiMatice(MATA, MATB, MATC);
    zapisMatici(MATC, "MATC.TXT");

    return 0;
}
