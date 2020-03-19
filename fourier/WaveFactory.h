#ifndef FOURIER_WAVEFACTORY_H
#define FOURIER_WAVEFACTORY_H

#include <cmath>
#include <vector>
#include <exception>
#include <complex>

class WaveFactory {
public:
    static auto generateSineWaveReal(double frequency, double amplitude, double sampleRate, double duration) -> std::vector<double>;
    static auto generateSineWaveComplex(double frequency, double amplitude, double sampleRate, double duration) -> std::vector<std::complex<double>>;
};


#endif //FOURIER_WAVEFACTORY_H
