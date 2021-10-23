Eigen is a general-purpose linear algebra C++ library.

# use cmake import eigen

https://eigen.tuxfamily.org/dox/TopicCMakeGuide.html

step 1: download the eigen library

step 2: use cmake build eigen

**attention**: you should make a directory named "build", then cmake it

step 3: cmake your project 

step 4: you are happy to use it


# Eigen 
In eigen, all matrices and vectors are objects of the Matrix template class 

## intial

use typedef define a (3, 3) shape of matrix 
``` c++
typedef Eigen::Matrix<float, 3, 3> Matrix33f;
```

use **"comma-initializer"** initial matrix
``` c++
a << 1, 2, 3, 4, 5, 6, 7, 8, 9;   
```

change an element of matrix directly
``` c++
a(0, 0) = 4;
```

use Eigen::Map to wrap a c/c++ raw array/vector
``` c++
int data[] = {1,2,3,4};
Eigen::Map<Eigen::RowVectorXi> v(data,4);
std::vector<float> data1 = {1,2,3,4,5,6,7,8,9};
Eigen::Map<Matrix33f> a(data1.data());
```


## calcualte

``` c++
Matrix33f a, b;
a = Matrix33f::Random();
b = Matrix33f::Random();

std::cout << a+b << std::endl;  // eigen overload operators, like +/-/*
std::cout << a.array() * b.array() << std::endl;  // element-wise multiplication
std::cout << a*b << std::endl;   // matrix multiplication
```

