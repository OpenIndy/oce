// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Plate_D2_HeaderFile
#define _Plate_D2_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <gp_XYZ.hxx>
class Plate_GtoCConstraint;
class Plate_FreeGtoCConstraint;
class gp_XYZ;


//! define an order 2 derivatives of a 3d valued
//! function of a 2d variable
class Plate_D2 
{
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT Plate_D2(const gp_XYZ& duu, const gp_XYZ& duv, const gp_XYZ& dvv);
  
  Standard_EXPORT Plate_D2(const Plate_D2& ref);


friend class Plate_GtoCConstraint;
friend class Plate_FreeGtoCConstraint;


protected:





private:



  gp_XYZ Duu;
  gp_XYZ Duv;
  gp_XYZ Dvv;


};







#endif // _Plate_D2_HeaderFile
