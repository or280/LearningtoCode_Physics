#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on ...

@author: Ollie

Title: Program to plot a wave with a given dispersion relation.
"""

import numpy as np
import matplotlib.pyplot as plt
from math import pi


m0 = 30
k0 = 1.0
sigmak = k0/10.0
deltak = sigmak/10.0
c = 1.0
d = 0.10
t = pi
y1 = 0.0
y2 = 0.0
x = np.linspace(0,50,5000)

for m in range (-m0, m0):
    km = k0 + m * deltak
    w = c * km + d * km**3
    y1 = y1 + np.exp((-(km-k0)**2)/(2*(sigmak**2)))*(np.cos(km*x-w*t))
    
    
# plot results
plt.plot(x,y1,'b-')
#plt.ylabel('Displacement/m')
#plt.xlabel('Distance/m')
plt.show()


# Now observing a travelling square wave rather than a sinusoid.

for m in range (0, m0):
    km = (2*m+1)*k0
    w = c * km + d * km**3
    y2 = y2 + (((-1)**m)/(2*m+1))*(np.cos(km*x-w*t))
    
    
# plot results
#plt.plot(x,y2,'b-')
#plt.ylabel('Displacement/m')
#plt.xlabel('Distance/m')
#plt.show()
    