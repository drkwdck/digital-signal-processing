#include  <math.h>
#include <vector>
#include <complex>
#include "FastFourierTransform.h"
#include <iostream>

int GetReversedIndex(int num, int bits_count)
{
	int res = 0;

	for (size_t i = 0; i<bits_count; ++i)
    {
		if (num & (1 << i))
        {
			res |= 1 << (bits_count - 1 - i);
        }
    }

    return res;
}


// Двоично-инверсные перестановки
void Shuffle(std::vector<std::complex<double> > &x, int n)
{
    int bits_count = 0;

    while ((1 << bits_count) < n)
    {
        ++bits_count;
    }

    for (size_t i = 0; i < n; ++i)
    {
        // Не переставляем второй раз элементы местами
        if (i < GetReversedIndex(i, bits_count))
        {
            std::swap(x[i], x[GetReversedIndex(i, bits_count)]);
        }
    }
}

void FastFourierTransform(std::vector<std::complex<double> > &x, bool reverse)
{
    int n = x.size();
    Shuffle(x, n);
    int sign = reverse ? -1 : 1;

    // стр. 94 (n из учебника = log2(n) отсюда)
    for (size_t k = 1; (1 << k) <= n; ++k)
    {
        auto wStep = std::exp(std::complex<double>(0, 2 * sign * M_PI / (1 << k)));

        for (size_t j = 0; j < n; ++j)
        {
            auto w0 = std::complex<double>(1, 0);

            for (size_t l = 0; l < (1 << (k - 1)); ++l)
            {
                // т.к. на каждой итерации перезатираем наш массив
                auto a = x[j * (1 << k) + l];
                auto b = x[j * (1 << k) + l + (1 << (k - 1))] * w0;
                x[j * (1 << k) +l] = a + b;
                x[j * (1 << k) + l + (1 << (k - 1))] = a - b;
                w0 *= wStep;
            }
        }
    }

    auto normMult = 1 / std::sqrt(n);

    for (size_t i = 0; i < n; ++i)
    {
        x[i] *= normMult;
    }
}