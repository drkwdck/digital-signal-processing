# Быстрое преобразование Фурье и вычисление с его помощью дискретной свёртки
Проект содержит реализацию на `C++` преобразования Фурье и вычисления свертки различными способами.

# Описание
В репозитории несколько заголовочных файлов, в каждом из которых описан отдельный алгоритм. 


В `convolution.h` находится реализация:
 * вычисления свертки двух сигналов (за `O(n^2)`)
 * вычисления свертки двух сигналов (за `n log(n)`)

В `dft.h` описано дискретное преобразование Фурье (за `O(n^2)`), а в `fft.h` - быстрое преобразование Фурье с двоично-инверсными перестановками и прореживанием по времени (за `n log(n)`).


В директории `matlab/` находятся скрипты для сравнения реализации на `C++` и встроенными функциями `Matlab`, а так же построение графиков зависимостей скорости работы реализованных алгоритмов от количества точек в дискретном сигнале.

# Установка и запуск
Для сборки проекта необходимо, чтобы на целевой машине были установлены `g++`, `make`.


Чтобы собрать проект, необходимо выполнить из `src/`:
```
$ make
```

Для запуска из `src/`:
```
$ ./main
```


В результате работы которого будет выведен средний квадрат отклонения между разными реализациями алгоритмов и измерено время их работы.


Для того, чтобы посмотреть на графики зависимости времени работы алгоритмов от количество точек в дискретном сигнале, необходимо запустить в `Matlab`: `check_conv_time.m` и `plot_perfomance_estimate.m`.

Для того, чтобы вычислить разницу между реализованным алгоритмом и встроенными функциями `Matlab`: `check_equal_conv.m`, `check_equal_fft.m`

# Пример запуска
Пример вывода в консоль после успешной сборки и запуска:
```
Разница между X и ОДПФ(ДПФ(X)): MSE = 1.50632e-26
Разница между X и ОБПФ(БПФ(X)): MSE = 4.0828e-29
Разница между ДПФ(X) и БПФ(X) MSE = 1.28977e-26
```