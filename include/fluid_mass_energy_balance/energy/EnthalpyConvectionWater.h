/****************************************************************/
/*             DO NOT MODIFY OR REMOVE THIS HEADER              */
/*          FALCON - Fracturing And Liquid CONvection           */
/*                                                              */
/*       (c) pending 2012 Battelle Energy Alliance, LLC         */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#ifndef ENTHALPYCONVECTIONWATER
#define ENTHALPYCONVECTIONWATER

#include "Kernel.h"
#include "Material.h"

//Forward Declarations
class EnthalpyConvectionWater;

template<>
InputParameters validParams<EnthalpyConvectionWater>();

class EnthalpyConvectionWater : public Kernel
{
public:

  EnthalpyConvectionWater(const std::string & name, InputParameters parameters);

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();
  virtual Real computeQpOffDiagJacobian(unsigned int jvar);

    const MaterialProperty<Real> & _Dtau_waterDH;
    const MaterialProperty<Real> & _Dtau_waterDP;
    const MaterialProperty<RealGradient> & _darcy_mass_flux_water;
    const MaterialProperty<Real> & _tau_water;
    const MaterialProperty<Real> & _enthalpy_water;
    const MaterialProperty<Real> & _denthalpy_waterdH_P;
    const MaterialProperty<Real> & _denthalpy_waterdP_H;

    unsigned int  _p_var;
    VariableGradient & _grad_p;


};
#endif //ENTHALPYCONVECTIONWATER
