#pragma once
#include <iostream>
#include <iomanip>
#include <cstdlib>

class Matrix {
    private:
        uint nRows, nCols;
        double** m;
    public:
        Matrix();
        Matrix(uint r_, uint c_);
        Matrix(const Matrix& m);
        ~Matrix();


        Matrix& operator=(const Matrix& m);

        Matrix operator+(const Matrix& m);
        Matrix operator-(const Matrix& m);
        Matrix operator*(const Matrix& m);
        Matrix operator*(const double& d);
        Matrix operator/(const double& d);

        Matrix& operator+=(const Matrix& m);
        Matrix& operator-=(const Matrix& m);
        Matrix& operator*=(const Matrix& m);
        Matrix& operator*=(const double& d);
        Matrix& operator/=(const double& d);

        inline double* &operator[](uint i) {return this->m[i];}
        
        friend std::ostream& operator<<(std::ostream& os, const Matrix& m) {
            for(uint r = 0; r < m.nRows; r++) {
                for(uint c = 0; c < m.nCols; c++) {
                    std::cout << std::setw(7) << std::setfill(' ') << std::left << static_cast<int>(m.m[r][c]*1000)/1000.0f;
                }
                if(r + 1 != m.nRows) {std::cout << "\n";}
            }
            return os;
        }
        void randomize();
};