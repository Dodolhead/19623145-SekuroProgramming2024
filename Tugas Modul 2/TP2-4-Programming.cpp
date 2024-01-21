#include <iostream>

using namespace std;

int jumlah(int arr[]){
    int N;
    int hasil = 0;
    for (int x = 0; x < N; x++){
        hasil += arr[x];
    }
    return hasil;
}

int main(){

    int N;
    cin >> N;

    int arr[N];

    for(int i = 0; i < N; i++){
        cin>>arr[i];
    }

    cout << jumlah(arr) << endl;

}