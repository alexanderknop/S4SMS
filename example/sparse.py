#!/usr/bin/python

import sys

val = 0;
with open(sys.argv[1]) as f:    
    for line in f:
        x = int(line.split()[0])
        y = float(line.split()[1])
        val += y / 50.0
        if x % 50 == 49:
            print(x, " ", val)
            val = 0

