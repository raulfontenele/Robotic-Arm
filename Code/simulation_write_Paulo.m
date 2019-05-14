%%Teste escrevendo o P em girando um motor um motor apos o outro
clc;
clear all;


[t1,t2,t3] = reverse_kinematics(50,0,-50);
i = 1;
[x(i),y(i),z(i)] = direct_kinematic(t1,t2,t3);

[t11,t22,t33] = reverse_kinematics(100,0,-50);

i = i+1;
[x(i),y(i),z(i)] = direct_kinematic(t11,t2,t3);
i = i+1;
[x(i),y(i),z(i)] = direct_kinematic(t11,t22,t3);
i = i+1;
[x(i),y(i),z(i)] = direct_kinematic(t11,t22,t33);

t1 = t11;
t2 = t22;
t3 = t33;

[t11,t22,t33] = reverse_kinematics(100,0,-50);
i = i+1;
[x(i),y(i),z(i)] = direct_kinematic(t11,t2,t3);
i = i+1;
[x(i),y(i),z(i)] = direct_kinematic(t11,t22,t3);
i = i+1;
[x(i),y(i),z(i)] = direct_kinematic(t11,t22,t33);

t1 = t11;
t2 = t22;
t3 = t33;

[t11,t22,t33] = reverse_kinematics(100,30,-50);
i = i+1;
[x(i),y(i),z(i)] = direct_kinematic(t11,t2,t3);
i = i+1;
[x(i),y(i),z(i)] = direct_kinematic(t11,t22,t3);
i = i+1;
[x(i),y(i),z(i)] = direct_kinematic(t11,t22,t33);

t1 = t11;
t2 = t22;
t3 = t33;

[t11,t22,t33] = reverse_kinematics(80,30,-50);
i = i+1;
[x(i),y(i),z(i)] = direct_kinematic(t11,t2,t3);
i = i+1;
[x(i),y(i),z(i)] = direct_kinematic(t11,t22,t3);
i = i+1;
[x(i),y(i),z(i)] = direct_kinematic(t11,t22,t33);

t1 = t11;
t2 = t22;
t3 = t33;

[t11,t22,t33] = reverse_kinematics(80,0,-50);
i = i+1;
[x(i),y(i),z(i)] = direct_kinematic(t11,t2,t3);
i = i+1;
[x(i),y(i),z(i)] = direct_kinematic(t11,t22,t3);
i = i+1;
[x(i),y(i),z(i)] = direct_kinematic(t11,t22,t33);


plot3(x,y,z);
grid;
%% Teste escrever o P girando os três "ao mesmo tempo"
clc;
clear all;

[t1,t2,t3] = reverse_kinematics(50,0,-50);
[t11,t22,t33] = reverse_kinematics(100,0,-50);

deltaT1 = (t11 - t1)/50;
deltaT2 = (t22 - t2)/50;
deltaT3 = (t33 - t3)/50;

for i = 0:50

[x(i+1),y(i+1),z(i+1)] = direct_kinematic(t1 + deltaT1*i,t2 + deltaT2*i ,t3 + deltaT3*i);

end
plot3(x,y,z);
grid;
hold on;

[t1,t2,t3] = reverse_kinematics(100,0,-50);
[t11,t22,t33] = reverse_kinematics(100,15,-50);

deltaT1 = (t1 - t11)/50;
deltaT2 = (t2 - t22)/50;
deltaT3 = (t3 - t33)/50;

for i = 0:50

[x(i+1),y(i+1),z(i+1)] = direct_kinematic(t11 + deltaT1*i,t22 + deltaT2*i ,t33 + deltaT3*i);

end

plot3(x,y,z);


[t1,t2,t3] = reverse_kinematics(100,15,-50);
[t11,t22,t33] = reverse_kinematics(80,15,-50);

deltaT1 = (t1 - t11)/50;
deltaT2 = (t2 - t22)/50;
deltaT3 = (t3 - t33)/50;

for i = 0:50

[x(i+1),y(i+1),z(i+1)] = direct_kinematic(t11 + deltaT1*i,t22 + deltaT2*i ,t33 + deltaT3*i);

end

plot3(x,y,z);

[t1,t2,t3] = reverse_kinematics(80,15,-50);
[t11,t22,t33] = reverse_kinematics(80,0,-50);

deltaT1 = (t1 - t11)/50;
deltaT2 = (t2 - t22)/50;
deltaT3 = (t3 - t33)/50;

for i = 0:50
[x(i+1),y(i+1),z(i+1)] = direct_kinematic(t11 + deltaT1*i,t22 + deltaT2*i ,t33 + deltaT3*i);
end

plot3(x,y,z);
xlim([30 150]);
ylim([-30 30]);
zlim([-100 0]);

hold off
