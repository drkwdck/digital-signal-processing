clear;
conv_cpp = readmatrix('conv_cpp.txt');
conv_cpp = conv_cpp(:, 1) + i * conv_cpp(:, 2);

fast_conv_cpp = readmatrix('fast_conv_cpp.txt');
fast_conv_cpp = fast_conv_cpp(:, 1) + fast_conv_cpp(:, 2) * i;

a = readmatrix('a.txt');
a = a(:, 1) + a(:, 2) * i;

b = readmatrix('b.txt');
b = b(:, 1) + b(:, 2) * i;

mse = sum(abs(conv(a,b) - fast_conv_cpp).^2) / length(fast_conv_cpp)
mse = sum(abs(conv(a,b) - conv_cpp).^2) / length(conv_cpp)