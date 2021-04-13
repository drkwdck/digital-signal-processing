#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include "Utils.h"
#include "DiscreteFourierTransform.h"
#include "FastFourierTransform.h"



int main()
{
    // Задание №3
    const int signalPoints = 16;
    char* singalFilePath = "./data.txt";
    GenerateSignalIntoFile(singalFilePath, signalPoints, 0);

    auto signal = ReadSignalFromFile(singalFilePath);
    auto restored_signal = DFT(signal);
    std::cout << "Разница между X и ОДПФ(ДПФ(X)) MAE = " << MAE(signal, iDFT(restored_signal)) << std::endl;

    auto singalCopy1 = std::vector<std::complex<double>>(signal.size(), 0);
    for (size_t i = 0; i < singalCopy1.size(); ++i)
    {
        singalCopy1[i] = std::complex<double>(signal[i].real(), signal[i].imag());
    }

    FastFourierTransform(signal);
    std::cout << "Разница между ДПФ(X) и БПФ(X) MAE = "<< MAE(signal, restored_signal)  << std::endl;
    FastFourierTransform(signal, true);

    std::cout << "Разница между X и ОБПФ(БПФ(X)) MAE = " << MAE(singalCopy1, signal) << std::endl;
    signal.clear();
    singalCopy1.clear();
    restored_signal.clear();

    // Задание №4
    // time_t start, end;
    for (int i = 10; i <= 1000; i *= 10)
    {
        auto x = GenerateSample(i, 0);
        clock_t tStart = clock();
        DFT(x);
        std::cout << std::fixed << double(clock() - tStart)   << " ";
        x.clear();
    }

    std::cout << std::endl;

    // std::vector<double> timesDelayFFT;
    // for (int i = 100; i < 1000; i *= 10)
    // {
    //     auto x = GenerateSample(i, 0);
    //     time(&start);
    //     DFT(x);
    //     time(&end);
    //     timesDelayFFT.push_back(end - start);
    // }
    // fileStream  = std::ofstream("./time_fft.txt");
    // for (size_t i = 0; i < timesDelayFFT.size(); ++i)
    // {
    //     fileStream << timesDelayFFT[i] << '\n';
    // }
    // fileStream.close();

    return 0;
}
