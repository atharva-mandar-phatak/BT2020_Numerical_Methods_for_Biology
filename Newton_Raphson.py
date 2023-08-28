# Shree
import sympy
from sympy import *
import numpy

x = sympy.symbols('x')
# x=sp.var('x')
f1 = input("Enter the function in variable x ")
f1_sympified = sympy.sympify(f1)

# Finding the root of the equation
root = (nsolve(f1_sympified, 0, dict=True))
root_value = root[0].get(x)

# print(f1_sympified)
# print(root_value)

# Finding the derivative for the inputed function
der_f1 = diff(f1, x, 1)
der_f1_sympified = sympy.sympify(der_f1)
# print(der_f1_sympified)

# Newton Raphson Method
a = float(input("Enter the initial guess : "))
iter = int(input("Enter the number of iteration required : "))
numerator_function = lambda t: f1_sympified.subs(x, t).evalf()
denominator_fucntion = lambda t: der_f1_sympified.subs(x, t).evalf()

# print((numerator_function(a)))
# print((denominator_fucntion(a)))

output_array = []

for i in range(iter):
    et = ((root_value - a) / (root_value)) * 100  # True error calculations
    et=round(abs(et),5)
    output_array.append([i, round(a,5), et])

    a = (a) - numerator_function(a) / denominator_fucntion(a)

    # print(a)
print(output_array)
