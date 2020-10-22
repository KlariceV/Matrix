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
        Matrix(uint d_);
        Matrix(const double* d, uint size);
        Matrix(const Matrix& m);
        ~Matrix();


        Matrix& operator=(const Matrix& m);

        Matrix static add(const Matrix& m1, const Matrix& m2);
        Matrix static add(const Matrix& m1, const double& d);
        Matrix static subtract(const Matrix& m1, const Matrix& m2);
        Matrix static subtract(const Matrix& m1, const double& d);
        Matrix static multiply(const Matrix& m1, const Matrix& m2, const bool element_wise = false);
        Matrix static multiply(const Matrix& m1, const double& d);
        Matrix static divide(const Matrix& m1, const Matrix& m2);
        Matrix static divide(const Matrix& m1, const double& d);

        Matrix static identity(const uint d);
        Matrix static function(const Matrix& m, double (*func)(double));
        Matrix static transpose(const Matrix& m);

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
        Matrix& randomize();
};