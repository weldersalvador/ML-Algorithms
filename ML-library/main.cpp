#include <iostream>
#include "core/matrix.hpp"


using namespace std;

int main(){
    
    Matrix m{
        {1,2,3,4},
        {1,1,1,1},
        {1,2,3,4}
    };

    m.print();
    cout << endl;
    Matrix m2{
        {1,1,1,1},
        {2,1,2,3},
        {3,3,3,3},
        {4,4,4,4}
    };

    m2.print();
    cout << endl;

    Matrix sum = m2.sum({m});
    sum.print();

    return 0;
}