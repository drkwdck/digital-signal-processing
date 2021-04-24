#include<complex>
#include<vector>
#include <string>

namespace cmn {
    using signal = std::vector<std::complex<double>>;

    void GenerateSignalIntoFile(const std::string fileName, const int N, const int sRand);
    signal ReadSignalFromFile(const std::string fileName);
    double MAE(signal a, signal b);
    signal GenerateSample(const int N, const int sRand);
}
