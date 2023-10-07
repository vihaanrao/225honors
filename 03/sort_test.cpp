#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <fstream>


void countingSort(std::vector<int>& arr) {
    int max_val = *std::max_element(arr.begin(), arr.end());
    int min_val = *std::min_element(arr.begin(), arr.end());
    std::vector<int> count(max_val - min_val + 1, 0);
    std::vector<int> output(arr.size());

    for(int i : arr) {
        count[i - min_val]++;
    }

    for(int i = 1; i < count.size(); i++) {
        count[i] += count[i-1];
    }

    for(int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - min_val] - 1] = arr[i];
        count[arr[i] - min_val]--;
    }

    arr = output;
}


int main() {
    std::vector<int> test_sizes = {100, 1000, 10000, 100000};
    std::vector<int> max_values = {10, 100, 1000, 10000};

    //open csv file
    std::ofstream outFile("sorting_times.csv");
    if(!outFile.is_open()) {
        std::cerr << "Unable to open file for writing!" << std::endl;
        return 1;
    }
    outFile << "Size,MaxValue,std::sort Time,Counting Sort Time\n"; // Writing header

    std::srand(std::time(nullptr));

    for(int number : test_sizes) {
        for(int max_value : max_values) {
            std::vector<int> arr(number);
            for(int i = 0; i < number; ++i) {
                arr[i] = std::rand() % max_value + 1; 
            }

            // sorting with std::sort
            auto arr_std = arr;
            auto start_std = std::chrono::steady_clock::now();
            std::sort(arr_std.begin(), arr_std.end());
            auto end_std = std::chrono::steady_clock::now();
            std::chrono::duration<double> elapsed_seconds_std = end_std - start_std;

            // sorting with countingSort
            auto arr_counting = arr;
            auto start_counting = std::chrono::steady_clock::now();
            countingSort(arr_counting);
            auto end_counting = std::chrono::steady_clock::now();
            std::chrono::duration<double> elapsed_seconds_counting = end_counting - start_counting;

            // output csv
            outFile << number << "," << max_value << "," << elapsed_seconds_std.count() << "," << elapsed_seconds_counting.count() << "\n";

            std::cout << "Size: " << number << ", MaxValue: " << max_value << "\n";
            std::cout << "std::sort elapsed time: " << elapsed_seconds_std.count() << "s\n";
            std::cout << "countingSort elapsed time: " << elapsed_seconds_counting.count() << "s\n\n";
        }
    }

    outFile.close();
    return 0;
}
