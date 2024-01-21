#include <iostream>

using namespace std;

int main(){

    int arr[10];
    int arr2[10];
    int hasil;

    for (int x = 0; x < 10; x++){
        cin >> arr[x];
    }

    for (int y = 0; y < 10; y++){
        cin >> arr2[y];
    }

    for (int z = 0; z < 10; z++){
        hasil = arr[z] + arr2[z];
        cout << hasil << " ";
    }


}