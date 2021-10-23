#include <iostream>
#include <vector>

#include <Eigen/Dense>
 
using Eigen::MatrixXd;

typedef Eigen::Matrix<float, 3, 3> Matrix33f;
typedef Eigen::Matrix<float, 3, 1> Vector3f;
typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> DMatrix;  // dynamic matrix


void initial() {
    Matrix33f a;
    Vector3f v;
    DMatrix m(10, 5);

    a = Matrix33f::Identity(); 
    a << 1, 2, 3, 4, 5, 6, 7, 8, 9;  // comma-initializer syntax

    // change an element of matrix directly
    a(0, 0) = 4;

    v = Vector3f::Random();

    std::cout << a << std::endl;
    std::cout << v << std::endl;
}

void initialByMap() {
    int data[] = {1,2,3,4};
    Eigen::Map<Eigen::RowVectorXi> v(data,4);
    std::vector<float> data1 = {1,2,3,4,5,6,7,8,9};
    Eigen::Map<Matrix33f> a(data1.data());

    std::cout << v << std::endl;
    std::cout << a << std::endl;
}

void calc() {
    Matrix33f a, b;
    a = Matrix33f::Random();
    b = Matrix33f::Random();

    std::cout << a+b << std::endl;  // eigen overload operators, like +/-/*
    std::cout << a.array() * b.array() << std::endl;  // element-wise multiplication
    std::cout << a*b << std::endl;   // matrix multiplication

}

int main()
{
    std::cout << "intial: " << std::endl;
    initial();

    std::cout << "intial by Eigen::Map: " << std::endl;
    initialByMap();

    std::cout << "calculate use Eigen: " << std::endl;
    calc();

    return 0;
}