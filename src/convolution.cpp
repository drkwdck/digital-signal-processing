#include "common.h"
#include "convolution.h"
#include "fft.h"

// Если ветокры разных размеров, расширяет их, заполняя нулями
void NormalizeVectors(cmn::signal a, cmn::signal b) {
    
}

cmn::signal conv::Convolution(const cmn::signal a, const cmn::signal b) {
    cmn::signal a_copy(a);
    cmn::signal b_copy(b);

    if (a_copy.size() > b_copy.size()) {
        b_copy.resize(a.size(), 0);
    }

    if (b_copy.size() > a_copy.size()) {
        a_copy.resize(b_copy.size(), 0);
    }

    size_t N = a_copy.size();
    auto result = cmn::signal(2 * N - 1, 0);

    for (size_t k = 0; k < 2 * N - 1; ++k) {
        for (size_t j = 0; j < N - 1; ++j) {
            if (j >= N || k - j >= N || k - j < 0) {
                continue;
            }

            result[k] += a_copy[j] * b_copy[k - j];
        }
    }

    return result;
}

cmn::signal conv::FastConvolution(const cmn::signal a, const cmn::signal b) {
    cmn::signal a_copy(a);
    cmn::signal b_copy(b);
    size_t N = a_copy.size() > b_copy.size() ? a.size() : b.size();
    a_copy.resize(2 * N - 1, 0);
    b_copy.resize(2 * N - 1, 0);
    fft::fft(a_copy);
    fft::fft(b_copy);
    auto result = cmn::signal(2 * N - 1, 0);

    for (size_t i = 0; i < result.size(); ++i) {
        result[i] =  sqrt(2 * N) * a_copy[i] * b_copy[i];   
    }

    return result;
}
