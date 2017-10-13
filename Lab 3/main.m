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
%I_3 = 0.0700;
I_3 = I_2;

%% INITIAL CONDITIONS

% Dynamics
w1_0 = 0;
w2_0 = 0;
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
e = 0;
i = 0;
OMG = 0;
omg = 0;
theta = 0;

% Used only in case of circual orbit pointing
%n = sqrt((6.674*10^-11*(5.972*10^24 + 800))/ 200000^3);

%% LAUNCH SIMULATOR

simulation_time = 50;
sim euler_works

%% OUTPUTS PLOT

% Pointing vectaarr
figure(1)
plot3(X_P(1,:),X_P(2,:),X_P(3,:));
% Pointing orbit
figure(2)
plot3(r(:,1),r(:,2),r(:,3))