#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on ...

@author: Ollie

Title: Program to solve for various coefficients at the interface of two materials.
"""

import numpy as np
import math
import cmath
import matplotlib.pyplot as plt

# Input boundary conditions

Z1 = 1.0 + 0.0j
Z2 = 3.0 + 0.0j
Z3 = 4.0 + 0.0j
k2 = 2*(math.pi)
j = 0.0 + 1.0j

r = []
a = []
b = []
t = []
phase_r = []
phase_a = []
phase_b = []
phase_t = []
amp_r = []
amp_a = []
amp_b = []
amp_t = []

for x in range(1,100,1):
    l = x/100
    A = np.array([[-1.0 + 0.0j,1.0 + 0.0j,1.0 + 0.0j,0.0 + 0.0j],[1.0 + 0.0j,(Z1/Z2) + 0.0j,(-Z1/Z2) + 0.0j,0.0 + 0.0j],[0.0 + 0.0j,(math.cos(-k2*l) + math.sin(-k2*l)*j),(math.cos(k2*l) + math.sin(k2*l)*j),-1.0 + 0.0j],[0.0 + 0.0j,(math.cos(-k2*l) + math.sin(-k2*l)*j),(math.cos(k2*l) - math.sin(k2*l)*j),(-Z2/Z3) + 0.0j]])
    B = np.array([1.0 + 0.0j,1.0 + 0.0j,0.0 + 0.0j,0.0 + 0.0j])
    C = np.linalg.solve(A,B)
    r.append(C[0])
    a.append(C[1])
    b.append(C[2])
    t.append(C[3])


for i in range(0,99,1):
    phase_r.append(cmath.polar(r[i])[1])
    phase_a.append(cmath.polar(a[i])[1])
    phase_b.append(cmath.polar(b[i])[1])
    phase_t.append(cmath.polar(t[i])[1])
    amp_r.append(cmath.polar(r[i])[0])
    amp_a.append(cmath.polar(a[i])[0])
    amp_b.append(cmath.polar(b[i])[0])
    amp_t.append(cmath.polar(t[i])[0])

length = range(0,99,1)
plt.plot(length,amp_r,'b-')
plt.plot(length,amp_a,'g-')
plt.plot(length,amp_b,'r-')
plt.plot(length,amp_t,'y-')

#plt.plot(length,phase_r,'b.')
#plt.plot(length,phase_a,'g.')
#plt.plot(length,phase_b,'r.')
#plt.plot(length,phase_t,'y.')









