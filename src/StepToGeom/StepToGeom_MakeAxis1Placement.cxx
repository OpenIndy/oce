// Created on: 1993-06-15
// Created by: Martine LANGLOIS
// Copyright (c) 1993-1999 Matra Datavision
// Copyright (c) 1999-2014 OPEN CASCADE SAS
//
// This file is part of Open CASCADE Technology software library.
//
// This library is free software; you can redistribute it and/or modify it under
// the terms of the GNU Lesser General Public License version 2.1 as published
// by the Free Software Foundation, with special exception defined in the file
// OCCT_LGPL_EXCEPTION.txt. Consult the file LICENSE_LGPL_21.txt included in OCCT
// distribution for complete text of the license and disclaimer of any warranty.
//
// Alternatively, this file may be used under the terms of Open CASCADE
// commercial license or contractual agreement.

// sln 22.10.2001. CTS23496: If problems with creation of axis's direction occur default direction is used (StepToGeom_MakeAxis1Placement(...) function)

#include <StepToGeom_MakeAxis1Placement.ixx>
#include <StepGeom_Direction.hxx>
#include <StepGeom_CartesianPoint.hxx>
#include <StepToGeom_MakeDirection.hxx>
#include <StepToGeom_MakeCartesianPoint.hxx>
#include <Geom_CartesianPoint.hxx>
#include <Geom_Direction.hxx>
#include <gp_Dir.hxx>
#include <gp_Pnt.hxx>
#include <Geom_Axis1Placement.hxx>

//=============================================================================
// Creation d' un Ax1Placement de Geom a partir d' un axis1_placement de Step
//=============================================================================

Standard_Boolean StepToGeom_MakeAxis1Placement::Convert (const Handle(StepGeom_Axis1Placement)& SA, Handle(Geom_Axis1Placement)& CA)
{
  Handle(Geom_CartesianPoint) P;
  if (StepToGeom_MakeCartesianPoint::Convert(SA->Location(),P))
  {
    // sln 22.10.2001. CTS23496: If problems with creation of axis direction occur default direction is used
    gp_Dir D(0.,0.,1.);
    if (SA->HasAxis())
    {
      Handle(Geom_Direction) D1;
      if (StepToGeom_MakeDirection::Convert(SA->Axis(),D1))
        D = D1->Dir();
    }
    CA = new Geom_Axis1Placement(P->Pnt(),D);
    return Standard_True;
  }
  return Standard_False;
}
