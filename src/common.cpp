#include <cstdlib>
#include <iostream>
#include <complex>
#include <fstream>
#include <string>

#include "common.h"

void cmn::GenerateSignalIntoFile(const std::string file_name, const int N, const int s_rand) {
    srand(s_rand);
    std::ofstream file_stream(file_name);

    for (size_t i = 0; i < N; ++i) {
        file_stream << ((double)(rand() % 100 )) / 10 << " " << ((double)(rand() % 100)) / 10 << '\n';
    }

    file_stream.close(); 
}

cmn::signal cmn::GenerateSample(const int N, const int s_rand) {
    srand(s_rand);
    cmn::signal sample;

    for (int i = 0; i < N; ++i) {
        double real = ((double)(rand() % 100 )) / 10;
        double imag = ((double)(rand() % 100)) / 10;
        sample.push_back(std::complex<double>(real, imag)); 
    }

    return sample;
}

cmn::signal cmn::ReadSignalFromFile(const std::string file_name) {
    std::ifstream file_stream(file_name);
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

double cmn::MAE(cmn::signal a, cmn::signal b) {
    double result = 0;

    for (size_t i = 0; i < b.size(); ++i) {
        result += abs(a[i] - b[i]);
    }

    return result / a.size();
}
