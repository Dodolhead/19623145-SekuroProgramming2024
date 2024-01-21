#include <iostream>

using namespace std;

int main(){

    int batas;
    int bintang = 1;

    cin >> batas;

    for (int x = 0; x < batas; x++){
        for (int y = 0; y < x + 1; y++){
            cout << '*';
        }
        cout << endl;
    }

    for (int x = batas-1; x > 0; x--){
        for (int y = x ; y > 0; y--){
            cout << '*';
        }
        cout << endl;
    }

}