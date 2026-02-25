#include "sgd.hpp"
#include <iostream>
#include "matrix.hpp"
using namespace std;

SGD::SGD(const Matrix& X,const Matrix& y, size_t epochs, double lr) 
    : X(X), 
      y(y), 
      number_epochs(epochs), 
      learning_rate(lr),
      theta(X.getCols(), 1)
{

}

SGD::~SGD(){
    
}

Matrix SGD::gd(){
    Matrix theta = Matrix::random_normal(1,5,2,1);
    theta.print();
    cout << endl;
    Matrix gradients(1,5);
    gradients.print();
    size_t m = X.getCols();
    cout << endl;
    Matrix X_t = X.transpose();
    X_t.print();
    
    for(size_t i = 0; i < number_epochs; i++){
        Matrix predictions = theta * X;
        Matrix errors = predictions - y;  
        Matrix gradients = (X.transpose() * errors) * (2.0/m);
        theta = theta - gradients * learning_rate;
    }
    return theta;
}