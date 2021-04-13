#include <string>
#include<complex>
#include<vector>

void GenerateSignalIntoFile(const char* fileName, const int N, const int sRand);
std::vector<std::complex<double>> ReadSignalFromFile(const char* fileName);
double MAE(std::vector<std::complex<double>> a, std::vector<std::complex<double>> b);
std::vector<std::complex<double>> GenerateSample(const int N, const int sRand);
