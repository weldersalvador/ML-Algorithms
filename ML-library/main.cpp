#include <iostream>
#include "core/matrix.hpp"
#include "optim/sgd.hpp"

using namespace std;

double squared(int x){
    return x*x;
}
    

int main(){
    cout << endl;
    Matrix m1{
        {12,18,32,38,48}
    };

    Matrix m2{
        {10,20,30,40,50}
    };
    SGD theta = SGD(m1,m2,30,0.01);
    return 0;
}