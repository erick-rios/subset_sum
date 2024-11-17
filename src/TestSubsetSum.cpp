#include "SubsetSum.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

/**
 * @brief Generate a random instance of the subset sum problem.
 * 
 * Generates a random instance of the subset sum problem with 10 random integers
 * between 1 and 300 and a random threshold value between 100 and 500.
 * 
 * @param S Vector to store the random integers.
 * @param t Threshold value.
 * @return void
 */
void generateInstance(std::vector<int>& S, int& t) {
    S.clear();
    for (int i = 0; i < 10; ++i) {
        S.push_back(rand() % 300 + 1); // Random integers between 1 and 300
    }
    t = rand() % 400 + 100; // Random threshold between 100 and 500
}

/**
 * @brief Compute the optimal subset sum for a given set of integers.
 * 
 * Computes the optimal subset sum for a given set of integers S and a threshold value t.
 * 
 * @param S Set of integers.
 * @param t Threshold value.
 * @return std::vector<int> Vector of optimal subset sums.
 * 
 */
std::vector<int> computeOptimalSubsetSum(const std::vector<int>& S, int t) {
    std::set<int> subsets = {0};
    for (int x : S) {
        std::set<int> newSubsets;
        for (int s : subsets) {
            if (s + x <= t) {
                newSubsets.insert(s + x);
            }
        }
        subsets.insert(newSubsets.begin(), newSubsets.end());
    }
    return std::vector<int>(subsets.begin(), subsets.end());
}

/**
 * @brief Run a test suite to validate the approximation algorithm.
 * 
 * Runs a test suite to validate the approximation algorithm for the subset sum problem.
 * 
 * @return void
 */
void testConditions() {
    for (int test = 1; test <= 5; ++test) { // Run 5 tests
        // Step 1: Generate random instance
        std::vector<int> S;
        int t;
        generateInstance(S, t);

        // Print instance
        std::cout << "\nTest " << test << ":\n";
        std::cout << "S = ";
        for (int s : S) std::cout << s << " ";
        std::cout << "\nt = " << t << std::endl;

        // Step 2: Run approximation algorithm
        double epsilon = 0.1;
        SubsetSum subsetSum(S, t, epsilon);
        int result = subsetSum.approxSubsetSum();

        // Step 3: Validate output
        std::cout << "Validating result...\n";
        bool isValid = true;

        // Compute optimal solution for validation
        std::vector<int> optimalSums = computeOptimalSubsetSum(S, t);
        int optimalSum = *std::max_element(optimalSums.begin(), optimalSums.end());

        if (result > t || result < static_cast<int>(optimalSum / (1 + epsilon))) {
            std::cout << "FAIL: Approximation result (" << result
                      << ") does not meet requirements.\n";
            isValid = false;
        }

        if (isValid) {
            std::cout << "PASS: Approximation result is valid. Result = " << result << "\n";
        }
    }
}

/**
 * @brief Main function to run the test suite.
 * 
 * Main function to run the test suite for the approximation algorithm for the subset sum problem.
 */
int main() {
    std::srand(std::time(0)); // Seed random number generator
    testConditions();         // Run the test suite
    return 0;
}

