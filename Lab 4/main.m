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

m_t = 5.972e24;  % Kg
G = 6.674e-11;   %  

%% INERTIAL PROPERTIES

I_1 = 0.0109;
I_2 = 0.0504;
I_3 = 0.0700;

%% INITIAL CONDITIONS

%Dynamics
% w1_0 = 0;
% w2_0 = 0;
% w3_0 = sqrt((6.674*10^-11*(5.972*10^24))/ (200000+6378000)^3);  

w1_0 = 0.56;
w2_0 = 0.64;
w3_0 = 0.587;  

% Kinematics : DCM
DCM_0 = eye(3);

% Kinematics : Euler Angles
phi_0 = 0.1;
theta_0 = 0.1;
psi_0 = 0.1;

% Pointing orbit
mu = 398600;    %km
a = 200+6378;   %km
e = 0;
i = 0;
OMG = 0;
omg = 0;
theta = 0;

%% LAUNCH SIMULATOR

simulation_time = 6000;
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
           * Gravity Gradient Torque
%}

          