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

#ifndef HUYAKORNBC_H
#define HUYAKORNBC_H

#include "IntegratedBC.h"


//Forward Declarations
class HuyakornBC;

template<>
InputParameters validParams<HuyakornBC>();

/**
 * Implements a simple constant Huyakorn BC where grad(u)=value on the boundary.
 * Uses the term produced from integrating the diffusion operator by parts.
 */
class HuyakornBC : public IntegratedBC
{
public:

  /**
   * Factory constructor, takes parameters so that all derived classes can be built using the same
   * constructor.
   */
  HuyakornBC(const std::string & name, InputParameters parameters);

virtual ~HuyakornBC() {}

protected:
  virtual Real computeQpResidual();

  VariableGradient & _grad_p;
  const MaterialProperty<Real> &_lamda;
  const MaterialProperty<Real> &_km;
  const MaterialProperty<Real> &_dT_dP;
private:
  Real _value;
};

#endif //HUYAKORNBC_H
