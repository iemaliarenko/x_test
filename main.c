#include "src/console_x_test.h"
#include "src/beacon_x_test.h"


void main(void) {  
	init_console ();
	init_beacon ();

    print_uart("Hello! I'm your GPS beacon.\r\n");

	while (true) {
        if (read_console_data(mfg_data_lo, LONG) && read_console_data(mfg_data_la, LAT)) {
			update_beacon_data();
			print_uart("Your GPS data updated.\r\n");
		}
	}
}
