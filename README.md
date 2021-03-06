# Dependencies

this program ha been developed under the pvbrowser suit, free software under the gpl2 license. it can be download for free at: www.pvbrowser.org.
it uses it's libraries. rllib, and pvslib, and it's client *pvbrowser*.
it uses also QT4 and sqlite3

# Installation

1.-qmake

2.-make clean

3.-make

4.-Finally it has 3 executables:

 modbus_client [.ini] for communications
 rb1000 as server
 pvbrowser as client (provided by the pvbrowser suit)

# Images license

./images/banner_logo.png
./images/calandra_chica.PNG
./images/calandra_grande.PNG
./images/maquina.jpg
./images/mat_abajo.PNG
./images/mat_abajo_d.PNG
./images/mat_abajo_r.PNG
./images/mat_arriba.PNG
./images/mat_arriba_d.PNG
./images/mat_arriba_r.PNG
./images/PLC1.PNG
./images/PLC2.PNG
./images/Brazo2_rojo.png      
./images/Empujador_verde.png  
./images/Brazo2_verde2.png    
./images/fondo                
./images/mat_abajo_r.PNG
./images/Brazo3.png           
./images/fondo_hmi.jpg        
./images/Brazo1.png         
./images/Brazo3_rojo2.png     
./images/fondo.png            
./images/Brazo1_rojo2.png   
./images/Brazo3_rojo.png      
./images/Globo_OFF.png
./images/Brazo1_rojo.png    
./images/Brazo3_verde2.png    
./images/Globo_ON.png
./images/Brazo1_verde2.png  
./images/Brazo3_verde.png     
./images/green.png
./images/Brazo1_verde.png   
./images/grey.png             
./images/RB1000.png
./images/Brazo2.png         
./images/red.png
./images/Brazo2_rojo2.png   
./images/Empujador_rojo.png 
./images/alarms_example.png 

```
This work is licensed under the Creative Commons Attribution 3.0 Unported License. 
You should have received a copy of the Creative Commons Attribution 3.0 Unported License along with this program.
To view a copy of this license, visit http://creativecommons.org/licenses/by/3.0/
or send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
```

copyright 2012-2018 Prointegra S.L. , mail: administracion@prointegra.com

# Database

program uses a sqlite3 database file named users.DB
there are suers and password, and accumulative meters of material worked.

for testing we can use:
user: admin
pass: 123456
with full privileges

# System alarms

for using the pvbrowser HTML alarms widget you'll have to set a file called *alarms.csv* here in the program root directory, when compiling.

this file will contain alarms and warning declarations, it's structure is:

```
<alarm_tag>TAB<alarm_message>TAB<blank>TAB<w/a (warning or alarm)
```

you can see the image *./images/alarms_example.png* for a fully functional example with the current code:

```
W_TRAINO	Imposible funcionar sin subir el traino		w
AL_PAROCCM1	Paro de emergencia Seta del cuadro de control		a
AL_PAROC1	Paro de emergencia Seta del cuadro rebobinadora 1		a
AL_PAROC2	Paro de emergencia Seta del cuadro desbobinadora		a
AL_PAROC3	Paro de emergencia Seta del cuadro rebobinadora 2		a
AL_PAROC4	Paro de emergencia Seta del cuadro de pisones de mesa, desbobinadora		a
W_BRAZOD	Imposible funcionar, subir el brazo del desbobinador		w
W_BRAZOR1	Imposible funcionar, subir el brazo del rebobinador1		w
W_BRAZOR2	Imposible funcionar, subir el brazo del rebobinador2		w
W_GLOBOD	Imposible funcionar, hinchar el eje del desbobinador		w
W_GLOBOR1	Imposible funcionar, hinchar el eje del rebobinador1		w
W_GLOBOR2	Imposible funcionar, hinchar el eje del rebobinador2		w
W_METROSALCZ	Parada por metros alcanzada		w
W_DIAMETROALCZ	Parada por diámetro alcanzada		w
AL_ETHCAT_D	ERROR de comunicaciones Ethercat en el driver 1		a
AL_ETHCAT_R1	ERROR de comunicaciones Ethercat en el driver 2		a
AL_ETHCAT_R2	ERROR de comunicaciones Ethercat en el driver 3		a
AL_ETHCAT_T	ERROR de comunicaciones Ethercat en el driver 4		a
```

# Authors

Pro Integra Sl <administracion (at) prointegra (dot) com>
Joaquín Cuéllar <joa.cuellar (at) riseup (dot) net>

# Copyright

Copyright (C) 2018 Prointegra SL

# License

```
SCADA plastic rolling machine is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

SCADA plastic rolling machine is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
```
