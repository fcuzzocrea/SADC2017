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

%% GEOMETRICAL PROPERTIES

% Triaxial symmetry case, J2 intermediate principal moment of inertia
I_1 = 0.0109;                % Kgm^2
I_2 = 0.0504;                % Kgm^2
I_3 = 0.055;                 % Kgm^2    

I = [I_1,   0,  0;
        0,I_2,  0;
        0,  0, I_3];   
    
I_inv = inv(I);    
%% INITIAL CONDITIONS

% Standard gravitational parameter
mu = 398600;        % Km^3/s^2

% Radius of the Earth 
R_e = 6.378e+03;    % Km

% Test omegas
w1_0 = 0.01;
w2_0 = 0.03;
w3_0 = 0.05;
%w3_0 = 0.001038158026828;

w_0 = [w1_0,w2_0,w3_0];

% Kinematics : DCM
A_BN_0 = eye(3);

% Kinematics : Euler Angles
phi_0 = 0;
theta_0 = 0;
psi_0 = 0;

% LVLH Orbit Setup
r_a = 800 + R_e;
r_p = 800 + R_e;                % Km
a = (r_a + r_p)/2;              % Km
e = (r_a - r_p)/(r_a + r_p);
i = 0;                          % Degrees
OMG = 0;                        % Degrees
omg = 0;                        % Degrees
theta = 0;                      % Degrees

%% CONTROLLER SETUP

% Gains

k1 = 0.01;
k2 = 0.001;

%% LAUNCH SIMULATOR

simulation_time = (2*pi*sqrt(a^3/mu))*3;
sim Lab_3

%% OUTPUTS PLOT

% Pointing vector
figure(1)
plot3(X_P(1,:),X_P(2,:),X_P(3,:));
% LVLH orbit
figure(2)
plot3(r_LVLH(:,1),r_LVLH(:,2),r_LVLH(:,3));