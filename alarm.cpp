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


#include "alarm.h"

Alarm::Alarm(int useEventLog)
{
  max_alarms = num_alarms = 0;
  use_event_log = useEventLog; 
}

Alarm::~Alarm()
{
}

const char *Alarm::strip(const char *text)
{
  txt2 = &text[1];
  char *mytext = txt2.text();
  char *cptr = strchr(mytext,'\"');
  if(cptr != NULL) *cptr = '\0';
  return mytext;
}

int Alarm::loadCSV(const char *filename)
{

  max_alarms = num_alarms = 0; 
  int ret = table.read(filename);
  if(ret < 0) return ret;
  rlSpreadsheetRow *row = table.getFirstRow();
  while(row != NULL)
  {
    max_alarms++;
    row = row->getNextRow();
  }
  return max_alarms;
}

int Alarm::set(const char *alarmId)
{
  mutex.lock();
  time.getLocalTime();
  rlSpreadsheetRow *row = table.getFirstRow();
  while(row != NULL)
  {
    if(strcmp(alarmId,strip(row->text(1))) == 0)
    {
      if(strlen(row->text(3)) == 0) num_alarms++;
      //joa edited
      //if(strlen(row->text(4)) == 0) num_alarms++;
      //
      txt1  = time.getTimeString();
      txt1 += " : ";
      txt1 += strip(row->text(2));
      row->setText(3,txt1.text()); // set the ALARM message
      //joa edited
      //row->setText(4,txt1.text()); // set the ALARM message
      //
      mutex.unlock();
      if(use_event_log)
      {
        rlEvent(rlError,"%s",strip(row->text(2))); // send alarm to event log
      }
      return 0;
    }
    row = row->getNextRow();
  }
  mutex.unlock();
  return -1;
}

int Alarm::setInt(const char *alarmId, int i)
{
  mutex.lock();
  rlString txt;
  time.getLocalTime();
  rlSpreadsheetRow *row = table.getFirstRow();
  while(row != NULL)
  {
    if(strcmp(alarmId,strip(row->text(1))) == 0)
    {
      if(strlen(row->text(3)) == 0) num_alarms++;
      txt1  = time.getTimeString();
      txt1 += " : ";
      txt.printf(strip(row->text(2)), i);
      txt1 += txt;
      row->setText(3,txt1.text()); // set the ALARM message
      mutex.unlock();
      if(use_event_log)
      {
        rlEvent(rlError,strip(row->text(2)),i); // send alarm to event log
      }
      return 0;
    }
    row = row->getNextRow();
  }
  mutex.unlock();
  return -1;
}

int Alarm::setFloat(const char *alarmId, float f)
{
  mutex.lock();
  rlString txt;
  time.getLocalTime();
  rlSpreadsheetRow *row = table.getFirstRow();
  while(row != NULL)
  {
    if(strcmp(alarmId,strip(row->text(1))) == 0)
    {
      if(strlen(row->text(3)) == 0) num_alarms++;
      txt1  = time.getTimeString();
      txt1 += " : ";
      txt.printf(strip(row->text(2)), f);
      txt1 += txt;
      row->setText(3,txt1.text()); // set the ALARM message
      mutex.unlock();
      if(use_event_log)
      {
        rlEvent(rlError,strip(row->text(2)),f); // send alarm to event log
      }
      return 0;
    }
    row = row->getNextRow();
  }
  mutex.unlock();
  return -1;
}

int Alarm::ack(const char *alarmId)
{
  rlString alarm_id(alarmId);
  rlString temp;
  if(alarm_id.startsWith("alarm://"))
  {
    alarm_id = &alarmId[8];
  }
  mutex.lock();
  rlSpreadsheetRow *row = table.getFirstRow();
  while(row != NULL)
  {
    if(alarm_id.strnocasecmp(strip(row->text(1))) == 0)
    {
      if(!strncmp(row->text(4),"\"a\"",3))
	{
	  temp.printf("Ack alarm: %s", row->text(3));
	  if(strncmp(row->text(3),"Ack alarm:",10) != 0)  
	    {
	      row->setText(3,temp.text()); // ack the ALARM message
	    } 
        }
      else
        {
         temp.printf("Ack warning: %s", row->text(3));
	 if(strncmp(row->text(3),"Ack warning:",12) != 0)  
	    {
	      row->setText(3,temp.text()); // ack the ALARM message
	    } 
        }

      mutex.unlock();
      if(use_event_log)
      {
        rlEvent(rlInfo,"Ack alarm: %s",strip(row->text(2))); // send alarm to event log
      }
      return 0;
    }
    row = row->getNextRow();
  }
  mutex.unlock();
  return -1;
}

int Alarm::reset(const char *alarmId)
{
  rlString alarm_id(alarmId);
  if(alarm_id.startsWith("alarm://"))
  {
    alarm_id = &alarmId[8];
  }
  mutex.lock();
  rlSpreadsheetRow *row = table.getFirstRow();
  while(row != NULL)
  {
    if(alarm_id.strnocasecmp(strip(row->text(1))) == 0)
    {
      if(strlen(row->text(3)) != 0) num_alarms--;
      if(num_alarms < 0) num_alarms = 0;
      row->setText(3,""); // reset the ALARM message
      mutex.unlock();
      if(use_event_log)
      {
        rlEvent(rlInfo,"Reset alarm: %s",strip(row->text(2))); // send alarm to event log
      }
      return 0;
    }
    row = row->getNextRow();
  }
  mutex.unlock();
  return -1;
}

int Alarm::ackAll()
{
  rlString temp;
  mutex.lock();
  rlSpreadsheetRow *row = table.getFirstRow();
  while(row != NULL)
  {
    if(strlen(row->text(3)) > 0)
    {
      if(!strncmp(row->text(4),"\"a\"",3))
	{
	 temp.printf("Ack alarm: %s", row->text(3));
         if(strncmp(row->text(3),"Ack alarm:",10) != 0)  
         {
          row->setText(3,temp.text()); // ack the ALARM message
         }
        }
      else
	{
          temp.printf("Ack warning: %s", row->text(3));
          if(strncmp(row->text(3),"Ack warning:",12) != 0)  
          {
            row->setText(3,temp.text()); // ack the ALARM message
          }
         }

      if(use_event_log)
      {
        rlEvent(rlInfo,"Ack alarm: %s",strip(row->text(2))); // send alarm to event log
      }
    }  
    row = row->getNextRow();
  }
  mutex.unlock();
  return 0;
}

int Alarm::resetAll()
{
  mutex.lock();
  rlSpreadsheetRow *row = table.getFirstRow();
  while(row != NULL)
  {
    if(strlen(row->text(3)) != 0) num_alarms--;
    if(num_alarms < 0) num_alarms = 0;
    row->setText(3,""); // reset the ALARM message
    if(use_event_log)
    {
      rlEvent(rlInfo,"Reset alarm: %s",strip(row->text(2))); // send alarm to event log
    }
    row = row->getNextRow();
  }
  mutex.unlock();
  return 0;
}

const char * Alarm::text(const char *alarmId)
{
  rlString alarm_id(alarmId);
  if(alarm_id.startsWith("alarm://"))
  {
    alarm_id = &alarmId[8];
  }
  mutex.lock();
  rlSpreadsheetRow *row = table.getFirstRow();
  //printf("DEBUG: ROW = %s , %s , %s , %s \n",row->text(1),row->text(2),row->text(3),row->text(4));
  while(row != NULL)
  {
    if(alarm_id.strnocasecmp(strip(row->text(1))) == 0)
    {
      mutex.unlock();
      return row->text(3);
      //Joa edited
      //return row->text(4);
      ////
    }
    row = row->getNextRow();
  }
  mutex.unlock();
  return NULL;
}

int Alarm::isSet(const char *alarmId)
{
  const char *txt = text(alarmId);
  if(txt == NULL)     return 0;
  if(strlen(txt) > 0) return 1;
  return 0;
}

int Alarm::count()
{
  return num_alarms;
}

int Alarm::maxCount()
{
  return max_alarms;
}

static const char *myHTML_HEADER = 
"<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\"><html><head><meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\"><head><body";
static const char *myHTML_TRAILER = 
"</body></html>";

int Alarm::updateWidgetHTML(PARAM *p, int id, int *state)
{
  if(num_alarms == 0)
  {
    if(*state > 1) return 0; // no update needed already green
    *state = 2;
    rlString html(myHTML_HEADER);
    html += " style=\"background-color:#DDDDDD\">";
    html += "<p>No Alarms</p>";
    html += myHTML_TRAILER;
    pvSetText(p,id,html.text());
  }
  else 
  {
    if(*state == 0) *state = 1;
    else            *state = 0;
    rlString html(myHTML_HEADER);
    rlString txt;
    //if(*state == 0) html += " style=\"background-color:#FF0000\">";
    //else            html += " style=\"background-color:#DD0000\">";
    html += " style=\"background-color:#888888\">";
    txt.printf("<p>Number of Alarms = %d</p>", num_alarms);
    html += txt;
    
    //mutex.lock();
    rlSpreadsheetRow *row = table.getFirstRow();
    while(row != NULL)
    {
      if(strlen(row->text(3)) != 0)
      {
	printf("DEBUG: campo 4 %s \n",row->text(4));
        printf("DEBUG: campo 3 %s \n",row->text(3));
        if(strncmp(row->text(3),"Ack alarm:",10) == 0) html += "<p> <a style=\"color:yellow\" ";
        else if(strncmp(row->text(3),"Ack warning:",12) == 0) html += "<p> <a style=\"color:green\" ";
        else if(!strncmp(row->text(4),"\"a\"",3) )
	  {
            if(*state == 0)                           html += "<p> <a style=\"color:FF0000\" ";
            else                                           html += "<p> <a style=\"color:880000\" ";
	    html += "href=\"alarm://";
          }
	else
         {
            if(*state == 0)                           html += "<p> <a style=\"color:0000FF\" ";
            else                                           html += "<p> <a style=\"color:000088\" ";
	     html += "href=\"warning://";
            
          }

            html += strip(row->text(1));
            html += "\">";
            html += strip(row->text(1));
            html += ": ";
            html += row->text(3);
            html += "</a></p>";

      }
      row = row->getNextRow();
    }
    //mutex.unlock();
    html += myHTML_TRAILER;
    pvSetText(p,id,html.text());
  }
  return 0;
}

/*! Alarms resume, to insert in every SCADA/HMI mask as an alarm briefing */
int Alarm::updateWidgetHTML_res(PARAM *p, int id, int *state)
{
 if(num_alarms == 0)
  {
    if(*state > 1) return 0; // no update needed already green
    *state = 2;
    rlString html(myHTML_HEADER);
    html += " style=\"background-color:#DDDDDD\">";
    //    html += "<p>No Alarms</p>";
    html += myHTML_TRAILER;
    pvSetText(p,id,html.text());
  }
  else 
  {
    if(*state == 0) *state = 1;
    else            *state = 0;
    rlString html(myHTML_HEADER);
    rlString txt;
    //if(*state == 0) html += " style=\"background-color:#FF0000\">";
    //else            html += " style=\"background-color:#DD0000\">";
    html += " style=\"background-color:#888888\">";
    //txt.printf("<p>Number of Alarms = %d</p>", num_alarms);
    html += txt;
    
    //mutex.lock();
    rlSpreadsheetRow *row = table.getFirstRow();
 while(row != NULL)
    {
      if(strlen(row->text(3)) != 0)
      {
        if(strncmp(row->text(3),"Ack alarm:",10) == 0) html += "<p> <a style=\"color:yellow\" ";
        else if(strncmp(row->text(3),"Ack warning:",12) == 0) html += "<p> <a style=\"color:green\" ";
        else if(!strncmp(row->text(4),"\"a\"",3) )
	  {
            if(*state == 0)                           html += "<p> <a style=\"color:FF0000\" ";
            else                                           html += "<p> <a style=\"color:880000\" ";
	    html += "href=\"alarm://";
          }
	else
         {
            if(*state == 0)                           html += "<p> <a style=\"color:0000FF\" ";
            else                                           html += "<p> <a style=\"color:000088\" ";
	     html += "href=\"warning://";
            
          }

            html += strip(row->text(1));
            html += "\">";
            html += strip(row->text(1));
            html += ": ";
            html += row->text(3);
            html += "</a></p>";

      }
      row = row->getNextRow();
    }
    //mutex.unlock();
    html += myHTML_TRAILER;
    pvSetText(p,id,html.text());
  }
  return 0;
}

