#include <cstdlib>
#include <iostream>
#include <complex>
#include <vector>
#include <fstream>
#include "Utils.h"

void GenerateSignalIntoFile(const char* fileName, const int N, const int sRand)
{
    srand(sRand);
    std::ofstream fileStream(fileName);

    for (size_t i = 0; i < N; ++i)
    {
        fileStream << ((double)(rand() % 100 )) / 10 << " " << ((double)(rand() % 100)) / 10 << '\n';
    }

    fileStream.close(); 
}

std::vector<std::complex<double>> GenerateSample(const int N, const int sRand)
{
    srand(sRand);
    std::vector<std::complex<double>> sample;

    for (int i = 0; i < N; ++i)
    {
        double real = ((double)(rand() % 100 )) / 10;
        double imag = ((double)(rand() % 100)) / 10;
        sample.push_back(std::complex<double>(real, imag)); 
    }

    return sample;
}

std::vector<std::complex<double>> ReadSignalFromFile(const char* fileName)
{
    std::ifstream fileStream(fileName);
    std::vector<std::complex<double>> signal;

    double realSignalPart;
    double imagSingalPart;
    
    if (fileStream.eof()) { return signal; }

    while (true)
    {
        fileStream >> realSignalPart >> imagSingalPart;
        if (fileStream.eof()) { break; }
        signal.push_back(std::complex<double>(realSignalPart, imagSingalPart));
    }
    
    return signal;
}

double MAE(std::vector<std::complex<double>> a, std::vector<std::complex<double>> b)
{
    double result = 0;

    for (size_t i = 0; i < b.size(); ++i)
    {
        result += abs(a[i] - b[i]);
    }

    return result / a.size();
}
