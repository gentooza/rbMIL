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
//###############################################################
//# mask5_slots.h for ProcessViewServer created: Fri Jun 6 10:37:59 2014
//# please fill out these slots
//# here you find all possible events
//# Yours: Lehrig Software Engineering
//###############################################################

// todo: uncomment me if you want to use this data aquisiton
// also uncomment this classes in main.cpp and pvapp.h
// also remember to uncomment rllib in the project file
//extern rlModbusClient     modbus;
//extern rlSiemensTCPClient siemensTCP;
//extern rlPPIClient        ppi;


extern rlDataAcquisition     adqui;


extern GLOBAL_DATA MyData;
extern piUsrMgnt *rbUsrMgnt;

static int slotInit(PARAM *p, DATA *d)
{
 int i;
 char name[100];
  if(p == NULL || d == NULL) return -1;
  //memset(d,0,sizeof(DATA));
  //table parameters contruction
 //parámetros
  pvSetNumRows(p,table_param,4); //numero de parámetros
  pvSetTableText(p,table_param,0,-1,"Parámetro");
  pvSetTableText(p,table_param,1,-1,"Valor");
  //poblando
  pvTableSetHeaderResizeEnabled(p,table_param,1,0,0);
  pvTableSetHeaderResizeEnabled(p,table_param,1,0,1);
  pvTableSetHeaderResizeEnabled(p,table_param,1,0,2);
  pvTableSetHeaderResizeEnabled(p,table_param,0,0,0);
  pvTableSetHeaderResizeEnabled(p,table_param,0,0,1);
  pvTableSetHeaderResizeEnabled(p,table_param,0,0,2);

  pvSetColumnWidth(p,table_param,0,240);
  pvSetColumnWidth(p,table_param,1,70);
  pvSetColumnWidth(p,table_param,2,60);

  pvSetTableLabel(p,table_param,0,0,"P1 diametro del traino (mm/100)");
  pvSetTableButton(p,table_param,2,0,"Editar");
  pvSetTableLabel(p,table_param,0,1,"P2 corrector calculo dist.(uds/1000)");
  pvSetTableButton(p,table_param,2,1,"Editar");
  pvSetTableLabel(p,table_param,0,2,"P3 diam. paro CG (mm)");
  pvSetTableButton(p,table_param,2,2,"Editar");
  pvSetTableLabel(p,table_param,0,3,"P4 diam. paro CP (mm)");
  pvSetTableButton(p,table_param,2,3,"Editar");


 //usuarios
  pvSetNumRows(p,table_users,12); //numero de usuarios
  pvSetTableText(p,table_users,0,-1,"Usuario");
  pvSetTableText(p,table_users,2,-1,"metros");
  //poblando
  pvTableSetHeaderResizeEnabled(p,table_users,1,0,0);
  pvTableSetHeaderResizeEnabled(p,table_users,1,0,1);
  pvTableSetHeaderResizeEnabled(p,table_users,1,0,2);
  pvTableSetHeaderResizeEnabled(p,table_users,1,0,3);
  pvTableSetHeaderResizeEnabled(p,table_users,0,0,0);
  pvTableSetHeaderResizeEnabled(p,table_users,0,0,1);
  pvTableSetHeaderResizeEnabled(p,table_users,0,0,2);
  pvTableSetHeaderResizeEnabled(p,table_users,0,0,3);

  pvSetColumnWidth(p,table_users,0,74);
  pvSetColumnWidth(p,table_users,2,74);
  pvSetColumnWidth(p,table_users,2,89);

  for (i=0;i < 10 ; i++) //10 users
  {
	memset(name,0,sizeof(name));
	sprintf(name,"user%d",i+1);
  	pvSetTableLabel(p,table_users,0,i,name);
  	pvSetTableButton(p,table_users,1,i,"Contraseña");
  	pvSetTableButton(p,table_users,3,i,"Reset Metros");
  }
  pvSetTableLabel(p,table_users,0,10,"mantenimiento");
  pvSetTableButton(p,table_users,1,10,"Contraseña");

  pvSetTableLabel(p,table_users,0,11,"gestion");
  pvSetTableButton(p,table_users,1,11,"Contraseña");

  if(MyData.UserLvl > PRIV_TOTAL)
	pvSetEnabled(p,table_users,0);
	
	
  return 0;
}

static int slotNullEvent(PARAM *p, DATA *d)
{
  char text[100];
  long dnumber;
  std::string stexto;
  std::ostringstream snumber;
  int i;
int index;

  if(p == NULL || d == NULL) return -1;

  //capture modbus
  ReadCommDATA(&d);

  //actualizamos parámetros
  memset(text,0,sizeof(text));
  sprintf(text,"%d",d->wval[wDIAM_TRAINOS]);
  pvSetTableLabel(p,table_param,1,0,text);

  memset(text,0,sizeof(text));
  sprintf(text,"%d",d->wval[wCORRECTOR_METROS]);
  pvSetTableLabel(p,table_param,1,1,text);

  memset(text,0,sizeof(text));
  sprintf(text,"%d",d->wval[WDIAM_PARADA]);
  pvSetTableLabel(p,table_param,1,2,text);

  memset(text,0,sizeof(text));
  sprintf(text,"%d",d->wval[WDIAM_PARADA_CP]);
  pvSetTableLabel(p,table_param,1,3,text);

  memset(text,0,sizeof(text));
  sprintf(text,"%d",d->wval[wSECCION_MATERIAL]);
  pvSetTableLabel(p,table_param,1,4,text);


  for(i=0;i< 10;i=i++)
{
index = TOTAL_METROS_USUARIO1_H + 2*i;
	dnumber = 65536*d->val[index] + d->val[index + 1];
//	cout << "DEBUG: i = " << i << "H = " << d->val[index] <<",indice ="<< index << " L= " << d->val[index+1] << ",indice = "<< index +1 << "VALOR TOTAL="<< dnumber << endl;
//cout << "ejemplo de primero valores : 1H,1L =" << d->val[TOTAL_METROS_USUARIO1_H] << "," << d->val[TOTAL_METROS_USUARIO1_L] << "  2H,2L =" << d->val[TOTAL_METROS_USUARIO2_H] << "," << d->val[TOTAL_METROS_USUARIO2_L] << endl;
//cout <<"indices primeros 4 valores = "<< TOTAL_METROS_USUARIO1_H <<"," << TOTAL_METROS_USUARIO1_L << "," << TOTAL_METROS_USUARIO2_H << "," << TOTAL_METROS_USUARIO2_L << endl;
	snumber.str("");
	snumber << dnumber;
  	stexto = snumber.str();
  	pvSetTableLabel(p,table_users,2,i,stexto.c_str());

}




  return 0;
}

static int slotButtonEvent(PARAM *p, int id, DATA *d)
{
  if(p == NULL || id == 0 || d == NULL) return -1;
  return 0;
}

static int slotButtonPressedEvent(PARAM *p, int id, DATA *d)
{
  if(p == NULL || id == 0 || d == NULL) return -1;
  return 0;
}

static int slotButtonReleasedEvent(PARAM *p, int id, DATA *d)
{
  if(p == NULL || id == 0 || d == NULL) return -1;
  if(id == produccion_button)
  {
      show_mask2(p);
  }
  else if(id == mant_button)
  {
	if(MyData.UserLvl <= PRIV_MANT)
		show_mask6(p);		
  }
  else if(id == config_button)
  {
	show_mask3(p);		
  }
  return 0;
}

static int slotTextEvent(PARAM *p, int id, DATA *d, const char *text)
{
  int val,address;
  char texto[100];
  std::string userName;
  std::ostringstream number;
  std::ostringstream password;

  if(p == NULL || id == 0 || d == NULL || text == NULL) return -1;
  if(id==id_inputPassdlg)
  {
	if(!strcmp(text,""))
	{
		return 0;
	}

	if(d->UserIdPassDlg < 10)
	{
		userName = "user";
		number << d->UserIdPassDlg +1;
		userName = userName + number.str();	
	}
	else if (d->UserIdPassDlg == 10)
	{
		userName = "mantenimiento";
	}
	else if (d->UserIdPassDlg  == 11)
	{
		userName = "gestion";
	}
	password << text;
	rbUsrMgnt->UsrMgnt_changePassword(userName,password.str());
  }
  else if(id==id_inputParamdlg)
  {
	if(!strcmp(text,""))
	{
		return 0;
	}
	val = atoi(text);
	if ((val == 0) && ( text[0] != '0'))
		printf("DEBUG: no es valor numerico \n");
	else
	{
		switch(d->ParamIdDlg )
		{
			case (0):
			address = wDIAM_TRAINOS;
			break;
			case (1):
			address = wCORRECTOR_METROS;
			break;
			case (2):
			address = WDIAM_PARADA;	
			break;
			case (3):
			address = WDIAM_PARADA_CP;	
			break;
			default:
			return 1;
		}
		d->wval[address] = val;
		sprintf(texto,"register(1,%d)",address);
		adqui.writeIntValue(texto,d->wval[address]);
	}
  }


  return 0;
}

static int slotSliderEvent(PARAM *p, int id, DATA *d, int val)
{
  int address;
  char text[100];
  if(p == NULL || id == 0 || d == NULL || val < -1000) return -1;
	if(id == table_users)
	{
		if(val == MessageBoxOk)
		{
			address = WCARGA_METROS_USUARIO;
			d->wval[address] = 21 + d->UserIdPassDlg;
			memset(text,0,sizeof(text));
			sprintf(text,"register(1,%d)",address);
			adqui.writeIntValue(text,d->wval[address]);
		}
	}
  return 0;
}

static int slotCheckboxEvent(PARAM *p, int id, DATA *d, const char *text)
{
  if(p == NULL || id == 0 || d == NULL || text == NULL) return -1;
  return 0;
}

static int slotRadioButtonEvent(PARAM *p, int id, DATA *d, const char *text)
{
  if(p == NULL || id == 0 || d == NULL || text == NULL) return -1;
  return 0;
}

static int slotGlInitializeEvent(PARAM *p, int id, DATA *d)
{
  if(p == NULL || id == 0 || d == NULL) return -1;
  return 0;
}

static int slotGlPaintEvent(PARAM *p, int id, DATA *d)
{
  if(p == NULL || id == 0 || d == NULL) return -1;
  return 0;
}

static int slotGlResizeEvent(PARAM *p, int id, DATA *d, int width, int height)
{
  if(p == NULL || id == 0 || d == NULL || width < 0 || height < 0) return -1;
  return 0;
}

static int slotGlIdleEvent(PARAM *p, int id, DATA *d)
{
  if(p == NULL || id == 0 || d == NULL) return -1;
  return 0;
}

static int slotTabEvent(PARAM *p, int id, DATA *d, int val)
{
  if(p == NULL || id == 0 || d == NULL || val < -1000) return -1;
  return 0;
}

static int slotTableTextEvent(PARAM *p, int id, DATA *d, int x, int y, const char *text)
{
  char pass[100];
  char showtext[150];
  int Userid;
  std::string userName;
  std::ostringstream number;
 
  if(p == NULL || id == 0 || d == NULL || x < -1000 || y < -1000 || text == NULL) return -1;
  if(id == table_users)
{
  	if(!strcmp(text,"Contraseña"))
  	{
		if(y < 10)
		{
			userName = "user";
			number << y+1;
			userName = userName + number.str();	
		}
		else if (y== 10)
		{
			userName = "mantenimiento";
		}
		else if (y == 11)
		{
			userName = "gestion";
		}
		else 
			return 0;
		d->UserIdPassDlg = y;
		memset(pass,0,sizeof(pass));
		sprintf(pass,rbUsrMgnt->UsrMgnt_retPassword(userName).c_str());
		memset(showtext,0,sizeof(showtext));
		sprintf(showtext,"introduzca la nueva contraseña para: %s , contraseña antigua: %s", userName.c_str(),pass);
		pvInputDialog(p,id_inputPassdlg,showtext,"");
  	}
	else if(!strcmp(text,"Reset Metros"))
  	{
		if(y < 10)
		{
			userName = "user";
			number << y+1;
			userName = userName + number.str();	
		}
		else 
			return 0;

		d->UserIdPassDlg = y;
		memset(showtext,0,sizeof(showtext));
		sprintf(showtext,"Seguro que desea resetear los metros del usuario: %s", userName.c_str());
		pvMessageBox(p,table_users,BoxWarning,showtext,MessageBoxOk,MessageBoxCancel,MessageBoxNoButton);
  	}
  }
  else if(id == table_param)
  {
	if(!strcmp(text,"Editar"))
  	{
		cout << "DEBUG; Estamos en editar, y: "<< y << endl;
		d->ParamIdDlg = y;
		memset(showtext,0,sizeof(showtext));
		if (y == 0)
			sprintf(showtext,"introduzca nuevo valor, antiguo: %d",d->wval[wDIAM_TRAINOS]);
		else if (y ==1)
			sprintf(showtext,"introduzca nuevo valor, antiguo: %d",d->wval[wCORRECTOR_METROS]);
		else if(y== 2)
			sprintf(showtext,"introduzca nuevo valor, antiguo: %d",d->wval[WDIAM_PARADA]);
		else if(y== 3)
			sprintf(showtext,"introduzca nuevo valor, antiguo: %d",d->wval[WDIAM_PARADA_CP]);

		else
			return 1;
			
		pvInputDialog(p,id_inputParamdlg,showtext,"");
		
	}
  }
  return 0;
}

static int slotTableClickedEvent(PARAM *p, int id, DATA *d, int x, int y, int button)
{
  if(p == NULL || id == 0 || d == NULL || x < -1000 || y < -1000 || button < 0) return -1;
  return 0;
}

static int slotSelectionEvent(PARAM *p, int id, DATA *d, int val, const char *text)
{
  if(p == NULL || id == 0 || d == NULL || val < -1000 || text == NULL) return -1;
  return 0;
}

static int slotClipboardEvent(PARAM *p, int id, DATA *d, int val)
{
  if(p == NULL || id == 0 || d == NULL || val < -1000) return -1;
  return 0;
}

static int slotRightMouseEvent(PARAM *p, int id, DATA *d, const char *text)
{
  if(p == NULL || id == 0 || d == NULL || text == NULL) return -1;
  //pvPopupMenu(p,-1,"Menu1,Menu2,,Menu3");
  return 0;
}

static int slotKeyboardEvent(PARAM *p, int id, DATA *d, int val, int modifier)
{
  if(p == NULL || id == 0 || d == NULL || val < -1000 || modifier < -1000) return -1;
  return 0;
}

static int slotMouseMovedEvent(PARAM *p, int id, DATA *d, float x, float y)
{
  if(p == NULL || id == 0 || d == NULL || x < -1000 || y < -1000) return -1;
  return 0;
}

static int slotMousePressedEvent(PARAM *p, int id, DATA *d, float x, float y)
{
  if(p == NULL || id == 0 || d == NULL || x < -1000 || y < -1000) return -1;
  return 0;
}

static int slotMouseReleasedEvent(PARAM *p, int id, DATA *d, float x, float y)
{
  if(p == NULL || id == 0 || d == NULL || x < -1000 || y < -1000) return -1;
  return 0;
}

static int slotMouseOverEvent(PARAM *p, int id, DATA *d, int enter)
{
  if(p == NULL || id == 0 || d == NULL || enter < -1000) return -1;
  return 0;
}

static int slotUserEvent(PARAM *p, int id, DATA *d, const char *text)
{
  if(p == NULL || id == 0 || d == NULL || text == NULL) return -1;
  return 0;
}
