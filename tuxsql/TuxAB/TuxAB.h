/***************************************************************************
*   Copyright (C) 2005 by TuxPLC                                          *
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

#ifndef _TUXAB_H
#define _TUXAB_H

#ifdef __cplusplus
extern "C"
{
#endif

#define MAX_ERR_MSG_LEN 255
#define MIN_SAMPLE 5
#define MAX_SAMPLE 20000 // timeout de connection

/************************** Error codes ************************************/

#define Tux_Error	100

#define T_Success 0
#define T_Error -1
#define T_DBError -2

typedef char D_Definition[100];
typedef char D_Path[255];
typedef char D_Tag[50];

typedef struct _PLC{
								D_Tag PlcName;
								char PlcPath[50];
								int PlcType;
								int NetWork;
								int Node;
								int Errors;
								Eip_Session *Session;
								Eip_Connection *Connection;
								int Next_Time;
								LISTE Tags;
								LISTE Packets;
							} PLC;

typedef struct _TAG{
								D_Tag TagName;
								char Address[100];
								Logical_Binary_Address lba;
								int DataType;
								short int Time_Sample;
								time_t Time_Value;
								int Index;
							} TAG;

typedef struct _PACKET{
								char BaseAddress[100];
								Logical_Binary_Address lba;
								int NumElt;
								short int Time_Sample;
								int Time_Value;
								LISTE Tags;
								} PACKET;

//typedef enum _Tux_Error_type{Tux_Internal_Error=100,Tux_Sys_Error,Tux_Cip_Error} Tux_Error_type;

/******************* Global Var ************************************/

extern unsigned int Tux_errno;
extern unsigned int Tux_ext_errno;
extern int Tux_err_type;
extern char Tux_err_msg[MAX_ERR_MSG_LEN+1];

extern LISTE PLCs;
extern LISTE SESSIONs;
extern LISTE CONNECTIONs;

/******************* Functions declaration **************************/

char *TuxGetInternalErrMsg(unsigned int ErrorCode);
char *TuxGetErrMsg(int s_err_type,unsigned int s_errno,unsigned int ext_errno);

#define TUXERROR(type,no,ext_no) {Tux_err_type=type;Tux_errno=no;Tux_ext_errno=ext_no;memcpy(&Tux_err_msg,GetErrMsg(Tux_err_type,Tux_errno,Tux_ext_errno),MAX_ERR_MSG_LEN);}

int _GetPlc(MYSQL *db,LISTE *plcs,char *plcname);
#define GetPlc(plcs,plcname) _GetPlc(&Default_Db, plcs,plcname)

int _GetPlcList(MYSQL *db,LISTE *plcs,LISTE *plclistname);
#define GetPlcList(plcs,plclistname) _GetPlcList(&Default_Db,plcs,plclistname)

int _GetTag(MYSQL *db,PLC *plc);
#define GetTag(plc) _GetTag(&Default_Db, plc)

int _UpdateTag(MYSQL *db,TAG *tag,double value);
#define UpdateTag(tag,value) _UpdateTag(&Default_Db,tag,value)

#ifdef __cplusplus
}
#endif

#endif /* _TUXAB2_H */
