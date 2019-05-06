function [teta1,teta2,teta3 ] = cinematica_inversa4( x,y,z )

a1 = 39.45;
a2 = 42.40;
a3 = 9.11;
a4 = 43.05;
a5 = 17.15;

w = sqrt(x^2 + y^2);

wlinha = sqrt( (a1-a3-z)^2 + (w-a2)^2 );

alpha = atan( (w-a2)/(a1-a3-z)  );

if (a4^2+ wlinha^2 - a5^2)/(2*a4*wlinha) > 1
    beta = acos((a4^2+ wlinha^2 - a5^2)/(2*a4*wlinha)-1);
elseif (a4^2+ wlinha^2 - a5^2)/(2*a4*wlinha) < -1
    beta = acos((a4^2+ wlinha^2 - a5^2)/(2*a4*wlinha)+1);
else
    beta = acos((a4^2+ wlinha^2 - a5^2)/(2*a4*wlinha));
end

if (a4^2 + a5^2 - wlinha^2)/(2*a4*a5) > 1
    gama = acos( (a4^2 + a5^2 - wlinha^2)/(2*a4*a5) - 1);
elseif (a4^2 + a5^2 - wlinha^2)/(2*a4*a5) < -1
    gama = acos( (a4^2 + a5^2 - wlinha^2)/(2*a4*a5) + 1);
else
    gama = acos((a4^2 + a5^2 - wlinha^2)/(2*a4*a5));
end

t1 = atan(y/x);
t2 = pi/2 - beta - alpha;
t3 = pi-gama;

if(180*t1/pi + 90<180 && 180*t1/pi + 90 > 0)
    teta1 = 180*t1/pi + 90;
elseif 180*t1/pi + 90 > 180
    teta1 = 180;
else
    teta1 = 0;
end
    
if(180*t2/pi + 90<180 && 180*t2/pi + 90 > 0)
    teta2 = 180*t2/pi + 90;
elseif 180*t2/pi + 90>180
    teta2 = 180;
else
    teta2 = 0;
end

if(180*t3/pi + 90<180 && 180*t3/pi + 90 > 0)
    teta3 = 180*t3/pi + 90;
elseif 180*t3/pi + 90>180
    teta3 = 180;
else
    teta3 = 0;
end


end