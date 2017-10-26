%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
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
R_e = 6378;

%% INERTIAL PROPERTIES

I_1 = 0.0067;
I_2 = 0.0333;
I_3 = 0.0333;

%% INITIAL CONDITIONS

% Test omegas
%
% w1_0 = 0;
% w2_0 = 0;
% w3_0 = sqrt((6.674*10^-11*(5.972*10^24))/ (200000+6378000)^3);  

% Simulation omegas

w1_0 = 0;
w2_0 = 0;
w3_0 = 0.58;  

% Kinematics : DCM
DCM_0 = eye(3);

% Kinematics : Euler Angles
phi_0 = 0.1;
theta_0 = 0.1;
psi_0 = 0.1;

% % Pointing orbit (Molynia)
% 
% a = 20176+R_e;   %km
% e = 0.72;
% i = 63.4;
% OMG = 0;
% omg = -pi;
% theta = 0;

% Pointing orbit (test)

a = 200+R_e;   %km
e = 0;
i = 0;
OMG = 0;
omg = 0;
theta = 0;

%% LAUNCH SIMULATOR

simulation_time = 2*pi*sqrt(a^3/mu);
sim Lab_4

%% OUTPUTS PLOT

% Pointing vector
figure(1)
plot3(X_P(1,:),X_P(2,:),X_P(3,:));
axis vis3d 

% Reference orbit
figure(2)
plot3(r(:,1),r(:,2),r(:,3))
axis vis3d
        
%{
   TODO : 
           * Quaternions
           * Gravity Gradient Torque - Are results ok ? 
            
            Piu mi allontano piu aumenta l'errore ? WTF


%}

          