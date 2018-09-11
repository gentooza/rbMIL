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
// show_mask3 for ProcessViewServer created: mar jun 3 09:48:44 2014
//
////////////////////////////////////////////////////////////////////////////
#include "pvapp.h"

// _begin_of_generated_area_ (do not edit -> use ui2pvc) -------------------

// our mask contains the following objects
enum {
  ID_MAIN_WIDGET = 0,
  fondo,
  imagen_fondo,
  panel1,
  titulillo_material,
  titulillo2_material_d,
  titulillo2_material_r1,
  titulillo2_material_r2,
  imagen_mat_d,
  imagen_mat_r1,
  imagen_mat_r2,
  panel_refilos,
  titulillo_refilos,
  titulillo2_refilo1,
  titulillo3_refilo1_LL,
  titulillo3_refilo1_HL,
  spi_refilo1_L,
  spi_refilo2_L,
  produccion_button,
  mant_button,
  mas_config_button,
  alarmHTML,
  titulo,
  panel2,
  hab_corte,
  hab_reb2,
  hab_ref1,
  hab_ref2,
  panel3,
  titulillo_diametros,
  titulillo2_diametros_d,
  titulillo2_diametros_r1,
  titulillo2_diametros_r2,
  spi_diametro_d,
  but_diametro_d,
  imagen_diametro_r1,
  imagen_diametro_r2,
  imagen_diametro_d,
  panel_paradas,
  titulillo_paradas,
  titulillo2_distancia,
  spi_parada_distancia,
  but_parada_distancia,
  panel_seccion,
  titulo_seccion,
  titulillo_seccion,
  lineedit_seccion,
  but_seccion,
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
  ""};

  static const char *whatsThis[] = {
  "",
  "",
  "./images/maquina.jpg",
  "",
  "",
  "",
  "",
  "",
  "./images/mat_abajo.PNG",
  "./images/mat_abajo.PNG",
  "./images/mat_abajo.PNG",
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
  "./images/calandra_grande.PNG",
  "./images/calandra_grande.PNG",
  "./images/calandra_chica.PNG",
  "",
  "./images/calandra_grande.PNG",
  "./images/calandra_chica.PNG",
  "./images/calandra_chica.PNG",
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
  TQLabel,
  TQImage,
  TQImage,
  TQImage,
  TQFrame,
  TQLabel,
  TQLabel,
  TQLabel,
  TQLabel,
  TQSpinBox,
  TQSpinBox,
  TQPushButton,
  TQPushButton,
  TQPushButton,
  TQTextBrowser,
  TQLabel,
  TQFrame,
  TQCheck,
  TQCheck,
  TQCheck,
  TQCheck,
  TQFrame,
  TQLabel,
  TQLabel,
  TQLabel,
  TQLabel,
  TQLineEdit,
  TQPushButton,
  TQImage,
  TQImage,
  TQImage,
  TQFrame,
  TQLabel,
  TQLabel,
  TQLineEdit,
  TQPushButton,
  TQFrame,
  TQLabel,
  TQLabel,
  TQLineEdit,
  TQPushButton,
  -1 };

static int generated_defineMask(PARAM *p)
{
  int w,h,depth;

  if(p == NULL) return 1;
  w = h = depth = strcmp(toolTip[0],whatsThis[0]);
  if(widgetType[0] == -1) return 1;
  if(w==h) depth=0; // fool the compiler
  pvStartDefinition(p,ID_END_OF_WIDGETS);

  pvQFrame(p,fondo,0,StyledPanel,Raised,2,1);
  pvSetGeometry(p,fondo,0,0,800,600);
  pvSetPaletteBackgroundColor(p,fondo,200,215,200);
  pvSetFont(p,fondo,"Arial",11,0,0,0,0);

  pvDownloadFile(p,"./images/maquina.jpg");
  pvQImage(p,imagen_fondo,fondo,"./images/maquina.jpg",&w,&h,&depth);
  pvSetGeometry(p,imagen_fondo,0,0,1280,800);
  pvSetFont(p,imagen_fondo,"Arial",11,0,0,0,0);
  pvSetWhatsThis(p,imagen_fondo,pvtr("./images/maquina.jpg"));

  pvQFrame(p,panel1,imagen_fondo,StyledPanel,Raised,2,1);
  pvSetGeometry(p,panel1,275,130,242,125);
  pvSetPaletteBackgroundColor(p,panel1,237,237,237);
  pvSetFont(p,panel1,"Arial",11,0,0,0,0);

  pvQLabel(p,titulillo_material,panel1);
  pvSetGeometry(p,titulillo_material,5,5,200,20);
  pvSetText(p,titulillo_material,pvtr("ENTRADA MATERIAL"));
  pvSetFont(p,titulillo_material,"Arial",13,1,0,0,0);

  pvQLabel(p,titulillo2_material_d,panel1);
  pvSetGeometry(p,titulillo2_material_d,10,25,70,30);
  pvSetText(p,titulillo2_material_d,pvtr("DESBOB."));
  pvSetFont(p,titulillo2_material_d,"Arial",10,1,0,0,0);

  pvQLabel(p,titulillo2_material_r1,panel1);
  pvSetGeometry(p,titulillo2_material_r1,90,25,70,30);
  pvSetText(p,titulillo2_material_r1,pvtr("REBOB1."));
  pvSetFont(p,titulillo2_material_r1,"Arial",10,1,0,0,0);

  pvQLabel(p,titulillo2_material_r2,panel1);
  pvSetGeometry(p,titulillo2_material_r2,170,25,70,30);
  pvSetText(p,titulillo2_material_r2,pvtr("REBOB2."));
  pvSetFont(p,titulillo2_material_r2,"Arial",10,1,0,0,0);

  pvDownloadFile(p,"./images/mat_abajo.PNG");
  pvQImage(p,imagen_mat_d,panel1,"./images/mat_abajo.PNG",&w,&h,&depth);
  pvSetGeometry(p,imagen_mat_d,10,50,60,60);
  pvSetFont(p,imagen_mat_d,"Arial",11,0,0,0,0);
  pvSetWhatsThis(p,imagen_mat_d,pvtr("./images/mat_abajo.PNG"));

  pvDownloadFile(p,"./images/mat_abajo.PNG");
  pvQImage(p,imagen_mat_r1,panel1,"./images/mat_abajo.PNG",&w,&h,&depth);
  pvSetGeometry(p,imagen_mat_r1,90,50,60,60);
  pvSetFont(p,imagen_mat_r1,"Arial",11,0,0,0,0);
  pvSetWhatsThis(p,imagen_mat_r1,pvtr("./images/mat_abajo.PNG"));

  pvDownloadFile(p,"./images/mat_abajo.PNG");
  pvQImage(p,imagen_mat_r2,panel1,"./images/mat_abajo.PNG",&w,&h,&depth);
  pvSetGeometry(p,imagen_mat_r2,170,50,60,60);
  pvSetFont(p,imagen_mat_r2,"Arial",11,0,0,0,0);
  pvSetWhatsThis(p,imagen_mat_r2,pvtr("./images/mat_abajo.PNG"));

  pvQFrame(p,panel_refilos,imagen_fondo,StyledPanel,Raised,2,1);
  pvSetGeometry(p,panel_refilos,10,360,242,140);
  pvSetPaletteBackgroundColor(p,panel_refilos,237,237,237);
  pvSetFont(p,panel_refilos,"Arial",11,0,0,0,0);

  pvQLabel(p,titulillo_refilos,panel_refilos);
  pvSetGeometry(p,titulillo_refilos,3,3,232,21);
  pvSetText(p,titulillo_refilos,pvtr("TENSIONES REFILOS"));
  pvSetFont(p,titulillo_refilos,"Arial",13,1,0,0,0);

  pvQLabel(p,titulillo2_refilo1,panel_refilos);
  pvSetGeometry(p,titulillo2_refilo1,3,20,130,30);
  pvSetText(p,titulillo2_refilo1,pvtr("CONSIGNA (N*m)/10"));
  pvSetFont(p,titulillo2_refilo1,"Arial",10,1,0,0,0);

  pvQLabel(p,titulillo3_refilo1_LL,panel_refilos);
  pvSetGeometry(p,titulillo3_refilo1_LL,8,50,100,30);
  pvSetText(p,titulillo3_refilo1_LL,pvtr("Refilo 1"));
  pvSetFont(p,titulillo3_refilo1_LL,"Arial",10,0,0,0,0);

  pvQLabel(p,titulillo3_refilo1_HL,panel_refilos);
  pvSetGeometry(p,titulillo3_refilo1_HL,8,80,100,30);
  pvSetText(p,titulillo3_refilo1_HL,pvtr("Refilo 2"));
  pvSetFont(p,titulillo3_refilo1_HL,"Arial",10,0,0,0,0);

  pvQSpinBox(p,spi_refilo1_L,panel_refilos,1,15,1);
  pvSetGeometry(p,spi_refilo1_L,105,48,72,34);
  pvSetFont(p,spi_refilo1_L,"Arial",12,0,0,0,0);

  pvQSpinBox(p,spi_refilo2_L,panel_refilos,1,15,1);
  pvSetGeometry(p,spi_refilo2_L,105,80,72,34);
  pvSetFont(p,spi_refilo2_L,"Arial",12,0,0,0,0);

  pvQPushButton(p,produccion_button,imagen_fondo);
  pvSetGeometry(p,produccion_button,243,3,120,60);
  pvSetText(p,produccion_button,pvtr("Producción"));
  pvSetFont(p,produccion_button,"Arial",11,0,0,0,0);

  pvQPushButton(p,mant_button,imagen_fondo);
  pvSetGeometry(p,mant_button,123,3,120,60);
  pvSetText(p,mant_button,pvtr("Mantenimiento"));
  pvSetFont(p,mant_button,"Arial",11,0,0,0,0);

  pvQPushButton(p,mas_config_button,imagen_fondo);
  pvSetGeometry(p,mas_config_button,3,3,120,60);
  pvSetText(p,mas_config_button,pvtr("Mas Parámetros"));
  pvSetFont(p,mas_config_button,"Arial",11,0,0,0,0);

  pvQTextBrowser(p,alarmHTML,imagen_fondo);
  pvSetGeometry(p,alarmHTML,3,520,793,76);
  pvSetFont(p,alarmHTML,"Sans Serif",10,0,0,0,0);

  pvQLabel(p,titulo,fondo);
  pvSetGeometry(p,titulo,556,6,236,39);
  pvSetText(p,titulo,pvtr("CONFIGURACIÓN"));
  pvSetPaletteForegroundColor(p,titulo,49,200,57);
  pvSetFont(p,titulo,"Arial",20,1,0,0,0);

  pvQFrame(p,panel2,fondo,StyledPanel,Raised,2,1);
  pvSetGeometry(p,panel2,10,160,242,160);
  pvSetPaletteBackgroundColor(p,panel2,237,237,237);
  pvSetFont(p,panel2,"Arial",11,0,0,0,0);

  pvQCheckBox(p,hab_corte,panel2);
  pvSetGeometry(p,hab_corte,3,10,160,30);
  pvSetText(p,hab_corte,pvtr("Habilitación Corte"));
  pvSetPaletteBackgroundColor(p,hab_corte,237,237,237);
  pvSetFont(p,hab_corte,"Arial",11,0,0,0,0);

  pvQCheckBox(p,hab_reb2,panel2);
  pvSetGeometry(p,hab_reb2,23,46,210,30);
  pvSetText(p,hab_reb2,pvtr("Habilitación Rebobinadora 2"));
  pvSetPaletteBackgroundColor(p,hab_reb2,237,237,237);
  pvSetFont(p,hab_reb2,"Arial",11,0,0,0,0);

  pvQCheckBox(p,hab_ref1,panel2);
  pvSetGeometry(p,hab_ref1,23,83,200,30);
  pvSetText(p,hab_ref1,pvtr("Habilitación Refilo 1"));
  pvSetPaletteBackgroundColor(p,hab_ref1,237,237,237);
  pvSetFont(p,hab_ref1,"Arial",11,0,0,0,0);

  pvQCheckBox(p,hab_ref2,panel2);
  pvSetGeometry(p,hab_ref2,23,118,200,30);
  pvSetText(p,hab_ref2,pvtr("Habilitación Refilo 2"));
  pvSetPaletteBackgroundColor(p,hab_ref2,237,237,237);
  pvSetFont(p,hab_ref2,"Arial",11,0,0,0,0);

  pvQFrame(p,panel3,fondo,StyledPanel,Raised,2,1);
  pvSetGeometry(p,panel3,260,290,270,155);
  pvSetPaletteBackgroundColor(p,panel3,237,237,237);
  pvSetFont(p,panel3,"Arial",11,0,0,0,0);

  pvQLabel(p,titulillo_diametros,panel3);
  pvSetGeometry(p,titulillo_diametros,5,5,202,21);
  pvSetText(p,titulillo_diametros,pvtr("DIÁMETROS INICIALES"));
  pvSetFont(p,titulillo_diametros,"Arial",13,1,0,0,0);

  pvQLabel(p,titulillo2_diametros_d,panel3);
  pvSetGeometry(p,titulillo2_diametros_d,10,25,100,25);
  pvSetText(p,titulillo2_diametros_d,pvtr("DESBOB.(mm)"));
  pvSetFont(p,titulillo2_diametros_d,"Arial",10,1,0,0,0);

  pvQLabel(p,titulillo2_diametros_r1,panel3);
  pvSetGeometry(p,titulillo2_diametros_r1,130,25,70,25);
  pvSetText(p,titulillo2_diametros_r1,pvtr("REBOB1."));
  pvSetFont(p,titulillo2_diametros_r1,"Arial",10,1,0,0,0);
  pvSetWhatsThis(p,titulillo2_diametros_r1,pvtr("./images/calandra_grande.PNG"));

  pvQLabel(p,titulillo2_diametros_r2,panel3);
  pvSetGeometry(p,titulillo2_diametros_r2,200,25,60,25);
  pvSetText(p,titulillo2_diametros_r2,pvtr("REBOB2."));
  pvSetFont(p,titulillo2_diametros_r2,"Arial",10,1,0,0,0);
  pvSetWhatsThis(p,titulillo2_diametros_r2,pvtr("./images/calandra_grande.PNG"));

  pvQLineEdit(p,spi_diametro_d,panel3);
  pvSetGeometry(p,spi_diametro_d,15,55,70,35);
  pvSetFont(p,spi_diametro_d,"Arial",12,0,0,0,0);
  pvSetWhatsThis(p,spi_diametro_d,pvtr("./images/calandra_chica.PNG"));

  pvQPushButton(p,but_diametro_d,panel3);
  pvSetGeometry(p,but_diametro_d,86,50,35,45);
  pvSetText(p,but_diametro_d,pvtr("<"));
  pvSetFont(p,but_diametro_d,"Arial",11,1,0,0,0);

  pvDownloadFile(p,"./images/calandra_grande.PNG");
  pvQImage(p,imagen_diametro_r1,panel3,"./images/calandra_grande.PNG",&w,&h,&depth);
  pvSetGeometry(p,imagen_diametro_r1,135,50,70,70);
  pvSetFont(p,imagen_diametro_r1,"Arial",11,0,0,0,0);
  pvSetWhatsThis(p,imagen_diametro_r1,pvtr("./images/calandra_grande.PNG"));

  pvDownloadFile(p,"./images/calandra_chica.PNG");
  pvQImage(p,imagen_diametro_r2,panel3,"./images/calandra_chica.PNG",&w,&h,&depth);
  pvSetGeometry(p,imagen_diametro_r2,205,50,70,70);
  pvSetFont(p,imagen_diametro_r2,"Arial",11,0,0,0,0);
  pvSetWhatsThis(p,imagen_diametro_r2,pvtr("./images/calandra_chica.PNG"));

  pvDownloadFile(p,"./images/calandra_chica.PNG");
  pvQImage(p,imagen_diametro_d,panel3,"./images/calandra_chica.PNG",&w,&h,&depth);
  pvSetGeometry(p,imagen_diametro_d,30,100,70,70);
  pvSetFont(p,imagen_diametro_d,"Arial",11,0,0,0,0);
  pvSetWhatsThis(p,imagen_diametro_d,pvtr("./images/calandra_chica.PNG"));

  pvQFrame(p,panel_paradas,fondo,StyledPanel,Raised,2,1);
  pvSetGeometry(p,panel_paradas,540,90,250,110);
  pvSetPaletteBackgroundColor(p,panel_paradas,237,237,237);
  pvSetFont(p,panel_paradas,"Arial",11,0,0,0,0);

  pvQLabel(p,titulillo_paradas,panel_paradas);
  pvSetGeometry(p,titulillo_paradas,5,5,232,21);
  pvSetText(p,titulillo_paradas,pvtr("PARADAS PROGRAMADAS"));
  pvSetFont(p,titulillo_paradas,"Arial",13,1,0,0,0);

  pvQLabel(p,titulillo2_distancia,panel_paradas);
  pvSetGeometry(p,titulillo2_distancia,10,25,140,30);
  pvSetText(p,titulillo2_distancia,pvtr("POR DISTANCIA (m)"));
  pvSetFont(p,titulillo2_distancia,"Arial",10,1,0,0,0);

  pvQLineEdit(p,spi_parada_distancia,panel_paradas);
  pvSetGeometry(p,spi_parada_distancia,40,55,140,40);
  pvSetFont(p,spi_parada_distancia,"Arial",12,0,0,0,0);

  pvQPushButton(p,but_parada_distancia,panel_paradas);
  pvSetGeometry(p,but_parada_distancia,181,50,40,50);
  pvSetText(p,but_parada_distancia,pvtr("<"));
  pvSetFont(p,but_parada_distancia,"Arial",11,1,0,0,0);

  pvQFrame(p,panel_seccion,fondo,StyledPanel,Raised,2,1);
  pvSetGeometry(p,panel_seccion,540,240,250,110);
  pvSetPaletteBackgroundColor(p,panel_seccion,237,237,237);
  pvSetFont(p,panel_seccion,"Arial",11,0,0,0,0);

  pvQLabel(p,titulo_seccion,panel_seccion);
  pvSetGeometry(p,titulo_seccion,5,5,232,21);
  pvSetText(p,titulo_seccion,pvtr("OTROS PARÁMETROS"));
  pvSetFont(p,titulo_seccion,"Arial",13,1,0,0,0);

  pvQLabel(p,titulillo_seccion,panel_seccion);
  pvSetGeometry(p,titulillo_seccion,10,25,210,30);
  pvSetText(p,titulillo_seccion,pvtr("GROSOR MATERIAL (micras)"));
  pvSetFont(p,titulillo_seccion,"Arial",10,1,0,0,0);

  pvQLineEdit(p,lineedit_seccion,panel_seccion);
  pvSetGeometry(p,lineedit_seccion,40,55,140,40);
  pvSetFont(p,lineedit_seccion,"Arial",12,0,0,0,0);

  pvQPushButton(p,but_seccion,panel_seccion);
  pvSetGeometry(p,but_seccion,181,50,40,50);
  pvSetText(p,but_seccion,pvtr("<"));
  pvSetFont(p,but_seccion,"Arial",11,1,0,0,0);


  pvEndDefinition(p);
  return 0;
}

// _end_of_generated_area_ (do not edit -> use ui2pvc) ---------------------

#include "mask3_slots.h"

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


int show_mask3(PARAM *p)
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
