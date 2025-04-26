#include <iostream>
#include <fstream>

using namespace std;

int main(){
    const int N = 100;
    ofstream OUT("out.txt");
    bool prvocislo[10000];

    // nastavime vsechna cisla na prvocisla
    // prvocislo[i] je true pokud i je prvocislo
    for (int i = 0; i < 10000; i++){
        prvocislo[i] = 1;
    }
    
    // zaciname od prvniho prvocisla a to je 2
    for (int i = 2; i < N; i++){

        // pokud je i prvocislo tak ho zapiseme do souboru
        if (prvocislo[i]){
            OUT << i << " ";

            // vsechna cisla ktera jsou nasobky prave objeveneho prvocisla nastuvujeme na false
            for (int j = i; j < N; j += i){
                prvocislo[j] = 0;
            }
        }
    }
    
    return 0;
}
