#include <iostream>

using namespace std;

class Shape{
private:
    float area;
    float keliling;
public:
    virtual float calculateArea() { 
        return 0; 
    }
    virtual float calculateKeliling() { 
        return 0; 
    }
};

class Rectangle : public Shape{
    private:
        float width;
        float length;

    public:
        Rectangle(int width,int length){
            this -> width = width;
            this -> length = length; 
        }

        float calculateArea(){
            return this -> width * this -> length; 
        }

        float calculateKeliling(){
            return 2 * this -> width + 2 * this -> length;
        }

};

int main(){
    Rectangle rect(5.0, 4.0);
    Shape* shape1 = &rect;
    
    cout << "Luas Persegi Panjang: " << rect.calculateArea() << endl;
    cout << "Keliling Persegi Panjang: " << rect.calculateKeliling();

    return 0;
}