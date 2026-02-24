#include <iostream>
#include "core/matrix.hpp"


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
    cout << m1.mse(m2) << endl;
    return 0;
}