#include <iostream>
#include "core/matrix.hpp"


using namespace std;

int main(){
    cout << endl;
    Matrix m2{
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    Matrix sum = m2.sum(1);
    sum.print();
    return 0;
}