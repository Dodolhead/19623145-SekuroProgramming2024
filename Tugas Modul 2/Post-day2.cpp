#include <bits/stdc++.h>

using namespace std;

vector<vector<float>> koordinat{
    
    {0},{0}

};

int nilai = 0;
int re = nilai;


void lokasi(){
    cout << "(" << koordinat[0][nilai] << "," << koordinat[1][nilai] << ")" << endl;
}

void gerak(float x,float y){
    koordinat[0].push_back(x + koordinat[0][nilai]);
    koordinat[1].push_back(y + koordinat[1][nilai]);
}

void gerak_2(float v, float t, float sudut){
    int jarak = v*t;
    double rad = sudut*(3.14/180);
    int xmod = jarak*cos(rad);
    int ymod = jarak*sin(rad);
    koordinat[0].push_back(xmod + koordinat[0][nilai]);
    koordinat[1].push_back(ymod + koordinat[1][nilai]);
}

void undo(){
    if (nilai == 0){
        cout << "Tidak dapat Undo" << endl << endl;
    }

    else {
        nilai -= 1;
        koordinat[0].push_back(koordinat[0][nilai]);
        koordinat[1].push_back(koordinat[1][nilai]);
        cout << "Undo berhasil" << endl << endl;
    }
}

void redo (){
    if (nilai == re){
        cout << "Tidak dapat Redo" << endl << endl;
    }

    else {
        nilai += 1;
        koordinat[0].push_back(koordinat[0][nilai]);
        koordinat[1].push_back(koordinat[1][nilai]);
        cout << "Redo berhasil" << endl << endl;
    }
}

void save(){
    ofstream Myfile("Lokasi-terakhir.txt");
    Myfile << koordinat[0][nilai] << endl;
    Myfile << koordinat[1][nilai];
    cout << "Data berhasil di save" << endl << endl;
}

void load(){
    ifstream MyReadFile("Lokasi-terakhir.txt");
    string data;
    string arr[2];
    int a = 0;
    while (getline (MyReadFile, data)) {
        arr[a] = data;
        a += 1;
    }
    cout << "(" << arr[0] << "," << arr[1] << ")"<< endl << endl;
    cout << "Data berhasil di load" << endl << endl;
    MyReadFile.close();
}

int main(){

    bool z = true;
    float x, y,v, t, sudut; 
    string input;

    cout << "PROGRAM SIMULASI DRONE" << endl;
    cout << "Masukkan Perintah (scroll ketas untuk melihat hasil):" << endl << endl << "lokasi"  << endl << "gerak" << endl << "gerak_2" << endl << "undo" << endl << "redo" << endl << "save" << endl << "load" << endl << "exit" << endl << endl;
   
    while (z == true){
        cin >> input;
        cout << endl;

        if (input == "lokasi"){
            lokasi();
            cout << endl;
            
        }

        else if (input == "gerak"){
            cout << "Masukkan x dan y:" << endl;
            cout << "x: ";
            cin >> x;
            cout << "y: ";
            cin >> y;
            gerak(x,y);
            cout << endl;
            nilai += 1;
            re += 1;
        }

        else if (input == "gerak_2"){
            cout << "Masukkan v, t, dan sudut:" << endl;
            cout << "v: ";
            cin >> v;
            cout << "t: ";
            cin >> t;
            cout << "sudut: ";
            cin >> sudut;
            gerak_2(v,t,sudut);
            cout << endl;
            nilai += 1;
            re += 1;
        }

        else if (input == "undo"){
            undo();
        }

        else if (input == "redo"){
            redo();
        }

        else if (input == "exit"){
            z = false;
        }

        else if (input == "save"){
            save();
        }

        else if (input == "load"){
            load();
        }

        else {
            cout << "INPUT TIDAK VALID" << endl << endl;
        }
    }

}