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
R_e = 6378;       % km


%% INERTIAL PROPERTIES

I_1 = 0.0134;
I_2 = 0.0666;
I_3 = 0.0666;

%% INITIAL CONDITIONS

% Test omegas
%
w1_0 = 0;
w2_0 = 0;
%w3_0 = 0.54;
w3_0 = sqrt(mu/(R_e+800)^3);

% Kinematics : DCM
DCM_0 = eye(3);

% Kinematics : Euler Angles
phi_0 = 0.1;
theta_0 = 0.1;
psi_0 = 0.1;

q_0 = [0 1/sqrt(3) 1/sqrt(3) 1/sqrt(3)];

% Pointing orbit (test)
a = 800+R_e;   %km
e = 0.1;
i = 0;
OMG = 0;
omg = 0;
theta = 0;

%% CONTROL 

% We want to be aligned with the LVLH frame, so

q_c = [0 0 0 1]';

%% LAUNCH SIMULATOR

simulation_time = (2*pi*sqrt(a^3/mu));
sim Lab_4    

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

% Error on attitude
figure(4)
hold on
plot(w_bl(1:700,1)); plot(w_bl(1:700,2)); plot(w_bl(1:700,3));
title('Error between BFF and RF')
legend('x','y','z')
        
%{
   TODO : 
           * Quaternions
           * Gravity Gradient : dare condizione iniziale che diverga
%}


    

          
