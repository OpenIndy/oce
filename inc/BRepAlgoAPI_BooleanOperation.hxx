// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _BRepAlgoAPI_BooleanOperation_HeaderFile
#define _BRepAlgoAPI_BooleanOperation_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <TopoDS_Shape.hxx>
#include <Standard_Boolean.hxx>
#include <BOPAlgo_Operation.hxx>
#include <Standard_Integer.hxx>
#include <BOPAlgo_PPaveFiller.hxx>
#include <BOPAlgo_PBuilder.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <BRepBuilderAPI_MakeShape.hxx>
class TopoDS_Shape;
class BOPAlgo_PaveFiller;
class TopTools_ListOfShape;


//! The abstract class BooleanOperation is the root
//! class of Boolean Operations (see Overview).
//! Boolean Operations algorithm is divided onto two parts.
//! -      The first one is computing interference between arguments.
//! -      The second one is building the result of operation.
//! The BooleanOperation class provides execution of both parts
//! of the Boolean Operations algorithm. The second part
//! (building the result) depends on given type of the Boolean
//! Operation (see Constructor).
class BRepAlgoAPI_BooleanOperation  : public BRepBuilderAPI_MakeShape
{
public:

  DEFINE_STANDARD_ALLOC

  
  //! Sets the type of Boolean operation to perform
  //! It can be BOPAlgo_SECTION
  //! BOPAlgo_COMMON
  //! BOPAlgo_FUSE
  //! BOPAlgo_CUT
  //! BOPAlgo_CUT21
  Standard_EXPORT   void SetOperation (const BOPAlgo_Operation anOp) ;
  
  //! Provides the algorithm of Boolean Operations
  //! -      Filling interference Data Structure (if it is necessary)
  //! -      Building the result of the operation.
  Standard_EXPORT virtual   void Build() ;
  
  //! Returns the first shape involved in this Boolean operation.
  Standard_EXPORT  const  TopoDS_Shape& Shape1()  const;
  
  //! Returns the second shape involved in this Boolean operation.
  Standard_EXPORT  const  TopoDS_Shape& Shape2()  const;
  
  //! Returns the type of Boolean Operation that has been performed.
  Standard_EXPORT   BOPAlgo_Operation Operation()  const;
  
  //! Returns the flag of edge refining
  Standard_EXPORT   Standard_Boolean FuseEdges()  const;
  
  //! Fuse C1 edges
  Standard_EXPORT   void RefineEdges() ;
  
  Standard_EXPORT   Standard_Boolean BuilderCanWork()  const;
  
  //! Returns the error status of operation.
  //! 0 - Ok
  //! 1 - The Object is created but Nothing is Done
  //! 2 - Null source shapes is not allowed
  //! 3 - Check types of the arguments
  //! 4 - Can not allocate memory for the DSFiller
  //! 5 - The Builder can not work with such types of arguments
  //! 6 - Unknown operation is not allowed
  //! 7 - Can not allocate memory for the Builder
  //! > 100 - See the Builder's  ErrorStatus
  Standard_EXPORT   Standard_Integer ErrorStatus()  const;
  
  //! Returns the list  of shapes modified from the shape <S>.
  Standard_EXPORT virtual  const  TopTools_ListOfShape& Modified (const TopoDS_Shape& aS) ;
  
  //! Returns true if the shape S has been deleted. The
  //! result shape of the operation does not contain the shape S.
  Standard_EXPORT virtual   Standard_Boolean IsDeleted (const TopoDS_Shape& aS) ;
  
  //! Returns the list  of shapes generated from the shape <S>.
  //! For use in BRepNaming.
  Standard_EXPORT virtual  const  TopTools_ListOfShape& Generated (const TopoDS_Shape& S) ;
  
  //! Returns true if there is at least one modified shape.
  //! For use in BRepNaming.
  Standard_EXPORT virtual   Standard_Boolean HasModified()  const;
  
  //! Returns true if there is at least one generated shape.
  //! For use in BRepNaming.
  Standard_EXPORT virtual   Standard_Boolean HasGenerated()  const;
  
  //! Returns true if there is at least one deleted shape.
  //! For use in BRepNaming.
  Standard_EXPORT virtual   Standard_Boolean HasDeleted()  const;
  
  Standard_EXPORT   void Destroy() ;
Standard_EXPORT virtual ~BRepAlgoAPI_BooleanOperation(){Destroy();}
  
  //! Returns a list of section edges.
  //! The edges represent the result of intersection between arguments of
  //! Boolean Operation. They are computed during operation execution.
  Standard_EXPORT  const  TopTools_ListOfShape& SectionEdges() ;




protected:

  
  //! Prepares the operations for S1 and S2.
  Standard_EXPORT BRepAlgoAPI_BooleanOperation(const TopoDS_Shape& S1, const TopoDS_Shape& S2, const BOPAlgo_Operation anOperation);
  
  //! Prepares the operations for S1 and S2.
  Standard_EXPORT BRepAlgoAPI_BooleanOperation(const TopoDS_Shape& S1, const TopoDS_Shape& S2, const BOPAlgo_PaveFiller& aDSF, const BOPAlgo_Operation anOperation);
  
  Standard_EXPORT   Standard_Boolean PrepareFiller() ;


  TopoDS_Shape myS1;
  TopoDS_Shape myS2;
  Standard_Boolean myBuilderCanWork;
  BOPAlgo_Operation myOperation;
  Standard_Integer myErrorStatus;
  BOPAlgo_PPaveFiller myDSFiller;
  BOPAlgo_PBuilder myBuilder;


private:

  
  //! Returns the list  of shapes generated from the shape <S>.
  //! For use in BRepNaming.
  Standard_EXPORT  const  TopTools_ListOfShape& RefinedList (const TopTools_ListOfShape& theL) ;


  Standard_Integer myEntryType;
  Standard_Boolean myFuseEdges;
  TopTools_DataMapOfShapeShape myModifFaces;
  TopTools_DataMapOfShapeShape myEdgeMap;


};







#endif // _BRepAlgoAPI_BooleanOperation_HeaderFile
