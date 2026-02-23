#include <iostream>
#include "core/matrix.hpp"


using namespace std;

int main(){
    Matrix m{
        {1,1,1},
        {2,3,1}
    };

    m.print();
    cout << endl;
    Matrix m2{
        {10},
        {20},
        {30}
    };

    m2.print();
    cout << endl;

    Matrix t = m2.transpose();
    t.print();
    return 0;
}