#include "header.h"

// Initialisation des variables statiques
int SearchingAlgorithm::totalComparisons = 0;
int SearchingAlgorithm::totalSearch = 0;
float SearchingAlgorithm::averageComparisons = 0.0;

SearchingAlgorithm::SearchingAlgorithm() : numberComparisons(0) {}

// display result
void SearchingAlgorithm::displaySearchResults(std::ostream& os, int results, int target) {
    totalSearch++;
    
    if (results == -1) {
        os << "Searching for element " << target << " was not successful.\n";
    } else {
        totalComparisons += numberComparisons;
        averageComparisons = static_cast<float>(totalComparisons) / totalSearch;
        os << "Found " << target << " at index " << results 
           << " after " << numberComparisons << " comparisons.\n";
    }
    os << "Average comparisons so far: " << averageComparisons << "\n\n";
}

int LinearSearch::search(const std::vector<int>& vf, int ele) {
    numberComparisons = 0;//nbr de comparaison
    for (size_t i = 0; i < vf.size(); ++i) {//on cherche de manière classique
        numberComparisons++;
        if (vf[i] == ele) {
            return i;
        }
    }
    return -1;
}

int BinarySearch::search(const std::vector<int>& vf, int ele) {
    numberComparisons = 0;
    int left = 0;
    int right = vf.size() - 1;

    while (left <= right) {
        numberComparisons++;
        int mid = left + (right - left) / 2;

        if (vf[mid] == ele) {
            return mid;  // trouvé
        }
        if (vf[mid] < ele) {
            left = mid + 1;  // recherche dans la moitier + droite
        } else {
            right = mid - 1;  // recherche dans la moitier + gauche
        }
    }
    
    return -1;  // Élément non trouvé
}

int JumpSearch::search(const std::vector<int>& vf, int ele) {
    numberComparisons = 0;
    int n = vf.size();
    int step = std::sqrt(n);//demonstration vu pour optimiser la fonction on doit appliquer la racine 
    int prev = 0;

    while (vf[std::min(step, n) - 1] < ele) {
        numberComparisons++;
        prev = step;
        step += std::sqrt(n);
        if (prev >= n) return -1;
    }

    // recherche linéaire
    while (vf[prev] < ele) {
        numberComparisons++;
        prev++;
        if (prev == std::min(step, n)) return -1;
    }

    numberComparisons++;
    if (vf[prev] == ele)
        return prev;

    return -1;
}

int main() {
    std::vector<int> vec = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

    // Linear search test
    LinearSearch linearSearch;
    int target = 11;
    int result = linearSearch.search(vec, target);
    linearSearch.displaySearchResults(std::cout, result, target);

    BinarySearch binarySearch;
    target = 7;
    result = binarySearch.search(vec, target);
    binarySearch.displaySearchResults(std::cout, result, target);
    
    JumpSearch jumpSearch;
    target = 15;
    result = jumpSearch.search(vec, target);
    jumpSearch.displaySearchResults(std::cout, result, target);

    return 0;
}
