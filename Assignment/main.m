%    CuSiTo - CUbesat SImulation Toolbox
%    Copyright (C) 2018 - Francescodario Cuzzocrea 
%    francescodario.cuzzocrea@mail.polimi.it
%
%    This program is free software; you can redistribute it and/or modify
%    it under the terms of the GNU General Public License as published by
%    the Free Software Foundation; either version 3 of the License, or
%    (at your option) any later version.
%    This program is distributed in the hope that it will be useful,
%    but WITHOUT ANY WARRANTY; without even the implied warranty of
%    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
%    GNU General Public License for more details.
%    You should have received a copy of the GNU General Public License
%    along with this program; if not, write to the Free Software Foundation,
%    Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
%
%    You should have received a copy of the GNU General Public License
%    along with this program.  If not, see <http://www.gnu.org/licenses/>.

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
M = 12.00;                          % Kg

% Dimensions
w = 100*10^-3;                      % m
l = 226.3*10^-3;                    % m
h = 340.5*10^-3;                    % m
dim = [w, l, h];

%Sections
A_i_1 = w*l;                        % m^2
A_i_2 = w*h;                        % m^2
A_i_3 = l*h;                        % m^2
A_i = [A_i_1, A_i_2, A_i_3];

I_1 = M/12 * (w^2 + l^2);           % Kg * m^2
I_2 = M/12 * (w^2 + h^2);           % Kg * m^2
I_3 = M/12 * (l^2 + h^2);           % Kg * m^2

I = [I_1,   0,  0;
        0,I_2,  0;
        0,  0, I_3];   
    
I_inv = inv(I);

%% INITIAL CONDITIONS

% Standard gravitational parameter
mu = 398600;                        % Km^3/s^2

% Radius of the Earth 
R_e = 6.378e+03;                    % Km

% Test omegas
w1_0 = 0.022;                        % rad/s
w2_0 = 0.058;                        % rad/s
w3_0 = 0.039;                        % rad/s
w_0 = [w1_0,w2_0,w3_0];
%w_0 = [0.01;0.01;0.01];

% Initial Attitude
q_0 = [0;0;0;1];
A_BN_0 = quat2dcm([q_0(4), q_0(1), q_0(2), q_0(3)]);

% Euler Angles
phi_0 = 0;                          % Degrees
theta_0 = 0;                        % Degrees
psi_0 = 0;                          % Degrees

% LVLH Orbit 
r_a = 800 + R_e;                    % Km
r_p = 800 + R_e;                    % Km
a = (r_a + r_p)/2;                  % Km
e = (r_a - r_p)/(r_a + r_p);
i = 60;                             % Degrees
OMG = 0;                            % Degrees
omg = 0;                            % Degrees
theta = 0;                          % Degrees

%% CONDITIONS FOR DISTURBANCES

% Nadir vector for gravity gradient computation
nadir_vector = [1; 0; 0];

% Angular velocity of the Earth
w_e = [0 0 0.00007291];             % rad/s

% Sun Mean Motion
n = 2*pi/(60*60*24*365);            % rad/s   

% Obliquity of the ecliptic plane
epsilon = deg2rad(23.439);          % rad       

% Air properties
rho = 1.31e-17*1000;                % Kg/m^3 @ 800km
C_d = 2.2;

% Reflection cofficients
rho_s = 0.5;
rho_d = 0.1;

% Load Schmidt quasi-normalized IGRF coefficients for magnetic field
% generation
load('igrf_normalized_coefficient.mat')

% Earth's magnetic axis inclination 
alpha_m = deg2rad(11);

% Earth's magnetic radius 
a_m = 6371.2;                       % Km

%% ACTUATORS PROPERTIES

% Magnetic Actuator
m_max = 1.2;                        % Am^2

% Reaction Wheels
max_torque = 0.635;                  % Nm
max_momentum = 11.076;               % Nms

%% SENSOR PROPERTIES

% Magnetometer
psi = deg2rad(1.5);
tetha = deg2rad(1.5);
phi = deg2rad(1.5);

A_epsilon = [cos(psi)*cos(tetha),  cos(psi)*sin(tetha)*sin(phi)+sin(psi)*cos(phi), -cos(psi)*sin(tetha)*cos(phi)+sin(psi)*sin(phi);
            -sin(psi)*cos(tetha), -sin(psi)*sin(tetha)*sin(phi)+cos(psi)*cos(phi),  sin(psi)*sin(tetha)*cos(phi)+cos(psi)*sin(phi);
                    sin(tetha)  ,               -cos(tetha)*sin(phi)             ,              cos(tetha)*cos(phi)                 ];

% Gyroscope
sigma_e = 4.84814e-6;

%% CONTROLLER SETUP

% Gains
k_bdot = -((4*pi)/((2*pi*sqrt(a^3/mu))) * (1 + sin(deg2rad(38.5))) * min([I_1,I_2,I_3]))*100000;
k_p = -0.0003;
k_d = -0.07;

% Commanded quaternion for inertial pointing 
q_c = [0; -0.1542; 0.9880; 0];

%% LAUNCH SIMULATOR

simulation_time = (2*pi*sqrt(a^3/mu));
sim assignment    

% %% OUTPUTS PLOT

% Pointing vector
figure(1)
plot3(X_P(1,:),X_P(2,:),X_P(3,:)); 

% Reference orbit
figure(2)
plot3(r_LVLH(:,1),r_LVLH(:,2),r_LVLH(:,3))

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

% Solar Radiation Pressure Torque
figure(5)
hold on
plot(srp_torque(1:end,1)); plot(srp_torque(1:end,2)); plot(srp_torque(1:end,3));
title('Disturbance Torque due to Solar Radiation Pressure')
legend('SRP_x','SRP_y','SRP_z')

% Magnetic Field Torque
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
