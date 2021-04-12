#include <iostream>
#include "Utils.h"
#include "DiscreteFourierTransform.h"
#include "FastFourierTransform.h"


int main()
{
    const int signalPoints = 16;
    char* singalFilePath = "./data.txt";
    GenerateSignalIntoFile(singalFilePath, signalPoints, 0);

    // пункт а
    auto signal = ReadSignalFromFile(singalFilePath);
    auto restored_signal = DFT(signal);
    std::cout << "Разница между X и ОДПФ(ДПФ(X)): MAE = " << MAE(signal, iDFT(restored_signal)) << std::endl;

    auto singalCopy1 = std::vector<std::complex<double>>(signal.size(), 0);

    for (size_t i = 0; i < singalCopy1.size(); ++i)
    {
        singalCopy1[i] = std::complex<double>(signal[i].real(), signal[i].imag());
    }

    FastFourierTransform(signal);
    std::cout << std::endl << "Разница между "<<MAE(signal,restored_signal)  << std::endl;
    FastFourierTransform(signal, true);
    std::cout << "Разница между X и ОБПФ(БПФ(X)): MAE = " << MAE(singalCopy1, signal) << std::endl;

    // пункт б
}
