#include <iostream>
#include <fstream>

using namespace std;

struct Node{
    string slovo;
    int pocet;
    Node *next;

    // konstruktor
    Node(string &slovo){
        this->slovo = slovo;
        pocet = 1;
        next = nullptr;
    }
};

struct linkedList{
    Node *koren;

    // konstruktor
    linkedList(){
        koren = nullptr;
    }

    // vytvori Node se slovem a vrati pointer na slovo
    Node* addWord(string &word){
        Node* nove_slovo = new Node(word);
        return nove_slovo;
    }

    void checkWord(string &slovo){\
        // pokud neexistuje zatim zadne slovo tak ho pridame
        if (!koren){
            koren = addWord(slovo);
            return;
        }

        Node *ptr = koren, *last = koren;
        // prohledavame a popripade zvysime pocet
        while (ptr) {
            if (ptr->slovo == slovo){
                ptr->pocet++;
                return;
            }
            last = ptr;
            ptr = ptr->next;
        }
        
        // pokud slovo neni pridame ho
        last->next = addWord(slovo);
    }

    void print(){
        Node* ptr = koren;
        while (ptr) {
            cout << ptr->slovo << " " << ptr->pocet << endl;
            koren = ptr->next;
        }
    }

};

int main(){
    ifstream FILE("zprava.txt");
    string str;
    linkedList seznam; 

    while (FILE >> str){
        seznam.checkWord(str);
    }

    seznam.print();

    return 0;
}
