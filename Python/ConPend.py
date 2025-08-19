#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on ...

@author: Ollie

Title: Program to show the osciallations of a conical pendulum.
"""

from numpy import cos, sin, linspace
import matplotlib.pyplot as plt

# Set up some paramaters.

g = 9.81
l = 1
theta0 = 0.1
t = linspace(0,3,500)
A = 0

w = ((g/(l*cos(theta0)))*(1+(cos(theta0))**2))**0.5
theta = A*cos(w*t)
r = l*sin(theta+theta0)
phi = ((g/(l*cos(theta0)))**0.5) * t

x = r*cos(phi)
y = r*sin(phi)

plt.plot(y,x,'g-')
plt.show()