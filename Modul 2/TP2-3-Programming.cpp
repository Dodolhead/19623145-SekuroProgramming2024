#include <iostream>

using namespace std;

int main(){
    int a = 10;
    int b = 20;
    int* pa = &a;
    int* pb = &b;
    int** ppa = &pa;
    int** ppb = &pb;
// Asumsikan address dari a adalah 0x111111
// Asumsikan address dari b adalah 0x222222
// Asumsikan address dari pa adalah 0x333333

// Asumsikan address dari pb adalah 0x444444
    cout<<a<<endl; //untuk output yang pertama keluarannya adalah 10 karena diatas di deklarasikan a = 10.
    cout<<&a<<endl; //untuk output yang kedua keluarannya adalah 0x7acc1ff6ac karena &a berarti output alamat memori dari a, sama seperti pa.
    cout<<pb<<endl; //untuk output yang ketiga keluarannya adalah 0x7acc1ff6a8 karena pb berarti output alamat memori dari b, sama seperti &b.
    cout<<ppa<<endl; ///untuk output yang keempat keluarannya adalah 0x7acc1ff6a0 karena ppa berarti output alamat memori dari pa, sama sepert &pa
    cout<<*pa<<endl; //untuk output yang kelima keluarannya adalah 10 karena *pa mengakses yang ada di dalam alamat memori tersebut yaitu a = 10.
    cout<<*ppb<<endl; //untuk output yang keenam keluarannya adalah 0x7acc1ff6a8 karena *ppb mengakses yang ada di dalam alamat memori tersebut yaitu alamt memori b (pb).
    cout<<**ppa<<endl; //untuk output yang ketujuh keluarannya adalah 10 karena **ppa mengakses yang ada di dalam alamat memori tersebut yaitu a = 10.
    cout<<*pb * **ppb<<endl; //untuk output yang kedelapan keluarannya adalah 400 karena *pb dan **ppb mengakses yang ada di dalam alamat memori tersebut yang keduanya hasilnya merupakan 20 dan dikalikan satu sama lain (20*20).

}
