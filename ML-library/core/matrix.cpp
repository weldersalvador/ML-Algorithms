#include "matrix.hpp"
#include <iostream>
#include <cmath>
#include <random>
#include <ctime>
#include <functional>
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
    matrix.reserve(rows*cols);
    for(auto row : values){
        for(double val : row)
            matrix.push_back(val);
    }
}

Matrix::Matrix(size_t r, size_t c){
    rows = r;
    cols = c;
    matrix.resize(r*c);
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

Matrix Matrix::get_column(size_t idx){

    if(idx >= cols)
        throw invalid_argument("The index must be valid");

    Matrix result(rows,1);
    size_t k = 0;
    for(size_t i = 0; i < rows; i++){
        result(0,k) = matrix[idx + i*cols];
        k++;
    }
    return result;
}

Matrix Matrix::get_row(size_t idx){
    if(idx >= rows)
        throw invalid_argument("The index must be valid");

    Matrix result(1,cols);
    size_t k = 0;
    for(size_t i = 0; i < rows; i++){
        result(0,k) = matrix[i];
        k++;
    }
    return result;
}

Matrix Matrix::transpose(){
    Matrix result(cols, rows);
    for(size_t i = 0; i < cols; i++){
        for(size_t j = 0; j < rows; j++){
            result(i,j) = matrix[j*cols + i];
        }
    }
    return result;
}

Matrix Matrix::sum(size_t axis) const{
    if(axis == 0){
        Matrix result(1,cols);
        for(size_t i = 0; i < cols; i++){
            for(size_t j = 0; j < rows; j++){
                result(0,i) += (*this)(j,i);
            }
        }
        return result;
    }
    else if(axis == 1){
        Matrix result(rows,1);
        for(size_t i = 0; i < rows; i++){
            for(size_t j = 0; j < cols; j++){
                result(i,0) += (*this)(i,j);
            }
        }
        return result;
    }
    else{
        throw invalid_argument("Axis must be 0 (columns) or 1 (axis)");
    }
}

Matrix Matrix::mean(size_t axis) const{
    if(axis == 0){
        Matrix result(1,cols);
        for(size_t i = 0; i < cols; i++){
            double sum = 0;
            for(size_t j = 0; j < rows; j++){
                sum += (*this)(j,i);
            }
            result(0,i) = sum / rows;
        }
        return result;
    }
    else if(axis == 1){
        Matrix result(rows,1);
        for(size_t i = 0; i < rows; i++){
            double sum = 0;
            for(size_t j = 0; j < cols; j++){
                sum += (*this)(i,j);
            }
            result(i,0) = sum / cols;
        }
        return result;
    }
    else{
        throw invalid_argument("Axis must be 0 (columns) or 1 (axis)");
    }
}

Matrix Matrix::hadamard(Matrix matrix1, Matrix matrix2){
    if(matrix1.getCols() != matrix2.getCols() || matrix1.getRows() != matrix2.getRows())
        throw invalid_argument("The matrices must have the same columns and rows");

    Matrix result(matrix1.getRows(),matrix1.getCols());

    for(size_t i = 0; i < matrix1.getRows();i++){
        for(size_t j = 0; j < matrix1.getCols(); j++){
            result(i,j) = matrix1(i,j)*matrix2(i,j);
        }
    }
    return result;
}
Matrix Matrix::exp(){
    Matrix result(rows,cols);
    for(size_t i = 0; i < rows; i++){
        for(size_t j = 0; j < cols; j++){
            result(i,j) = std::exp((*this)(i,j));
        }
    }
    return result;
}

Matrix Matrix::log(){
    Matrix result(rows,cols);
    for(size_t i = 0; i < rows; i++){
        for(size_t j = 0; j < cols; j++){
            result(i,j) = std::log((*this)(i,j));
        }
    }
    return result;
}

Matrix Matrix::random_normal(size_t rows, size_t cols,double mean, double stddv){
    random_device rd;
    mt19937 gen(rd());
    normal_distribution<double> dist(mean,stddv);
    Matrix result(rows,cols);
    for(size_t i = 0; i < rows; i++){
        for(size_t j = 0; j < cols; j++){
            result(i,j) = dist(gen);
        }
    }
    return result;
}

Matrix Matrix::apply(function<double(double)> f){
    Matrix result(rows,cols);
    for(size_t i = 0; i < rows; i++){
        for(size_t j = 0; j < cols; j++){
            result(i,j) = f((*this)(i,j));
        }
    }
    return result;
}

double Matrix::mse(Matrix results){
    double mse = 0;
    for(size_t i = 0; i < results.getRows(); i++){
        for(size_t j = 0; j < results.getCols(); j++){
            mse += ((*this)(i,j) - results(i,j))*((*this)(i,j) - results(i,j));
        }
    }
    return mse / (rows*cols);
} 
