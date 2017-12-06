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
%
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

%% INITIAL CONDITIONS

% Standard gravitational parameter
mu = 398600;        % Km^3/s^2

% Radius of the Earth 
R_e = 6.378e+03;    % Km

% Test omegas
w1_0 = 0;
w2_0 = 0;
%w3_0 = sqrt(mu/(R_e+800)^3);
w3_0 = sqrt(mu/(7.9755e+03)^3);  % rad/s^2
%w3_0 = 0.0080;

% Kinematics : DCM
DCM_0 = eye(3);

% Kinematics : Euler Angles
phi_0 = 0.1;
theta_0 = 0.1;
psi_0 = 0.1;
q_0 = [0 1/sqrt(3) 1/sqrt(3) 1/sqrt(3)];

% Pointing orbit (test)
r_a = 2395 + R_e;               % Km
r_p = 800 + R_e;                % Km
a = (r_a + r_p)/2;              % Km
e = (r_a - r_p)/(r_a + r_p);
i = 0;                          % Degrees
OMG = 0;                        % Degrees
omg = 0;                        % Degrees
theta = 0;                      % Degrees

%% CONDITIONS FOR DISTURBANCES

% Angular velocity of the Earth
w_e = [0 0 0.00007291];  % rad/sec

% Sun Mean Motion
n = 2*pi/(60*60*24*365); % rad/s   

% Obliquity of the Ecliptic
eps = deg2rad(23.439);   % rad       

% Air properties
rho = 1.31e-17*1000;     % Kg/m^3 @ 800km
C_d = 2.2;

% Reflection cofficients
rho_s = 0.5;
rho_d = 0.1;

% Earth's magnetic axis inclination 
alpha_m = deg2rad(11);

% Earth's magnetic radius 
a_m = 6371.2;         % m

% IGRF 2005 Contants
g_1_0 = -29554*10^-9;      % T
g_1_1 = -1669.05*10^-9;    % T
h_1_1 = 5077.99*10^-9;     % T

H_0 = sqrt((g_1_0)^2 + (g_1_1)^2 + (h_1_1)^2);  % T

% Vacuum permeability, to convert m^3*T in A*m^2
mu_0 = 4*pi*1e-7;            % T*m/A

% Magnitude of the dipole
m_m = (a_m^3*H_0)*(4*pi/mu_0);  % Am^2

%% CONTROL 

% We want to be aligned with the LVLH frame, so

q_c = [0 0 0 1]';

%% LAUNCH SIMULATOR

simulation_time = (2*pi*sqrt(a^3/mu));
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

% Drag Torque
figure(5)
hold on
plot(srp_torque(1:end,1)); plot(srp_torque(1:end,2)); plot(srp_torque(1:end,3));
title('Disturbance Torque due to Solar Radiation Pressure')
legend('SRP_x','SRP_y','SRP_z')

% Drag Torque
figure(6)
hold on
plot(magnetic_torque(1:end,1)); plot(magnetic_torque(1:end,2)); plot(magnetic_torque(1:end,3));
title('Disturbance Torque due to Earth''s Magnetic Field')
legend('MT_x','MT_y','MT_z')

% Error on attitude
figure(7)
hold on
plot(w_bl(1:end,1)); plot(w_bl(1:end,2)); plot(w_bl(1:end,3));
title('Error between BFF and RF')
legend('x','y','z')
        
%{
   TODO : 
           * Quaternions          
%}


    

          
