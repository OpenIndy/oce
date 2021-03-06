// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _IGESSolid_Array1OfFace_HeaderFile
#define _IGESSolid_Array1OfFace_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <Standard_Integer.hxx>
#include <Standard_Address.hxx>
#include <Standard_Boolean.hxx>
#include <Handle_IGESSolid_Face.hxx>
class Standard_RangeError;
class Standard_DimensionMismatch;
class Standard_OutOfRange;
class Standard_OutOfMemory;
class IGESSolid_Face;



class IGESSolid_Array1OfFace 
{
public:

  DEFINE_STANDARD_ALLOC

  
    IGESSolid_Array1OfFace(const Standard_Integer Low, const Standard_Integer Up);
  
    IGESSolid_Array1OfFace(const Handle(IGESSolid_Face)& Item, const Standard_Integer Low, const Standard_Integer Up);
  
  Standard_EXPORT   void Init (const Handle(IGESSolid_Face)& V) ;
  
      void Destroy() ;
~IGESSolid_Array1OfFace()
{
  Destroy();
}
  
      Standard_Boolean IsAllocated()  const;
  
  Standard_EXPORT  const  IGESSolid_Array1OfFace& Assign (const IGESSolid_Array1OfFace& Other) ;
 const  IGESSolid_Array1OfFace& operator = (const IGESSolid_Array1OfFace& Other) 
{
  return Assign(Other);
}
  
      Standard_Integer Length()  const;
  
      Standard_Integer Lower()  const;
  
      Standard_Integer Upper()  const;
  
      void SetValue (const Standard_Integer Index, const Handle(IGESSolid_Face)& Value) ;
  
     const  Handle(IGESSolid_Face)& Value (const Standard_Integer Index)  const;
   const  Handle(IGESSolid_Face)& operator () (const Standard_Integer Index)  const
{
  return Value(Index);
}
  
      Handle(IGESSolid_Face)& ChangeValue (const Standard_Integer Index) ;
    Handle(IGESSolid_Face)& operator () (const Standard_Integer Index) 
{
  return ChangeValue(Index);
}




protected:





private:

  
  Standard_EXPORT IGESSolid_Array1OfFace(const IGESSolid_Array1OfFace& AnArray);


  Standard_Integer myLowerBound;
  Standard_Integer myUpperBound;
  Standard_Address myStart;
  Standard_Boolean isAllocated;


};

#define Array1Item Handle(IGESSolid_Face)
#define Array1Item_hxx <IGESSolid_Face.hxx>
#define TCollection_Array1 IGESSolid_Array1OfFace
#define TCollection_Array1_hxx <IGESSolid_Array1OfFace.hxx>

#include <TCollection_Array1.lxx>

#undef Array1Item
#undef Array1Item_hxx
#undef TCollection_Array1
#undef TCollection_Array1_hxx




#endif // _IGESSolid_Array1OfFace_HeaderFile
