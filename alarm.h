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

