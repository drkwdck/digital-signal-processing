#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include <string>

#include "common.h"
#include "dft.h"
#include "fft.h"
#include "convolution.h"

int main() {
    const int signal_points_count = 1024;
    std::string signal_fie_path = "./signal.txt";
    cmn::WriteSignalToFile(cmn::GenerateSignal(signal_points_count, 0), signal_fie_path);
    auto signal = cmn::ReadSignalFromFile(signal_fie_path);
    
    
    // Сравнение исходного сигнала и сигнала, восстановленного после дискретного преобразования Фурье
    // с помощью обратного дискретного преобразования Фурье
    auto dft_transformed_signal = dft::DFT(signal);
    std::cout << "Разница между X и ОДПФ(ДПФ(X)): MSE = " << cmn::MSE(signal, dft::iDFT(dft_transformed_signal)) << std::endl;

    // Сравнение исходного сигнала и сигнала, восстановленного после быстрого преобразования Фурье
    // с помощью обратного быстрого преобразования Фурье
    cmn::signal signal_copy(signal);
    fft::fft(signal_copy);
    fft::fft(signal_copy, true);
    std::cout << "Разница между X и ОБПФ(БПФ(X)): MSE = " << cmn::MSE(signal, signal_copy) << std::endl;    

    // Сравнение результатов дискретного преобразования Фурье и быстрого преобразования Фурье
    fft::fft(signal);
    std::cout << "Разница между ДПФ(X) и БПФ(X) MSE = "<< cmn::MSE(signal, dft_transformed_signal)  << std::endl;

    // Запись результат БПФ в файл для того, чтобы сравнить с реализацией в Matlab
    cmn::WriteSignalToFile(signal, "matlab/cpp_fft_result.txt");


    // Сравнение времени БПФ и ДПФ
    clock_t start, end;
    
    // Замеры времени для ДПФ
    auto file_stream  = std::ofstream("./matlab/time_dft.txt");
    auto file_stream_N = std::ofstream("./matlab/N.txt");
    
    for (int i = 256; i < 256 * 64; i *= 2) {
        auto x = cmn::GenerateSignal(i, 0);
        start = clock();
        dft::DFT(x);
        end = clock();
        file_stream << double(end - start) / CLOCKS_PER_SEC << '\n';
        file_stream_N << i << '\n';
    }

    file_stream.close();

    // Замеры вермени для БПФ
    file_stream  = std::ofstream("./matlab/time_fft.txt");

    for (int i = 256; i < 256 * 64; i *= 2) {
        auto x = cmn::GenerateSignal(i, 0);
        start = clock();
        fft::fft(x);
        end = clock();
        file_stream << double(end - start) / CLOCKS_PER_SEC << '\n';
    }

    file_stream.close();

    auto a = cmn::GenerateSignal(signal_points_count, 0);
    auto b = cmn::GenerateSignal(signal_points_count, 0);
    auto convolution = conv::Convolution(a, b);
    auto conv2 = conv::FastConvolution(a, b);
    std::cout << cmn::MSE(convolution, conv2) << std::endl;

    return 0;
}
