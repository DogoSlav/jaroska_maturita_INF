#include <iostream>

using namespace std;

class SestridenePole{
    private:
        int *polePrvku, pocetPrvku, maxPocet;

    public:
        SestridenePole(int maximum);
        int vlozDoPole(int cislo);
        void tiskniPole();
};

SestridenePole::SestridenePole(int maximum){
    polePrvku = new int[maximum];
    maxPocet = maximum;
    pocetPrvku = 0;
}

int SestridenePole::vlozDoPole(int cislo){
    if (maxPocet == pocetPrvku) return 0;

    int pozice = 0;

    // najdeme pozici kam budeme cislo vkladat
    while (pozice < pocetPrvku && polePrvku[pozice] < cislo) pozice++;

    // posuneme prvky o jedno doprava abychom mohli vlozit nase cislo
    for (int i = pocetPrvku - 1; i >= pozice; i--){
        polePrvku[i + 1] = polePrvku[i];
    }

    // pridame cislo na misto
    polePrvku[pozice] = cislo;

    pocetPrvku++;

    return 1;
}

void SestridenePole::tiskniPole(){
    for (int i = 0; i < pocetPrvku; i++){
        cout << polePrvku[i] << " ";
    }
    cout << endl;
}


int main(){
    SestridenePole pole(10);

    pole.vlozDoPole(0);
    pole.vlozDoPole(10);
    pole.vlozDoPole(5);
    pole.vlozDoPole(-1);
    pole.vlozDoPole(15);
    pole.vlozDoPole(7);
    pole.vlozDoPole(3);

    pole.tiskniPole();

    return 0;
}
