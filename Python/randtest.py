#!/usr/bin/env python3

from random import random

loops = 10000000
numupdates = 1000

def test(loops, testL, progprec):
    out = 0
    lastprint = -1
    for i in range(0, loops):
        if(lastprint != int(i / loops * progprec)):
            lastprint = int(i / loops * progprec)
            print(str(percent(lastprint, progprec, 1)) + " done, ", end='')
            print(str(percent(error(out, (i + 1) / 2), 1, 5)) + " error", end='')
            print("                                       ", end='\r')
        out += testL(random())
    return out

def percent(amount, total, precision = 2):
    return ("%." + str(precision) + "f") % round(float(amount) / total * 100, precision) + "%"

def error(experimental, theoretical):
    return abs((experimental - theoretical) / theoretical) * 100

def run(loops, testL, progprec):
    print(str(percent(error(test(loops, testL, progprec), loops / 2), 1, 5)) + " error", end='')
    print("                                       ")

run(loops, lambda x: x > 0.5,  numupdates)
run(loops, lambda x: x >= 0.5, numupdates)
run(loops, lambda x: x < 0.5,  numupdates)
run(loops, lambda x: x <= 0.5, numupdates)
