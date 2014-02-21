/***************************************************************************
 *   Copyright (C) 2006 by TuxPLC					                                 *
 *   Author Stephane JEANNE s.jeanne@tuxplc.net                            *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
 
#ifndef _CIP_OBJECTS_H
#define _CIP_OBJECTS_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "CIP_Types.h"
#pragma pack (1)
	
typedef struct _List
								{
									CIP_UINT Number;
									//CIP_UINT Attributes[0];
								}List;

typedef struct _Common_Class_Attributes
								{
									CIP_UINT Revision;
									CIP_UINT MaxInstance;
									CIP_UINT NunInstances;
									List AttributesList;
									List ServicesList;
									CIP_UINT MaxIdNumClassAttribute;
									CIP_UINT MaxIdNumInstanceAttribute;
								}Common_Class_Attributes;

#ifdef __cplusplus
}
#endif

#endif /* _CIP_OBJECTS_H */
