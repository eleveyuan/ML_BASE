#include "dtw.h"

double DTW::dtw_dist(double* x, double* y, int x_size, int y_size, int win_size) {
    std::cout << "start to calculating dtw distance..." << std::endl;
    double dist, min;
    int min_idx, max_idx;

    // store distance of elements of two sequences
    // Setting the matrix length plus 1 is to reserve space to store the results,
    // and you can also reduce the space usage by modifying the index
    double **dists = (double**)malloc((x_size+1) * sizeof(double *));
    for (int i = 0; i < x_size+1; i ++)
        dists[i] = (double*)malloc((y_size+1) * sizeof(double));

    for (int i = 0; i < x_size+1; i ++)
        for (int j = 0; j < y_size+1; j ++)
            dists[i][j] = DTWVERYBIG;
    dists[0][0] = 0.0;

    // dynamic programming
    for (int i = 0; i < x_size; i ++) {
        min_idx = i - win_size;
        if(min_idx < 0)
            min_idx = 0;
        max_idx = i + win_size;
        if(max_idx > y_size)
            max_idx = y_size;
        for (int j = min_idx; j < max_idx; j ++) {
            dist = fabs(x[i] - y[j]);
            min = dists[i][j];
            if (min > dists[i][j+1])
                min = dists[i][j+1];
            if (min > dists[i+1][j])
                min = dists[i+1][j];
            dists[i+1][j+1] = dist + min;
        }
    }

    dist = dists[x_size][y_size];

    for(int i = 0; i < x_size + 1; ++i)
        free(dists[i]);
    free(dists);

    return dist;
}

int** DTW::dtw_path(double* x, double* y, int x_size, int y_size, int win_size) {
    double dist, min;
    int min_idx, max_idx;

    // store distance of elements of two sequences
    double **dists = (double**)malloc((x_size+1) * sizeof(double *));
    for (int i = 0; i < x_size+1; i ++)
        dists[i] = (double*)malloc((y_size+1) * sizeof(double));

    for (int i = 0; i < x_size+1; i ++)
        for (int j = 0; j < y_size+1; j ++)
            dists[i][j] = DTWVERYBIG;
    dists[0][0] = 0.0;

    // dynamic programming
    for (int i = 0; i < x_size; i ++) {
        min_idx = i - win_size;
        if(min_idx < 0)
            min_idx = 0;
        max_idx = i + win_size;
        if(max_idx > y_size)
            max_idx = y_size;
        for (int j = min_idx; j < max_idx; j ++) {
            dist = fabs(x[i] - y[j]);
            min = dists[i][j];
            if (min > dists[i][j+1])
                min = dists[i][j+1];
            if (min > dists[i+1][j])
                min = dists[i+1][j];
            dists[i+1][j+1] = dist + min;
        }
    }


    path_len = x_size > y_size ? x_size+2 : y_size+2;
    int** path = (int**)malloc(2 * sizeof(int*));
    for (int i = 0; i < 2; i ++) {
        path[i] = (int*)malloc(path_len * sizeof(int));
    }
    
    int i = x_size;
    int j = y_size;
    path[0][0] = x_size - 1;
    path[1][0] = y_size - 1;
    int k = 1;  // index
    while(i > 1 || j > 1)
    {
        if(i == 1) {
            --j;
        } else if(j == 1) {
            --i;
        } else {
            min = dists[i - 1][j - 1];
            if(dists[i - 1][j] < min)
                min = dists[i - 1][j];
            if(dists[i][j - 1] < min)
                min = dists[i][j - 1];

            if(dists[i - 1][j - 1] == min) {
                --i;
                --j;
            } else if(dists[i - 1][j] == min) {
                --i;
            } else {
                --j;
            }
        }
        path[0][k] = i - 1;
        path[1][k] = j - 1;
        ++k;
    }
    path[0][k] = 0;
    path[1][k] = 0;

    return path;
}