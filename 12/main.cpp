#include <iostream>

using namespace std;

struct Prvek{
    int hodnota;
    Prvek *dalsi;

    // kontruktor
    Prvek(int hodnota, Prvek* dalsi){
        this->hodnota = hodnota;
        this->dalsi = dalsi;
    }
};

struct LinkedList{
    Prvek *koren;

    LinkedList(){
        koren = nullptr;
    }

    void add(int cislo){
        Prvek *ptr = koren, *last;

        // kdyz je seznam prazdny
        if (!koren){
            koren = new Prvek(cislo, nullptr);
            return;
        }

        // kdyz pridavame na zacatek seznamu
        if (koren->hodnota > cislo){
            koren = new Prvek(cislo, koren);
            return;
        }

        while (ptr){
            // pokud najdeme vetsi cislo tak vytvorime Prvek ktery na toto cislo ukazuje a zaroven last bude prvek ktery bude ukazovat na nas
            if (ptr->hodnota > cislo){
                last->dalsi = new Prvek(cislo, ptr);
                return;
            }

            last = ptr;
            ptr = ptr->dalsi;
        }

        // pridame na konec pokud je cislo nejvyssi
        last->dalsi = new Prvek(cislo, nullptr);
    }

    void print(){
        Prvek *ptr = koren;

        while (ptr){
            cout << ptr->hodnota << " ";
            ptr = ptr->dalsi;
        }
        cout << endl;
    }

};

int main(){
    LinkedList seznam;

    seznam.add(5);
    seznam.add(10);
    seznam.add(0);
    seznam.add(15);
    seznam.add(7);
    seznam.add(13);
    seznam.add(2);

    seznam.print();

    return 0;
}
