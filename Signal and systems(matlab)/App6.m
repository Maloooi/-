n = 0:300;
y1 =cos(2*pi*50*(1/Ft)*n); %50 Гц (в полосе задерживания)
y2=cos(2*pi*70*(1/Ft)*n); %70 Гц (в полосе пропускания)
x=y1+y2;

n1=[ 0.861888691792640  -0.843859193013008   0.861888693061288   ];
d1=[1.000000000000000  -0.881800479426981 0.921806264502153];

n2=[1.000000000000000  -1.003983264363036   0.999999998511189  ];
d2=[1.000000000000000  -1.022392215395558 0.925293847764276];

n3=[1.000000000000000  -0.962613542903116   0.999999999366148   ];
d3=[1.000000000000000  -0.924328187096459  0.989345165082282];

n4=[1.000000000000000  -1.020011642567023   1.000000000650734     ];
d4=[1.000000000000000  -1.046054115243146 0.989762247489705];


F1=filter(n1,d1,x);
F2=filter(n2,d2,F1);
F3=filter(n3,d3,F2);
F4=filter(n4,d4,F3);
figure(5)
subplot(4,1,1), plot(n,y1), 
set(gca,'FontName','Times New Roman Cyr','FontSize',12),
title('Гармоника 50 Гц');
subplot(4,1,2), plot(n,y2), 
set(gca,'FontName','Times New Roman Cyr','FontSize',12),
title('Гармоника 70 Гц');
subplot(4,1,3), plot(n,x), 
set(gca,'FontName','Times New Roman Cyr','FontSize',12),
title('Сигнал суммы гармоник');
subplot(4,1,4), plot(n,F4),
set(gca,'FontName','Times New Roman Cyr','FontSize',12),
title('Сигнал на выходе фильтра');

y2 =cos(2*pi*50*(1/Ft)*n); % 50 Гц (в полосе задерживания)
F1=filter(n1,d1,y2);
F2=filter(n2,d2,F1);
F3=filter(n3,d3,F2);
F4=filter(n4,d4,F3);
figure(6)
subplot(2,1,1), plot(n,y2), 
set(gca,'FontName','Times New Roman Cyr','FontSize',12),
title('Гармоника 50 Гц');
subplot(2,1,2), plot(n,F4),
set(gca,'FontName','Times New Roman Cyr','FontSize',12),
title('Сигнал на выходе фильтра');
20*log10((y2)/(F4))

y3 =cos(2*pi*70*(1/Ft)*n); % 70 Гц (в полосе пропускания)
F1=filter(n1,d1,y3);
F2=filter(n2,d2,F1);
F3=filter(n3,d3,F2);
F4=filter(n4,d4,F3);
figure(7)
subplot(2,1,1), plot(n,y3), 
set(gca,'FontName','Times New Roman Cyr','FontSize',12),
title('Гармоника 70 Гц');
subplot(2,1,2), plot(n,F4),
set(gca,'FontName','Times New Roman Cyr','FontSize',12),
title('Сигнал на выходе фильтра');
20*log10(max(y3)/max(F4))