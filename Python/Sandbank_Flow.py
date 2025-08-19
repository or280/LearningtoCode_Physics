#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on ...

@author: Ollie

Title: Program to plot the flow potential and velocities of flow over a sandbank.
"""

from mpl_toolkits import mplot3d
import numpy as np
import matplotlib.pyplot as plt

a = 2.0

def f1(x, y):
    return (4/3 * x1)

theta1 = 2 * np.pi * np.random.random(1000)
r1 = 2 * np.random.random(1000)
x1 = np.ravel(r1 * np.sin(theta1))
y1 = np.ravel(r1 * np.cos(theta1))
z1 = f1(x1, y1)

def f2(x2, y2):
    return (1 - a**2/(3*(x2*x2+y2*y2))) * x2/((x2*x2+y2*y2)**0.5)

theta2 = 2 * np.pi * np.random.random(1000)
r2 = 2 + 2 * np.random.random(1000)
x2 = np.ravel(r2 * np.sin(theta2))
y2 = np.ravel(r2 * np.cos(theta2))
z2 = f2(x2, y2)

ax = plt.axes(projection='3d')
ax.scatter(x2, y2, z2, c=z2, cmap='viridis', linewidth=0.5);

ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('Potential');
ax.view_init(30, 135)