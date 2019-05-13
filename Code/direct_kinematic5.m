function [ cooX,cooY,cooZ ] = direct_kinematic5( t1,t2,t3 )

a1 = 39.45;
a2 = 42.40;
a3 = 9.11;
a4 = 43.05;
a5 = 17.15;

%syms t1 t2 t3;


M01 = Rot('z',t1)*Trans('z',a1)*Rot('y',pi/2)*Trans('z',a2);
M12 = Rot('y',-pi/2)*Rot('y',t2)*Trans('z',a4);
M23 = Rot('y',pi/2)*Rot('y',t3)*Trans('z',a5);

M13 = M01*M12*M23;

cooX = M13(1,4);
cooY = M13(2,4);
cooZ = M13(3,4);



end