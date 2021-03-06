// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _ChFi3d_SearchSing_HeaderFile
#define _ChFi3d_SearchSing_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <Handle_Geom_Curve.hxx>
#include <math_FunctionWithDerivative.hxx>
#include <Standard_Boolean.hxx>
#include <Standard_Real.hxx>
class Geom_Curve;


//! Searches   singularities on fillet.
//! F(t) = (C1(t) - C2(t)).(C1'(t) - C2'(t));
class ChFi3d_SearchSing  : public math_FunctionWithDerivative
{
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT ChFi3d_SearchSing(const Handle(Geom_Curve)& C1, const Handle(Geom_Curve)& C2);
  
  //! computes the value of the function <F> for the
  //! variable <X>.
  //! returns True if the computation was done successfully,
  //! False otherwise.
  Standard_EXPORT   Standard_Boolean Value (const Standard_Real X, Standard_Real& F) ;
  
  //! computes the derivative <D> of the function
  //! for the variable <X>.
  //! Returns True if the calculation were successfully done,
  //! False otherwise.
  Standard_EXPORT   Standard_Boolean Derivative (const Standard_Real X, Standard_Real& D) ;
  
  //! computes the value <F> and the derivative <D> of the
  //! function for the variable <X>.
  //! Returns True if the calculation were successfully done,
  //! False otherwise.
  Standard_EXPORT   Standard_Boolean Values (const Standard_Real X, Standard_Real& F, Standard_Real& D) ;




protected:





private:



  Handle(Geom_Curve) myC1;
  Handle(Geom_Curve) myC2;


};







#endif // _ChFi3d_SearchSing_HeaderFile
