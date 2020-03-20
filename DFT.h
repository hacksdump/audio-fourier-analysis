#ifndef FOURIER_DFT_H
#define FOURIER_DFT_H

#include <cmath>
#include <vector>
#include <complex>

typedef std::complex<double> ComplexNumber;
typedef std::vector<ComplexNumber> ComplexNumberSeries;

class DFT {
private:
    ComplexNumberSeries mSampleSeries;
public:
    explicit DFT(ComplexNumberSeries inSamples);
    auto getSeries() -> ComplexNumberSeries;
    void fourierTransform();
    void inverseFourierTransform();
    void setSeries(ComplexNumberSeries inSamples);
};


#endif //FOURIER_DFT_H
