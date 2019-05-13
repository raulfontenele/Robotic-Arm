clc

disp('========================');
[t1,t2,t3] = cinematica_inversa4(100,0,-70)
[x,y,z] = direct_kinematic(t1,t2,t3)

t11 = t1*180/pi
t22 = t2*180/pi
t33 = t3*180/pi

disp('========================');
[t1,t2,t3] = cinematica_inversa4(60,0,-70);
[x,y,z] = direct_kinematic(t1,t2,t3)

t11 = t1*180/pi
t22 = t2*180/pi
t33 = t3*180/pi

disp('========================');

[t1,t2,t3] = cinematica_inversa4(60,30,-70);
[x,y,z] = direct_kinematic(t1,t2,t3)

t11 = t1*180/pi
t22 = t2*180/pi
t33 = t3*180/pi

disp('========================');

[t1,t2,t3] = cinematica_inversa4(80,30,-70);
[x,y,z] = direct_kinematic(t1,t2,t3)

t11 = t1*180/pi
t22 = t2*180/pi
t33 = t3*180/pi

disp('========================');

[t1,t2,t3] = cinematica_inversa4(80,0,-70);
[x,y,z] = direct_kinematic(t1,t2,t3)

t11 = t1*180/pi
t22 = t2*180/pi
t33 = t3*180/pi