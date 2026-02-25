#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <functional>
#include <stdexcept>
#include <vector>

using namespace std;

class Matrix{
    private:
        vector<double> matrix;
        size_t rows, cols;
    public:
        double get_number(size_t i, size_t j);
        ~Matrix();
        Matrix(initializer_list<initializer_list<double>> values);

        double& operator()(size_t i, size_t j) {
            return matrix[i * cols + j];
        }

        const double& operator()(size_t i, size_t j) const {
            return matrix[i * cols + j];
        }


        Matrix(size_t r, size_t c);
        size_t getRows() const {return rows;};
        size_t getCols() const {return cols;};
        void print();

        static Matrix sum(initializer_list<Matrix> m);
        Matrix operator+(const Matrix &other_matrix) const {
            if((rows != other_matrix.getRows()) || (cols != other_matrix.getCols()))
                throw std::invalid_argument("The rows and columns must have the same size");
            Matrix result(rows,cols);
            for(size_t i = 0; i < rows;i++){
                for(size_t j = 0; j < cols; j++){
                    result(i,j) = matrix[i*cols + j] + other_matrix(i,j);
                }
            }  
            return result;
        }

        Matrix operator-(const Matrix &other_matrix){
            if((rows != other_matrix.getRows()) || (cols != other_matrix.getCols()))
                throw std::invalid_argument("The rows and columns must have the same size");
            Matrix result(rows,cols);
            for(size_t i = 0; i < rows;i++){
                for(size_t j = 0; j < cols; j++){
                    result(i,j) = matrix[i*cols + j] - other_matrix(i,j);
                }
            }  
            return result;
        }

        Matrix operator*(const Matrix &other_matrix) const{
            if(cols != other_matrix.getRows())
                throw invalid_argument("Incompatible dimensions");

            Matrix result(rows,other_matrix.getCols());

            for(size_t i = 0; i < rows; i++){
                for(size_t j = 0; j < other_matrix.getCols(); j++){
                    for(size_t k = 0; k < cols; k++){
                        result(i,j) += matrix[i*cols + k]*other_matrix(k,j);
                    }
                }
            }
            return result;
        }

        Matrix operator*(const double scalar){
            Matrix result(rows,cols);
            for(size_t i = 0; i < rows; i++){
                for(size_t j = 0; j < cols; j++){
                    result(i,j) = matrix[i*cols + j]*scalar;
                }
            }
            return result;
        }

        Matrix get_column(size_t idx);
        Matrix get_row(size_t idx);

        Matrix transpose() const;

        Matrix sum(size_t axis) const;
        Matrix mean(size_t axis) const;
        static Matrix hadamard(Matrix arr1, Matrix arr2);
        Matrix exp();
        Matrix log();
        static Matrix random_normal(size_t rows, size_t cols,double mean, double standard_dev);
        Matrix apply(function<double(double)> func);
        double mse(Matrix results);

};

#endif