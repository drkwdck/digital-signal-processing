#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include <string>

#include "common.h"
#include "dft.h"
#include "fft.h"

int main() {
    // Задание №3
    const int signal_points_count = 1024;
    std::string signal_fie_path = "./data.txt";
    cmn::GenerateSignalIntoFile(signal_fie_path, signal_points_count, 0);
    auto signal = cmn::ReadSignalFromFile(signal_fie_path);
    auto restored_signal = dft::DFT(signal);
    std::cout << "Разница между X и ОДПФ(ДПФ(X)) MAE = " << cmn::MAE(signal, dft::iDFT(restored_signal)) << std::endl;

    cmn::GenerateSignalIntoFile(signal_fie_path, signal_points_count, 0);
    auto signalCopy = cmn::ReadSignalFromFile(signal_fie_path);
    fft::fft(signal);
    std::cout << "Разница между ДПФ(X) и БПФ(X) MAE = "<< cmn::MAE(signal, restored_signal)  << std::endl;
    signal = cmn::ReadSignalFromFile(signal_fie_path);

    // для matlab
    std::ofstream file_stream("fft.txt");
    auto signal_to_error = cmn::ReadSignalFromFile("data_error.txt");
    file_stream.precision(17);
    fft::fft(signal_to_error);

    for (size_t i = 0; i < signal_to_error.size(); ++i) {
        file_stream << signal_to_error[i].real() << " " << signal_to_error[i].imag() << '\n';
    }

    file_stream.close();

    fft::fft(signalCopy);
    fft::fft(signalCopy, true);
    std::cout << "Разница между X и ОБПФ(БПФ(X)) MAE = " << cmn::MAE(signal, signalCopy) << std::endl;
    signal_to_error.clear();
    signalCopy.clear();
    restored_signal.clear();

    // Задание №4
    clock_t start, end;
    
    // Замеры времени для ДПФ
    // file_stream  = std::ofstream("./time_dft.txt");
    // for (int i = 256; i < 256 * 32; i *= 2)
    // {
    //     auto x = GenerateSample(i, 0);
    //     start = clock();
    //     DFT(x);
    //     end = clock();
    //     file_stream << double(end - start) / CLOCKS_PER_SEC << " ";
    // }
    // file_stream.close();

    // // Замеры для БПФ
    // file_stream  = std::ofstream("./time_fft.txt");
    // for (int i = 256; i < 256 * 32; i *= 2)
    // {
    //     auto x = GenerateSample(i, 0);
    //     start = clock();
    //     fft(x);
    //     end = clock();
    //     file_stream << double(end - start) / CLOCKS_PER_SEC << " ";
    // }
    // file_stream.close();

    return 0;
}
