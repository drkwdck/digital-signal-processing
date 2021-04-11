#include <string>
#include<complex>
#include<vector>

void GenerateSignalIntoFile(const char* fileName, const int N, const int sRand);
std::vector<std::complex<double>> ReadSignalFromFile(const char* fileName);