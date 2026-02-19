#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>

using namespace std;

class Matrix{
    private:
        vector<double> matrix;
        size_t rows, cols;
    public:
        auto begin() { return matrix.begin(); }
        auto end() { return matrix.end(); }

        auto begin() const { return matrix.begin(); }
        auto end() const { return matrix.end(); }

        double& operator()(size_t i, size_t j);
        const double& operator()(size_t i, size_t j) const;
        ~Matrix();
        Matrix(initializer_list<initializer_list<double>> values);
        Matrix(size_t r, size_t c);
        size_t getRows(){return rows;};
        size_t getCols(){return cols;};
        void print();
        Matrix sum(initializer_list<Matrix> m1);
};

#endif