Fpass1=46; 	
Fpass2=54; 	
Fstop1=48.5;
Fstop2=52; 	
Astop=50;
Apass=0.5; 	
Ft=300; 	

wp1=2*pi*Fpass1/Ft;
wp2=2*pi*Fpass2/Ft;
ws1=2*pi*Fstop1/Ft;
ws2=2*pi*Fstop2/Ft;

Ws1=2*Ft*tan(ws1/2);
Ws2=2*Ft*tan(ws2/2);
Wp1=2*Ft*tan(wp1/2);
Wp2=2*Ft*tan(wp2/2);
%Пересчет Wp1
Wp1=(Ws1 * Ws2)/ Wp2;

Wo=sqrt(Ws1*Ws2);
Bw=Ws2-Ws1; 