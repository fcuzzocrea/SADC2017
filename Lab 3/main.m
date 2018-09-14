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
% Mass of 6U cubesat + payload
M = 3.00;         % Kg

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

I = [I_1  0   0;
      0  I_2  0;
      0   0  I_3];
  
I_inv = inv(I);  
%% INITIAL CONDITIONS

% Standard gravitational parameter
mu = 398600;        % Km^3/s^2

% Radius of the Earth 
R_e = 6.378e+03;    % Km

% Test omegas
w1_0 = 0.012;
w2_0 = 0.09;
w3_0 = 0.17;

w_0 = [w1_0,w2_0,w3_0];

% Kinematics : DCM
DCM_0 = eye(3);

% Kinematics : Euler Angles
phi_0 = 0.1;
theta_0 = 0.1;
psi_0 = 0.1;

% Pointing orbit
r_a = 800 + R_e;
r_p = 800 + R_e;                % Km
a = (r_a + r_p)/2;              % Km
e = (r_a - r_p)/(r_a + r_p);
i = 0;                          % Degrees
OMG = 0;                        % Degrees
omg = 0;                        % Degrees
theta = 0;                      % Degrees

%% LAUNCH SIMULATOR

simulation_time = (2*pi*sqrt(a^3/mu));
sim Lab_3

%% OUTPUTS PLOT

% Pointing vector
figure(1)
plot3(X_P(1,:),X_P(2,:),X_P(3,:));

% Pointing orbit
figure(2)
plot3(r(:,1),r(:,2),r(:,3))