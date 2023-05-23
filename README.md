# Lattice Boltzmann C++ Library

## About

This is a simple library which is intended to allow for easy implementation of lattice Boltzmann simulations, by implementing a class structure to handle all underlying mechanics of the simulation. The goal is give input options and handle all computation automatically.

## Contents
	1. Features
	2. Structure
	3. Future Plans

## 1. Features
The LB library is currently only able to implement 1D diffusive simulations. 2D and 3D implementations are planned as well as hydrodynamic counterparts. An example simulation is given in DiffusionExample.cxx There is a simple python script which can be used to create quick and dirty plots of simulation results for testing. 

## 2. Structure
The current structure is based on the LB class which the baseline algorithm utilizes. In the current state, there is no need to actually use any LB base class objects.

The structure of the classes are as follows:
	LB -> LB1D

LB1D is a child class of LB containing all necessary attributes of LB. DiffusionExample.cxx uses LB1D objects to perform simple diffusion of a sine wave profile.

	### Files
		-LB.h -> Main header file defining all classes
		-LB1D.cxx -> All methods of LB1D class
		-DiffusionExample.cxx -> Example simulation using LB1D objects.
		-printOutput.py -> Simple python script to create plots of simulation output. Requires numpy and matplotlib  

## 3. Future Plans
	1. Extend to hydrodynamic cases
	2. Extend to 2D and 3D
	3. Add external forcing
	4. Improve on python scripting

Any questions, comments, concerns are welcome. Please contact me at my email below.

Kyle Strand
ktstrandphd@gmail.com

