#include <iostream>

using namespace std;

int main(){

    char x;

    while (x != 'o'){
        cout << "Masukkan jenis pesawat: " ;
        cin >> x;
        if (x == 'a'){
            cout << "3" << endl << "2" << endl << "1" << endl << "PESAWAT A BERANGKAT" << endl;
        }

        else if (x == 'b'){
            cout << "5" << endl << "4" << endl << "3" << endl << "2" << endl << "1" << endl <<"PESAWAT B BERANGKAT" << endl;
        }

        else if (x == 'o'){
            cout << "PENERBANGAN DITUTUP" << endl;
        }

        else {
            cout << "INPUT TIDAK VALID" << endl;
        }

    }

}