clear
dft_time = readmatrix('time_dft.txt');
fft_time = readmatrix('time_fft.txt');
n = readmatrix('N.txt');

figure(1)
plot(n, log(dft_time), 'b')
hold on
grid on
plot(n, log(fft_time), 'r')
legend(["dft", "fft"])
xlabel('N')
ylabel('seconds')
title('log scale')

figure(2)
plot(n, dft_time, 'b--')
hold on
grid on
plot(n, fft_time, 'r')
legend(["dft", "fft"])
xlabel('N')
ylabel('seconds')
title('original scale')