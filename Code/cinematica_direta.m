%% Cinemática direta

a1 = 39.45;
a2 = 42.40;
a3 = 9.11;
a4 = 43.05;
a5 = 17.15;

syms t1 t2 t3;

% t1g = -26.5651;
% t2g = -42.1332;
% t3g =  87.2715;

% t1 =  0.3218;
% t2 =  0.4895;
% t3 = 2.6463;

% t1 = 10*pi/180;
% t2 = 20*pi/180;
% t3 = 30*pi/180;




M01 = Rot('z',t1)*Trans('z',a1)*Rot('y',pi/2);
M12 = Trans('z',a2)*Rot('y',pi/2)*Trans('z',a3);
M23 = Rot('y',-pi/2+t2)*Trans('z',a4);
M34 = Rot('y',t3)*Trans('z',a5);


M13 = simplify(M01*M12*M23*M34)