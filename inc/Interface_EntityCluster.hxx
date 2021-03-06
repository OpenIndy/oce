// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Interface_EntityCluster_HeaderFile
#define _Interface_EntityCluster_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_Interface_EntityCluster.hxx>

#include <Handle_Standard_Transient.hxx>
#include <Handle_Interface_EntityCluster.hxx>
#include <MMgt_TShared.hxx>
#include <Standard_Boolean.hxx>
#include <Standard_Integer.hxx>
class Standard_Transient;
class Standard_OutOfRange;
class Standard_NullObject;
class Interface_EntityList;
class Interface_EntityIterator;


//! Auxiliary class for EntityList. An EntityList designates an
//! EntityCluster, which brings itself an fixed maximum count of
//! Entities. If it is full, it gives access to another cluster
//! ("Next"). This class is intended to give a good compromise
//! between access time (faster than a Sequence, good for little
//! count) and memory use (better than a Sequence in any case,
//! overall for little count, better than an Array for a very
//! little count. It is designed for a light management.
//! Remark that a new Item may not be Null, because this is the
//! criterium used for "End of List"
class Interface_EntityCluster : public MMgt_TShared
{

public:

  
  //! Creates an empty, non-chained, EntityCluster
  Standard_EXPORT Interface_EntityCluster();
  
  //! Creates a non-chained EntityCluster, filled with one Entity
  Standard_EXPORT Interface_EntityCluster(const Handle(Standard_Transient)& ent);
  
  //! Creates an empty EntityCluster, chained with another one
  //! (that is, put BEFORE this other one in the list)
  Standard_EXPORT Interface_EntityCluster(const Handle(Interface_EntityCluster)& ec);
  
  //! Creates an EntityCluster, filled with a first Entity, and
  //! chained to another EntityCluster (BEFORE it, as above)
  Standard_EXPORT Interface_EntityCluster(const Handle(Standard_Transient)& ant, const Handle(Interface_EntityCluster)& ec);
  
  //! Appends an Entity to the Cluster. If it is not full, adds the
  //! entity directly inside itself. Else, transmits to its Next
  //! and Creates it if it does not yet exist
  Standard_EXPORT   void Append (const Handle(Standard_Transient)& ent) ;
  
  //! Removes an Entity from the Cluster. If it is not found, calls
  //! its Next one to do so.
  //! Returns True if it becomes itself empty, False else
  //! (thus, a Cluster which becomes empty is deleted from the list)
  Standard_EXPORT   Standard_Boolean Remove (const Handle(Standard_Transient)& ent) ;
  
  //! Removes an Entity from the Cluster, given its rank. If <num>
  //! is greater than NbLocal, calls its Next with (num - NbLocal),
  //! Returns True if it becomes itself empty, False else
  Standard_EXPORT   Standard_Boolean Remove (const Standard_Integer num) ;
  
  //! Returns total count of Entities (including Next)
  Standard_EXPORT   Standard_Integer NbEntities()  const;
  
  //! Returns the Entity identified by its rank in the list
  //! (including Next)
  Standard_EXPORT  const  Handle(Standard_Transient)& Value (const Standard_Integer num)  const;
  
  //! Changes an Entity given its rank.
  Standard_EXPORT   void SetValue (const Standard_Integer num, const Handle(Standard_Transient)& ent) ;
  
  //! Fills an Iterator with designated Entities (includes Next)
  Standard_EXPORT   void FillIterator (Interface_EntityIterator& iter)  const;


friend class Interface_EntityList;


  DEFINE_STANDARD_RTTI(Interface_EntityCluster)

protected:




private: 

  
  //! Returns True if all the set of entities local to a Cluster is
  //! full. Used by EntityList.
  Standard_EXPORT   Standard_Boolean IsLocalFull()  const;
  
  //! Returns count of entities in the local set (without Next)
  //! Entities can then be read normally by method Value
  Standard_EXPORT   Standard_Integer NbLocal()  const;
  
  //! Returns True if a Cluster has a Next
  Standard_EXPORT   Standard_Boolean HasNext()  const;
  
  //! Returns Next Cluster in the chain
  Standard_EXPORT   Handle(Interface_EntityCluster) Next()  const;

  Handle(Standard_Transient) theents[4];
  Handle(Interface_EntityCluster) thenext;


};







#endif // _Interface_EntityCluster_HeaderFile
