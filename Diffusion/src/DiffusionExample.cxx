//DiffusionExample.cxx

//Sample 1D diffusive lattice Boltzmann simulation using LB class

#include <string>
#include <cmath>
#include "LB.h"

using namespace std;

int main() {

  LB1D lbdiff(3, 64, 1., 1./3., 100.);    //Create LB object
  
  lbdiff.Initialize();										//Initialize simulation

  lbdiff.PrintData("Data/LBInit.dat");		//Output initial density profile
  
  while (lbdiff.iterations < 10000) {
    lbdiff.Iteration();										//Perform simulation for 10000 time steps
  }

  lbdiff.PrintData("Data/LBOut.dat");			//Output final profile

  return 0;
} 
