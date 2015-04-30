/*!

   SCADA users managment interfaze v0.0.4

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
@File piUsrMgnt.h
*/

#ifndef  _PIUSRMGNT_
#define _PIUSRMGNT_

#include <sqlite3.h>
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class piUsrMgnt 
{
 public:

  piUsrMgnt();
  ~piUsrMgnt();
  int UsrMgnt_openDB(const char* DB_Name);
  int UsrMgnt_closeDB();
  int UsrMgnt_openTable(const char* sql_construction );
  int UsrMgnt_login(string Name,string Password);
  int UsrMgnt_logout();
  int UsrMgnt_isLogged(){return IsLogged;};
  string UsrMgnt_retName(){return ActUsrName;};
  int UsrMgnt_retLevel() { return level;};
  string UsrMgnt_retPassword(string Name);
  int UsrMgnt_changePassword(string Name,string password);
  int UsrMgnt_retId(){return id;};
 private:

  string UsrName;
  string UsrPass;
  string ActUsrName;
  int IsLogged;
  int id;
  int level;

  sqlite3 *UserDB;
  char* TableDB;

  //methods
  vector<vector<string> > query(const char* query);
};


#endif
