#include <iostream>
#include "dtw.h"

int main() {
    DTW dtw;
    dtw.docstring();
    double a[] = {1, 1, 3, 3, 2, 4};
    double b[] = {1, 3, 2, 2, 4, 4};

    std::cout << dtw.dtw_dist(a, b, 6, 6, 2) << std::endl;
    
    int** c = dtw.dtw_path(a, b, 6, 6, 2);
    for (int i = 0; i < 2; i ++) {
        for (int j = 0; j < dtw.path_len; j ++) 
            std::cout << c[i][j]+1 << ' ';
        std::cout << std::endl;
    } 
    return 0;
}