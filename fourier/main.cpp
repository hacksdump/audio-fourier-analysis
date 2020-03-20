#include <iostream>

#include "DFT.h"
#include "WaveFactory.h"

int main() {
    ComplexNumberSeries timeDomainWave = WaveFactory::generateSineWaveComplex(300, 1, 800, 1);
    DFT dft(timeDomainWave);
    double maxValue = 0;
    int maxFrequency = 0;
    auto transformValues = dft.getFourierTransform();
    for (int idx = 0; idx < transformValues.size(); idx++) {
        ComplexNumber num = transformValues.at(idx);
        double frequencyDomainValue = abs(num);
        if (frequencyDomainValue > maxValue) {
            maxValue = frequencyDomainValue;
            maxFrequency = idx;
        }
    }
    std::cout << maxFrequency;
    return 0;
}
