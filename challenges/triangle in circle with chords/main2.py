#!/usr/bin/env python3
"""
Module Docstring
"""

__author__ = "Jude Shreffler"
__version__ = "0.0.0"
__license__ = "MIT"


import random
import math

SIDE_LENGTH = math.sqrt(3)
NUM_RUNS = 10000000

def main():
    #generating our points
    pointsInCircle = []

    for i in range(NUM_RUNS):
        pointsInCircle.append([(random.random() * 2 * math.pi), (random.random())])
    
    #checking how many are longer and how many are shorter
    longer = 0
    shorter = 0
    for i in pointsInCircle:
        if (2*math.sqrt(1 - ()))



if __name__ == "__main__":
    """ This is executed when run from the command line """
    main()