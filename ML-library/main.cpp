#include <iostream>
#include "core/matrix.hpp"


using namespace std;

int main(){
    Matrix m{
        {1},
        {2},
        {3},
        {4}
    };

    m.print();
    cout << endl;
    Matrix m2{
        {10},
        {22},
        {33},
        {41}
    };

    m2.print();
    cout << endl;

    Matrix sum = m - m2;
    sum.print();
    return 0;
}