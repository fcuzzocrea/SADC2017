% Plot ellissoidi 

I1 = 0.0109;
I2 = 0.0504;
I3 = 0.0304;

H = [I_1*w_1, I_2*w_2, I_3*w_3];
T = 1/2*[I_1*w_1.^2, I_2*w_2.^2, I_3*w_3.^2];
H = norm(H);
T = norm(T);

a = sqrt(H/I1);
b = sqrt(H/I2);
c = sqrt(H/I3);
[theta,phi] = ndgrid(linspace(0,2*pi,50),linspace(0,pi,50));

x = a*sin(theta).*cos(phi);
y = b*sin(theta).*sin(phi);
z = c*cos(theta);

a1 = sqrt(T)/I1;
b1 = sqrt(T)/I2;
c1 = sqrt(T)/I3;
x1 = a1*sin(theta).*cos(phi);
y1 = b1*sin(theta).*sin(phi);
z1 = c1*cos(theta);

ang=0:0.0005:2*pi; 
A = sqrt((I3*H - T)/(I1*I3 - I1^2));
B = sqrt((I3*H - T)/(I2*I3 - I2^2));
xp= A*cos(ang);
yp= B*sin(ang);
zp= sqrt(1/I3*(H - xp.^2*I1 - yp.^2*I2));
zpm = -sqrt(1/I3*(H - xp.^2*I1 - yp.^2*I2));
zp(find(imag(zp)~=0 )) = NaN;
zpm(find(imag(zpm)~=0 )) = NaN;

figure(1)
hold on
grid on
surf(x,y,z,'FaceColor', [0.5 1.0 0], 'EdgeColor', 'none')
surf(x1,y1,z1,'FaceColor', [1 0.2 0], 'EdgeColor', 'none')
alpha 0.3
plot3(xp,yp,zp,'k','LineWidth',2);
plot3(xp,yp,zpm,'k','LineWidth',2);
hold off
xlabel('x')
ylabel('y')
zlabel('z')
hold off
axis vis3d
camlight




