#include <iostream>

using namespace std;

int main(){
    string add = "&nbsp;", output, input;

    getline(cin, input);

    int len = 0;
    for (int i = 0; i < input.size(); i++){
        if (input[i] == ' '){
            output += ((len == 1) ? add : " ");

            len = 0;
        }
        else{
            len++;
            output += input[i];
        }
    }

    cout << output << endl;
}
