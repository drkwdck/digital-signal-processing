#include <cstdlib>
#include <iostream>
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