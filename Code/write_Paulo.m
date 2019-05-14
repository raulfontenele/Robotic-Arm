clc

disp('========================');
[t1,t2,t3] = cinematica_inversa(100,0,-70)
[x,y,z] = direct_kinematic(t1,t2,t3)

t11 = t1*180/pi
t22 = t2*180/pi
t33 = t3*180/pi

disp('========================');
[t1,t2,t3] = cinematica_inversa(60,0,-70);
[x,y,z] = direct_kinematic(t1,t2,t3)

t11 = t1*180/pi
t22 = t2*180/pi
t33 = t3*180/pi

disp('========================');

[t1,t2,t3] = cinematica_inversa(60,30,-70);
[x,y,z] = direct_kinematic(t1,t2,t3)

t11 = t1*180/pi
t22 = t2*180/pi
t33 = t3*180/pi

disp('========================');

[t1,t2,t3] = cinematica_inversa(80,30,-70);
[x,y,z] = direct_kinematic(t1,t2,t3)

t11 = t1*180/pi
t22 = t2*180/pi
t33 = t3*180/pi

disp('========================');

[t1,t2,t3] = cinematica_inversa(80,0,-70);
[x,y,z] = direct_kinematic(t1,t2,t3)

t11 = t1*180/pi
t22 = t2*180/pi
t33 = t3*180/pi