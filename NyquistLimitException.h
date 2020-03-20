#ifndef FOURIER_NYQUISTLIMITEXCEPTION_H
#define FOURIER_NYQUISTLIMITEXCEPTION_H

#include <exception>

class NyquistLimitException: public std::exception
{
    [[nodiscard]] const char* what() const noexcept override {
        return "Sampling frequency should be at least double the maximum audio frequency.";
    }
};

#endif //FOURIER_NYQUISTLIMITEXCEPTION_H
