#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include "Utils.h"
#include "DiscreteFourierTransform.h"
#include "FastFourierTransform.h"

int main()
{
    // Задание №3
    const int signalPoints = 1024;
    char* singalFilePath = "./data.txt";
    GenerateSignalIntoFile(singalFilePath, signalPoints, 0);
    auto signal = ReadSignalFromFile(singalFilePath);
    auto restored_signal = DFT(signal);
    std::cout << "Разница между X и ОДПФ(ДПФ(X)) MAE = " << MAE(signal, iDFT(restored_signal)) << std::endl;

    GenerateSignalIntoFile(singalFilePath, signalPoints, 0);
    auto signalCopy = ReadSignalFromFile(singalFilePath);
    FastFourierTransform(signal);
    std::cout << "Разница между ДПФ(X) и БПФ(X) MAE = "<< MAE(signal, restored_signal)  << std::endl;
    signal = ReadSignalFromFile(singalFilePath);

    // для matlab
    std::ofstream fileStream("fft.txt");
    auto signalToError = ReadSignalFromFile("data_error.txt");
    fileStream.precision(17);
    FastFourierTransform(signalToError);
    for (size_t i = 0; i < signalToError.size(); ++i)
    {
        fileStream << signalToError[i].real() << " " << signalToError[i].imag() << '\n';
    }
    fileStream.close();

    FastFourierTransform(signalCopy);
    FastFourierTransform(signalCopy, true);
    std::cout << "Разница между X и ОБПФ(БПФ(X)) MAE = " << MAE(signal, signalCopy) << std::endl;
    signalToError.clear();
    signalCopy.clear();
    restored_signal.clear();


    // Задание №4
    clock_t start, end;
    
    // Замеры времени для ДПФ
    // fileStream  = std::ofstream("./time_dft.txt");
    // for (int i = 256; i < 256 * 32; i *= 2)
    // {
    //     auto x = GenerateSample(i, 0);
    //     start = clock();
    //     DFT(x);
    //     end = clock();
    //     fileStream << double(end - start) / CLOCKS_PER_SEC << " ";
    // }
    // fileStream.close();

    // // Замеры для БПФ
    // fileStream  = std::ofstream("./time_fft.txt");
    // for (int i = 256; i < 256 * 32; i *= 2)
    // {
    //     auto x = GenerateSample(i, 0);
    //     start = clock();
    //     FastFourierTransform(x);
    //     end = clock();
    //     fileStream << double(end - start) / CLOCKS_PER_SEC << " ";
    // }
    // fileStream.close();

    return 0;
}
