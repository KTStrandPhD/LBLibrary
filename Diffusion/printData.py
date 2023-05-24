#Simple script for printing plots of LB output.
  #This currently prints the initial and equilibrium profiles
  #These outputs were gathered from main.cxx using LB1D class
  #This is a simple example to show that the class does perform a proper diffusive LB simulation 

import matplotlib.pyplot as plt
import numpy as np

indicesIn = []
rhoIn = []
indicesOut = []
rhoOut = []

fileIn = open("Data/LBInit.dat", "r")
fileOut = open("Data/LBout.dat", "r")

for row in fileIn:
  row = row.split(' ')
  indicesIn.append(int(row[0]))
  rhoIn.append(float(row[1]))

for row in fileOut:
  row = row.split(' ')
  indicesOut.append(int(row[0]))
  rhoOut.append(float(row[1]))

plt.xlabel("Lattice Position", fontsize = 12)
plt.ylabel("Density", fontsize = 12)

plt.title("LB Density Profile")
plt.plot(indicesIn, rhoIn, label = "Initial Profile")
plt.plot(indicesOut, rhoOut, label = "10000 time steps")
plt.legend()
plt.show()
