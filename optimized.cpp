#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <immintrin.h>
#pragma GCC target("avx2")

using namespace std;


void LUdecomposition(vector<vector<float>>& a, vector<vector<float>>& l, vector<vector<float>>& u, int n) {
    int i = 0, j = 0, k = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (j < i)
                l[j][i] = 0;
            else {
                __m256 sum = _mm256_loadu_ps(&a[j][i]);
                for (k = 0; k < i; k++) {
                    __m256 l_row = _mm256_loadu_ps(&l[j][k]);
                    __m256 u_col = _mm256_loadu_ps(&u[k][i]);
                    __m256 product = _mm256_mul_ps(l_row, u_col);
                    sum = _mm256_sub_ps(sum, product);
                }
                _mm256_storeu_ps(&l[j][i], sum);
            }
        }
        for (j = 0; j < n; j++) {
            if (j < i)
                u[i][j] = 0;
            else if (j == i)
                u[i][j] = 1; 
            else {
                __m256 sum = _mm256_loadu_ps(&a[i][j]);
                for (k = 0; k < i; k++) {
                    __m256 l_row = _mm256_loadu_ps(&l[i][k]);
                    __m256 u_col = _mm256_loadu_ps(&u[k][j]);
                    __m256 product = _mm256_mul_ps(l_row, u_col);
                    sum = _mm256_sub_ps(sum, product);
                }
                __m256 l_ii = _mm256_broadcast_ss(&l[i][i]);
                __m256 u_ji = _mm256_div_ps(sum, l_ii);
                _mm256_storeu_ps(&u[i][j], u_ji);
            }
        }
    }
}

int main() {
    int i = 0, j = 0;

    int n = 4000; 

    vector<vector<float>> a(n, vector<float>(n)), l(n, vector<float>(n)), u(n, vector<float>(n));

    std::srand(static_cast<unsigned>(std::time(nullptr)));
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = static_cast<double>(rand()) / RAND_MAX;
        }
    }




    auto start = std::chrono::high_resolution_clock::now();

    LUdecomposition(a, l, u, n);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << "Execution time: " << duration.count() << " seconds" << std::endl;

    return 0;
}
