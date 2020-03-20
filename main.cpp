#include <iostream>

#include "DFT.h"
#include "WaveFactory.h"

int getMaxIdx(ComplexNumberSeries series) {
    double maxValue = 0;
    int maxIdx = 0;
    for (int idx = 0; idx < series.size(); idx++) {
        ComplexNumber num = series.at(idx);
        double frequencyDomainValue = abs(num);
        if (frequencyDomainValue > maxValue) {
            maxValue = frequencyDomainValue;
            maxIdx = idx;
        }
    }
    return maxIdx;
}

int main() {
    double frequency = 1.5;
    int amplitude = 1;
    int sampleRate = 2000;
    double duration = 5;
    ComplexNumberSeries timeDomainWave = WaveFactory::generateSineWaveComplex(
            frequency,
            amplitude,
            sampleRate,
            duration);
    DFT dft(timeDomainWave);
    dft.fourierTransform();
    ComplexNumberSeries halfSeries;
    for (int idx = 0; idx < dft.getSeries().size() / 2; idx++) {
        halfSeries.emplace_back(dft.getSeries().at(idx));
    }
    std::cout << "Most probable frequency: "
            << getMaxIdx(halfSeries) / duration
            << std::endl;
    return 0;
}
