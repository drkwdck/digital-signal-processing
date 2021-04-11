#include <vector>
#include <complex>
#include <math.h>
#include "DiscreteFourierTransform.h"

// ДПФ
std::vector<std::complex<double> > DFT(const std::vector<std::complex<double> > &x)
{
    size_t N = x.size();
    std::vector<std::complex<double> > y(N, 0);

    for(size_t k = 0; k < N; ++k)
    {
        for(size_t j = 0; j < N; ++j)
        {
            y[k] += x[j] * std::exp(std::complex<double>(0, (-2 * M_PI * k * j) / N));
        }

        y[k] /= sqrt(N);
    }

    return y;
}

// ОДПФ
std::vector<std::complex<double> > iDFT(const std::vector<std::complex<double> > &y)
{
    size_t N = y.size();
    std::vector<std::complex<double> > x(N, 0);

    for(size_t k = 0; k < N; ++k)
    {
        for(size_t j = 0; j < N; ++j)
        {
            x[k] += y[j] * std::exp(std::complex<double>(0, ( 2 * M_PI * k * j) / N));
        }

        x[k] /= std::sqrt(N);
    }

    return x;
}
