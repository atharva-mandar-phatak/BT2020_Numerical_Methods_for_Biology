# Shree
import sympy
import numpy as np
from matplotlib import pyplot as plt
from sympy import *

x = sympy.symbols('x')
f1 = input("Enter the function in variable x : ")
f1_sympified = sympy.sympify(f1)
f = lambda t: f1_sympified.subs(x,t).evalf()
print(f(1))
#((686.06/x)* (1-exp(-0.146843*c)))-40
x_axis=[]
y_axis=[]

r1=int(input("Lower limit for range : "))
r2=int(input("Upper limit for range : "))
stp=int(input("Step size : "))
for i in range(r1,r2,stp):
    x_axis.append(i)
    y_axis.append(f(i))
# print(x_axis)
# print(y_axis)
#Plotting the graph
plt.plot(x_axis,y_axis)
plt.grid(color='black' ,linewidth = 1)

plt.show()