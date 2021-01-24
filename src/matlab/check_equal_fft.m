clear
% Читаем сигнал
x = readmatrix('../signal.txt');
x = x(:, 1) + x(:, 2) * i;

% Читаем то, что получилось в плюсах
fft_cpp = readmatrix('cpp_fft_result.txt');
fft_cpp = fft_cpp(:, 1) + fft_cpp(:, 2) * i;

% Считаем, что выдает матлаб по нашему сигналу
fft_matlab=fft(x)./sqrt(length(x));

% Считаем средний квадрат ошибки
mse = sum(abs(fft(x) / sqrt(length(x)) - fft_cpp).^2) / length(x)
