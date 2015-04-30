//###############################################################
//# mask7_slots.h for ProcessViewServer created: mié jul 30 10:16:29 2014
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
	//printf("DEBUG: image set: %s , valor: %d\n",filename,value );
  pvSetImage(p,id,filename);
}
static void multisetState(PARAM *p, DATA *d, int value0,int value1, int id, const char *IMAGEN_0, const char * IMAGEN_1,const char * IMAGEN_2,const char * IMAGEN_3, const char* IMAGEN_INDEFINIDO) 
{ // helper function
  char filename[80] = "";
  if    ((value0 == 0) && (value1 == 0)) strcpy(filename,IMAGEN_0);
  else if    ((value0 > 0) && (value1 == 0)) strcpy(filename,IMAGEN_1);
  else if    ((value0 == 0) && (value1 > 0)) strcpy(filename,IMAGEN_2);
  else if    ((value0 > 0) && (value1 > 0)) strcpy(filename,IMAGEN_3);
  else                       strcpy(filename,IMAGEN_INDEFINIDO);
	printf("DEBUG: image set: %s , valor 0: %d  valor 1: %d\n",filename,value0,value1 );
  pvSetImage(p,id,filename);
}
static int slotInit(PARAM *p, DATA *d)
{
 char text[100];
int address;
int i;
int* word;
  if(p == NULL || d == NULL) return -1;
  //memset(d,0,sizeof(DATA));
	ReadCommDATA(&d);
  //iniciamos alarmas
  InitAlarms(&d);
//digitals
//digitales
  pvDownloadFile(p,"./images/green.png");
  pvDownloadFile(p,"./images/Empujador_rojo.png");
  pvDownloadFile(p,"./images/Globo_ON.png");
  pvDownloadFile(p,"./images/Brazo1_verde.png"); //arriba bloq
  pvDownloadFile(p,"./images/Brazo1_verde2.png");  //arriba bloq der
  pvDownloadFile(p,"./images/Brazo2_rojo.png");  //intermedia sin bloq
  pvDownloadFile(p,"./images/Brazo2_rojo2.png");  //intermedia sin bloq der
  pvDownloadFile(p,"./images/Brazo2_verde.png"); //intermedia bloq
  pvDownloadFile(p,"./images/Brazo2_verde2.png");  //intermedia bloq der
  pvDownloadFile(p,"./images/Brazo3_rojo.png");  //abajo sin bloq
  pvDownloadFile(p,"./images/Brazo3_rojo2.png");  //abajo sin bloq der
  pvDownloadFile(p,"./images/Brazo3_verde.png"); //abajo bloq
  pvDownloadFile(p,"./images/Brazo3_verde2.png");  //abajo bloq der
//REB1
	word = (int*)malloc(16*sizeof(int));
	word2digitals(d->val[SCW_STATUSR1B],&word);//Psret,psext,ejedesb,ejebloq,cantabj,cantarr,pisonarr,pisonPMarr
	for(i=0;i<16;i++)
		d->statusR1[i]=word[i];
		
        multisetState(p,d,word[0],word[1],imagen_psden_r1,"./images/Empujador_rojo.png","./images/Empujador_verde.png","./images/Empujador_rojo.png","./images/Empujador_rojo.png","./images/Empujador_rojo.png");

	if(word[3]) //eje bloqueado
		multisetState(p,d,word[4],word[5],imagen_cantilever_r1,"./images/Brazo2_verde.png","./images/Brazo3_verde.png","./images/Brazo1_verde.png","./images/Brazo2_verde.png","./images/Brazo2_verde.png");
	else if(word[2]) //eje desbloqueado
		multisetState(p,d,word[4],word[5],imagen_cantilever_r1,"./images/Brazo2_rojo.png","./images/Brazo3_rojo.png","./images/Brazo1_rojo.png","./images/Brazo2_rojo.png","./images/Brazo2_rojo.png");
	else //indefinido
		multisetState(p,d,word[4],word[5],imagen_cantilever_r1,"./images/Brazo2_verde.png","./images/Brazo3_verde.png","./images/Brazo1_verde.png","./images/Brazo2_verde.png","./images/Brazo2_verde.png");


	setState(p,d,word[6],imagen_pison_r1,"./images/green.png","./images/grey.png","./images/grey.png");
 	setState(p,d,word[7],imagen_pm_r1,"./images/green.png","./images/grey.png","./images/grey.png");
	setState(p,d,word[8],imagen_glob_r1,"./images/green.png","./images/grey.png","./images/grey.png");
  	
//REB2

	word2digitals(d->val[SCW_STATUSR2B],&word);//Psret,psext,ejedesb,ejebloq,cantabj,cantarr,pisonarr,pisonPMarr
	for(i=0;i<16;i++)
		d->statusR2[i]=word[i];
        multisetState(p,d,word[0],word[1],imagen_psden_r2,"./images/Empujador_rojo.png","./images/Empujador_verde.png","./images/Empujador_rojo.png","./images/Empujador_rojo.png","./images/Empujador_rojo.png");

	if(word[3]) //eje bloqueado
		multisetState(p,d,word[4],word[5],imagen_cantilever_r1,"./images/Brazo2_verde2.png","./images/Brazo3_verde2.png","./images/Brazo1_verde2.png","./images/Brazo2_verde2.png","./images/Brazo2_verde2.png");
	else if(word[2]) //eje desbloqueado
		multisetState(p,d,word[4],word[5],imagen_cantilever_r1,"./images/Brazo2_rojo2.png","./images/Brazo3_rojo2.png","./images/Brazo1_rojo2.png","./images/Brazo2_rojo2.png","./images/Brazo2_rojo2.png");
	else //indefinido
		multisetState(p,d,word[4],word[5],imagen_cantilever_r1,"./images/Brazo2_verde2.png","./images/Brazo3_verde2.png","./images/Brazo1_verde2.png","./images/Brazo2_verde2.png","./images/Brazo2_verde2.png");
	setState(p,d,word[6],imagen_pison_r2,"./images/green.png","./images/grey.png","./images/grey.png");
 	setState(p,d,word[7],imagen_pm_r2,"./images/green.png","./images/grey.png","./images/grey.png");
	setState(p,d,word[8],imagen_glob_r2,"./images/green.png","./images/grey.png","./images/grey.png");
//DESB
	word2digitals(d->val[SCW_STATUSDB],&word);//Psret,psext,ejedesb,ejebloq,cantabj,cantarr,pisonsuparr,pisoninfarr,pisonarr_t,pisonabj_t,globo
	for(i=0;i<16;i++)
		d->statusD[i]=word[i];
        multisetState(p,d,word[0],word[1],imagen_psden_d,"./images/Empujador_rojo.png","./images/Empujador_verde.png","./images/Empujador_rojo.png","./images/Empujador_rojo.png","./images/Empujador_rojo.png");

	if(word[3]) //eje bloqueado
		multisetState(p,d,word[4],word[5],imagen_cantilever_r1,"./images/Brazo2_verde.png","./images/Brazo3_verde.png","./images/Brazo1_verde.png","./images/Brazo2_verde.png","./images/Brazo2_verde.png");
	else if(word[2]) //eje desbloqueado
		multisetState(p,d,word[4],word[5],imagen_cantilever_r1,"./images/Brazo2_rojo.png","./images/Brazo3_rojo.png","./images/Brazo1_rojo.png","./images/Brazo2_rojo.png","./images/Brazo2_rojo.png");
	else //indefinido
		multisetState(p,d,word[4],word[5],imagen_cantilever_r1,"./images/Brazo2_verde.png","./images/Brazo3_verde.png","./images/Brazo1_verde.png","./images/Brazo2_verde.png","./images/Brazo2_verde.png");
	setState(p,d,word[6],imagen_pmsup_d,"./images/green.png","./images/grey.png","./images/grey.png");
 	setState(p,d,word[7],imagen_pminf_d,"./images/green.png","./images/grey.png","./images/grey.png");
	setState(p,d,word[8],imagen_pisarr_t,"./images/green.png","./images/grey.png","./images/grey.png");
 	setState(p,d,word[9],imagen_pisabj_t,"./images/green.png","./images/grey.png","./images/grey.png");
	setState(p,d,word[10],imagen_glob_d,"./images/green.png","./images/grey.png","./images/grey.png");
	delete(word);

//////////////////////////
  //mask navigation control
  MyData.lastMask = MyData.thisMask;
  MyData.thisMask = 7;
  return 0;
}

static int slotNullEvent(PARAM *p, DATA *d)
{
  int* word;
  int i;
  if(p == NULL || d == NULL) return -1;
		ReadCommDATA(&d);
//digitales

//REB1
	word = (int*)malloc(16*sizeof(int));
	word2digitals(d->val[SCW_STATUSR1B],&word);//Psret,psext,ejedesb,ejebloq,cantabj,cantarr,pisonarr,pisonPMarr
	for(i=0;i<16;i++)
		d->statusR1[i]=word[i];
        multisetState(p,d,word[0],word[1],imagen_psden_r1,"./images/Empujador_rojo.png","./images/Empujador_verde.png","./images/Empujador_rojo.png","./images/Empujador_rojo.png","./images/Empujador_rojo.png");

	if(word[3]) //eje bloqueado
		multisetState(p,d,word[4],word[5],imagen_cantilever_r1,"./images/Brazo2_verde.png","./images/Brazo3_verde.png","./images/Brazo1_verde.png","./images/Brazo2_verde.png","./images/Brazo2_verde.png");
	else if(word[2]) //eje desbloqueado
		multisetState(p,d,word[4],word[5],imagen_cantilever_r1,"./images/Brazo2_rojo.png","./images/Brazo3_rojo.png","./images/Brazo1_rojo.png","./images/Brazo2_rojo.png","./images/Brazo2_rojo.png");
	else //indefinido
		multisetState(p,d,word[4],word[5],imagen_cantilever_r1,"./images/Brazo2_verde.png","./images/Brazo3_verde.png","./images/Brazo1_verde.png","./images/Brazo2_verde.png","./images/Brazo2_verde.png");

	setState(p,d,word[6],imagen_pison_r1,"./images/green.png","./images/grey.png","./images/grey.png");
 	setState(p,d,word[7],imagen_pm_r1,"./images/green.png","./images/grey.png","./images/grey.png");
	setState(p,d,word[8],imagen_glob_r1,"./images/Globo_ON.png","./images/Globo_OFF.png","./images/Globo_OFF.png");
  	
//REB2

	word2digitals(d->val[SCW_STATUSR2B],&word);//Psret,psext,ejedesb,ejebloq,cantabj,cantarr,pisonarr,pisonPMarr
	for(i=0;i<16;i++)
		d->statusR2[i]=word[i];
        multisetState(p,d,word[0],word[1],imagen_psden_r1,"./images/Empujador_rojo.png","./images/Empujador_verde.png","./images/Empujador_rojo.png","./images/Empujador_rojo.png","./images/Empujador_rojo.png");

	if(word[3]) //eje bloqueado
		multisetState(p,d,word[4],word[5],imagen_cantilever_r1,"./images/Brazo2_verde2.png","./images/Brazo3_verde2.png","./images/Brazo1_verde2.png","./images/Brazo2_verde2.png","./images/Brazo2_verde2.png");
	else if(word[2]) //eje desbloqueado
		multisetState(p,d,word[4],word[5],imagen_cantilever_r1,"./images/Brazo2_rojo2.png","./images/Brazo3_rojo2.png","./images/Brazo1_rojo2.png","./images/Brazo2_rojo2.png","./images/Brazo2_rojo2.png");
	else //indefinido
		multisetState(p,d,word[4],word[5],imagen_cantilever_r1,"./images/Brazo2_verde2.png","./images/Brazo3_verde2.png","./images/Brazo1_verde2.png","./images/Brazo2_verde2.png","./images/Brazo2_verde2.png");

	setState(p,d,word[6],imagen_pison_r2,"./images/green.png","./images/grey.png","./images/grey.png");
 	setState(p,d,word[7],imagen_pm_r2,"./images/green.png","./images/grey.png","./images/grey.png");
	setState(p,d,word[8],imagen_glob_r2,"./images/Globo_ON.png","./images/Globo_OFF.png","./images/Globo_OFF.png");
//DESB
	word2digitals(d->val[SCW_STATUSDB],&word);//Psret,psext,ejedesb,ejebloq,cantabj,cantarr,pisonsuparr,pisoninfarr,pisonarr_t,pisonabj_t,globo
	for(i=0;i<16;i++)
		d->statusD[i]=word[i];
        multisetState(p,d,word[0],word[1],imagen_psden_d,"./images/Empujador_rojo.png","./images/Empujador_verde.png","./images/Empujador_rojo.png","./images/Empujador_rojo.png","./images/Empujador_rojo.png");

	if(word[3]) //eje bloqueado
		multisetState(p,d,word[4],word[5],imagen_cantilever_r1,"./images/Brazo2_verde.png","./images/Brazo3_verde.png","./images/Brazo1_verde.png","./images/Brazo2_verde.png","./images/Brazo2_verde.png");
	else if(word[2]) //eje desbloqueado
		multisetState(p,d,word[4],word[5],imagen_cantilever_r1,"./images/Brazo2_rojo.png","./images/Brazo3_rojo.png","./images/Brazo1_rojo.png","./images/Brazo2_rojo.png","./images/Brazo2_rojo.png");
	else //indefinido
		multisetState(p,d,word[4],word[5],imagen_cantilever_r1,"./images/Brazo2_verde.png","./images/Brazo3_verde.png","./images/Brazo1_verde.png","./images/Brazo2_verde.png","./images/Brazo2_verde.png");
	setState(p,d,word[6],imagen_pmsup_d,"./images/green.png","./images/grey.png","./images/grey.png");
 	setState(p,d,word[7],imagen_pminf_d,"./images/green.png","./images/grey.png","./images/grey.png");
	setState(p,d,word[8],imagen_pisarr_t,"./images/green.png","./images/grey.png","./images/grey.png");
 	setState(p,d,word[9],imagen_pisabj_t,"./images/green.png","./images/grey.png","./images/grey.png");
	setState(p,d,word[10],imagen_glob_d,"./images/Globo_ON.png","./images/Globo_OFF.png","./images/Globo_OFF.png");
	delete(word);
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
  if(p == NULL || id == 0 || d == NULL) return -1;
	if (id == but_volver)
	{
		show_mask2(p);
	}
  	else if(id == alarmHTML)
  	{
   	 	show_mask4(p);
  	}
  return 0;
}

static int slotTextEvent(PARAM *p, int id, DATA *d, const char *text)
{
  if(p == NULL || id == 0 || d == NULL || text == NULL) return -1;
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
