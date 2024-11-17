#ifndef SUBSET_SUM_H
#define SUBSET_SUM_H

#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <cmath>

class SubsetSum {
private:
    /**
    * Instance variables
    */
    std::vector<int> S;  
    int t;               
    double epsilon;

    /**
     * Merge operation
     */
    std::vector<int> merge(const std::vector<int>& L, int x);
    std::vector<int> trim(const std::vector<int>& L, double delta);
    std::vector<int> dropGreater(const std::vector<int>& L, int t);

public:
    /**
     * Constructor
     */
    SubsetSum(const std::vector<int>& S, int t, double epsilon);

    /**
     * Approximation algorithm execution
     */
    int approxSubsetSum();

    /**
     * Print generated lists
     */
    void printLists(const std::vector<std::vector<int>>& lists);
};

#endif
