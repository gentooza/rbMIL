/*!

   PRointegra SQLite Database Interfaze V0.0.1

   copyright 2014 by its authors

   This program is free software; you can redistribute it and/or modify  
   it under the terms of the GNU General Public License as published by  
   the Free Software Foundation; either version 3 of the License, or     
   (at your option) any later version.                                   
                                                                         
   This program is distributed in the hope that it will be useful,       
   but WITHOUT ANY WARRANTY; without even the implied warranty of        
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         
   GNU General Public License for more details.                          
                                                                         
   You should have received a copy of the GNU General Public License     
   along with this program; if not, write to the                         
   Free Software Foundation, Inc.,                                      
   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             


   See files AUTHORS and LICENSE for more information

*/
/*!
@File piSQLite.h
*/
#ifndef _PISQLITE_
#define _PISQLITE_
#include <sqlite3.h>

/*! Data structure to retrieve data from all callback functions called, by the sql queries*/
typedef struct 
{
  int ret;

} stcallback;

 

static int callback(void *data, int argc, char **argv, char **azColName); 
static int callback_old(void *data, int argc, char **argv, char **azColName); 
int DBcreatetable(sqlite3 **ppDb, const char* Table_Constructor);
int DBinit(sqlite3 **ppDb,const char* DB_Name);
int Tableinit(sqlite3 **ppDb, const char* Table_Name,const char* Table_Construction);





#endif
