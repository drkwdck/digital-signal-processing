#include <iostream>
#include "Utils.h"
#include "DiscreteFourierTransform.h"

int main()
{
    const int signalPoints = 10;
    char* singalFilePath = "./data.txt";
    GenerateSignalIntoFile(singalFilePath, signalPoints, 0);
    std::vector<std::complex<double>> signal = ReadSignalFromFile(singalFilePath);
    std::vector<std::complex<double>> restored_signal = iDFT(DFT(signal));
    std::cout << "Difference between original signal and recovered signal:\n";

    for (size_t i = 0; i < restored_signal.size(); ++i)
    {
        std::cout << restored_signal[i] - signal[i] << std::endl;
    }
}