c_time = readmatrix('time_conv.txt');
fft_time = readmatrix('time_conv_fft.txt');
n = readmatrix('conv_N.txt');

plot(n, c_time, 'b--')
hold on
grid on
plot(n, fft_time, 'r')
legend(["simple conv", "fft conv"])
xlabel('N')
ylabel('seconds')
title('original scale')