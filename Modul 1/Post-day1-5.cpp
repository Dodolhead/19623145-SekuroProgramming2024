#include <iostream>

using namespace std;

int main(){

    int angka;
    bool isPrime = true;

    cout << "Program C++ Angka Prima" << endl << "=======================" << endl << endl;
    cout << "Input satu angka bulat: ";
    cin >> angka;

    for (int i = 2; i*i <= angka; i++){
        if(angka%i == 0){
            isPrime = false;
        }

    }

    if (isPrime){
        cout << angka << " angka prima";

    }

    else {
        cout << angka << " bukan angka prima";
    }

}