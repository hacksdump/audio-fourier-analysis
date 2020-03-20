#include "DFT.h"

#include <utility>

DFT::DFT(std::vector<std::complex<double>> inSamples): mSampleSeries{std::move(inSamples)}{}

ComplexNumberSeries DFT::getSeries() {
    return mSampleSeries;
}

void DFT::fourierTransform() {
    const std::complex<double> iota(0, 1);
    std::vector<std::complex<double>> transform;
    size_t n = mSampleSeries.size();
    for (size_t k = 0; k < n; k++) {
        std::complex<double> sum(0.0, 0.0);
        for (size_t t = 0; t < n; t++) {
            sum += mSampleSeries[t] * std::exp(- 2 * M_PI * iota *
                    static_cast<double>(t) * static_cast<double>(k) / static_cast<double>(n));
        }
        transform.push_back(sum);
    }
    mSampleSeries = transform;
}

void DFT::inverseFourierTransform() {
}

void DFT::setSeries(ComplexNumberSeries inSamples) {
    mSampleSeries = std::move(inSamples);
}
