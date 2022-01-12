#ifndef _dtw_h
#define _dtw_h

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

class DTW {
public:
    const double DTWVERYBIG = 100000000.0;
    int path_len;

    DTW() {};
    ~DTW() {};
    /**
     * calculate dtw distance for two sequences
     * x, y: sequences
     * x_size, y_size: length of sequences
     * win_size: length of window
     */ 
    double dtw_dist(double* x, double* y, int x_size, int y_size, int win_size);
    
    /**
     * show the sequence after dynamic time warping
     */
    int** dtw_path(double* x, double* y, int x_size, int y_size, int win_size); 

    inline void docstring() {
        std::cout << "This is a class about Dynamic Time Warping.\n"
            << "Please provide these parameters: \n"
            << "x, y           : two sequences needs to compare\n"
            << "x_size, y_size : length of sequence\n"
            << "win_size       : size of window" << std::endl;
    };

};

#endif