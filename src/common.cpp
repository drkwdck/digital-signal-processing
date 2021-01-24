#include <cstdlib>
#include <iostream>
#include <complex>
#include <fstream>
#include <string>

#include "common.h"

cmn::signal cmn::GenerateSignal(const int N, const int s_rand) {
    srand(s_rand);
    cmn::signal sample;

    for (int i = 0; i < N; ++i) {
        double real = ((double)(rand() % 100 )) / 100;
        double imag = ((double)(rand() % 100)) / 100;
        sample.push_back(std::complex<double>(real, imag)); 
    }

    return sample;
}

void cmn::WriteSignalToFile(const cmn::signal signal, const std::string file_name) {
    std::ofstream file_stream(file_name);
    file_stream.precision(17);

    for (size_t i = 0; i < signal.size(); ++i) {
        file_stream << signal[i].real() << " " << signal[i].imag() << '\n';
    }

    file_stream.close(); 
}

cmn::signal cmn::ReadSignalFromFile(const std::string file_name) {
    std::ifstream file_stream(file_name);
    file_stream.precision(17);
    cmn::signal signal;

    double real_signal_part;
    double imag_signal_part;
    
    if (file_stream.eof()) { return signal; }

    while (true) {
        file_stream >> real_signal_part >> imag_signal_part;
        if (file_stream.eof()) { break; }
        signal.push_back(std::complex<double>(real_signal_part, imag_signal_part));
    }
    
    return signal;
}

double cmn::MSE(cmn::signal a, cmn::signal b) {
    double result = 0;

    for (size_t i = 0; i < b.size(); ++i) {
        result += pow(abs(a[i] - b[i]), 2);
    }

    return result / a.size();
}
