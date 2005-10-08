/*=========================================================================

Program:   Medical Imaging & Interaction Toolkit
Module:    $RCSfile$
Language:  C++
Date:      $Date$
Version:   $Revision$

Copyright (c) German Cancer Research Center, Division of Medical and
Biological Informatics. All rights reserved.
See MITKCopyright.txt or http://www.mitk.org/copyright.html for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notices for more information.

=========================================================================*/


#ifndef MITKDRAWOPERATION_H
#define MITKDRAWOPERATION_H

#include <mitkCommon.h>
#include <mitkOperation.h>
#include <mitkVector.h>
#include <mitkImage.h>
#include <mitkSeedsImage.h>

namespace mitk {

//##ModelId=3F0189F0016F
//##Documentation
//## @brief Operation, that handles all aktions on Seeds.
//##
//## Stores everything for Adding and Deleting Seeds.
//## @ingroup Undo
class DrawOperation : public Operation
{
  public:
  //##ModelId=3F0189F003A2
	//##Documentation
	//##@brief Operation, that handles all aktions on Seeds.
	//##
	//## @param operationType is the type of that operation (see mitkOperation.h; e.g. move or add; Information for StateMachine::ExecuteOperation());
  //## @param point is the information of the seed point to add to the seeds image
  //## @param last_point is the information of the point added before
  //## @param draw_state represents the seeds type e.g foreground or background seeds
  //## @param radius is the radius of seeds 
  DrawOperation(OperationType operationType,	Point3D point, Point3D last_point, int draw_state, int radius);
 
	//##Documentation
	//##@brief Operation, that handles all aktions on Seeds.
	//##
	//## @param operationType is the type of that operation (see mitkOperation.h; e.g. move or add; Information for StateMachine::ExecuteOperation());
  //## @param seedsImage is the current image of seeds
  //## @param lastSeedsImage is the image before a seed point is set
  DrawOperation(OperationType operationType,	SeedsImage::Pointer seedsImage, SeedsImage::Pointer lastSeedsImage);


  virtual ~DrawOperation();

	Point3D GetPoint();

	Point3D GetLastPoint();

	int GetDrawState();

	int GetRadius();

  SeedsImage::Pointer DrawOperation::GetSeedsImage();

  SeedsImage::Pointer DrawOperation::GetLastSeedsImage();

  private:
	Point3D m_Point;
	Point3D m_LastPoint;

	int m_DrawState;
  int m_Radius;

  SeedsImage::Pointer m_SeedsImage;
  SeedsImage::Pointer m_LastSeedsImage;

};
}//namespace mitk
#endif /* MITKDRAWOPERATION_H*/

