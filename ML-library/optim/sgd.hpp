#ifndef SGD_HPP
#define SGD_HPP
#include <iostream>

using namespace std;

class SGD{
    private:
        Matrix X;
        Matrix y;
        Matrix theta;

        size_t number_epochs;
        double learning_rate;
    public:
        SGD(const Matrix& X,const Matrix& y,size_t epochs,double lr);
        ~SGD();

        Matrix gd();
};


#endif