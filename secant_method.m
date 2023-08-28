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
x2 = input('Enter second val: ');

%Acceptable Et
E=1e-6;

%Starts Here
f1=f(x1);
f2=f(x2);
ct=0;
while abs(f2)>E && ct<100
    x3= x2 - f2*(x2-x1)/(f2-f1);
    x1=x2;
    x2=x3;
    f1=f2;
    f2=f(x2);
    ct=ct+1;
end

fprintf('Number of Iterations: %d\n', ct);
fprintf('Root is: %f\n', x2)
plot(x2,f2,'*');