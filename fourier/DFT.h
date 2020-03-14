#ifndef FOURIER_DFT_H
#define FOURIER_DFT_H

#include <cmath>
#include <vector>
#include <complex>

class DFT {
private:
    std::vector<std::complex<double>> mTimeDomainSignalSamples;
    std::vector<std::complex<double>> mFourierTransformSamples;
    bool bCalculatedDft = false;
    std::vector<std::complex<double>> computeDft();
public:
    explicit DFT(std::vector<std::complex<double>> inSamples);
    auto getFourierTransform() -> std::vector<std::complex<double>>;
};


#endif //FOURIER_DFT_H
