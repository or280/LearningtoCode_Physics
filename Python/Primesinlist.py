#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on ...

@author: Ollie

Title: Program to determine the number of primes in a list.
"""

def primesinlist(mylist):
    
    primes = []
    
    for x in mylist:
        if x > 1:
            for n in range (2,x):
                if x % n == 0:
                    break
            else:
                primes.append(x)
            
    return primes
            


mylist1 = list(range(1,100))

print(primesinlist(mylist1))
