#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include <string>

#include "common.h"
#include "dft.h"
#include "fft.h"

int main() {
    // Сравнение исходного сигнала и сигнала, восстановленного после дискретного преобразования Фурье
    // с помощью обратного дискретного преобразования Фурье
    const int signal_points_count = 16;
    std::string signal_fie_path = "./signal.txt";
    // cmn::WriteSignalToFile(cmn::GenerateSignal(signal_points_count, 0), signal_fie_path);
    auto signal = cmn::ReadSignalFromFile(signal_fie_path);
    auto dft_transformed_signal = dft::DFT(signal);
    std::cout << "Разница между X и ОДПФ(ДПФ(X)): MSE = " << cmn::MSE(signal, dft::iDFT(dft_transformed_signal)) << std::endl;

    // Сравнение результатов дискретного преобразования Фурье и быстрого преобразования Фурье
    fft::fft(signal);
    std::cout << "Разница между ДПФ(X) и БПФ(X) MSE = "<< cmn::MSE(signal, dft_transformed_signal)  << std::endl;

    // Запись результат БПФ в файл для того, чтобы сравнить с реализацией в Matlab
    cmn::WriteSignalToFile(signal, "matlab/cpp_fft_result.txt");

    // для matlab
    // std::ofstream file_stream("fft.txt");
    // auto signal_to_error = cmn::ReadSignalFromFile("data_error.txt");
    // file_stream.precision(17);
    // fft::fft(signal_to_error);

    // for (size_t i = 0; i < signal_to_error.size(); ++i) {
    //     file_stream << signal_to_error[i].real() << " " << signal_to_error[i].imag() << '\n';
    // }
    

    // file_stream.close();

    // fft::fft(signal_copy);
    // fft::fft(signal_copy, true);
    // std::cout << "Разница между X и ОБПФ(БПФ(X)) MSE = " << cmn::MSE(signal, signal_copy) << std::endl;
    // signal_to_error.clear();
    // signal_copy.clear();
    // restored_signal.clear();

    // Задание №4
    clock_t start, end;
    
    // Замеры времени для ДПФ
    // file_stream  = std::ofstream("./time_dft.txt");
    // for (int i = 256; i < 256 * 32; i *= 2)
    // {
    //     auto x = GenerateSignal(i, 0);
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
    //     auto x = GenerateSignal(i, 0);
    //     start = clock();
    //     fft(x);
    //     end = clock();
    //     file_stream << double(end - start) / CLOCKS_PER_SEC << " ";
    // }
    // file_stream.close();

    return 0;
}
