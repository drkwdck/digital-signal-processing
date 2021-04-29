#include "common.h"

namespace fft {
    // Быстрое преобразование Фурье. Для того, чтобы получить обратное
    // преобразование, необходимо вторым параметром передать true
    void fft(cmn::signal &x, bool reverse = false);
}