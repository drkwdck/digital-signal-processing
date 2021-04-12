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

void FastFourierTransform(std::vector<std::complex<double> > &a)
{
    int n = a.size();
    Shuffle(a, n);

    for (int k = 1; (1 << k) <= n; ++k)
    {
        std::complex<double> wlen = std::exp(std::complex<double>(0, 2 * M_PI / (1 << k)));
        
        for (int i = 0; i < n; i += (1 << k))
        {
            auto w = std::complex<double>(1, 0);

            for (int j = 0; j < (1 << (k - 1)); ++j)
            {
                std::complex<double> u = a[i+j], v = a[i+j+(1 << k)/2] * w;
                a[i+j] = u + v;
                a[i+j+(1 << k)/2] = u - v;
                w *= wlen;
            }
        }
    }

    for (int i = 0; i < a.size(); ++i)
    {
        a[i] /= std::sqrt(a.size());
    }
}