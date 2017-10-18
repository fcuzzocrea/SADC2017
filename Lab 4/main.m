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

m_t = 5.972e24 %Kg

%% INERTIAL PROPERTIES

I_1 = 0.0109;
I_2 = 0.0504;
I_3 = 0.0700;

%% INITIAL CONDITIONS

% Dynamics
w1_0 = 0.45;
w2_0 = 0.52;
w3_0 = 0.55;

% Kinematics : DCM
DCM_0 = eye(3);

% Kinematics : Euler Angles
phi_0 = 0.3;
theta_0 = 0.5;
psi_0 = 0.5;

% Pointing orbit
mu = 398600;
a = 200;
e = 0.3;
i = 0;
OMG = 0;
omg = 0;
theta = 0;

%% LAUNCH SIMULATOR

simulation_time = 10;
sim Lab_4

%% OUTPUTS PLOT

% Pointing vectaarr
figure(1)
plot3(X_P(1,:),X_P(2,:),X_P(3,:));
% Pointing orbit
figure(2)
plot3(r(:,1),r(:,2),r(:,3))