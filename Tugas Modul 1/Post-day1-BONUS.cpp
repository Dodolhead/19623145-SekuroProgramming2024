#include <iostream>

using namespace std;

int main(){

    int angka = 0;
    int baris;
    int baris2;
    int baris3 = 2;
    int awal = 0;
    bool bol;

    cout << "N = ";
    cin >> baris;
    bol = true;
    baris2 = (baris/2)+1;

    for (int y = 0; y < (baris/2)+1; y++){
        for (int i = 0; i < awal; i++){
            cout << " ";
        }

        for (int x = baris2; x > 0; x--){
            cout << angka;
            angka += 1;
            if (angka == 10){
                angka = 0;
            }
        }

        cout << endl;
        awal += 1;
        baris2 -= 1;

    }

    for (int i = 0; i < baris - (baris/2)-1; i++){
        for (int j = 0; j < (baris/2); j++){
            cout << " ";
        }

        for (int k = 0; k < baris3; k++){
            cout << angka;
            angka += 1;
            if (angka == 10){
                angka = 0;
            }
        } 

        cout << endl;
        baris3 += 1;
    }

}