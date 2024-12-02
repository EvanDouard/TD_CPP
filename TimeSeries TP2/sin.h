#ifndef SIN_H
#define SIN_H

#include <vector>
#include <cmath>
  // Inclure TimeSeriesGenerator pour la classe de base

class SinWaveGenerator : public TimeSeriesGenerator {
public:
    SinWaveGenerator(double frequency = 1.0, double amplitude = 1.0)
        : frequency_(frequency), amplitude_(amplitude) {}

    std::vector<double> generateTimeSeries(int n) override {
        std::vector<double> series;
        for (int i = 0; i < n; ++i) {
            series.push_back(amplitude_ * sin(2 * M_PI * frequency_ * i / n));
        }
        return series;
    }

private:
    double frequency_;
    double amplitude_;
};

#endif  // SIN_H
