clear all;
close all;

%Set Function Here
f = @(x) x^2-3;

figure(1);
hold on;
ezplot(f);
grid on;

%Initial Guess
x1 = input('Enter first val: ');
h = input('Enter step size: ');

%Acceptable Et
E=1e-6;

%Starts Here
f1=f(x1);

ct=0;
while abs(f1)>E && ct<100
    x3= x1 - f1*h/(f(x1+h)-f1);
    x1=x3;
    f1=f(x1);
    ct=ct+1;
end

fprintf('Number of Iterations: %d\n', ct);
fprintf('Root is: %f\n', x1)
plot(x1,f1,'*');