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
/* changelog 
rev 0.0.5 20140807 .- added UsrMgnt_changePassword function
 */
/**
@file piUsrMgnt.cc
*/

#include "piUsrMgnt.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>



piUsrMgnt::piUsrMgnt()
  {
    sqlite3_initialize();
    return;
  }
  piUsrMgnt::~piUsrMgnt()
  {
    return;
  }
int piUsrMgnt::UsrMgnt_openDB(const char* DB_Name)
  {
    cout << "INFO: connecting to Users DB" << endl;
     if (sqlite3_open(DB_Name, &UserDB))
    {
      printf("Can't open database: %s\n", sqlite3_errmsg(UserDB));
      sqlite3_close(UserDB);
      return 1;
    }
  printf("Something happend?: %s\n", sqlite3_errmsg(UserDB));
 
    return 0;
  }
int piUsrMgnt::UsrMgnt_closeDB()
  {
        sqlite3_close(UserDB);
	return 0;
  }
int piUsrMgnt::UsrMgnt_openTable(const char* sql_construction )
  {

    vector<vector<string> > result;
    int populated = 0;

    query(sql_construction);
    result = query("SELECT * from USERS where NAME = 'admin'");
    for(vector<vector<string> >::iterator it = result.begin(); it < result.end(); ++it)
      {
	vector<string> row = *it;
	//cout << "Values: (A=" << row.at(0) << ", B=" << row.at(1) << ")" << endl;
	populated = atoi((row.at(0)).c_str());
      }
    if (populated ==0)
      query( "INSERT INTO USERS VALUES (1,'admin','admin',0)");

    return 0;
  }
int piUsrMgnt::UsrMgnt_login(std::string Name,std::string Password)
{
  char sql[100];
  vector<vector<string> > result;
  int populated = -1;

  sprintf(sql,"select * from USERS where (NAME = '%s' AND PASSWORD = '%s');",Name.c_str(),Password.c_str());

  result = query(sql);
    for(vector<vector<string> >::iterator it = result.begin(); it < result.end(); ++it)
      {
	vector<string> row = *it;
	cout << "Values: (A=" << row.at(0) << ", B=" << row.at(1) << ")" << endl;
	populated = atoi((row.at(0)).c_str());   
	if (populated == 0 )
	  return 1;
	else
	  {
	    //logged

	    id =  atoi((row.at(0)).c_str());
	    ActUsrName = row.at(1).c_str();
	    level = atoi((row.at(3)).c_str());
	    IsLogged = 1;
	  }
      }
   if (populated < 0 )
	  return 1;
  return 0;
}
int piUsrMgnt::UsrMgnt_logout()
{
  id = -1;
  ActUsrName = "";
  level = -1;
  IsLogged = 0;
  return 0;
}

string piUsrMgnt::UsrMgnt_retPassword(string Name)
{
 char sql[100];
 vector<vector<string> > result;
 string ret = "";

 sprintf(sql,"select PASSWORD from USERS where NAME = '%s';",Name.c_str());
 result = query(sql);
 for(vector<vector<string> >::iterator it = result.begin(); it < result.end(); ++it)
    {
	vector<string> row = *it;	
	ret =  row.at(0);   
	  
    }
  

  return ret;
}
 //change password
int piUsrMgnt::UsrMgnt_changePassword(string Name,string password)
{
 char sql[100];
 vector<vector<string> > result;
	int ret;

 sprintf(sql,"update USERS SET PASSWORD = '%s' where NAME = '%s';",password.c_str(),Name.c_str());
 result = query(sql);
 for(vector<vector<string> >::iterator it = result.begin(); it < result.end(); ++it)
    {
	vector<string> row = *it;	
	ret =  atoi(row.at(0).c_str());     
    }
  

  return ret;
}
/*! Function to initialize table inside a database
   - Creates it if it doesn't exist*/
vector<vector<string> > piUsrMgnt::query(const char* query)
{
 
  sqlite3_stmt *statement;
  vector<vector<string> > results;
	 
	    if(sqlite3_prepare_v2(UserDB, query, -1, &statement, 0) == SQLITE_OK)
	    {
	        int cols = sqlite3_column_count(statement);
	        int result = 0;
	        while(true)
	        {
	            result = sqlite3_step(statement);
	             
	            if(result == SQLITE_ROW)
	            {
	                vector<string> values;
	                for(int col = 0; col < cols; col++)
	                {
	                    values.push_back((char*)sqlite3_column_text(statement, col));
	                }
	                results.push_back(values);
	            }
	            else
	            {
	                break;  
	            }
	        }
	        
	        sqlite3_finalize(statement);
	    }
	     
	    string error = sqlite3_errmsg(UserDB);
	    if(error != "not an error") cout << query << " " << error << endl;
  	     
  	    return results;  
}

