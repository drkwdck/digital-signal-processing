#pragma once

#include "common.h"

namespace conv {
    // Возвращает результат свертки двух векторов
    cmn::signal Convolution(const cmn::signal a, const cmn::signal b);

    // Возвращает результат свертки двух векторов,
    // вычисленный с помощью быстрого преобразования Фурье
    cmn::signal FastConvolution(const cmn::signal a, const cmn::signal b);
}