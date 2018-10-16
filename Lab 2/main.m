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
mu = 398600;                  % Km^3/s^2

% Radius of the Earth 
R_e = 6.378e+03;               % Km

% Kinematics : DCM
DCM_0 = eye(3);

% Euler Angles
phi_0 = 0.1;                   % rad
theta_0 = 0.1;                 % rad
psi_0 = 0.1;                   % rad

% Angular Velocities
w1_0 = 0;                      % rad/s
w2_0 = 0;                      % rad/s
w3_0 = 0.26;                   % rad/s
w_0 = [w1_0, w2_0, w3_0];

% Test orbit
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
k_11 = 0.1;
k_12 = 0.1;
k_21 = 0.1;
k_22 = 0.1;
k_31 = 0.1;
k_32 = 0.1;

% Desired output

phi_d = 0;
theta_d = 0;
psi_d = 0.3;

%% LAUNCH SIMULATOR

simulation_time = (2*pi*sqrt(a^3/mu));
sim Lab_2

%% PLOTTING

% Pointing vector
figure(1)
plot3(X_P(1,:),X_P(2,:),X_P(3,:));