#include <iostream>

using namespace std;

// nejsem si jistej jak mame najit delku seznamu tak ho hledam dokud nenajdu '\0' tento znak ukoncuje retezec
int delkaSeznamu(char *s){
    int delka = 0;

    while (s[delka] != '\0') delka++;
    
    return delka;
}

void strdel(char *s, int pozice, int pocet){
    int delka = delkaSeznamu(s);

    // budeme postupne davat znak po znaku na spravne misto
    for (int i = pozice; i < delka - pocet; i++){
            s[i] = s[i + pocet];
    }

    // ukonceni noveho seznamu
    s[delka - pocet] = '\0';
}

void strins(char *s1, char *s2, int pozice){
    int delka1 = delkaSeznamu(s1);
    int delka2 = delkaSeznamu(s2);

    // nejdriv posuneme vsechny znaky v s1 doprava, musime posoouvat nejdrive ty vpravo abychom si je neprepsali
    for (int i = pozice + delka1; i >= pozice; i--){
        s1[i + delka2] = s1[i];
    }

    // ted vlozime s2 do s1
    for (int i = 0; i < delka2; i++){
        s1[pozice + i] = s2[i];
    }
}

int main(){
    char str1[15] = "ahoj lidi";
    char str2[10] = "cau";

    strins(str1, str2, 4);
    
    cout << str1 << endl;
}
