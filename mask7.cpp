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
// show_mask7 for ProcessViewServer created: mié jul 30 10:16:29 2014
//
////////////////////////////////////////////////////////////////////////////
#include "pvapp.h"

// _begin_of_generated_area_ (do not edit -> use ui2pvc) -------------------

// our mask contains the following objects
enum {
  ID_MAIN_WIDGET = 0,
  main_frame,
  imagen_fondo,
  frame_sensores,
  imagen_sensores,
  imagen_cantilever_d,
  imagen_cantilever_r1,
  imagen_cantilever_r2,
  imagen_glob_d,
  imagen_glob_r1,
  imagen_glob_r2,
  imagen_pison_r2,
  imagen_pm_r2,
  imagen_pison_r1,
  imagen_pm_r1,
  imagen_psden_d,
  imagen_psden_r1,
  imagen_pisarr_t,
  imagen_pisabj_t,
  imagen_psden_r2,
  imagen_pmsup_d,
  imagen_pminf_d,
  but_volver,
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
  ""};

  static const char *whatsThis[] = {
  "",
  "",
  "./images/maquina.jpg",
  "",
  "./images/fondo",
  "./images/Braz0_p1b.png",
  "./images/Braz0_p1b.png",
  "./images/Braz1_p1b.png",
  "./images/Globo_OFF.png",
  "./images/Globo_OFF.png",
  "./images/Globo_OFF.png",
  "./images/grey.png",
  "./images/grey.png",
  "./images/grey.png",
  "./images/grey.png",
  "./images/Empujador_verde.png",
  "./images/Empujador_verde.png",
  "./images/grey.png",
  "./images/grey.png",
  "./images/Empujador_verde.png",
  "./images/grey.png",
  "./images/grey.png",
  "",
  "./images/grey.png",
  ""};

  static const int widgetType[ID_END_OF_WIDGETS+1] = {
  0,
  TQFrame,
  TQImage,
  TQFrame,
  TQImage,
  TQImage,
  TQImage,
  TQImage,
  TQImage,
  TQImage,
  TQImage,
  TQImage,
  TQImage,
  TQImage,
  TQImage,
  TQImage,
  TQImage,
  TQImage,
  TQImage,
  TQImage,
  TQImage,
  TQImage,
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

  pvQFrame(p,main_frame,0,StyledPanel,Raised,2,1);
  pvSetGeometry(p,main_frame,0,0,800,600);
  pvSetPaletteBackgroundColor(p,main_frame,200,215,200);
  pvSetFont(p,main_frame,"Arial",11,0,0,0,0);

  pvDownloadFile(p,"./images/fondo.png");
  pvQImage(p,imagen_fondo,main_frame,"./images/fondo.png",&w,&h,&depth);
  pvSetGeometry(p,imagen_fondo,-200,0,1200,600);
  pvSetFont(p,imagen_fondo,"Arial",11,0,0,0,0);
  pvSetWhatsThis(p,imagen_fondo,pvtr("./images/fondo.png.jpg"));

  pvQFrame(p,frame_sensores,imagen_fondo,StyledPanel,Raised,2,1);
  pvSetGeometry(p,frame_sensores,203,70,794,390);
  pvSetPaletteBackgroundColor(p,frame_sensores,237,237,237);
  pvSetFont(p,frame_sensores,"Arial",11,0,0,0,0);

  pvDownloadFile(p,"./images/RB1000.png");
  pvQImage(p,imagen_sensores,frame_sensores,"./images/RB1000",&w,&h,&depth);
  pvSetGeometry(p,imagen_sensores,12,3,788,384);
  pvSetFont(p,imagen_sensores,"Arial",11,0,0,0,0);
  pvSetWhatsThis(p,imagen_sensores,pvtr("./images/RB1000"));

  pvDownloadFile(p,"./images/Brazo1_rojo.png");
  pvQImage(p,imagen_cantilever_d,imagen_sensores,"./images/Brazo1_rojo.png",&w,&h,&depth);
  pvSetGeometry(p,imagen_cantilever_d,125,245,120,120);
  pvSetFont(p,imagen_cantilever_d,"Arial",11,0,0,0,0);
  pvSetWhatsThis(p,imagen_cantilever_d,pvtr("./images/Brazo1_rojo.png"));

  pvDownloadFile(p,"./images/Brazo1_rojo.png");
  pvQImage(p,imagen_cantilever_r1,imagen_sensores,"./images/Brazo1_rojo.png",&w,&h,&depth);
  pvSetGeometry(p,imagen_cantilever_r1,310,245,120,120);
  pvSetFont(p,imagen_cantilever_r1,"Arial",11,0,0,0,0);
  pvSetWhatsThis(p,imagen_cantilever_r1,pvtr("./images/Brazo1_rojo.png"));

  pvDownloadFile(p,"./images/Brazo1_rojo2.png");
  pvQImage(p,imagen_cantilever_r2,imagen_sensores,"./images/Brazo1_rojo2.png",&w,&h,&depth);
  pvSetGeometry(p,imagen_cantilever_r2,590,245,120,120);
  pvSetFont(p,imagen_cantilever_r2,"Arial",11,0,0,0,0);
  pvSetWhatsThis(p,imagen_cantilever_r2,pvtr("./images/Brazo1_rojo2.png"));

  pvDownloadFile(p,"./images/Globo_OFF.png");
  pvQImage(p,imagen_glob_d,imagen_sensores,"./images/Globo_OFF.png",&w,&h,&depth);
  pvSetGeometry(p,imagen_glob_d,88,232,40,40);
  pvSetFont(p,imagen_glob_d,"Arial",11,0,0,0,0);
  pvSetWhatsThis(p,imagen_glob_d,pvtr("./images/Globo_OFF.png"));

  pvDownloadFile(p,"./images/Globo_OFF.png");
  pvQImage(p,imagen_glob_r1,imagen_sensores,"./images/Globo_OFF.png",&w,&h,&depth);
  pvSetGeometry(p,imagen_glob_r1,276,232,40,40);
  pvSetFont(p,imagen_glob_r1,"Arial",11,0,0,0,0);
  pvSetWhatsThis(p,imagen_glob_r1,pvtr("./images/Globo_OFF.png"));

  pvDownloadFile(p,"./images/Globo_OFF.png");
  pvQImage(p,imagen_glob_r2,imagen_sensores,"./images/Globo_OFF.png",&w,&h,&depth);
  pvSetGeometry(p,imagen_glob_r2,695,232,40,40);
  pvSetFont(p,imagen_glob_r2,"Arial",11,0,0,0,0);
  pvSetWhatsThis(p,imagen_glob_r2,pvtr("./images/Globo_OFF.png"));

  pvDownloadFile(p,"./images/grey.png");
  pvQImage(p,imagen_pison_r2,imagen_sensores,"./images/grey.png",&w,&h,&depth);
  pvSetGeometry(p,imagen_pison_r2,690,150,35,35);
  pvSetFont(p,imagen_pison_r2,"Arial",11,0,0,0,0);
  pvSetWhatsThis(p,imagen_pison_r2,pvtr("./images/grey.png"));

  pvDownloadFile(p,"./images/grey.png");
  pvQImage(p,imagen_pm_r2,imagen_sensores,"./images/grey.png",&w,&h,&depth);
  pvSetGeometry(p,imagen_pm_r2,585,210,35,35);
  pvSetFont(p,imagen_pm_r2,"Arial",11,0,0,0,0);
  pvSetWhatsThis(p,imagen_pm_r2,pvtr("./images/grey.png"));

  pvDownloadFile(p,"./images/grey.png");
  pvQImage(p,imagen_pison_r1,imagen_sensores,"./images/grey.png",&w,&h,&depth);
  pvSetGeometry(p,imagen_pison_r1,290,150,35,35);
  pvSetFont(p,imagen_pison_r1,"Arial",11,0,0,0,0);
  pvSetWhatsThis(p,imagen_pison_r1,pvtr("./images/grey.png"));

  pvDownloadFile(p,"./images/grey.png");
  pvQImage(p,imagen_pm_r1,imagen_sensores,"./images/grey.png",&w,&h,&depth);
  pvSetGeometry(p,imagen_pm_r1,400,210,35,35);
  pvSetFont(p,imagen_pm_r1,"Arial",11,0,0,0,0);
  pvSetWhatsThis(p,imagen_pm_r1,pvtr("./images/grey.png"));

  pvDownloadFile(p,"./images/Empujador_verde.png");
  pvQImage(p,imagen_psden_d,imagen_sensores,"./images/Empujador_verde.png",&w,&h,&depth);
  pvSetGeometry(p,imagen_psden_d,71,190,80,60);
  pvSetFont(p,imagen_psden_d,"Arial",11,0,0,0,0);
  pvSetWhatsThis(p,imagen_psden_d,pvtr("./images/Empujador_verde.png"));

  pvDownloadFile(p,"./images/Empujador_verde.png");
  pvQImage(p,imagen_psden_r1,imagen_sensores,"./images/Empujador_verde.png",&w,&h,&depth);
  pvSetGeometry(p,imagen_psden_r1,259,190,80,60);
  pvSetFont(p,imagen_psden_r1,"Arial",11,0,0,0,0);
  pvSetWhatsThis(p,imagen_psden_r1,pvtr("./images/Empujador_verde.png"));

  pvDownloadFile(p,"./images/grey.png");
  pvQImage(p,imagen_pisarr_t,imagen_sensores,"./images/grey.png",&w,&h,&depth);
  pvSetGeometry(p,imagen_pisarr_t,405,50,35,35);
  pvSetFont(p,imagen_pisarr_t,"Arial",11,0,0,0,0);
  pvSetWhatsThis(p,imagen_pisarr_t,pvtr("./images/grey.png"));

  pvDownloadFile(p,"./images/grey.png");
  pvQImage(p,imagen_pisabj_t,imagen_sensores,"./images/grey.png",&w,&h,&depth);
  pvSetGeometry(p,imagen_pisabj_t,405,90,35,35);
  pvSetFont(p,imagen_pisabj_t,"Arial",11,0,0,0,0);
  pvSetWhatsThis(p,imagen_pisabj_t,pvtr("./images/grey.png"));

  pvDownloadFile(p,"./images/Empujador_verde.png");
  pvQImage(p,imagen_psden_r2,imagen_sensores,"./images/Empujador_verde.png",&w,&h,&depth);
  pvSetGeometry(p,imagen_psden_r2,677,190,80,60);
  pvSetFont(p,imagen_psden_r2,"Arial",11,0,0,0,0);
  pvSetWhatsThis(p,imagen_psden_r2,pvtr("./images/Empujador_verde.png"));

  pvDownloadFile(p,"./images/grey.png");
  pvQImage(p,imagen_pmsup_d,imagen_sensores,"./images/grey.png",&w,&h,&depth);
  pvSetGeometry(p,imagen_pmsup_d,12,150,35,35);
  pvSetFont(p,imagen_pmsup_d,"Arial",11,0,0,0,0);
  pvSetWhatsThis(p,imagen_pmsup_d,pvtr("./images/grey.png"));

  pvDownloadFile(p,"./images/grey.png");
  pvQImage(p,imagen_pminf_d,imagen_sensores,"./images/grey.png",&w,&h,&depth);
  pvSetGeometry(p,imagen_pminf_d,5,185,35,35);
  pvSetFont(p,imagen_pminf_d,"Arial",11,0,0,0,0);
  pvSetWhatsThis(p,imagen_pminf_d,pvtr("./images/grey.png"));

  pvQPushButton(p,but_volver,main_frame);
  pvSetGeometry(p,but_volver,3,3,120,60);
  pvSetText(p,but_volver,pvtr("Volver"));
  pvSetFont(p,but_volver,"Arial",11,0,0,0,0);

  pvQTextBrowser(p,alarmHTML,main_frame);
  pvSetGeometry(p,alarmHTML,3,520,793,76);
  pvSetFont(p,alarmHTML,"Sans Serif",10,0,0,0,0);
  pvSetWhatsThis(p,alarmHTML,pvtr("./images/grey.png"));


  pvEndDefinition(p);
  return 0;
}

// _end_of_generated_area_ (do not edit -> use ui2pvc) ---------------------

#include "mask7_slots.h"

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


int show_mask7(PARAM *p)
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
