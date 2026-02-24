#include "sgd.hpp"
#include <iostream>
#include "matrix.hpp"
using namespace std;

SGD::SGD(const Matrix& X,
         const Matrix& y,
         size_t epochs,
         double lr){
            this->X = X;
            this->y = y;
            this->number_epochs = epochs;
            this->learning_rate = lr;
}

SGD::~SGD(){
    
}

Matrix SGD::gd(){
    Matrix theta = Matrix::random_normal(1,4,2,1);
    Matrix gradients(1,4);
    int m = 4;
    for(size_t i = 0; i < number_epochs; i++){
        gradients = (X.transpose() * (X * theta - y))*(2.0/m);
        theta = theta - gradients*learning_rate;
    }
    return theta;
}