#include "matrix.hpp"
#include <iostream>
using namespace std;

Matrix::Matrix(initializer_list<initializer_list<double>> values){
    rows = values.size();
    cols = values.begin()->size();
    if (values.size() == 0) {
        throw invalid_argument("Matrix cannot be empty.");
    }
    if (cols == 0) {
        throw invalid_argument("Matrix rows cannot be empty.");
    }
    for (const auto& row : values) {
        if (row.size() != cols) {
            throw invalid_argument("All rows must have the same number of columns.");
        }
    }
    matrix.reserve(rows*cols);
    for(auto row : values){
        for(double val : row)
            matrix.push_back(val);
    }
}

Matrix::Matrix(size_t r, size_t c){
    rows = r;
    cols = c;
    matrix.reserve(r*c);
}

Matrix::~Matrix(){
    
}

Matrix Matrix::sum(initializer_list<Matrix> matrices){
    auto it = matrices.begin();
    size_t r = it->getRows();
    size_t c = it->getCols();
    Matrix result(r,c);
    for(auto matrix : matrices){
        for(size_t i = 0; i < matrix.getRows();i++){
            for(size_t j = 0; j < matrix.getCols(); j++){
                result(i,j) += matrix(i,j);
            }
        }    
    }
    return result;
}

void Matrix::print(){
    for(size_t i = 0; i < rows;i++){
        for(size_t j = 0; j < cols; j++){
            cout << matrix[i*cols + j] << " ";
        }
        cout << endl;
    }
}

double Matrix::get_number(size_t i, size_t j){
    return matrix[i*cols + j];
}