%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%       SPACECRAFT ATTITUDE SIMULATION AND CONTROL TOOLBOX            %
%                                                                     %
%  Author : Francescodario Cuzzocrea                                  %
%                                                                     %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

clearvars
close all
clear 
clc

mu = 398600;
R_e = 6.378e+03;
w_e = [0 0 0.00007291]; % rad/sec

%% GEOMETRICAL PROPERTIES
% Datas taken from ISIS space : https://www.isispace.nl/product/6-unit-cubesat-structure/
%
%
%                                        ^
%                                        |
%                                        |   z
%
%                             +--------------------------+
%                            /                          /|
%                           /                          / |
%                          /                          /  |
%                         +--------------------------+   |  ---> y
%                         |                          |   +
%                         | w                        | h/
%                         |           l              | /
%                         +--------------------------+
%                                     /
%                                    /  x
%                                  \/
%
% Mass of 6U cubesat + payload
M = 3.00; % Kg

% Dimensions
w = 100*10^-3;    % m
l = 226.3*10^-3;  % m
h = 340.5*10^-3;  % m
dim = [w, l, h];

%Sections
A_i_1 = w*l; % m^2
A_i_2 = w*h; % m^2
A_i_3 = l*h; % m^2
A_i = [A_i_1, A_i_2, A_i_3];

I_1 = M/12 * (w^2 + l^2); % Kg * m^2
I_2 = M/12 * (w^2 + h^2); % Kg * m^2
I_3 = M/12 * (l^2 + h^2); % Kg * m^2

% Air properties
rho = 1.31e-17*1000;  %Kg/m^3 @ 800km
C_d = 2.2;

%% INITIAL CONDITIONS

% Test omegas
w1_0 = 0;
w2_0 = 0;
%w3_0 = sqrt(mu/(R_e+800)^3);
w3_0 = sqrt(mu/(7.9755e+03)^3);
%w3_0 = 0.0080;

% Kinematics : DCM
DCM_0 = eye(3);

% Kinematics : Euler Angles
phi_0 = 0.1;
theta_0 = 0.1;
psi_0 = 0.1;
q_0 = [0 1/sqrt(3) 1/sqrt(3) 1/sqrt(3)];

% Pointing orbit (test)
r_a = 2395 + R_e;
r_p = 800 + R_e;
a = (r_a + r_p)/2;
e = (r_a - r_p)/(r_a + r_p);
i = 0;
OMG = 0;
omg = 0;
theta = 0;

%% LAUNCH SIMULATOR

simulation_time = (2*pi*sqrt(a^3/mu))*15;
sim Lab_5    

%% OUTPUTS PLOT

% Pointing vector
figure(1)
plot3(X_P(1,:),X_P(2,:),X_P(3,:));
axis equal 

% Reference orbit
figure(2)
plot3(r(:,1),r(:,2),r(:,3))
axis equal

% Gravity Gradient
figure(3)
hold on
plot(GG(1:end,1)); plot(GG(1:end,2)); plot(GG(1:end,3));
title('Disturbance Torque due to Gravity Gradient')
legend('GG_x','GG_y','GG_z')

% Drag Torque
figure(4)
hold on
plot(drag_torque(1:end,1)); plot(drag_torque(1:end,2)); plot(drag_torque(1:end,3));
title('Disturbance Torque due to Aerodynamic Drag')
legend('DT_x','DT_y','DT_z')

% Error on attitude
figure(5)
hold on
plot(w_bl(1:end,1)); plot(w_bl(1:end,2)); plot(w_bl(1:end,3));
title('Error between BFF and RF')
legend('x','y','z')
        
%{
   TODO : 
           * Quaternions          
%}


    

          
