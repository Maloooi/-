[num, den]=lp2bs(numd,dend, Wo, Bw);

% построение АЧХ и ЛАЧХ аналогового РФ:
[H, W] = freqs(num, den, 4096);
figure(2)
subplot(2,1,1);
plot (W, abs(H))
xlim([300 400]);
grid;
set(gca,'FontName', 'Times New Roman Cyr', 'FontSize', 10)
title('График АЧХ аналогового РФ');
subplot(2,1,2);
plot (W, 20*log10(abs(H)))
xlim([300 400]);
grid;
set(gca,'FontName', 'Times New Roman Cyr', 'FontSize', 10)
title('График ЛАЧХ аналогового РФ');
xlabel('w, рад');

num
den