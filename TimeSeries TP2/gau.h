#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>



// GaussianGenerator, générant une série gaussienne avec Box-Muller
class GaussianGenerator : public TimeSeriesGenerator {
public:
    GaussianGenerator(float mean = 0, float stddev = 1) : mean_(mean), stddev_(stddev) {}

    std::vector<double> generateTimeSeries(int n) override {
        std::vector<double> series;
        for (int i = 0; i < n; i += 2) {
            double u1 = static_cast<double>(std::rand()) / RAND_MAX;
            double u2 = static_cast<double>(std::rand()) / RAND_MAX;
            double z0 = sqrt(-2.0 * log(u1)) * cos(2 * M_PI * u2) * stddev_ + mean_;
            double z1 = sqrt(-2.0 * log(u1)) * sin(2 * M_PI * u2) * stddev_ + mean_;
            series.push_back(z0);
            if (i + 1 < n) series.push_back(z1);
        }
        return series;
    }

private:
    float mean_;
    float stddev_;
};



// StepGenerator, 
class StepGenerator : public TimeSeriesGenerator {
public:
    StepGenerator(float mean = 0, float stddev = 1) : mean_(mean), stddev_(stddev) {}

    std::vector<double> generateTimeSeries(int n) override {
        std::vector<double> series(n, 0); // Initialize vector with size n
        for (int i = 0; i < n; ++i) {
            double val = static_cast<double>(std::rand()) / RAND_MAX * 100; // Generate random value
            double prob = static_cast<double>(std::rand()) / RAND_MAX; // Generate probability
            if (prob > 0.50) {
                series[i] = val; // Assign new value
            } else if (i > 0) {
                series[i] = series[i - 1]; // Repeat previous value
            }
        }
        return series;
    }

private:
    float mean_;
    float stddev_;
};
