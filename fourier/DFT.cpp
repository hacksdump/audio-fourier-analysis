#include "DFT.h"

#include <utility>

DFT::DFT(std::vector<std::complex<double>> inSamples): mTimeDomainSignalSamples{std::move(inSamples)}{}

std::vector<std::complex<double> > DFT::computeDft() {
    const std::complex<double> iota(0, 1);
    std::vector<std::complex<double>> output;
    size_t n = mTimeDomainSignalSamples.size();
    for (size_t k = 0; k < n; k++) {
        std::complex<double> sum(0.0, 0.0);
        for (size_t t = 0; t < n; t++) {
            sum += mTimeDomainSignalSamples[t] * std::exp(- 2 * M_PI * iota *
                    static_cast<double>(t) * static_cast<double>(k) / static_cast<double>(n));
        }
        output.push_back(sum);
    }
    return output;
}

auto DFT::getFourierTransform() -> std::vector<std::complex<double>> {
    if (mFourierTransformSamples.empty() || !bCalculatedDft) {
        printf("calculating dft");
        mFourierTransformSamples = computeDft();
        bCalculatedDft = true;
    }
    return mFourierTransformSamples;
}

void DFT::setInputSignal(std::vector<std::complex<double>> inSamples) {
    mTimeDomainSignalSamples = std::move(inSamples);
    bCalculatedDft = false;
}
