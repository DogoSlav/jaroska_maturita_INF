#include <iostream>
#include <algorithm>
using namespace std;

struct T{
    int *pole;
    int size;

    T(int *arr, int velikost){
        pole = arr;
        size = velikost;
    }

    void nahodne_cisla(int i){
        if (i == size) return;
        pole[i] = rand() % 10;
        nahodne_cisla(i + 1);
    }

    void print(int i){

        if (i == size) {cout << endl; return;}

        cout << pole[i] << " ";
        print(i + 1);
    }

    void serad(){
        sort(pole, pole + size);
    }
};

int main(){
    int pole[5];

    T lol(pole, 5);
    lol.nahodne_cisla(0);
    lol.print(0);
    lol.serad();
    lol.print(0);
    //xd
}
