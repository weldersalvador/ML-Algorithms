#include <iostream>
#include "core/matrix.hpp"


using namespace std;

int main(){
    cout << endl;
    Matrix m1{
        {1,3,3},
        {4,5,6},
        {7,8,9}
    };

    Matrix m2{
        {2,2,3},
        {1,1,1},
        {3,3,3}
    };
    Matrix exp = m1.exp();
    exp.print();
    return 0;
}