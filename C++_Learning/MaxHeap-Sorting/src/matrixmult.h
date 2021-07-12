#ifndef MAXHEAP_SORTING_MATRIXMULT_H
#define MAXHEAP_SORTING_MATRIXMULT_H


// multiply a (n,m) with a (m,p) matrix
auto multiplyMatrices = [](int **m1, int **m2, unsigned int n, unsigned int m, unsigned int p) {
    // initialize result matrix
    int **res = new int *[n];
    for (int i = 0; i < n; i++) {
        res[i] = new int[p];
    }
    for (unsigned int i = 0; i < n; i++) {
        for (unsigned int j = 0; j < p; j++) {
            int sum = 0;
            for (unsigned int k = 0; k < m; k++) {
                sum += m1[i][k] * m2[k][j];
            }
            res[i][j] = sum;
        }
    }
    return res;
};

#endif //MAXHEAP_SORTING_MATRIXMULT_H