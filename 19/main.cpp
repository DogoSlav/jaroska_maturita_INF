#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

struct TPRACOVNIK{
    char jmeno[50];
    int plat;
    char funkce[30];
    
};


int main(){
    vector<string> info(4);

    ifstream FILE("priklad.txt");
    ofstream OUT("out.txt", ios::out  | ios::binary);
    string s;
    char sep = ';';

    while (getline(FILE, s)){
        cout << "Nacteno: " << s;
        int count = 0;
        for (int i = 0; i < 4; i++){
            info[i].clear();
        }

        for (auto znak: s){
            if (znak == sep) {count++; continue;}

            info[count] += znak;    
        }

        TPRACOVNIK x;
        strcpy(x.jmeno, info[1].c_str());
        x.plat = stoi(info[2]);
        strcpy(x.funkce, info[3].c_str());
        cout << endl;
        cout << info[1].c_str() << endl;
        cout << info[3].c_str() << endl;

        OUT.write((char *)&x, sizeof(TPRACOVNIK));
    }

    FILE.close();
    OUT.close();
    return 0;
}
