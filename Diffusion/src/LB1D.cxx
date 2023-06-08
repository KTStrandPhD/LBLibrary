//LB1D.cxx

//Class for implementing 1D diffusive lattice Boltzmann simulations
  //This is a for a simple d1q3 LB model

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include "LB.h"

//Function to allocate arrays sized by constructor inouts
void LB1D::AllocateArrays() {

  w = new double [vdims];
  rho = new double [xdim];
  f = new double *[vdims];
  for (int a = 0; a < vdims; a++) {
    f[a] = new double[xdim];
  }
}

//Function to set value for weights
void LB1D::SetWeights() {
  
  w[0] = 1. - theta;
  w[1] = w[2] = theta/2.;
}

//Function to initialize a new LB simulation
void LB1D::Initialize() {

  iterations = 0;
  SetWeights();        
  for (int i = 0; i < xdim; i++) {
    rho[i] = rho0 * (1. + sin(2.*M_PI * i/xdim)); //sine wave, this is for testing. I will make this something that can be customized later.
    for (int a = 0; a < vdims; a++) {
      f[a][i] = rho[i]*w[a];
    }
  }
}

//Function to perform LB streaming step
void LB1D::Stream() {

  double tmp1 = f[1][xdim-1];
  double tmp2 = f[2][0];
  memmove(&f[1][1], &f[1][0], (xdim-1)*sizeof(double));
  memmove(&f[2][0], &f[2][1], (xdim-1)*sizeof(double));
  f[1][0] = tmp1;
  f[2][xdim-1] = tmp2;
}

//Function to perform LB collision
void LB1D::Collision() {

  for (int i = 0; i < xdim; i++) {
    for (int a = 0; a < vdims; a++) {
      f[a][i] += 1./tau*(rho[i] * w[a] - f[a][i]);
    }
  }  
}

//Function to perform each iteration step
void LB1D::Iteration() {

  for (int i = 0; i < xdim; i++) {
    rho[i] = 0;
    for (int a = 0; a < vdims; a++) {
      rho[i] += f[a][i];
    }
  }
  Collision();
  Stream();
  iterations++;
}

//Function to output data to block data file
  //This is only for the density at the moment.
  //I'll abstract this for much more later
void LB1D::PrintData(std::string fileName) {

  std::ofstream outFile(fileName);

  for (int i = 0; i < xdim; i++) {
    outFile << i << ' ' << rho[i] << ' ' << std::endl;
  }
  
  outFile.close();
}

