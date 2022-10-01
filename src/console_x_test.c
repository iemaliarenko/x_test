#include "console_x_test.h"

#define UART_DEVICE_NODE DT_CHOSEN(zephyr_shell_uart)
#define MSG_SIZE 12

static const struct device *uart_dev = DEVICE_DT_GET(UART_DEVICE_NODE);
static char rx_buf[MSG_SIZE];
static int rx_buf_pos;

K_MSGQ_DEFINE(uart_msgq, sizeof(rx_buf), 8, 4);

static void serial_cb(const struct device *dev, void *user_data) {
	uint8_t c;

	if (!uart_irq_update(uart_dev)) {
		return;
	}

	while (uart_irq_rx_ready(uart_dev)) {

		uart_fifo_read(uart_dev, &c, 1);

		if ((c == '\n' || c == '\r') && rx_buf_pos > 0) {
			/* terminate string */
			rx_buf[rx_buf_pos] = '\0';

			/* if queue is full, message is silently dropped */
			k_msgq_put(&uart_msgq, &rx_buf, K_NO_WAIT);

			/* reset the buffer (it was copied to the msgq) */
			rx_buf_pos = 0;
		} else if (rx_buf_pos < (sizeof(rx_buf) - 1)) {
			rx_buf[rx_buf_pos++] = c;
			uart_poll_out(uart_dev, c);
		}
		/* else: characters beyond buffer size are dropped */
	}
}

static bool validate_data (const char *data, uint8_t tlc) {
    
	for(int i = 0; i < strlen( data ); i ++) {
        //ASCII value of 0 = 48, 9 = 57.
        //Checking for "-", "."
        if ((data[i] < 48 || data[i] > 57) &&
			data[i] != 45 &&
			data[i] != 46 ) {
            return false;
	    }
    }

	if (-180.0000000 <= atof(data) && 
	    atof(data) <= 180.000000 && tlc == LONG) {
		return true;
	}
	if (-90.000000 <= atof(data) &&
	    atof(data) <= 90.000000 && tlc == LAT) {
		return true;
	}

	return false;
}

void print_uart(char *buf) {
	int msg_len = strlen(buf);

	for (int i = 0; i < msg_len; i++) {
		uart_poll_out(uart_dev, buf[i]);
	}
}

void init_console (void) {
    if (!device_is_ready(uart_dev)) {
		printk("Console not ready\n");
		return;
	}

	uart_irq_callback_user_data_set(uart_dev, serial_cb, NULL);
	uart_irq_rx_enable(uart_dev);
}

bool read_console_data (uint8_t *mfg_data_, uint8_t tlc) {
	char tx_buf[MSG_SIZE];
	memset(&rx_buf, ' ', MSG_SIZE);
	rx_buf_pos = 0;
    if (tlc == LONG){
        print_uart("Enter longtitude as 180.000000 ... -180.000000\r\n");
	}
	if (tlc == LAT){
        print_uart("Enter latitude as 90.000000 ... -90.000000\r\n");
	}

	k_msgq_get(&uart_msgq, &tx_buf, K_FOREVER);
	print_uart("\r\n");

	if (true == validate_data(rx_buf, tlc)){
		memcpy(mfg_data_, rx_buf, sizeof(rx_buf)-1);
		return true;
	}
	else {
		print_uart("Wrong data format, try ag\r\n");
		return false;
	}
}
