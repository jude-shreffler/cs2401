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
    pointsOnCircle = []

    #list of points on a circle
    for i in range(NUM_RUNS):
        pointsOnCircle.append(random.random() * 2 * math.pi)
    
    #checking how many chords are longer and how many are shorter
    shorter = 0
    longer = 0

    for i in pointsOnCircle:
        if (2*math.sin(i/2)) > (SIDE_LENGTH):
            longer += 1
        else:
            shorter += 1

    #output
    total = shorter + longer
    
    odds = longer/total * 100

    print(f"Odds of a random chord being longer than an inscribed equilateral triangle: {odds}")
    


if __name__ == "__main__":
    """ This is executed when run from the command line """
    main()