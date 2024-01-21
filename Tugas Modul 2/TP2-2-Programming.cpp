#include <iostream>
#include <cmath>

using namespace std;

float luas(float x){
    return 3.14*pow(x,2);
}

int main(){

    cout << luas(3) << endl;
    cout << luas(5.5) << endl;
    
}