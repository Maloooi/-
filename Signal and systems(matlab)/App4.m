format long;
[numk, denk]=bilinear(num, den, Ft);

[H, f]=freqz(numk, denk, 4096*10,Ft);
figure(3)
subplot(2,1,1);
plot(f, abs(H));
xlim([40 60]);
%ylim([0 1]);
grid;
set(gca,'FontName', 'Times New Roman Cyr', 'FontSize', 10)
title('АЧХ цифрового РФ')
subplot(2,1,2), plot(f, 20*log10(abs(H)))
set(gca,'FontName', 'Times New Roman Cyr', 'FontSize', 10)
title('ЛАЧХ цифрового РФ')
xlim([48 52]);
ylim([-70 -50]);
grid;
xlabel('f , Гц')
ylabel('дБ')

figure(4)
zplane(numk, denk);

numk
denk