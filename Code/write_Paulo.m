%% Functions for write name Paulo
[t1,t2,t3] = cinematica_inversa4(60,0,-20);
[x,y,z] = direct_kinematic(t1,t2,t3);

t11 = t1*180/pi
t22 = t2*180/pi
t33 = t3*180/pi

disp('========================');
[t1,t2,t3] = cinematica_inversa4(90,0,-20);
[x,y,z] = direct_kinematic(t1,t2,t3);

t11 = t1*180/pi
t22 = t2*180/pi
t33 = t3*180/pi

disp('========================');

[t1,t2,t3] = cinematica_inversa4(90,20,-20);
[x,y,z] = direct_kinematic(t1,t2,t3);

t11 = t1*180/pi
t22 = t2*180/pi
t33 = t3*180/pi

disp('========================');

[t1,t2,t3] = cinematica_inversa4(70,20,-20);
[x,y,z] = direct_kinematic(t1,t2,t3);

t11 = t1*180/pi
t22 = t2*180/pi
t33 = t3*180/pi

disp('========================');

[t1,t2,t3] = cinematica_inversa4(70,0,-20);
[x,y,z] = direct_kinematic(t1,t2,t3);

t11 = t1*180/pi
t22 = t2*180/pi
t33 = t3*180/pi