#include <iostream>
#include <vector>
#include <cmath>
#include "pbPlots/pbPlots.cpp"
#include "pbPlots/supportLib.cpp"

using namespace std;

class Matrix {
private:
    vector<vector<double>> data;
    int rows;
    int cols;

public:
    Matrix(const vector<vector<double>>& input = {}) : data(input), rows(input.size()), cols(input.empty() ? 0 : input[0].size()) {}

    Matrix(int numRows, int numCols) : data(vector<vector<double>>(numRows, vector<double>(numCols, 0))), rows(numRows), cols(numCols) {}

    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            cout << "The matrix dimension is not valid!\n";
            return Matrix(1, 1);
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator-(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            cout << "The matrix dimension is not valid!\n";
            return Matrix(1, 1);
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            cout << "Multiplication cannot be done. The number of columns in the first matrix should be equal to the number of rows in the second.\n";
            return Matrix(1, 1);
        }

        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                for (int k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    vector<vector<double>> getmatrix() const {
        return data;
    }
};

class Swerve {
private:
    double r;
    double x;
    double y;
    vector<vector<double>> v_gede;
    vector<vector<double>> v_hasil;
    vector<vector<double>> v_kecil;
    Matrix m_gede;
    Matrix m_kecil;
    Matrix m_hasil;

public:
    Swerve() : r(0.26363), x(0.0), y(0.0),
               v_gede({{1, 0, -r}, {0, 1, r}, {1, 0, -r}, {0, 1, r},
                       {1, 0, -r}, {0, 1, r}, {1, 0, -r}, {0, 1, r}}),
               m_gede(this->v_gede), v_kecil({{0.0}, {0.0}, {0.0}}), m_kecil(this->v_kecil) {}

    vector<vector<double>> velocityCommand(double t) {
        double vx = 48 * cos(t) * sin(t) * sin(t);
        double vy = 4 * sin(4 * t) + 6 * sin(3 * t) + 10 * sin(2 * t) - 13 * sin(t);

        this->v_kecil = {{vx}, {vy}, {0.0}}; // Set omega to 0
        this->m_kecil = Matrix(this->v_kecil);
        this->m_hasil = m_gede * m_kecil;
        this->v_hasil = m_hasil.getmatrix();
        return this->v_hasil;
    }

    void updatePose(double deltaTime) {
        x += v_hasil[0][0] * deltaTime;
        y += v_hasil[1][0] * deltaTime;
    }

    double getX() const { return x; }
    double getY() const { return y; }
};

void graph(vector<double>& x_axis, vector<double>& y_axis, int image_num) {
    bool success;
    StringReference *errorMessage = CreateStringReferenceLengthValue(0, L' ');
    RGBABitmapImageReference *imageReference = CreateRGBABitmapImageReference();

    vector<double> xs = x_axis;
    vector<double> ys = y_axis;

    success = DrawScatterPlot(imageReference, 600, 400, &xs, &ys, errorMessage);

    if (success) {
        vector<double> *pngdata = ConvertToPNG(imageReference->image);
        string name = "grafik_" + to_string(image_num) + ".png";
        WriteToFile(pngdata, name);
        DeleteImage(imageReference->image);
    } else {
        cerr << "Error: ";
        for (wchar_t c : *errorMessage->string) {
            wcerr << c;
        }
        cerr << endl;
    }

    FreeAllocations();
}

int main() {
    vector<double> waktu = {0};

    for (double i = 0.01; i <= 6.3; i += 0.01) {
        waktu.push_back(i);
    }

    Swerve robot;

    const double time_bound = 6.3;
    const double time_step = 0.01;

    vector<double> x_vals, y_vals, v1_vals, v2_vals, v3_vals, v4_vals, times;

    for (double t = 0; t <= time_bound; t += time_step) {
        vector<vector<double>> v_result = robot.velocityCommand(t);
        robot.updatePose(time_step);

        x_vals.push_back(robot.getX());
        y_vals.push_back(robot.getY());
        v1_vals.push_back(v_result[0][0]);
        v2_vals.push_back(v_result[1][0]);
        v3_vals.push_back(v_result[2][0]);
        v4_vals.push_back(v_result[3][0]);

        times.push_back(t);
    }

    // Plotting
    graph(x_vals, y_vals, 1);
    graph(times, v1_vals, 2);
    graph(times, v2_vals, 3);
    graph(times, v3_vals, 4);
    graph(times, v4_vals, 5);

    cout << "Plots generated successfully!" << endl;

    return 0;
}
