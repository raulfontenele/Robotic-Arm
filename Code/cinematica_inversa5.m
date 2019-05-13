function [teta1,teta2,teta3 ] = cinematica_inversa5( x,y,z )

a1 = 39.45;
a2 = 42.40;
a3 = 9.11;
a4 = 43.05;
a5 = 17.15;

w = sqrt(x^2 + y^2) -a2;

wlinha = sqrt(  (z-a1)^2 + w^2 )
try
    alpha = atan( (z-a1)/w );
catch
    try
        alpha = asin((z-a1)/wlinha);
    catch
        alpha = acos( w /wlinha);
    end
end
div1 = (a4^2+ a5^2 - wlinha^2)/(2*a4*a5)
if (a4^2+ a5^2 - wlinha^2)/(2*a4*a5) > 1 || (a4^2+ a5^2 - wlinha^2)/(2*a4*a5) < -1 
    pontoFlutuante = (a4^2+ a5^2 - wlinha^2)/(2*a4*a5) - fix( (a4^2+ a5^2 - wlinha^2)/(2*a4*a5) );
    sigma = acos(pontoFlutuante);
    disp('entrou no caso do +1 ou -1 no do sigma');
else
    sigma = acos((a4^2+ a5^2 - wlinha^2)/(2*a4*a5));
end

div2 = (a4^2 - a5^2 + wlinha^2)/(2*a4*wlinha)

if (a4^2 - a5^2 + wlinha^2)/(2*a4*wlinha) > 1 || (a4^2 - a5^2 + wlinha^2)/(2*a4*wlinha) < -1
    pontoFlutuante = (a4^2 - a5^2 + wlinha^2)/(2*a4*wlinha) - fix((a4^2 - a5^2 + wlinha^2)/(2*a4*wlinha));
    beta = acos(pontoFlutuante);
    disp('entrou no caso do +1 ou -1 no do beta');
else
    beta = acos((a4^2 - a5^2 + wlinha^2)/(2*a4*wlinha));
end


teta1 = atan(y/x);
teta3 = pi/2 - sigma;
teta2 = pi/2-beta - alpha;


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