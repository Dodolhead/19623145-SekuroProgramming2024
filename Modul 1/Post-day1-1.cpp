#include <iostream>

using namespace std;

int main(){

    int x;
    int y;

     cin >> x >> y;
    
    int angka = x;
    
     while ((x <= angka) && (angka < y)){
        if (angka % 2 == 0){
            cout << angka << " ";
            angka += 1;
        }

        else if (angka % 2 != 0){
            angka += 1;
        }
        
     }

}