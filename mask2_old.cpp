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
////////////////////////////////////////////////////////////////////////////
//
// show_mask2 for ProcessViewServer created: mié may 28 11:31:36 2014
//
////////////////////////////////////////////////////////////////////////////
#include "pvapp.h"

// _begin_of_generated_area_ (do not edit -> use ui2pvc) -------------------

// our mask contains the following objects
enum {
  ID_MAIN_WIDGET = 0,
  obj1,
  imagen_fondo,
  obj3,
  lb_desb,
  lb_reb1,
  lb_reb2,
  lcd_lecdiam_d,
  lcd_lecdiam_r1,
  lcd_lecdiam_r2,
  button_resetdiam_d,
  button_resetdiam_r1,
  button_resetdiam_r2,
  titulillo_diametros,
  logout_button,
  Conf_button,
  mant_button,
  titulo,
  panel_estado,
  LineEdit_Estado,
  label1,
  linedit_user,
  panel2,
  label3,
  label6,
  label7,
  lcd_lecvel,
  spi_convel,
  button_load_vel,
  panel3,
  label4,
  lb_desb_,
  lb_reb1_,
  lb_reb2_,
  label8,
  label10,
  lcd_lecten_d,
  lcd_lecten_r1,
  lcd_lecten_r2,
  spi_conten_d,
  spi_conten_r1,
  spi_conten_r2,
  button_load_ten_d,
  button_load_ten_r1,
  button_load_ten_r2,
  panel_metros,
  label_total_metros,
  label_total_metros_trab,
  lcd_lecdistancia,
  button_reset_metros,
  label_total_metros_sesion,
  lcd_lecdistancia_sesion,
  button_carga_metros_sesion,
  label_total_metros_user,
  lcd_lecdistancia_user,
  button_carga_metros_user,
  alarmHTML,
  ID_END_OF_WIDGETS
};

  static const char *toolTip[] = {
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  ""};

  static const char *whatsThis[] = {
  "",
  "",
  "./images/fondo_hmi.jpg",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "./images/fondo",
  "",
  "",
  "./images/grey.png",
  "",
  "",
  "./images/grey.png",
  "",
  "",
  "./images/grey.png",
  "",
  "",
  "./images/grey.png",
  "",
  "",
  "./images/grey.png",
  "",
  "",
  "./images/grey.png",
  "",
  "",
  "./images/grey.png",
  "",
  "",
  "./images/grey.png",
  "",
  "",
  "./images/grey.png",
  "",
  "",
  "",
  "./images/grey.png",
  "",
  "./images/grey.png",
  "",
  "",
  "",
  "./images/grey.png",
  "",
  "./images/grey.png",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  ""};

  static const int widgetType[ID_END_OF_WIDGETS+1] = {
  0,
  TQFrame,
  TQImage,
  TQFrame,
  TQLabel,
  TQLabel,
  TQLabel,
  TQLCDNumber,
  TQLCDNumber,
  TQLCDNumber,
  TQPushButton,
  TQPushButton,
  TQPushButton,
  TQLabel,
  TQPushButton,
  TQPushButton,
  TQPushButton,
  TQLabel,
  TQFrame,
  TQLineEdit,
  TQLabel,
  TQLineEdit,
  TQFrame,
  TQLabel,
  TQLabel,
  TQLabel,
  TQLCDNumber,
  TQLineEdit,
  TQPushButton,
  TQFrame,
  TQLabel,
  TQLabel,
  TQLabel,
  TQLabel,
  TQLabel,
  TQLabel,
  TQLCDNumber,
  TQLCDNumber,
  TQLCDNumber,
  TQLineEdit,
  TQLineEdit,
  TQLineEdit,
  TQPushButton,
  TQPushButton,
  TQPushButton,
  TQFrame,
  TQLabel,
  TQLabel,
  TQLCDNumber,
  TQPushButton,
  TQLabel,
  TQLCDNumber,
  TQPushButton,
  TQLabel,
  TQLCDNumber,
  TQPushButton,
  TQTextBrowser,
  -1 };

static int generated_defineMask(PARAM *p)
{
  int w,h,depth;

  if(p == NULL) return 1;
  w = h = depth = strcmp(toolTip[0],whatsThis[0]);
  if(widgetType[0] == -1) return 1;
  if(w==h) depth=0; // fool the compiler
  pvStartDefinition(p,ID_END_OF_WIDGETS);

  pvQFrame(p,obj1,0,StyledPanel,Raised,2,1);
  pvSetGeometry(p,obj1,0,0,800,600);
  pvSetPaletteBackgroundColor(p,obj1,200,215,200);
  pvSetFont(p,obj1,"Arial",11,0,0,0,0);

  pvDownloadFile(p,"./images/fondo_hmi.jpg");
  pvQImage(p,imagen_fondo,obj1,"./images/fondo_hmi.jpg",&w,&h,&depth);
  pvSetGeometry(p,imagen_fondo,0,0,1280,800);
  pvSetFont(p,imagen_fondo,"Arial",11,0,0,0,0);
  pvSetWhatsThis(p,imagen_fondo,pvtr("./images/fondo_hmi.jpg"));

  pvQFrame(p,obj3,imagen_fondo,StyledPanel,Raised,2,1);
  pvSetGeometry(p,obj3,600,377,195,140);
  pvSetPaletteBackgroundColor(p,obj3,237,237,237);
  pvSetFont(p,obj3,"Arial",11,0,0,0,0);

  pvQLabel(p,lb_desb,obj3);
  pvSetGeometry(p,lb_desb,3,27,60,30);
  pvSetText(p,lb_desb,pvtr("DESB."));
  pvSetFont(p,lb_desb,"Arial",10,1,0,0,0);

  pvQLabel(p,lb_reb1,obj3);
  pvSetGeometry(p,lb_reb1,66,27,60,30);
  pvSetText(p,lb_reb1,pvtr("REB1."));
  pvSetFont(p,lb_reb1,"Arial",10,1,0,0,0);

  pvQLabel(p,lb_reb2,obj3);
  pvSetGeometry(p,lb_reb2,129,27,60,30);
  pvSetText(p,lb_reb2,pvtr("REB2."));
  pvSetFont(p,lb_reb2,"Arial",10,1,0,0,0);

  pvQLCDNumber(p,lcd_lecdiam_d,obj3,4,Filled,Dec);
  pvSetGeometry(p,lcd_lecdiam_d,3,50,60,40);
  pvSetFont(p,lcd_lecdiam_d,"Arial",11,0,0,0,0);

  pvQLCDNumber(p,lcd_lecdiam_r1,obj3,4,Filled,Dec);
  pvSetGeometry(p,lcd_lecdiam_r1,66,50,60,40);
  pvSetFont(p,lcd_lecdiam_r1,"Arial",11,0,0,0,0);

  pvQLCDNumber(p,lcd_lecdiam_r2,obj3,4,Filled,Dec);
  pvSetGeometry(p,lcd_lecdiam_r2,129,50,60,40);
  pvSetFont(p,lcd_lecdiam_r2,"Arial",11,0,0,0,0);

  pvQPushButton(p,button_resetdiam_d,obj3);
  pvSetGeometry(p,button_resetdiam_d,3,90,60,45);
  pvSetText(p,button_resetdiam_d,pvtr("Reset"));
  pvSetFont(p,button_resetdiam_d,"Arial",11,0,0,0,0);

  pvQPushButton(p,button_resetdiam_r1,obj3);
  pvSetGeometry(p,button_resetdiam_r1,66,90,60,45);
  pvSetText(p,button_resetdiam_r1,pvtr("Reset"));
  pvSetFont(p,button_resetdiam_r1,"Arial",11,0,0,0,0);

  pvQPushButton(p,button_resetdiam_r2,obj3);
  pvSetGeometry(p,button_resetdiam_r2,129,90,60,45);
  pvSetText(p,button_resetdiam_r2,pvtr("Reset"));
  pvSetFont(p,button_resetdiam_r2,"Arial",11,0,0,0,0);

  pvQLabel(p,titulillo_diametros,obj3);
  pvSetGeometry(p,titulillo_diametros,3,3,150,21);
  pvSetText(p,titulillo_diametros,pvtr("DIÁMETROS (mm)"));
  pvSetFont(p,titulillo_diametros,"Arial",13,1,0,0,0);


  pvQPushButton(p,logout_button,obj1);
  pvSetGeometry(p,logout_button,696,51,99,30);
  pvSetText(p,logout_button,pvtr("Logout"));
  pvSetFont(p,logout_button,"Arial",11,0,0,0,0);

  pvQPushButton(p,Conf_button,obj1);
  pvSetGeometry(p,Conf_button,3,3,120,60);
  pvSetText(p,Conf_button,pvtr("Configuración"));
  pvSetFont(p,Conf_button,"Arial",11,0,0,0,0);

  pvQPushButton(p,mant_button,obj1);
  pvSetGeometry(p,mant_button,123,3,120,60);
  pvSetText(p,mant_button,pvtr("Mantenimiento"));
  pvSetFont(p,mant_button,"Arial",11,0,0,0,0);

  pvQLabel(p,titulo,obj1);
  pvSetGeometry(p,titulo,603,6,189,39);
  pvSetText(p,titulo,pvtr("PRODUCCIÓN"));
  pvSetPaletteForegroundColor(p,titulo,49,200,57);
  pvSetFont(p,titulo,"Arial",20,1,0,0,0);

  pvQFrame(p,panel_estado,obj1,StyledPanel,Raised,2,1);
  pvSetGeometry(p,panel_estado,3,105,267,90);
  pvSetPaletteBackgroundColor(p,panel_estado,237,237,237);
  pvSetFont(p,panel_estado,"Arial",11,0,0,0,0);

  pvQLineEdit(p,LineEdit_Estado,panel_estado);
  pvSetGeometry(p,LineEdit_Estado,12,33,189,45);
  pvSetText(p,LineEdit_Estado,pvtr("LineEdit"));
  pvSetFont(p,LineEdit_Estado,"Arial",14,1,0,0,0);

  pvQLabel(p,label1,panel_estado);
  pvSetGeometry(p,label1,57,3,99,30);
  pvSetText(p,label1,pvtr("ESTADO"));
  pvSetFont(p,label1,"Arial",16,1,0,0,0);

  pvQLineEdit(p,linedit_user,obj1);
  pvSetGeometry(p,linedit_user,597,51,99,30);
  pvSetText(p,linedit_user,pvtr("LineEdit"));
  pvSetFont(p,linedit_user,"Arial",11,0,0,0,0);

  pvQFrame(p,panel2,obj1,StyledPanel,Raised,2,1);
  pvSetGeometry(p,panel2,3,198,267,99);
  pvSetPaletteBackgroundColor(p,panel2,237,237,237);
  pvSetFont(p,panel2,"Arial",11,0,0,0,0);

  pvQLabel(p,label3,panel2);
  pvSetGeometry(p,label3,3,3,161,21);
  pvSetText(p,label3,pvtr("VELOCIDAD (m/min)"));
  pvSetFont(p,label3,"Arial",13,1,0,0,0);

  pvQLabel(p,label6,panel2);
  pvSetGeometry(p,label6,3,27,80,30);
  pvSetText(p,label6,pvtr("CONSIGNA:"));
  pvSetFont(p,label6,"Arial",10,1,0,0,0);

  pvQLabel(p,label7,panel2);
  pvSetGeometry(p,label7,3,60,70,30);
  pvSetText(p,label7,pvtr("LECTURA:"));
  pvSetFont(p,label7,"Arial",10,1,0,0,0);

  pvQLCDNumber(p,lcd_lecvel,panel2,4,Filled,Dec);
  pvSetGeometry(p,lcd_lecvel,96,57,70,30);
  pvSetPaletteForegroundColor(p,lcd_lecvel,1,1,1);
  pvSetPaletteBackgroundColor(p,lcd_lecvel,255,255,255);
  pvSetFont(p,lcd_lecvel,"Arial",11,0,0,0,0);

  pvQLineEdit(p,spi_convel,panel2);
  pvSetGeometry(p,spi_convel,96,24,72,34);
  pvSetFont(p,spi_convel,"Arial",11,0,0,0,0);

  pvQPushButton(p,button_load_vel,panel2);
  pvSetGeometry(p,button_load_vel,168,24,22,34);
  pvSetText(p,button_load_vel,pvtr("<"));
  pvSetFont(p,button_load_vel,"Arial",11,1,0,0,0);

  pvQFrame(p,panel3,obj1,StyledPanel,Raised,2,1);
  pvSetGeometry(p,panel3,273,377,324,140);
  pvSetPaletteBackgroundColor(p,panel3,237,237,237);
  pvSetFont(p,panel3,"Arial",11,0,0,0,0);

  pvQLabel(p,label4,panel3);
  pvSetGeometry(p,label4,3,3,310,21);
  pvSetText(p,label4,pvtr("TENSIÓN (N)"));
  pvSetFont(p,label4,"Arial",13,1,0,0,0);

  pvQLabel(p,lb_desb_,panel3);
  pvSetGeometry(p,lb_desb_,85,27,60,30);
  pvSetText(p,lb_desb_,pvtr("DESB."));
  pvSetFont(p,lb_desb_,"Arial",10,1,0,0,0);

  pvQLabel(p,lb_reb1_,panel3);
  pvSetGeometry(p,lb_reb1_,164,27,60,30);
  pvSetText(p,lb_reb1_,pvtr("REB1."));
  pvSetFont(p,lb_reb1_,"Arial",10,1,0,0,0);

  pvQLabel(p,lb_reb2_,panel3);
  pvSetGeometry(p,lb_reb2_,243,27,60,30);
  pvSetText(p,lb_reb2_,pvtr("REB2."));
  pvSetFont(p,lb_reb2_,"Arial",10,1,0,0,0);

  pvQLabel(p,label8,panel3);
  pvSetGeometry(p,label8,3,60,80,30);
  pvSetText(p,label8,pvtr("CONSIGNA:"));
  pvSetFont(p,label8,"Arial",10,1,0,0,0);

  pvQLabel(p,label10,panel3);
  pvSetGeometry(p,label10,3,100,70,30);
  pvSetText(p,label10,pvtr("LECTURA:"));
  pvSetFont(p,label10,"Arial",10,1,0,0,0);

  pvQLCDNumber(p,lcd_lecten_d,panel3,4,Filled,Dec);
  pvSetGeometry(p,lcd_lecten_d,85,94,60,40);
  pvSetFont(p,lcd_lecten_d,"Arial",11,0,0,0,0);

  pvQLCDNumber(p,lcd_lecten_r1,panel3,4,Filled,Dec);
  pvSetGeometry(p,lcd_lecten_r1,164,94,60,40);
  pvSetFont(p,lcd_lecten_r1,"Arial",11,0,0,0,0);

  pvQLCDNumber(p,lcd_lecten_r2,panel3,4,Filled,Dec);
  pvSetGeometry(p,lcd_lecten_r2,243,94,60,40);
  pvSetFont(p,lcd_lecten_r2,"Arial",11,0,0,0,0);

  pvQLineEdit(p,spi_conten_d,panel3);
  pvSetGeometry(p,spi_conten_d,85,57,52,34);
  pvSetFont(p,spi_conten_d,"Arial",11,0,0,0,0);

  pvQLineEdit(p,spi_conten_r1,panel3);
  pvSetGeometry(p,spi_conten_r1,164,57,52,34);
  pvSetFont(p,spi_conten_r1,"Arial",11,0,0,0,0);

  pvQLineEdit(p,spi_conten_r2,panel3);
  pvSetGeometry(p,spi_conten_r2,243,57,52,34);
  pvSetFont(p,spi_conten_r2,"Arial",11,0,0,0,0);

  pvQPushButton(p,button_load_ten_d,panel3);
  pvSetGeometry(p,button_load_ten_d,135,55,31,38);
  pvSetText(p,button_load_ten_d,pvtr("<"));
  pvSetFont(p,button_load_ten_d,"Arial",11,1,0,0,0);

  pvQPushButton(p,button_load_ten_r1,panel3);
  pvSetGeometry(p,button_load_ten_r1,214,55,31,38);
  pvSetText(p,button_load_ten_r1,pvtr("<"));
  pvSetFont(p,button_load_ten_r1,"Arial",11,1,0,0,0);

  pvQPushButton(p,button_load_ten_r2,panel3);
  pvSetGeometry(p,button_load_ten_r2,293,55,31,38);
  pvSetText(p,button_load_ten_r2,pvtr("<"));
  pvSetFont(p,button_load_ten_r2,"Arial",11,1,0,0,0);

  pvQFrame(p,panel_metros,obj1,StyledPanel,Raised,2,1);
  pvSetGeometry(p,panel_metros,3,300,267,217);
  pvSetPaletteBackgroundColor(p,panel_metros,237,237,237);
  pvSetFont(p,panel_metros,"Arial",11,0,0,0,0);

  pvQLabel(p,label_total_metros,panel_metros);
  pvSetGeometry(p,label_total_metros,3,3,200,21);
  pvSetText(p,label_total_metros,pvtr("METROS TOTALES (m)"));
  pvSetFont(p,label_total_metros,"Arial",13,1,0,0,0);

  pvQLabel(p,label_total_metros_trab,panel_metros);
  pvSetGeometry(p,label_total_metros_trab,3,24,200,21);
  pvSetText(p,label_total_metros_trab,pvtr("Metros trabajo actual:"));
  pvSetFont(p,label_total_metros_trab,"Arial",10,1,0,0,0);

  pvQLCDNumber(p,lcd_lecdistancia,panel_metros,4,Filled,Dec);
  pvSetGeometry(p,lcd_lecdistancia,6,45,110,35);
  pvSetPaletteForegroundColor(p,lcd_lecdistancia,1,1,1);
  pvSetPaletteBackgroundColor(p,lcd_lecdistancia,255,255,255);
  pvSetFont(p,lcd_lecdistancia,"Arial",11,1,0,0,0);

  pvQPushButton(p,button_reset_metros,panel_metros);
  pvSetGeometry(p,button_reset_metros,120,45,80,35);
  pvSetText(p,button_reset_metros,pvtr("Reset"));
  pvSetFont(p,button_reset_metros,"Arial",11,0,0,0,0);

  pvQLabel(p,label_total_metros_sesion,panel_metros);
  pvSetGeometry(p,label_total_metros_sesion,3,80,200,21);
  pvSetText(p,label_total_metros_sesion,pvtr("Metros sesión:"));
  pvSetFont(p,label_total_metros_sesion,"Arial",10,1,0,0,0);

  pvQLCDNumber(p,lcd_lecdistancia_sesion,panel_metros,5,Filled,Dec);
  pvSetGeometry(p,lcd_lecdistancia_sesion,6,101,110,30);
  pvSetPaletteForegroundColor(p,lcd_lecdistancia_sesion,1,1,1);
  pvSetPaletteBackgroundColor(p,lcd_lecdistancia_sesion,255,255,255);
  pvSetFont(p,lcd_lecdistancia_sesion,"Arial",11,0,0,0,0);

  pvQPushButton(p,button_carga_metros_sesion,panel_metros);
  pvSetGeometry(p,button_carga_metros_sesion,120,101,80,30);
  pvSetText(p,button_carga_metros_sesion,pvtr("Carga"));
  pvSetFont(p,button_carga_metros_sesion,"Arial",11,0,0,0,0);

  pvQLabel(p,label_total_metros_user,panel_metros);
  pvSetGeometry(p,label_total_metros_user,3,131,200,21);
  pvSetText(p,label_total_metros_user,pvtr("Metros usuario:"));
  pvSetFont(p,label_total_metros_user,"Arial",10,1,0,0,0);

  pvQLCDNumber(p,lcd_lecdistancia_user,panel_metros,12,Filled,Dec);
  pvSetGeometry(p,lcd_lecdistancia_user,6,152,130,30);
  pvSetPaletteForegroundColor(p,lcd_lecdistancia_user,1,1,1);
  pvSetPaletteBackgroundColor(p,lcd_lecdistancia_user,255,255,255);
  pvSetFont(p,lcd_lecdistancia_user,"Arial",11,0,0,0,0);

  pvQPushButton(p,button_carga_metros_user,panel_metros);
  pvSetGeometry(p,button_carga_metros_user,150,152,80,30);
  pvSetText(p,button_carga_metros_user,pvtr("Carga"));
  pvSetFont(p,button_carga_metros_user,"Arial",11,0,0,0,0);

  pvQTextBrowser(p,alarmHTML,obj1);
  pvSetGeometry(p,alarmHTML,3,520,793,76);
  pvSetFont(p,alarmHTML,"Sans Serif",10,0,0,0,0);


  pvEndDefinition(p);
  return 0;
}

// _end_of_generated_area_ (do not edit -> use ui2pvc) ---------------------

#include "mask2_slots.h"

static int defineMask(PARAM *p)
{
  if(p == NULL) return 1;
  generated_defineMask(p);
  // (todo: add your code here)
  return 0;
}


static int showData(PARAM *p, DATA *d)
{
  if(p == NULL) return 1;
  if(d == NULL) return 1;
  return 0;
}

static int readData(DATA *d) // from shared memory, database or something else
{
  if(d == NULL) return 1;
  // (todo: add your code here)
  return 0;
}


int show_mask2(PARAM *p)
{
  DATA d;
  char event[MAX_EVENT_LENGTH];
  char text[MAX_EVENT_LENGTH];
  char str1[MAX_EVENT_LENGTH];
  int  i,w,h,val,x,y,button,ret;
  float xval, yval;

  defineMask(p);
  //rlSetDebugPrintf(1);
  if((ret=slotInit(p,&d)) != 0) return ret;
  readData(&d); // from shared memory, database or something else
  showData(p,&d);
  pvClearMessageQueue(p);
  while(1)
  {
    pvPollEvent(p,event);
    switch(pvParseEvent(event, &i, text))
    {
      case NULL_EVENT:
        readData(&d); // from shared memory, database or something else
        showData(p,&d);
        if((ret=slotNullEvent(p,&d)) != 0) return ret;
        break;
      case BUTTON_EVENT:
        if(trace) printf("BUTTON_EVENT id=%d\n",i);
        if((ret=slotButtonEvent(p,i,&d)) != 0) return ret;
        break;
      case BUTTON_PRESSED_EVENT:
        if(trace) printf("BUTTON_PRESSED_EVENT id=%d\n",i);
        if((ret=slotButtonPressedEvent(p,i,&d)) != 0) return ret;
        break;
      case BUTTON_RELEASED_EVENT:
        if(trace) printf("BUTTON_RELEASED_EVENT id=%d\n",i);
        if((ret=slotButtonReleasedEvent(p,i,&d)) != 0) return ret;
        break;
      case TEXT_EVENT:
        if(trace) printf("TEXT_EVENT id=%d %s\n",i,text);
        if((ret=slotTextEvent(p,i,&d,text)) != 0) return ret;
        break;
      case SLIDER_EVENT:
        sscanf(text,"(%d)",&val);
        if(trace) printf("SLIDER_EVENT val=%d\n",val);
        if((ret=slotSliderEvent(p,i,&d,val)) != 0) return ret;
        break;
      case CHECKBOX_EVENT:
        if(trace) printf("CHECKBOX_EVENT id=%d %s\n",i,text);
        if((ret=slotCheckboxEvent(p,i,&d,text)) != 0) return ret;
        break;
      case RADIOBUTTON_EVENT:
        if(trace) printf("RADIOBUTTON_EVENT id=%d %s\n",i,text);
        if((ret=slotRadioButtonEvent(p,i,&d,text)) != 0) return ret;
        break;
      case GL_INITIALIZE_EVENT:
        if(trace) printf("you have to call initializeGL()\n");
        if((ret=slotGlInitializeEvent(p,i,&d)) != 0) return ret;
        break;
      case GL_PAINT_EVENT:
        if(trace) printf("you have to call paintGL()\n");
        if((ret=slotGlPaintEvent(p,i,&d)) != 0) return ret;
        break;
      case GL_RESIZE_EVENT:
        sscanf(text,"(%d,%d)",&w,&h);
        if(trace) printf("you have to call resizeGL(w,h)\n");
        if((ret=slotGlResizeEvent(p,i,&d,w,h)) != 0) return ret;
        break;
      case GL_IDLE_EVENT:
        if((ret=slotGlIdleEvent(p,i,&d)) != 0) return ret;
        break;
      case TAB_EVENT:
        sscanf(text,"(%d)",&val);
        if(trace) printf("TAB_EVENT(%d,page=%d)\n",i,val);
        if((ret=slotTabEvent(p,i,&d,val)) != 0) return ret;
        break;
      case TABLE_TEXT_EVENT:
        sscanf(text,"(%d,%d,",&x,&y);
        pvGetText(text,str1);
        if(trace) printf("TABLE_TEXT_EVENT(%d,%d,\"%s\")\n",x,y,str1);
        if((ret=slotTableTextEvent(p,i,&d,x,y,str1)) != 0) return ret;
        break;
      case TABLE_CLICKED_EVENT:
        sscanf(text,"(%d,%d,%d)",&x,&y,&button);
        if(trace) printf("TABLE_CLICKED_EVENT(%d,%d,button=%d)\n",x,y,button);
        if((ret=slotTableClickedEvent(p,i,&d,x,y,button)) != 0) return ret;
        break;
      case SELECTION_EVENT:
        sscanf(text,"(%d,",&val);
        pvGetText(text,str1);
        if(trace) printf("SELECTION_EVENT(column=%d,\"%s\")\n",val,str1);
        if((ret=slotSelectionEvent(p,i,&d,val,str1)) != 0) return ret;
        break;
      case CLIPBOARD_EVENT:
        sscanf(text,"(%d",&val);
        if(trace) printf("CLIPBOARD_EVENT(id=%d)\n",val);
        if(trace) printf("clipboard = \n%s\n",p->clipboard);
        if((ret=slotClipboardEvent(p,i,&d,val)) != 0) return ret;
        break;
      case RIGHT_MOUSE_EVENT:
        if(trace) printf("RIGHT_MOUSE_EVENT id=%d text=%s\n",i,text);
        if((ret=slotRightMouseEvent(p,i,&d,text)) != 0) return ret;
        break;
      case KEYBOARD_EVENT:
        sscanf(text,"(%d",&val);
        if(trace) printf("KEYBOARD_EVENT modifier=%d key=%d\n",i,val);
        if((ret=slotKeyboardEvent(p,i,&d,val,i)) != 0) return ret;
        break;
      case PLOT_MOUSE_MOVED_EVENT:
        sscanf(text,"(%f,%f)",&xval,&yval);
        if(trace) printf("PLOT_MOUSE_MOVE %f %f\n",xval,yval);
        if((ret=slotMouseMovedEvent(p,i,&d,xval,yval)) != 0) return ret;
        break;
      case PLOT_MOUSE_PRESSED_EVENT:
        sscanf(text,"(%f,%f)",&xval,&yval);
        if(trace) printf("PLOT_MOUSE_PRESSED %f %f\n",xval,yval);
        if((ret=slotMousePressedEvent(p,i,&d,xval,yval)) != 0) return ret;
        break;
      case PLOT_MOUSE_RELEASED_EVENT:
        sscanf(text,"(%f,%f)",&xval,&yval);
        if(trace) printf("PLOT_MOUSE_RELEASED %f %f\n",xval,yval);
        if((ret=slotMouseReleasedEvent(p,i,&d,xval,yval)) != 0) return ret;
        break;
      case MOUSE_OVER_EVENT:
        sscanf(text,"%d",&val);
        if(trace) printf("MOUSE_OVER_EVENT %d\n",val);
        if((ret=slotMouseOverEvent(p,i,&d,val)) != 0) return ret;
        break;
      case USER_EVENT:
        if(trace) printf("USER_EVENT id=%d %s\n",i,text);
        if((ret=slotUserEvent(p,i,&d,text)) != 0) return ret;
        break;
      default:
        if(trace) printf("UNKNOWN_EVENT id=%d %s\n",i,text);
        break;
    }
  }
}
