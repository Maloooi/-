sos = tf2sos(numk, denk) ;
fvtool(sos);
[numc, denc]=sos2tf(sos);
[Hc, fc]=freqz(numc, denc, 4096, Ft);
figure(5)
plot(fc,abs(Hc))
hold on;
plot(f, abs(H),'--')
xlim([35 65]);
set(gca,'FontName', 'Times New Roman Cyr', 'FontSize', 10)
legend('АЧХ исходного фильтра', 'АЧХ фильтра в каскадной форме')
grid;
sos