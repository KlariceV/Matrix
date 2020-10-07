#include "mat.h"

Matrix::Matrix() {
    this->nRows = 0;
    this->nCols = 0;
    this->m = nullptr;
}
Matrix::Matrix(uint _r, uint _c) {
    this->nRows = _r;
    this->nCols = _c;
    this->m = new double*[this->nRows];
    for(uint r = 0; r < this->nRows; r++) {
        this->m[r] = new double[this->nCols];
    }
    for(uint r = 0; r < this->nRows; r++) {
        for(uint c = 0; c < this->nCols; c++) {
            this->m[r][c] = 0;
        }
    }
}
Matrix::Matrix(const Matrix& m) {
    this->nRows = m.nRows;
    this->nCols = m.nCols;
    this->m = new double*[this->nRows];
    for(uint r = 0; r < this->nRows; r++) {
        this->m[r] = new double[this->nCols];
    }
    for(uint r = 0; r < this->nRows; r++) {
        for(uint c = 0; c < this->nCols; c++) {
            this->m[r][c] = m.m[r][c];
        }
    }
}
Matrix::~Matrix() {
    if(this->m != nullptr) {
        for(uint r = 0; r < this->nRows; r++) {
            delete [] this->m[r];
        }
        delete [] this->m;
        this->m = nullptr;
    }
    
}
Matrix& Matrix::operator=(const Matrix& m) {
    if(this->nRows == m.nRows && this->nCols == m.nCols) {
        for(uint r = 0; r < m.nRows; r++) {
            for(uint c = 0; c < m.nCols; c++) {
                this->m[r][c] = m.m[r][c];
            }
        }
    } else {
        for(uint r = 0; r < this->nRows; r++) {
            delete [] this->m[r];
        }
        delete [] this->m;
        this->nRows = m.nRows;
        this->nCols = m.nCols;
        this->m = new double*[m.nRows];
        for(uint r = 0; r < m.nRows; r++) {
            this->m[r] = new double[m.nCols];
        }
        for(uint r = 0; r < m.nRows; r++) {
            for(uint c = 0; c < m.nCols; c++) {
                this->m[r][c] = m.m[r][c];
            }
        }
    }
    return *this;
}
Matrix Matrix::operator+(const Matrix& m) {
    if(this->nRows != m.nRows || this->nCols != m.nCols) {
        std::cout << "ERROR: DIM MISMATCH\n";
        return *this;
    } else {
        Matrix n(m.nRows, m.nCols);
        for(uint r = 0; r < m.nRows; r++) {
            for(uint c = 0; c < m.nCols; c++) {
                n.m[r][c] = this->m[r][c] + m.m[r][c];
            }
        }
        return n;
    }
}
Matrix Matrix::operator-(const Matrix& m) {
    if(this->nRows != m.nRows || this->nCols != m.nCols) {
        std::cout << "ERROR: DIM MISMATCH\n";
        return *this;
    } else {
        Matrix n(m.nRows, m.nCols);
        for(uint r = 0; r < m.nRows; r++) {
            for(uint c = 0; c < m.nCols; c++) {
                n.m[r][c] = this->m[r][c] - m.m[r][c];
            }
        }
        return n;
    }
}
Matrix Matrix::operator*(const Matrix& m) {
    if(this->nCols != m.nRows) {
        std::cout << "ERROR: DIM MISMATCH\n";
        return *this;
    } else {
        Matrix n(this->nRows, m.nCols);
        for(uint r = 0; r < this->nRows; r++) {
            for(uint c = 0; c < m.nCols; c++) {
                for(uint k = 0; k < this->nCols; k++) {
                    n.m[r][c] += this->m[r][k] * m.m[k][c];
                }
            }
        }
        return n;
    }
}
Matrix Matrix::operator*(const double& d) {
    Matrix n(this->nRows, this->nCols);
    for(uint r = 0; r < this->nRows; r++) {
        for(uint c = 0; c < this->nCols; c++) {
            n.m[r][c] = this->m[r][c] * d;
        }
    }
    return n;
}
Matrix Matrix::operator/(const double& d) {
    Matrix n(this->nRows, this->nCols);
    for(uint r = 0; r < this->nRows; r++) {
        for(uint c = 0; c < this->nCols; c++) {
            n.m[r][c] = this->m[r][c] / d;
        }
    }
    return n;
}
Matrix& Matrix::operator+=(const Matrix& m) {
    *this = *this + m;
    return *this;
}
Matrix& Matrix::operator-=(const Matrix& m) {
    *this = *this - m;
    return *this;
}
Matrix& Matrix::operator*=(const Matrix& m) {
    *this = *this * m;
    return *this;
}
Matrix& Matrix::operator*=(const double& d) {
    *this = *this * d;
    return *this;
}
Matrix& Matrix::operator/=(const double& d) {
    *this = *this / d;
    return *this;
}
void Matrix::randomize() {
    for(uint r = 0; r < this->nRows; r++) {
        for(uint c = 0; c < this->nCols; c++) {
            this->m[r][c] = rand()/(float)RAND_MAX;
        }
    }
}