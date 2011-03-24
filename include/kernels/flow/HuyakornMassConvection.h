#ifndef HUYAKORNMASSCONVECTION
#define HUYAKORNMASSCONVECTION

#include "Diffusion.h"
#include "Material.h"

//Forward Declarations
class HuyakornMassConvection;

template<>
InputParameters validParams<HuyakornMassConvection>();

class HuyakornMassConvection : public Diffusion
{
public:

  HuyakornMassConvection(const std::string & name, InputParameters parameters);
    
protected:
  virtual Real computeQpResidual();

  virtual Real computeQpJacobian();

  MaterialProperty<Real> &_tau;

  
};
#endif //HUYAKORNMASSCONVECTION