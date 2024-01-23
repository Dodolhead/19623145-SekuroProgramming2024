#include <iostream>

using namespace std;

class LinearLine{
    private:
        float x1,y1,x2,y2;

    public:
        LinearLine(float x1, float y1, float x2, float y2) {
            this -> x1 = x1;
            this -> y1 = y1;
            this -> x2 = x2;
            this -> y2 = y2;
        }

        float gradient() {
            float m = (y2-y1)/(x2-x1);
            return m;
        }

        float y_intercept() {
            float y_inter;
            float m = gradient();
            y_inter = this -> y1 + m*(0 - this -> x1);
            return y_inter;
        }
        
        void operator + (float a) {
            cout << "y = " << gradient() << "x + " << a * - 1 * gradient() + y_intercept() << endl;
        }

        void printEquation() {
            cout << "y = " << gradient() << "X + " << y_intercept() << endl;
        }
        
        void printPoints() {
            cout << "(x1, y1) =" << "(" << this -> x1 << "," << this -> y1 << ")" << endl << "(x2, y2) =" << "(" << this -> x2 << "," << this -> y2 << ")" << endl;
        }
};

int main(){
    LinearLine line(1.0f, 8.0f, 2.0f, 3.0f); 
    int a = 3; 
    
    line.printPoints();
    cout << line.gradient() << endl;
    line.y_intercept();
    line.printEquation();
    line + a;
}
