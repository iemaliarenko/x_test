####################
Env:
Ubuntu 22.04.1 LTS
VSCode Version: 1.71.2
Toolchains v2.1.0
nRF Connect for Desktop v3.12.0
Programmer v3.0.4

Based on: Bluetooth: Beacon UART Driver Sample
***********************************************

Build and flash the test as follows, board ``nrf52840dk_nrf52840`` :

.. zephyr-app-commands::
   :zephyr-app: x test
   :board: nrf52840dk_nrf52840
   :goals: build flash
   :compact:

Consol: use minicom --device /dev/ttyACM<x>
***********************************************

*** Booting Zephyr OS build v3.1.99-ncs1  ***                                   
Bluetooth initialized                                                           
Beacon started, advertising as F4:BB:B9:54:74:1D (random)                       
Hello! I'm your GPS beacon.                                                     
Enter longtitude as 180.000000 ... -180.000000                                  
-19.2312312                                                                     
Enter latitude as 90.000000 ... -90.000000                                      
84.21423433                                                                     
Your GPS data updated.                                                          
Enter longtitude as 180.000000 ... -180.000000 

