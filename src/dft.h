#include "common.h"

namespace dft {
    // Дискретное преобразование Фурье
    cmn::signal dft(const cmn::signal &x);

    // Обратное дискретное преобразование Фурье
    cmn::signal idft(const cmn::signal &y);
}