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

    auto result = cmn::signal(a_copy.size() * 2  -1, 0);

    for (size_t k = 0; k < result.size(); ++k) {
        for (size_t j = 0; j < a_copy.size(); ++j) {
            if (j >= a_copy.size() || k - j >= a_copy.size() || k - j < 0) {
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
    
    // Найдем ближайшую степень двойки, чтобы расширить вектора для БПФ
    size_t N = 1;
    auto max_vectors_length = a.size() > b.size() ? a.size() : b.size();
    while (N < max_vectors_length) {
        N <<= 1;
    }

    // Увеличиваем N еще в два раза уже для вычисления свертки
    N <<= 1;

    a_copy.resize(N, 0);
    b_copy.resize(N, 0);
    fft::fft(a_copy);
    fft::fft(b_copy);
    auto result = cmn::signal(N, 0);

    for (size_t i = 0; i < result.size(); ++i) {
        result[i] =  sqrt(N << 2) *  a_copy[i] * b_copy[i] / (double)(2);   
    }

    fft::fft(result, true);
    result.resize(a.size() + b.size() - 1);
    return result;
}
