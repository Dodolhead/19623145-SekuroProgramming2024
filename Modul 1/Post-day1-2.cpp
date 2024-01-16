#include <iostream>

using namespace std;

int main(){
    int jumlah;
    int x = 1;
    float angka;

    cout << "jumlah bilangan: ";
    cin >> jumlah;

    while (x <= jumlah){
        cout << "bilangan " << x << ": ";
        cin >> angka;
        x += 1;
        angka += angka;
    }

    cout << "RATA-RATA : " << angka/jumlah;

}