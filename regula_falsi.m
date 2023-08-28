clear all;
close all;

%Set Function Here
f = @(x) x^2-3;

figure(1);
hold on;
ezplot(f);
grid on;

%Initial Guess
xl = input('Enter Lower Guess: ');
xu = input('Enter Upper Guess: ');

%Acceptable Et
E=1e-6;

%Starts Here
fl=f(xl);
fu=f(xu);
fr=inf;
ct=0;
fprintf('\n\nxl\t\txu\t\txr\t\tf(r)\n');
while abs(fr)>E && ct<100
    xr = xu - fu*(xu-xl)/(fu-fl);
    fr=f(xr);
    fprintf('%f\t%f\t%f\t%f\n',xl,xu,xr,fr);
    if fr*fl<0
        xu=xr;
    elseif fr*fl>0
        xl=xr;
    end
    ct=ct+1;
end

fprintf('Number of Iterations: %d\n', ct);
fprintf('Root is: %f\n', xr)
plot(xr,fr,'*');