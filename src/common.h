#pragma once

#include<complex>
#include<vector>
#include <string>

namespace cmn {
    using signal = std::vector<std::complex<double>>;

    // Возвращает сгенерированный сигнал (набор комплексных чисел заданного размера)
    signal GenerateSignal(const int N, const int sRand);

    // Записывает сигнал в файл
    void WriteSignalToFile(const cmn::signal signal, const std::string file_name);
    
    // Читает сигнал из файла (разделитель между комплексной и действительной частью - пробел
    // каждое число начинается с новой строки)
    signal ReadSignalFromFile(const std::string fileName);

    // Средний квадрат ошибки
    double MSE(signal a, signal b);
}
