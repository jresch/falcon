#include "ImplicitEuler.h"

#ifndef COUPLEDDARCYIMPLICITEULER
#define COUPLEDDARCYIMPLICITEULER

//Forward Declarations
class CoupledDarcyImplicitEuler;

template<>
InputParameters validParams<CoupledDarcyImplicitEuler>();

class CoupledDarcyImplicitEuler : public Kernel
{
public:

  CoupledDarcyImplicitEuler(std::string name, MooseSystem & moose_system, InputParameters parameters);

protected:
  virtual Real computeQpResidual();

  virtual Real computeQpJacobian();

   VariableValue & _enthalpy;


   MaterialProperty<Real> & _porosity;
   MaterialProperty<Real> & _rho;
   MaterialProperty<Real> & _rho_old;
   MaterialProperty<Real> & _sat_w;
   MaterialProperty<Real> & _sat_s;
   MaterialProperty<Real> & _Hw;
   MaterialProperty<Real> & _Hs;

     Real E3;
     Real E6;
     Real a1;
     Real a2;
     Real b1;
     Real b2;
     Real b3;
     Real b4; 
  
};
#endif //COUPLEDDARCYIMPLICITEULER