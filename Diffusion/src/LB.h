//LB.h

#ifndef LB_H
#define LB_H

//Base Lattice Boltzmann class.
class LB {
  //This class will house the baseline LB information. 

  //Class attributes
  protected:
		int *V;         //Velocity set array
		double tau;         //Relaxation time
		double theta;       //Lattice temperature

  public:
    int iterations;     //Iteration counter
    //int dims;           //Number of required spatial dimensions of lattice
													//I intend to make this an input option to determine dimensions of simulation
  //Class methods
		//Have no needed methods yet. This may be removed if unnecessary
};

class LB1D: public LB {

  public:			//I should check to see what's needed as public, private, and protected for more careful code

  //Class attributes
  int vdims;                  //velocity set dimensions
  int xdim;                   //Size of lattice's x-dimension
  double **f;                 //Distribution functions
  double *rho;           			//Density array
  double *w;
  double rho0;                //Initial density

  //Constructor - This takes initial values and allocates all necessary arrays
  LB1D(int vdimIn, int xdimIn, double tauIn, double thetaIn, double rho0In) {
    vdims = vdimIn;
    xdim = xdimIn;
    tau = tauIn;
    theta = thetaIn;
    rho0 = rho0In;

    AllocateArrays();
  }
  

  //Class methods
  void AllocateArrays();											//Allocate arrays
  void SetWeights();													//Set values or weights
  void Initialize();													//Initialize simulation
  void Stream();															//Perform LB streaming step
  void Collision();														//Perform LB collision step
  void Iteration();														//Perform LB iteration step
  void PrintData(std::string fileName);				//Output data to .dat file
																								//Why .dat? Because I like it, that's why.
};

#endif
