#include "WaveFactory.h"
#include "NyquistLimitException.h"

auto WaveFactory::generateSineWaveReal(double frequency, double amplitude, double sampleRate, double duration) -> std::vector<double> {
    if (2 * frequency > sampleRate) {
        throw NyquistLimitException();
    }
    int numberOfSamples = static_cast<int>(sampleRate * duration);
    std::vector<double> outSamples;
    for (int sampleIdx = 0; sampleIdx < numberOfSamples; sampleIdx++) {
        double sample = amplitude * sin(2 * M_PI * frequency * sampleIdx / sampleRate);
        outSamples.emplace_back(sample);
    }
    return outSamples;
}

auto WaveFactory::generateSineWaveComplex(double frequency, double amplitude, double sampleRate,
                                          double duration) -> std::vector<std::complex<double>> {
    std::vector<std::complex<double>> outSamples;
    for (auto iter : generateSineWaveReal(frequency, amplitude, sampleRate, duration)) {
        std::complex<double> complexed (iter, 0);
        outSamples.emplace_back(complexed);
    }
    return outSamples;
}
