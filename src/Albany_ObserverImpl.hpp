//*****************************************************************//
//    Albany 3.0:  Copyright 2016 Sandia Corporation               //
//    This Software is released under the BSD license detailed     //
//    in the file "license.txt" in the top-level Albany directory  //
//*****************************************************************//
#ifndef ALBANY_OBSERVER_IMPL_HPP
#define ALBANY_OBSERVER_IMPL_HPP

#include <string>

#include "Albany_StatelessObserverImpl.hpp"
#include "Piro_ROL_ObserverBase.hpp"

namespace Albany {

class ObserverImpl : public StatelessObserverImpl,
                     public Piro::ROL_ObserverBase<ST>
{
public:
  explicit ObserverImpl(const Teuchos::RCP<Application>& app);

  // Bring in scope the version we don't override
  using StatelessObserverImpl::observeSolution;

  // Override from ROL_ObserverBase
  void observeSolution (double stamp, const Thyra_Vector& x,
                        const Teuchos::Ptr<const Thyra_MultiVector>& x_dxdp,
                        const Teuchos::Ptr<const Thyra_Vector>& x_dot,
                        const Teuchos::Ptr<const Thyra_Vector>& x_dotdot) override;

  void observeSolution (double stamp,
                        const Thyra_MultiVector& x, 
                        const Teuchos::Ptr<const Thyra_MultiVector>& dxdp) override;

  void parameterChanged (const std::string& param) override;

  void parametersChanged() override;
  
  void observeResponse(int iter) override;
};

} // namespace Albany

#endif // ALBANY_OBSERVER_IMPL_HPP
