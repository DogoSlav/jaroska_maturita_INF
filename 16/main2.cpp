#include <iostream>

using namespace std;

void print(int matice[][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << matice[i][j] << " ";
        }
        cout << endl;
    }
}

bool radkoveDominantni(int matice[][3], int radek){
    int soucet = 0;

    for (int i = 0; i < 3; i++){
        if (radek == i) continue;
        soucet += matice[radek][i];
    }

    return matice[radek][radek] > soucet; 
}

bool sloupcoveDominantni(int matice[][3], int sloupec){
    int soucet = 0;
    for (int i = 0; i < 3; i++){
        if (sloupec == i) continue;

        soucet += matice[i][sloupec];
    }

    return matice[sloupec][sloupec] > soucet;
}

int main(){
    int matice[3][3] = {4, -1, 0,
                        2, 5, 7,
                        0, -2, 6};

    print(matice);

    for (int i = 0; i < 3; i++){
        cout << radkoveDominantni(matice, i) << " ";
        cout << sloupcoveDominantni(matice, i) << endl << endl;
    }

    return 0;
}
