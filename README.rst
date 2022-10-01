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

Build:
**************************************************
.................
[178/187] Generating dev_handles.c
[179/187] Building C object zephyr/CMakeFiles/zephyr_pre1.dir/misc/empty_file.c.obj
[180/187] Building C object zephyr/CMakeFiles/zephyr_pre1.dir/dev_handles.c.obj
[181/187] Linking C executable zephyr/zephyr_pre1.elf

[182/187] Generating linker.cmd
[183/187] Generating isr_tables.c, isrList.bin
[184/187] Building C object zephyr/CMakeFiles/zephyr_final.dir/misc/empty_file.c.obj
[185/187] Building C object zephyr/CMakeFiles/zephyr_final.dir/isr_tables.c.obj
[186/187] Building C object zephyr/CMakeFiles/zephyr_final.dir/dev_handles.c.obj
[187/187] Linking C executable zephyr/zephyr.elf
Memory region         Used Size  Region Size  %age Used
           FLASH:      105944 B         1 MB     10.10%
            SRAM:       24723 B       256 KB      9.43%
        IDT_LIST:          0 GB         2 KB      0.00%
 *  Terminal will be reused by tasks, press any key to close it. 