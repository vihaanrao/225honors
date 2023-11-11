
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// recursive function to solve the 0/1 knapsack problem
int knapsackRecursive(const vector<int>& values, const vector<int>& weights, int capacity, int n) {
    if (n == 0 || capacity == 0) return 0;
    if (weights[n - 1] > capacity)
        return knapsackRecursive(values, weights, capacity, n - 1);
    return max(
        values[n - 1] + knapsackRecursive(values, weights, capacity - weights[n - 1], n - 1),
        knapsackRecursive(values, weights, capacity, n - 1)
    );
}

// dynamic programming function to solve the 0/1 knapsack problem
int knapsackDP(const vector<int>& values, const vector<int>& weights, int capacity) {
    int n = values.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (weights[i - 1] <= w)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][capacity];
}

int main() {
    // expanded set of item values and weights
    vector<int> values = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> capacities = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100}; // expanded capacities

    cout << "Approach\tCapacity\tExecution Time (µs)" << endl;

    for (int capacity : capacities) {
        int n = values.size();

        // measure time for recursive approach
        auto start = high_resolution_clock::now();
        knapsackRecursive(values, weights, capacity, n);
        auto stop = high_resolution_clock::now();
        auto durationRecursive = duration_cast<microseconds>(stop - start).count();

        // measure time for dynamic programming approach
        start = high_resolution_clock::now();
        knapsackDP(values, weights, capacity);
        stop = high_resolution_clock::now();
        auto durationDP = duration_cast<microseconds>(stop - start).count();

        // output the results in a table format
        cout << "Recursive\t" << capacity << "\t\t" << durationRecursive << endl;
        cout << "DP\t\t" << capacity << "\t\t" << durationDP << endl;
    }

    return 0;
}
