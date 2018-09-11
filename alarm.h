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

#ifndef _ALARM_H_
#define _ALARM_H_

#include "processviewserver.h"
#include "rlthread.h"
#include "rlspreadsheet.h"
#include "rlstring.h"
#include "rltime.h"
#include "rlevent.h"

class Alarm
{
  public:
    Alarm(int useEventLog=0);
    ~Alarm();
    int loadCSV(const char *filename);
    int set(const char *alarmId);
    int setInt(const char *alarmId, int i);
    int setFloat(const char *alarmId, float f);
    int ack(const char *alarmId);
    int reset(const char *alarmId);
    int ackAll();
    int resetAll();
    const char *text(const char *alarmId);
    int isSet(const char *alarmId);
    int count();
    int maxCount();
    int updateWidgetHTML(PARAM *p, int id, int *state);
    int updateWidgetHTML_res(PARAM *p, int id, int *state);
  private:  
    const char *strip(const char *text);
    rlString txt1, txt2;
    rlTime time;
    rlSpreadsheetTable table;
    rlMutex mutex;
    int max_alarms, num_alarms, use_event_log;
};

#endif

