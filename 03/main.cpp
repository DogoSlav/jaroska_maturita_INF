#include <iostream>
#include <fstream>

using namespace std;

int main(){
    const int N = 100;
    ofstream OUT("out.txt");
    bool prvocislo[10000];

    for (int i = 0; i < 10000; i++){
        prvocislo[i] = 1;
    }

    prvocislo[0] = 0;
    for (int i = 1; i < N; i++){
        if (prvocislo[i]){
            OUT << i + 1 << " ";
            for (int j = i; j < N; j += i + 1){
                prvocislo[j] = 0;
            }
        }
    }
    
    return 0;
}
