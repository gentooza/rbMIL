/*
 * SCADA RB1000 - Plastic rolling machine RB1000, operator Interface
 *
 *  Copyright 2012-2014 by it's authors. 
 *
 *  Some rights reserved. See COPYING, AUTHORS.
 *  This file may be used under the terms of the GNU General Public
 *  License version 3.0 as published by the Free Software Foundation
 *  and appearing in the file COPYING included in the packaging of
 *  this file.
 *
 *  This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 *  WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */
//###############################################################
//# mask2_slots.h for ProcessViewServer created: mié may 28 11:31:36 2014
//# please fill out these slots
//# here you find all possible events
//# Yours: Lehrig Software Engineering
//###############################################################


// todo: uncomment me if you want to use this data aquisiton
// also uncomment this classes in main.cpp and pvapp.h
// also remember to uncomment rllib in the project file
extern rlDataAcquisition     adqui;
//extern rlSiemensTCPClient siemensTCP;
//extern rlPPIClient        ppi;



extern Alarm myalarm;
extern GLOBAL_DATA MyData;

static void setState(PARAM *p, DATA *d, int value, int id, const char *IMAGEN_ON, const char * IMAGEN_OFF, const char* IMAGEN_INDEFINIDO) 
{ // helper function
  char filename[80] = "";
  if     (value == 0) strcpy(filename,IMAGEN_OFF);
  else if(value > 0) strcpy(filename,IMAGEN_ON);
  else                       strcpy(filename,IMAGEN_INDEFINIDO);
	printf("DEBUG: image set: %s , valor: %d\n",filename,value );
  pvSetImage(p,id,filename);
}
//setState(p,d,0,markFlow,    "coilStatus(1,0)");

static int slotInit(PARAM *p, DATA *d)
{
 char text[100];
int address;
int i;

  if(p == NULL || d == NULL) return -1;
	  d->state = -1; //init alarms html
//capture modbus
	ReadCommDATA(&d);
  //iniciamos alarmas
  InitAlarms(&d);
//initial values
  	pvDownloadFile(p,"./images/green.png");
	memset(text,0,sizeof(text));
	sprintf(text,"%d",d->wval[wCONSIGNA_VELOCIDAD]);
//	sprintf(texto,"%d",d->con_vel);
	pvSetText(p,spi_convel,text);
	memset(text,0,sizeof(text));
	sprintf(text,"%d",d->wval[wCONSIGNA_TENSION_D]);
	pvSetText(p,spi_conten_d,text);
	memset(text,0,sizeof(text));
	sprintf(text,"%d",d->wval[wCONSIGNA_TENSION_R1]);
	pvSetText(p,spi_conten_r1,text);
	memset(text,0,sizeof(text));
	sprintf(text,"%d",d->wval[wCONSIGNA_TENSION_R2]);
	pvSetText(p,spi_conten_r2,text);

	pvSetText(p,linedit_user,MyData.CurrUser.c_str());


//contador total de metros
	address = WCARGA_METROS_USUARIO;

	d->wval[address] = MyData.UserId + 9; //9 es la deriva en el valor
	memset(text,0,sizeof(text));
	sprintf(text,"register(1,%d)",address);
	adqui.writeIntValue(text,d->wval[address]);
//permisivos
	if(d->val[PERMISIVOS_MARCHA] > 0) 
		pvSetImage(p,piloto_permisivos,"./images/green.png");
	else
		pvSetImage(p,piloto_permisivos,"./images/red.png");
//widgets read-only
	pvSetEditable(p,LineEdit_Estado,0);
	pvSetEditable(p,spi_convel,0);
	pvSetEditable(p,spi_conten_d,0);
	pvSetEditable(p,spi_conten_r1,0);
	pvSetEditable(p,spi_conten_r2,0);


  //mask navigation control
  MyData.lastMask = MyData.thisMask;
  MyData.thisMask = 2;	

  //memset(d,0,sizeof(DATA));
  return 0;
}

static int slotNullEvent(PARAM *p, DATA *d)
{
	char texto[100];
	double dnumber;

  std::string stexto;
  std::ostringstream snumber;

//capture modbus
	ReadCommDATA(&d);
//refresh visu
//hacer función!
	switch (d->val[ESTADO_MAQUINA])
	{
		case (0):
		pvSetText(p,LineEdit_Estado,"INIZIALIZANDO");
		break;
		case(1):
		pvSetText(p,LineEdit_Estado,"PARADA");
		break;
		case(2):
		pvSetText(p,LineEdit_Estado,"TENSANDO");
		break;	
		case(3):
		pvSetText(p,LineEdit_Estado,"ACELERANDO");
		break;
		case(4):
		pvSetText(p,LineEdit_Estado,"MARCHA");
		break;
		case(5):
		pvSetText(p,LineEdit_Estado,"DESACELERANDO");
		break;
		case(6):
		pvSetText(p,LineEdit_Estado,"MANTENIMIENTO");
		break;
		case(7):
		pvSetText(p,LineEdit_Estado,"PARO EMERGENC.");
		break;
		case(8):
		pvSetText(p,LineEdit_Estado,"PARO EMERGENC.");
		break;
		default:
		pvSetText(p,LineEdit_Estado,"ESTADO ERRONEO");
		break;		
	}
//
	pvDisplayFloat(p,lcd_lecvel,static_cast<float>(d->val[LECTURA_VELOCIDAD])/10);	
	pvDisplayFloat(p,lcd_lecten_d,static_cast<float>(d->val[LECTURA_TENSION_D]));
	pvDisplayFloat(p,lcd_lecten_r1,static_cast<float>(d->val[LECTURA_TENSION_R1]));
	pvDisplayFloat(p,lcd_lecten_r2,static_cast<float>(d->val[LECTURA_TENSION_R2]));
	pvDisplayFloat(p,lcd_lecdiam_d,static_cast<float>(d->val[LECTURA_DIAMETRO_D]));
	pvDisplayFloat(p,lcd_lecdiam_r1,static_cast<float>(d->val[LECTURA_DIAMETRO_R1]));
	pvDisplayFloat(p,lcd_lecdiam_r2,static_cast<float>(d->val[LECTURA_DIAMETRO_R2]));

  	pvDisplayFloat(p,lcd_lecdistancia,static_cast<float>(d->val[TOTAL_METROS])/10);
	pvDisplayNum(p,lcd_lecdistancia_sesion,d->val[TOTAL_METROS_SESION]);
	dnumber = 65536*d->val[TOTAL_METROS_USUARIO_H] + d->val[TOTAL_METROS_USUARIO_L];
	snumber << dnumber;
	stexto = snumber.str();
	pvDisplayStr(p,lcd_lecdistancia_user,stexto.c_str());

	memset(texto,0,sizeof(texto));
	sprintf(texto,"%d",d->wval[wCONSIGNA_VELOCIDAD]);
//	sprintf(texto,"%d",d->con_vel);
	pvSetText(p,spi_convel,texto);
	memset(texto,0,sizeof(texto));
	sprintf(texto,"%d",d->wval[wCONSIGNA_TENSION_D]);
	pvSetText(p,spi_conten_d,texto);
	memset(texto,0,sizeof(texto));
	sprintf(texto,"%d",d->wval[wCONSIGNA_TENSION_R1]);
	pvSetText(p,spi_conten_r1,texto);
	memset(texto,0,sizeof(texto));
	sprintf(texto,"%d",d->wval[wCONSIGNA_TENSION_R2]);
	pvSetText(p,spi_conten_r2,texto);
//permisivos
	if(d->val[PERMISIVOS_MARCHA] > 0) 
		pvSetImage(p,piloto_permisivos,"./images/green.png");
	else
		pvSetImage(p,piloto_permisivos,"./images/red.png");
	//alarmas
	//cout << "DEBUG: numero de alarmas antes de la funcion: " << d->num_alarmas << endl;
	CheckAlarms(&d,&p,alarmHTML);
		
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
  int address;
  char texto[100];
  if(p == NULL || id == 0 || d == NULL) return -1;
	if(id == logout_button)
	{
		show_mask1(p);
	}
	else if(id == Conf_button)
	{
		show_mask3(p);
        }
	else if(id == mant_button)
	{
		if(MyData.UserLvl <= PRIV_MANT)
			show_mask6(p);		
         }
  	else if(id ==but_permisivos)
	{
		show_mask7(p);
	}
	else if  (id == button_reset_metros)
	{
		address = wRST_TOT_METROS;

		d->wval[address] = 1;
		sprintf(texto,"register(1,%d)",address);
		adqui.writeIntValue(texto,d->wval[address]);
	}
	else if  (id == button_resetdiam_d)
	{
		address = wRESET_DIAM_D;

		d->wval[address] = 1;
		sprintf(texto,"register(1,%d)",address);
		adqui.writeIntValue(texto,d->wval[address]);
	}
	else if  (id == button_resetdiam_r1)
	{
		address = wRESET_DIAM_R1;

		d->wval[address] = 1;
		sprintf(texto,"register(1,%d)",address);
		adqui.writeIntValue(texto,d->wval[address]);
	}
	else if  (id == button_resetdiam_r2)
	{
		address = wRESET_DIAM_R2;

		d->wval[address] = 1;
		sprintf(texto,"register(1,%d)",address);
		adqui.writeIntValue(texto,d->wval[address]);
	}
	else if(id ==button_load_vel)
	{

		pvInputDialog(p,button_load_vel,"Velocidad (m/min) min=0 max=200","");

	}
	else if(id ==button_load_ten_d)
	{

		pvInputDialog(p,button_load_ten_d,"Tensión Desbobinador (N) min=0 max=600","");

        }
	else if(id ==button_load_ten_r1)
	{
		pvInputDialog(p,button_load_ten_r1,"Tensión Rebobinador 1 (N) min=0 max=600","");

        }
	else if(id ==button_load_ten_r2)
	{

		pvInputDialog(p,button_load_ten_r2,"Tensión Rebobinador 2 (N) min=0 max=600","");

        }
	else if(id ==button_carga_metros_sesion)
	{
		//contador total de metros
		address = WCARGA_METROS_SESION;

		d->wval[address] = 1; //9 es la deriva en el valor
		memset(texto,0,sizeof(texto));
		sprintf(texto,"register(1,%d)",address);
		adqui.writeIntValue(texto,d->wval[address]);
		

        }
	else if(id ==button_carga_metros_user)
	{
	//contador total de metros
		address = WCARGA_METROS_USUARIO;

		d->wval[address] = MyData.UserId - 1; //1 es la deriva en el valor
		memset(texto,0,sizeof(texto));
		sprintf(texto,"register(1,%d)",address);
		adqui.writeIntValue(texto,d->wval[address]);
		

        }
  	else if(id == alarmHTML)
  	{
   	 	show_mask4(p);
  	}
  return 0;
}

static int slotTextEvent(PARAM *p, int id, DATA *d, const char *text)
{
  int val,address;
  char texto[100];
  if(p == NULL || id == 0 || d == NULL || text == NULL) return -1;
  if(id == button_load_vel)
  {
	val = atoi(text);
	if ((val == 0) && ( text[0] != '0'))
		printf("DEBUG: no es valor numerico \n");
	else
	{
		address = wCONSIGNA_VELOCIDAD;
		if(val >200)
			return 0;
		if(val < 0)
			return 0;
		
		d->wval[address] = val;
		sprintf(texto,"register(1,%d)",address);
		adqui.writeIntValue(texto,d->wval[address]);
	}	
  }
  else if(id==button_load_ten_d)
  {
	val = atoi(text);
	if ((val == 0) && ( text[0] != '0'))
		printf("DEBUG: no es valor numerico \n");
	else
	{
		if(val >600)
			val = 600;
		if(val < 0)
			val = 0;
		
		address = wCONSIGNA_TENSION_D;
		d->wval[address] = val;
		sprintf(texto,"register(1,%d)",address);
		adqui.writeIntValue(texto,d->wval[address]);
	}
  }
  else if(id==button_load_ten_r1)
  {
	val = atoi(text);
	if ((val == 0) && ( text[0] != '0'))
		printf("DEBUG: no es valor numerico \n");
	else
	{
		if(val >600)
			val = 600;
		if(val < 0)
			val = 0;
		
		address = wCONSIGNA_TENSION_R1;
		d->wval[address] = val;
		sprintf(texto,"register(1,%d)",address);
		adqui.writeIntValue(texto,d->wval[address]);
	}
  }
  else if(id==button_load_ten_r2)
  {
	val = atoi(text);
	if ((val == 0) && ( text[0] != '0'))
		printf("DEBUG: no es valor numerico \n");
	else
	{
		if(val >600)
			val = 600;
		if(val < 0)
			val = 0;
		
		address = wCONSIGNA_TENSION_R2;
		d->wval[address] = val;
		sprintf(texto,"register(1,%d)",address);
		adqui.writeIntValue(texto,d->wval[address]);
	}
  }
  else if(id == alarmHTML)
  {
    show_mask4(p);
  }
  return 0;
}

static int slotSliderEvent(PARAM *p, int id, DATA *d, int val)
{
  if(p == NULL || id == 0 || d == NULL || val < -1000) return -1;
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
  if(p == NULL || id == 0 || d == NULL || x < -1000 || y < -1000 || text == NULL) return -1;
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
