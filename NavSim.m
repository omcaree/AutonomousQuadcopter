function NavSim
% Target Positions
targets = [0 1; 1 0; 0 -1; -1 0; 1.5 1.5];

% Some constants
dt = 0.1;
range = 1;

% Actual position values
x(1) = 1.5;
y(1) = 0;
z(1) = 1;

% Kalman filter variables
myKF.X = [1.5 0 1 0 0]';    % State estimate
myKF.P = eye(5);            % Covariance estimate
myKF.A = [1 0 0 dt 0; 0 1 0 0 dt; 0 0 1 0 0; 0 0 0 0 0; 0 0 0 0 0];     % State evolution matrix
myKF.B = [0 0; 0 0; 0 0; 1 0; 0 1];         % Control evolution matrix
myKF.C = [1 0 0 0 0; 0 1 0 0 0; 0 0 1 0 0]; % Measurement matrix
myKF.Q = 50000*eye(5);
myKF.R = eye(3);

x_est2(1) = myKF.X(1);
y_est2(1) = myKF.X(2);
e_est(1) = sqrt(myKF.P(1,1)+myKF.P(2,2));

for i=2:600
    x(i) = 1.5*cos(i*dt*0.1);
    y(i) = 1.5*sin(i*dt*0.1);
    
    u = [x(i) - x(i-1); y(i) - y(i-1)]/dt;
    
    u(1) = normrnd(u(1),0.2);
    u(2) = normrnd(u(2),0.2);
    
    myKF = TimeUpdate(myKF,u);
    x_est = myKF.X(1);
    y_est = myKF.X(2);    
    
    for j=1:length(targets)
        d_x(j) = targets(j,1) - x(i);
        d_y(j) = targets(j,2) - y(i);
        d(j) = sqrt(d_x(j)^2 + d_y(j)^2);
        
        d_x2(j) = targets(j,1) - x_est;
        d_y2(j) = targets(j,2) - y_est;
        d2(j) = sqrt(d_x2(j)^2 + d_y2(j)^2);
    end
    d_x_local = d_x(d<range);
    d_y_local = d_y(d<range);
    
    for j=1:length(d_x_local)
        for k=1:length(d_x2)
            dd = sqrt((d_x_local(j) - d_x2(k))^2 + (d_y_local(j) - d_y2(k))^2);
            if (dd<0.2)
                z(1) = targets(k,1) - d_x_local(j);
                z(2) = targets(k,2) - d_y_local(j);
                z(3) = 1;
                z(1) = normrnd(z(1),0.05);
                z(2) = normrnd(z(2),0.05);
                z(3) = normrnd(z(3),0.05);
                myKF = MeasurementUpdate(myKF,z');
            end
        end
    end
    x_est2(i) = myKF.X(1);
    y_est2(i) = myKF.X(2);
    e_est(i) = sqrt(myKF.P(1,1)+myKF.P(2,2));
end

hold on;
plot(targets(:,1),targets(:,2),'r*')
plot(x_est2,y_est2,'rx');
plot(x,y)
axis equal

figure
plot(e_est);
hold off;
end

function kf_est = TimeUpdate(kf, u)
    kf_est = kf;
    kf_est.X = kf.A * kf.X + kf.B * u;
    kf_est.P = kf.A * kf.P * kf.A' + kf.Q;
end

function kf_m = MeasurementUpdate(kf, z)
    kf_m = kf;
    K = kf.P*kf.C'*(kf.C*kf.P*kf.C' + kf.R)^-1;
    kf_m.X = kf.X + K*(z - kf.C*kf.X);
    kf_m.P = (eye(5) - K*kf.C)*kf.P;
end