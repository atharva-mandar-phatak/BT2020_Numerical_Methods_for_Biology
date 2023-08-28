# Shree
import sympy
from sympy import *

x = sympy.symbols('x')
f1 = input("Enter the function in variable x : ")
f1_sympified = sympy.sympify(f1)

# Finding the root of the equation
# root = (nsolve(f1_sympified, 0, dict=True))
root_value = float(input("Input true value : "))

f = lambda t: f1_sympified.subs(x, t).evalf()

x_l = float(input("Enter the lower cap : "))
x_u = float(input("Enter the upper cap : "))

# x_r=(x_l+x_u/2)
output_array = []
iter = int(input("Nummber of Iterations : "))
for i in range(iter):
    x_r = ((x_l + x_u) / 2)

    # True error calculations
    et = ((root_value - x_r) / (root_value)) * 100
    et = round(abs(et), 5)

    # Absolute error calculation
    if (i == 0):
        ea = 'NIL'
    else:
        ea = ((x_r - xr_0) / (x_r)) * 100
        ea = round(abs(ea), 5)
    output_array.append([i, x_r, et, ea])

    # Bisection Method
    if ((f(x_l) * f(x_r)) < 0):
        x_u = x_r
    if ((f(x_l) * f(x_r)) > 0):
        x_l = x_r
    if ((f(x_l) * f(x_r)) == 0):
        print("The rot of equation is :", x_r)
        break
    xr_0 = x_r
print(output_array)
