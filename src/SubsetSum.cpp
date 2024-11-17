/**
 * @file SubsetSum.cpp
 * 
 * @brief Implementation of the approximation algorithm for the subset sum problem.
 * 
 * This file contains the implementation of the approximation algorithm for the subset sum problem.
 * 
 * @author Erick Jesús Ríos González
 * @date  16/11/2024
 */
#include "SubsetSum.h"

/**
 * @brief Constructor
 * 
 * Initializes the instance variables of the SubsetSum class.
 * 
 * @param S Set of integers.
 * @param t Threshold value.
 * @param epsilon Approximation factor.
 * 
 * @return void
 */
SubsetSum::SubsetSum(const std::vector<int>& S, int t, double epsilon) 
    : S(S), t(t), epsilon(epsilon) {}

/**
 * @brief Merge operation
 * 
 * Merges a list L with a new element x.
 * 
 * @param L List of integers.
 * @param x New element.
 * 
 * @return std::vector<int> Merged list.
 */
std::vector<int> SubsetSum::merge(const std::vector<int>& L, int x) {
    std::set<int> merged(L.begin(), L.end());
    for (int l : L) {
        merged.insert(l + x);
    }
    return std::vector<int>(merged.begin(), merged.end());
}

/**
 * @brief Trim operation
 * 
 * Trims a list L by removing elements greater than (1 + delta) times the last element.
 * 
 * @param L List of integers.
 * @param delta Trimming factor.
 * 
 * @return std::vector<int> Trimmed list.
 */
std::vector<int> SubsetSum::trim(const std::vector<int>& L, double delta) {
    std::vector<int> trimmed;
    trimmed.push_back(L[0]);

    for (size_t i = 1; i < L.size(); ++i) {
        if (L[i] > trimmed.back() * (1 + delta)) {
            trimmed.push_back(L[i]);
        }
    }
    return trimmed;
}

/**
 * @brief Drop greater operation
 * 
 * Drops elements greater than a threshold value t.
 * 
 * @param L List of integers.
 * @param t Threshold value.
 * 
 * @return std::vector<int> Filtered list.
 */
std::vector<int> SubsetSum::dropGreater(const std::vector<int>& L, int t) {
    std::vector<int> filtered;
    for (int l : L) {
        if (l <= t) {
            filtered.push_back(l);
        }
    }
    return filtered;
}

/**
 * @brief Approximation algorithm execution
 * 
 * Executes the approximation algorithm for the subset sum problem.
 * 
 * @return int Approximated subset sum.
 */
int SubsetSum::approxSubsetSum() {
    int n = S.size();
    double delta = epsilon / (2 * n);
    std::vector<std::vector<int>> lists(n + 1);
    lists[0] = {0};

    for (int i = 1; i <= n; ++i) {
        lists[i] = merge(lists[i - 1], S[i - 1]);
        lists[i] = trim(lists[i], delta);
        lists[i] = dropGreater(lists[i], t);
    }

    printLists(lists);
    return *std::max_element(lists[n].begin(), lists[n].end());
}

/**
 * @brief Print generated lists
 * 
 * Prints the lists generated during the execution of the approximation algorithm.
 * 
 * @param lists Vector of lists.
 * 
 * @return void
 */
void SubsetSum::printLists(const std::vector<std::vector<int>>& lists) {
    for (size_t i = 0; i < lists.size(); ++i) {
        std::cout << "L" << i << ": ";
        for (int num : lists[i]) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}
