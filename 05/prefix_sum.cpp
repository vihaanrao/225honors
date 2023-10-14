#include <iostream>
#include <vector>
#include <omp.h>
#include <chrono>
#include <fstream>

void parallel_prefix_sum(std::vector<int>& arr, int N) {
    #pragma omp parallel for
    for (int i = 1; i < N; ++i) {
        arr[i] += arr[i - 1];
    }
}

void measure_performance(int N, int num_threads, std::ofstream& file) {
    std::vector<int> arr(N, 1); // Initialize array with ones

    omp_set_num_threads(num_threads);

    auto start = std::chrono::high_resolution_clock::now();
    parallel_prefix_sum(arr, N);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    file << N << "," << num_threads << "," << duration.count() << std::endl;
}

int main() {
    std::vector<int> sizes = {256, 512, 1024};
    std::vector<int> thread_counts = {1, 2, 4, 8};

    std::ofstream file("prefix_sum_performance.csv");
    file << "ArraySize,ThreadCount,TimeMillis" << std::endl;

    for (int N : sizes) {
        for (int t : thread_counts) {
            measure_performance(N, t, file);
        }
    }

    file.close();

    return 0;
}
