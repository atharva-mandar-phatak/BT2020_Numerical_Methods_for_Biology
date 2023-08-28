# Shree
import sympy
from sympy import *

x = sympy.symbols('x')
f1 = input("Enter the function in variable x ")
f1_sympified = sympy.sympify(f1)

# Finding the root of the equation
root = (nsolve(f1_sympified, 0, dict=True))
root_value = root[0].get(x)
# print(root_value)

f1a = f1 + '+(x)'
f1a_sympified = sympy.sympify(f1a)
# print(f1a_sympified)
gx = lambda t: f1a_sympified.subs(x, t).evalf()
output_array = []
a = float(input("Intial Guess: "))
iter = int(input("Nummber of Iterations: "))
a0 = a
for i in range(10):

    et = ((root_value - a) / (root_value)) * 100  # True error calculations
    et = round(abs(et), 5)
    # Absolute error calculation
    if (i == 0):
        ea = 'NIL'
    else:
        ea = ((a - a0) / (a)) * 100
        ea = round(abs(ea), 5)

    output_array.append([i, round(a, 5), ea, et])
    a0 = a
    a = gx(a)

print(output_array)
