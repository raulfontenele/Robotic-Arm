function [teta1,teta2,teta3 ] = reverse_kinematics( x,y,z )

a1 = 39.45;
a2 = 42.40;
a3 = 9.11;
a4 = 43.05;
% a5 = 17.15;
a5=46 + 40;

w = sqrt(x^2 + y^2);

wlinha = sqrt( (a1-a3-z)^2 + (w-a2)^2 );

try
    alpha = atan( (w-a2)/(a1-a3-z)  );
catch
    try
        alpha = asin((w-a2)/wlinha);
    catch
        alpha = acos((a1-a3-z)/wlinha);
    end
end

if (a4^2+ wlinha^2 - a5^2)/(2*a4*wlinha) > 1 || (a4^2+ wlinha^2 - a5^2)/(2*a4*wlinha) < -1 
%     div = (a4^2+ wlinha^2 - a5^2)/(2*a4*wlinha);
    pontoFlutuante = (a4^2+ wlinha^2 - a5^2)/(2*a4*wlinha) - fix((a4^2+ wlinha^2 - a5^2)/(2*a4*wlinha));
    beta = acos(pontoFlutuante);
    disp('entrou no caso do +1 ou -1 no do beta');
else
    beta = acos((a4^2+ wlinha^2 - a5^2)/(2*a4*wlinha));
end


if (a4^2 + a5^2 - wlinha^2)/(2*a4*a5) > 1 || (a4^2 + a5^2 - wlinha^2)/(2*a4*a5) < -1
    div = (a4^2 + a5^2 - wlinha^2)/(2*a4*a5);
    fix((a4^2 + a5^2 - wlinha^2)/(2*a4*a5));
    pontoFlutuante = (a4^2 + a5^2 - wlinha^2)/(2*a4*a5) - fix((a4^2 + a5^2 - wlinha^2)/(2*a4*a5));
    if (pontoFlutuante<0)
        gama = acos(-pontoFlutuante)
    else
        gama = acos(pontoFlutuante );
    end
    disp('entrou no caso do +1 ou -1 no do gama');
else
    gama = acos((a4^2 + a5^2 - wlinha^2)/(2*a4*a5));
end


% if atan(y/x) < 0
%     teta1 = 0;
% elseif atan(y/x) > pi
%     teta1 = pi;
% else
%     teta1 = atan(y/x);
% end
% 
% if pi/2 - beta - alpha < 0
%     teta2 = 0;
% elseif atan(y/x) > pi
%     teta2 = pi;
% else
%     teta2 = pi/2 - beta - alpha;
% end
% 
% if pi-gama < 0
%     teta3 = 0;
% elseif pi-gama > pi
%     teta3 = pi;
% else
%     teta3 = pi-gama;
% end

teta1 = atan(y/x);
teta2 = pi/2 - beta - alpha;
teta3 = pi-gama;


% t2 = pi/2 - beta - alpha;
% t3 = pi-gama;

% if(180*t1/pi + 90<180 && 180*t1/pi + 90 > 0)
%     teta1 = 180*t1/pi + 90;
% elseif 180*t1/pi + 90 > 180
%     teta1 = 180;
% else
%     teta1 = 0;
% end
%     
% if(180*t2/pi + 90<180 && 180*t2/pi + 90 > 0)
%     teta2 = 180*t2/pi + 90;
% elseif 180*t2/pi + 90>180
%     teta2 = 180;
% else
%     teta2 = 0;
% end
% 
% if(180*t3/pi + 90<180 && 180*t3/pi + 90 > 0)
%     teta3 = 180*t3/pi + 90;
% elseif 180*t3/pi + 90>180
%     teta3 = 180;
% else
%     teta3 = 0;
% end


end