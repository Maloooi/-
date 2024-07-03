Omega_s = (Ws2-Ws1)/(Wp2-Wp1);
[n,Wn]=ellipord(1,Omega_s, Apass, Astop,'s'); 
[numd,dend]=ellip(n, Apass, Astop,Wn,'low','s'); % Расчет  перед.    функции  НФНЧ

n
Wn
