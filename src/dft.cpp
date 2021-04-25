#include <complex>
#include <math.h>

#include "common.h"
#include "dft.h"

// ДПФ
cmn::signal dft::dft(const cmn::signal &x) {
    size_t N = x.size();
    cmn::signal y(N, 0);

    for(size_t k = 0; k < N; ++k) {
        for(size_t j = 0; j < N; ++j) {
            y[k] += x[j] * std::exp(std::complex<double>(0, (-2 * M_PI * k * j) / N));
        }

        y[k] /= sqrt(N);
    }

    return y;
}

// ОДПФ
cmn::signal dft::idft(const cmn::signal &y) {
    size_t N = y.size();
    std::vector<std::complex<double>> x(N, 0);

    for(size_t k = 0; k < N; ++k) {
        for(size_t j = 0; j < N; ++j) {
            x[k] += y[j] * std::exp(std::complex<double>(0, ( 2 * M_PI * k * j) / N));
        }

        x[k] /= std::sqrt(N);
    }

    return x;
}
