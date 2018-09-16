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

% First we consider a generic S/C
I_1 = 0.109; % Kg * m^2
I_2 = 0.0504; % Kg * m^2
I_3 = 0.55; % Kg * m^2

% Then we consider a simmetric S/C
I_1 = 0.109; % Kg * m^2
I_2 = 0.0504; % Kg * m^2
I_3 = 0.0504; % Kg * m^2


I = [I_1,   0,  0;
        0,I_2,  0;
        0,  0, I_3];   
    
I_inv = inv(I);    

%% INITIAL CONDITIONS

% Test omegas
w1_0 = 0.45;
w2_0 = 0.52;
w3_0 = 0.55;

w_0 = [w1_0, w2_0, w3_0];