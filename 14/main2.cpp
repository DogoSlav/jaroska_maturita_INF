#include <iostream>

using namespace std;

// jednoduchy bubble sort
void serad(int *pole){
    for (int i = 0; i < 25; i++){
        for (int j = 0; j < 24; j++){
            if (pole[j] > pole[j + 1]) swap(pole[j], pole[j + 1]);
        }
    }
}

// binarni vyhledavani
int binSearch(int l, int r, int k, int *pole){
    if (l > r) return -1;
    int mid = (l + r) / 2;

    cout << "koukam doprosted: " << pole[mid] << " hledam: " << k << endl;

    if (pole[mid] > k) {cout << "jdu doleva" << endl << endl; return binSearch(l, mid - 1, k, pole);}
    if (pole[mid] < k) {cout << "jdu doprava" << endl << endl; return binSearch(mid + 1, r, k, pole);}
    
    // vrat index pokud jsem nasel k jinak -1
    return (pole[mid] == k) ? mid : -1;
}

void print(int *pole){
    for (int i = 0; i < 25; i++){
        cout << pole[i] << " ";
    }
    cout << endl;
}

int main(){
    int pole[25];

    for (int i = 0; i < 25; i++){
        pole[i] = rand() % 100;
    }

    print(pole);
    serad(pole);
    print(pole);
    cout << binSearch(0, 24, pole[3], pole) << endl;



    return 0;
}
