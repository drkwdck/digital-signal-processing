#include "common.h"
#include "convolution.h"

cmn::signal conv::Convolution(cmn::signal a, cmn::signal b) {
    if (a.size() > b.size()) {
        for (size_t i = b.size() - 1; i < a.size(); ++i) {
            b.push_back(0);
        }
    }

    if (b.size() > a.size()) {
        for (size_t i = a.size() - 1; i < b.size(); ++i) {
            a.push_back(0);
        }
    }

    size_t N = a.size();
    auto result = cmn::signal(2 * N - 1, 0);

    for (size_t k = 0; k < 2 * N - 1; ++k) {
        for (size_t j = 0; j < N - 1; ++j) {
            if (j >= N || k - j >= N || k - j < 0) {
                continue;
            }

            result[k] += a[j] * b[k - j];
        }
    }

    return result;
}