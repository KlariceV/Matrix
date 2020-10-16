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
Matrix::Matrix(uint _d) {
    this->nRows = _d;
    this->nCols = _d;
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

Matrix Matrix::add(const Matrix& m1, const Matrix& m2) {
    if(m1.nRows != m2.nRows || m1.nCols != m2.nCols) {
        std::cout << "ERROR: DIM MISMATCH\n";
        return m1;
    } else {
        Matrix n(m1.nRows, m1.nCols);
        for(uint r = 0; r < m1.nRows; r++) {
            for(uint c = 0; c < m1.nCols; c++) {
                n.m[r][c] = m1.m[r][c] + m2.m[r][c];
            }
        }
        return n;
    }
}
Matrix Matrix::add(const Matrix& m1, const double& d) {
    Matrix n(m1.nRows, m1.nCols);
    for(uint r = 0; r < m1.nRows; r++) {
        for(uint c = 0; c < m1.nCols; c++) {
            n.m[r][c] = m1.m[r][c] + d;
        }
    }
    return n;
}
Matrix Matrix::subtract(const Matrix& m1, const Matrix& m2) {
    if(m1.nRows != m2.nRows || m1.nCols != m2.nCols) {
        std::cout << "ERROR: DIM MISMATCH\n";
        return m1;
    } else {
        Matrix n(m1.nRows, m1.nCols);
        for(uint r = 0; r < m1.nRows; r++) {
            for(uint c = 0; c < m1.nCols; c++) {
                n.m[r][c] = m1.m[r][c] - m2.m[r][c];
            }
        }
        return n;
    }
}
Matrix Matrix::subtract(const Matrix& m1, const double& d) {
    Matrix n(m1.nRows, m1.nCols);
    for(uint r = 0; r < m1.nRows; r++) {
        for(uint c = 0; c < m1.nCols; c++) {
            n.m[r][c] = m1.m[r][c] - d;
        }
    }
    return n;
}
Matrix Matrix::multiply(const Matrix& m1, const Matrix& m2, const bool element_wise) {
    if(element_wise == true) {
        if(m1.nRows != m2.nRows || m1.nCols != m2.nCols) {
            std::cout << "ERROR: DIM MISMATCH\n";
            return m1;
        } else {
            Matrix n(m1.nRows, m1.nCols);
            for(uint r = 0; r < m1.nRows; r++) {
                for(uint c = 0; c < m1.nCols; c++) {
                    n.m[r][c] = m1.m[r][c] * m2.m[r][c];
                }
            }
            return n;
        }
    } else {
        if(m1.nCols != m2.nRows) {
            std::cout << "ERROR: DIM MISMATCH\n";
            return m1;
        } else {
            Matrix n(m1.nRows, m2.nCols);
            for(uint r = 0; r < m1.nRows; r++) {
                for(uint c = 0; c < m2.nCols; c++) {
                    for(uint k = 0; k < m1.nCols; k++) {
                        n.m[r][c] += m1.m[r][k] * m2.m[k][c];
                    }
                }
            }
            return n;
        }
    }
}
Matrix Matrix::multiply(const Matrix& m1, const double& d) {
    Matrix n(m1.nRows, m1.nCols);
    for(uint r = 0; r < m1.nRows; r++) {
        for(uint c = 0; c < m1.nCols; c++) {
            n.m[r][c] = m1.m[r][c] * d;
        }
    }
    return n;
}
Matrix Matrix::divide(const Matrix& m1, const Matrix& m2) {
    if(m1.nRows != m2.nRows || m1.nCols != m2.nCols) {
        std::cout << "ERROR: DIM MISMATCH\n";
        return m1;
    } else {
        Matrix n(m1.nRows, m1.nCols);
        for(uint r = 0; r < m1.nRows; r++) {
            for(uint c = 0; c < m1.nCols; c++) {
                n.m[r][c] = m1.m[r][c] / m2.m[r][c];
            }
        }
        return n;
    }
}
Matrix Matrix::divide(const Matrix& m1, const double& d) {
    Matrix n(m1.nRows, m1.nCols);
    for(uint r = 0; r < m1.nRows; r++) {
        for(uint c = 0; c < m1.nCols; c++) {
            n.m[r][c] = m1.m[r][c] / d;
        }
    }
    return n;
}
Matrix Matrix::identity(uint d) {
    Matrix n(d, d);
    for(uint r = 0; r < d; r++) {
        for(uint c = 0; c < d; c++) {
            if(r == c) {n.m[r][c] = 1;}
            else {n.m[r][c] = 0;}
        }
    }
    return n;
}
Matrix& Matrix::randomize() {
    for(uint r = 0; r < this->nRows; r++) {
        for(uint c = 0; c < this->nCols; c++) {
            this->m[r][c] = rand()/(float)RAND_MAX;
        }
    }
    return *this;
}
Matrix Matrix::transpose() {
    Matrix n(this->nCols, this->nRows);
    for(uint r = 0; r < this->nRows; r++) {
        for(uint c = 0; c < this->nCols; c++) {
            n.m[c][r] = this->m[r][c];
        }
    }
    return n;
}