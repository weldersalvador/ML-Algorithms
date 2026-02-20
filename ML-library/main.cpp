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
        {10,21,33,45},
        {22,12,11,23},
        {33,4,7,2},
        {41,10,5,231},
        {1,2,1,2,3}
    };

    m2.print();
    cout << endl;

    Matrix column0 = m2.get_column(-1);
    column0.print();
    return 0;
}