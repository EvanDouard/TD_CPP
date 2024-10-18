#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
/*Fonction virtuel pur important et héritage pour td noté*/
class SearchingAlgorithm {
public:
    SearchingAlgorithm();
    virtual ~SearchingAlgorithm() = default;//initialisateur par defaut


    virtual int search(const std::vector<int>&, int) = 0;
    void displaySearchResults(std::ostream&, int, int);

protected:
    int numberComparisons;

    static int totalComparisons;
    static int totalSearch;
    static float averageComparisons;
};

class LinearSearch : public SearchingAlgorithm {
public:
    int search(const std::vector<int>&, int) override;
};

class BinarySearch : public SearchingAlgorithm {
public:
    int search(const std::vector<int>&, int) override; 
};

class JumpSearch : public SearchingAlgorithm {
public:
    int search(const std::vector<int>&, int) override;
};

#endif
