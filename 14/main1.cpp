#include <iostream>
#include <fstream>
#include <vector>

using namespace std;



int main(){
    ifstream FILE1("a1.txt"), FILE2("a2.txt");
    vector<int> arr1, arr2, output;

    int a;
    
    // nacitani vstupu
    while (FILE1 >> a) arr1.push_back(a);
    while (FILE2 >> a) arr2.push_back(a);

    FILE1.close();
    FILE2.close();


    int len1 = arr1.size(), len2 = arr2.size();
    int i = 0, j = 0;
    
    while (i + j < len1 + len2) {

        // podminky kdyz uz jsme pouzili vsechna cisla z jednoho seznamu
        if (i == len1){
            output.push_back(arr2[j]);
            j++;
            continue;
        }

        if (j == len2){
            output.push_back(arr1[i]);
            i++;
            continue;
        }

        // do listu pridame mensi cislo
        if (arr1[i] > arr2[j]){
            output.push_back(arr2[j]);
            j++;
        }
        else {
            output.push_back(arr1[i]);
            i++;
        }
    }

    // zapiseme vysledek
    ofstream FILE("A3.txt");
    for (auto it: output){
        FILE << it << " ";
    }
    FILE.close();

    return 0;
}
