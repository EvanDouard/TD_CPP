// knn.h
#include <vector>
#include <string>
#include <iostream>
#include <cmath>

class KNN {
public:
    KNN(int k, const std::string& distanceType) : k_(k), distanceType_(distanceType) {}

    double evaluate(const TimeSeriesDataset& trainData, const TimeSeriesDataset& testData, const std::vector<int>& ground_truth) {
        int correctPredictions = 0;
        const auto& trainDataSeries = trainData.getData();
        const auto& trainLabels = trainData.getLabels();
        const auto& testDataSeries = testData.getData();

        for (size_t i = 0; i < testDataSeries.size(); ++i) {
            int predictedLabel = predictLabel(testDataSeries[i], trainDataSeries, trainLabels);
            if (predictedLabel == ground_truth[i]) {
                correctPredictions++;
            }
        }
        return static_cast<double>(correctPredictions) / testDataSeries.size();
    }

private:
    int k_;
    std::string distanceType_;

    double euclideanDistance(const std::vector<double>& a, const std::vector<double>& b) const {
        double sum = 0.0;
        for (size_t i = 0; i < a.size(); ++i) {
            sum += (a[i] - b[i]) * (a[i] - b[i]);
        }
        return sqrt(sum);
    }

    int predictLabel(const std::vector<double>& testSeries, const std::vector<std::vector<double>>& trainSeries, const std::vector<int>& trainLabels) {
        double minDistance = euclideanDistance(testSeries, trainSeries[0]);
        int label = trainLabels[0];
        for (size_t i = 1; i < trainSeries.size(); ++i) {
            double distance = euclideanDistance(testSeries, trainSeries[i]);
            if (distance < minDistance) {
                minDistance = distance;
                label = trainLabels[i];
            }
        }
        return label;
    }
};
