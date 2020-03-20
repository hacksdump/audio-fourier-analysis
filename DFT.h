#ifndef FOURIER_DFT_H
#define FOURIER_DFT_H

#include <cmath>
#include <vector>
#include <complex>

typedef std::complex<double> ComplexNumber;
typedef std::vector<ComplexNumber> ComplexNumberSeries;

class DFT {
private:
    ComplexNumberSeries mTimeDomainSignalSamples;
    ComplexNumberSeries mFourierTransformSamples;
    bool bCalculatedDft = false;
    ComplexNumberSeries computeDft();
public:
    explicit DFT(ComplexNumberSeries inSamples);
    auto getFourierTransform() -> ComplexNumberSeries ;
    void setInputSignal(ComplexNumberSeries inSamples);
};


#endif //FOURIER_DFT_H
