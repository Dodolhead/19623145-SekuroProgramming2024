#include <iostream>

using namespace std;

int main(){

    int tahun;

    cout << "Tentukan tahun kabisat" << endl << "Tahun: ";
    cin >> tahun;

    if (((tahun % 400 != 0) && (tahun % 100 == 0)) or ((tahun % 400 != 0) && (tahun % 100 != 0) && (tahun % 4 != 0))){
        cout << "bukan kabisat";
    }
    
    else {
        cout << "kabisat";
    }

}   