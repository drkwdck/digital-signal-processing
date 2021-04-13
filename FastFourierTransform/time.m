fft = [0.00014 0.000333 0.000915 0.001399 0.003038];
dft = [0.012648 0.047041 0.145071 0.594685 2.38044];
n = [];
n(1) = 256;
for i=2:5
    n(i) = n(i -1) * 2;
end

plot(n, fft)
hold on
plot(n, dft)
grid on
legend('БПФ', 'ДПФ')
xlabel('N')
ylabel('сек')
title('время(N)')
