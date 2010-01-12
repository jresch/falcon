#ifndef OUTFLOWBC_H
#define OUTFLOWBC_H

#include "BoundaryCondition.h"

//libMesh includes
#include "vector_value.h"


//Forward Declarations
class OutFlowBC;

template<>
InputParameters validParams<OutFlowBC>();

/**
 * Implements a simple constant VectorNeumann BC where grad(u)=value on the boundary.
 * Uses the term produced from integrating the diffusion operator by parts.
 */
class OutFlowBC : public BoundaryCondition
{
public:

  /**
   * Factory constructor, takes parameters so that all derived classes can be built using the same
   * constructor.
   */
  OutFlowBC(std::string name, InputParameters parameters, std::string var_name, unsigned int boundary_id, std::vector<std::string> coupled_to, std::vector<std::string> coupled_as);
  
 virtual ~OutFlowBC(){}

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();
  
private:
  /**
   * Vector to dot with the normal.
   */
  Real _cond,_porosity,_diff;
  
//  std::vector<RealGradient> & _grad_p;
  
};

#endif //NEUMANNBC_H