
#include <iostream>
#include <vector>
using namespace std;
class TimeSeriesGenerator {
public:
    TimeSeriesGenerator() : seed_(time(0)) { std::srand(seed_); }
    virtual std::vector<double> generateTimeSeries(int n) = 0;

protected:
    int seed_;
};



class TimeSeriesDataset {
public:
    TimeSeriesDataset(bool training, bool normalized) : training_(training), normalized_(normalized) {}

    void addTimeSeries(const std::vector<double>& series, int label = -1) {
        data_.push_back(series);
        labels_.push_back(label);
    }

    const std::vector<std::vector<double>>& getData() const { return data_; }
    const std::vector<int>& getLabels() const { return labels_; }

private:
    bool training_;
    bool normalized_;
    std::vector<std::vector<double>> data_;
    std::vector<int> labels_;
};
