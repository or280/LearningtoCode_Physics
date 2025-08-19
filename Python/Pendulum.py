#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on ...

@author: Ollie

Title: Program to solve motion of a pendulum numerically.
"""

import numpy as np
from scipy.integrate import odeint
import matplotlib.pyplot as plt
from math import pi

def model(z,t):
    x = z[0]
    y = z[1]
    dxdt = y
    dydt = -(np.sin(x))
    dzdt = [dxdt,dydt]
    return dzdt

# initial condition
z0 = [1,0]

# time points
t = np.linspace(0,100,500)

# solve ODE
z = odeint(model,z0,t)

# plot results
plt.plot(t,z[:,0],'b-')
plt.ylabel('Theta displacement/rad')
plt.xlabel('Time/s')
plt.show()
