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



std::vector<std::complex<double>>  FastFourierTransform(std::vector<std::complex<double>> &x)
{
    int n = x.size();
    Shuffle(x, n);

    for (size_t k = n; k > 0; --k)
    {
        for (size_t j = 0; j <= (1 << (n - k)) - 1; ++j)
        {
            for (size_t l = 0; l <= (1 << (k - 1)) - 1; ++l)
            {
                auto w = - std::exp(std::complex<double>(0, -2 * M_PI  * l / (1 << k))); 
                x[j * (1 << k) + l] = x[j * (1 << k) + l] + w * x[j * (1 << k) + l + (1 << (k - 1))];
                x[(1 << (k -1)) + j * (1 << k) + l] = x[j * (1 << k) + l] - w * x[j * (1 << k) + l + (1 << (k - 1))];
            }
        }

        x[k] /= std::sqrt(n);
    }

   x[0] /= std::sqrt(n);
}
