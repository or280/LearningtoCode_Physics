#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on ...

@author: Ollie

Title: Program to plot the diffraction pattern of a single slit of width d.
"""

import scipy.integrate as integrate
from numpy import pi, sqrt, cos, sin
import matplotlib.pyplot as plt
import numpy as np

# Set up parameters.

d = 0.0002
D = 1.0
l = 0.000000005
k = 2*pi/l
X = []
Y = np.linspace(-2.0,2.0,100)

# Do integration.

for n in range(-200,200,4):
    m = n/100
    real = (integrate.quad(lambda y: cos(k*(sqrt((m-y)**2+D**2))), d/2.0, -d/2.0))
    imag = (integrate.quad(lambda y: sin(k*(sqrt((m-y)**2+D**2))), d/2.0, -d/2.0))
    X.append((real[0])**2 + (imag[0])**2)
    
    
print(X)


plt.plot(Y,X,'g-')
plt.show()