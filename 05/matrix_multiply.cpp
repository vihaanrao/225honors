#include <iostream>
#include <vector>
#include <omp.h>
#include <chrono>
#include <fstream>

void matrix_multiply(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B, std::vector<std::vector<int>>& C, int N) {
    #pragma omp parallel for
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; j += 4) {
            for (int k = 0; k < N; ++k) {
                int a = A[i][k];
                C[i][j] += a * B[k][j];
                C[i][j+1] += a * B[k][j+1];
                C[i][j+2] += a * B[k][j+2];
                C[i][j+3] += a * B[k][j+3];
            }
        }
    }
}

void measure_performance(int N, int num_threads, std::ofstream& file) {
    std::vector<std::vector<int>> A(N, std::vector<int>(N, 1));
    std::vector<std::vector<int>> B(N, std::vector<int>(N, 2));
    std::vector<std::vector<int>> C(N, std::vector<int>(N, 0));

    omp_set_num_threads(num_threads);

    auto start = std::chrono::high_resolution_clock::now();
    matrix_multiply(A, B, C, N);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    file << N << "," << num_threads << "," << duration.count() << std::endl;
}

int main() {
    std::vector<int> sizes = {256, 512, 1024};
    std::vector<int> thread_counts = {1, 2, 4, 8};

    std::ofstream file("performance_metrics.csv");
    file << "MatrixSize,ThreadCount,TimeMillis" << std::endl;

    for (int N : sizes) {
        for (int t : thread_counts) {
            measure_performance(N, t, file);
        }
    }

    file.close();

    return 0;
}
