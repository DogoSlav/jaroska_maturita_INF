#include <iostream>

using namespace std;

int mod(int a, int b) {
    return (a % b + b) % b;
}

string zakoduj(const string &text, const string &klic){
    int len1 = text.size();
    int len2 = klic.size();
    int posun = 65;
    string output;

    for (int i = 0; i < text.size(); i++){
        int znak = text[i] - posun;
        int kl = klic[i % len2] - posun + 1;
 
        znak += kl;
        znak = mod(znak, 26);

        output += znak + posun;
    }

    return output;

}

string dekoduj(const string &text, const string &klic){
    int len1 = text.size();
    int len2 = klic.size();
    int posun = 65;
    string output;

    for (int i = 0; i < text.size(); i++){
        int znak = text[i] - posun;
        int kl = klic[i % len2] - posun + 1;
 
        znak -= kl;
        znak = mod(znak, 26);

        output += znak + posun;
    }

    return output;
}

int main(){
    string text, klic, output;

    cin >> text >> klic;
    cout << zakoduj(text, klic) << endl;
    cout << dekoduj(zakoduj(text, klic), klic) << endl;

    return 0;
}
