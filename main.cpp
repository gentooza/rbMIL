/*
This file is part of SCADA Plastic rolling machine.

Copyright 2018, Prointegra SL.

SCADA Plastic rolling machine is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

SCADA Plastic rolling machiner is distributed in the hope that it will 
be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with SCADA Plastic rolling machine.  
If not, see <https://www.gnu.org/licenses/>.
*/
#include "pvapp.h"
#include <string>
#include <sstream>


// todo: comment me out. you can insert these objects as extern in your masks.
//rlDataAcquisition  adqui("/home/usuario/modbus1.mbx","/home/usuario/modbus1.shm", 65536);
rlDataAcquisition  adqui("/home/prointegra/modbus1.mbx","/home/prointegra/modbus1.shm", 65536);
//rlDataAcquisition  adqui("/home/joa/modbus1.mbx","/home/joa/modbus1.shm", 65536);
//rlPPIClient        ppi(ppidaemon_MAILBOX,ppidaemon_SHARED_MEMORY,ppidaemon_SHARED_MEMORY_SIZE);
Alarm myalarm(1);   // with event log
//Alarm myalarm;        // without event log
rlThread thread;

GLOBAL_DATA MyData;
piUsrMgnt *rbUsrMgnt;

int pvMain(PARAM *p)
{
int ret;

  pvSendVersion(p);
  pvSetCaption(p,"rb1000");
  pvResize(p,0,800,600);
  //pvScreenHint(p,1024,768); // this may be used to automatically set the zoomfactor
  ret = 1;
  pvGetInitialMask(p);
  MyData.lastMask = 0;
  MyData.thisMask = 0;
  if(strcmp(p->initial_mask,"mask1") == 0) ret = 1;

  while(1)
  {
    if(trace) printf("show_mask%d\n", ret);
    switch(ret)
    {
      case 7:
        pvStatusMessage(p,-1,-1,-1,"mask7");
        ret = show_mask7(p);
        break;
      case 6:
        pvStatusMessage(p,-1,-1,-1,"mask6");
        ret = show_mask6(p);
        break;
      case 4:
        pvStatusMessage(p,-1,-1,-1,"mask4");
        ret = show_mask4(p);
        break;
      case 3:
        pvStatusMessage(p,-1,-1,-1,"mask3");
        ret = show_mask3(p);
        break;
      case 2:
        pvStatusMessage(p,-1,-1,-1,"mask2");
        ret = show_mask2(p);
        break;
      case 1:
        pvStatusMessage(p,-1,-1,-1,"mask1");
        ret = show_mask1(p);
        break;
      default:
        return 0;
    }
  }
}

#ifdef USE_INETD
int main(int ac, char **av)
{
PARAM p;

  pvInit(ac,av,&p);
  /* here you may interpret ac,av and set p->user to your data */
  pvMain(&p);
  return 0;
}
#else  // multi threaded server
int main(int ac, char **av)
{
PARAM p;
int   s;

 // begin user defined code
s = myalarm.loadCSV("alarm.csv");
printf("DEBUG: number of alarms %d\n",s);
  if(myalarm.loadCSV("alarm.csv") < 0)          
  {
    printf("could not load alarm.csv\n");
    return -1;
  }
#ifdef unix
  char *argv[] = {"","-eventhost=localhost","-eventport=6003"};
#else
  char *argv[] = {"","-eventhost=localhost","-eventport=5100"};
#endif
  rlEventInit(3,argv,"/TEST/");
//DATABASES
//users
//	sprintf(MyData.Users_Table_Name,"USERS");
//	sprintf(MyData.DB_Name,"~/users.DB");
	rbUsrMgnt = new piUsrMgnt();
	rbUsrMgnt->UsrMgnt_openDB("users.DB");
	rbUsrMgnt->UsrMgnt_openTable("CREATE TABLE IF NOT EXISTS USERS(ID INT PRIMARY KEY,NAME VARCHAR(20),PASSWORD VARCHAR(20),permission INT);");
//	Tableinit(&MyData.DB,MyData.DB_Name,MyData.SQL);
  // end user defined code

  pvInit(ac,av,&p);
  /* here you may interpret ac,av and set p->user to your data */
  while(1)
  {
    s = pvAccept(&p);
    if(s != -1) pvCreateThread(&p,s);
    else        break;
  }
  rbUsrMgnt->UsrMgnt_closeDB();
  delete rbUsrMgnt;
  return 0;
}

//functions
int ReadCommDATA(DATA **d)
{
	int i;
	char text[100];


	DATA *temp;
	temp = *d;
	//capture modbus
	for(i=0;i<END_INPUT_REGISTERS;i++)
	{
		sprintf(text,"inputRegisters(1,%d)",i);
		temp->val[i] = adqui.intValue(text);
		//cout << "DEBUG: "<< i <<" , value: "<< temp->val[i]<< endl;
	}
	for(i=0;i<END_HOLDING_REGISTERS;i++)
	{
		sprintf(text,"holdingRegisters(1,%d)",i);
		temp->wval[i] = adqui.intValue(text);
		//cout << "DEBUG: "<< i <<" , value: "<< temp->wval[i]<< endl;
	}
	*d = temp;
	return 1;
}
int InitUsersName(DATA **d)
{
	DATA *temp;
	int i;


	temp = *d;

	for(i=0;i<10;i++)
	{
		memset(temp->UsersName[i],0,sizeof(temp->UsersName[i]));
		sprintf(temp->UsersName[i],"user%d",i+1);
	}
	memset(temp->UsersName[10],0,sizeof(temp->UsersName[10]));
	sprintf(temp->UsersName[10],"mantenimiento");

	memset(temp->UsersName[11],0,sizeof(temp->UsersName[11]));
	sprintf(temp->UsersName[11],"gestion");
   
	
	return 0;
}
int InitAlarms(DATA **d)
{
	DATA *temp;
	temp = *d;
	
 //alarmas
	memset(temp->alarmsId[0],0,sizeof(temp->alarmsId[0]));
	sprintf(temp->alarmsId[0],"AL_PAROCCM1");//0
	temp->alarmasAdd[0] = AL_PAROCCM1;
	memset(temp->alarmsId[1],0,sizeof(temp->alarmsId[1]));
	sprintf(temp->alarmsId[1],"AL_PAROC1");//1
	temp->alarmasAdd[1] = AL_PAROC1;
	memset(temp->alarmsId[2],0,sizeof(temp->alarmsId[2]));//2
	sprintf(temp->alarmsId[2],"AL_PAROC2");
	temp->alarmasAdd[2] = AL_PAROC2;
	memset(temp->alarmsId[3],0,sizeof(temp->alarmsId[3]));//3
	sprintf(temp->alarmsId[3],"AL_PAROC3");
	temp->alarmasAdd[3] = AL_PAROC3;
	memset(temp->alarmsId[4],0,sizeof(temp->alarmsId[4]));//4
	sprintf(temp->alarmsId[4],"AL_PAROC4");
	temp->alarmasAdd[4] = AL_PAROC4;
	memset(temp->alarmsId[5],0,sizeof(temp->alarmsId[5]));//5
	sprintf(temp->alarmsId[5],"W_TRAINO");
	temp->alarmasAdd[5] = W_TRAINO;
	memset(temp->alarmsId[6],0,sizeof(temp->alarmsId[6]));//6
	sprintf(temp->alarmsId[6],"W_BRAZOD");
	temp->alarmasAdd[6] = W_BRAZOD;
	memset(temp->alarmsId[7],0,sizeof(temp->alarmsId[7]));//7
	sprintf(temp->alarmsId[7],"W_BRAZOR1");
	temp->alarmasAdd[7] = W_BRAZOR1;
	memset(temp->alarmsId[8],0,sizeof(temp->alarmsId[8]));//8
	sprintf(temp->alarmsId[8],"W_BRAZOR2");
	temp->alarmasAdd[8] = W_BRAZOR2;
	memset(temp->alarmsId[9],0,sizeof(temp->alarmsId[9]));//9
	sprintf(temp->alarmsId[9],"W_GLOBOD");
	temp->alarmasAdd[9] = W_GLOBOD;
	memset(temp->alarmsId[10],0,sizeof(temp->alarmsId[10]));//10
	sprintf(temp->alarmsId[10],"W_GLOBOR1");
	temp->alarmasAdd[10] = W_GLOBOR1;
	memset(temp->alarmsId[11],0,sizeof(temp->alarmsId[11]));//11
	sprintf(temp->alarmsId[11],"W_GLOBOR2");
	temp->alarmasAdd[11] = W_GLOBOR2;
	memset(temp->alarmsId[12],0,sizeof(temp->alarmsId[12]));//12
	sprintf(temp->alarmsId[12],"W_METROSALCZ");
	temp->alarmasAdd[12] = W_METROSALCZ;
	memset(temp->alarmsId[13],0,sizeof(temp->alarmsId[13]));//13
	sprintf(temp->alarmsId[13],"W_DIAMETROALCZ");
	temp->alarmasAdd[13] = W_DIAMETROALCZ;
	memset(temp->alarmsId[14],0,sizeof(temp->alarmsId[14]));//14
	sprintf(temp->alarmsId[14],"AL_ETHCAT_D");
	temp->alarmasAdd[14] =  AL_ETHCAT_D;
	memset(temp->alarmsId[15],0,sizeof(temp->alarmsId[15]));//15
	sprintf(temp->alarmsId[15],"AL_ETHCAT_R1");
	temp->alarmasAdd[15] =  AL_ETHCAT_R1;
	memset(temp->alarmsId[16],0,sizeof(temp->alarmsId[16]));//16
	sprintf(temp->alarmsId[16],"AL_ETHCAT_R2");
	temp->alarmasAdd[16] =  AL_ETHCAT_R2;
	memset(temp->alarmsId[17],0,sizeof(temp->alarmsId[17]));//17
	sprintf(temp->alarmsId[17],"AL_ETHCAT_T");
	temp->alarmasAdd[17] =  AL_ETHCAT_T;


	temp->num_alarmas = 18;
	*d = temp;
	return 0;
}
int CheckAlarms(DATA **d,PARAM **p, int AlarmWidgID)
{
	DATA *temp;
	PARAM * tempParam;
	int i;

  temp = *d;
  tempParam = *p;
  myalarm.updateWidgetHTML_res(tempParam,AlarmWidgID,&temp->state);

  if(myalarm.count() > 0) 
  {
    char buf[80];
    sprintf(buf, "There are %d alarms pending", myalarm.count());
    pvStatusMessage(tempParam,255,0,0,buf);
  }
  else
  {
    pvStatusMessage(tempParam,0,255,0,"Normal operation");
  }
 // cout << "DEBUG: comprobando numero de alarmas: " << temp->num_alarmas << endl;
  for(i=0;i<temp->num_alarmas;i++)
  {
//	cout << "DEBUG: comprobando la alarma: " << temp->alarmsId[i] <<"VALOR = " << temp->val[temp->alarmasAdd[i]] << endl;
 	//alarmas
  	if(temp->val[temp->alarmasAdd[i]])
  	{
		if(!myalarm.isSet(temp->alarmsId[i]))
		{
			//printf("DEBUG: set en alarma AL_PAROCCM1\n");
			myalarm.set(temp->alarmsId[i]);
		}
  	}
  } 
 
  *d = temp;
  *p = tempParam;

  return 1;
}
int word2digitals(int word,int ** ret)
{
int i=0;
int aux = word;
int aux2;
int * temp;

temp = *ret;
//cout << "palabra introducida = "<< word << endl;


for(i=0;i<16;i++)
{
	if(aux==0)
	{
		for(i;i<16;i++)
			temp[i]=0;
		*ret = temp;
		return 0;
	}

	aux2 = aux%2;
	temp[i] = aux2;
	aux=aux/2;

	
}
*ret = temp;
return 0;
} 
#endif
