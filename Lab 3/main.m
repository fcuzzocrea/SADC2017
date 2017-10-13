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

%% INERTIAL PROPERTIES

I_1 = 0.0109;
I_2 = 0.0504;
I_3 = 0.0700;

%% INITIAL CONDITIONS

% Dynamics
w1_0 = 0.53;
w2_0 = 0.54;
w3_0 = 0.26;

% Kinematics : DCM
DCM_0 = eye(3);

% Kinematics : Euler Angles
phi_0 = 0.56;
theta_0 = 0.56;
psi_0 = 0.84;

% Pointing orbit
mu = 398600;
a = 200;
e = 0.3;
i = 0;
OMG = 0;
omg = 0;
theta = 0;

%% LAUNCH SIMULATOR

simulation_time = 50;
sim Lab_3

%% OUTPUTS PLOT

% Pointing vectaarr
figure(1)
plot3(X_P(1,:),X_P(2,:),X_P(3,:));
% Pointing orbit
figure(2)
plot3(r(:,1),r(:,2),r(:,3))