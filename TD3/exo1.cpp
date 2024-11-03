#include<iostream>
#include<vector>
#include<map>

using namespace std;

void countFrequencyBruteForce(const vector<int>& number) {
    vector<int> numbers = number; 
    int n = numbers.size(); 
    vector<bool> alreadyCounted(n, false);

    for (int i = 0; i < n; i++) {
        if (alreadyCounted[i]) {
            continue; 
        }

        int count = 0; 
        for (int j = 0; j < n; j++) {
            if (numbers[j] == numbers[i]) {
                count++;
                alreadyCounted[j] = true; 
            }
        }
        cout << numbers[i] << " apparaît " << count << " fois." << endl;
    }
}

map<int, int> countFrequencyOptimal(const vector<int>& numbers) {
    map<int, int> frequencyMap; 

    for (int num : numbers) {
        frequencyMap[num]++;
    }

    return frequencyMap; 
}

int main() {
    vector<int> numbers = {1, 2, 3, 2, 4, 1, 5, 5, 6};

    cout << "Fréquences (Brute Force) :" << endl;
    countFrequencyBruteForce(numbers);

    cout << "\nFréquences (Optimal) :" << endl;
    map<int, int> frequencyMapOptimal = countFrequencyOptimal(numbers);
    
    for (const auto& entry : frequencyMapOptimal) {
        cout << entry.first << " apparaît " << entry.second << " fois." << endl;
    }

    return 0;
}
