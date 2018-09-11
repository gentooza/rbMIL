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
//# mask3_slots.h for ProcessViewServer created: mar jun 3 09:48:44 2014
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



extern Alarm myalarm;
extern GLOBAL_DATA MyData;

static void setState(PARAM *p, DATA *d, int ind, int id, const char *IMAGEN_ON, const char * IMAGEN_OFF, const char* IMAGEN_INDEFINIDO) 
{ // helper function
  char filename[80] = "";
  if     (d->wval[ind] == 0) strcpy(filename,IMAGEN_OFF);
  else if(d->wval[ind] == 1) strcpy(filename,IMAGEN_ON);
  else                       strcpy(filename,IMAGEN_INDEFINIDO);
	//printf("DEBUG: image set: %s , valor: %d\n",filename,d->wval[ind] );
  pvSetImage(p,id,filename);
}
static int slotInit(PARAM *p, DATA *d)
{
  int address;
  char text[100];
  if(p == NULL || d == NULL) return -1;
	  d->state = -1; //init alarms html
  //memset(d,0,sizeof(DATA));
//capture modbus
	ReadCommDATA(&d);
  //iniciamos alarmas
  InitAlarms(&d);
//initial values
  if(d->val[ESTADO_MAQUINA] >= 2)
  { 
  	pvSetEnabled(p,imagen_mat_d,0);
	pvSetEnabled(p,imagen_mat_r1,0);
	pvSetEnabled(p,imagen_mat_r2,0);
  }
  else
  {
	pvSetEnabled(p,imagen_mat_d,1);
	pvSetEnabled(p,imagen_mat_r1,1);
	pvSetEnabled(p,imagen_mat_r2,1);
  }
  address = wHAB_CORTE;
  if( d->wval[address] == 0)
  {
	//desactivamos, esto hay que mejorarlo
	d->wval[wHAB_R2] = 0;
	memset(text,0,sizeof(text));
	sprintf(text,"register(1,%d)",wHAB_R2);
	adqui.writeIntValue(text,d->wval[wHAB_R2]);
	pvSetChecked(p,hab_reb2,d->wval[wHAB_R2]);
	pvSetEnabled(p,hab_reb2,0);
	d->wval[wHAB_REF1] = 0;
	sprintf(text,"register(1,%d)",wHAB_REF1);
	adqui.writeIntValue(text,d->wval[wHAB_REF1]);
	pvSetChecked(p,hab_ref1,d->wval[wHAB_REF1]);
	pvSetEnabled(p,hab_ref1,0);
	d->wval[wHAB_REF2] = 0;
	memset(text,0,sizeof(text));
	sprintf(text,"register(1,%d)",wHAB_REF2);
	adqui.writeIntValue(text,d->wval[wHAB_REF2]);
	pvSetChecked(p,hab_ref2,d->wval[wHAB_REF2]);
	pvSetEnabled(p,hab_ref2,0);
  }
  else
  {
	//desactivamos, esto hay que mejorarlo
	pvSetChecked(p,hab_reb2,d->wval[wHAB_R2]);
	pvSetEnabled(p,hab_reb2,1);

	pvSetChecked(p,hab_ref1,d->wval[wHAB_REF1]);
	pvSetEnabled(p,hab_ref1,1);

	pvSetChecked(p,hab_ref2,d->wval[wHAB_REF2]);
	pvSetEnabled(p,hab_ref2,1);
  }
  
  pvSetChecked(p,hab_corte,d->wval[address]);

  memset(text,0,sizeof(text));
  sprintf(text,"%d",d->wval[wDIAM_INI_D]);
  pvSetText(p,spi_diametro_d,text);
  memset(text,0,sizeof(text));
  sprintf(text,"%d",d->wval[wPARO_DISTANCIA]);
  pvSetText(p,spi_parada_distancia,text);
  memset(text,0,sizeof(text));
  sprintf(text,"%d",d->wval[wSECCION_MATERIAL]);
  pvSetText(p,lineedit_seccion,text);


  pvSetValue(p,spi_refilo1_L,d->wval[wL_REFILO1]);
  pvSetValue(p,spi_refilo2_L,d->wval[wL_REFILO2]);
//widgets read-only
	pvSetEditable(p,spi_refilo1_L,0);
	pvSetEditable(p,spi_refilo2_L,0);
	pvSetEditable(p,spi_diametro_d,0);
	pvSetEditable(p,spi_parada_distancia,0);
	pvSetEditable(p,lineedit_seccion,0);
  //mask navigation control
  MyData.lastMask = MyData.thisMask;
  MyData.thisMask = 3;
	
  //images
  pvDownloadFile(p,"./images/mat_abajo_d.PNG");
  pvDownloadFile(p,"./images/mat_abajo_r.PNG");
  pvDownloadFile(p,"./images/mat_arriba_d.PNG");
  pvDownloadFile(p,"./images/mat_arriba_r.PNG");



  return 0;
}

static int slotNullEvent(PARAM *p, DATA *d)
{
  char text[100];

  if(p == NULL || d == NULL) return -1;
//capture modbus
	ReadCommDATA(&d);
	//refresh visu
	 // printf("DEBUG: Estamos ene ste puto estado máquina! %d \n",d->val[ESTADO_MAQUINA]);
        //materiales
	setState(p,d,wMAT_ABAJO_D,imagen_mat_d,"./images/mat_abajo_d.PNG","./images/mat_arriba_d.PNG","./images/mat_arriba_d.PNG");
	setState(p,d,wMAT_ABAJO_R1,imagen_mat_r1,"./images/mat_abajo_r.PNG","./images/mat_arriba_r.PNG","./images/mat_arriba_r.PNG");
	setState(p,d,wMAT_ABAJO_R2,imagen_mat_r2,"./images/mat_abajo_r.PNG","./images/mat_arriba_r.PNG","./images/mat_arriba_r.PNG");
  	//diametros
 	setState(p,d,wDIAM_PEQ_R1,imagen_diametro_r1,"./images/calandra_grande.PNG","./images/calandra_chica.PNG","./images/calandra_chica.PNG");
	setState(p,d,wDIAM_PEQ_R2,imagen_diametro_r2,"./images/calandra_grande.PNG","./images/calandra_chica.PNG","./images/calandra_chica.PNG");
	setState(p,d,WCALANDRA_DG,imagen_diametro_d,"./images/calandra_grande.PNG","./images/calandra_chica.PNG","./images/calandra_chica.PNG");
  if(d->val[ESTADO_MAQUINA] >= 2)
  { 
  	pvSetEnabled(p,imagen_mat_r2,0);
	pvSetEnabled(p,imagen_mat_r2,0);
	pvSetEnabled(p,imagen_mat_r2,0);
  }
  else
  {
	pvSetEnabled(p,imagen_mat_r2,1);
	pvSetEnabled(p,imagen_mat_r2,1);
	pvSetEnabled(p,imagen_mat_r2,1);
  }


  memset(text,0,sizeof(text));
  sprintf(text,"%d",d->wval[wDIAM_INI_D]);
  pvSetText(p,spi_diametro_d,text);
  memset(text,0,sizeof(text));
  sprintf(text,"%d",d->wval[wPARO_DISTANCIA]);
  pvSetText(p,spi_parada_distancia,text);
  memset(text,0,sizeof(text));
  sprintf(text,"%d",d->wval[wSECCION_MATERIAL]);
  pvSetText(p,lineedit_seccion,text);
  //alarmas
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
  if(id == produccion_button)
  {
      show_mask2(p);
  }
  else if(id == mant_button)
  {
	if(MyData.UserLvl <= PRIV_MANT)
		show_mask6(p);		
  }
  else if(id == mas_config_button)
  {
	if(MyData.UserLvl <= PRIV_MANT)
		show_mask5(p);		
  }
  else if ( id == imagen_mat_d)
  {
     	address = wMAT_ABAJO_D;
	
	if (d->wval[address])
		d->wval[address] = 0;
	else
		d->wval[address] = 1;
	memset(texto,0,sizeof(texto));
	sprintf(texto,"register(1,%d)",address);
	adqui.writeIntValue(texto,d->wval[address]);	
  }
  else if ( id == imagen_mat_r1)
  {
     	address = wMAT_ABAJO_R1;
	
	if (d->wval[address])
		d->wval[address] = 0;
	else
		d->wval[address] = 1;
	memset(texto,0,sizeof(texto));
	sprintf(texto,"register(1,%d)",address);
	adqui.writeIntValue(texto,d->wval[address]);	
  }
  else if ( id == imagen_mat_r2)
  {
     	address = wMAT_ABAJO_R2;
	
	if (d->wval[address])
		d->wval[address] = 0;
	else
		d->wval[address] = 1;
	memset(texto,0,sizeof(texto));
	sprintf(texto,"register(1,%d)",address);
	adqui.writeIntValue(texto,d->wval[address]);
	cout << "DEBUG: writting mat reb2 por abajo = " << d->wval[address] << endl;	
  }
 else if ( id == imagen_diametro_r1)
  {
     	address = wDIAM_PEQ_R1;
	
	if (d->wval[address])
		d->wval[address] = 0;
	else
		d->wval[address] = 1;

	sprintf(texto,"register(1,%d)",address);
	adqui.writeIntValue(texto,d->wval[address]);	
  }
 else if ( id == imagen_diametro_r2)
  {
     	address = wDIAM_PEQ_R2;
	
	if (d->wval[address])
		d->wval[address] = 0;
	else
		d->wval[address] = 1;

	sprintf(texto,"register(1,%d)",address);
	adqui.writeIntValue(texto,d->wval[address]);	
  }
 else if ( id == imagen_diametro_d)
  {
     	address = WCALANDRA_DG;
	
	if (d->wval[address])
		d->wval[address] = 0;
	else
		d->wval[address] = 1;

	sprintf(texto,"register(1,%d)",address);
	adqui.writeIntValue(texto,d->wval[address]);	
  }
  else if(id == but_diametro_d)
  {
	pvInputDialog(p,but_diametro_d,"Diámetro Inicial Desbobinador (mm) min=100 max=800","");
  }
  else if(id == but_parada_distancia)
  {
	pvInputDialog(p,but_parada_distancia,"Distancia de Parada Programada (0 = desactivada) (m) min=0 max=4000","");
  }
  else if(id == but_seccion)
  {
	pvInputDialog(p,but_seccion,"Sección del material a rebobinar (pulgadas) min=100 max=600","");
  }

  else if(id == alarmHTML)
  {
   	 show_mask4(p);
  }
  return 0;
}

static int slotTextEvent(PARAM *p, int id, DATA *d, const char *text)
{
  int val, address;
  char texto[100];
  if(p == NULL || id == 0 || d == NULL || text == NULL) return -1;
  else if(id==but_diametro_d)
  {
	val = atoi(text);
	if ((val == 0) && ( text[0] != '0'))
		printf("DEBUG: no es valor numerico \n");
	else
	{
          	address = wDIAM_INI_D;
		if(val >800)
			val = d->wval[address];
		if(val < 100)
			val = d->wval[address];
		
		address = wDIAM_INI_D;
		d->wval[address] = val;
		sprintf(texto,"register(1,%d)",address);
		adqui.writeIntValue(texto,d->wval[address]);
	}
  }
  else if(id==but_parada_distancia)
  {
	val = atoi(text);
	if ((val == 0) && ( text[0] != '0'))
		printf("DEBUG: no es valor numerico \n");
	else
	{
		address = wPARO_DISTANCIA;
		if(val >4000)
			val = d->wval[address];
		if(val < 0)
			val = d->wval[address];
		
		d->wval[address] = val;
		sprintf(texto,"register(1,%d)",address);
		adqui.writeIntValue(texto,d->wval[address]);
	}
  }
  else if(id==but_seccion)
  {
	val = atoi(text);
	if ((val == 0) && ( text[0] != '0'))
		printf("DEBUG: no es valor numerico \n");
	else
	{
		address = wSECCION_MATERIAL;
		if(val >600)
			return 0;
		if(val < 100)
			return 0;
		
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
  int address;
  char texto[100];
  if(p == NULL || id == 0 || d == NULL || val < -1000) return -1;

   if(id == spi_refilo1_L)
  {
	address = wL_REFILO1;

	d->wval[address] = val;
	sprintf(texto,"register(1,%d)",address);
	adqui.writeIntValue(texto,d->wval[address]);	
  }
   if(id == spi_refilo2_L)
  {
	address = wL_REFILO2;

	d->wval[address] = val;
	sprintf(texto,"register(1,%d)",address);
	adqui.writeIntValue(texto,d->wval[address]);	
  }

  
  return 0;
}

static int slotCheckboxEvent(PARAM *p, int id, DATA *d, const char *text)
{
  int address;
  char texto[100];
  if(p == NULL || id == 0 || d == NULL || text == NULL) return -1;
  //printf("DEBUG: que mierda es el texto este?!?! %s \n",text);

  if (id == hab_corte)
  {
	address = wHAB_CORTE;
	if( d->wval[address] == 1)
	{
		d->wval[address] = 0;
		sprintf(texto,"register(1,%d)",address);
		adqui.writeIntValue(texto,d->wval[address]);
		pvSetChecked(p,hab_corte,d->wval[address]);
		//desactivamos, esto hay que mejorarlo
		d->wval[wHAB_R2] = 0;
		sprintf(texto,"register(1,%d)",wHAB_R2);
		adqui.writeIntValue(texto,d->wval[wHAB_R2]);
		pvSetChecked(p,hab_reb2,d->wval[wHAB_R2]);
		pvSetEnabled(p,hab_reb2,0);
		d->wval[wHAB_REF1] = 0;
		sprintf(texto,"register(1,%d)",wHAB_REF1);
		adqui.writeIntValue(texto,d->wval[wHAB_REF1]);
		pvSetChecked(p,hab_ref1,d->wval[wHAB_REF1]);
		pvSetEnabled(p,hab_ref1,0);
		d->wval[wHAB_REF2] = 0;
		sprintf(texto,"register(1,%d)",wHAB_REF2);
		adqui.writeIntValue(texto,d->wval[wHAB_REF2]);
		pvSetChecked(p,hab_ref2,d->wval[wHAB_REF2]);
		pvSetEnabled(p,hab_ref2,0);
	}
	else
	{
		d->wval[address] = 1;
		sprintf(texto,"register(1,%d)",address);
		adqui.writeIntValue(texto,d->wval[address]);
		pvSetChecked(p,hab_corte,d->wval[address]);
		//desactivamos, esto hay que mejorarlo
		d->wval[wHAB_R2] = 0;
		sprintf(texto,"register(1,%d)",wHAB_R2);
		adqui.writeIntValue(texto,d->wval[wHAB_R2]);
		pvSetChecked(p,hab_reb2,d->wval[wHAB_R2]);
		pvSetEnabled(p,hab_reb2,1);
		d->wval[wHAB_REF1] = 0;
		sprintf(texto,"register(1,%d)",wHAB_REF1);
		adqui.writeIntValue(texto,d->wval[wHAB_REF1]);
		pvSetChecked(p,hab_ref1,d->wval[wHAB_REF1]);
		pvSetEnabled(p,hab_ref1,1);
		d->wval[wHAB_REF2] = 0;
		sprintf(texto,"register(1,%d)",wHAB_REF2);
		adqui.writeIntValue(texto,d->wval[wHAB_REF2]);
		pvSetChecked(p,hab_ref2,d->wval[wHAB_REF2]);
		pvSetEnabled(p,hab_ref2,1);
	}
	
  }
  else if (id == hab_reb2)
  {
  	if (d->wval[wHAB_CORTE] == 1)
	{
		address = wHAB_R2;
		if( d->wval[address] == 1)
		{
			d->wval[address] = 0;
			sprintf(texto,"register(1,%d)",address);
			adqui.writeIntValue(texto,d->wval[address]);
		}
		else
		{
			d->wval[address] = 1;
			sprintf(texto,"register(1,%d)",address);
			adqui.writeIntValue(texto,d->wval[address]);
		}
		pvSetChecked(p,hab_reb2,d->wval[address]);
	}
  }
   else if (id == hab_ref1)
  {
  	if (d->wval[wHAB_CORTE] == 1)
	{
		address = wHAB_REF1;
		if( d->wval[address] == 1)
		{
			d->wval[address] = 0;
			sprintf(texto,"register(1,%d)",address);
			adqui.writeIntValue(texto,d->wval[address]);
		}
		else
		{
			d->wval[address] = 1;
			sprintf(texto,"register(1,%d)",address);
			adqui.writeIntValue(texto,d->wval[address]);
		}
		pvSetChecked(p,hab_ref1,d->wval[address]);
	}
  }
   else if (id == hab_ref2)
  {
  	if (d->wval[wHAB_CORTE] == 1)
	{
		address = wHAB_REF2;
		if( d->wval[address] == 1)
		{
			d->wval[address] = 0;
			sprintf(texto,"register(1,%d)",address);
			adqui.writeIntValue(texto,d->wval[address]);
		}
		else
		{
			d->wval[address] = 1;
			sprintf(texto,"register(1,%d)",address);
			adqui.writeIntValue(texto,d->wval[address]);
		}
		pvSetChecked(p,hab_ref2,d->wval[address]);
	}
  }	
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

