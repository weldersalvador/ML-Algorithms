#ifndef SGD_HPP
#define SGD_HPP

#include <iostream>
#include "matrix.hpp"  

class SGD {
    private:
        const Matrix &X;
        const Matrix &y;
        Matrix theta; 
        double learning_rate;
        std::size_t number_epochs;
    public:
        SGD(const Matrix& X,const Matrix& y,size_t epochs, double lr);
        ~SGD();

        Matrix gd();
};

#endif