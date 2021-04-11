#include <iostream>
#include "Utils.h"
#include "DiscreteFourierTransform.h"
#include "FastFourierTransform.h"

int main()
{
    const int signalPoints = 10;
    char* singalFilePath = "./data.txt";
    GenerateSignalIntoFile(singalFilePath, signalPoints, 0);
    auto signal = ReadSignalFromFile(singalFilePath);
    auto restored_signal = iDFT(DFT(signal));
    // std::cout << "Difference between original signal and recovered signal:\n";

    for (size_t i = 0; i < restored_signal.size(); ++i)
    {
        // std::cout << restored_signal[i] - signal[i] << std::endl;
    }

    auto y = DFT(signal);
    FastFourierTransform(signal);

    for (size_t i = 0; i < y.size(); ++i)
    {
        std::cout << y[i] - signal[i] << std::endl;
    }
}
