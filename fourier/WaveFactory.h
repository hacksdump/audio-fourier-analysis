#ifndef FOURIER_WAVEFACTORY_H
#define FOURIER_WAVEFACTORY_H

#include <cmath>
#include <vector>
#include <exception>
#include <complex>

class WaveFactory {
public:
    auto generateSineWaveReal(double frequency, double amplitude, double sampleRate, double duration) -> std::vector<double>;
    auto generateSineWaveComplex(double frequency, double amplitude, double sampleRate, double duration) -> std::vector<std::complex<double>>;
};


#endif //FOURIER_WAVEFACTORY_H
