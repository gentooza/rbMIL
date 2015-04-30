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
/**
@file piSQLite.c
*/

#include "piSQLite.h"
#include <stdio.h>
#include <stdlib.h>

/*!Sqlite callback function, modified to transfer data*/
static int callback(void *data, int argc, char **argv, char **azColName){
   int i;
   stcallback *localdata;
   localdata = (stcallback*)data;
   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
      localdata->ret = atoi(argv[i]);
   }
   printf("\n");
   return 0;
}
/*! Sqlite original callback function */
static int callback_old(void *data, int argc, char **argv, char **azColName){
   int i;
 
   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

/*!Function to create a generic table */
int DBcreatetable(sqlite3 **ppDb, const char* Table_Constructor)
{
  int RC;
  sqlite3 *pDb;
  char* zErrMsg = 0;

  pDb=*ppDb;


  RC = sqlite3_exec(pDb, Table_Constructor, callback_old, 0, &zErrMsg);
  if (RC != SQLITE_OK)
    {
      fprintf(stderr, "ERROR: Creating table, %s\n", zErrMsg);
      *ppDb=pDb;
      return -1;
    }

  *ppDb=pDb;
  return 0;    
}

/*! Function to initialize database */
int DBinit(sqlite3 **ppDb, const char* DB_Name)
{
  sqlite3 *pDb;
  pDb = *ppDb;
  const char* data = "Callback function called";
  stcallback callbackinfo;

  callbackinfo.ret=0;
  printf("INFO: Connecting to database\n");
  //Connection to Database
  if (sqlite3_open_v2(DB_Name, &pDb,SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE,NULL))
    {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(pDb));
      sqlite3_close(pDb);
      return 0;
    }
  return 1;
}

/*! Function to initialize table inside a database
   - Creates it if it doesn't exist*/
int Tableinit(sqlite3 **ppDb, const char* Table_Name,const char* Table_Construction)
{
  sqlite3 *pDb;
  pDb = *ppDb;
  char  sql[100];
  char* zErrMsg = 0;
  int RC;
  const char* data = "Callback function called";
  stcallback callbackinfo;

  callbackinfo.ret=0;

  printf("INFO: Looking for table %s\n",Table_Name);
  sprintf(sql,"select count(type) from sqlite_master where type='table' and name='%s';",Table_Name);
  RC = sqlite3_exec(pDb, sql, callback, &callbackinfo, &zErrMsg);
  if (RC != SQLITE_OK)//bad function execution
    {
      fprintf(stderr, "ERROR: Can't look for table, %s\n", zErrMsg);
      return -1;
    }
  printf("INFO: callbackinfo.ret = %d\n",callbackinfo.ret);//DEBUG
  if(callbackinfo.ret == 0)//CREATING TABLE
    {
      printf("WARNING: Table: %s doesn't exist \n",Table_Name);
      printf("INFO: Creating it!!\n");
      if(DBcreatetable(&pDb,Table_Construction))      
	{
	  printf("ERROR: Can't create table: %s\n",Table_Name);
	  return -1;
	}
    }
  return 0;

}

